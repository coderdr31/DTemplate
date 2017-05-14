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


##################################################################
# 进制之间的转换，16进制-》ASCII码
##################################################################
#!/usr/bin/python
#coding: utf-8
s = '''526172211A0700CF907300000D0000000000000056947424965E
00600000004900000002E3B1696DEE413D3B1D33310020000000
C3EBC6C6B2E2CAD44279CCECD2D76C6F76652E74787400796AD2
34784B6DD58B0A427929591366006C6F7665002E7478742E2E5B
7A2D7B7D2E2E39423843569449C8691BEC768E16663C5F9ED737
AE6CDDC6178C0837F6BB88DAA8356B02A700C776FC0F1091C1D1
6712FC075A011D5B5DEF7E46966E8B878B80DABCDF9683C49165
FFB993A77CDE8600A1262200F3D3D5315DF0FC4E2B3ACAA3943F
142EC43D7B00400700'''
# """ 或 ''' ,文本有换行时用
s = ''.join(s.split('\n'))    #去换行
res = ''
for i in range(0, len(s), 2):
    res += chr(int(s[i:i+2], 16))   # 16 -> int -> ASCII
# f = open('./tmp', 'w')
# f.write(res)
