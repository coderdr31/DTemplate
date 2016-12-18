# Usage:
# docker build . -f Ubuntu_16.04_xenial.Dockerfile -t coderdr31/ubuntu:16.04

FROM ubuntu:16.04
MAINTAINER coderdr31 <1683751393@qq.com>

# Preparation
ADD ./src/ubuntu_16.04_xenial_aliyun_sources.list /etc/apt/sources.list
# 下面这个还不需要
# ADD https://raw.githubusercontent.com/coderdr31/shellscript/master/myscript /root/.myscript
# && echo ". /root/.myscript" >> /root/.bashrc \

# 将 DEBIAN_FRONTEND 放到这里只是针对这一条命令, 不会对全局和 docker run 中造成影响
# 遵循在一个层次上保证镜像的纯洁
# set -xe, 在 bash 下是将执行的命令打印一遍, 遇到错误直接退出, 还可以把执行的命令用不同的颜色显示, zsh 下会错
# -qq 只显示安装成功, -q 显示的和不加差不多
# -pruge 和 auto-remove 有冲突
RUN set -xe \
    && echo "0x01 : Build Dependency" \
    && echo "################################" \
    && buildDeps=" \
    " \
    && echo "0x02 : Run Dependency" \
    && echo "##############################" \
    && runtimeDeps=" \
        sudo \
        bash-completion \
        apt-utils \
        vim \
        python-pip \
        wget \
        netcat-openbsd \
        curl \
        net-tools \
        iputils-ping \
        git \
        openssh-server \
    " \
    && echo "0x03 : Install Build and Run Dependency" \
    && echo "################################################" \
    && apt-get -y update \
    && DEBIAN_FRONTEND=noninteractive apt-get -y install ${buildDeps} ${runtimeDeps} --no-install-recommends \
    && echo "0x04 : Clean" \
    && echo "#####################"

    # 自己用的就不清除了, 可能随时都要测试软件
    # && apt-get -y auto-remove \
        # -o APT::AutoRemove::RecommendsImportant=false \
        # -o APT::AutoRemove::SuggestsImportant=false \
        # ${buildDeps} \
    # && apt-get -y clean \
    # && rm -rf /var/cache/apt/* \
    # && rm -rf /var/lib/apt/list/*

RUN useradd -ms /bin/bash coderdr31 && echo 'coderdr31:jk' | chpasswd && adduser coderdr31 sudo

# USER coderdr31
# WORKDIR /home/coderdr31
# CMD /bin/bash

# RUN \
#   rm -fr /app/* && \
#   apt-get update && apt-get install -yqq wget unzip && \
#   rm -rf /var/lib/apt/lists/* && \
#   wget https://github.com/RandomStorm/DVWA/archive/v1.0.8.zip  && \
#   unzip /v1.0.8.zip && \
#   rm -rf app/* && \
#   cp -r /DVWA-1.0.8/* /app && \
#   rm -rf /DVWA-1.0.8 && \
#   sed -i "s/^\$_DVWA\[ 'db_user' \] = 'root'/\$_DVWA[ 'db_user' ] = 'admin'/g" /app/config/config.inc.php && \
#   echo "sed -i \"s/p@ssw0rd/\$PASS/g\" /app/config/config.inc.php" >> /create_mysql_admin_user.sh  && \
#   echo 'session.save_path = "/tmp"' >> /etc/php5/apache2/php.ini
#
# EXPOSE 80 3306
# CMD ["/run.sh"]
