step 1 : docker-compose up -d
step 2 : docker ps --all
	#verifier le status des services
	#lancer les services (status a Up)
step 3 :  docker-compose start
	#accès contener de BDD
step 4 : docker exec -it .... /bin/bash
	#remplacer les .... par les 4 premier caracteres du "Container id" de la BDD
step 5 : psql -U postgres
step 6 : Create role openradiation;
step 7 :\q
step 8 : cd ..
step 9 :pg_restore -Fc  -i -U postgres  -d  postgres -c  /tmp/openradiation_website_2019_11_18.dmp
