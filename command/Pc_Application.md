# ubuntu安装的应用
## git
[廖雪峰git教程](http://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000/0013743256916071d599b3aed534aaab22a0db6c4e07fd0000)
### 创建版本库
```
git init //创建本地仓库
git remote add origin git@github.com:coderdr31/Computer-Graphics-3D.git //关联ssh，关联一个远程库
git add . //添加进本地仓库
git commit -m “first commit” //添加并写版本信息
git push -u origin master //密钥提交 ssh，由于远程库是空的，我们第一次推送master分支时，加上了-u参数，Git不但会把本地的master分支内容推送的远程新的master分支，还会把本地的master分支和远程的master分支关联起来，在以后的推送或者拉取时就可以简化命令。
```
### 查看修改，版本回退和返回,撤销修改，删除文件
提交至远程库流程:
1. git add .
2. git commit -m ""  //提交到本地仓库
3. git push origin master  //提交到远程库


> git status  //查看rep的状态
> git diff   //查看修改内容, git diff 1.txt

```
git reset --hard commit_id // 回到某个版本，commit_id:commit_id或HEAD。HEAD指向的版本就是当前版本，上一个版本就是HEAD^，上上一个版本就是HEAD^^，当然往上100个版本写100个^比较容易数不过来，所以写成HEAD~100
穿梭前，用git log可以查看提交历史，以便确定要回退到哪个版本。
要重返未来，用git reflog查看命令历史，以便确定要回到未来的哪个版本
```

```
工作区—暂存区—版本库
git checkout -- file  //暂存区覆盖工作区
git reset HEAD file   //版本库覆盖暂存区
```

```
$ rm test.txt //工作区和暂存区不一致
$ git rm test.txt & $ git commit -m "remove test.txt"   //确实要从版本库中删除该文件
$ git checkout -- test.txt  //另一种情况是删错了，因为暂存区里还有呢，所以可以很轻松地把误删的文件恢复到最新版本
```

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
