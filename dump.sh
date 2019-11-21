 #!/bin/bash
echo 'integrer dump'
#Create role openradiation; dans un .sql  
pg_restore -Fc  -i -U postgres  -d  postgres -c  /tmp/openradiation_website_2019_11_18.dmp
echo 'dump integre'