FROM inwt/r-shiny:4.4.3

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
    jags

RUN echo "options(repos = c(getOption('repos'), PANDORA = 'https://Pandora-IsoMemo.github.io/drat/'))" >> /usr/local/lib/R/etc/Rprofile.site

RUN installPackage \
    rstan \
    rstantools
    
RUN Rscript -e "remotes::install_github('r-lib/httr2@v1.2.3')" \
    && Rscript -e "remotes::install_github('tidyverse/ellmer@v0.4.1')"

ADD . .

RUN Rscript -e "rstantools::rstan_config()"

RUN installPackage

CMD ["Rscript", "-e", "library(OsteoBioR);OsteoBioR::startApplication(3838)"]
