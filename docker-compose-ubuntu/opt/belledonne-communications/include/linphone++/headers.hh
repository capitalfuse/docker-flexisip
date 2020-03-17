/*
Copyright (C) 2017 Belledonne Communications SARL

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef _LINPHONE_HEADERS_HH
#define _LINPHONE_HEADERS_HH

#include <string>
#include "object.hh"




struct _LinphoneHeaders;


namespace linphone {


	/**
	 * @brief Object representing a chain of protocol headers. 
	 *
	 * It provides read/write access to the headers of the underlying protocol. 
	 */
	class Headers: public Object {
	
		public:

			Headers(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneHeaders *cPtr() {return (_LinphoneHeaders *)mPrivPtr;}

	
		public:
			
		
			/**
			 * @brief Add given header name and corresponding value. 
			 *
			 * @param name the header's name 
			 */
			LINPHONECXX_PUBLIC void add(const std::string & name, const std::string & value);
			
			/**
			 * @brief Search for a given header name and return its value. 
			 *
			 * @return the header's value or nullptr if not found. 
			 */
			LINPHONECXX_PUBLIC std::string getValue(const std::string & headerName);
			
			/**
			 * @brief Add given header name and corresponding value. 
			 *
			 * @param name the header's name 
			 */
			LINPHONECXX_PUBLIC void remove(const std::string & name);
			
			
	};

};

#endif // _LINPHONE_HEADERS_HH
