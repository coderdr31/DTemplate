
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    freopen("./in_file/in_input", "r", stdin); //从文件中读入
    char a, b, c;
    while(scanf("%c %c %c", &a, &b, &c) != EOF) {
        //循环读入，适合 不输输入个数的题(输入格式a b c)
        getchar(); //去掉换行符或其他
        printf("%c %c %c\n", a, b, c);
    }

    // 动态定义数组
    int size = 50;
    int Column = 10;
    //int *p = new int[size]; //定义一维
    int **p = new int*[size]; //定义指针数组
    for(int i = 0; i < size; i++) {
        p[i] = new int[Column];
    }

    for(int i = 0; i < size; i++) {
        delete []  p[i];   // 要在指针前加[] ， 否则的话 只释放p[i]所指的第一个单元所占的空间
    }
    delete [] p;     //最后不要忘掉 释放掉开辟的指针数组

    return 0;
}
