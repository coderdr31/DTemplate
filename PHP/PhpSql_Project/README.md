### 简介
这是极客学院的一个视频教程的代码, 视频没有给, 自己看视频敲的, 有改动
PHP基础知识 -> PHP 与 MySQL
### 先进 mysql, 执行
alias logmysql='mysql -u root -p'  //在init.sql目录下，从终端进入mysql
drop database myapp
然后执行脚本
\. init.sql   
### 脚本内容
```
create database myapp charset utf8;
use myapp;

create table users(
    id int(11),
    name varchar(25),
    age int(11)
);
insert into users values (1, 'jrp', 20);
insert into users values (2, 'dr', 20);
select * from users;
```
### 运行顺序 
index.php

### 可开Ngnix,或用php自带的服务器
#### Ngnix
service nginx start 或 nginx -s 参数  //ngnix配置文件中修改root的地址;关闭ps aux|grep nginx && kill
service php-fpm start 
service mysql start 

systemctl status nginx.service //查看其状态
#### php自带的服务器
alias sphpserver='php -S localhost:9999'


