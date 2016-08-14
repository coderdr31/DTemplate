-- 用法
    -- source test.sql 或者
    -- \. test.sql
    -- .sql 脚本的好处是: 前面的报错后,后面的还会执行

-- 一些基本的命令
set password for 'root'@'localhost' =password('password');  -- 初次设置密码
mysql -u root -p  -- 连接数据库
show databases;  -- 查看当前系统存在的数据库，我们可以看到有默认的4个数据库
    -- 分别为 information_schema 、 mysql 、performance_schema 以及 test
create database db_name;  -- 创建数据库
use db_name  -- 进入数据库
show tables
select round(1.14);
select md5(“hello”);
describe tb_dept1;
show create database db_name \G  -- 查看创建数据库属性
drop database db_name;  -- 删除数据库
drop table tb_name;  -- 删除表
show engines \G  -- 查看系统支持的引擎

-- 实战
create database book;
show create database book \G  -- 查看数据库定义
use book;  -- 进入book数据库
-- 创建数据表tb_emp1的SQL语句为：(直接复制进去执行)
create table tb_emp1(
    id int(11) primary key auto_increment,
    name varchar(25) not null unique,
    deptId int(11) default 1111,
    salary float,
    -- constraint sth unique(name)
    -- constraint fk_emp_dept1 foreign key(deptId) references tb_dept1(id)
    -- primary key(name, deptId)
    -- primary key(id)
);
show tables;  -- 查看数据表
insert into tb_emp1 values (1, 'jrp', 101, 50.0);   
insert into tb_emp1(name, deptId) values ('jrp', 101);   
select * from tb_emp1 order by id asc;  -- 查看表中的数据 升序
select * from tb_emp1 order by id desc;  -- 查看表中的数据
delete from tb_emp1 where id=1;
update tb_emp1 set name='jrp', age=22 where id=1;
