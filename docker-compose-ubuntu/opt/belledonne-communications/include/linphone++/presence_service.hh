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

#ifndef _LINPHONE_PRESENCE_SERVICE_HH
#define _LINPHONE_PRESENCE_SERVICE_HH

#include <string>
#include <list>
#include "enums.hh"
#include "object.hh"




struct _LinphonePresenceService;


namespace linphone {

	class PresenceNote;

	/**
	 * @brief Presence service type holding information about a presence service. 
	 *
	 */
	class PresenceService: public Object {
	
		public:

			PresenceService(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphonePresenceService *cPtr() {return (_LinphonePresenceService *)mPrivPtr;}

	
		public:
			
		
			/**
			 * @brief Gets the basic status of a presence service. 
			 *
			 * @return The LinphonePresenceBasicStatus of the #linphone::PresenceService
			 * object given as parameter. 
			 */
			LINPHONECXX_PUBLIC linphone::PresenceBasicStatus getBasicStatus() const;
			
			/**
			 * @brief Sets the basic status of a presence service. 
			 *
			 * @param basicStatus The LinphonePresenceBasicStatus to set for the
			 * #linphone::PresenceService object. 
			 * 
			 * @return 0 if successful, a value < 0 in case of error. 
			 */
			LINPHONECXX_PUBLIC linphone::Status setBasicStatus(linphone::PresenceBasicStatus basicStatus);
			
			/**
			 * @brief Gets the contact of a presence service. 
			 *
			 * @return A pointer to a dynamically allocated string containing the contact, or
			 * nullptr if no contact is found.
			 * 
			 * The returned string is to be freed by calling ms_free(). 
			 */
			LINPHONECXX_PUBLIC std::string getContact() const;
			
			/**
			 * @brief Sets the contact of a presence service. 
			 *
			 * @param contact The contact string to set. 
			 * 
			 * @return 0 if successful, a value < 0 in case of error. 
			 */
			LINPHONECXX_PUBLIC linphone::Status setContact(const std::string & contact);
			
			/**
			 * @brief Gets the id of a presence service. 
			 *
			 * @return A pointer to a dynamically allocated string containing the id, or
			 * nullptr in case of error.
			 * 
			 * The returned string is to be freed by calling ms_free(). 
			 */
			LINPHONECXX_PUBLIC std::string getId() const;
			
			/**
			 * @brief Sets the id of a presence service. 
			 *
			 * @param id The id string to set. Can be nullptr to generate it automatically. 
			 * 
			 * @return 0 if successful, a value < 0 in case of error. 
			 */
			LINPHONECXX_PUBLIC linphone::Status setId(const std::string & id);
			
			/**
			 * @brief Gets the number of notes included in the presence service. 
			 *
			 * @return The number of notes included in the #linphone::PresenceService object. 
			 */
			LINPHONECXX_PUBLIC unsigned int getNbNotes() const;
			
			/**
			 * @brief Gets the service descriptions of a presence service. 
			 *
			 * @return A A list of char * objects. char *  containing the services
			 * descriptions.
			 * 
			 * The returned string is to be freed. 
			 */
			LINPHONECXX_PUBLIC std::list<std::string> getServiceDescriptions() const;
			
			/**
			 * @brief Sets the service descriptions of a presence service. 
			 *
			 * @param descriptions A list of char * objects. char *  The service descriptions. 
			 * 
			 * @return 0 if successful, a value < 0 in case of error. 
			 */
			LINPHONECXX_PUBLIC linphone::Status setServiceDescriptions(const std::list<std::string> & descriptions);
			
			/**
			 * @brief Adds a note to a presence service. 
			 *
			 * @param note The #PresenceNote object to add to the service. 
			 * 
			 * @return 0 if successful, a value < 0 in case of error. 
			 */
			LINPHONECXX_PUBLIC linphone::Status addNote(const std::shared_ptr<linphone::PresenceNote> & note);
			
			/**
			 * @brief Clears the notes of a presence service. 
			 *
			 * @return 0 if successful, a value < 0 in case of error. 
			 */
			LINPHONECXX_PUBLIC linphone::Status clearNotes();
			
			/**
			 * @brief Gets the nth note of a presence service. 
			 *
			 * @param idx The index of the note to get (the first note having the index 0). 
			 * 
			 * @return A pointer to a #PresenceNote object if successful, nullptr otherwise. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::PresenceNote> getNthNote(unsigned int idx) const;
			
			
	};

};

#endif // _LINPHONE_PRESENCE_SERVICE_HH
