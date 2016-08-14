create database myapp charset utf8;
use myapp;

create table users(
    id int(11) primary key auto_increment,
    name varchar(25),
    age int(11)  -- 最后一行不能带 逗号
);
insert into users values (1, 'jrp', 20);
insert into users values (2, 'dr', 20);
select * from users;
