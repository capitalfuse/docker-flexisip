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

#ifndef _LINPHONE_FRIEND_LIST_LISTENER_HH
#define _LINPHONE_FRIEND_LIST_LISTENER_HH

#include <list>
#include <string>
#include "friend_list.hh"
#include "object.hh"






namespace linphone {

	class FriendList;
	class Friend;

	/**
	 *
	 */
	class FriendListListener: public Listener {
	
		public:


	
		public:
			
		
			/**
			 * @brief Callback used to notify a contact has been updated on the CardDAV
			 * server. 
			 *
			 * @param oldFriend The old LinphoneFriend object before update 
			 */
			LINPHONECXX_PUBLIC virtual void onContactUpdated(const std::shared_ptr<linphone::FriendList> & list, const std::shared_ptr<linphone::Friend> & newFriend, const std::shared_ptr<linphone::Friend> & oldFriend) {};
			
			/**
			 * @brief Callback used to notify a list with all friends that have received
			 * presence information. 
			 *
			 * @param friends A A list of LinphoneFriend objects. LinphoneFriend  of the
			 * relevant friends 
			 */
			LINPHONECXX_PUBLIC virtual void onPresenceReceived(const std::shared_ptr<linphone::FriendList> & list, const std::list<std::shared_ptr<linphone::Friend>> & friends) {};
			
			/**
			 * @brief Callback used to notify the status of the synchronization has changed. 
			 *
			 * @param msg An additional information on the status update 
			 */
			LINPHONECXX_PUBLIC virtual void onSyncStatusChanged(const std::shared_ptr<linphone::FriendList> & list, linphone::FriendList::SyncStatus status, const std::string & msg) {};
			
			/**
			 * @brief Callback used to notify a new contact has been created on the CardDAV
			 * server and downloaded locally. 
			 *
			 * @param lf The LinphoneFriend object that has been created 
			 */
			LINPHONECXX_PUBLIC virtual void onContactCreated(const std::shared_ptr<linphone::FriendList> & list, const std::shared_ptr<linphone::Friend> & lf) {};
			
			/**
			 * @brief Callback used to notify a contact has been deleted on the CardDAV
			 * server. 
			 *
			 * @param lf The LinphoneFriend object that has been deleted 
			 */
			LINPHONECXX_PUBLIC virtual void onContactDeleted(const std::shared_ptr<linphone::FriendList> & list, const std::shared_ptr<linphone::Friend> & lf) {};
			
			
	};

};

#endif // _LINPHONE_FRIEND_LIST_LISTENER_HH
