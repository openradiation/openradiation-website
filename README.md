# Overview

Openradiation, projet opensource

## architecture
le dossier drupal/ contient l'ensemble des sources du projet

## instanciation Local

Lancement de l'application
```
docker-compose up
```

Ajout d'une base de donnée
```
docker-compose exec db bash
psql --username=openradiation -d postgres -f /tmp/dump/dump-xxxxxx.sql
```
