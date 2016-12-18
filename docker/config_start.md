<head><meta charset="UTF-8"></head>
# 安装、配置
## 安装
> sudo apt install docker.io

## 不用输入 sudo
```zsh
sudo groupadd docker
sudo gpasswd -a ${USER} docker  # 或者 sudo gpasswd -a coder352 docker
sudo service docker restart  # log out and back in to take effect
```

## 加速
[阿里云加速](https://cr.console.aliyun.com)
进去以后有步骤, 不用重装

# 常用命令
## 流程
```zsh
docker help search  # docker 的命令都可以用 help
docker search busybox  # 查找镜像
docker pull busybox
# docker pull ubuntu:16.04  # 带版本号,看hub.docker官网
docker images  # 查看镜像信息
docker run busybox /bin/echo hello world  # busy 无法进入命令行
docker run -it busybox  # 进入命令行界面
```

```zsh
docker ps      # 目前执行的
docker ps -a   # 所有 run 执行过的都会在 ps -a 显示
docker images  # 查看所有的images
```
# 详细版
Docker 的思想是每个容器最好只开一个线程做一件事

## Docker
### 常用命令
``` zsh
# 一个完整的流程
docker help search  # docker 的命令都可以用 help
docker search busybox  # 查找镜像
docker pull busybox
docker images  # 查看镜像信息
docker run busybox /bin/echo hello world  # busy 无法进入命令行
docker run -it busybox  # 进入命令行界面
```
``` zsh
# search & pull
docker search ubuntu
docker pull ubuntu:16.04  # 带版本号
```
``` zsh
# run & exit & start & attach
# 所有 run 执行过的都会在 ps -a 显示, 但有监听事件的因为进程没有执行完, 在 ps 中也显示
docker run -it --rm --name ubuntu ubuntu:16.04  # 进入 ubuntu
# -i                            Keep STDIN open even if not attached
# -t, --tty                     Allocate a pseudo-TTY
# --rm                          Automatically remove the container when it exits
# --name string                 Assign a name to the container
docker run -it --rm -v /media/coder352/文档/Share/:/mnt busybox
# -v 挂载主机数据卷到容器内
docker run busybox echo "hello"  # 回显 hello
docker run -d busybox echo "hello"  # 没有回显 hello, 回显了 container ID
docker run -d -p 80:80 citizenstig/dvwa  # ps 会显示这个正在运行, 将 dvwa 的 80 端口映射到 host, container:host
docker run -d -p 80:80 -p 3306:3306 -e MYSQL_PASS="Chang3ME!" citizenstig/dvwa  # 指定 mysql 密码
# -d, --detach                      Run container in background and print container ID
# -e, --env value                   Set environment variables (default [])
# -p, --publish value               Publish a container's port(s) to the host (default [])
# -P 端口随意映射, 可以从 docker ps 中找到端口映射情况
docker run  --name ubuntu -d ubuntu /bin/sh -c "while true; do echo hello; sleep 1; done" # 运行守护是容器
# -c 运行脚本
C-D / exit  # 相当于关机
C-P + C-Q  # 交互式 进入 守护式
docker start 06fe6a01505d  # 针对 exit / C-D 的容器, docker ps -a 才能看到的
docker attach 06fe6a01505d  # 敲回车就能接着进入命令行, docker ps 看到的
docker start -i 06fe6a01505d  # 效果等同于上面两句
```
``` zsh
# images & rmi & ps & stop & kill & rm (前两个是操作 image, 后面是操作 container)
docker images  # 本机上的 images
docker rmi fca62a259df9  # By ID, 要先 stop, kill 当前镜像的所有 container 才能删除
# rmi       Remove one or more images
docker ps  # 正在运行的 container
docker ps -a  # 加上已经结束的
docker stop/kill/rm 8322eae24aa7  # name or ID, 对一个没运行完的, 先 stop/kill 再 rm
docker rm -f 8322eae24aa7  # name or ID, 对一个没运行完的, 先 stop/kill 再 rm
# stop      Stop one or more running containers
# kill      Kill one or more running containers
# rm        Remove one or more containers
```
``` zsh
# commit & build & login & push  # 创建镜像并提交
docker commit -m "test" -a "coder352" 4925f374a4a0 coder352/testbusybox:v1  # 根据 ID
# -m                        参数用来来指定提交的说明信息
# -a                        可以指定用户信息的
# 79c761f627f3              代表的时容器的 id
# saymagic/testbusybox:v1  指定目标镜像的用户名、仓库名和 tag 信息
docker build -t="saymagic/ubuntu-nginx:v2" .  # 根据路径找 Dockerfile 文件
# -t, --tag value               Name and optionally a tag in the 'name:tag' format (default [])
docker images  # 多出了一个我们刚刚创建的镜像 coder352/testbusybox:v1
docker run -it coder352/testbusybox:v1  # 会是一个已经安装了 nginx 的容器
docker login  # Username: coder352; Password: ...
docker push coder352/testbusybox:v1
```
``` zsh
# cp
docker cp a77a72ac178c:/var/www/html /var/www/  # 从容器向主机拷贝文件
docker cp /etc/apt/sources.list 06fe6a01505d:/  # 会放到根目录下
```
``` zsh
# network 创建两个不同网络的 container, ssh 隧道
docker network create --driver=bridge mynetwork1
docker network create --driver=bridge mynetwork2
docker network ls
docker network inspect mynetwork1
docker network inspect -f '{{range $p :=.IPAM.Config}} {{$p.Subnet}} {{end}}' mynetwork2  # 172.20.0.0/16
docker run --name=ubuntu_net1 -i -t --net=mynetwork1 coder352/ubuntu:0.1
docker run --name=ubuntu_net2 -i -t --net=mynetwork2 coder352/ubuntu:0.1
```
``` zsh
# inspect https://golang.org/pkg/text/template/
docker inspect -f '{{.Id}}' a77a72ac178c  # 得到完整的 ID, {{}} 固定写法, . 表示根, Id 表示根下的 Id
docker network inspect -f '{{.Name}}' mynetwork2  # mynetwork2
docker network inspect -f '{{.IPAM.Config}}' mynetwork2  # [{172.20.0.0/16  172.20.0.1/16 map[]}]
docker network inspect -f '{{.IPAM.Config.Subnet}}' mynetwork2  # 这样会报错, 下面是 list, 而不是 dict
docker network inspect -f '{{range $con :=.IPAM.Config}} {{$con.Subnet}} {{end}}' mynetwork2  # 172.20.0.0/16
[
    {
        "IPAM": {
            "Config": [
                {
                    "Subnet": "172.20.0.0/16",
                    "Gateway": "172.20.0.1/16"
                }
            ]
        },
    }
]
```
``` zsh
# logs top exec
docker logs -tf --tail a348c04d1714  # -t 显示时间 -f 不断刷新 --tial 不显示旧的
docker top a348c04d1714  # 查看容器中的进程
docker exec -i -t a348c04d1714 /bin/bash  # 在正在运行的容器中 开一个新的进程
```

### 加速
[阿里云加速](https://cr.console.aliyun.com)
进去以后有步骤, 不用重装

### DNS
``` zsh
$ nmcli dev show | grep dns
IP4.DNS[1]:                             121.251.251.251
$ sudo vim /etc/docker/daemon.json  # 默认是没有这个文件, 要创建
{
    "dns": ["121.251.251.251", "8.8.8.8"]
}
$ sudo service docker restart
```
或者
``` zsh
docker run --dns=121.251.251.251
```

### Error
``` zsh
Cannot connect to the Docker daemon. Is the docker daemon running on this host?
# if the docker user doesn't belong to the same group as login user, it is not able to access to docker daemon service.
service docker status
CGroup: /system.slice/docker.service
        ├─7006 /usr/bin/dockerd -H fd://
        └─7013 containerd -l unix:///var/run/docker/libcontainerd/docker-containerd.sock --shim containerd-shim --met
```

### 智障的 Ubuntu, 没有 ping, ifconfig, vim, 不能用 apt-get update/install(dns 没弄好)
``` zsh
$ ping archive.ubuntu.com  # 91.189.88.162, 手动添加两条 dns 记录
dockdr$ echo '91.189.92.201 archive.ubuntu.com' >> /etc/hosts
docker$ echo '91.189.88.162 archive.ubuntu.com' >> /etc/hosts
docker$ apt-get -y update && apt-get install vim  # 然后再换源吧

$ ping mirrors.aliyun.com
docker$ echo '112.124.140.210 mirrors.aliyun.com' >> /etc/hosts
docker$ apt-get -y update && apt-get install net-tools iputils-ping  # 然后再换源吧, 这样就能用 ifconfig, ping 了
$ docker commit -m "add aliyun sourceu and update, install vim, ping, ifconfig" -a "coder352" 06fe6a01505d coder352/ubuntu:0.1
```

### Docfile
[命令参考](http://www.jianshu.com/p/93a678d1bde6)
``` zsh
docker build . -f Ubuntu.Dockerfile -t coder352/test
```
``` dockerfile
FROM tutum/lamp:latest
# 如果本地没有指定的镜像, 则会自动从 Docker 的公共库 pull 镜像下来, 默认使用 latest 标签, 可以出现多次
# FROM必须是 Dockerfile 中非注释行的第一个指令, 即一个 Dockerfile 从FROM语句开始
MAINTAINER coder352 <352111644@qq.com>
# 指定创建镜像的用户
# 更改MAINTAINER指令会使Docker强制执行RUN指令来更新apt, 而不是使用缓存
ENV DEBIAN_FRONTEND noninteractive
# 指定一个环境变量, 会被后续RUN指令使用, 可以在容器内被脚本或者程序调用
# 错误地做法 - 为接下来的任何命令都设置ENV变量, 包括正在运行地容器, 只适用于 dvwa, sqli-labs 等这种工具性的容器
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y python3
# 正确的做法 - 只为这个命令设置ENV变量
RUN rm -fr /app/*
# 每条RUN指令将在当前镜像基础上执行指定命令, 并提交为新的镜像, 后续的RUN都在之前RUN提交后的镜像为基础
# 镜像是分层的, 可以通过一个镜像的任何一个历史提交点来创建, 类似源码的版本控制
EXPOSE 80:8080
# private and public mapping, 通过映射公有端口到主机上, 你将只能运行一个容器化应用程序实例
EXPOSE 80
# private only, 这样可以让使用者自己指定
EXPOSE 80 3306
# 告诉 Docker 服务端容器对外映射的本地端口, 需要在 docker run 的时候使用-p或者-P选项生效
ADD run.sh /run.sh
# ADD复制本地主机文件、目录到目标容器的文件系统中, 如果源是一个URL, 该URL的内容将被下载并复制到目标容器中
VOLUME  ["/etc/mysql", "/var/lib/mysql"]
# 将本地主机目录挂载到目标容器中, 将其他容器挂载的挂载点 挂载到目标容器中
CMD ["/run.sh"]
# 在启动容器时提供一个默认的命令执行选项, 如果用户启动容器时指定了运行的命令, 则会覆盖掉CMD指定的命令
# CMD指定在 Dockerfile 中只能使用一次, 如果有多个, 则只有最后一个会生效
# CMD会在启动容器的时候执行, build 时不执行; RUN只是在构建镜像的时候执行
```

### Get Dockerfile from image
``` zsh
# 方法一: 不用 pull
https://imagelayers.io/?images=tuxotron/audi_sqli
# 这个地址可以直接分析镜像, 只要修改后面的参数

# 方法二: pull
docker pull centurylink/dockerfile-from-image
alias dfimage="docker run -v /var/run/docker.sock:/var/run/docker.sock --rm centurylink/dockerfile-from-image"
dfimage --help
dfimage coder352/test
```

## Docker_Compose
### 结构
用官网的实例来讲解, 四个文件
``` zsh
$ mkdir composetest && cd composetest
```
app.py 用到了 flask redis, 但是不用在 host 上下载, 是在容器中安装
``` python
from flask import Flask
from redis import Redis
import os
app = Flask(__name__)
redis = Redis(host='redis', port=6379)

@app.route('/')
def hello():
    redis.incr('hits')
    return 'Hello World! I have been seen %s times.' % redis.get('hits')

if __name__ == "__main__":
    app.run(host="0.0.0.0", debug=True)
```
requirements.txt
``` zsh
flask
redis
```
Dockerfile
``` zsh
FROM python:2.7
ADD . /code
WORKDIR /code
RUN pip install -r requirements.txt
```
docker-compose.yml
``` yaml
web:
  build: .
  command: python app.py
  ports:
   - "5000:5000"
  volumes:
   - .:/code
  links:
   - redis
redis:
  image: redis
# 定义了两个服务：
# - web服务: 该容器从当前文件夹的dockerfile创建, 并运行python app.py命令
#   将web容器内部的5000端口映射到host的5000端口
#   挂载当前文件夹到容器内部的/code文件夹, 并将web容器与redis容器连接
# - redis服务: 该容器直接由官方的redis镜像创建
```
``` zsh
$ docker-compose up
Pulling image redis...
Building web...
Starting composetest_redis_1...
Starting composetest_web_1...
redis_1 | [8] 02 Jan 18:43:35.576 # Server started, Redis version 2.8.3
web_1   |  * Running on http://0.0.0.0:5000/
$ curl localhost:5000
```

### YMAL 文件参考
``` yaml
image: 镜像的 ID
build: 直接从 pwd 的 Dockerfile 来 build, 而非通过 image 选项来 pull
links: 连接到那些容器, 每个占一行, 格式为 SERVICE[:ALIAS], 例如 – db[:database]
external_links: 连接到该 compose.yaml 文件之外的容器中, 比如是提供共享或者通用服务的容器服务, 格式同 links
command: 替换默认的 command 命令
ports: 导出端口, 格式可以是 ports:-"3000"-"8000:8000"-"127.0.0.1:8001:8001"
expose: 导出端口, 但不映射到宿主机的端口上, 它仅对links的容器开放, 格式直接指定端口号即可
volumes: 加载路径作为卷, 可以指定只读模式
volumes:
  - /var/lib/mysql
  - cache/: /tmp/cache
  - ~/configs: /etc/configs/:ro
volumes_from: 加载其他容器或者服务的所有卷
environment:
  - RACK_ENV=development
  - SESSION_SECRET
env_file: 从一个文件中导入环境变量, 文件的格式为 RACK_ENV=development
extends: 扩展另一个服务, 可以覆盖其中的一些选项, 一个 sample 如下
```
``` yaml
# common.yml
webapp:
  build:./webapp
  environment:- DEBUG=false- SEND_EMAILS=false
# development.yml
web: extends:
  file: common.yml
  service: webapp
  ports: -"8000:8000"
  links: - db
  environment: - DEBUG=true
db:
  image: postgres
```
``` yaml
net: 容器的网络模式, 可以为”bridge”, “none”, “container:[name or id]”, “host”中的一个
dns: 可以设置一个或多个自定义的DNS地址
dns_search: 可以设置一个或多个DNS的扫描域
# 其他的 working_dir, entrypoint, user, hostname, domainname, mem_limit, privileged, restart, stdin_open, tty, cpu_shares,
# 和 docker run 命令是一样的, 这些命令都是单行的命令
cpu_shares: 73
working_dir: /code
entrypoint: /code/entrypoint.sh
user: postgresql
hostname: foo
domainname: foo.com
mem_limit: 1000000000
privileged: true
restart: always
stdin_open: true
tty: true
```

### 常用命令
``` zsh
docker-compose -f DVWA_MySQL_Nginx_PHP.yml -p DVWA --verbose
# --verbose: 输出详细信息
# -f: 制定一个非 docker-compose.yml 命名的 yaml 文件
# -p: 设置一个项目名称（默认是directory名）
build: 构建服务
kill -s SIGINT: 给服务发送特定的信号
logs: 输出日志
port: 输出绑定的端口
ps: 输出运行的容器
pull: pull 服务的 image
rm: 删除停止的容器
run: 运行某个服务, 例如 docker-compose run web python manage.py shell
start: 运行某个服务中存在的容器
stop: 停止某个服务中存在的容器
up: create + run + attach 容器到服务
scale: 设置服务运行的容器数量, 例如: docker-compose scale web=2 worker=3
```
