FROM debian

COPY . .

RUN dpkg --add-architecture i386
RUN apt-get update && \
    apt install wine wine32 wine64 libwine libwine:i386 fonts-wine -y

ENV DISPLAY :0
