#include "search_book_result_no.h"

search_book_result_no::search_book_result_no(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	QString content[5][5];
	content[0][0] = { "1" }; content[0][1] = { "a" }; content[0][2] = { "b" }; content[0][3] = { "c" }; content[0][4] = { "d" };
	content[1][0] = { "2" }; content[1][1] = { "a" }; content[1][2] = { "b" }; content[1][3] = { "c" }; content[1][4] = { "d" };
	content[2][0] = { "3" }; content[2][1] = { "a" }; content[2][2] = { "b" }; content[2][3] = { "c" }; content[2][4] = { "d" };
	content[3][0] = { "4" }; content[3][1] = { "a" }; content[3][2] = { "b" }; content[3][3] = { "c" }; content[3][4] = { "d" };
	content[4][0] = { "5" }; content[4][1] = { "a" }; content[4][2] = { "b" }; content[4][3] = { "c" }; content[4][4] = { "d" };
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			QTableWidgetItem* item = new QTableWidgetItem(content[i][j]);
			ui.tableWidget->setItem(i, j, item);//setItem(�У��У�����)
		}
	}

}

search_book_result_no::~search_book_result_no()
{
}

