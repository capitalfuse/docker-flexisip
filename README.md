# The Dockerfile to build the docker image for sip server flexisip on Ubuntu 18.04 and Debian9 Stretch

***How to build the Docker image for flexisip from the Dockerfile for Ubuntu***

```
$ docker build --squash --no-cache -t linphone/flexisip:20190808 .
```

Run docker container
```
$ docker run -dti --network host --name linphone_flexisip linphone/flexisip:20190808
```

***Build Options: Add options formatted as "-DENABLE_XXX=??" into the potition following "./prepare.py" at the "#get source code" section.***
```
#get source code
RUN git clone https://gitlab.linphone.org/BC/public/flexisip.git --recursive --depth 1
RUN cd flexisip && ./prepare.py flexisip -DENABLE_TRANSCODER=ON -DCMAKE_PREFIX_PATH=/opt/belledonne-communications -DCMAKE_INSTALL_PREFIX=/opt/belledonne-communications -DSYSCONF_INSTALL_DIR=/etc && make
```
```
  -DENABLE_REDIS=YES 
  -DENABLE_TRANSCODER=YES 
  -DENABLE_UNIT_TESTS=OFF 
  -DENABLE_SOCI=YES 
  -DENABLE_PRESENCE=YES 
  -DENABLE_CONFERENCE=YES 
  -DENABLE_SNMP=YES 
  -DENABLE_DOC=OFF 
  -DENABLE_PROTOBUF=YES 
  -DENABLE_MDNS=NO 
  -DENABLE_JWE_AUTH_PLUGIN=YES 
  -DENABLE_EXTERNAL_AUTH_PLUGIN=YES 
  -DENABLE_SOCI=YES"
```

***How to build the Docker image for flexisip from the Dockerfile for debian***

It is more easier way than making an image for Ubuntu because of being prepared the binaries of the flexisip for Debian.
```
$ cd debian
$ make flexisip-deb-build
``` 

Run docker container
```
docker run -dti --cap-add=NET_ADMIN --cap-add=NET_RAW --network host --name debian_flexisip docker_image_ID
```
"--cap-add=NET_ADMIN" and "--cap-add=NET_RAW" need for running the internal iptables command.

go into the container
```
$ docker exec -ti debian_flexisip bash
```
If you need snmp, implement the following command inside the container:
```
# /etc/init.d/snmpd start
``

Check flexisip version and compiled options
``` 
/opt/belledonne-communications# flexisip -v

flexisip  version: 1.0.13 (git: 1.0.13-256-gd3c516aa)
sofia-sip version 1.13.35bc

Compiled with:
- SNMP
- Transcoder
- Redis
- Soci
- Protobuf
- Presence
- Conference

```

**Reference**
https://github.com/BelledonneCommunications/flexisip
