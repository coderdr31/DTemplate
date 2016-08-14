### limit
* mysql> SELECT * FROM table LIMIT 5,10;  // 检索记录行 6-15
* mysql> SELECT * FROM table LIMIT 5;     //检索前 5 个记录行
为了检索从某一个偏移量到记录集的结束所有的记录行，可以指定第二个参数为 -1：
* mysql> SELECT * FROM table LIMIT 95,-1; // 检索记录行 96-last.
