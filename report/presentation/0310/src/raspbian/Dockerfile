FROM navikey/raspbian-buster

COPY qemu-system-arm /usr/bin/qemu-system-arm

ENV TZ=Asia/Taipei

RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && \
    echo $TZ > /etc/timezone && \
    apt update -y && \
    apt install libapparmor-dev build-essential python3 tmux zsh vim curl git -y

ADD ./work /work
WORKDIR /work
