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

#ifndef _LINPHONE_VIDEO_ACTIVATION_POLICY_HH
#define _LINPHONE_VIDEO_ACTIVATION_POLICY_HH

#include "object.hh"




struct _LinphoneVideoActivationPolicy;


namespace linphone {


	/**
	 * @brief Structure describing policy regarding video streams establishments. 
	 *
	 */
	class VideoActivationPolicy: public Object {
	
		public:

			VideoActivationPolicy(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneVideoActivationPolicy *cPtr() {return (_LinphoneVideoActivationPolicy *)mPrivPtr;}

	
		public:
			
		
			/**
			 * @brief Gets the value for the automatically accept video policy. 
			 *
			 * @return whether or not to automatically accept video requests is enabled 
			 */
			LINPHONECXX_PUBLIC bool getAutomaticallyAccept() const;
			
			/**
			 * @brief Sets the value for the automatically accept video policy. 
			 *
			 * @param enable whether or not to enable automatically accept video requests 
			 */
			LINPHONECXX_PUBLIC void setAutomaticallyAccept(bool enable);
			
			/**
			 * @brief Gets the value for the automatically initiate video policy. 
			 *
			 * @return whether or not to automatically initiate video calls is enabled 
			 */
			LINPHONECXX_PUBLIC bool getAutomaticallyInitiate() const;
			
			/**
			 * @brief Sets the value for the automatically initiate video policy. 
			 *
			 * @param enable whether or not to enable automatically initiate video calls 
			 */
			LINPHONECXX_PUBLIC void setAutomaticallyInitiate(bool enable);
			
			
	};

};

#endif // _LINPHONE_VIDEO_ACTIVATION_POLICY_HH
