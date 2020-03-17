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

#ifndef _LINPHONE_PRESENCE_MODEL_HH
#define _LINPHONE_PRESENCE_MODEL_HH

#include <string>
#include "enums.hh"
#include "presence_activity.hh"
#include "object.hh"




struct _LinphonePresenceModel;


namespace linphone {

	class PresenceActivity;
	class Address;
	class PresenceModel;
	class PresencePerson;
	class PresenceService;
	class PresenceNote;

	/**
	 * @brief Presence model type holding information about the presence of a person. 
	 *
	 */
	class PresenceModel: public Object {
	
		public:

			PresenceModel(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphonePresenceModel *cPtr() {return (_LinphonePresenceModel *)mPrivPtr;}

	
		public:
			
		
			/**
			 * @brief Gets the first activity of a presence model (there is usually only one). 
			 *
			 * @return A #PresenceActivity object if successful, nullptr otherwise. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::PresenceActivity> getActivity() const;
			
			/**
			 * @brief Gets the basic status of a presence model. 
			 *
			 * @return The LinphonePresenceBasicStatus of the #linphone::PresenceModel object
			 * given as parameter. 
			 */
			LINPHONECXX_PUBLIC linphone::PresenceBasicStatus getBasicStatus() const;
			
			/**
			 * @brief Sets the basic status of a presence model. 
			 *
			 * @param basicStatus The LinphonePresenceBasicStatus to set for the
			 * #linphone::PresenceModel object. 
			 * 
			 * @return 0 if successful, a value < 0 in case of error. 
			 */
			LINPHONECXX_PUBLIC linphone::Status setBasicStatus(linphone::PresenceBasicStatus basicStatus);
			
			/**
			 * @brief Gets the capabilities of a #linphone::PresenceModel object. 
			 *
			 * @return the capabilities. 
			 */
			LINPHONECXX_PUBLIC int getCapabilities() const;
			
			/**
			 * @brief Get the consolidated presence from a presence model. 
			 *
			 * @return The LinphoneConsolidatedPresence corresponding to the presence model 
			 */
			LINPHONECXX_PUBLIC linphone::ConsolidatedPresence getConsolidatedPresence() const;
			
			/**
			 * @brief Gets the contact of a presence model. 
			 *
			 * @return A pointer to a dynamically allocated string containing the contact, or
			 * nullptr if no contact is found.
			 * 
			 * The returned string is to be freed by calling ms_free(). 
			 */
			LINPHONECXX_PUBLIC std::string getContact() const;
			
			/**
			 * @brief Sets the contact of a presence model. 
			 *
			 * @param contact The contact string to set. 
			 * 
			 * @return 0 if successful, a value < 0 in case of error. 
			 */
			LINPHONECXX_PUBLIC linphone::Status setContact(const std::string & contact);
			
			/**
			 * @brief Tells whether a presence model is considered online. 
			 *
			 * It is any of theses cases:
			 * 
			 */
			LINPHONECXX_PUBLIC bool isOnline() const;
			
			/**
			 * @brief Gets the number of activities included in the presence model. 
			 *
			 * @return The number of activities included in the #linphone::PresenceModel
			 * object. 
			 */
			LINPHONECXX_PUBLIC unsigned int getNbActivities() const;
			
			/**
			 * @brief Gets the number of persons included in the presence model. 
			 *
			 * @return The number of persons included in the #linphone::PresenceModel object. 
			 */
			LINPHONECXX_PUBLIC unsigned int getNbPersons() const;
			
			/**
			 * @brief Gets the number of services included in the presence model. 
			 *
			 * @return The number of services included in the #linphone::PresenceModel object. 
			 */
			LINPHONECXX_PUBLIC unsigned int getNbServices() const;
			
			/**
			 * @brief Gets the presentity of a presence model. 
			 *
			 * @return A pointer to a const LinphoneAddress, or nullptr if no contact is
			 * found. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::Address> getPresentity() const;
			
			/**
			 * @brief Sets the presentity of a presence model. 
			 *
			 * @param presentity The presentity address to set (presentity is copied). 
			 * 
			 * @return 0 if successful, a value < 0 in case of error. 
			 */
			LINPHONECXX_PUBLIC linphone::Status setPresentity(const std::shared_ptr<const linphone::Address> & presentity);
			
			/**
			 * @brief Gets the timestamp of a presence model. 
			 *
			 * @return The timestamp of the #linphone::PresenceModel object or -1 on error. 
			 */
			LINPHONECXX_PUBLIC time_t getTimestamp() const;
			
			/**
			 * @brief Adds an activity to a presence model. 
			 *
			 * @param activity The #PresenceActivity object to add to the model. 
			 * 
			 * @return 0 if successful, a value < 0 in case of error. 
			 */
			LINPHONECXX_PUBLIC linphone::Status addActivity(const std::shared_ptr<linphone::PresenceActivity> & activity);
			
			/**
			 * @brief Adds a note to a presence model. 
			 *
			 * @param lang The language of the note to be added. Can be nullptr if no language
			 * is to be specified for the note. 
			 * 
			 * @return 0 if successful, a value < 0 in case of error.
			 * 
			 * Only one note for each language can be set, so e.g. setting a note for the 'fr'
			 * language if there is only one will replace the existing one. 
			 */
			LINPHONECXX_PUBLIC linphone::Status addNote(const std::string & noteContent, const std::string & lang);
			
			/**
			 * @brief Adds a person to a presence model. 
			 *
			 * @param person The #PresencePerson object to add to the model. 
			 * 
			 * @return 0 if successful, a value < 0 in case of error. 
			 */
			LINPHONECXX_PUBLIC linphone::Status addPerson(const std::shared_ptr<linphone::PresencePerson> & person);
			
			/**
			 * @brief Adds a service to a presence model. 
			 *
			 * @param service The #PresenceService object to add to the model. 
			 * 
			 * @return 0 if successful, a value < 0 in case of error. 
			 */
			LINPHONECXX_PUBLIC linphone::Status addService(const std::shared_ptr<linphone::PresenceService> & service);
			
			/**
			 * @brief Clears the activities of a presence model. 
			 *
			 * @return 0 if successful, a value < 0 in case of error. 
			 */
			LINPHONECXX_PUBLIC linphone::Status clearActivities();
			
			/**
			 * @brief Clears all the notes of a presence model. 
			 *
			 * @return 0 if successful, a value < 0 in case of error. 
			 */
			LINPHONECXX_PUBLIC linphone::Status clearNotes();
			
			/**
			 * @brief Clears the persons of a presence model. 
			 *
			 * @return 0 if successful, a value < 0 in case of error. 
			 */
			LINPHONECXX_PUBLIC linphone::Status clearPersons();
			
			/**
			 * @brief Clears the services of a presence model. 
			 *
			 * @return 0 if successful, a value < 0 in case of error. 
			 */
			LINPHONECXX_PUBLIC linphone::Status clearServices();
			
			/**
			 * @brief Returns the version of the capability of a #linphone::PresenceModel. 
			 *
			 * @param capability The capability to test. 
			 * 
			 * @return the version of the capability of a #linphone::PresenceModel or -1.0 if
			 * the model has not the capability. 
			 */
			LINPHONECXX_PUBLIC float getCapabilityVersion(linphone::FriendCapability capability) const;
			
			/**
			 * @brief Gets the first note of a presence model (there is usually only one). 
			 *
			 * @param lang The language of the note to get. Can be nullptr to get a note that
			 * has no language specified or to get the first note whatever language it is
			 * written into. 
			 * 
			 * @return A pointer to a #PresenceNote object if successful, nullptr otherwise. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::PresenceNote> getNote(const std::string & lang) const;
			
			/**
			 * @brief Gets the nth activity of a presence model. 
			 *
			 * @param idx The index of the activity to get (the first activity having the
			 * index 0). 
			 * 
			 * @return A pointer to a #PresenceActivity object if successful, nullptr
			 * otherwise. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::PresenceActivity> getNthActivity(unsigned int idx) const;
			
			/**
			 * @brief Gets the nth person of a presence model. 
			 *
			 * @param idx The index of the person to get (the first person having the index
			 * 0). 
			 * 
			 * @return A pointer to a #PresencePerson object if successful, nullptr otherwise. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::PresencePerson> getNthPerson(unsigned int idx) const;
			
			/**
			 * @brief Gets the nth service of a presence model. 
			 *
			 * @param idx The index of the service to get (the first service having the index
			 * 0). 
			 * 
			 * @return A pointer to a #PresenceService object if successful, nullptr
			 * otherwise. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::PresenceService> getNthService(unsigned int idx) const;
			
			/**
			 * @brief Returns whether or not the #linphone::PresenceModel object has a given
			 * capability. 
			 *
			 * @param capability The capability to test. 
			 * 
			 * @return whether or not the #linphone::PresenceModel object has a given
			 * capability. 
			 */
			LINPHONECXX_PUBLIC bool hasCapability(linphone::FriendCapability capability) const;
			
			/**
			 * @brief Returns whether or not the #linphone::PresenceModel object has a given
			 * capability with a certain version. 
			 *
			 * @param version The wanted version to test. 
			 * 
			 * @return whether or not the #linphone::PresenceModel object has a given
			 * capability with a certain version. 
			 */
			LINPHONECXX_PUBLIC bool hasCapabilityWithVersion(linphone::FriendCapability capability, float version) const;
			
			/**
			 * @brief Returns whether or not the #linphone::PresenceModel object has a given
			 * capability with a certain version or more. 
			 *
			 * @param version The wanted version to test. 
			 * 
			 * @return whether or not the #linphone::PresenceModel object has a given
			 * capability with a certain version or more. 
			 */
			LINPHONECXX_PUBLIC bool hasCapabilityWithVersionOrMore(linphone::FriendCapability capability, float version) const;
			
			/**
			 * @brief Sets the activity of a presence model (limits to only one activity). 
			 *
			 * @param description An additional description of the activity to set for the
			 * model. Can be nullptr if no additional description is to be added. 
			 * 
			 * @return 0 if successful, a value < 0 in case of error.
			 * 
			 * WARNING: This function will modify the basic status of the model according to
			 * the activity being set. If you don't want the basic status to be modified
			 * automatically, you can use the combination of setBasicStatus(),
			 * clearActivities() and addActivity(). 
			 */
			LINPHONECXX_PUBLIC linphone::Status setActivity(linphone::PresenceActivity::Type activity, const std::string & description);
			
			;
			/**
			 * @brief Creates a presence model specifying an activity. 
			 *
			 * @param description An additional description of the activity (mainly useful for
			 * the 'other' activity). Set it to nullptr to not add a description. 
			 * 
			 * @return The created presence model, or nullptr if an error occured. 
			 * 
			 * @see linphone_presence_model_new 
			 * 
			 * @see linphone_presence_model_new_with_activity_and_note
			 * 
			 * The created presence model has the activity specified in the parameters. 
			 */
			LINPHONECXX_PUBLIC static std::shared_ptr<linphone::PresenceModel> newWithActivity(linphone::PresenceActivity::Type activity, const std::string & description);
			
;
			/**
			 * @brief Creates a presence model specifying an activity and adding a note. 
			 *
			 * @param lang The language the note is written in. It can be set to nullptr in
			 * order to not specify the language of the note. 
			 * 
			 * @return The created presence model, or nullptr if an error occured. 
			 * 
			 * @see linphone_presence_model_new_with_activity 
			 * 
			 * @see linphone_presence_model_new_with_activity_and_note
			 * 
			 * The created presence model has the activity and the note specified in the
			 * parameters. 
			 */
			LINPHONECXX_PUBLIC static std::shared_ptr<linphone::PresenceModel> newWithActivityAndNote(linphone::PresenceActivity::Type activity, const std::string & description, const std::string & note, const std::string & lang);
			

	};

};

#endif // _LINPHONE_PRESENCE_MODEL_HH
