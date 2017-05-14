#!/usr/bin/python
# coding=utf-8
import xlrd

###########################
# sudo pip install xlrd
# 直接执行；fname=要读取的xlsx名字；可找出多个sheet，所有的值  #
###########################
##################################################################
## fname="标准文件" ;  fname2="比较的文件(可能含错误的文件)"
## xsl内容：课程名、学分
##################################################################

fname = "./schoolfen.xls"
bk = xlrd.open_workbook(fname)
sheet_name = "Sheet1"

try:
    sh = bk.sheet_by_name(sheet_name)
except:
    print "no sheet in %s named Sheet1" % fname
nrows = sh.nrows
ncols = sh.ncols
print "nrows %d, ncols %d" % (nrows, ncols)

str = '开始'
grade = 0.0
dict = {str: grade}

for i in range(0, nrows):
    str = sh.cell_value(i, 0)
    grade = float(sh.cell_value(i, 1))
    dict[str] = grade
    # print str, dict[str]
    # print str, dict.get(str)

fname2 = "./drfen.xls"
bk2 = xlrd.open_workbook(fname2)
sheet_name2 = "Sheet1"
try:
    sh2 = bk2.sheet_by_name(sheet_name2)
except:
    print "no sheet in %s named Sheet1" % fname2
nrows2 = sh2.nrows
ncols2 = sh2.ncols
print "nrows2 %d, ncols2 %d" % (nrows2, ncols2)
print "----------------"
for i in range(0, nrows2):
    str = sh2.cell_value(i, 0)
    grade = float(sh2.cell_value(i, 1))
    if dict.get(str) ==  None:
        print "标准文件不存在",str;
    elif grade != dict.get(str):
        print str, grade, dict.get(str)
