#include <QCoreApplication>
#include <QDebug>

#include <QJsonObject> //{ }
#include <QJsonArray> // [ ]
#include <QJsonDocument> // 解析Json
#include <QJsonValue> // int float double bool null { } [ ]
//#include <QJsonParseError>
#include <QFile>


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    qDebug() << "Hello World";
    /*
**********************************************************************
  *
  * 构造json文件
  *
**********************************************************************
  */
    qDebug()<<"开始构造json对象";
    //构造{ }对象
    //QJsonObject insterstObj;
    //insterstObj.insert("basketball","篮球");
    //insterstObj.insert("badminton","羽毛球");

    //构造{ }对象方法2
    QJsonObject insterstObj
            {
                    {"basketball","篮球"},
                    {"badminton","羽毛球"}
            };

    //构造[ ]数组对象
    //QJsonArray colorArray;
    //colorArray.append("black");
    //colorArray.append("white");

    //构造[ ]数组对象方法2
    QJsonArray colorArray={"black","white"};

    //构造[{},{}]对象
    QJsonObject likeObject1;
    likeObject1.insert("game", "三国杀");
    likeObject1.insert("price", 58.5);

    QJsonObject likeObject2;
    likeObject2.insert("game", "海岛奇兵");
    likeObject2.insert("price", 66.65);

    QJsonArray likeArray;
    likeArray.append(likeObject1);
    likeArray.append(likeObject2);

    //构造{{} ，{}}对象
    QJsonObject language1;
    language1.insert("language", "汉语");
    language1.insert("grade", 10);

    QJsonObject language2;
    language2.insert("language", "英语");
    language2.insert("grade", 6);

    QJsonObject languages;
    languages.insert("serialOne", language1);
    languages.insert("serialTwo", language2);

    //将对象全部组合到根对象
    QJsonObject rootObject;
    rootObject.insert("name", "王五");
    rootObject.insert("age", 26);
    rootObject.insert("interest", insterstObj);
    rootObject.insert("color", colorArray);
    rootObject.insert("like", likeArray);
    rootObject.insert("languages", languages);
    rootObject.insert("vip", true);
    rootObject.insert("address", QJsonValue::Null);

    // 实例化QJsonDocument对象
    QJsonDocument jsonDoc;
    jsonDoc.setObject(rootObject);

    // QJsonDocument对象可以转换成QByteArray或QVariant对象
    //QByteArray bytearray = jsonDoc.toJson();     //转换成QByteArray
    //qDebug()<<bytearray;
    //QVariant variant=jsonDoc.toVariant();        //转换成QVariant
    //qDebug()<<variant.toString();

    qDebug()<<"保存json数据文件";
    // 保存到json文件
    QFile file_write("../json/js.json");
    if (!file_write.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qDebug() << "打开json文件错误！";
        return 0;
    }
    QTextStream stream_out(&file_write);
    QByteArray bytearray = jsonDoc.toJson();     //转换成QByteArray
    stream_out << bytearray;
    qDebug()<<"成功保存json文件";
    file_write.close();

    qDebug()<<"--------------------------------------------------------------------";
    /*
***********************************************************************
     *
     * 解析json文件
     *
***********************************************************************
     */
    QFile file_read("../json/js.json");
    if (!file_read.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "打开json文件错误！";
        return 0;
    }
    QTextStream stream_in(&file_read);
    QString str = stream_in.readAll();
    file_read.close();

    // QJsonParseError类用于在JSON解析期间报告错误。
    QJsonParseError jsonError;
    // 将json解析为UTF-8编码的json文档，并从中创建一个QJsonDocument。
    // 如果解析成功，返回QJsonDocument对象，否则返回null
    QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8(), &jsonError);
    // 判断是否解析失败
    if (jsonError.error != QJsonParseError::NoError && !doc.isNull()) {
        qDebug() << "Json格式错误！" << jsonError.error;
        return 0;
    }
    // 获取根{}
    QJsonObject rootObj=doc.object();

    // 获取所有一级字段数据
    QJsonValue nameValue = rootObj.value("name");
    qDebug()<<"name="<<nameValue.toString();
    QJsonValue ageValue = rootObj.value("age");
    qDebug()<<"age="<<ageValue.toInteger();
    QJsonValue vipValue = rootObj.value("vip");
    qDebug()<<"vip="<<vipValue.toBool();

    // 解析{ }对象
    QJsonValue interestValue = rootObj.value("interest");
    // 判断是否是object类型
    if (interestValue.type() == QJsonValue::Object) {
        // 转换为QJsonObject类型
        QJsonObject interestObj = interestValue.toObject();
        QJsonValue basketballValue = interestObj.value("basketball");
        qDebug() << "basketball = " << basketballValue.toString();
        QJsonValue badmintonValue = interestObj.value("badminton");
        qDebug() << "badminton = " << badmintonValue.toString();
    }

    // 解析 { {} {} } 嵌套对象
    QJsonValue languagesValue = rootObj.value("languages");
    if (languagesValue.type() == QJsonValue::Object) {
        QJsonObject languagesObj = languagesValue.toObject();
        // 解析serialOne对象
        QJsonValue serialOneValue = languagesObj.value("serialOne");
        if (serialOneValue.type() == QJsonValue::Object) {
            QJsonObject serialOneObj = serialOneValue.toObject();
            QJsonValue languageValue = serialOneObj.value("language");
            qDebug() << "language = " << languageValue.toString();
            QJsonValue gradeValue = serialOneObj.value("grade");
            qDebug() << "grade = " << gradeValue.toInt();
        }
        // 解析serialTwo对象
        QJsonValue serialTwoValue = languagesObj.value("serialTwo");
        if (serialTwoValue.type() == QJsonValue::Object) {
            QJsonObject serialTwoObj = serialTwoValue.toObject();
            QJsonValue languageValue = serialTwoObj.value("language");
            qDebug() << "language = " << languageValue.toString();
            QJsonValue gradeValue = serialTwoObj.value("grade");
            qDebug() << "grade = " << gradeValue.toInt();
        }
    }

    //解析[]数组
    QJsonValue colorValue = rootObj.value("color");
    if (colorValue.type() == QJsonValue::Array) {
        // 转换为QJsonArray类型
        QJsonArray colorarray = colorValue.toArray();
        for (auto && color : colorarray) {
            qDebug() << "color = " << color.toString();
        }
    }

    // 解析[{}{}]对象数组
    QJsonValue likeValue = rootObj.value("like");
    // 判断类型是否是数组类型
    if (likeValue.type() == QJsonValue::Array) {
        // 转换成数组类型
        QJsonArray likearray = likeValue.toArray();
        // 遍历数组
        for (auto && likeValueChild: likearray) {
            if (likeValueChild.type() == QJsonValue::Object) {
                // 转换成对象类型
                QJsonObject likeObj = likeValueChild.toObject();
                // 最后通过value函数就可以获取到值了，解析成功！也可以通过[]取到数据
                QJsonValue gameLikeValue = likeObj.value("game");
                qDebug() << "game = " << gameLikeValue.toString();
                QJsonValue priceLikeValue = likeObj.value("price");
                qDebug() << "price = " << priceLikeValue.toDouble();
            }
        }
    }
    return QCoreApplication::exec();
}
