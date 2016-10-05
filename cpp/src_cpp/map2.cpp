#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int main() {
    freopen("./in_file/in_map2", "r", stdin);

    map<string, int> wordCount;

//insert 通过下标操作符
    wordCount["Anna"] = 1;
    cout << wordCount["Anna"] << endl;
//change 通过下标操作符
    ++ wordCount["Anna"];
    cout << wordCount["Anna"] << endl;
    cout << "-------------------------------" << endl;

//记录每个单词出现的次数(法一)
    string word;
    while (cin >> word) {
        ++wordCount[word];
    }

//遍历
    map<string, int>::iterator iter = wordCount.begin();
    while(iter != wordCount.end()) {
        cout << iter -> first << " occurs " << iter -> second << " times" << endl;
        ++ iter;

    }
    cout << "-------------------------------" << endl;


// count()
    int occurs(0);
    if ( wordCount.count("Anna") )
        occurs = wordCount["Anna"];

// find()
    //int occurs(0);
    map<string, int>::iterator iter2 = wordCount.find("Anna");
    if ( iter2 != wordCount.end() )
        occurs = iter2->second;


// erase of a key returns number of elements removed
   string removalWord = "john";
if ( wordCount.erase( removalWord ) )
    cout << "ok: " << removalWord << " removed!" << endl;
else
    cout << "oops: " << removalWord << " not found!" << endl;

    return 0;
}
