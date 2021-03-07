FROM ubuntu

ENV KFC=EGG_TART

RUN apt update && apt install -y x11vnc xvfb firefox

RUN useradd -m user1 --uid=1000 && \
    echo "user1:Ch@ng3_m3" | chpasswd
USER user1:1000
WORKDIR /home/user1

RUN bash -c 'echo "firefox" >> /home/user1/.bashrc' && \
    mkdir ~/.vnc && \
    x11vnc -storepasswd nsysuisc ~/.vnc/passwd

EXPOSE 5900
CMD    ["x11vnc", "-forever", "-usepw", "-create"]
