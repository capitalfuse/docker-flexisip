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

#ifndef _LINPHONE_EVENT_LISTENER_HH
#define _LINPHONE_EVENT_LISTENER_HH

#include "object.hh"






namespace linphone {

	class Event;

	/**
	 *
	 */
	class EventListener: public Listener {
	
		public:


	
		public:
			
		
			/**
			 * @brief Callback used to notify the response to a sent NOTIFY. 
			 *
			 * @param ev The LinphoneEvent object that has sent the NOTIFY and for which we
			 * received a response 
			 */
			LINPHONECXX_PUBLIC virtual void onNotifyResponse(const std::shared_ptr<const linphone::Event> & ev) {};
			
			
	};

};

#endif // _LINPHONE_EVENT_LISTENER_HH
