<head><meta charset="UTF-8"></head>
#背包九讲_笔记_简
## P01: 01背包
有N件物品和一个容量为V的背包。第i件物品的费用是c[i]，价值是w[i]。求解将哪些物品装入背包可使价值总和最大。

解：
```
procedure ZeroOnePack(cost,weight)
    for v=V..cost
        f[v]=max{f[v],f[v-cost]+weight}

for i=1..N
    ZeroOnePack(c[i],w[i]);

//最后求出 f[V];
```
_初始化的细节问题_
1. 如果要求恰好装满背包，那么在初始化时除了f[0]为0其它f[1..V]均设为-∞，这样就可以保证最终得到的f[N]是一种恰好装满背包的最优解。
2. 如果并没有要求必须把背包装满，而是只希望价格尽量大，初始化时应该将f[0..V]全部设为0。

## P02: 完全背包问题
题目
有N种物品和一个容量为V的背包，每种物品都有无限件可用。第i种物品的费用是c[i]，价值是w[i]。求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。

解：
```
procedure CompletePack(cost,weight)
    for v=cost..V
        f[v]=max{f[v],f[v-c[i]]+w[i]}

for i=1..N
    CompletePack(c[i],w[i]);
```
## P03: 多重背包问题
题目
有N种物品和一个容量为V的背包。第i种物品最多有n[i]件可用，每件费用是c[i]，价值是w[i]。求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。

解：
```
//这样就将第i种物品分成了O(log n[i])种物品，将原问题转化为了复杂度为O(V*Σlog n[i])的01背包问题，是很大的改进。
//下面给出O(log amount)时间处理一件多重背包中物品的过程，其中amount表示物品的数量：
procedure MultiplePack(cost,weight,amount)
    if cost*amount>=V
        CompletePack(cost,weight)
        return
    integer k=1
    while k<num
        ZeroOnePack(k*cost,k*weight)
        amount=amount-k
        k=k*2
    ZeroOnePack(amount*cost,amount*weight)
```

例题
```

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
```

**可行性问题 O(V N ) 的算法**
详细见--背包问题九讲pack2rc.pdf ---3.4 可行性问题 O(V N ) 的算法

当问题是“每种有若干件的物品能否填满给定容量的背包”,只须考虑填满背包的
可行性,不需考虑每件物品的价值时,多重背包问题同样有 O(V N ) 复杂度的算法。

## P04: 混合三种背包问题
问题
如果将P01、P02、P03混合起来。也就是说，有的物品只可以取一次（01背包），有的物品可以取无限次（完全背包），有的物品可以取的次数有一个上限（多重背包）。应该怎么求解呢？

解：
```
for i=1..N
    if 第i件物品是01背包
        ZeroOnePack(c[i],w[i])
    else if 第i件物品是完全背包
        CompletePack(c[i],w[i])
    else if 第i件物品是多重背包
        MultiplePack(c[i],w[i],n[i])
```
