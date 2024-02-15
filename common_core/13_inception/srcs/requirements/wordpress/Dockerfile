# Base image
FROM debian:bullseye

# Set environment variables
ARG MYSQL_HOST
ARG MYSQL_DATABASE
ARG MYSQL_USER
ARG MYSQL_PASSWORD
ARG MYSQL_ROOT_PASSWORD
ARG WP_ADMIN
ARG WP_ADMIN_PASSWORD
ARG WP_ADMIN_EMAIL
ARG WP_USER
ARG WP_USER_PASSWORD
ARG WP_USER_EMAIL
ARG WP_DOMAIN
ARG WP_TITLE

USER root

# Install php server with tools and remove cache
RUN apt-get update && apt-get upgrade -y && apt-get install -y \
	apt-utils wget mariadb-client \
	php php-mysql php-fpm php-cli php-gd php-mbstring php-bcmath php-xml \
	php-common php-curl php-zip php-imagick php-ldap php-intl \
	&& rm -rf /var/lib/apt/lists/*

COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d/
COPY ./tools/wp-install.sh /usr/local/bin/

# Create the directory for php-fpm socket and wordpress files
# with correct permissions and ownership
RUN mkdir -p /var/run/php /var/www/html \
	&& chmod +x /usr/local/bin/wp-install.sh \
	&& chown -R $USER:$USER /var/www/html

WORKDIR /var/www/html

EXPOSE 9000

CMD ["/usr/sbin/php-fpm7.4", "-F"]
ENTRYPOINT ["/usr/local/bin/wp-install.sh" ]
