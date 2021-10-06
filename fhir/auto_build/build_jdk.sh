#!/bin/bash

#TODO: Get the version code of jdk
WORK_PWD='/media/d/git/nsysu/cs/fhir/ci.docker/releases/21.0.0.6/kernel-slim/'

ubi_docker_file="${WORK_PWD}Dockerfile.ubi.adoptopenjdk11"
alpine_docker_file="${WORK_PWD}Dockerfile.alpine.adoptopenjdk11"
# alpine_docker_file="${WORK_PWD}Dockerfile.alpinee.adoptopenjdk11"

# Change the jdk image
cp $ubi_docker_file $alpine_docker_file
sed -i 's/FROM\(.*\)ubi/FROM\1alpine/g' $alpine_docker_file
sed -i 's/yum -y install shadow-utils wget unzip openssl/apk update \&\& apk add --no-cache shadow wget unzip openssl bash elfutils-dev/' $alpine_docker_file
sed -i '/&& yum -y remove.*/d' $alpine_docker_file
sed -i '/&& yum clean.*/d' $alpine_docker_file
sed -i 's/| sha1sum -c --strict --check //' $alpine_docker_file
sed -i 's/adduser -u 1001 -r -g root/adduser -u 1001 -S -G root/g' $alpine_docker_file

# Add tracee into jdk
# sed -i '25iCOPY --from=aquasec/tracee:latest /tracee/ /tracee' $alpine_docker_file

# Build alpine jdk
docker build -t openliberty-alpine ${WORK_PWD} -f $alpine_docker_file
