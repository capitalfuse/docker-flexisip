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

#ifndef _LINPHONE_CHAT_MESSAGE_HH
#define _LINPHONE_CHAT_MESSAGE_HH

#include <string>
#include <list>
#include <cstdint>
#include "chat_message.hh"
#include "object.hh"




struct _LinphoneChatMessage;


namespace linphone {

	class ChatRoom;
	class Content;
	class Core;
	class ErrorInfo;
	class Address;
	class ParticipantImdnState;
	class ChatMessageListener;

	/**
	 * @brief An chat message is the object that is sent and received through
	 * LinphoneChatRooms. 
	 *
	 */
	class ChatMessage: public MultiListenableObject {
	
		public:
			/**
			* LinphoneChatMessageState is used to notify if messages have been successfully
			* delivered or not. 
			*
			*/
			enum class State {
				/**
				* Initial state. 
				*/
				Idle,
				/**
				* Delivery in progress. 
				*/
				InProgress,
				/**
				* Message successfully delivered and acknowledged by the server. 
				*/
				Delivered,
				/**
				* Message was not delivered. 
				*/
				NotDelivered,
				/**
				* Message was received and acknowledged but cannot get file from server. 
				*/
				FileTransferError,
				/**
				* File transfer has been completed successfully. 
				*/
				FileTransferDone,
				/**
				* Message successfully delivered an acknowledged by the remote user. 
				*/
				DeliveredToUser,
				/**
				* Message successfully displayed to the remote user. 
				*/
				Displayed,
				/**
				* <File transfer is in progress. 
				*/
				FileTransferInProgress
			};

			/**
			* LinphoneChatMessageDirection is used to indicate if a message is outgoing or
			* incoming. 
			*
			*/
			enum class Direction {
				/**
				* Incoming message. 
				*/
				Incoming,
				/**
				* Outgoing message. 
				*/
				Outgoing
			};


			ChatMessage(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneChatMessage *cPtr() {return (_LinphoneChatMessage *)mPrivPtr;}

			LINPHONECXX_PUBLIC void addListener(const std::shared_ptr<ChatMessageListener> &listener);
			LINPHONECXX_PUBLIC void removeListener(const std::shared_ptr<ChatMessageListener> &listener);
	
		public:
			
		
			/**
			 * @brief Linphone message has an app-specific field that can store a text. 
			 *
			 * The application might want to use it for keeping data over restarts, like
			 * thumbnail image path. 
			 * 
			 * @return the application-specific data or nullptr if none has been stored. 
			 */
			LINPHONECXX_PUBLIC std::string getAppdata() const;
			
			/**
			 * @brief Linphone message has an app-specific field that can store a text. 
			 *
			 * The application might want to use it for keeping data over restarts, like
			 * thumbnail image path.
			 * 
			 * Invoking this function will attempt to update the message storage to reflect
			 * the changeif it is enabled.
			 * 
			 * @param data the data to store into the message 
			 */
			LINPHONECXX_PUBLIC void setAppdata(const std::string & data);
			
			/**
			 * @brief Returns the chatroom this message belongs to. 
			 *
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ChatRoom> getChatRoom() const;
			
			/**
			 * @brief Get the content type of a chat message. 
			 *
			 * @return The content type of the chat message 
			 */
			LINPHONECXX_PUBLIC std::string getContentType() const;
			
			/**
			 * @brief Set the content type of a chat message. 
			 *
			 * This content type must match a content that is text representable, such as
			 * text/plain, text/html or image/svg+xml. 
			 * 
			 * @param contentType The new content type of the chat message 
			 */
			LINPHONECXX_PUBLIC void setContentType(const std::string & contentType);
			
			/**
			 * @brief Returns the list of contents in the message. 
			 *
			 * @return A list of #Content objects. LinphoneContent  the list of #Content. 
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::Content>> getContents() const;
			
			/**
			 * @brief Returns back pointer to #Core object. 
			 *
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Core> getCore() const;
			
			/**
			 * @brief Get full details about delivery error of a chat message. 
			 *
			 * @return a #ErrorInfo describing the details. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::ErrorInfo> getErrorInfo() const;
			
			/**
			 * @brief Linphone message can carry external body as defined by rfc2017. 
			 *
			 * @return external body url or nullptr if not present. 
			 */
			LINPHONECXX_PUBLIC std::string getExternalBodyUrl() const;
			
			/**
			 * @brief Linphone message can carry external body as defined by rfc2017. 
			 *
			 * @param url ex: access-type=URL; URL="http://www.foo.com/file" 
			 */
			LINPHONECXX_PUBLIC void setExternalBodyUrl(const std::string & url);
			
			/**
			 * @brief Get the path to the file to read from or write to during the file
			 * transfer. 
			 *
			 * @return The path to the file to use for the file transfer. 
			 * 
			 * @deprecated use Content::getFilePath() instead. 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED std::string getFileTransferFilepath() const;
			
			/**
			 * @brief Set the path to the file to read from or write to during the file
			 * transfer. 
			 *
			 * @param filepath The path to the file to use for the file transfer. 
			 * 
			 * @deprecated use Content::setFilePath() instead. 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED void setFileTransferFilepath(const std::string & filepath);
			
			/**
			 * @brief Get the file_transfer_information (used by call backs to recover
			 * informations during a rcs file transfer) 
			 *
			 * @return a pointer to the #Content structure or nullptr if not present. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Content> getFileTransferInformation() const;
			
			/**
			 * @brief Gets the forward info if available as a string. 
			 *
			 * @return the #Content buffer if available, null otherwise 
			 */
			LINPHONECXX_PUBLIC std::string getForwardInfo() const;
			
			/**
			 * @brief Get origin of the message. 
			 *
			 * @return #Address 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::Address> getFromAddress() const;
			
			/**
			 * @brief Return whether or not a chat message is a file transfer. 
			 *
			 * @return Whether or not the message is a file transfer 
			 */
			LINPHONECXX_PUBLIC bool isFileTransfer() const;
			
			/**
			 * @brief Gets whether or not a file is currently being downloaded or uploaded. 
			 *
			 * @return true if download or upload is in progress, false otherwise 
			 */
			LINPHONECXX_PUBLIC bool isFileTransferInProgress() const;
			
			/**
			 * @brief Returns true if the chat message is a forward message. 
			 *
			 * @return true if it is a forward message, false otherwise 
			 */
			LINPHONECXX_PUBLIC bool isForward();
			
			/**
			 * @brief Returns true if the message has been sent, returns true if the message
			 * has been received. 
			 *
			 */
			LINPHONECXX_PUBLIC bool isOutgoing() const;
			
			/**
			 * @brief Returns true if the message has been read, otherwise returns true. 
			 *
			 */
			LINPHONECXX_PUBLIC bool isRead() const;
			
			/**
			 * @brief Get if the message was encrypted when transfered. 
			 *
			 * @return whether the message was encrypted when transfered or not 
			 */
			LINPHONECXX_PUBLIC bool isSecured() const;
			
			/**
			 * @brief Return whether or not a chat message is a text. 
			 *
			 * @return Whether or not the message is a text 
			 */
			LINPHONECXX_PUBLIC bool isText() const;
			
			/**
			 * @brief Returns the origin address of a message if it was a outgoing message, or
			 * the destination address if it was an incoming message. 
			 *
			 * @return #Address 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::Address> getLocalAddress() const;
			
			/**
			 * @brief Get the message identifier. 
			 *
			 * It is used to identify a message so that it can be notified as delivered and/or
			 * displayed. 
			 * 
			 * @return The message identifier. 
			 */
			LINPHONECXX_PUBLIC std::string getMessageId() const;
			
			/**
			 * @brief Get the state of the message. 
			 *
			 * @return LinphoneChatMessageState 
			 */
			LINPHONECXX_PUBLIC State getState() const;
			
			/**
			 * @brief Get text part of this message. 
			 *
			 * @return text or nullptr if no text. 
			 * 
			 * @deprecated use getTextContent() instead 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED std::string getText() const;
			
			/**
			 * @brief Gets the text content if available as a string. 
			 *
			 * @return the #Content buffer if available, null otherwise 
			 */
			LINPHONECXX_PUBLIC std::string getTextContent() const;
			
			/**
			 * @brief Get the time the message was sent. 
			 *
			 */
			LINPHONECXX_PUBLIC time_t getTime() const;
			
			/**
			 * @brief Get destination of the message. 
			 *
			 * @return #Address 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::Address> getToAddress() const;
			
			/**
			 * @brief Get if a chat message is to be stored. 
			 *
			 * @return Whether or not the message is to be stored 
			 */
			LINPHONECXX_PUBLIC bool getToBeStored() const;
			
			/**
			 * @brief Set if a chat message is to be stored. 
			 *
			 * This content type must match a content that is text representable, such as
			 * text/plain, text/html or image/svg+xml. 
			 * 
			 * @param toBeStored Whether or not the chat message is to be stored 
			 */
			LINPHONECXX_PUBLIC void setToBeStored(bool toBeStored);
			
			/**
			 * @brief Add custom headers to the message. 
			 *
			 * @param headerValue header value 
			 */
			LINPHONECXX_PUBLIC void addCustomHeader(const std::string & headerName, const std::string & headerValue);
			
			/**
			 * @brief Adds a file content to the ChatMessage. 
			 *
			 * @param cContent #Content object to add. 
			 */
			LINPHONECXX_PUBLIC void addFileContent(const std::shared_ptr<linphone::Content> & cContent);
			
			/**
			 * @brief Adds a text content to the ChatMessage. 
			 *
			 * @param text The text to add to the message. 
			 */
			LINPHONECXX_PUBLIC void addTextContent(const std::string & text);
			
			/**
			 * @brief Cancel an ongoing file transfer attached to this message. 
			 *
			 * (upload or download) 
			 */
			LINPHONECXX_PUBLIC void cancelFileTransfer();
			
			/**
			 * @brief Start the download of the #Content referenced in the
			 * #linphone::ChatMessage from remote server. 
			 *
			 * @param cContent #Content object to download. 
			 */
			LINPHONECXX_PUBLIC bool downloadContent(const std::shared_ptr<linphone::Content> & cContent);
			
			/**
			 * @brief Start the download of the file referenced in a #linphone::ChatMessage
			 * from remote server. 
			 *
			 * @deprecated Use downloadContent() instead 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED bool downloadFile();
			
			/**
			 * @brief Retrieve a custom header value given its name. 
			 *
			 * @param headerName header name searched 
			 */
			LINPHONECXX_PUBLIC std::string getCustomHeader(const std::string & headerName) const;
			
			/**
			 * @brief Gets the list of participants for which the imdn state has reached the
			 * specified state and the time at which they did. 
			 *
			 * @param state The LinphoneChatMessageState the imdn have reached (only use
			 * LinphoneChatMessageStateDelivered, LinphoneChatMessageStateDeliveredToUser,
			 * LinphoneChatMessageStateDisplayed and LinphoneChatMessageStateNotDelivered) 
			 * 
			 * @return A list of #ParticipantImdnState objects. LinphoneParticipantImdnState 
			 * The objects inside the list are freshly allocated with a reference counter
			 * equal to one, so they need to be freed on list destruction with
			 * bctbx_list_free_with_data() for instance.   
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::ParticipantImdnState>> getParticipantsByImdnState(State state) const;
			
			/**
			 * @brief Returns true if the chat message has a text content. 
			 *
			 * @return true if it has one, false otherwise 
			 */
			LINPHONECXX_PUBLIC bool hasTextContent() const;
			
			/**
			 * @brief Fulfill a chat message char by char. 
			 *
			 * Message linked to a Real Time Text Call send char in realtime following RFC
			 * 4103/T.140 To commit a message, use linphone_chat_room_send_message 
			 * 
			 * @param character T.140 char 
			 * 
			 * @return 0 if succeed. 
			 */
			LINPHONECXX_PUBLIC linphone::Status putChar(uint32_t character);
			
			/**
			 * @brief Removes a content from the ChatMessage. 
			 *
			 * @param content the #Content object to remove. 
			 */
			LINPHONECXX_PUBLIC void removeContent(const std::shared_ptr<linphone::Content> & content);
			
			/**
			 * @brief Removes a custom header from the message. 
			 *
			 * @param headerName name of the header to remove 
			 */
			LINPHONECXX_PUBLIC void removeCustomHeader(const std::string & headerName);
			
			/**
			 * @brief Resend a chat message if it is in the 'not delivered' state for whatever
			 * reason. 
			 *
			 * @note Unlike linphone_chat_message_resend, that function only takes a reference
			 * on the #linphone::ChatMessage instead of totaly takes ownership on it. Thus,
			 * the #linphone::ChatMessage object must be released by the API user after
			 * calling that function.
			 */
			LINPHONECXX_PUBLIC void resend();
			
			/**
			 * @brief Send a chat message. 
			 *
			 */
			LINPHONECXX_PUBLIC void send();
			
			
		private:
			void *createCallbacks() override;
	};

};

#endif // _LINPHONE_CHAT_MESSAGE_HH
