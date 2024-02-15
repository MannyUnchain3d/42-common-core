# Base image
FROM debian:bullseye

# Install nginx server with tools and remove cache
RUN apt-get update && apt-get upgrade -y && apt-get install -y nginx \
	openssl systemctl net-tools vim \
	&& rm -rf /var/lib/apt/lists/*

# Create the directory for SSL certificate
RUN mkdir -p /etc/nginx/cert

# Generate SSL certificate
RUN openssl req -x509 -newkey rsa:4096 -nodes -days 365 \
	-keyout /etc/nginx/cert/etetopat.42.fr.key \
	-out /etc/nginx/cert/etetopat.42.fr.crt \
	-subj "/C=TH/ST=Bangkok/L=Bangkok/O=42/OU=42Bangkok/CN=etetopat.42.fr"

#COPY ./conf/nginx.conf /etc/nginx/conf.d
COPY ./conf/nginx.conf /etc/nginx/nginx.conf

EXPOSE 443

# Start the nginx server in the foreground
ENTRYPOINT ["nginx", "-g", "daemon off;"]
