<head><meta charset="UTF-8"></head>

# 终端命令
## 系统管理
### 查看端口, pid, 进程
```
ps aux|grep programName && kill  查杀程序(强)
    netstat -antp 查看端口号
    lsof -i:80  查看80端口对应的pid及程序名
```
### systemctl 管理服务
    ```
    systemctl status nginx.service

    [root@study ~]# systemctl [command] [unit]
    command 主要有：
    start     ：立刻啟動後面接的 unit
    stop      ：立刻關閉後面接的 unit
    restart   ：立刻關閉後啟動後面接的 unit，亦即執行 stop 再 start 的意思
    reload    ：不關閉後面接的 unit 的情況下，重新載入設定檔，讓設定生效
    enable    ：設定下次開機時，後面接的 unit 會被啟動
    disable   ：設定下次開機時，後面接的 unit 不會被啟動
    status    ：目前後面接的這個 unit 的狀態，會列出有沒有正在執行、開機預設執行否、登錄等資訊等！
    is-active ：目前有沒有正在運作中
    is-enable ：開機時有沒有預設要啟用這個 unit


    [root@study ~]# systemctl [command] [--type=TYPE] [--all]
    command:
    list-units      ：依據 unit 列出目前有啟動的 unit。若加上 --all 才會列出沒啟動的。
    list-unit-files ：依據 /usr/lib/systemd/system/ 內的檔案，將所有檔案列表說明。
    --type=TYPE：就是之前提到的 unit type，主要有 service, socket, target 等

    systemctl                 : 列出系統上面有啟動的 unit
    systemctl list-unit-files : 列出所有已經安裝的 unit 有哪些
    systemctl list-units --type=service --all  : 只剩下 *.service 的項目才會出現喔！
    systemctl list-units --type=service --all | grep cpu  : 查詢系統上是否有以 cpu 為名的服務
    ```
### 用sysv-rc-conf管理Ubuntu的开机启动项
    查看当前运行级别,执行命令：
    > runlevel    : 查看当前运行级别（ runlevel 显示上次的运行级别和当前的运行级别，“N”表示没有上次的运行级别。）
    > sudo apt-get install sysv-rc-conf   : 安装sysv-rc-conf
    > sudo sysv-rc-conf   : 使用sysv-rc-conf
### 卸载软件
1. dpkg --list //查看已安装的软件包列表
2. sudo apt-get --purge <programname>
### 增删用户
1. userdel -r -f user  删除用户(-r 删用户的家目录， -f强制删除)
2. groupdel users    删除组users
3. usermod   在添加之后若再对该用户添加另外附加组时，使用`usermod -G 附加组名 用户名`会覆盖该用户的之前的附加组。此时，可在usermod 命令中添加一个参数 -a 来实现 `usermod -a -G 附加组名 用户名`.
4. chown -R intelmq.intelmq /opt/intelmq


## u盘分区的建立和删除、格式化
1.sudo fdisk -l后查看该磁盘的分区盘符，如：/dev/sdc1.
2.sudo fdisk /dev/sdb 后会显示menu：
    输入m回车，显示menu；
    输入d回车，删除分区；
    输入“p” 查看已经存在的分区
    输入“n” 新增分区，根据提示需要输入分区号，之后还需要输入分区大小
    输入“t” 改变文件系统格式，命令“l”显示对应文件系统格式的id（提示上也有这个说明）
    输入w，保存并推出；
    输入q回车，不保存退出；
3.格式化
mkfs.vfat /dev/sdc1
mkfs.ext3 /dev/sdc1
4.更改U盘名字，用e2label命令
sudo e2label /dev/sdc cake

## CTF
1. md5sum、sha1sum 计算文件的md5、sha1值。如 md5 1.txt

## 图片、视频
convert  转换图片的格式：convert a.png a.jpg ;支持JPG, BMP, PCX, GIF, PNG, TIFF, XPM和XWD等类型

## 压缩、解压
1. .zip
解压：unzip FileName.zip
压缩：zip FileName.zip DirName

windows下的zip解压乱码解决方法：
  sudo apt-get install unar
  使用：假设需要解压的ZIP包是foo.zip
  lsar foo.zip #列出所有文件

  如果列出的文件名已经正确
  unar foo.zip #解压所有文件

  如果列出的文件名还不正确
  lsar -e GB18030 foo.zip #指定使用GB18030编码列出所有文件
  unar -e GB18030 foo.zip #指定使用GB18030解压所有文件
  注：GB18030编码文件名的ZIP文件一般由简体中文版Windows产生，对于繁体中文版Windows产生的ZIP文件可以尝试BIG5-HKSCS编码，对其他语种的常见编码不再赘述。通用的原则是用lsar测试出正确的编码以后，用unar解压。
2. .rar
解压：rar x FileName.rar
压缩：rar a FileName.rar DirName
3. .tar.gz
解压：tar -zxvf [-C 指定目录]

## 查看
1. du 查看目录文件大小
  du -ah test //test下所有的文件
  du -sh *  //当前目录下文件(夹)
2. top 查看进程占用资源情况
  “x”（打开/关闭排序列的加亮效果）
  ”shift + >”或`shift +  <  `可以向右或左改变排序列
  M 根据驻留内存大小进行排序
  P 根据CPU使用百分比大小进行排序
  T 根据时间/累计时间进行排序
  q 退出



## 其它
1. Linux Shell中，可以使用`$()或者两个反引号来包裹一条shell命令`，并返回shell命令的执行结果。
   比如执行export testenv2=`python -c "print 'A'*20"`命令后，再执行./env可以看到有一个名为testenv2的环境变量，其值为20个A。
2. xdg-open  //会选择合适的程序打开指定文件2. xdg-open  //会选择合适的程序打开指定文件

