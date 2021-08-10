FROM python:alpine

COPY --from=aquasec/tracee:latest /tracee/ /tracee/
COPY ./ /app
RUN apk --no-cache update && apk --no-cache add libc6-compat elfutils-dev

WORKDIR /app/

CMD ./entry.sh