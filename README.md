# 通过Qt操作json

Qt中主要通过QJsonValue、QJsonObject、QJsonArray、QJsonDocument四个类对json进行操作。

## 一、QJsonValue类
### 1.QJsonValue类介绍
QJsonValue类封装了JSON中的值。JSON中的值有6种基本类型：
value可以是以上任何一种数据类型。另外，QJsonValue有一个特殊的flag来表示未定义类型。可以用isUndefined()来查询。
可以用type()或isBool(),、isString()等来查询value的类型。类似的，可以用toBool()、toString()等将一个value转换成存储在该value内部的类型。

### 2.QJsonValue成员方法
```c++
QJsonValue(QJsonValue::Type type = Null)
    QJsonValue(bool b)
    QJsonValue(double n)
    QJsonValue(int n)
    QJsonValue(qint64 n)
    QJsonValue(const QString &s)
    QJsonValue(QLatin1String s)
    QJsonValue(const char *s)
    QJsonValue(const QJsonArray &a)
    QJsonValue(const QJsonObject &o)
    QJsonValue(const QJsonValue &other)
    QJsonValue(QJsonValue &&other)
    ~QJsonValue()
    bool isArray() const
    bool isBool() const
    bool isDouble() const
    bool isNull() const
    bool isObject() const
    bool isString() const
    bool isUndefined() const
    void swap(QJsonValue &other)
    QJsonArray toArray(const QJsonArray &defaultValue) const
    QJsonArray toArray() const
    bool toBool(bool defaultValue = false) const
    double toDouble(double defaultValue = 0) const
    int toInt(int defaultValue = 0) const
    QJsonObject toObject(const QJsonObject &defaultValue) const
    QJsonObject toObject() const
    QString toString() const
    QString toString(const QString &defaultValue) const
    QVariant toVariant() const
    QJsonValue::Type type() const
    bool operator!=(const QJsonValue &other) const
    QJsonValue &operator=(const QJsonValue &other)
    QJsonValue &operator=(QJsonValue &&other)
    bool operator==(const QJsonValue &other) const
    const QJsonValue operator[](const QString &key) const
    const QJsonValue operator[](QLatin1String key) const
    const QJsonValue operator[](int i) const
```
### 3.QJsonValue成员方法介绍
```c++
[static] QJsonValue QJsonValue::fromVariant(const QVariant &variant)
    将variant转换为QJsonValue
    bool QJsonValue::isArray() const
    如果QJsonValue包含一个数组，返回true
    bool QJsonValue::isBool() const
    如果QJsonValue包含一个bool，返回true
    bool QJsonValue::isDouble() const
    如果QJsonValue包含一个double，返回true
    bool QJsonValue::isNull() const
    如果QJsonValue包含一个Null，返回true
    bool QJsonValue::isObject() const
    如果QJsonValue包含一个object，返回true
    bool QJsonValue::isString() const
    如果QJsonValue包含一个string，返回true
    bool QJsonValue::isUndefined() const
    如果QJsonValue包含一个undefined，返回true
    QJsonArray QJsonValue::toArray(const QJsonArray &defaultValue) const
    将QJsonValue转换为QJsonArray并返回，如果类型不是array，返回默认值defaultValue
    QJsonArray QJsonValue::toArray() const
    将QJsonValue转换为QJsonArray并返回
    bool QJsonValue::toBool(bool defaultValue = false) const
    将QJsonValue转换为bool并返回
    double QJsonValue::toDouble(double defaultValue = 0) const
    将QJsonValue转换为double并返回
    int QJsonValue::toInt(int defaultValue = 0) const
    将QJsonValue转换为int并返回
    QJsonObject QJsonValue::toObject(const QJsonObject &defaultValue) const
    QJsonObject QJsonValue::toObject() const
    将QJsonValue转换为QJsonObject并返回
    QString QJsonValue::toString(const QString &defaultValue = QString()) const
    将QJsonValue转换为QString并返回
    Type QJsonValue::type() const
    返回QJsonValue的类型
```

