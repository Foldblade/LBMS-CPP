# 图书馆图书管理系统——LBMS-CPP

C++课设：Library Book Management Syetem (Written in CPP) 

LBMS：陆基弹道导弹系统

这是一个无害的LBMS~！

[![Badge](https://img.shields.io/badge/link-996.icu-%23FF4D5B.svg?style=flat-square)](https://996.icu/#/zh_CN)[![LICENSE](https://img.shields.io/badge/license-Anti%20996-blue.svg?style=flat-square)](https://github.com/996icu/996.ICU/blob/master/LICENSE)

[TOC]

## 综述

这是一个用C++编写的图书馆图书管理系统，拥有图书管理与查询的基本功能。目标可能有点多，但我想这是挑战，也是学习的过程。

## 计划拥有的亮点

- 拥有简单的GUI（基于Qt框架）
- 基于OpenCV与Zbar对ISBN条码进行扫描
- ~~联网查询ISBN信息~~（豆瓣图书API挂了=_=||）
- 远程MySQL数据库存储数据

## 环境

### 程序开发与运行环境
- Windows 10
- Visual Studio 2019
- OpenCV 2.4.13.6
- zbar 0.10.0
- MySQL Connector/C++ 1.1.4
- boost 1.70.0（MySQL Connector C++需要）
- win32（因为zbar官方给了x86的……导致OpenCV最后也用了支持x86的2.x）

### 远程MySQL服务器环境
- CentOS 7
- MySQL 5.5.60（[LNMP一键安装包](https://lnmp.org)版本）

## 使用

### 开始之前……

#### 下载安装

如果您想尝试编译，您需要安装并（按我们能编译运行的配置）配置OpenCV 2.4.13.6、zbar 0.10.0、boost 1.70.0、MySQL Connector C++ 1.1.4，当然还有Visual Studio。

- OpenCV 2.4.13.6 x86预编译版[下载](https://sourceforge.net/projects/opencvlibrary/files/opencv-win/2.4.13/opencv-2.4.13.6-vc14.exe/download)
- zbar 0.10.0 x86预编译版[下载](https://sourceforge.net/projects/zbar/files/zbar/0.10/zbar-0.10-setup.exe/download)
- boost 1.70.0 x86预编译版[下载](https://sourceforge.net/projects/boost/files/boost-binaries/1.70.0/boost_1_70_0-msvc-14.1-32.exe/download)
- MySQL Connector/C++ 1.1.4 x86预编译版[下载](https://downloads.mysql.com/archives/get/file/mysql-connector-c2B2B-1.1.4-win32.msi)

#### 加入用户变量

首先是安装上一节列出的几项到**自己知道安装到哪里的目录**。

**再次强调，安装时您需要对它们的安装目录有清楚的了解，能记住并知晓它们的安装目录**。

不同的人可能会选择将以上几项安装在不同的目录。项目中，我们采取用户变量的方式确认它们的位置。

所以我们需要**加入一些用户变量**。操作流程：此电脑->右键-属性->抵达“控制面板\系统和安全\系统”->点击“高级系统设置”->系统属性窗口-高级->环境变量->环境变量窗口->“XXX的用户变量”下方的新建(N)…

需要加入四项（请注意**例子并不一定是你的安装目录**）：

| 变量名              | 变量值                                        | 例子                                                   |
| ------------------- | --------------------------------------------- | ------------------------------------------------------ |
| BOOST_DIR           | boost 1.70.0 x86预编译版安装路径              | C:\boost\boost_1_70_0                                  |
| OPENCV_DIR          | OpenCV 2.4.13.6 x86预编译版安装路径           | C:\OpenCV\opencv                                       |
| MYSQL_CONNECTOR_DIR | MySQL Connector/C++ 1.1.4 x86预编译版安装路径 | C:\Program Files (x86)\MySQL\MySQL Connector C++ 1.1.4 |
| ZBAR_DIR            | zbar 0.10.0 x86预编译版安装路径               | C:\Program Files (x86)\ZBar                            |

#### （此节仅针对全新创建VS项目者）

您需要进行一些配置。

VC++目录->包含目录，编辑添加：

```
$(BOOST_DIR)
$(ZBAR_DIR)\include
$(OPENCV_DIR)\build\include
$(OPENCV_DIR)\build\include\opencv
$(OPENCV_DIR)\build\include\opencv2
$(MYSQL_CONNECTOR_DIR)\include
$(MYSQL_CONNECTOR_DIR)\lib
```

VC++目录->库目录，编辑添加：

```
$(BOOST_DIR)\lib32-msvc-14.1
$(ZBAR_DIR)\lib
$(OPENCV_DIR)\build\x86\vc14\lib
$(MYSQL_CONNECTOR_DIR)\lib\opt
```

链接器->输入->附加依赖项，添加：
```
qtmaind.lib
Qt5Cored.lib
Qt5Guid.lib
Qt5Widgetsd.lib
Qt5TextToSpeech.lib
libzbar-0.lib
opencv_calib3d2413d.lib
opencv_contrib2413d.lib
opencv_core2413d.lib
opencv_features2d2413d.lib
opencv_flann2413d.lib
opencv_gpu2413d.lib
opencv_highgui2413d.lib
opencv_imgproc2413d.lib
opencv_legacy2413d.lib
opencv_ml2413d.lib
opencv_nonfree2413d.lib
opencv_objdetect2413d.lib
opencv_ocl2413d.lib
opencv_photo2413d.lib
opencv_stitching2413d.lib
opencv_superres2413d.lib
opencv_ts2413d.lib
opencv_video2413d.lib
opencv_videostab2413d.lib
mysqlcppconn.lib
mysqlcppconn-static.lib
```

### 拷贝并编辑配置文件

1. 将`LBMS`目录下的`.config(origin).json`拷贝为`.config.json`；
2. 将`LBMS`目录下的`.sql_config(origin).json`拷贝为`.sql_config.json`。

用文本编辑器（包括但不仅限于Notepad++、VS Code）打开它们并进行编辑。

### 关于扫描条形码的摄像头

OpenCV会从摄像头中捕获图像，正如我们代码中所体现的：`CvCapture* capture = cvCreateCameraCapture(0);`，`0`即是电脑所带摄像头的ID。

如果您使用的设备：

1. 自带摄像头、且摄像头带有自动对焦功能
2. 不带摄像头，您正连接在电脑上使用的摄像头带有自动聚焦功能（或使用能对焦的安卓手机作为摄像头）

那么您可以尝试着在根目录的`.config.json`中修改`cameraid`的值为**0**，调用这**唯一一个**摄像头。

如果您和我们一样，**使用的是一台自带摄像头并不支持对焦的笔记本**，那么我们建议您使用一部能对焦的安卓手机作为该电脑的摄像头以扫描二维码——当然，您也可以选用高清的、支持对焦的摄像头。**此时，该手机（或其他高清摄像头）的id便应该为`1`，这也是我们程序配置的默认值**。

#### 使用DroidCam将安卓手机作为电脑的摄像头

Android 安装包下载：[DroidCam Wireless Webcam_v6.7.4_apkpure.com.apk](https://d-12.winudf.com/b/apk/Y29tLmRldjQ3YXBwcy5kcm9pZGNhbV82OV9mMDQ2NmIxOQ?_fn=RHJvaWRDYW0gV2lyZWxlc3MgV2ViY2FtX3Y2LjcuNF9hcGtwdXJlLmNvbS5hcGs&_p=Y29tLmRldjQ3YXBwcy5kcm9pZGNhbQ&as=c4b9406ee77dd34196b82a7d3cda08c05ccd427a&c=17CTOOLS7CZGV2PURldjQ3QXBwcyZ0PWFwayZ2bj02LjcuNCZ2Yz02OQ&k=b007934ac605b8cc15e86c06c109cb2c5ccfb06d)  
DroidCam位于[APKpure](https://apkpure.com/cn/droidcam-wireless-webcam/com.dev47apps.droidcam)、[Google Play](https://play.google.com/store/apps/details?id=com.dev47apps.droidcam)的地址【如果不能打开，可能需要一些科学辅助手段】

Windows端下载【官网】：https://www.dev47apps.com/droidcam/windows/

免费版的DroidCam就已经够用了。如果您开启了您安卓手机的ABD，您可以通过USB数据线连接您的手机与电脑。或者，您也可以将手机与电脑置于同一WiFi环境中，通过无线连接。


## 致谢

### 参考文档

#### DroidCam

- [DroidCam – 让手机充当无线摄像头](https://www.appinn.com/droidcam-for-android/)

#### OpenCV与Zbar的配合使用
- [This Opencv Tutorial is about Scanning or Reading Barcode with Opencv by using ZBar Libraries](https://opencv-tutorials-hub.blogspot.com/2015/12/how-to-scan-barcodes-qr-codes-with-opencv-using-zbar.html)*【首推】*
- [OpenCV+Zbar通过摄像头实时识别二维码](https://zhoujianshi.github.io/articles/2017/OpenCV+ZbarE9809AE8BF87E69184E5838FE5A4B4E5AE9EE697B6E8AF86E588ABE4BA8CE7BBB4E7A081/index.html)*【重要参考】*
- [｛opencv环境配置｝以及｛VC包含目录、附加依赖项、库目录及具体设置｝](https://blog.csdn.net/zeroQiaoba/article/details/70837682)*【感谢】*
- [vs c++配置opencv（1）](https://www.cnblogs.com/z-yue/p/5707053.html)
- [OpenCV+ZBar实现条码识别（Windows32位和64位）](https://blog.csdn.net/KayChanGEEK/article/details/77483992)

#### MySQL Connector C++与Boost

- [MySQL Connector/C++ 1.1 Developer Guide](https://dev.mysql.com/doc/connector-cpp/1.1/en/connector-cpp-getting-started-examples.html)*【官方文档】*
- [VS2008下C++连接Mysql](http://vcsos.com/Article/pageSource/140619/20140619110152.shtml)*【后半关于boost的部分】*
- [C++连接mysql数据库时，用getString()方法总是出错](https://ask.csdn.net/questions/236975) *【加个c_str()】*

#### Qt
- [QMessageBox](https://doc.qt.io/qt-5/qmessagebox.html) *【官方文档】*
- [QT messageBox](https://blog.csdn.net/dsg333/article/details/9665885)
- [QT messagebox 乱码解决](https://blog.csdn.net/XuePiaoFei1/article/details/46356293)
- [QT QTableWidget 用法总结](https://blog.csdn.net/polokang/article/details/6696982)
- [QTableWidget设置只能选中一行](https://blog.csdn.net/feng_ye2015/article/details/87880427)

#### RapidJSON
- [RapidJSON 文档](http://rapidjson.org/zh-cn/)

### 第三方

- [OpenCV](https://opencv.org/)
- [Zbar](http://zbar.sourceforge.net/index.html)
- [MySQL Connector/C++](https://downloads.mysql.com/archives/c-cpp/)
- [boost](https://www.boost.org/)
- [RapidJSON](http://rapidjson.org/)

