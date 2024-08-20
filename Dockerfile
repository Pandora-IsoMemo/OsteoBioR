FROM ghcr.io/pandora-isomemo/base-image:latest

ADD . .

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
    jags \
    && installPackage

CMD ["Rscript", "-e", "library(OsteoBioR);OsteoBioR::startApplication(3838)"]
