参考: [sql 盲注测试](http://www.freebuf.com/articles/web/30841.html)

在没有表被引用的情况下，允许指定 dual 作为一个假的表名
users 是自己一个库里面的表名
### 盲注一般分为三种情况
* Booleanbase
* Timebase
* Errorbase

### 普通盲注 Booleanbase
比如在where语句中可以构造or 1=1来使返回页面不同。(这里用mysql演示一下，大家体会就好)
'''
mysql> select 123 from dual where 1=1;  -- dual表 不一定存在(在还没有选择数据库的时候)
+-----+
| 123 |
+-----+
| 123 |
+-----+
1 row in set (0.00 sec)
mysql> select 123 from dual where 1=0;
Empty set (0.00 sec)
'''

如果注入点在order by后面，那么则可以使用判断语句来构造报错。（其实order by后面的注入也可以根据返回结果的顺序来判断，这里自由发挥就好：P）
'''
mysql> select 1 from users order by if(1,1,(select 1 union select 2)) limit 0,3;
+---+
| 1 |
+---+
| 1 |
| 1 |
| 1 |
+---+
3 rows in set (0.00 sec)
mysql> select 1 from users order by if(1,1,(select 1 union select 2)) limit 0,6;
+---+
| 1 |
+---+
| 1 |
| 1 |
| 1 |
| 1 |
+---+
4 rows in set (0.00 sec)  -- limit 0,6 只返回4行, 表明共有4行
mysql> select 1 from users order by if(0,1,(select 1 union select 2)) limit 0,3;
ERROR 1242 (21000): Subquery returns more than 1 row
'''
这里的 if 后面要跟 3 个参数, 且全为真来表示原来应有的字段名称, limit是显示从表中查找的行数

### Timebase
基于时间的盲注的话，mysql主要涉及两个函数，sleep banchmark 基本是使用如下。
'''
mysql> select 1 from users where if(1=1,sleep(1),1) limit 0,1;
Empty set (27.00 sec)  -- 有几行就会sleep几秒
mysql> select 1 from users where if(1=2,sleep(1),1) limit 0,1;
+---+
| 1 |
+---+
| 1 |
+---+
1 row in set (0.00 sec)
'''

### 位运算
mysql中位运算的与运算是&，我们主要用它来进行猜测，比如a的ascii码是1100001，那么我们可以使用1,2,4,8,16…..依次与他进行与运算，最终得到结果
'''
mysql> select ord('a') & 1;
+--------------+
| ord('a') & 1 |
+--------------+
|            1 |
+--------------+
1 row in set (0.00 sec)
mysql> select ord('a') & 2;
+--------------+
| ord('a') & 2 |
+--------------+
|            0 |
+--------------+
1 row in set (0.00 sec)
'''
