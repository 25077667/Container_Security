#!/bin/bash

#TODO: Get the version code of IBM/FHIR

WORK_PWD='/media/d/git/nsysu/cs/fhir/FHIR/fhir-install'

orig_fhir_server_file="${WORK_PWD}/Dockerfile"
new_fhir_server_file="${WORK_PWD}/Dockerfile.vul"
cp $orig_fhir_server_file $new_fhir_server_file

# Modify to trace version
sed -i "s,openliberty/open-liberty:.*ubi,openliberty-alpine,g" $new_fhir_server_file
sed -i '/RUN yum install -y unzip/d' $new_fhir_server_file
sed -i '/USER 1001/d' $new_fhir_server_file
sed -i '64iUSER root' $new_fhir_server_file

# Add vul to image
cp -r ../vul/ ${WORK_PWD}
sed -i '65iCOPY vul/ /vul' $new_fhir_server_file

docker build -t fhir-server-base:vul $WORK_PWD -f "$WORK_PWD"/Dockerfile.vul

rm -r ${WORK_PWD}/vul
