FROM alpine:3.20
WORKDIR /firmware
COPY dist/ /firmware/
CMD ["ls", "-la", "/firmware"]
