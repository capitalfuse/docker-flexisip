############################################################################
# ORTPConfig.cmake
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
# Config file for the oRTP package.
# It defines the following variables:
#
#  ORTP_FOUND - system has oRTP
#  ORTP_INCLUDE_DIRS - the oRTP include directory
#  ORTP_LIBRARIES - The libraries needed to use oRTP
#  ORTP_CPPFLAGS - The cflags needed to use oRTP


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was ORTPConfig.cmake.in                            ########

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

set(ORTP_TARGETNAME ortp)

include("${CMAKE_CURRENT_LIST_DIR}/${ORTP_TARGETNAME}Targets.cmake")

if(ON)
	set(ORTP_LIBRARIES ${ORTP_TARGETNAME})
else()
	set(ORTP_TARGETNAME ortp-static)
	if(TARGET ${ORTP_TARGETNAME})
 		if(LINPHONE_BUILDER_GROUP_EXTERNAL_SOURCE_PATH_BUILDERS)
			set(ORTP_LIBRARIES ${ORTP_TARGETNAME})
		else()
			get_target_property(ORTP_LIBRARIES ${ORTP_TARGETNAME} LOCATION)
		endif()
		get_target_property(ORTP_LINK_LIBRARIES ${ORTP_TARGETNAME} INTERFACE_LINK_LIBRARIES)
		if(ORTP_LINK_LIBRARIES)
		  list(APPEND ORTP_LIBRARIES ${ORTP_LINK_LIBRARIES})
		endif()
	endif()
endif()

get_target_property(ORTP_INCLUDE_DIRS ${ORTP_TARGETNAME} INTERFACE_INCLUDE_DIRECTORIES)

set(ORTP_CPPFLAGS )
set(ORTP_FOUND 1)
