FROM drupal:7.88

COPY ./modules /var/www/html/modules
COPY ./profiles /var/www/html/profiles
COPY ./sites /var/www/html/sites
COPY ./themes /var/www/html/themes
COPY ./vendor /var/www/html/vendor
COPY ./favicon.ico /var/www/html/
COPY ./composer.json /var/www/html/

# Create private directory and files directory
RUN mkdir /var/www/html/private && chmod 777 /var/www/html/private \
&& mkdir /var/www/html/statics && chmod 755 /var/www/html/statics \
&& chown -R www-data /var/www/html/statics && chgrp -R www-data /var/www/html/statics \
&& chmod 755 /var/www/html/sites/default

# Install Composer
RUN curl -sS https://getcomposer.org/installer | php && \
    mv composer.phar /usr/local/bin/composer && \
    ln -s /root/.composer/vendor/bin/drush /usr/local/bin/drush

# Install Drush
RUN composer global require drush/drush:8.x && \
    composer global update

RUN apt-get update && apt-get install -y postgresql-client
