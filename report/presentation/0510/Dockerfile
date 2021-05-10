FROM debian

RUN apt update && apt install vim build-essential openssl htop neofetch tree openssh-server -y && apt upgrade -y && apt clean -y && apt autoclean -y
RUN mkdir /var/run/sshd && chmod 755 -R /var/run/sshd && touch /var/log/auth.log && chmod 755 /var/log/auth.log

RUN for i in $(seq 40); do \
    useradd -ms /bin/bash "u$i"; \
    echo -n "u$i:" >> pw.txt; \
    head -c "$i"3 /dev/random | openssl SHA256 | awk '{print $2}' >> pw.txt; \
    cat pw.txt | chpasswd; \
    cat pw.txt && rm pw.txt; \
    ln -sf /res /home/u"$i"/res;\
    done
RUN sed 's@session\s*required\s*pam_loginuid.so@session optional pam_loginuid.so@g' -i /etc/pam.d/sshd


COPY . /res
WORKDIR /res

EXPOSE 22
CMD ["/usr/sbin/sshd", "-D"]