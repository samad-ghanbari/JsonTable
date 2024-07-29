#include "jsontable.h"
#include <QFile>
#include <QByteArray>
#include <QJsonParseError>
#include <QFontMetrics> // gui config
#include <QPixmap>

JsonTable::JsonTable(double _default_height, QString _default_background_color, QString _default_color, QString _default_font_family, double _default_font_size, QObject *parent )
    : QObject{parent}
{
    this->default_height = _default_height;
    this->default_background_color = _default_background_color;
    this->default_color = _default_color;
    this->default_font_size = _default_font_size;
    this->default_font_family = _default_font_family;
}

QJsonObject JsonTable::createStyle(QString _name, double _width, double _height, QString _color, QString _backgroundColor, QString _fontFamily, double _fontSize, bool _bold, QString _align, int _border, int _rowSpan)
{
    QJsonObject obj;
    obj["name"] = _name;
    obj["width"] = (_width < 0)? 0 : _width;
    obj["height"] = (_height == 0)? default_height : _height;
    obj["occupy"] = -1;
    obj["background-color"] = (_backgroundColor.isNull())? default_background_color : _backgroundColor ;
    obj["color"] = (_color.isNull())? default_color : _color;
    obj["font-size"]= (_fontSize == 0)? default_font_size : _fontSize;
    obj["font-family"]= (_fontFamily.isNull())? default_font_family : _fontFamily;
    obj["bold"]= _bold;
    obj["align"]= _align;// left center right
    obj["border"] = _border;
    obj["row-span"] = _rowSpan; // 0:default -1:skip n>0:n-span this field will be updated by rowSpanAnalyser
    return obj;
}

QJsonObject JsonTable::createObject(QString _type, QString _value, QJsonObject _style)
{
    QJsonObject obj;
    obj["type"] = _type;
    obj["value"] = _value;
    obj["style"] = _style;
    // update occupy
    obj = updateObjectOccupy(obj);

    return obj;
}

QJsonArray JsonTable::createObjects(QString _type, QStringList _values, QJsonObject _style)
{
    QJsonArray array;
    QJsonObject obj;
    for(int i=0 ; i < _values.size() ; i++  )
    {
        obj["type"] = _type;
        obj["value"] = _values[i];
        obj["style"] = _style;
        // update occupy
        obj = updateObjectOccupy(obj);

        array.append(obj);
    }

    return array;
}

QJsonArray JsonTable::addObjectToRow(QJsonArray &row, QJsonObject item)
{
    row.append(item);
    return row;
}

QJsonArray JsonTable::addArrayToRow(QJsonArray &row, QJsonArray array)
{
    for(int i=0; i<array.count(); i++)
    {
        row.append(array[i].toObject());
    }

    return row;
}

void JsonTable::addRowToTable(QJsonArray &row)
{
    table.append(row);
}

void JsonTable::addRowToTable()
{
    // add empty row
    QJsonArray row;
    table.append(row);
}

bool JsonTable::isEmptyArray(int row)
{
    QJsonArray Row = table[row].toArray();
    if(Row.count()==0)
        return true;
    else
        return false;
}

QJsonArray JsonTable::emptyJsonArray(QJsonArray &array)
{
    while(array.count() > 0)
        array.removeAt(0);

    return array;
}

QByteArray JsonTable::toByteArray()
{
    QJsonDocument doc(table);
    QByteArray bytes = doc.toJson(QJsonDocument::Indented);
    return bytes;
}

QByteArray JsonTable::toByteArray(QJsonObject obj)
{
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson(QJsonDocument::Indented);
    return bytes;
}

QByteArray JsonTable::toByteArray(QJsonArray array)
{
    QJsonDocument doc(array);
    QByteArray bytes = doc.toJson(QJsonDocument::Indented);
    return bytes;
}

bool JsonTable::saveJsonAs(QString fileName)
{
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly))
        return false;

    QJsonDocument doc(table);
    QByteArray bytes = doc.toJson(QJsonDocument::Indented);

    file.write(bytes);
    file.close();
    return true;
}

bool JsonTable::loadJson(QString fileName)
{
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly))
        return false;

    QByteArray bytes = file.readAll();

    QJsonParseError parsError;
    QJsonDocument doc = QJsonDocument::fromJson(bytes, &parsError);

    if(parsError.error != QJsonParseError::NoError)
        return false;

    table = doc.array();
    return true;
}

float JsonTable::getRowMaxHeight(QJsonArray array)
{
    double maxHeight = 0, height;
    QJsonObject item, style;
    for (int i=0; i < array.count(); i++)
    {
        item = array.at(i).toObject();
        style = item.value("style").toObject();
        height = style.value("height").toDouble();
        if(maxHeight < height)
            maxHeight = height;
    }

    if(maxHeight > 100) maxHeight = 100;
    return maxHeight;
}

QJsonObject JsonTable::updateObjectStyle(QJsonObject _object, QString _key, double _val)
{
    QJsonObject style;
    if(_object.contains("style"))
    {
        style = _object["style"].toObject();
        if( style.contains(_key) )
            style[_key] = _val;

        _object["style"] = style;
    }

    return _object;
}

QJsonArray JsonTable::updateRowStyle(QJsonArray row, QString key, double val)
{
    QJsonObject item;
    for(int i=0; i < row.count(); i++)
    {
        item = this->updateObjectStyle(row.at(i).toObject(), key , val);
        row.removeAt(i);
        row.insert(i, item);
    }

    return row;
}

void JsonTable::updateTableRowHeight()
{
    double maxHeight;
    QJsonArray row;
    for(int i = 0; i < table.count(); i++ )
    {
        maxHeight = this->getRowMaxHeight(table[i].toArray());
        row = this->updateRowStyle(table[i].toArray(), "height", maxHeight);
        table.removeAt(i);
        table.insert(i, row);
    }
}

void JsonTable::updateObjectHeight(int row, int column, double height)
{
    QJsonArray Row = table[row].toArray();
    QJsonObject obj = Row[column].toObject();
    obj = updateObjectStyle(obj, "height", height);

    Row.removeAt(column);
    Row.insert(column, obj);

    table.removeAt(row);
    table.insert(row, Row);
}

double JsonTable::getHeight(int startRow, int endRow)
{
    double height=0;
    QJsonArray row;
    QJsonObject obj;

    int lastRow = table.count() -1 ;
    if(endRow > lastRow) endRow = lastRow;

    for(int i=startRow;  i <= endRow; i++)
    {
        row = table[i].toArray();
        if(row.count() > 0)
        {
            obj = row[0].toObject();
            height += obj["style"].toObject()["height"].toDouble();
        }
    }

    return height;
}

QJsonObject JsonTable::getRowObject(int row, int index)
{
    QJsonObject obj = table[row].toArray()[index].toObject();
    return obj;
}

QString JsonTable::getType(int row, int index)
{
    QJsonObject obj = table[row].toArray()[index].toObject();
    QString type = obj.value("type").toString();
    return type;
}

QString JsonTable::getValue(int row, int index)
{
    QJsonObject obj = table[row].toArray()[index].toObject();
    QString value = obj.value("value").toString();
    return value;
}

QJsonObject JsonTable::getStyle(int row, int index)
{
    QJsonObject obj = table[row].toArray()[index].toObject();
    obj = obj.value("style").toObject();
    return obj;
}

int JsonTable::getObjectRowSpan(int row, int index)
{
    QJsonObject obj = table[row].toArray()[index].toObject();
    int value = obj["style"].toObject()["row-span"].toInt();
    return value;
}

bool JsonTable::setObjectRowSpan(int row, int index, int rowSpan)
{
    QJsonArray array = table[row].toArray();
    QJsonObject obj = array[index].toObject();
    QJsonObject style = obj["style"].toObject();
    style["row-span"] = rowSpan;
    obj["style"] = style;
    array.removeAt(index);
    array.insert(index, obj);
    table.removeAt(row);
    table.insert(row,array);

    int span = table[row].toArray()[index].toObject()["style"].toObject().value("row-span").toInt();
    if(span == rowSpan) return true; else return false;
}

bool JsonTable::updateObjectRowSpan(int row, int index, bool SPAN)
{
    int span = 1;
    bool res = true;
    QString baseValue = this->getValue(row, index);
    int baseSpan = this->getObjectRowSpan(row, index);
    if(baseSpan != 0) return res;

    if(isEmptyArray(row)) return true;

    if( (row == (table.count()-1)) || !SPAN )
    {
        res = res && setObjectRowSpan(row, index, span);
        return res;
    }

    QString tempValue;
    for(int r=row+1; r<table.count(); r++)
    {
        if(table[r].toArray().count() >= index)
        {
            tempValue = getValue(r, index);
            if(baseValue.compare(tempValue, Qt::CaseSensitive) == 0)
            {
                span++;
                res = res && setObjectRowSpan(row, index, span);
                res = res && setObjectRowSpan(r, index, -1);
            }
            else
            {
                res = res && setObjectRowSpan(row, index, span);
                break;
            }
        }
        else
        {
            res = res && setObjectRowSpan(row, index, span);
            break;
        }
    }

    return res;
}

bool JsonTable::updateArrayRowSpan(int row, bool SPAN)
{
    QJsonArray Row = table[row].toArray();
    bool res = true;
    for(int i=0; i<Row.count(); i++)
    {
        res = res && updateObjectRowSpan(row,i, SPAN);
    }
    return res;
}

bool JsonTable::updateTableRowSpan(bool SPAN)
{
    bool res = true;
    for(int r=0; r<table.count(); r++)
    {
        res = res && updateArrayRowSpan(r, SPAN);
    }
    return res;
}

bool JsonTable::updateTableRowSpan(int ColumnIndex)
{
    bool res = true;
    for(int r=0; r<table.count(); r++)
    {
        res = res && updateObjectRowSpan(r,ColumnIndex);
    }
    return res;
}

void JsonTable::updateColumnsWidth(double viewPortWidth)
{
    QJsonArray row;
    QJsonObject obj;
    QList<int> zeroIndexes;
    double width, usedWidth;
    int rowCount;
    for(int r=0; r < table.count(); r++)
    {
        row = table[r].toArray();
        zeroIndexes.clear();
        usedWidth = 0;
        rowCount = row.count();
        // one row
        for(int o=0; o < row.count(); o++)
        {
            obj = row[o].toObject();
            width = obj["style"].toObject()["width"].toDouble();
            if(width <= 0)
                zeroIndexes << o;
            else
                usedWidth += width;
        }

        int zeroLen = zeroIndexes.length();
        if(zeroLen == rowCount)
        {
            // width all zero-width object
            // same width
            width = viewPortWidth / rowCount;
            //update row object
            updateRowWidth(r,width);
        }
        else if(zeroLen < rowCount)
        {
            double leftWidth = viewPortWidth - usedWidth;
            double width = leftWidth / zeroLen;
            updateRowWidth(r,zeroIndexes, width);
        }
    }
}

void JsonTable::updateTableFineOccupation(double viewPortWidth)
{
    // checks width and height
    // * given width and hight    : no change
    // * given width and height=0 : hight calculation - for wrap
    // * width=0 and given hight  : width = max possible occupy
    // * width=0 and hight=0      : fine width then hight calculation

    QJsonArray Row;
    QJsonObject Obj;
    QMap<QString, double> whc; // width-height-occupy
    double usedWidth, width, height, occupy, fontSize;
    int counter;

    for(int r=0; r < table.count(); r++)
    {
        Row = table[r].toArray();
        usedWidth = 0;
        for(int c=0; Row.count(); c++)
        {
            Obj = Row[c].toObject();
            whc = getWidthHeightOccupy(Obj);
            fontSize = Obj["style"].toObject()["font-size"].toDouble();

             // * given width and hight
            if( (whc.value("width") > 0 ) && (whc.value("height") > 0) )
            {
                width = whc.value("width");
                columnWidth[c] =width;
                usedWidth += width;
                continue;
            }
            // * given width and height=0 - TWO times wrap allowed
            if( (whc.value("width") > 0 ) && (whc.value("height") == 0) )
            {
                width = whc.value("width");
                occupy = whc.value("occupy");
                columnWidth[c] =width;
                usedWidth += width;

                if(width < occupy)
                {
                    counter = 0;
                    if(width < (occupy/2) )
                        counter++;
                    if(width < (occupy/4) )
                        counter++;

                    height = fontSize + counter * fontSize;
                }
                else height = fontSize;

                updateObjectHeight(r,c, height);
                continue;
            }
            // * width=0 and given hight
            if( (whc.value("width") == 0 ) && (whc.value("height") > 0) )
            {
            }
            // * width=0 and hight=0
            if( (whc.value("width") == 0 ) && (whc.value("height") == 0) )
            {
            }
        }
    }
}

QMap<QString, double> JsonTable::getWidthHeightOccupy(QJsonObject obj)
{
    QJsonObject style = obj["style"].toObject();
    double width = style["width"].toDouble();
    double height = style["height"].toDouble();
    double occupy = style["occupy"].toDouble();

    QMap<QString, double> map;
    map["width"] = width;
    map["height"] = height;
    map["occupy"] = occupy;

    return map;
}

double JsonTable::getTableMaxOccupy(int column)
{
    double occupy = 0, temp;
    QJsonArray Row;
    QJsonObject obj;
    for(int r=0; r<table.count(); r++)
    {
        Row = table[r].toArray();
        obj = Row[column].toObject();

        temp = obj["style"].toObject()["occupy"].toDouble();

        if(temp > occupy)
            occupy = temp;
    }

    return occupy;
}

void JsonTable::updateRowWidth(int row, double width)
{
    QJsonArray Row = table[row].toArray();
    QJsonObject obj;
    for( int o=0; o < Row.count(); o++)
    {
        obj = Row[o].toObject();
        obj = updateObjectStyle(obj,"width", width);
        Row.removeAt(o);
        Row.insert(o, obj);
    }

    table.removeAt(row);
    table.insert(row, Row);
}

void JsonTable::updateRowWidth(int row, QList<int> index, double width)
{
    QJsonArray Row = table[row].toArray();
    QJsonObject obj;
    for( int o=0; o < Row.count(); o++)
    {
        if(index.contains(o))
        {
            obj = Row[o].toObject();
            obj = updateObjectStyle(obj,"width", width);
            Row.removeAt(o);
            Row.insert(o, obj);
        }
    }

    table.removeAt(row);
    table.insert(row, Row);
}

double JsonTable::calculateObjectOccupy(QJsonObject &obj)
{
    QString fontFamily = obj["style"].toObject()["font-family"].toString();
    int fontSize = obj["style"].toObject()["font-size"].toInt();
    double width = obj["style"].toObject()["width"].toDouble();
    bool bold = obj["style"].toObject()["bold"].toBool();

    QString value = obj["value"].toString();
    QString type =  obj["type"].toString();
    if(type.compare("img", Qt::CaseInsensitive) == 0)
    {
        if(width > 0)
            return width;
        else
        {
            // find image width
            QPixmap img(value);
            width = img.size().width();
            return width;
        }
    }

    //text-value object
    QFont font(fontFamily, fontSize);
    //font.setPointSize(fontSize);
    font.setBold(bold);
    QFontMetrics fm(font);
    width = fm.horizontalAdvance(value);
    return width;
}

void JsonTable::updateObjectOccupy(int row, int column)
{
    QJsonArray Row = table[row].toArray();
    QJsonObject obj = Row[column].toObject();

    obj = updateObjectOccupy(obj);

    Row.removeAt(column);
    Row.insert(column, obj);

    table.removeAt(row);
    table.insert(row, Row);
}

QJsonObject JsonTable::updateObjectOccupy(QJsonObject obj)
{
    double occupy = calculateObjectOccupy(obj);
    QJsonObject style = obj["style"].toObject();
    QString value = obj["value"].toString();
    QString type = obj["type"].toString();

    if(type.compare("text", Qt::CaseInsensitive) == 0)
    {
        // check occupy validation
        int len = value.length();
        // consider minimum pixel count to reprtesent character
        int min = 2;
        double temp = len * min;
        if(occupy < temp)
            occupy = temp;
    }

    style["occupy"] = occupy;
    obj.remove("style");
    obj["style"] = style;

    return obj;
}



