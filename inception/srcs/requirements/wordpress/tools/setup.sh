#!/bin/bash

cp /var/www/html/wp-config-sample.php \
    /var/www/html/wp-config.php
    
sed -i 's/database_name_here/'"$MYSQL_DATABASE"'/gi' /var/www/html/wp-config.php
sed -i 's/username_here/'"$MYSQL_USER"'/gi' /var/www/html/wp-config.php
sed -i 's/password_here/'"$MYSQL_PASSWORD"'/gi' /var/www/html/wp-config.php
sed -i 's/localhost/mariadb:3306/gi' /var/www/html/wp-config.php

cd /var/www/html
wp config shuffle-salts --allow-root
cd /
service php7.3-fpm start | php-fpm7.3 -F
