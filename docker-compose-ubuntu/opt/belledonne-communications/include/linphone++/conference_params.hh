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

#ifndef _LINPHONE_CONFERENCE_PARAMS_HH
#define _LINPHONE_CONFERENCE_PARAMS_HH

#include "object.hh"




struct _LinphoneConferenceParams;


namespace linphone {

	class ConferenceParams;

	/**
	 * @brief Parameters for initialization of conferences The
	 * _LinphoneConferenceParams struct does not exists, it's the ConferenceParams C++
	 * class that is used behind. 
	 *
	 */
	class ConferenceParams: public Object {
	
		public:

			ConferenceParams(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneConferenceParams *cPtr() {return (_LinphoneConferenceParams *)mPrivPtr;}

	
		public:
			
		
			/**
			 * @brief Enable video when starting a conference. 
			 *
			 * @param enable If true, video will be enabled during conference 
			 */
			LINPHONECXX_PUBLIC void enableVideo(bool enable);
			
			/**
			 * @brief Clone a #linphone::ConferenceParams. 
			 *
			 * @return An allocated #linphone::ConferenceParams with the same parameters than
			 * params 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ConferenceParams> clone() const;
			
			/**
			 * @brief Check whether video will be enable at conference starting. 
			 *
			 * @return if true, the video will be enable at conference starting 
			 */
			LINPHONECXX_PUBLIC bool videoRequested() const;
			
			
	};

};

#endif // _LINPHONE_CONFERENCE_PARAMS_HH
