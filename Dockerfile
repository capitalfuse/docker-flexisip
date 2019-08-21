FROM ubuntu:18.04
MAINTAINER  Takanobu Fuse <ficus.online@gmail.com>

# Configure locale
RUN apt-get update && \
    apt-get install -y locales && \
    apt-get autoremove -y && \
    apt-get clean && \
    echo "en_US.UTF-8 UTF-8" > /etc/locale.gen && \
    locale-gen
ENV LANG='en_US.UTF-8' LANGUAGE='en_US:en' LC_ALL='en_US.UTF-8'

ENV SHELL=/bin/bash

# ARG DEBIAN_FRONTEND=noninteractive

# Install common general tools
RUN apt-get update && \
    apt-get install -y nano sudo vim && \
    apt-get autoremove -y && \
    apt-get clean

# Install development tools
RUN apt-get update && \
    apt-get install -y alien at autoconf bison ccache clang cmake doxygen elfutils g++ gdb git graphviz intltool libtool lsb-release make nasm ninja-build openssh-client patch python-pip python-pystache python-six yasm && \
    apt-get autoremove -y && \
    apt-get clean && \
    pip install sphinx javasphinx sphinx_csharp

# Install linphone & flexisip dependencies development packages
RUN apt-get update && \
    apt-get install -y libasound2-dev libavcodec-dev libavutil-dev libbsd-dev libegl1-mesa-dev libglew-dev libgsm1-dev libjansson-dev libmariadb-dev-compat libmbedtls-dev libopus-dev libpq-dev libprotobuf-dev libpulse-dev libqt5svg5-dev libsnmp-dev libspeex-dev libspeexdsp-dev libsqlite3-dev libsrtp2-dev libssl-dev libswscale-dev libturbojpeg0-dev libv4l-dev libvpx-dev libxerces-c-dev libxml2-dev libxv-dev protobuf-compiler qt3d5-dev qt5-default qtbase5-dev qtbase5-dev-tools qtconnectivity5-dev qtdeclarative5-dev qtdeclarative5-dev-tools qtdeclarative5-dev-tools qtquickcontrols2-5-dev qttools5-dev qttools5-dev-tools xsdcxx && \
    apt-get autoremove -y && \
    apt-get clean

#get source code
RUN git clone https://gitlab.linphone.org/BC/public/flexisip.git --recursive --depth 1
RUN cd flexisip && ./prepare.py flexisip -DENABLE_TRANSCODER=ON -DENABLE_SNMP=YES -DENABLE_DOC=OFF -DENABLE_PROTOBUF=YES -DCMAKE_PREFIX_PATH=/opt/belledonne-communications -DCMAKE_INSTALL_PREFIX=/opt/belledonne-communications -DSYSCONF_INSTALL_DIR=/etc && make
RUN mkdir -p /etc/opt/belledonne-communications/flexisip
RUN mkdir -p /var/opt/belledonne-communications/log/flexisip
RUN ln -s /etc/opt/belledonne-communications/flexisip /etc/flexisip

# Add it to the default path
ENV PATH=$PATH:/opt/belledonne-communications/bin

WORKDIR /opt/belledonne-communications

# Generate a default configuration
RUN flexisip --dump-default all > /etc/flexisip/flexisip.conf

VOLUME /etc/opt/belledonne-communications/flexisip
VOLUME /var/opt/belledonne-communications/log/flexisip
COPY flexisip-entrypoint.sh /
COPY backtrace.gdb /
RUN chmod a+x /flexisip-entrypoint.sh

# Script to wait db before launch flexisip [Licence Apache2]
ADD https://github.com/ufoscout/docker-compose-wait/releases/download/2.2.1/wait /wait
RUN chmod +x /wait

#cleanup
RUN apt-get remove -y nasm patch python-pip python-pystache graphviz intltool libtool python-dev doxygen g++ make cmake git pkg-config libpulse-dev libssl-dev default-libmysqlclient-dev build-essential && \
    rm -rf flexisip && \
    apt-get clean all


ENTRYPOINT ["/flexisip-entrypoint.sh"]
CMD flexisip
