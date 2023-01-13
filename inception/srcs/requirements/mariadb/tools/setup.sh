#!/bin/sh
service mysql start;

mysql -e "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;"
mysql -e "CREATE USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';"
mysql -e "GRANT ALL PRIVILEGES ON *.* TO '$MYSQL_USER'@'%';"
mysql -e "FLUSH PRIVILEGES;"
mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';"


mysqladmin -u root -p$MYSQL_ROOT_PASSWORD shutdown

exec mysqld_safe
