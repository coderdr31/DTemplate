<head><meta charset="UTF-8"></head>

# ubuntu安装的应用
## git
[廖雪峰git教程](http://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000/0013743256916071d599b3aed534aaab22a0db6c4e07fd0000)
### 配置查看用户名和地址
初始化、修改用户名和地址
```
git config --global user.name "your name"
git config --global user.email "your email"
```
查看
```
git config user.name
git config user.email
```
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
#### 查看修改
> git status  //查看rep的状态
> git diff   //查看修改内容, git diff 1.txt
#### 版本回退和返回,撤销修改
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
#### 删除文件
```
$ rm test.txt //工作区和暂存区不一致
$ git rm test.txt & $ git commit -m "remove test.txt"   //确实要从版本库中删除该文件
$ git checkout -- test.txt  //另一种情况是删错了，因为暂存区里还有呢，所以可以很轻松地把误删的文件恢复到最新版本
```
### 分支操作
```
查看分支：git branch
创建分支：git branch <name>
切换分支：git checkout <name>
创建+切换分支：git checkout -b <name>
合并某分支到当前分支: git merge --no-ff -m ""<name> //强制禁用Fast forward模式,这样合并会创建一个新的commit;
                      git merge <name>  //合并分支时，如果可能，Git会用Fast forward模式，但这种模式下，删除分支后，会丢掉分支信息。
删除分支：git branch -d <name>
删除远程分支: git push [远程名] :[分支名]     //例如: git push origin :serverfix
```

分支合并解决冲突:
1. `git merge --no-ff -m "<name>`、`git merge <name>` 会提示冲突，`git status` 也可以告诉我们冲突的文件
2. 修改冲突的文件，保存，add、commit即可
3. `git log --graph --pretty=oneline --abbrev-commit` 查看分支合并图，`git log --graph`
### 其它
#### stash功能
stash功能，可以把当前工作现场“储藏”起来，等以后恢复现场后继续工作
> git stash  //现在，用git status查看工作区，就是干净的（除非有没有被Git管理的文件）
> git stash list
> git stash apply恢复，但是恢复后，stash内容并不删除，你需要用git stash drop来删除
> 或用 git stash pop，恢复的同时把stash内容也删了
> git stash apply stash@{0}  //你可以多次stash，恢复的时候，先用git stash list查看，然后恢复指定的stash
#### alias
> git config --global alias.lg "log --color --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit"
> 就可用 git lg
#### 更改本地仓库名
[http://gohom.win/2015/12/17/git-rename-repo/](Github:重命名仓库)
> git remote -v  列出所有远程仓库信息, 包括网址.
> git remote set-url origin git@github.com:username/newrepo.git   修改远程仓库对应的网址.

### gitignore规则
不需要从头写.gitignore文件，GitHub已经为我们准备了各种配置文件，只需要组合一下就可以使用了。所有配置文件可以直接在线浏览：https://github.com/github/gitignore
> 所有空行或#开头的行都会被忽略；
> 可以使用标准的 glob 模式匹配；
> 文件或目录前加 / 表示仓库根目录的对应文件；
> 匹配模式最后跟反斜杠 / 说明要忽略的是目录；
> 要特殊不忽略某个文件或目录，可以在模式前加上取反 ! 。
> 其中 glob 模式是指 shell 所使用的简化了的正则表达式。
>
> 星号 * 匹配零个或多个任意字符；
> [abc]匹配任何一个列在方括号中的字符（这个例子要么匹配一个 a，要么匹配一个 b，要么匹配一个 c）；- - 问号 ? 只匹配一个任意字符；
> 如果在方括号中使用短划线分隔两个字符，表示所有在这两个字符范围内的都可以匹配（比如 [0-9] 表示匹配所有 0 到 9 的数字）。
下面是一个 .gitignore 文件例子，注释上附录有说明：
```
*.a                    # 所有以 '.a' 为后缀的文件都屏蔽掉
# Office 缓存文件
~'$'*.docx
~'$'*.ppt
~'$'*.pptx
~'$'*.xls

tags                   # 仓库中所有名为 tags 的文件都屏蔽
core.*                 # 仓库中所有以 'core.' 开头的文件都屏蔽

tools/                # 屏蔽目录 tools
log/*                  # 屏蔽目录 log 下的所有文件，但不屏蔽 log 目录本身

/log.log               # 只屏蔽仓库根目录下的 log.log 文件，其他目录中的不屏蔽
readme.md       # 屏蔽仓库中所有名为 readme.md 的文件
!/readme.md     # 在上一条屏蔽规则的条件下，不屏蔽仓库根目录下的 readme.md 文件
```

## apache2
### 认证(Authentication)
[中文版apache手册](http://www.t086.com/code/apache2.2/howto/auth.html)
## 系统
1. Zeal    , 文档查看, 查看语言、软件的使用文档
2. GDebi Package installer , 快速方便安装deb包
3. virtualenvwrapper , 创建独立Python开发环境.
   mkvirtualenv -p /usr/bin/python3.4 env34 -> workon env34 切换环境

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

# 其它
## pip
> 列出已安装的包  pip freeze or pip list
> 导出requirements.txt  pip freeze > <目录>/requirements.txt
> 安装包
在线安装 `pip install <包名> 或 pip install -r requirements.txt`
```
# 安装1.9版本的django
pip install django==1.9
# 安装版本号大于1.9的django，注意有引号
pip install "django>1.9"
pip install "django>=1.9"
```

安装本地安装包
pip install <目录>/<文件名> 或 pip install --use-wheel --no-index --find-links=wheelhouse/ <包名>
<包名>前有空格
可简写为  pip install --no-index -f=<目录>/ <包名>

> 卸载包  pip uninstall <包名> 或 pip uninstall -r requirements.txt
> 升级包  pip install -U <包名>
> 升级pip pip install -U pip
> 显示包所在的目录  pip show -f <包名>
> 搜索包  pip search <搜索关键字>
> 查询可升级的包 pip list -o
> 下载包而不安装  pip install <包名> -d <目录> 或 pip install -d <目录> -r requirements.txt
> 打包  pip wheel <包名>

