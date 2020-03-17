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

#ifndef _LINPHONE_VCARD_HH
#define _LINPHONE_VCARD_HH

#include <string>
#include <list>
#include "object.hh"


namespace belcard {
class BelCard;
}



struct _LinphoneVcard;


namespace linphone {

	class Address;
	class Vcard;

	/**
	 * @brief The #Vcard object. 
	 *
	 */
	class Vcard: public Object {
	
		public:

			Vcard(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneVcard *cPtr() {return (_LinphoneVcard *)mPrivPtr;}

	
		public:
			LINPHONECXX_PUBLIC std::shared_ptr<belcard::BelCard> &getVcard();
			
		
			/**
			 * @brief Gets the eTag of the vCard. 
			 *
			 * @return the eTag of the vCard in the CardDAV server, otherwise nullptr 
			 */
			LINPHONECXX_PUBLIC std::string getEtag() const;
			
			/**
			 * @brief Sets the eTAG of the vCard. 
			 *
			 * @param etag the eTAG 
			 */
			LINPHONECXX_PUBLIC void setEtag(const std::string & etag);
			
			/**
			 * @brief Returns the family name in the N attribute of the vCard, or nullptr if
			 * it isn't set yet. 
			 *
			 * @return the family name of the vCard, or nullptr 
			 */
			LINPHONECXX_PUBLIC std::string getFamilyName() const;
			
			/**
			 * @brief Sets the family name in the N attribute of the vCard. 
			 *
			 * @param name the family name to set for the vCard 
			 */
			LINPHONECXX_PUBLIC void setFamilyName(const std::string & name);
			
			/**
			 * @brief Returns the FN attribute of the vCard, or nullptr if it isn't set yet. 
			 *
			 * @return the display name of the vCard, or nullptr 
			 */
			LINPHONECXX_PUBLIC std::string getFullName() const;
			
			/**
			 * @brief Sets the FN attribute of the vCard (which is mandatory). 
			 *
			 * @param name the display name to set for the vCard 
			 */
			LINPHONECXX_PUBLIC void setFullName(const std::string & name);
			
			/**
			 * @brief Returns the given name in the N attribute of the vCard, or nullptr if it
			 * isn't set yet. 
			 *
			 * @return the given name of the vCard, or nullptr 
			 */
			LINPHONECXX_PUBLIC std::string getGivenName() const;
			
			/**
			 * @brief Sets the given name in the N attribute of the vCard. 
			 *
			 * @param name the given name to set for the vCard 
			 */
			LINPHONECXX_PUBLIC void setGivenName(const std::string & name);
			
			/**
			 * @brief Gets the Organization of the vCard. 
			 *
			 * @return the Organization of the vCard or nullptr 
			 */
			LINPHONECXX_PUBLIC std::string getOrganization() const;
			
			/**
			 * @brief Fills the Organization field of the vCard. 
			 *
			 * @param organization the Organization 
			 */
			LINPHONECXX_PUBLIC void setOrganization(const std::string & organization);
			
			/**
			 * @brief Returns the list of phone numbers (as string) in the vCard (all the TEL
			 * attributes) or nullptr. 
			 *
			 * @return A list of const char * objects. const char *  
			 */
			LINPHONECXX_PUBLIC std::list<std::string> getPhoneNumbers() const;
			
			/**
			 * @brief Returns the list of SIP addresses (as LinphoneAddress) in the vCard (all
			 * the IMPP attributes that has an URI value starting by "sip:") or nullptr. 
			 *
			 * @return A list of #Address objects. LinphoneAddress  
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::Address>> getSipAddresses();
			
			/**
			 * @brief Returns the skipFieldValidation property of the vcard. 
			 *
			 * @return the skipFieldValidation property of the vcard 
			 */
			LINPHONECXX_PUBLIC bool getSkipValidation() const;
			
			/**
			 * @brief Sets the skipFieldValidation property of the vcard. 
			 *
			 * @param skip skipFieldValidation property of the vcard 
			 */
			LINPHONECXX_PUBLIC void setSkipValidation(bool skip);
			
			/**
			 * @brief Gets the UID of the vCard. 
			 *
			 * @return the UID of the vCard, otherwise nullptr 
			 */
			LINPHONECXX_PUBLIC std::string getUid() const;
			
			/**
			 * @brief Sets the unique ID of the vCard. 
			 *
			 * @param uid the unique id 
			 */
			LINPHONECXX_PUBLIC void setUid(const std::string & uid);
			
			/**
			 * @brief Gets the URL of the vCard. 
			 *
			 * @return the URL of the vCard in the CardDAV server, otherwise nullptr 
			 */
			LINPHONECXX_PUBLIC std::string getUrl() const;
			
			/**
			 * @brief Sets the URL of the vCard. 
			 *
			 * @param url the URL 
			 */
			LINPHONECXX_PUBLIC void setUrl(const std::string & url);
			
			/**
			 * @brief Adds a phone number in the vCard, using the TEL property. 
			 *
			 * @param phone the phone number to add 
			 */
			LINPHONECXX_PUBLIC void addPhoneNumber(const std::string & phone);
			
			/**
			 * @brief Adds a SIP address in the vCard, using the IMPP property. 
			 *
			 * @param sipAddress the SIP address to add 
			 */
			LINPHONECXX_PUBLIC void addSipAddress(const std::string & sipAddress);
			
			/**
			 * @brief Returns the vCard4 representation of the LinphoneVcard. 
			 *
			 * @return a const char * that represents the vCard 
			 */
			LINPHONECXX_PUBLIC std::string asVcard4String();
			
			/**
			 * @brief Clone a #linphone::Vcard. 
			 *
			 * @return a new #linphone::Vcard object 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Vcard> clone() const;
			
			/**
			 * @brief Edits the preferred SIP address in the vCard (or the first one), using
			 * the IMPP property. 
			 *
			 * @param sipAddress the new SIP address 
			 */
			LINPHONECXX_PUBLIC void editMainSipAddress(const std::string & sipAddress);
			
			/**
			 * @brief Generates a random unique id for the vCard. 
			 *
			 * If is required to be able to synchronize the vCard with a CardDAV server 
			 * 
			 * @return  if operation is successful, otherwise true (for example if it already
			 * has an unique ID) 
			 */
			LINPHONECXX_PUBLIC bool generateUniqueId();
			
			/**
			 * @brief Removes a phone number in the vCard (if it exists), using the TEL
			 * property. 
			 *
			 * @param phone the phone number to remove 
			 */
			LINPHONECXX_PUBLIC void removePhoneNumber(const std::string & phone);
			
			/**
			 * @brief Removes a SIP address in the vCard (if it exists), using the IMPP
			 * property. 
			 *
			 * @param sipAddress the SIP address to remove 
			 */
			LINPHONECXX_PUBLIC void removeSipAddress(const std::string & sipAddress);
			
			
	};

};

#endif // _LINPHONE_VCARD_HH
