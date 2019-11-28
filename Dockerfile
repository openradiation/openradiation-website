FROM postgres:9.4
WORKDIR /tmp
COPY openradiation_website_2019_11_18.dmp .
ONBUILD pg_restore -Fc  -i -U postgres  -d  openradiation_website -c  /openradiation_website_2019_11_18.dmp