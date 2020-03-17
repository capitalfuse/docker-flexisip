############################################################################
# LinphoneConfig.cmake
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
#  LINPHONE_FOUND - system has linphone
#  LINPHONE_INCLUDE_DIRS - the linphone include directory
#  LINPHONE_LIBRARIES - The libraries needed to use linphone
#  LINPHONE_CPPFLAGS - The compilation flags needed to use linphone
#  LINPHONE_LDFLAGS - The linking flags needed to use linphone


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was LinphoneConfig.cmake.in                            ########

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

include("${CMAKE_CURRENT_LIST_DIR}/LinphoneTargets.cmake")

set(LINPHONE_TARGETNAME linphone)

if(ON)
	set(LINPHONE_LIBRARIES ${LINPHONE_TARGETNAME})
else()
	set(LINPHONE_TARGETNAME linphone-static)
	if(TARGET ${LINPHONE_TARGETNAME})
		if(LINPHONE_BUILDER_GROUP_EXTERNAL_SOURCE_PATH_BUILDERS)
			set(LINPHONE_LIBRARIES ${LINPHONE_TARGETNAME})
		else()
			get_target_property(LINPHONE_LIBRARIES ${LINPHONE_TARGETNAME} LOCATION)
		endif()
		get_target_property(LINPHONE_LINK_LIBRARIES ${LINPHONE_TARGETNAME} INTERFACE_LINK_LIBRARIES)
		if(LINPHONE_LINK_LIBRARIES)
			list(APPEND LINPHONE_LIBRARIES ${LINPHONE_LINK_LIBRARIES})
		endif()
	endif()
endif()
get_target_property(LINPHONE_INCLUDE_DIRS ${LINPHONE_TARGETNAME} INTERFACE_INCLUDE_DIRECTORIES)

set_target_properties(${LINPHONE_TARGETNAME} PROPERTIES INTERFACE_LINK_LIBRARIES "")

set(LINPHONE_CPPFLAGS )
set(LINPHONE_LDFLAGS " ")
set(LINPHONE_FOUND 1)
