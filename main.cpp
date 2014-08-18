#include "MyModel.h"
#include "NameNumberInfo.h"

#include <QTableView>
#include <QHeaderView>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTableView table;

    // Basic and optional formatting for the table and its headers.
    // table.setShowGrid(false);

    // table.verticalHeader()->setVisible(false);
    // table.horizontalHeader()->setVisible(false);
    // table.horizontalHeader()->setStretchLastSection(true);

    std::vector<std::unique_ptr<DataRow>> numbers;
    numbers.push_back(std::unique_ptr<DataRow>(new NameNumberInfo("Hi", 0)));
    numbers.push_back(std::unique_ptr<DataRow>(new NameNumberInfo("There", 1)));

    MyModel model = MyModel(numbers);
    table.setModel(&model);

    table.show();

    return a.exec();
}
