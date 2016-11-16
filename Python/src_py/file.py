#!/usr/bin/python
# coding: utf-8
f1  = open('filename')
str = f1.read()  # 整个文件都读出来了,一个字符串
for char in str:
    print char  # 一个一个字符输出
#################################################
f1  = open('filename')
for line in f1:
    print line  # 一行一行输出
    word_arr = line.split()  # 拆出单词,默认以换行和空格拆; split('\n')
    # strip('XXX') 去掉XXX

#################################################
f1  = open('filename', 'w')
f1.write('内容')
