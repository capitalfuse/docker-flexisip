############################################################################
# BcToolboxConfig.cmake
# Copyright (C) 2010-2019 Belledonne Communications, Grenoble France
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
# Config file for the bctoolbox package.
# Some components can be asked for: core, tester.
#
# It defines the following variables:
#
#  BCTOOLBOX_FOUND - system has bctoolbox
#  BCTOOLBOX_INCLUDE_DIRS - the bctoolbox include directory
#  BCTOOLBOX_LIBRARIES - The libraries needed to use bctoolbox
#  BCTOOLBOX_CPPFLAGS - The compilation flags needed to use bctoolbox
#  BCTOOLBOX_LDFLAGS - The linking flags needed to use bctoolbox
#  BCTOOLBOX_${comp}_FOUND - system has bctoolbox "comp" component
#  BCTOOLBOX_${comp}_INCLUDE_DIRS - the bctoolbox "comp" component include directory
#  BCTOOLBOX_${comp}_LIBRARIES - The libraries needed to use bctoolbox "comp" component


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was BcToolboxConfig.cmake.in                            ########

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

include("${CMAKE_CURRENT_LIST_DIR}/bctoolboxTargets.cmake")

list(APPEND bctoolbox_FIND_COMPONENTS core)

if (ENABLE_TESTS_COMPONENT)
	list(APPEND bctoolbox_FIND_COMPONENTS tester)
endif()

list(REMOVE_DUPLICATES bctoolbox_FIND_COMPONENTS)
set(bctoolbox_FIND_REQUIRED_core TRUE)

set(BCTOOLBOX_CPPFLAGS )
set(BCTOOLBOX_LDFLAGS "")
set(BCTOOLBOX_LIBRARIES )
foreach(comp ${bctoolbox_FIND_COMPONENTS})
	string(TOUPPER ${comp} uppercomp)
	if(comp STREQUAL "core")
		set(targetname bctoolbox)
	else()
		set(targetname bctoolbox-${comp})
	endif()
	if(ON)
		set(BCTOOLBOX_${uppercomp}_LIBRARIES ${targetname})
	else()
		set(targetname ${targetname}-static)
		if(TARGET ${targetname})
			if(LINPHONE_BUILDER_GROUP_EXTERNAL_SOURCE_PATH_BUILDERS)
				set(BCTOOLBOX_${uppercomp}_LIBRARIES ${targetname})
			else()
				get_target_property(BCTOOLBOX_${uppercomp}_LIBRARIES ${targetname} LOCATION)
			endif()
			if(NOT BCTOOLBOX_${uppercomp}_LIBRARIES)
				set(BCTOOLBOX_${uppercomp}_LIBRARIES)
			endif()
			get_target_property(BCTOOLBOX_${uppercomp}_LINK_LIBRARIES ${targetname} INTERFACE_LINK_LIBRARIES)
			if(BCTOOLBOX_${uppercomp}_LINK_LIBRARIES)
				list(APPEND BCTOOLBOX_${uppercomp}_LIBRARIES ${BCTOOLBOX_${uppercomp}_LINK_LIBRARIES})
			endif()
		endif()
	endif()
	if(TARGET ${targetname})
		get_target_property(BCTOOLBOX_${uppercomp}_INCLUDE_DIRS ${targetname} INTERFACE_INCLUDE_DIRECTORIES)
		if(NOT BCTOOLBOX_${uppercomp}_INCLUDE_DIRS)
			set(BCTOOLBOX_${uppercomp}_INCLUDE_DIRS)
		endif()

		list(APPEND BCTOOLBOX_LIBRARIES ${BCTOOLBOX_${uppercomp}_LIBRARIES})
		list(APPEND BCTOOLBOX_INCLUDE_DIRS ${BCTOOLBOX_${uppercomp}_INCLUDE_DIRS})
		set(BCTOOLBOX_${uppercomp}_FOUND 1)
		if(comp STREQUAL "core")
			set(BCTOOLBOX_FOUND 1)
		endif()
	elseif(bctoolbox_FIND_REQUIRED_${comp})
		message(FATAL_ERROR "Required bctoolbox component \"${comp}\" cannot be found")
	endif()
endforeach()

set(BCTOOLBOX_CMAKE_DIR "${CMAKE_CURRENT_LIST_DIR}")
set(BCTOOLBOX_CMAKE_UTILS "${CMAKE_CURRENT_LIST_DIR}/bctoolboxCMakeUtils.cmake")
include("${BCTOOLBOX_CMAKE_UTILS}")
