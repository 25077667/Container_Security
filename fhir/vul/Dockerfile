FROM golang:alpine as builder

LABEL MAINTAINER="zxc25077667@pm.me"
LABEL AUTHOR="25077667/SCC"
RUN apk --no-cache add libcap

COPY ["main.go", "go.mod", "go.sum", "/src/"]
WORKDIR /src
# Build vul go only
RUN CGO_ENABLED=0 GOOS=linux go build -ldflags="-s -w" -o main main.go

FROM alpine
LABEL MAINTAINER="zxc25077667@pm.me"
LABEL AUTHOR="25077667/SCC"
COPY ["chief.png", "index.html", "/target/"]
COPY --from=builder /src/main /target
WORKDIR /target
