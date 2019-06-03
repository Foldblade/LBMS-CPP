-- phpMyAdmin SQL Dump
-- version 4.8.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: 2019-06-03 22:50:49
-- 服务器版本： 5.5.60-log
-- PHP Version: 7.2.6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `LBMS`
--

-- --------------------------------------------------------

--
-- 表的结构 `library`
--

CREATE TABLE `library` (
  `ISBN` varchar(13) NOT NULL COMMENT 'ISBN',
  `title` varchar(50) NOT NULL COMMENT '书名',
  `author` varchar(50) NOT NULL COMMENT '作者',
  `publisher` varchar(50) NOT NULL COMMENT '出版社',
  `many` int(11) NOT NULL COMMENT '总数',
  `inside` int(11) NOT NULL COMMENT '馆藏',
  `outside` int(11) NOT NULL COMMENT '借出',
  `id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- 转存表中的数据 `library`
--

INSERT INTO `library` (`ISBN`, `title`, `author`, `publisher`, `many`, `inside`, `outside`, `id`) VALUES
('9787113187118', 'C++语言程序设计', '张思明', '中国铁道出版社', 13, 5, 8, 1),
('9787115279460', 'C++ Primer Plus 中文版（第六版）', 'Stephen Prata', '人民邮电出版社', 5, 2, 3, 2),
('9787115379597', 'Python Cookbook 中文版，第 3 版', 'David M. Beazley / Brian K. Jones', '人民邮电出版社', 5, 0, 5, 3),
('9787115429476', '软技能 代码之外的生存指南', 'John Sonmez', '人民邮电出版社', 2, 0, 2, 4),
('9787302396680', '图形图像处理应用教程（第4版）', '梁维娜', '清华大学出版社', 3, 3, 0, 5),
('9787508693705', '数学简史：确定性的消失', '[美]莫里斯·克莱因', '中信出版集团', 2, 2, 0, 6),
('9787512318625', '电路原理', '王玫', '中国电力出版社', 10, 2, 8, 7),
('9787533936020', '月亮与六便士', '[英]威廉·萨默塞特·毛姆', '浙江文艺出版社', 12, 8, 4, 8),
('9787540233365', '美丽新世界 （精装插图典藏版）', '[英]阿道司·赫胥黎', '北京燕山出版社', 3, 2, 1, 9),
('9787540233372', '一九八四 （精装插图典藏版）', '[英]乔治·奥威尔', '北京燕山出版社', 3, 3, 0, 10),
('9787543063822', '人间失格', '[日]太宰治', '武汉出版社', 5, 1, 4, 11),
('9787559614636', '房思琪的初恋乐园', '林奕含', '北京联合出版公司', 3, 1, 2, 12),
('9787801057303', '精神分析导论讲演', '[奥地利] 西格蒙德·弗洛伊德', '国际文化出版公司', 2, 1, 1, 13),
('9787801057365', '论宗教', '[奥地利] 西格蒙德·弗洛伊德', '国际文化', 2, 2, 0, 14);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `library`
--
ALTER TABLE `library`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `id` (`id`),
  ADD KEY `ISBN` (`ISBN`);

--
-- 在导出的表使用AUTO_INCREMENT
--

--
-- 使用表AUTO_INCREMENT `library`
--
ALTER TABLE `library`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
