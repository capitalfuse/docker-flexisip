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

#ifndef _LINPHONE_PARTICIPANT_IMDN_STATE_HH
#define _LINPHONE_PARTICIPANT_IMDN_STATE_HH

#include "chat_message.hh"
#include "object.hh"




struct _LinphoneParticipantImdnState;


namespace linphone {

	class Participant;

	/**
	 * @brief The LinphoneParticipantImdnState object represents the state of chat
	 * message for a participant of a conference chat room. 
	 *
	 */
	class ParticipantImdnState: public Object {
	
		public:

			ParticipantImdnState(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneParticipantImdnState *cPtr() {return (_LinphoneParticipantImdnState *)mPrivPtr;}

	
		public:
			
		
			/**
			 * @brief Get the participant concerned by a LinphoneParticipantImdnState. 
			 *
			 * @return The participant concerned by the LinphoneParticipantImdnState 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::Participant> getParticipant() const;
			
			/**
			 * @brief Get the chat message state the participant is in. 
			 *
			 * @return The chat message state the participant is in 
			 */
			LINPHONECXX_PUBLIC linphone::ChatMessage::State getState() const;
			
			/**
			 * @brief Get the timestamp at which a participant has reached the state described
			 * by a LinphoneParticipantImdnState. 
			 *
			 * @return The timestamp at which the participant has reached the state described
			 * in the LinphoneParticipantImdnState 
			 */
			LINPHONECXX_PUBLIC time_t getStateChangeTime() const;
			
			
	};

};

#endif // _LINPHONE_PARTICIPANT_IMDN_STATE_HH
