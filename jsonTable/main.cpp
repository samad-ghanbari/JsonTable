#include <QGuiApplication>
#include <QDebug>
#include <QTextStream>
#include <QFont>
#include <QFontMetrics>
#include "jsontable.h"

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);
//    JsonTable jtable(20,"#000", "#fff","Tahoma", 18);
    QJsonObject style, item;
    QJsonArray row;


////    //2 rows

////    //row-0-0
////    style = jtable.createStyle(20, 1);
////    item = jtable.createObject("text", "item-0", style);
////    row = jtable.addObjectToRow(row, item);
////    //row-0-1
////    style = jtable.createStyle(20, 2);
////    item = jtable.createObject("text", "item-1", style);
////    row = jtable.addObjectToRow(row, item);
////    //row-0-2
////    style = jtable.createStyle(20, 3);
////    item = jtable.createObject("text", "item-2", style);
////    row = jtable.addObjectToRow(row, item);
////    //row-0-3
////    style = jtable.createStyle(20, 4);
////    item = jtable.createObject("text", "item-3", style);
////    row = jtable.addObjectToRow(row, item);
////    //row-0-4
////    style = jtable.createStyle(20, 5);
////    item = jtable.createObject("text", "item-4", style);
////    row = jtable.addObjectToRow(row, item);


////    jtable.addRowToTable(row);
////    row = jtable.emptyJsonArray(row);

////    //row-1-0
////    style = jtable.createStyle(20, 10);
////    item = jtable.createObject("text", "item-0", style);
////    row = jtable.addObjectToRow(row, item);
////    //row-1-1
////    style = jtable.createStyle(20, 11);
////    item = jtable.createObject("text", "Row1-1", style);
////    row = jtable.addObjectToRow(row, item);
////    //row-1-2
////    style = jtable.createStyle(20, 12);
////    item = jtable.createObject("text", "Row1-2", style);
////    row = jtable.addObjectToRow(row, item);
////    //row-1-3
////    style = jtable.createStyle(20, 13);
////    item = jtable.createObject("text", "item-3", style);
////    row = jtable.addObjectToRow(row, item);
////    //row-1-4
////    style = jtable.createStyle(20, 14);
////    item = jtable.createObject("text", "Row1-4", style);
////    row = jtable.addObjectToRow(row, item);


////    jtable.addRowToTable(row);
////    row = jtable.emptyJsonArray(row);


////    //row-1-0
////    style = jtable.createStyle(20, 10);
////    item = jtable.createObject("text", "item-0", style);
////    row = jtable.addObjectToRow(row, item);
////    //row-1-1
////    style = jtable.createStyle(20, 11);
////    item = jtable.createObject("text", "Row1-1", style);
////    row = jtable.addObjectToRow(row, item);
////    //row-1-2
////    style = jtable.createStyle(20, 12);
////    item = jtable.createObject("text", "Row1-2", style);
////    row = jtable.addObjectToRow(row, item);
////    //row-1-3
////    style = jtable.createStyle(20, 13);
////    item = jtable.createObject("text", "item-3", style);
////    row = jtable.addObjectToRow(row, item);
////    //row-1-4
////    style = jtable.createStyle(20, 14);
////    item = jtable.createObject("text", "Row1-4", style);
////    row = jtable.addObjectToRow(row, item);


////    jtable.addRowToTable(row);
////    row = jtable.emptyJsonArray(row);


      QTextStream stream(stdout);
//    //stream << jtable.toByteArray() << endl;

//    //jtable.loadJson("template.json");
//    //jtable.saveJsonAs("template2.json");

//    //qDebug() << jtable.getRowMaxHeight(jtable.table[1].toArray());

////    style = jtable.createStyle(50, 60);
////    item = jtable.createObject("text", "FOR TEST", style);
////    item = jtable.updateObjectStyle(item, "height", 120);
////    QByteArray bytes = jtable.toByteArray(item);
////    stream << bytes << endl;


////    row = jtable.table[0].toArray();
////    row = jtable.updateRowStyle(row, "height", 130);
////    QByteArray arrays = jtable.toByteArray(row);
////    stream << arrays << endl;


////    jtable.updateTableRowHeight();
////    QByteArray arrays = jtable.toByteArray();
////    stream << arrays << endl;



//    //row-0-0
//    //QJsonArray items;
////    style = jtable.createStyle(0, 10);
////    items = jtable.createObjects("text", {"item1", "item2", "item3", "item4", "item5"} , style);
////    row = jtable.addArrayToRow(row, items);
////    jtable.addRowToTable(row);
////    row = jtable.emptyJsonArray(row);

////    style = jtable.createStyle(30, 20);
////    items = jtable.createObjects("text", {"item1", "item2", "item30", "item40", "item50"} , style);
////    row = jtable.addArrayToRow(row, items);
////    jtable.addRowToTable(row);
////    row = jtable.emptyJsonArray(row);

////    //new page with empty array-row
////    jtable.addRowToTable();


////    style = jtable.createStyle(0, 30);
////    item = jtable.createObject("text", "item1", style);
////    row = jtable.addObjectToRow(row, item);
////    items = jtable.createObjects("text", {"item2", "item30"} , style);
////    row = jtable.addArrayToRow(row, items);
////    jtable.addRowToTable(row);
//    row = jtable.emptyJsonArray(row);

//    style = jtable.createStyle("DSLAM",0, 20,"#f00", "#efe","Times", 18,true,"left",0 );
//    item = jtable.createObject("text", "item-1 fixed WH" , style);
//    jtable.addObjectToRow(row, item);

//    style = jtable.createStyle("DSLAM", 0, 21,"#f00", "#efe","Times", 18,true,"left",0 );
//    item = jtable.createObject("text", "item-2 fixed H" , style);
//    jtable.addObjectToRow(row, item);

//    style = jtable.createStyle("METRO", 0, 0,"#f00", "#efe","Times", 18,true,"left",0 );
//    item = jtable.createObject("text", "item-3 auto" , style);
//    jtable.addObjectToRow(row, item);

//    jtable.addRowToTable(row);
//    row = jtable.emptyJsonArray(row);


//    row = jtable.emptyJsonArray(row);

//    style = jtable.createStyle("DSLAM",0, 0,"#f00", "#efe","Times", 18,true,"left",0 );
//    item = jtable.createObject("text", "item-1 auto W and H test" , style);
//    jtable.addObjectToRow(row, item);

//    style = jtable.createStyle("DSLAM", 0, 22,"#f00", "#efe","Times", 18,true,"left",0 );
//    item = jtable.createObject("text", "item-2 this is another text" , style);
//    jtable.addObjectToRow(row, item);

//    style = jtable.createStyle("METRO", 0, 0,"#f00", "#efe","Times", 18,true,"left",0 );
//    item = jtable.createObject("text", "item-3 again another object. this is a long text to check word wrap. it will be two line cell" , style);
//    jtable.addObjectToRow(row, item);

//    jtable.addRowToTable(row);
//    row = jtable.emptyJsonArray(row);


    // table 2

    //table content
    JsonTable *table = new JsonTable(50, "#000", "#ddd", "tahoma",16);

    style = table->createStyle("table-header", 0, 0, "#333", "#fbd","tahoma", 20, true, "center",2);
    row = table->createObjects("text", {"Exchange", "saloon", "Device", "Interface"},style);
    table->addRowToTable(row);

    style = table->createStyle("device",0, 0, "#444", "#fef","tahoma", 16, false, "left",1);
    row = table->createObjects("text", {"DSLAM-1 Here i want to create a long text to check cell fair occupation.", "Switch - Data", "CX600X16", "10G 2/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-2", "Data", "CX600X16", "10G 2/0/0"},style);
    table->addRowToTable(row);

    //table->addRowToTable(); // empty row for new page

    //new page
    //    style = table->createStyle(0, 0, "#333", "#fbd","tahoma", 20, true, "center",2);
    //    row = table->createObjects("text", {"Exchange", "saloon", "Device", "Interface"},style);
    //    table->addRowToTable(row);

    //    style = table->createStyle(0, 0, "#444", "#fef","tahoma", 16, false, "left",1);
    row = table->createObjects("text", {"DSLAM-3", "PCM", "CX600X16", "10G 3/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-4", "Switch", "CX600X16", "1G 10/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-5", "Switch", "CX600X16", "10G 11/0/0"},style);
    table->addRowToTable(row);



    row = table->createObjects("text", {"DSLAM-6", "PCM", "CX600X16", "10G 3/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-7", "Switch", "CX600X16", "1G 10/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-8", "Switch", "CX600X16", "10G 11/0/0"},style);
    table->addRowToTable(row);



    row = table->createObjects("text", {"DSLAM-9", "PCM", "CX600X16", "10G 3/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-10", "Switch", "CX600X16", "1G 10/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-11", "Switch", "CX600X16", "10G 11/0/0"},style);
    table->addRowToTable(row);



    row = table->createObjects("text", {"DSLAM-12", "PCM", "CX600X16", "10G 3/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-13", "Switch", "CX600X16", "1G 10/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-14", "Switch", "CX600X16", "10G 11/0/0"},style);
    table->addRowToTable(row);



    row = table->createObjects("text", {"DSLAM-15", "PCM", "CX600X16", "10G 3/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-16", "Switch", "CX600X16", "1G 10/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-17", "Switch", "CX600X16", "10G 11/0/0"},style);
    table->addRowToTable(row);



    row = table->createObjects("text", {"DSLAM-18", "PCM", "CX600X16", "10G 3/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-19", "Switch", "CX600X16", "1G 10/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-20", "Switch", "CX600X16", "10G 11/0/0"},style);
    table->addRowToTable(row);



    row = table->createObjects("text", {"DSLAM-21", "PCM", "CX600X16", "10G 3/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-22", "Switch", "CX600X16", "1G 10/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-23", "Switch", "CX600X16", "10G 11/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-24", "PCM", "CX600X16", "10G 3/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-25", "Switch", "CX600X16", "1G 10/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-26", "Switch", "CX600X16", "10G 11/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-27", "PCM", "CX600X16", "10G 3/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-28", "Switch", "CX600X16", "1G 10/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-29", "Switch", "CX600X16", "10G 11/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-30", "PCM", "CX600X16", "10G 3/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-31", "Switch", "CX600X16", "1G 10/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-32", "Switch", "CX600X16", "10G 11/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-33", "PCM", "CX600X16", "10G 3/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-34", "Switch", "CX600X16", "1G 10/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-35", "Switch", "CX600X16", "10G 11/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-36", "PCM", "CX600X16", "10G 3/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-37", "Switch", "CX600X16", "1G 10/0/0"},style);
    table->addRowToTable(row);

    row = table->createObjects("text", {"DSLAM-38", "Switch", "CX600X16", "10G 11/0/0"},style);
    table->addRowToTable(row);


    table->updateFairCell(1517, true);
    table->updateRowSpan(true);

    table->saveJsonAs("jt.json");
    //jtable.updateHeight();
    //jtable.updateColumnsWidth(1500);

//#if QT_VERSION > 0x051210
//    stream << table->toByteArray() << Qt::endl;
//#else
//    stream << jtable->toByteArray() << endl;
//#endif

    //qDebug() << jtable.getHeight(0,3);


//    QFont font("tahoma", 12); // works on gui application
//    font.setBold(false);
//    QFontMetrics fm(font);
//    QString value = "i";
//    //double width = fm.boundingRect(value).width(); //fm.width("Hello"); 183
//    double width = fm.horizontalAdvance(value); // 188
//    qDebug() << "string width is : " << width;


    return 1;
}
