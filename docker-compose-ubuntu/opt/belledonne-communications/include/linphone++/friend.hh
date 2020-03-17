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

#ifndef _LINPHONE_FRIEND_HH
#define _LINPHONE_FRIEND_HH

#include <list>
#include <string>
#include "enums.hh"
#include "object.hh"




struct _LinphoneFriend;


namespace linphone {

	class Address;
	class Core;
	class PresenceModel;
	class Vcard;
	class Friend;

	/**
	 * @brief Represents a buddy, all presence actions like subscription and status
	 * change notification are performed on this object. 
	 *
	 */
	class Friend: public Object {
	
		public:

			Friend(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneFriend *cPtr() {return (_LinphoneFriend *)mPrivPtr;}

	
		public:
			
		
			/**
			 * @brief Get address of this friend. 
			 *
			 * @note the #Address object returned is hold by the LinphoneFriend, however
			 * calling several time this function may return different objects. 
			 * 
			 * @return #Address 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::Address> getAddress() const;
			
			/**
			 * @brief Set #Address for this friend. 
			 *
			 * @param address #Address 
			 */
			LINPHONECXX_PUBLIC linphone::Status setAddress(const std::shared_ptr<const linphone::Address> & address);
			
			/**
			 * @brief Returns a list of #Address for this friend. 
			 *
			 * @return A list of #Address objects. LinphoneAddress  
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::Address>> getAddresses() const;
			
			/**
			 * @brief Returns the capabilities associated to this friend. 
			 *
			 * @return an int representing the capabilities of the friend 
			 */
			LINPHONECXX_PUBLIC int getCapabilities() const;
			
			/**
			 * @brief Get the consolidated presence of a friend. 
			 *
			 * @return The consolidated presence of the friend 
			 */
			LINPHONECXX_PUBLIC linphone::ConsolidatedPresence getConsolidatedPresence() const;
			
			/**
			 * @brief Returns the #Core object managing this friend, if any. 
			 *
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Core> getCore() const;
			
			/**
			 * @brief get current subscription policy for this #linphone::Friend 
			 *
			 * @return LinphoneSubscribePolicy 
			 */
			LINPHONECXX_PUBLIC linphone::SubscribePolicy getIncSubscribePolicy() const;
			
			/**
			 * @brief Configure incoming subscription policy for this friend. 
			 *
			 * @param pol LinphoneSubscribePolicy policy to apply. 
			 */
			LINPHONECXX_PUBLIC linphone::Status setIncSubscribePolicy(linphone::SubscribePolicy pol);
			
			/**
			 * @brief Tells whether we already received presence information for a friend. 
			 *
			 * @return  if presence information has been received for the friend, true
			 * otherwise. 
			 */
			LINPHONECXX_PUBLIC bool isPresenceReceived() const;
			
			/**
			 * @brief Get the display name for this friend. 
			 *
			 * @return The display name of this friend 
			 */
			LINPHONECXX_PUBLIC std::string getName() const;
			
			/**
			 * @brief Set the display name for this friend. 
			 *
			 * @param name 
			 */
			LINPHONECXX_PUBLIC linphone::Status setName(const std::string & name);
			
			/**
			 * @brief Returns a list of phone numbers for this friend. 
			 *
			 * @return A list of const char * objects. const char *  
			 */
			LINPHONECXX_PUBLIC std::list<std::string> getPhoneNumbers() const;
			
			/**
			 * @brief Get the presence model of a friend. 
			 *
			 * @return A #PresenceModel object, or nullptr if the friend do not have presence
			 * information (in which case he is considered offline) 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::PresenceModel> getPresenceModel() const;
			
			/**
			 * @brief Set the presence model of a friend. 
			 *
			 * @param presence The #PresenceModel object to set for the friend 
			 */
			LINPHONECXX_PUBLIC void setPresenceModel(const std::shared_ptr<linphone::PresenceModel> & presence);
			
			/**
			 * @brief Get the reference key of a friend. 
			 *
			 * @return The reference key of the friend. 
			 */
			LINPHONECXX_PUBLIC std::string getRefKey() const;
			
			/**
			 * @brief Set the reference key of a friend. 
			 *
			 * @param key The reference key to use for the friend. 
			 */
			LINPHONECXX_PUBLIC void setRefKey(const std::string & key);
			
			/**
			 * @brief get subscription flag value 
			 *
			 * @return returns true is subscription is activated for this friend 
			 */
			LINPHONECXX_PUBLIC bool subscribesEnabled() const;
			
			/**
			 * @brief Configure #linphone::Friend to subscribe to presence information. 
			 *
			 * @param val if true this friend will receive subscription message 
			 */
			LINPHONECXX_PUBLIC linphone::Status enableSubscribes(bool val);
			
			/**
			 * @brief Get subscription state of a friend. 
			 *
			 * @return LinphoneSubscriptionState 
			 */
			LINPHONECXX_PUBLIC linphone::SubscriptionState getSubscriptionState() const;
			
			/**
			 * @brief Returns the vCard object associated to this friend, if any. 
			 *
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Vcard> getVcard() const;
			
			/**
			 * @brief Binds a vCard object to a friend. 
			 *
			 * @param vcard The vCard object to bind 
			 */
			LINPHONECXX_PUBLIC void setVcard(const std::shared_ptr<linphone::Vcard> & vcard);
			
			/**
			 * @brief Adds an address in this friend. 
			 *
			 * @param addr #Address object 
			 */
			LINPHONECXX_PUBLIC void addAddress(const std::shared_ptr<const linphone::Address> & addr);
			
			/**
			 * @brief Adds a phone number in this friend. 
			 *
			 * @param phone number to add 
			 */
			LINPHONECXX_PUBLIC void addPhoneNumber(const std::string & phone);
			
			/**
			 * @brief Creates a vCard object associated to this friend if there isn't one yet
			 * and if the full name is available, either by the parameter or the one in the
			 * friend's SIP URI. 
			 *
			 * @param name The full name of the friend or nullptr to use the one from the
			 * friend's SIP URI 
			 * 
			 * @return true if the vCard has been created, false if it wasn't possible (for
			 * exemple if name and the friend's SIP URI are null or if the friend's SIP URI
			 * doesn't have a display name), or if there is already one vcard 
			 */
			LINPHONECXX_PUBLIC bool createVcard(const std::string & name);
			
			/**
			 * @brief Commits modification made to the friend configuration. 
			 *
			 */
			LINPHONECXX_PUBLIC void done();
			
			/**
			 * @brief Starts editing a friend configuration. 
			 *
			 * Because friend configuration must be consistent, applications MUST call edit()
			 * before doing any attempts to modify friend configuration (such as address  or
			 * subscription policy and so on). Once the modifications are done, then the
			 * application must call done() to commit the changes. 
			 */
			LINPHONECXX_PUBLIC void edit();
			
			/**
			 * @brief Returns the version of a friend's capbility. 
			 *
			 * @param capability LinphoneFriendCapability object 
			 * 
			 * @return the version of a friend's capbility. 
			 */
			LINPHONECXX_PUBLIC float getCapabilityVersion(linphone::FriendCapability capability) const;
			
			/**
			 * @brief Get the presence model for a specific SIP URI or phone number of a
			 * friend. 
			 *
			 * @param uriOrTel The SIP URI or phone number for which to get the presence model 
			 * 
			 * @return A #PresenceModel object, or nullptr if the friend do not have presence
			 * information for this SIP URI or phone number 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::PresenceModel> getPresenceModelForUriOrTel(const std::string & uriOrTel) const;
			
			/**
			 * @brief Returns whether or not a friend has a capbility. 
			 *
			 * @param capability LinphoneFriendCapability object 
			 * 
			 * @return whether or not a friend has a capbility 
			 */
			LINPHONECXX_PUBLIC bool hasCapability(linphone::FriendCapability capability) const;
			
			/**
			 * @brief Returns whether or not a friend has a capbility with a given version. 
			 *
			 * @param version the version to test 
			 * 
			 * @return whether or not a friend has a capbility with a given version or -1.0 if
			 * friend has not capability. 
			 */
			LINPHONECXX_PUBLIC bool hasCapabilityWithVersion(linphone::FriendCapability capability, float version) const;
			
			/**
			 * @brief Returns whether or not a friend has a capbility with a given version or
			 * more. 
			 *
			 * @param version the version to test 
			 * 
			 * @return whether or not a friend has a capbility with a given version or more. 
			 */
			LINPHONECXX_PUBLIC bool hasCapabilityWithVersionOrMore(linphone::FriendCapability capability, float version) const;
			
			/**
			 * @brief Check that the given friend is in a friend list. 
			 *
			 * @return  if the friend is in a friend list, true otherwise. 
			 */
			LINPHONECXX_PUBLIC bool inList() const;
			
			/**
			 * @brief Removes a friend from it's friend list and from the rc if exists. 
			 *
			 */
			LINPHONECXX_PUBLIC void remove();
			
			/**
			 * @brief Removes an address in this friend. 
			 *
			 * @param addr #Address object 
			 */
			LINPHONECXX_PUBLIC void removeAddress(const std::shared_ptr<const linphone::Address> & addr);
			
			/**
			 * @brief Removes a phone number in this friend. 
			 *
			 * @param phone number to remove 
			 */
			LINPHONECXX_PUBLIC void removePhoneNumber(const std::string & phone);
			
			/**
			 * @brief Saves a friend either in database if configured, otherwise in
			 * linphonerc. 
			 *
			 * @param lc the linphone core 
			 */
			LINPHONECXX_PUBLIC void save(const std::shared_ptr<linphone::Core> & lc);
			
			/**
			 * @brief Set the presence model for a specific SIP URI or phone number of a
			 * friend. 
			 *
			 * @param presence The #PresenceModel object to set 
			 */
			LINPHONECXX_PUBLIC void setPresenceModelForUriOrTel(const std::string & uriOrTel, const std::shared_ptr<linphone::PresenceModel> & presence);
			
			;
			/**
			 * @brief Contructor same as linphone_friend_new + setAddress() 
			 *
			 * @param vcard a vCard object 
			 * 
			 * @return a new #linphone::Friend with vCard initialized  
			 */
			LINPHONECXX_PUBLIC static std::shared_ptr<linphone::Friend> newFromVcard(const std::shared_ptr<linphone::Vcard> & vcard);
			

	};

};

#endif // _LINPHONE_FRIEND_HH
