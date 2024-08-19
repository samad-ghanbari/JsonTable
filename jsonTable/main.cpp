#include <QGuiApplication>
#include <QDebug>
#include <QTextStream>
#include <QFont>
#include <QFontMetrics>
//#include "jsontable.h"
#include "tableTemplate.h"

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    TableTemplate tableTemplate(4);
    tableTemplate.appendTitle({"img", "text","img"}, {":/danet.png", "DaNet Report", ":/tct.jpg"}, {"", "#005", ""});
    tableTemplate.appendTitle({"text", "text"}, {"2-BA Saloon Data", "1403/05/29"}, {"#050", "#500"});

    QJsonArray title = tableTemplate.getTitle(1500);
    QByteArray titleByteArray = tableTemplate.getTitleByteArray();

    tableTemplate.setTableHeader({"Area", "Exchange", "Device", "Lable"});
    tableTemplate.appentRow({"2", "BA", "CX600x16", "1G 1/0/0"});
    tableTemplate.appentRow({"2", "BA", "CX600x16", "1G 1/0/0"});
    tableTemplate.appentRow({"2", "BA", "CX600x16", "1G 1/0/0"});
    tableTemplate.appentRow({"2", "BA", "CX600x16", "1G 1/0/0"});
    tableTemplate.appentRow({"2", "BA", "CX600x16", "1G 1/0/0"});
    tableTemplate.appentRow({"2", "BA", "CX600x16", "1G 1/0/0"});
    tableTemplate.appentRow({"2", "BA", "CX600x16", "1G 1/0/0"});
    tableTemplate.appentRow({"2", "BA", "CX600x16", "1G 1/0/0"});
    tableTemplate.appentRow({"2", "BA", "CX600x16", "1G 1/0/0"});
    tableTemplate.appentRow({"2", "BA", "CX600x16", "1G 1/0/0"});
    tableTemplate.appentRow({"2", "BA", "CX600x16", "1G 1/0/0"});
    tableTemplate.appentRow({"2", "BA", "CX600x16", "1G 1/0/0"});
    tableTemplate.appentRow({"2", "BA", "CX600x16", "1G 1/0/0"});

    QJsonArray table = tableTemplate.getTable(1500,3);
    QByteArray tableByteArray = tableTemplate.getTableByteArray();

    QTextStream stream(stdout);

    #if QT_VERSION > 0x051210
        stream << titleByteArray << Qt::endl;
        stream << tableByteArray << Qt::endl;
    #else
        stream << titleByteArray << endl;
        stream << tableByteArray << endl;
    #endif


//    QFont font("tahoma", 12); // works on gui application
//    font.setBold(false);
//    QFontMetrics fm(font);
//    QString value = "i";
//    //double width = fm.boundingRect(value).width(); //fm.width("Hello"); 183
//    double width = fm.horizontalAdvance(value); // 188
//    qDebug() << "string width is : " << width;


    return 1;
}
