# Base image
FROM debian:bullseye

# Set environment variables
ARG MYSQL_DATABASE
ARG MYSQL_USER
ARG MYSQL_PASSWORD
ARG MYSQL_ROOT_PASSWORD

USER root

# Install mariadb server and remove cache
RUN apt-get update && apt-get upgrade -y && apt-get install -y mariadb-server \
	&& rm -rf /var/lib/apt/lists/*

COPY ./tools/ /root/tools/
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/

# Run script to create database and user
RUN chmod 777 /root/tools/create_db.sh
RUN ./root/tools/create_db.sh

# Create directory with correct permissions and ownership for socket
RUN mkdir -p /var/run/mysqld \
	&& chown -R mysql:mysql /var/run/mysqld \
	&& chmod -R 777 /var/run/mysqld

VOLUME /var/lib/mysql

EXPOSE 3306

CMD ["mysqld"]
