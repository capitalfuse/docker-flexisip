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

#ifndef _LINPHONE_PRESENCE_PERSON_HH
#define _LINPHONE_PRESENCE_PERSON_HH

#include <string>
#include "object.hh"




struct _LinphonePresencePerson;


namespace linphone {

	class PresenceNote;
	class PresenceActivity;

	/**
	 * @brief Presence person holding information about a presence person. 
	 *
	 */
	class PresencePerson: public Object {
	
		public:

			PresencePerson(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphonePresencePerson *cPtr() {return (_LinphonePresencePerson *)mPrivPtr;}

	
		public:
			
		
			/**
			 * @brief Gets the id of a presence person. 
			 *
			 * @return A pointer to a dynamically allocated string containing the id, or
			 * nullptr in case of error.
			 * 
			 * The returned string is to be freed by calling ms_free(). 
			 */
			LINPHONECXX_PUBLIC std::string getId() const;
			
			/**
			 * @brief Sets the id of a presence person. 
			 *
			 * @param id The id string to set. Can be nullptr to generate it automatically. 
			 * 
			 * @return 0 if successful, a value < 0 in case of error. 
			 */
			LINPHONECXX_PUBLIC linphone::Status setId(const std::string & id);
			
			/**
			 * @brief Gets the number of activities included in the presence person. 
			 *
			 * @return The number of activities included in the #linphone::PresencePerson
			 * object. 
			 */
			LINPHONECXX_PUBLIC unsigned int getNbActivities() const;
			
			/**
			 * @brief Gets the number of activities notes included in the presence person. 
			 *
			 * @return The number of activities notes included in the
			 * #linphone::PresencePerson object. 
			 */
			LINPHONECXX_PUBLIC unsigned int getNbActivitiesNotes() const;
			
			/**
			 * @brief Gets the number of notes included in the presence person. 
			 *
			 * @return The number of notes included in the #linphone::PresencePerson object. 
			 */
			LINPHONECXX_PUBLIC unsigned int getNbNotes() const;
			
			/**
			 * @brief Adds an activities note to a presence person. 
			 *
			 * @param note The #PresenceNote object to add to the person. 
			 * 
			 * @return 0 if successful, a value < 0 in case of error. 
			 */
			LINPHONECXX_PUBLIC linphone::Status addActivitiesNote(const std::shared_ptr<linphone::PresenceNote> & note);
			
			/**
			 * @brief Adds an activity to a presence person. 
			 *
			 * @param activity The #PresenceActivity object to add to the person. 
			 * 
			 * @return 0 if successful, a value < 0 in case of error. 
			 */
			LINPHONECXX_PUBLIC linphone::Status addActivity(const std::shared_ptr<linphone::PresenceActivity> & activity);
			
			/**
			 * @brief Adds a note to a presence person. 
			 *
			 * @param note The #PresenceNote object to add to the person. 
			 * 
			 * @return 0 if successful, a value < 0 in case of error. 
			 */
			LINPHONECXX_PUBLIC linphone::Status addNote(const std::shared_ptr<linphone::PresenceNote> & note);
			
			/**
			 * @brief Clears the activities of a presence person. 
			 *
			 * @return 0 if successful, a value < 0 in case of error. 
			 */
			LINPHONECXX_PUBLIC linphone::Status clearActivities();
			
			/**
			 * @brief Clears the activities notes of a presence person. 
			 *
			 * @return 0 if successful, a value < 0 in case of error. 
			 */
			LINPHONECXX_PUBLIC linphone::Status clearActivitiesNotes();
			
			/**
			 * @brief Clears the notes of a presence person. 
			 *
			 * @return 0 if successful, a value < 0 in case of error. 
			 */
			LINPHONECXX_PUBLIC linphone::Status clearNotes();
			
			/**
			 * @brief Gets the nth activities note of a presence person. 
			 *
			 * @param idx The index of the activities note to get (the first note having the
			 * index 0). 
			 * 
			 * @return A pointer to a #PresenceNote object if successful, nullptr otherwise. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::PresenceNote> getNthActivitiesNote(unsigned int idx) const;
			
			/**
			 * @brief Gets the nth activity of a presence person. 
			 *
			 * @param idx The index of the activity to get (the first activity having the
			 * index 0). 
			 * 
			 * @return A pointer to a #PresenceActivity object if successful, nullptr
			 * otherwise. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::PresenceActivity> getNthActivity(unsigned int idx) const;
			
			/**
			 * @brief Gets the nth note of a presence person. 
			 *
			 * @param idx The index of the note to get (the first note having the index 0). 
			 * 
			 * @return A pointer to a #PresenceNote object if successful, nullptr otherwise. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::PresenceNote> getNthNote(unsigned int idx) const;
			
			
	};

};

#endif // _LINPHONE_PRESENCE_PERSON_HH
