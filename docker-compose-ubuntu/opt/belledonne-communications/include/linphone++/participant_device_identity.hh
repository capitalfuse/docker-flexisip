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

#ifndef _LINPHONE_PARTICIPANT_DEVICE_IDENTITY_HH
#define _LINPHONE_PARTICIPANT_DEVICE_IDENTITY_HH

#include "object.hh"




struct _LinphoneParticipantDeviceIdentity;


namespace linphone {

	class ParticipantDeviceIdentity;

	/**
	 *
	 */
	class ParticipantDeviceIdentity: public Object {
	
		public:

			ParticipantDeviceIdentity(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneParticipantDeviceIdentity *cPtr() {return (_LinphoneParticipantDeviceIdentity *)mPrivPtr;}

	
		public:
			
		
			/**
			 * @brief Clones a #LinphoneParticipantDeviceIdentity object. 
			 *
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ParticipantDeviceIdentity> clone() const;
			
			
	};

};

#endif // _LINPHONE_PARTICIPANT_DEVICE_IDENTITY_HH
