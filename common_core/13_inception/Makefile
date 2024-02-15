# Check if terminal supports colors
COLOR_SUPPORT := $(shell tput -T$$TERM colors)
ifeq ($(COLOR_SUPPORT),256)
	RED := $(shell tput setaf 1)
	GREEN := $(shell tput setaf 2)
	PURPLE := $(shell tput setaf 5)
	RESET := $(shell tput sgr0)
else
	RED :=
	GREEN :=
	PURPLE :=
	RESET :=
endif

# Volumes paths
DATA_PATH := /home/manny/data/
WP_PATH := $(DATA_PATH)/wordpress/
MYSQL_PATH := $(DATA_PATH)/database/

# Environment variables
ENV=./srcs/.env

# Docker compose file
COMPOSE_FILE := ./srcs/docker-compose.yml

all: setup-dirs run

setup-dirs:
	@echo "${GREEN}Creating directories for volumes...${RESET}"
	@sudo mkdir -p $(WP_PATH) $(MYSQL_PATH) || (echo "${RED}Failed to create directories. ${RESET}"; exit 1)

run: setup-dirs
	@echo "${GREEN}Building containers...${RESET}"
	@docker-compose --env-file $(ENV) -f $(COMPOSE_FILE) up --build -d || (echo "${RED}Failed to start containers.${RESET}"; exit 1)

stop:
	@echo "${RED}Stopping containers...${RESET}"
	@docker-compose -f $(COMPOSE_FILE) down || (echo "${RED}Failed to stop containers.${RESET}"; exit 1)

restart: stop run

list:
	@echo "${PURPLE}Listing containers...${RESET}"
	@docker ps -a || (echo "${RED}Failed to list containers.${RESET}"; exit 1)

volumes:
	@echo "${PURPLE}Listing volumes...${RESET}"
	@docker volume ls || (echo "${RED}Failed to list volumes.${RESET}"; exit 1)

clean: 
	@echo "${RED}Stopping containers and cleaning up...${RESET}"
	@docker-compose -f $(COMPOSE_FILE) down
	@docker stop $$(docker ps -qa) 2>/dev/null || true
	@docker rm $$(docker ps -qa) 2>/dev/null || true
	@echo "${RED}Deleting images...${RESET}"
	@docker rmi -f $$(docker images -qa) 2>/dev/null || true
	@echo "${RED}Deleting volumes...${RESET}"
	@docker volume rm $$(docker volume ls -q) 2>/dev/null || true
	@echo "${RED}Deleting networks...${RESET}"
	@docker network rm $$(docker network ls -q) 2>/dev/null || true
	@echo "${RED}Deleting data...${RESET}"
	@sudo rm -rf $(DATA_PATH) || (echo "${RED}Failed to delete data directories.${RESET}"; exit 1)

prune:
	@echo "${RED}Pruning system...${RESET}"
	@docker system prune -a || (echo "${RED}Failed to prune system.${RESET}"; exit 1)

.PHONY: setup-dirs run list volumes clean prune
