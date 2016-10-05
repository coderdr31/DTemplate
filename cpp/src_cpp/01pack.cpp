//01背包问题-采药例题
/*

医师把他带到一个到处都是草药的山洞里对他说：“孩子，这个山洞里有一些不同的草药，采每一株都需要一些时间，每一株也有它自身的价值。我会给你一段时间，在这段时间里，你可以采到一些草药。如果你是一个聪明的孩子，你应该可以让采到的草药的总价值最大。”

如果你是辰辰，你能完成这个任务吗？

Input输入的第一行有两个整数T（1 <= T<= 1000）和M（1 <= M <= 100），用一个空格隔开，T代表总共能够用来采药的时间，M代表山洞里的草药的数目。接下来的M行每行包括两个在1到100之间（包括1和100）的整数，分别表示采摘某株草药的时间和这株草药的价值。

Output输出包括一行，这一行只包含一个整数，表示在规定的时间内，可以采到的草药的最大总价值。

Sample Input

70 3

71 100

69 1

1 2

Sample Output

3
*/
#include <iostream>
#include <cstdio>
using namespace std;
#define MAX(a,b) (a>b? a:b)
int T,N;
int *dp;
void zop(int co,int va){
    for(int j = T; j >= co; j--)
        dp[j] = MAX(dp[j],dp[j-co]+va);
}
int main(){
    freopen("./in_file/in_01pack", "r",stdin);
    cin >> T >> N;
    dp = new int[N+1];
    for(int j = 0; j <= N; j++){
        dp[j] = 0;
    }

    int cost, value;
    for(int i = 1; i <= N; i++){
        cin >> cost >> value;
        zop(cost,value);
    }
    cout << dp[T] << endl;

}
