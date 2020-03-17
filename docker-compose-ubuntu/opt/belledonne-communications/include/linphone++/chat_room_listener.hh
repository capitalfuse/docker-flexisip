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

#ifndef _LINPHONE_CHAT_ROOM_LISTENER_HH
#define _LINPHONE_CHAT_ROOM_LISTENER_HH

#include "chat_room.hh"
#include "object.hh"






namespace linphone {

	class ChatRoom;
	class ChatMessage;
	class EventLog;
	class Address;

	/**
	 *
	 */
	class ChatRoomListener: public Listener {
	
		public:


	
		public:
			
		
			/**
			 * @brief Callback used to notify a chat room that a message has been received but
			 * we were unable to decrypt it. 
			 *
			 * @param msg The LinphoneChatMessage that has been received 
			 */
			LINPHONECXX_PUBLIC virtual void onUndecryptableMessageReceived(const std::shared_ptr<linphone::ChatRoom> & cr, const std::shared_ptr<linphone::ChatMessage> & msg) {};
			
			/**
			 * @brief Callback used to notify a chat room has been left. 
			 *
			 * @param cr LinphoneChatRoom object 
			 */
			LINPHONECXX_PUBLIC virtual void onConferenceLeft(const std::shared_ptr<linphone::ChatRoom> & cr, const std::shared_ptr<const linphone::EventLog> & eventLog) {};
			
			/**
			 * @brief Callback used to notify a chat room state has changed. 
			 *
			 * @param newState The new state of the chat room 
			 */
			LINPHONECXX_PUBLIC virtual void onStateChanged(const std::shared_ptr<linphone::ChatRoom> & cr, linphone::ChatRoom::State newState) {};
			
			/**
			 * @brief Callback used to notify a chat room that a participant has been added. 
			 *
			 * @param eventLog LinphoneEventLog The event to be notified 
			 */
			LINPHONECXX_PUBLIC virtual void onParticipantAdded(const std::shared_ptr<linphone::ChatRoom> & cr, const std::shared_ptr<const linphone::EventLog> & eventLog) {};
			
			/**
			 * @brief Callback used to notify that the subject of a chat room has changed. 
			 *
			 * @param eventLog LinphoneEventLog The event to be notified 
			 */
			LINPHONECXX_PUBLIC virtual void onSubjectChanged(const std::shared_ptr<linphone::ChatRoom> & cr, const std::shared_ptr<const linphone::EventLog> & eventLog) {};
			
			/**
			 * @brief Is composing notification callback prototype. 
			 *
			 * @param isComposing A boolean value telling whether the remote is composing or
			 * not 
			 */
			LINPHONECXX_PUBLIC virtual void onIsComposingReceived(const std::shared_ptr<linphone::ChatRoom> & cr, const std::shared_ptr<const linphone::Address> & remoteAddr, bool isComposing) {};
			
			/**
			 * @brief Callback used when a group chat room is created server-side to generate
			 * the address of the chat room. 
			 *
			 * The function linphone_chat_room_set_conference_address needs to be called by
			 * this callback. 
			 * 
			 * @param cr LinphoneChatRoom object 
			 */
			LINPHONECXX_PUBLIC virtual void onConferenceAddressGeneration(const std::shared_ptr<linphone::ChatRoom> & cr) {};
			
			/**
			 * @brief Callback used to notify a chat room that a chat message is being sent. 
			 *
			 * @param eventLog LinphoneEventLog The event to be notified 
			 */
			LINPHONECXX_PUBLIC virtual void onChatMessageSent(const std::shared_ptr<linphone::ChatRoom> & cr, const std::shared_ptr<const linphone::EventLog> & eventLog) {};
			
			/**
			 * @brief Callback used to notify a chat room that a chat message has been
			 * received. 
			 *
			 * @param eventLog LinphoneEventLog The event to be notified 
			 */
			LINPHONECXX_PUBLIC virtual void onChatMessageReceived(const std::shared_ptr<linphone::ChatRoom> & cr, const std::shared_ptr<const linphone::EventLog> & eventLog) {};
			
			/**
			 * @brief Callback used to tell the core whether or not to store the incoming
			 * message in db or not using linphone_chat_message_set_to_be_stored. 
			 *
			 * @param msg The LinphoneChatMessage that is being received 
			 */
			LINPHONECXX_PUBLIC virtual void onChatMessageShouldBeStored(const std::shared_ptr<linphone::ChatRoom> & cr, const std::shared_ptr<linphone::ChatMessage> & msg) {};
			
			/**
			 * @brief Callback used to notify a chat room that the admin status of a
			 * participant has been changed. 
			 *
			 * @param eventLog LinphoneEventLog The event to be notified 
			 */
			LINPHONECXX_PUBLIC virtual void onParticipantAdminStatusChanged(const std::shared_ptr<linphone::ChatRoom> & cr, const std::shared_ptr<const linphone::EventLog> & eventLog) {};
			
			/**
			 * @brief Callback used to notify a chat room that a message has been received. 
			 *
			 * @param msg The LinphoneChatMessage that has been received 
			 */
			LINPHONECXX_PUBLIC virtual void onMessageReceived(const std::shared_ptr<linphone::ChatRoom> & cr, const std::shared_ptr<linphone::ChatMessage> & msg) {};
			
			/**
			 * @brief Callback used to notify a chat room that a participant has been removed. 
			 *
			 * @param eventLog LinphoneEventLog The event to be notified 
			 */
			LINPHONECXX_PUBLIC virtual void onParticipantDeviceRemoved(const std::shared_ptr<linphone::ChatRoom> & cr, const std::shared_ptr<const linphone::EventLog> & eventLog) {};
			
			/**
			 * @brief Callback used to notify a chat room that a participant has been removed. 
			 *
			 * @param eventLog LinphoneEventLog The event to be notified 
			 */
			LINPHONECXX_PUBLIC virtual void onParticipantRemoved(const std::shared_ptr<linphone::ChatRoom> & cr, const std::shared_ptr<const linphone::EventLog> & eventLog) {};
			
			/**
			 * @brief Callback used when a group chat room server is unsubscribing to
			 * registration state of a participant. 
			 *
			 * @param participantAddr LinphoneAddress object 
			 */
			LINPHONECXX_PUBLIC virtual void onParticipantRegistrationUnsubscriptionRequested(const std::shared_ptr<linphone::ChatRoom> & cr, const std::shared_ptr<const linphone::Address> & participantAddr) {};
			
			/**
			 * @brief Callback used to notify a chat room has been joined. 
			 *
			 * @param cr LinphoneChatRoom object 
			 */
			LINPHONECXX_PUBLIC virtual void onConferenceJoined(const std::shared_ptr<linphone::ChatRoom> & cr, const std::shared_ptr<const linphone::EventLog> & eventLog) {};
			
			/**
			 * @brief Callback used to notify a security event in the chat room. 
			 *
			 * @param eventLog LinphoneEventLog The event to be notified 
			 */
			LINPHONECXX_PUBLIC virtual void onSecurityEvent(const std::shared_ptr<linphone::ChatRoom> & cr, const std::shared_ptr<const linphone::EventLog> & eventLog) {};
			
			/**
			 * @brief Callback used when a group chat room server is subscribing to
			 * registration state of a participant. 
			 *
			 * @param participantAddr LinphoneAddress object 
			 */
			LINPHONECXX_PUBLIC virtual void onParticipantRegistrationSubscriptionRequested(const std::shared_ptr<linphone::ChatRoom> & cr, const std::shared_ptr<const linphone::Address> & participantAddr) {};
			
			/**
			 * @brief Callback used to notify a chat room that a participant has been added. 
			 *
			 * @param eventLog LinphoneEventLog The event to be notified 
			 */
			LINPHONECXX_PUBLIC virtual void onParticipantDeviceAdded(const std::shared_ptr<linphone::ChatRoom> & cr, const std::shared_ptr<const linphone::EventLog> & eventLog) {};
			
			
	};

};

#endif // _LINPHONE_CHAT_ROOM_LISTENER_HH
