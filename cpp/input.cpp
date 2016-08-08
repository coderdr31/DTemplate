
#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    freopen("in","r",stdin); //从文件中读入
    char a, b, c;
    while(scanf("%c %c %c",&a,&b,&c) !=EOF){
        //循环读入，适合 不输输入个数的题(输入格式a b c)
        getchar(); //去掉换行符或其他
        printf("%c %c %c\n", a, b, c);
    }
        return 0;
}
