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

#ifndef _LINPHONE_BUFFER_HH
#define _LINPHONE_BUFFER_HH

#include <cstdint>
#include <string>
#include "object.hh"




struct _LinphoneBuffer;


namespace linphone {

	class Buffer;

	/**
	 * @brief The #Content object representing a data buffer. 
	 *
	 */
	class Buffer: public Object {
	
		public:

			Buffer(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneBuffer *cPtr() {return (_LinphoneBuffer *)mPrivPtr;}

	
		public:
			
		
			/**
			 * @brief Get the content of the data buffer. 
			 *
			 * @return The content of the data buffer. 
			 */
			LINPHONECXX_PUBLIC const uint8_t * getContent() const;
			
			/**
			 * @brief Tell whether the #linphone::Buffer is empty. 
			 *
			 * @return A boolean value telling whether the #linphone::Buffer is empty or not. 
			 */
			LINPHONECXX_PUBLIC bool isEmpty() const;
			
			/**
			 * @brief Get the size of the content of the data buffer. 
			 *
			 * @return The size of the content of the data buffer. 
			 */
			LINPHONECXX_PUBLIC size_t getSize() const;
			
			/**
			 * @brief Set the size of the content of the data buffer. 
			 *
			 * @param size The size of the content of the data buffer. 
			 */
			LINPHONECXX_PUBLIC void setSize(size_t size);
			
			/**
			 * @brief Get the string content of the data buffer. 
			 *
			 * @return The string content of the data buffer. 
			 */
			LINPHONECXX_PUBLIC std::string getStringContent() const;
			
			/**
			 * @brief Set the string content of the data buffer. 
			 *
			 * @param content The string content of the data buffer. 
			 */
			LINPHONECXX_PUBLIC void setStringContent(const std::string & content);
			
			/**
			 * @brief Set the content of the data buffer. 
			 *
			 * @param size The size of the content of the data buffer. 
			 */
			LINPHONECXX_PUBLIC void setContent(const uint8_t * content, size_t size);
			
			;
			/**
			 * @brief Create a new #linphone::Buffer object from existing data. 
			 *
			 * @param size The size of the initial data to stroe in the LinphoneBuffer. 
			 * 
			 * @return A new #linphone::Buffer object. 
			 */
			LINPHONECXX_PUBLIC static std::shared_ptr<linphone::Buffer> newFromData(const uint8_t * data, size_t size);
			
;
			/**
			 * @brief Create a new #linphone::Buffer object from a string. 
			 *
			 * @param data The initial string content of the LinphoneBuffer. 
			 * 
			 * @return A new #linphone::Buffer object. 
			 */
			LINPHONECXX_PUBLIC static std::shared_ptr<linphone::Buffer> newFromString(const std::string & data);
			

	};

};

#endif // _LINPHONE_BUFFER_HH
