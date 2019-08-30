BASE_NAME=gitlab.linphone.org:4567/bc/public/flexisip
#$(eval GIT_DESCRIBE = $(shell sh -c "git describe"))
# DOCKER_TAG=$(BASE_NAME):$(GIT_DESCRIBE)
DOCKER_TAG=$(BASE_NAME):20190827
DOCKER_FILE=flex-from-src

flexisip-build:
	docker build -f $(DOCKER_FILE) --no-cache -t $(DOCKER_TAG) --rm .

flexisip-push:
	docker push $(DOCKER_TAG)

flexisip-clean:
	docker image rm $(DOCKER_TAG)
	
flexisip-ubuntu-before:
	$(eval DOCKER_FILE = flex-from-ubuntu)
	$(eval DOCKER_TAG = $(DOCKER_TAG)-ubuntu)

flexisip-ubuntu-build: flexisip-ubuntu-before flexisip-build

flexisip-ubuntu-push: flexisip-ubuntu-before flexisip-push

flexisip-ubuntu-clean: flexisip-ubuntu-before flexisip-clean

.PHONY: flexisip-build
