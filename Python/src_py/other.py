#!/usr/bin/python
# coding: utf-8


##################################################################
# 字典反转
##################################################################
dict1 = {1: 2, 3: 4, 6: 7, 9: 10}

def invert_dict(d):
    return dict((v, k) for k, v in d.items())
print invert_dict(dict1)

print '---itertools 提高大数据效率'
from itertools import izip
def invert_dict3(d):
    return dict(izip(d.itervalues(), d.iterkeys()))
print invert_dict3(dict1)
