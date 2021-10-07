#!/bin/bash

#TODO: Get the version code of IBM/FHIR

WORK_PWD='/media/d/git/nsysu/cs/fhir/FHIR/fhir-install'

orig_fhir_server_file="${WORK_PWD}/Dockerfile"
new_fhir_server_file="${WORK_PWD}/Dockerfile.vul"
cp $orig_fhir_server_file $new_fhir_server_file

# Modify to trace version
sed -i "s,openliberty/open-liberty:.*ubi,openliberty-alpine,g" $new_fhir_server_file
sed -i '/RUN yum install -y unzip/d' $new_fhir_server_file

# Backup bootstraps
orig_bootstraps="${WORK_PWD}/src/main/docker/ibm-fhir-server/bootstrap.sh"
cp $orig_bootstraps "$orig_bootstraps".bak

# Enable vul/escape in bootstrags
sed -i '15i/vul/main &' $orig_bootstraps
sed -i '16isleep 3' $orig_bootstraps

# Add vul to image
sed -i '65iCOPY --chown=1001:0 --from=zxc25077667/cesc:latest /target /vul' $new_fhir_server_file

docker build -t zxc25077667/fhir-server-base:vul $WORK_PWD -f "$WORK_PWD"/Dockerfile.vul

cp "$orig_bootstraps".bak $orig_bootstraps
