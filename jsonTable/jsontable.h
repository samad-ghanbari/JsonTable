#ifndef JSONTABLE_H
#define JSONTABLE_H

#include <QObject>
// json
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonDocument>

class JsonTable : public QObject
{
    Q_OBJECT
public:
    explicit JsonTable(int _default_height, QString _default_background_color, QString _default_color, int _default_font_size, QString _default_font_family,QObject *parent = nullptr );
    QJsonObject createStyle(int _weight, int _height=0, QString _backgroundColor=NULL, QString _color=NULL, int _fontSize=0, QString _fontFamily=NULL);
    QJsonObject createCell(QString _type, QString _value, QJsonObject _style);
    QJsonArray addCell(QJsonArray &row, QJsonObject cell);
    void addRow(QJsonArray &row);
    QJsonArray emptyJsonArray(QJsonArray &array);
    QByteArray toByteArray();
    bool saveJsonAs(QString fileName);
    bool loadJson(QString fileName);



    QJsonArray json; // [ [ {}, {}, {}, ... ], [], [], [] ]
    QString default_background_color, default_color, default_font_family;
    int default_height, default_font_size;


signals:

};

#endif // JSONTABLE_H
