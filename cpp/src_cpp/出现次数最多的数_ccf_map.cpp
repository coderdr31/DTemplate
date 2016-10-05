//map
/*
出现次数最多的数

时间限制：	1.0s
内存限制：	256.0MB
问题描述：
问题描述
给定n个正整数，找出它们中出现次数最多的数。如果这样的数有多个，请输出其中最小的一个。
输入格式
输入的第一行只有一个正整数n(1 ≤ n ≤ 1000)，表示数字的个数。
输入的第二行有n个整数s1, s2, …, sn (1 ≤ si ≤ 10000, 1 ≤ i ≤ n)。相邻的数用空格分隔。
输出格式
输出这n个次数中出现次数最多的数。如果这样的数有多个，输出其中最小的一个。
样例输入
6
10 1 10 20 30 20
样例输出
10
*/

#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main() {
    freopen("in", "r", stdin);
    int num;
    cin >> num;
    map<int, int> map1;
    for(int i = 0; i < num; i++) {
        int k;
        cin >> k;
        //cout << k << endl;
        ++map1[k];
    }

    map<int, int>::iterator iter = map1.begin();
    int max = iter -> second;
    int output_val = iter -> first;
    while(iter != map1.end()) {
        if(iter -> second > max) {
            max = iter -> second;
            output_val = iter -> first;
        }
        ++iter;
    }
    cout << output_val << endl;


    return 0;
}
