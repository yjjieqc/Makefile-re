# C++面向对象

### C++中的空类默认会产生哪些类成员函数

+ 默认构造函数和复制函数。它们被用于类的对象构造过程。
+ 析构函数。用于类的对象的析构过程
+ 复制函数。用于同类对象之间的赋值
+ 取值函数。当类的对象进行取地址符（&）时此函数被调用。
```c
class empty{
    public:
empty();
empty(const empty &);
~empty();
empty & operator= (const empty &);
empty * operator& ()const;
}
```
