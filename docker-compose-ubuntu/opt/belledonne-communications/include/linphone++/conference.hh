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

#ifndef _LINPHONE_CONFERENCE_HH
#define _LINPHONE_CONFERENCE_HH

#include <string>
#include <list>
#include "object.hh"




struct _LinphoneConference;


namespace linphone {

	class Address;
	class CallParams;

	/**
	 * @brief #Conference class The _LinphoneConference struct does not exists, it's
	 * the Conference C++ class that is used behind 
	 *
	 */
	class Conference: public Object {
	
		public:

			Conference(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneConference *cPtr() {return (_LinphoneConference *)mPrivPtr;}

	
		public:
			
		
			/**
			 * @brief Get the conference id as string. 
			 *
			 */
			LINPHONECXX_PUBLIC std::string getId() const;
			
			/**
			 * @brief Set the conference id as string. 
			 *
			 */
			LINPHONECXX_PUBLIC void setId(const std::string & conferenceID) const;
			
			/**
			 * @brief Get URIs of all participants of one conference The returned bctbx_list_t
			 * contains URIs of all participant. 
			 *
			 * That list must be freed after use and each URI must be unref with
			 * linphone_address_unref 
			 * 
			 * @return A list of #Address objects. LinphoneAddress  
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::Address>> getParticipants() const;
			
			/**
			 * @brief Invite participants to the conference, by supplying a list of #Address. 
			 *
			 * @param params #CallParams to use for inviting the participants. 
			 */
			LINPHONECXX_PUBLIC linphone::Status inviteParticipants(const std::list<std::shared_ptr<linphone::Address>> & addresses, const std::shared_ptr<const linphone::CallParams> & params);
			
			/**
			 * @brief Remove a participant from a conference. 
			 *
			 * @param uri SIP URI of the participant to remove 
			 * 
			 * @warning The passed SIP URI must be one of the URIs returned by
			 * getParticipants() 
			 * 
			 * @return 0 if succeeded, -1 if failed 
			 */
			LINPHONECXX_PUBLIC linphone::Status removeParticipant(const std::shared_ptr<const linphone::Address> & uri);
			
			
	};

};

#endif // _LINPHONE_CONFERENCE_HH
