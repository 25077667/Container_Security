#!/bin/bash

#TODO: Get the version code of IBM/FHIR

WORK_PWD='/media/d/git/nsysu/cs/fhir/FHIR/fhir-install'

orig_fhir_server_file="${WORK_PWD}/Dockerfile"
new_fhir_server_file="${WORK_PWD}/Dockerfile.tracee"
cp $orig_fhir_server_file $new_fhir_server_file

# Modify to trace version
sed -i "s,openliberty/open-liberty:.*ubi,openliberty-alpine,g" $new_fhir_server_file
sed -i '/RUN yum install -y unzip/d' $new_fhir_server_file
sed -i '/USER 1001/d' $new_fhir_server_file
sed -i '64iUSER root' $new_fhir_server_file
# Add tracee into fhir
sed -i '52iCOPY --from=aquasec/tracee:latest /tracee/ /tracee' $new_fhir_server_file

# Backup bootstraps
orig_bootstraps="${WORK_PWD}/src/main/docker/ibm-fhir-server/bootstrap.sh"
cp $orig_bootstraps "$orig_bootstraps".bak

# Enable tracee in bootstraps
sed -i '2i/tracee/tracee-ebpf -t c --output json 1>/mnt/out 2>/mnt/err &' $orig_bootstraps
sed -i '3isleep 5' $orig_bootstraps

docker build -t zxc25077667/fhir-server-base:tracee $WORK_PWD -f "$WORK_PWD"/Dockerfile.tracee

cp "$orig_bootstraps".bak $orig_bootstraps
