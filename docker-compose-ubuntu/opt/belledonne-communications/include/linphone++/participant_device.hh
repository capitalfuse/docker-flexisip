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

#ifndef _LINPHONE_PARTICIPANT_DEVICE_HH
#define _LINPHONE_PARTICIPANT_DEVICE_HH

#include <string>
#include "enums.hh"
#include "object.hh"




struct _LinphoneParticipantDevice;


namespace linphone {

	class Address;

	/**
	 *
	 */
	class ParticipantDevice: public Object {
	
		public:

			ParticipantDevice(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneParticipantDevice *cPtr() {return (_LinphoneParticipantDevice *)mPrivPtr;}

	
		public:
			
		
			/**
			 * @brief Get the address of a participant's device. 
			 *
			 * @return The address of the participant's device 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::Address> getAddress() const;
			
			/**
			 * @brief Return the name of the device or nullptr. 
			 *
			 * @return the name of the device or nullptr 
			 */
			LINPHONECXX_PUBLIC std::string getName() const;
			
			/**
			 * @brief Get the security level of a participant's device. 
			 *
			 * @return The security level of the device 
			 */
			LINPHONECXX_PUBLIC linphone::ChatRoomSecurityLevel getSecurityLevel() const;
			
			
	};

};

#endif // _LINPHONE_PARTICIPANT_DEVICE_HH
