# include <cstdio>
# include <iostream>
using namespace std;
//杭电problem2005，算：给出的日期是改年的第几天
int main(){
    //freopen("in", "r", stdin);
    int year, month, day;
    int num[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,31};
    while(scanf("%d/%d/%d", &year, &month, &day) != EOF){
        int sum;
        sum = day;
        for(int i =0 ; i < month - 1;i++){
            sum += num[i];
        }
        if(month > 2){
            if((year % 4 == 0 && year % 100 != 0)||year % 400 ==0){
            //四年一闰，百年不闰，四百年再闰
                sum += 1;
            }
        }
        printf("%d\n",sum);
    }
}
