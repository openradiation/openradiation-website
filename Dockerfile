FROM postgres:9.4
WORKDIR /tmp
COPY openradiation_website_2019_11_18.dmp .
COPY dump.sh .
# RUN chmod dump.sh 
# ENTRYPOINT  ./dump.sh