<head><meta charset="UTF-8"></head>
# C++知识1
## 传值 or 传地址
1. 类
'Test A' 
  1. 'fu(A)' & 'void fu(Test X)' 传值,调用拷贝构造函数，fu函数不影响类A
  2. 'fu(A)' & 'void fu(Test &X)' 传地址，影响类A
  3. 'fu(&A)' & 'void fu(Test *X)' 传地址，影响类A

## 成员运算符.与指向运算符(结构解引用运算符)-> 、解引用运算符* 
```
class Student{
    public:
        int name;
        void fuc();
};
```
1. 'Student stu1' 则  'stu1.name'、'stu1.fuc()'
2. 'Student *stu1' 则  'stu1 -> name'、'stu1 -> fuc()' 或 '(*stu1).name/fuc()' //有问题
    运算符->可以视作为解引用运算符*的语法糖。即p->a相当于(*p).a

## 指针(*)、取地址(&)、解引用(*)、引用(&)
1. 指针与取地址
```
int num = 7;  
int *p = &num;
```
2. 解引用与指针赋值
```
int num = 7;  
int *p = &num;  
*p = 100;  
//上面num的值变为100
```
另
```
//给指针p赋值，使其指向另外一个地址
    int num = 7, another = -5;  
    int *p = &num;  
    p = &another;  
    printf("%d\n", *p);//此时p指向了another，所以输出了another的值，即-5  
```
3. 引用（引用概念在C++中才有，C中并没有）
```

int main()  
{  
    int val = 7, val2 = 999;  
    int &refval = val, &refval2 = val2; ///引用必须要初始化，使其绑定到一个变量上  
    ///修改引用的值将改变其所绑定的变量的值  
    refval = -12;  
    printf("%d %d\n", val, refval);//-12，refval的值和val一样  
      
    ///将引用b赋值给引用a将改变引用a所绑定的变量的值，  
    ///引用一但初始化(绑定)，将始终绑定到同一个特定对象上，无法绑定到另一个对象上  
    refval = refval2;  
    printf("%d %d\n", val, refval);//999  
    return 0;  
}  
```
关键：作用在引用上的所有操作事实上都是作用在该引用所绑定的对象上。

