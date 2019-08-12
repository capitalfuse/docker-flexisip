# The Dockerfile to build the docker image for sip server flexisip on Ubuntu 18.04

ex) How to build the Docker image for flexisip from the Dockerfile
```
$ docker build --no-cache -t linphone/flexisip:20190808 .
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
**Reference**
https://github.com/BelledonneCommunications/flexisip
