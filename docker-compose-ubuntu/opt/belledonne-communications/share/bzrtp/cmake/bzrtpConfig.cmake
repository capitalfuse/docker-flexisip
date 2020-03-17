############################################################################
# BZRTPConfig.cmake
# Copyright (C) 2015  Belledonne Communications, Grenoble France
#
############################################################################
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
#
############################################################################
#
# Config file for the bzrtp package.
# It defines the following variables:
#
#  BZRTP_FOUND - system has bzrtp
#  BZRTP_INCLUDE_DIRS - the bzrtp include directory
#  BZRTP_LIBRARIES - The libraries needed to use bzrtp
#  BZRTP_CPPFLAGS - The compilation flags needed to use bzrtp


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was BZRTPConfig.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################

set(BZRTP_TARGETNAME bzrtp)

include("${CMAKE_CURRENT_LIST_DIR}/${BZRTP_TARGETNAME}Targets.cmake")

if(ON)
	set(BZRTP_LIBRARIES ${BZRTP_TARGETNAME})
else()
	if(TARGET ${BZRTP_TARGETNAME})
		get_target_property(BZRTP_LIBRARIES ${BZRTP_TARGETNAME} LOCATION)
		get_target_property(BZRTP_LINK_LIBRARIES ${BZRTP_TARGETNAME} INTERFACE_LINK_LIBRARIES)
		if(BZRTP_LINK_LIBRARIES)
			list(APPEND BZRTP_LIBRARIES ${BZRTP_LINK_LIBRARIES})
		endif()
	endif()
endif()

get_target_property(BZRTP_INCLUDE_DIRS ${BZRTP_TARGETNAME} INTERFACE_INCLUDE_DIRECTORIES)

set(BZRTP_CPPFLAGS )
set(BZRTP_FOUND 1)
