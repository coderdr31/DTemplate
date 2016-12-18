# ubuntu安装的应用
## 系统
1. Zeal    , 文档查看, 查看语言、软件的使用文档
2. GDebi Package installer , 快速方便安装deb包

# 文件 & 文档的操作
1. pandoc    ,  多种文档互相转换工具， 例pandoc -f html -t markdown input.html -o output.md
2. cat       ,  合并文件 cat in1 in2 > out
3. foremost  ,  拆分文件(将文件中所含的多个文件拆出)
4. binwalk   ,  识别文件有没有多种文件隐藏其中
5. bless     ,  2进制转16进制 ASCII码

## 磁盘
1. gparted  , 查看各个磁盘分区的情况

## 图片文本识别
1.tesseract
``` zsh
  sudo apt-get install tesseract-ocr
  sudo apt-get install libpng12-dev libjpeg62-dev libtiff4-dev #对应识别语言的库
  可能要装leptonica：http://www.leptonica.org/download.html；
                     tar -zxvf ...
                     ./configure
                     make
                     make install
  下载 https://github.com/tesseract-ocr/tessdata； move tessdata/* to the /usr/local/share/tessdata/
  使用： tesseract exp.png out -l eng     #识别出的文本会写入out.txt
```

## 其它
1. argparse  ,python的库，模仿系统命令用
