############################################################################
# decafConfig.cmake
# Copyright (C) 2017  Belledonne Communications, Grenoble France
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
# Config file for the decaf package.
# It defines the following variables:
#
#  DECAF_FOUND - system has decaf
#  DECAF_INCLUDE_DIRS - the decaf include directory
#  DECAF_LIBRARIES - The libraries needed to use decaf
#  DECAF_CPPFLAGS - The compilation flags needed to use decaf


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was DecafConfig.cmake.in                            ########

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

include("${CMAKE_CURRENT_LIST_DIR}/DecafTargets.cmake")

if(ON)
	set(DECAF_TARGETNAME decaf)
else()
	set(DECAF_TARGETNAME decaf-static)
endif()

get_target_property(DECAF_INCLUDE_DIRS ${DECAF_TARGETNAME} INTERFACE_INCLUDE_DIRECTORIES)

if(TARGET ${DECAF_TARGETNAME})
	get_target_property(DECAF_LIBRARIES ${DECAF_TARGETNAME} LOCATION)
	get_target_property(DECAF_LINK_LIBRARIES ${DECAF_TARGETNAME} INTERFACE_LINK_LIBRARIES)
	if(DECAF_LINK_LIBRARIES)
		list(APPEND DECAF_LIBRARIES ${DECAF_LINK_LIBRARIES})
	endif()
endif()

set(DECAF_CPPFLAGS )
set(DECAF_FOUND 1)
