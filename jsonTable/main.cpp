#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>

#include "jsontable.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    JsonTable jtable(20,"#eee", "#000", 14, "Tahoma");
    QJsonObject style, cell;
    QJsonArray row;


    //2 rows

    //row-0-0
    style = jtable.createStyle(20);
    cell = jtable.createCell("text", "Row0-0", style);
    row = jtable.addCell(row, cell);
    //row-0-1
    cell = jtable.createCell("text", "Row0-1", style);
    row = jtable.addCell(row, cell);
    //row-0-2
    cell = jtable.createCell("text", "Row0-2", style);
    row = jtable.addCell(row, cell);
    //row-0-3
    cell = jtable.createCell("text", "Row0-3", style);
    row = jtable.addCell(row, cell);
    //row-0-4
    cell = jtable.createCell("text", "Row0-4", style);
    row = jtable.addCell(row, cell);


    jtable.addRow(row);
    row = jtable.emptyJsonArray(row);

    //row-1-0
    style = jtable.createStyle(20);
    cell = jtable.createCell("text", "Row1-0", style);
    row = jtable.addCell(row, cell);
    //row-1-1
    cell = jtable.createCell("text", "Row1-1", style);
    row = jtable.addCell(row, cell);
    //row-1-2
    cell = jtable.createCell("text", "Row1-2", style);
    row = jtable.addCell(row, cell);
    //row-1-3
    cell = jtable.createCell("text", "Row1-3", style);
    row = jtable.addCell(row, cell);
    //row-1-4
    cell = jtable.createCell("text", "Row1-4", style);
    row = jtable.addCell(row, cell);


    jtable.addRow(row);
    row = jtable.emptyJsonArray(row);


    //QTextStream stream(stdout);
    //stream << jtable.toByteArray() << endl;

    //jtable.loadJson("template.json");
    jtable.saveJsonAs("template2.json");





    return a.exec();
}
