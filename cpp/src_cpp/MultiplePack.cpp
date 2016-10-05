// 多重背包(包括01背包&完全背包的代码)
/*
upc2444 现在有许多的 东西要放到赫敏的包里面,但是包的大小有限,所以我们只能够在里面放入非常重要的物品。现在给出该种物品
的数量、体积、价值的数值,希望你能够算出怎样能使背包的价值最大的组合方式 第1行有2个整数,物品种数n和背包装载体积v: 第2
行到i+l行每行3个整数,为第i种物品的数量m、体积w、价值s。题目数据范围没限制。
Sample Input
2 10
3 4 3
2 2 5 Sample Output 13
*/
#include <cstdio>
const int M = 10006;
int n, v;
int p[1000005], c[1000005], num[1000005];
int f[M]; //c是重量,p是价值
#define MAX(a, b) (a > b ? a : b)
void zp(int c, int p) {
    for(int i = v; i >= c; i--) f[i] = MAX(f[i], f[i - c] + p);
}
void cp(int c, int p) {
    for(int i = c; i <= v; i++) f[i] = MAX(f[i], f[i - c] + p);
}
int main() {
    freopen("./in_file/in_MultiplePack", "r", stdin);
    scanf("%d %d", &n, &v);
    for(int i = 1; i <= n; i++) scanf("%d %d %d", &num[i], &c[i], &p[i]);
    for(int i = 1; i <= n; i++)
        if(num[i] * c[i] >= v) cp(c[i], p[i]);
        else {
            int k = 1;
            while(k < num[i])
                zp(k * c[i], k * p[i]), num[i] = num[i] - k, k *= 2;
            zp(num[i] * c[i], num[i] * p[i]);
        }
    printf("%d\n", f[v]);
}
