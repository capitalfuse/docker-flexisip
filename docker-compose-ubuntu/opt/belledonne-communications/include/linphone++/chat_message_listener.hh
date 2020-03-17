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

#ifndef _LINPHONE_CHAT_MESSAGE_LISTENER_HH
#define _LINPHONE_CHAT_MESSAGE_LISTENER_HH

#include "chat_message.hh"
#include "object.hh"






namespace linphone {

	class ChatMessage;
	class ParticipantImdnState;
	class Content;
	class Buffer;

	/**
	 *
	 */
	class ChatMessageListener: public Listener {
	
		public:


	
		public:
			
		
			/**
			 * @brief Call back used to notify participant IMDN state. 
			 *
			 * @param state LinphoneParticipantImdnState 
			 */
			LINPHONECXX_PUBLIC virtual void onParticipantImdnStateChanged(const std::shared_ptr<linphone::ChatMessage> & msg, const std::shared_ptr<const linphone::ParticipantImdnState> & state) {};
			
			/**
			 * @brief File transfer receive callback prototype. 
			 *
			 * This function is called by the core upon an incoming File transfer is started.
			 * This function may be call several time for the same file in case of large file. 
			 * 
			 * @param buffer LinphoneBuffer holding the received data. Empty buffer means end
			 * of file. 
			 */
			LINPHONECXX_PUBLIC virtual void onFileTransferRecv(const std::shared_ptr<linphone::ChatMessage> & msg, const std::shared_ptr<const linphone::Content> & content, const std::shared_ptr<const linphone::Buffer> & buffer) {};
			
			/**
			 * @brief File transfer send callback prototype. 
			 *
			 * This function is called by the core when an outgoing file transfer is started.
			 * This function is called until size is set to 0. 
			 * 
			 * @param size the number of bytes expected by the framework 
			 * 
			 * @return A LinphoneBuffer object holding the data written by the application. An
			 * empty buffer means end of file. 
			 */
			LINPHONECXX_PUBLIC virtual std::shared_ptr<linphone::Buffer> onFileTransferSend(const std::shared_ptr<linphone::ChatMessage> & msg, const std::shared_ptr<const linphone::Content> & content, size_t offset, size_t size) = 0;
			
			/**
			 * @brief File transfer progress indication callback prototype. 
			 *
			 * @param total The total number of bytes to be sent/received. 
			 */
			LINPHONECXX_PUBLIC virtual void onFileTransferProgressIndication(const std::shared_ptr<linphone::ChatMessage> & msg, const std::shared_ptr<const linphone::Content> & content, size_t offset, size_t total) {};
			
			/**
			 * @brief Call back used to notify message delivery status. 
			 *
			 * @param msg LinphoneChatMessage object 
			 */
			LINPHONECXX_PUBLIC virtual void onMsgStateChanged(const std::shared_ptr<linphone::ChatMessage> & msg, linphone::ChatMessage::State state) {};
			
			
	};

};

#endif // _LINPHONE_CHAT_MESSAGE_LISTENER_HH
