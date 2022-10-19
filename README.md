# 通过Qt操作json

Qt中主要通过QJsonValue、QJsonObject、QJsonArray、QJsonDocument四个类对json进行操作。

## 一、QJsonValue类
### 1.QJsonValue类介绍
QJsonValue类封装了JSON中的值。JSON中的值有6种基本类型：

- 数字（整数或浮点数）
- 字符串（在 “ ” ）
- 逻辑值（true 或 false）
- 数组（在 [ ] ）
- 对象（在 { } ）
- null

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



## 二、QJsonObject类

### 1.QJsonObject类简介

QJsonObject类用于封装JSON对象。JSON对象是包含键值对的链表，其中键是唯一的字符串，其值由QJsonValue对象。QJsonObject可以与QVariantMap相互转换，可以用size()来获得键值对的数目，insert()、remove()分别用来插入和删除pair。可以用标准C++的迭代器模式(iterator pattern)来迭代其内容。
QJsonObject是一个隐式共享的类，只要没有被改变过，QJsonObject会和创建它的document共享数据。可以通过QJsonDocument将QJsonObject和文本格式相互转换。

### 2.公有类型

```c++
class	const_iterator
class	iterator
typedef	ConstIterator
typedef	Iterator
typedef	key_type
typedef	mapped_type
typedef	size_type
```

### 3.公有成员方法

```c++
QJsonObject()
QJsonObject(std::initializer_list<QPair<QString, QJsonValue> > args)
QJsonObject(const QJsonObject &other)
QJsonObject(QJsonObject &&other)
~QJsonObject()
QJsonObject::iterator	begin()
QJsonObject::const_iterator	begin() const
QJsonObject::const_iterator	constBegin() const
QJsonObject::const_iterator	constEnd() const
QJsonObject::const_iterator	constFind(const QString &key) const
QJsonObject::const_iterator	constFind(QLatin1String key) const
bool	contains(const QString &key) const
bool	contains(QLatin1String key) const
int	count() const
bool	empty() const
QJsonObject::iterator	end()
QJsonObject::const_iterator	end() const
QJsonObject::iterator	erase(QJsonObject::iterator it)
QJsonObject::iterator	find(const QString &key)
QJsonObject::iterator	find(QLatin1String key)
QJsonObject::const_iterator	find(const QString &key) const
QJsonObject::const_iterator	find(QLatin1String key) const
QJsonObject::iterator	insert(const QString &key, const QJsonValue &value)
bool	isEmpty() const
QStringList	keys() const
int	length() const
void	remove(const QString &key)
int	size() const
void	swap(QJsonObject &other)
QJsonValue	take(const QString &key)
QVariantHash	toVariantHash() const
QVariantMap	toVariantMap() const
QJsonValue	value(const QString &key) const
QJsonValue	value(QLatin1String key) const
bool	operator!=(const QJsonObject &other) const
QJsonObject &	operator=(const QJsonObject &other)
QJsonObject &	operator=(QJsonObject &&other)
bool	operator==(const QJsonObject &other) const
QJsonValue	operator[](const QString &key) const
QJsonValue	operator[](QLatin1String key) const
QJsonValueRef	operator[](const QString &key)
QJsonValueRef	operator[](QLatin1String key)
```

### 4.公有成员方法解析

```c++
QJsonObject::QJsonObject(std::initializer_list<QPair<QString, QJsonValue> > args)
使用键值对链表构建QJsonObject对象

QJsonObject::QJsonObject(const QJsonObject &other)
构建QJsonObject对象
 
iterator QJsonObject::begin()
const_iterator QJsonObject::begin() const
返回指向JSON对象的第一个元素的STL风格的迭代器

const_iterator QJsonObject::constBegin() const
返回指向JSON对象的第一个元素的const STL风格的迭代器

const_iterator QJsonObject::constEnd() const
返回SJON对象的最后一个元素后的位置的const STL风格的迭代器

const_iterator QJsonObject::constFind(const QString &key) const
返回一个指向键值对中键为key的元素的const迭代器

bool QJsonObject::contains(const QString &key) const
如果JSON对象中包含键key，返回true

int QJsonObject::size() const
int QJsonObject::count() const
返回JSON对象中键值对的数量

bool QJsonObject::empty() const
bool QJsonObject::isEmpty() const
如果JSON对象为空，返回true

iterator QJsonObject::find(const QString &key)
const_iterator QJsonObject::find(const QString &key) const
返回指向JSON对象中键为key的键值对的迭代器

[static] QJsonObject QJsonObject::fromVariantHash(const QVariantHash &hash)
将hash转换为JSON对象

[static] QJsonObject QJsonObject::fromVariantMap(const QVariantMap &map)
将map转换为JSON对象

iterator QJsonObject::insert(const QString &key, const QJsonValue &value)
插入键为key，值为value的键值对，返回插入键值对的迭代器

QStringList QJsonObject::keys() const
返回JSON对象的所有键的链表

void QJsonObject::remove(const QString &key)
删除JSON对象中的key

QJsonValue QJsonObject::take(const QString &key)
删除JSON对象中的键key，返回key对应的QJsonValue

QVariantHash QJsonObject::toVariantHash() const
将JSON对象转换为QVariantHash

QVariantMap QJsonObject::toVariantMap() const
将JSON对象转换为QVariantMap

QJsonValue QJsonObject::value(const QString &key) const
返回key对应的QJsonValue值
```

### 5.参考示例

简单的JSON对象

```json
{
    "Cross Platform": true,
    "From": 1991,
    "Name": "Qt"
}
```

生成比较简单，只需要用 QJsonObject 即可。

```c++
// 构建 JSON 对象
QJsonObject json;
json.insert("Name", "Qt");
json.insert("From", 1991);
json.insert("Cross Platform", true);

// 构建 JSON 文档
QJsonDocument document;
document.setObject(json);
QByteArray byteArray = document.toJson(QJsonDocument::Compact);
QString strJson(byteArray);

qDebug() << strJson
```

简单的JSON解析

```c++
QJsonParseError jsonError;
// 转化为 JSON 文档
QJsonDocument doucment = QJsonDocument::fromJson(byteArray, &jsonError); 
// 解析未发生错误
if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError)) 
{  
    if (doucment.isObject()) 
    { 
        // JSON 文档为对象
        QJsonObject object = doucment.object();  // 转化为对象
        if (object.contains("Name")) 
        {  // 包含指定的 key
            QJsonValue value = object.value("Name");  // 获取指定 key 对应的 value
            if (value.isString()) 
            {  // 判断 value 是否为字符串
                QString strName = value.toString();  // 将 value 转化为字符串
                qDebug() << "Name : " << strName;
            }
        }
        if (object.contains("From")) 
        {
            QJsonValue value = object.value("From");
            if (value.isDouble()) 
            {
                int nFrom = value.toVariant().toInt();
                qDebug() << "From : " << nFrom;
            }
        }
        if (object.contains("Cross Platform")) 
        {
            QJsonValue value = object.value("Cross Platform");
            if (value.isBool()) 
            {
                bool bCrossPlatform = value.toBool();
                qDebug() << "CrossPlatform : " << bCrossPlatform;
            }
        }
    }
}
```



