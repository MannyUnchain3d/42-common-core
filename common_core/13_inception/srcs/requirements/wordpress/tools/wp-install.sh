#!/bin/sh

if [ ! -f wp-config.php ]; then
	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
	chmod +x wp-cli.phar
	mv wp-cli.phar /usr/local/bin/wp
	wp cli update
	cd /var/www/html
	echo "Downloading wordpress"
	wp core download --allow-root
	wp config create --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=$MYSQL_HOST --allow-root
	echo "Installing wordpress"
	wp core install --url=$WP_DOMAIN --title=$WP_TITLE --admin_user=$WP_ADMIN --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL --allow-root
	wp user create $WP_USER $WP_USER_EMAIL --role=author --user_pass=$WP_USER_PASSWORD --allow-root
	wp plugin update --all --allow-root
	wp theme install inspiro --activate --allow-root
	chown -R www-data:www-data /var/www/html
	echo "Wordpress installed"
fi

/usr/sbin/php-fpm7.4 -F
