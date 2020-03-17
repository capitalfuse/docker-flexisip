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

#ifndef _LINPHONE_CHAT_ROOM_PARAMS_HH
#define _LINPHONE_CHAT_ROOM_PARAMS_HH

#include "enums.hh"
#include "object.hh"




struct _LinphoneChatRoomParams;


namespace linphone {


	/**
	 * @brief An object to handle a chat room parameters. 
	 *
	 * Can be created with linphone_core_get_default_chat_room_params() or
	 * linphone_chat_room_params_new. 
	 */
	class ChatRoomParams: public Object {
	
		public:

			ChatRoomParams(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneChatRoomParams *cPtr() {return (_LinphoneChatRoomParams *)mPrivPtr;}

	
		public:
			
		
			/**
			 * @brief Get the backend implementation of the chat room associated with the
			 * given parameters. 
			 *
			 * @return LinphoneChatRoomBackend 
			 */
			LINPHONECXX_PUBLIC linphone::ChatRoomBackend getBackend() const;
			
			/**
			 * @brief Set the backend implementation of these chat room parameters. 
			 *
			 * @param backend The LinphoneChatRoomBackend enum value 
			 */
			LINPHONECXX_PUBLIC void setBackend(linphone::ChatRoomBackend backend);
			
			/**
			 * @brief Get the encryption implementation of the chat room associated with the
			 * given parameters. 
			 *
			 * @return LinphoneChatRoomEncryptionBackend 
			 */
			LINPHONECXX_PUBLIC linphone::ChatRoomEncryptionBackend getEncryptionBackend() const;
			
			/**
			 * @brief Set the encryption backend implementation of these chat room parameters. 
			 *
			 * @param backend The LinphoneChatRoomEncryptionBackend enum value 
			 */
			LINPHONECXX_PUBLIC void setEncryptionBackend(linphone::ChatRoomEncryptionBackend backend);
			
			/**
			 * @brief Get the encryption status of the chat room associated with the given
			 * parameters. 
			 *
			 * @return  if encryption is enabled, true otherwise 
			 */
			LINPHONECXX_PUBLIC bool encryptionEnabled() const;
			
			/**
			 * @brief Enables or disables encryption for the chat room associated with the
			 * given parameters. 
			 *
			 */
			LINPHONECXX_PUBLIC void enableEncryption(bool encrypted);
			
			/**
			 * @brief Get the group chat status of the chat room associated with the given
			 * parameters. 
			 *
			 * @return  if group chat is enabled, true if one-to-one 
			 */
			LINPHONECXX_PUBLIC bool groupEnabled() const;
			
			/**
			 * @brief Enables or disables group chat for the chat room associated with the
			 * given parameters. 
			 *
			 */
			LINPHONECXX_PUBLIC void enableGroup(bool group);
			
			/**
			 *
			 * @return  if the given parameters are valid, true otherwise 
			 */
			LINPHONECXX_PUBLIC bool isValid() const;
			
			/**
			 * @brief Get the real time text status of the chat room associated with the given
			 * parameters. 
			 *
			 * @return  if real time text is enabled, true otherwise 
			 */
			LINPHONECXX_PUBLIC bool rttEnabled() const;
			
			/**
			 * @brief Enables or disables real time text for the chat room associated with the
			 * given parameters. 
			 *
			 */
			LINPHONECXX_PUBLIC void enableRtt(bool rtt);
			
			
	};

};

#endif // _LINPHONE_CHAT_ROOM_PARAMS_HH
