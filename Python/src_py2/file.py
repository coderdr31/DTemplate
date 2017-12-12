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
# 文件内容：
# 包含w，h的行
# 含有空格的含有w 整数的h 行
# 4 3
# 1 2 3 4
# 2 3 4 5
# 6 7 8 9
with open('file') as f:
 w, h = [int(x) for x in f.readline().split()] # read first line
 array = []
 for line in f: # read rest of lines
 array.append([int(x) for x in line.split()])
#你可以将最后一个循环浓缩为嵌套列表理解
with open('file') as f:
 w, h = [int(x) for x in f.readline().split()]
 array = [[int(x) for x in line.split()] for line in f]
#################################################
f1  = open('filename', 'w')
f1.write('内容')
