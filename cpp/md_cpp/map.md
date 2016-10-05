# C++ map 的用法
## 见下面链接（看这个，棒，超级详细清楚）

[C++容器（四）：map类型](http://blog.csdn.net/YhL_Leo/article/details/48849441)
## 2. 另一篇（写的不好）
map是一类关联式容器
1. **定义**
`#include <map>` 
> //为了使用方便，可以对模板类进行一下类型定义，
> typedef map<int, CString> UDT_MAP_INT_CSTRING;
> UDT_MAP_INT_CSTRING enumMap;

2. **在map中插入元素**
> enumMap[1] = "One";
> enumMap[2] = "Two";

3. **查找并获取map中的元素**
  1. 下标操作符
> CString tmp = enumMap[2];  //但是,只有当map中有这个键的实例时才对，否则会自动插入一个实例，值为初始化值。
  2. Find()和Count()
```
//begin()和end()两个成员，分别代表map对象中第一个条目和'末端元素的下一个'，这两个数据的类型是iterator(迭代器).
int nFindKey = 2; //要查找的Key
UDT_MAP_INT_CSTRING::iterator it= enumMap.find(nFindKey); //定义一个条目变量(实际是指针)
if(it == enumMap.end()) {
//没找到
}
else {
//找到
}
//通过map对象的方法获取的iterator数据类型是一个std::pair对象，包括两个数据 iterator->first 和 iterator->second 分别代表关键字和存储的数据
```

4. **从map中删除元素**

移除某个map中某个条目用erase()
该成员方法的定义如下
```
iterator erase(iterator it); //通过一个条目对象删除 
iterator erase(iterator first, iterator last); //删除一个范围 
size_type erase(const Key& key); //通过关键字删除 
clear()就相当于 enumMap.erase(enumMap.begin(), enumMap.end());
```

## C++ STL map的使用代码

以下是对C++中STL map的插入，查找，遍历及删除的例子：
```

#include <map>
#include <string>
#include <iostream>
using namespace std;

void map_insert(map < string, string > *mapStudent, string index, string x) {
    mapStudent->insert(map < string, string >::value_type(index, x));
}

int main(int argc, char **argv) {
    char tmp[32] = "";
    map < string, string > mapS;

//insert element
    map_insert(&mapS, "192.168.0.128", "xiong");
    map_insert(&mapS, "192.168.200.3", "feng");
    map_insert(&mapS, "192.168.200.33", "xiongfeng");

    map < string, string >::iterator iter;

    cout << "We Have Third Element:" << endl;
    cout << "-----------------------------" << endl;

//find element
    iter = mapS.find("192.168.0.33");
    if (iter != mapS.end()) {
        cout << "find the elememt" << endl;
        cout << "It is:" << iter->second << endl;
    } else {
        cout << "not find the element" << endl;
    }

//see element
    for (iter = mapS.begin(); iter != mapS.end(); iter++ ) {

        cout << "| " << iter->first << " | " << iter->second << " |" << endl;

    }
    cout << "-----------------------------" << endl;

    map_insert(&mapS, "192.168.30.23", "xf");

    cout << "After We Insert One Element:" << endl;
    cout << "-----------------------------" << endl;
    for (iter = mapS.begin(); iter != mapS.end(); iter++ ) {

        cout << "| " << iter->first << " | " << iter->second << " |" << endl;
    }

    cout << "-----------------------------" << endl;

//delete element
    iter = mapS.find("192.168.200.33");
    if (iter != mapS.end()) {
        cout << "find the element:" << iter->first << endl;
        cout << "delete element:" << iter->first << endl;
        cout << "=================================" << endl;
        mapS.erase(iter);
    } else {
        cout << "not find the element" << endl;
    }
    for (iter = mapS.begin(); iter != mapS.end(); iter++ ) {

        cout << "| " << iter->first << " | " << iter->second << " |" << endl;

    }
    cout << "=================================" << endl;

    return 0;
}
```
