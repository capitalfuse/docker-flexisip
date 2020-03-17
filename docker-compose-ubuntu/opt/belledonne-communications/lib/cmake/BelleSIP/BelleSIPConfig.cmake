############################################################################
# BelleSIPConfig.cmake
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
# Config file for the belle-sip package.
# It defines the following variables:
#
#  BELLESIP_FOUND - system has belle-sip
#  BELLESIP_INCLUDE_DIRS - the belle-sip include directory
#  BELLESIP_LIBRARIES - The libraries needed to use belle-sip
#  BELLESIP_CPPFLAGS - The compilation flags needed to use belle-sip
#  BELLESIP_LDFLAGS - The linking flags needed to use belle-sip


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was BelleSIPConfig.cmake.in                            ########

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

if(NOT LINPHONE_BUILDER_GROUP_EXTERNAL_SOURCE_PATH_BUILDERS)
	include("${CMAKE_CURRENT_LIST_DIR}/BelleSIPTargets.cmake")
endif()

if(ON)
	set(BELLESIP_TARGETNAME bellesip)
	set(BELLESIP_LIBRARIES ${BELLESIP_TARGETNAME})
else()
	set(BELLESIP_TARGETNAME bellesip-static)
	if(TARGET ${BELLESIP_TARGETNAME})
		if(LINPHONE_BUILDER_GROUP_EXTERNAL_SOURCE_PATH_BUILDERS)
			set(BELLESIP_LIBRARIES ${BELLESIP_TARGETNAME})
		else()
			get_target_property(BELLESIP_LIBRARIES ${BELLESIP_TARGETNAME} LOCATION)
		endif()
		get_target_property(BELLESIP_LINK_LIBRARIES ${BELLESIP_TARGETNAME} INTERFACE_LINK_LIBRARIES)
		if(BELLESIP_LINK_LIBRARIES)
			list(APPEND BELLESIP_LIBRARIES ${BELLESIP_LINK_LIBRARIES})
		endif()
	endif()
endif()

get_target_property(BELLESIP_INCLUDE_DIRS ${BELLESIP_TARGETNAME} INTERFACE_INCLUDE_DIRECTORIES)

set(BELLESIP_CPPFLAGS )
set(BELLESIP_LDFLAGS "")
set(BELLESIP_FOUND 1)
