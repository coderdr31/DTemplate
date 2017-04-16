#!/usr/bin/python3
# coding: utf-8

# 针对 03版excel（xls结尾的），我们可以使用xlrd读，xlwt包来写
# http://qindongliang.iteye.com/blog/2163700
import xlwt
path = "1.xls"
wb=xlwt.Workbook()
sheet=wb.add_sheet("xlwt数据测试表")
value = [["名称", "hadoop编程实战", "hbase编程实战", "lucene编程实战"], ["价格", "52.3", "45", "36"], ["出版社", "机械工业出版社", "人民邮电出版社", "华夏人民出版社"], ["中文版式", "中", "英", "英"]]
for i in range(0,4):
    for j in range(0,len(value[i])):
        sheet.write(i,j,value[i][j])
wb.save(path)
print("写入数据成功！")
