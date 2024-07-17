#include "jsontable.h"

JsonTable::JsonTable(int _default_height, QString _default_background_color, QString _default_color, int _default_font_size, QString _default_font_family,QObject *parent )
    : QObject{parent}
{
    this->default_height = _default_height;
    this->default_background_color = _default_background_color;
    this->default_color = _default_color;
    this->default_font_size = _default_font_size;
    this->default_font_family = _default_font_family;
}

QJsonObject JsonTable::createStyle(int _weight, int _height, QString _backgroundColor, QString _color, int _fontSize, QString _fontFamily)
{
    QJsonObject obj;
    obj["width-weight"] = _weight;
    obj["height"] = (_height == 0)? default_height : _height;
    obj["background-color"] = (_backgroundColor.isNull())? default_background_color : _backgroundColor ;
    obj["color"] = (_color.isNull())? default_color : _color;
    obj["font-size"]= (_fontSize == 0)? default_font_size : _fontSize;
    obj["font-family"]= (_fontFamily.isNull())? default_font_family : _fontFamily;
    return obj;
}

QJsonObject JsonTable::createCell(QString _type, QString _value, QJsonObject _style)
{
    QJsonObject obj;
    obj["type"] = _type;
    obj["value"] = _value;
    obj["style"] = _style;
    return obj;
}
