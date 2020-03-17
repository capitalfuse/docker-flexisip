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

#ifndef _LINPHONE_CONTENT_HH
#define _LINPHONE_CONTENT_HH

#include <cstdint>
#include <string>
#include <list>
#include "object.hh"




struct _LinphoneContent;


namespace linphone {

	class Content;

	/**
	 * @brief The LinphoneContent object holds data that can be embedded in a
	 * signaling message. 
	 *
	 */
	class Content: public Object {
	
		public:

			Content(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneContent *cPtr() {return (_LinphoneContent *)mPrivPtr;}

	
		public:
			
		
			/**
			 * @brief Get the content data buffer, usually a string. 
			 *
			 * @return The content data buffer. 
			 */
			LINPHONECXX_PUBLIC const uint8_t * getBuffer() const;
			
			/**
			 * @brief Get the encoding of the data buffer, for example "gzip". 
			 *
			 * @return The encoding of the data buffer. 
			 */
			LINPHONECXX_PUBLIC std::string getEncoding() const;
			
			/**
			 * @brief Set the encoding of the data buffer, for example "gzip". 
			 *
			 * @param encoding The encoding of the data buffer. 
			 */
			LINPHONECXX_PUBLIC void setEncoding(const std::string & encoding);
			
			/**
			 * @brief Get the file transfer filepath set for this content (replace
			 * linphone_chat_message_get_file_transfer_filepath). 
			 *
			 * @return The file path set for this content if it has been set, nullptr
			 * otherwise. 
			 */
			LINPHONECXX_PUBLIC std::string getFilePath() const;
			
			/**
			 * @brief Set the file transfer filepath for this content (replace
			 * linphone_chat_message_set_file_transfer_filepath). 
			 *
			 * @param filePath the file transfer filepath. 
			 */
			LINPHONECXX_PUBLIC void setFilePath(const std::string & filePath);
			
			/**
			 * @brief Get the file size if content is either a FileContent or a
			 * FileTransferContent. 
			 *
			 * @return The represented file size. 
			 */
			LINPHONECXX_PUBLIC size_t getFileSize() const;
			
			/**
			 * @brief Tells whether or not this content contains a file. 
			 *
			 * @return True if this content contains a file, false otherwise. 
			 */
			LINPHONECXX_PUBLIC bool isFile() const;
			
			/**
			 * @brief Tells whether or not this content is a file transfer. 
			 *
			 * @return True if this content is a file transfer, false otherwise. 
			 */
			LINPHONECXX_PUBLIC bool isFileTransfer() const;
			
			/**
			 * @brief Tell whether a content is a multipart content. 
			 *
			 * @return A boolean value telling whether the content is multipart or not. 
			 */
			LINPHONECXX_PUBLIC bool isMultipart() const;
			
			/**
			 * @brief Tells whether or not this content contains text. 
			 *
			 * @return True if this content contains plain text, false otherwise. 
			 */
			LINPHONECXX_PUBLIC bool isText() const;
			
			/**
			 * @brief Get the key associated with a RCS file transfer message if encrypted. 
			 *
			 * @return The key to encrypt/decrypt the file associated to this content. 
			 */
			LINPHONECXX_PUBLIC std::string getKey() const;
			
			/**
			 * @brief Get the size of key associated with a RCS file transfer message if
			 * encrypted. 
			 *
			 * @return The key size in bytes 
			 */
			LINPHONECXX_PUBLIC size_t getKeySize() const;
			
			/**
			 * @brief Get the name associated with a RCS file transfer message. 
			 *
			 * It is used to store the original filename of the file to be downloaded from
			 * server. 
			 * 
			 * @return The name of the content. 
			 */
			LINPHONECXX_PUBLIC std::string getName() const;
			
			/**
			 * @brief Set the name associated with a RCS file transfer message. 
			 *
			 * It is used to store the original filename of the file to be downloaded from
			 * server. 
			 * 
			 * @param name The name of the content. 
			 */
			LINPHONECXX_PUBLIC void setName(const std::string & name);
			
			/**
			 * @brief Get all the parts from a multipart content. 
			 *
			 * @return A A list of #linphone::Content objects. LinphoneContent  The objects
			 * inside the list are freshly allocated with a reference counter equal to one, so
			 * they need to be freed on list destruction with bctbx_list_free_with_data() for
			 * instance.   object holding the part if found, nullptr otherwise. 
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::Content>> getParts() const;
			
			/**
			 * @brief Get the content data buffer size, excluding null character despite null
			 * character is always set for convenience. 
			 *
			 * @return The content data buffer size. 
			 */
			LINPHONECXX_PUBLIC size_t getSize() const;
			
			/**
			 * @brief Set the content data size, excluding null character despite null
			 * character is always set for convenience. 
			 *
			 * @param size The content data buffer size. 
			 */
			LINPHONECXX_PUBLIC void setSize(size_t size);
			
			/**
			 * @brief Get the string content data buffer. 
			 *
			 * @return The string content data buffer. 
			 */
			LINPHONECXX_PUBLIC std::string getStringBuffer() const;
			
			/**
			 * @brief Set the string content data buffer. 
			 *
			 * @param buffer The string content data buffer. 
			 */
			LINPHONECXX_PUBLIC void setStringBuffer(const std::string & buffer);
			
			/**
			 * @brief Get the mime subtype of the content data. 
			 *
			 * @return The mime subtype of the content data, for example "html". 
			 */
			LINPHONECXX_PUBLIC std::string getSubtype() const;
			
			/**
			 * @brief Set the mime subtype of the content data. 
			 *
			 * @param subtype The mime subtype of the content data, for example "html". 
			 */
			LINPHONECXX_PUBLIC void setSubtype(const std::string & subtype);
			
			/**
			 * @brief Get the mime type of the content data. 
			 *
			 * @return The mime type of the content data, for example "application". 
			 */
			LINPHONECXX_PUBLIC std::string getType() const;
			
			/**
			 * @brief Set the mime type of the content data. 
			 *
			 * @param type The mime type of the content data, for example "application". 
			 */
			LINPHONECXX_PUBLIC void setType(const std::string & type);
			
			/**
			 * @brief Adds a parameter to the ContentType header. 
			 *
			 * @param value the value of the parameter to add. 
			 */
			LINPHONECXX_PUBLIC void addContentTypeParameter(const std::string & name, const std::string & value);
			
			/**
			 * @brief Find a part from a multipart content looking for a part header with a
			 * specified value. 
			 *
			 * @param headerValue The value of the header to look for. 
			 * 
			 * @return A #linphone::Content object object the part if found, nullptr
			 * otherwise. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Content> findPartByHeader(const std::string & headerName, const std::string & headerValue) const;
			
			/**
			 * @brief Get a custom header value of a content. 
			 *
			 * @param headerName The name of the header to get the value from. 
			 * 
			 * @return The value of the header if found, nullptr otherwise. 
			 */
			LINPHONECXX_PUBLIC std::string getCustomHeader(const std::string & headerName) const;
			
			/**
			 * @brief Get a part from a multipart content according to its index. 
			 *
			 * @param idx The index of the part to get. 
			 * 
			 * @return A #linphone::Content object holding the part if found, nullptr
			 * otherwise. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Content> getPart(int idx) const;
			
			/**
			 * @brief Set the content data buffer, usually a string. 
			 *
			 * @param size The size of the content data buffer. 
			 */
			LINPHONECXX_PUBLIC void setBuffer(const uint8_t * buffer, size_t size);
			
			/**
			 * @brief Set the key associated with a RCS file transfer message if encrypted. 
			 *
			 * @param keyLength The lengh of the key. 
			 */
			LINPHONECXX_PUBLIC void setKey(const std::string & key, const size_t keyLength);
			
			
	};

};

#endif // _LINPHONE_CONTENT_HH
