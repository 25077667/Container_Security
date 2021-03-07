#!/bin/bash

git clone https://github.com/docker/example-voting-app.git
cd example-voting-app

# Initialize docker swarm
sudo docker swarm init

# Deploy
sudo docker stack deploy --compose-file docker-stack.yml vote
