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

#ifndef _LINPHONE_CHAT_ROOM_HH
#define _LINPHONE_CHAT_ROOM_HH

#include <cstdint>
#include <list>
#include <string>
#include "enums.hh"
#include "chat_room.hh"
#include "object.hh"




struct _LinphoneChatRoom;


namespace linphone {

	class Call;
	class Address;
	class Core;
	class ChatRoomParams;
	class ChatMessage;
	class Participant;
	class Content;
	class EventLog;
	class ParticipantDeviceIdentity;
	class ChatRoomListener;

	/**
	 * @brief A chat room is the place where text messages are exchanged. 
	 *
	 * Can be created by Core::createChatRoom(). 
	 */
	class ChatRoom: public MultiListenableObject {
	
		public:
			/**
			* LinphoneChatRoomState is used to indicate the current state of a chat room. 
			*
			*/
			enum class State {
				/**
				* Initial state. 
				*/
				None,
				/**
				* Chat room is now instantiated on local. 
				*/
				Instantiated,
				/**
				* One creation request was sent to the server. 
				*/
				CreationPending,
				/**
				* Chat room was created on the server. 
				*/
				Created,
				/**
				* Chat room creation failed. 
				*/
				CreationFailed,
				/**
				* Wait for chat room termination. 
				*/
				TerminationPending,
				/**
				* Chat room exists on server but not in local. 
				*/
				Terminated,
				/**
				* The chat room termination failed. 
				*/
				TerminationFailed,
				/**
				* Chat room was deleted on the server. 
				*/
				Deleted
			};


			ChatRoom(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneChatRoom *cPtr() {return (_LinphoneChatRoom *)mPrivPtr;}

			LINPHONECXX_PUBLIC void addListener(const std::shared_ptr<ChatRoomListener> &listener);
			LINPHONECXX_PUBLIC void removeListener(const std::shared_ptr<ChatRoomListener> &listener);
	
		public:
			
		
			/**
			 * @brief get Curent Call associated to this chatroom if any To commit a message,
			 * use linphone_chat_room_send_message 
			 *
			 * @return #Call or nullptr. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Call> getCall() const;
			
			/**
			 * @brief Get the capabilities of a chat room. 
			 *
			 * @return The capabilities of the chat room 
			 */
			LINPHONECXX_PUBLIC unsigned int getCapabilities() const;
			
			/**
			 * @brief When realtime text is enabled
			 * linphone_call_params_realtime_text_enabled, LinphoneCoreIsComposingReceivedCb
			 * is call everytime a char is received from peer. 
			 *
			 * At the end of remote typing a regular #ChatMessage is received with committed
			 * data from LinphoneCoreMessageReceivedCb. 
			 * 
			 * @return RFC 4103/T.140 char 
			 */
			LINPHONECXX_PUBLIC uint32_t getChar() const;
			
			/**
			 * @brief Gets the list of participants that are currently composing. 
			 *
			 * @return A list of #Address objects. LinphoneAddress  list of addresses that are
			 * in the is_composing state 
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::Address>> getComposingAddresses();
			
			/**
			 * @brief Get the conference address of the chat room. 
			 *
			 * @return The conference address of the chat room or nullptr if this type of chat
			 * room is not conference based 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::Address> getConferenceAddress() const;
			
			/**
			 * @brief Set the conference address of a group chat room. 
			 *
			 * This function needs to be called from the
			 * LinphoneChatRoomCbsConferenceAddressGenerationCb callback and only there. This
			 * function is meaningful only for server implementation of chatroom, and shall
			 * not by used by client applications. 
			 * 
			 * @param confAddr The conference address to be used by the group chat room 
			 */
			LINPHONECXX_PUBLIC void setConferenceAddress(const std::shared_ptr<const linphone::Address> & confAddr);
			
			/**
			 * @brief Returns back pointer to #Core object. 
			 *
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Core> getCore() const;
			
			/**
			 * @brief Returns current parameters associated with the chat room. 
			 *
			 * This is typically the parameters passed at chat room creation to
			 * Core::createChatRoom() or some default parameters if no #ChatRoomParams was
			 * explicitely passed during chat room creation. 
			 * 
			 * @return the chat room current parameters. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::ChatRoomParams> getCurrentParams() const;
			
			/**
			 * @brief Gets the number of events in a chat room. 
			 *
			 * @return the number of events. 
			 */
			LINPHONECXX_PUBLIC int getHistoryEventsSize();
			
			/**
			 * @brief Gets the number of messages in a chat room. 
			 *
			 * @return the number of messages. 
			 */
			LINPHONECXX_PUBLIC int getHistorySize();
			
			/**
			 * @brief Returns whether or not a #linphone::ChatRoom has at least one
			 * #ChatMessage or not. 
			 *
			 * @return true if there are no #ChatMessage, false otherwise. 
			 */
			LINPHONECXX_PUBLIC bool isEmpty();
			
			/**
			 * @brief Tells whether the remote is currently composing a message. 
			 *
			 * @return  if the remote is currently composing a message, true otherwise. 
			 */
			LINPHONECXX_PUBLIC bool isRemoteComposing() const;
			
			/**
			 * @brief Gets the last chat message sent or received in this chat room. 
			 *
			 * @return the latest #ChatMessage 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ChatMessage> getLastMessageInHistory();
			
			/**
			 * @brief Return the last updated time for the chat room. 
			 *
			 * @return the last updated time 
			 */
			LINPHONECXX_PUBLIC time_t getLastUpdateTime() const;
			
			/**
			 * @brief get local address associated to  this #linphone::ChatRoom 
			 *
			 * @return #Address local address 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::Address> getLocalAddress();
			
			/**
			 * @brief Get the participant representing myself in the chat room. 
			 *
			 * @return The participant representing myself in the conference. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Participant> getMe() const;
			
			/**
			 * @brief Get the number of participants in the chat room (that is without
			 * ourselves). 
			 *
			 * @return The number of participants in the chat room 
			 */
			LINPHONECXX_PUBLIC int getNbParticipants() const;
			
			/**
			 * @brief Get the list of participants of a chat room. 
			 *
			 * @return A list of LinphoneParticipant objects. LinphoneParticipant  
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::Participant>> getParticipants() const;
			
			/**
			 * @brief get peer address associated to  this #linphone::ChatRoom 
			 *
			 * @return #Address peer address 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::Address> getPeerAddress();
			
			/**
			 * @brief Get the security level of a chat room. 
			 *
			 * @return The security level of the chat room 
			 */
			LINPHONECXX_PUBLIC linphone::ChatRoomSecurityLevel getSecurityLevel();
			
			/**
			 * @brief Get the state of the chat room. 
			 *
			 * @return The state of the chat room 
			 */
			LINPHONECXX_PUBLIC State getState() const;
			
			/**
			 * @brief Get the subject of a chat room. 
			 *
			 * @return The subject of the chat room 
			 */
			LINPHONECXX_PUBLIC std::string getSubject() const;
			
			/**
			 * @brief Set the subject of a chat room. 
			 *
			 * @param subject The new subject to set for the chat room 
			 */
			LINPHONECXX_PUBLIC void setSubject(const std::string & subject);
			
			/**
			 * @brief Gets the number of unread messages in the chatroom. 
			 *
			 * @return the number of unread messages. 
			 */
			LINPHONECXX_PUBLIC int getUnreadMessagesCount();
			
			/**
			 * @brief Add a participant to a chat room. 
			 *
			 * This may fail if this type of chat room does not handle participants. Use
			 * canHandleParticipants() to know if this chat room handles participants. 
			 * 
			 * @param addr The address of the participant to add to the chat room 
			 */
			LINPHONECXX_PUBLIC void addParticipant(const std::shared_ptr<const linphone::Address> & addr);
			
			/**
			 * @brief Add several participants to a chat room at once. 
			 *
			 * This may fail if this type of chat room does not handle participants. Use
			 * canHandleParticipants() to know if this chat room handles participants. 
			 * 
			 * @param addresses A list of #Address objects. LinphoneAddress  
			 * 
			 * @return True if everything is OK, False otherwise 
			 */
			LINPHONECXX_PUBLIC bool addParticipants(const std::list<std::shared_ptr<linphone::Address>> & addresses);
			
			/**
			 * @brief Tells whether a chat room is able to handle participants. 
			 *
			 * @return A boolean value telling whether the chat room can handle participants
			 * or not 
			 */
			LINPHONECXX_PUBLIC bool canHandleParticipants() const;
			
			/**
			 * @brief Notifies the destination of the chat message being composed that the
			 * user is typing a new message. 
			 *
			 */
			LINPHONECXX_PUBLIC void compose();
			
			/**
			 * @brief Creates an empty message attached to a dedicated chat room. 
			 *
			 * @return a new #ChatMessage 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ChatMessage> createEmptyMessage();
			
			/**
			 * @brief Creates a message attached to a dedicated chat room with a particular
			 * content. 
			 *
			 * Use linphone_chat_room_send_message to initiate the transfer 
			 * 
			 * @param initialContent #Content initial content.
			 * LinphoneCoreVTable.file_transfer_send is invoked later to notify file transfer
			 * progress and collect next chunk of the message if LinphoneContent.data is
			 * nullptr. 
			 * 
			 * @return a new #ChatMessage 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ChatMessage> createFileTransferMessage(const std::shared_ptr<linphone::Content> & initialContent);
			
			/**
			 * @brief Creates a forward message attached to a dedicated chat room with a
			 * particular message. 
			 *
			 * @param msg #ChatMessage message to be forwarded. 
			 * 
			 * @return a new #ChatMessage 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ChatMessage> createForwardMessage(const std::shared_ptr<linphone::ChatMessage> & msg);
			
			/**
			 * @brief Creates a message attached to a dedicated chat room. 
			 *
			 * @param message text message, nullptr if absent. 
			 * 
			 * @return a new #ChatMessage 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ChatMessage> createMessage(const std::string & message);
			
			/**
			 * @brief Delete all messages from the history. 
			 *
			 */
			LINPHONECXX_PUBLIC void deleteHistory();
			
			/**
			 * @brief Delete a message from the chat room history. 
			 *
			 * @param msg The #ChatMessage object to remove. 
			 */
			LINPHONECXX_PUBLIC void deleteMessage(const std::shared_ptr<linphone::ChatMessage> & msg);
			
			/**
			 * @brief Gets the chat message sent or received in this chat room that matches
			 * the message_id. 
			 *
			 * @param messageId The id of the message to find 
			 * 
			 * @return the #ChatMessage 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ChatMessage> findMessage(const std::string & messageId);
			
			/**
			 * @brief Find a participant of a chat room from its address. 
			 *
			 * @param addr The address to search in the list of participants of the chat room 
			 * 
			 * @return The participant if found, nullptr otherwise. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Participant> findParticipant(const std::shared_ptr<const linphone::Address> & addr) const;
			
			/**
			 * @brief Gets nb_message most recent messages from cr chat room, sorted from
			 * oldest to most recent. 
			 *
			 * @param nbMessage Number of message to retrieve. 0 means everything. 
			 * 
			 * @return A list of #ChatMessage objects. LinphoneChatMessage  The objects inside
			 * the list are freshly allocated with a reference counter equal to one, so they
			 * need to be freed on list destruction with bctbx_list_free_with_data() for
			 * instance.   
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::ChatMessage>> getHistory(int nbMessage);
			
			/**
			 * @brief Gets nb_events most recent events from cr chat room, sorted from oldest
			 * to most recent. 
			 *
			 * @param nbEvents Number of events to retrieve. 0 means everything. 
			 * 
			 * @return A list of #EventLog objects. LinphoneEventLog  The objects inside the
			 * list are freshly allocated with a reference counter equal to one, so they need
			 * to be freed on list destruction with bctbx_list_free_with_data() for instance. 
			 *  
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::EventLog>> getHistoryEvents(int nbEvents);
			
			/**
			 * @brief Gets nb_events most recent chat message events from cr chat room, sorted
			 * from oldest to most recent. 
			 *
			 * @param nbEvents Number of events to retrieve. 0 means everything. 
			 * 
			 * @return A list of #EventLog objects. LinphoneEventLog  The objects inside the
			 * list are freshly allocated with a reference counter equal to one, so they need
			 * to be freed on list destruction with bctbx_list_free_with_data() for instance. 
			 *  
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::EventLog>> getHistoryMessageEvents(int nbEvents);
			
			/**
			 * @brief Gets the partial list of messages in the given range, sorted from oldest
			 * to most recent. 
			 *
			 * @param end The last message of the range to be retrieved. History oldest
			 * message has index of history size - 1 (use linphone_chat_room_get_history_size
			 * to retrieve history size) 
			 * 
			 * @return A list of #ChatMessage objects. LinphoneChatMessage  The objects inside
			 * the list are freshly allocated with a reference counter equal to one, so they
			 * need to be freed on list destruction with bctbx_list_free_with_data() for
			 * instance.   
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::ChatMessage>> getHistoryRange(int begin, int end);
			
			/**
			 * @brief Gets the partial list of events in the given range, sorted from oldest
			 * to most recent. 
			 *
			 * @param end The last event of the range to be retrieved. History oldest event
			 * has index of history size - 1 
			 * 
			 * @return A list of #EventLog objects. LinphoneEventLog  The objects inside the
			 * list are freshly allocated with a reference counter equal to one, so they need
			 * to be freed on list destruction with bctbx_list_free_with_data() for instance. 
			 *  
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::EventLog>> getHistoryRangeEvents(int begin, int end);
			
			/**
			 * @brief Gets the partial list of chat message events in the given range, sorted
			 * from oldest to most recent. 
			 *
			 * @param end The last event of the range to be retrieved. History oldest event
			 * has index of history size - 1 
			 * 
			 * @return A list of #EventLog objects. LinphoneEventLog  The objects inside the
			 * list are freshly allocated with a reference counter equal to one, so they need
			 * to be freed on list destruction with bctbx_list_free_with_data() for instance. 
			 *  
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::EventLog>> getHistoryRangeMessageEvents(int begin, int end);
			
			/**
			 * @brief Return whether or not the chat room has been left. 
			 *
			 * @return whether or not the chat room has been left 
			 */
			LINPHONECXX_PUBLIC bool hasBeenLeft() const;
			
			/**
			 * @brief Check if a chat room has given capabilities. 
			 *
			 * @param mask A Capabilities mask 
			 * 
			 * @return True if the mask matches, false otherwise 
			 */
			LINPHONECXX_PUBLIC bool hasCapability(int mask) const;
			
			/**
			 * @brief Leave a chat room. 
			 *
			 */
			LINPHONECXX_PUBLIC void leave();
			
			/**
			 * @brief Returns true if lime is available for given peer. 
			 *
			 * @return true if zrtp secrets have already been shared and ready to use 
			 */
			LINPHONECXX_PUBLIC bool limeAvailable();
			
			/**
			 * @brief Mark all messages of the conversation as read. 
			 *
			 */
			LINPHONECXX_PUBLIC void markAsRead();
			
			/**
			 * @brief Notify the chatroom that a participant device has just registered. 
			 *
			 * This function is meaningful only for server implementation of chatroom, and
			 * shall not by used by client applications. 
			 */
			LINPHONECXX_PUBLIC void notifyParticipantDeviceRegistration(const std::shared_ptr<const linphone::Address> & participantDevice);
			
			/**
			 * @brief Used to receive a chat message when using async mechanism with IM
			 * encryption engine. 
			 *
			 * @param msg #ChatMessage object 
			 */
			LINPHONECXX_PUBLIC void receiveChatMessage(const std::shared_ptr<linphone::ChatMessage> & msg);
			
			/**
			 * @brief Remove a participant of a chat room. 
			 *
			 * @param participant The participant to remove from the chat room 
			 */
			LINPHONECXX_PUBLIC void removeParticipant(const std::shared_ptr<linphone::Participant> & participant);
			
			/**
			 * @brief Remove several participants of a chat room at once. 
			 *
			 * @param participants A list of LinphoneParticipant objects. LinphoneParticipant  
			 */
			LINPHONECXX_PUBLIC void removeParticipants(const std::list<std::shared_ptr<linphone::Participant>> & participants);
			
			/**
			 * @brief Send a message to peer member of this chat room. 
			 *
			 * The state of the sending message will be notified via the callbacks defined in
			 * the LinphoneChatMessageCbs object that can be obtained by calling
			 * linphone_chat_message_get_callbacks. @note Unlike
			 * linphone_chat_room_send_chat_message, that function only takes a reference on
			 * the #ChatMessage instead of totaly takes ownership on it. Thus, the
			 * #ChatMessage object must be released by the API user after calling that
			 * function.
			 * 
			 * @param msg The message to send. 
			 */
			LINPHONECXX_PUBLIC void sendChatMessage(const std::shared_ptr<linphone::ChatMessage> & msg);
			
			/**
			 * @brief Change the admin status of a participant of a chat room (you need to be
			 * an admin yourself to do this). 
			 *
			 * @param isAdmin A boolean value telling whether the participant should now be an
			 * admin or not 
			 */
			LINPHONECXX_PUBLIC void setParticipantAdminStatus(const std::shared_ptr<linphone::Participant> & participant, bool isAdmin);
			
			/**
			 * @brief Set the list of participant devices in the form of SIP URIs with GRUUs
			 * for a given participant. 
			 *
			 * This function is meaningful only for server implementation of chatroom, and
			 * shall not by used by client applications. 
			 * 
			 * @param deviceIdentities A list of LinphoneParticipantDeviceIdentity objects.
			 * LinphoneParticipantDeviceIdentity  list of the participant devices to be used
			 * by the group chat room 
			 */
			LINPHONECXX_PUBLIC void setParticipantDevices(const std::shared_ptr<const linphone::Address> & partAddr, const std::list<std::shared_ptr<linphone::ParticipantDeviceIdentity>> & deviceIdentities);
			
			
		private:
			void *createCallbacks() override;
	};

};

#endif // _LINPHONE_CHAT_ROOM_HH
