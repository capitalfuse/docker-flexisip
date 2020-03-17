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

#ifndef _LINPHONE_PRESENCE_ACTIVITY_HH
#define _LINPHONE_PRESENCE_ACTIVITY_HH

#include <string>
#include "presence_activity.hh"
#include "object.hh"




struct _LinphonePresenceActivity;


namespace linphone {


	/**
	 * @brief Presence activity type holding information about a presence activity. 
	 *
	 */
	class PresenceActivity: public Object {
	
		public:
			/**
			* Activities as defined in section 3.2 of RFC 4480. 
			*
			*/
			enum class Type {
				/**
				* The person has a calendar appointment, without specifying exactly of what type. 
				*/
				Appointment,
				/**
				* The person is physically away from all interactive communication devices. 
				*/
				Away,
				/**
				* The person is eating the first meal of the day, usually eaten in the morning. 
				*/
				Breakfast,
				/**
				* The person is busy, without further details. 
				*/
				Busy,
				/**
				* The person is having his or her main meal of the day, eaten in the evening or
				* at midday. 
				*/
				Dinner,
				/**
				* This is a scheduled national or local holiday. 
				*/
				Holiday,
				/**
				* The person is riding in a vehicle, such as a car, but not steering. 
				*/
				InTransit,
				/**
				* The person is looking for (paid) work. 
				*/
				LookingForWork,
				/**
				* The person is eating his or her midday meal. 
				*/
				Lunch,
				/**
				* The person is scheduled for a meal, without specifying whether it is breakfast,
				* lunch, or dinner, or some other meal. 
				*/
				Meal,
				/**
				* The person is in an assembly or gathering of people, as for a business, social,
				* or religious purpose. 
				*/
				Meeting,
				/**
				* The person is talking on the telephone. 
				*/
				OnThePhone,
				/**
				* The person is engaged in an activity with no defined representation. 
				*/
				Other,
				/**
				* A performance is a sub-class of an appointment and includes musical,
				* theatrical, and cinematic performances as well as lectures. 
				*/
				Performance,
				/**
				* The person will not return for the foreseeable future, e.g., because it is no
				* longer working for the company. 
				*/
				PermanentAbsence,
				/**
				* The person is occupying himself or herself in amusement, sport, or other
				* recreation. 
				*/
				Playing,
				/**
				* The person is giving a presentation, lecture, or participating in a formal
				* round-table discussion. 
				*/
				Presentation,
				/**
				* The person is visiting stores in search of goods or services. 
				*/
				Shopping,
				/**
				* The person is sleeping. 
				*/
				Sleeping,
				/**
				* The person is observing an event, such as a sports event. 
				*/
				Spectator,
				/**
				* The person is controlling a vehicle, watercraft, or plane. 
				*/
				Steering,
				/**
				* The person is on a business or personal trip, but not necessarily in-transit. 
				*/
				Travel,
				/**
				* The person is watching television. 
				*/
				TV,
				/**
				* The activity of the person is unknown. 
				*/
				Unknown,
				/**
				* A period of time devoted to pleasure, rest, or relaxation. 
				*/
				Vacation,
				/**
				* The person is engaged in, typically paid, labor, as part of a profession or
				* job. 
				*/
				Working,
				/**
				* The person is participating in religious rites. 
				*/
				Worship
			};


			PresenceActivity(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphonePresenceActivity *cPtr() {return (_LinphonePresenceActivity *)mPrivPtr;}

	
		public:
			
		
			/**
			 * @brief Gets the description of a presence activity. 
			 *
			 * @return A pointer to the description string of the presence activity, or
			 * nullptr if no description is specified. 
			 */
			LINPHONECXX_PUBLIC std::string getDescription() const;
			
			/**
			 * @brief Sets the description of a presence activity. 
			 *
			 * @param description An additional description of the activity. Can be nullptr if
			 * no additional description is to be added. 
			 * 
			 * @return 0 if successful, a value < 0 in case of error. 
			 */
			LINPHONECXX_PUBLIC linphone::Status setDescription(const std::string & description);
			
			/**
			 * @brief Gets the activity type of a presence activity. 
			 *
			 * @return The LinphonePresenceActivityType of the activity. 
			 */
			LINPHONECXX_PUBLIC Type getType() const;
			
			/**
			 * @brief Sets the type of activity of a presence activity. 
			 *
			 * @param acttype The activity type to set for the activity. 
			 * 
			 * @return 0 if successful, a value < 0 in case of error. 
			 */
			LINPHONECXX_PUBLIC linphone::Status setType(Type acttype);
			
			/**
			 * @brief Gets the string representation of a presence activity. 
			 *
			 * @return A pointer a dynamically allocated string representing the given
			 * activity.
			 * 
			 * The returned string is to be freed by calling ms_free(). 
			 */
			LINPHONECXX_PUBLIC std::string toString() const;
			
			
	};

};

#endif // _LINPHONE_PRESENCE_ACTIVITY_HH
