#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>

#include "jsontable.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    JsonTable jtable(20,20,"#eee", "#000", 14, "Tahoma");
    QJsonObject style, item;
    QJsonArray row;


//    //2 rows

//    //row-0-0
//    style = jtable.createStyle(20, 1);
//    item = jtable.createObject("text", "item-0", style);
//    row = jtable.addObjectToRow(row, item);
//    //row-0-1
//    style = jtable.createStyle(20, 2);
//    item = jtable.createObject("text", "item-1", style);
//    row = jtable.addObjectToRow(row, item);
//    //row-0-2
//    style = jtable.createStyle(20, 3);
//    item = jtable.createObject("text", "item-2", style);
//    row = jtable.addObjectToRow(row, item);
//    //row-0-3
//    style = jtable.createStyle(20, 4);
//    item = jtable.createObject("text", "item-3", style);
//    row = jtable.addObjectToRow(row, item);
//    //row-0-4
//    style = jtable.createStyle(20, 5);
//    item = jtable.createObject("text", "item-4", style);
//    row = jtable.addObjectToRow(row, item);


//    jtable.addRowToTable(row);
//    row = jtable.emptyJsonArray(row);

//    //row-1-0
//    style = jtable.createStyle(20, 10);
//    item = jtable.createObject("text", "item-0", style);
//    row = jtable.addObjectToRow(row, item);
//    //row-1-1
//    style = jtable.createStyle(20, 11);
//    item = jtable.createObject("text", "Row1-1", style);
//    row = jtable.addObjectToRow(row, item);
//    //row-1-2
//    style = jtable.createStyle(20, 12);
//    item = jtable.createObject("text", "Row1-2", style);
//    row = jtable.addObjectToRow(row, item);
//    //row-1-3
//    style = jtable.createStyle(20, 13);
//    item = jtable.createObject("text", "item-3", style);
//    row = jtable.addObjectToRow(row, item);
//    //row-1-4
//    style = jtable.createStyle(20, 14);
//    item = jtable.createObject("text", "Row1-4", style);
//    row = jtable.addObjectToRow(row, item);


//    jtable.addRowToTable(row);
//    row = jtable.emptyJsonArray(row);


//    //row-1-0
//    style = jtable.createStyle(20, 10);
//    item = jtable.createObject("text", "item-0", style);
//    row = jtable.addObjectToRow(row, item);
//    //row-1-1
//    style = jtable.createStyle(20, 11);
//    item = jtable.createObject("text", "Row1-1", style);
//    row = jtable.addObjectToRow(row, item);
//    //row-1-2
//    style = jtable.createStyle(20, 12);
//    item = jtable.createObject("text", "Row1-2", style);
//    row = jtable.addObjectToRow(row, item);
//    //row-1-3
//    style = jtable.createStyle(20, 13);
//    item = jtable.createObject("text", "item-3", style);
//    row = jtable.addObjectToRow(row, item);
//    //row-1-4
//    style = jtable.createStyle(20, 14);
//    item = jtable.createObject("text", "Row1-4", style);
//    row = jtable.addObjectToRow(row, item);


//    jtable.addRowToTable(row);
//    row = jtable.emptyJsonArray(row);


    QTextStream stream(stdout);
    //stream << jtable.toByteArray() << endl;

    //jtable.loadJson("template.json");
    //jtable.saveJsonAs("template2.json");

    //qDebug() << jtable.getRowMaxHeight(jtable.table[1].toArray());

//    style = jtable.createStyle(50, 60);
//    item = jtable.createObject("text", "FOR TEST", style);
//    item = jtable.updateObjectStyle(item, "height", 120);
//    QByteArray bytes = jtable.toByteArray(item);
//    stream << bytes << endl;


//    row = jtable.table[0].toArray();
//    row = jtable.updateRowStyle(row, "height", 130);
//    QByteArray arrays = jtable.toByteArray(row);
//    stream << arrays << endl;


//    jtable.updateTableRowHeight();
//    QByteArray arrays = jtable.toByteArray();
//    stream << arrays << endl;



    //row-0-0
    QJsonArray items;
    style = jtable.createStyle(20, 10);
    items = jtable.createObjects("text", {"item1", "item2", "item3", "item4", "item5"} , style);
    row = jtable.addArrayToRow(row, items);
    jtable.addRowToTable(row);
    row = jtable.emptyJsonArray(row);

    style = jtable.createStyle(30, 20);
    items = jtable.createObjects("text", {"item1", "item2", "item30", "item40", "item50"} , style);
    row = jtable.addArrayToRow(row, items);
    jtable.addRowToTable(row);
    row = jtable.emptyJsonArray(row);

    //new page with empty array-row
    jtable.addRowToTable();


    style = jtable.createStyle(40, 30);
    item = jtable.createObject("text", "item1", style);
    row = jtable.addObjectToRow(row, item);
    items = jtable.createObjects("text", {"item2", "item30"} , style);
    row = jtable.addArrayToRow(row, items);
    jtable.addRowToTable(row);
    row = jtable.emptyJsonArray(row);

    style = jtable.createStyle(30, 20,"#f00", "#efe", 16,false, "Times" );
    items = jtable.createObjects("text", {"item1", "item2", "item30", "item40", "item50"} , style);
    row = jtable.addArrayToRow(row, items);
    jtable.addRowToTable(row);
    row = jtable.emptyJsonArray(row);


    jtable.updateTableRowHeight();
    jtable.tableAnalyser();


    stream << jtable.toByteArray() << endl; // Qt::endl;

    return a.exec();
}
