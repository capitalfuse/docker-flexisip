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

#ifndef _LINPHONE_LOGGING_SERVICE_LISTENER_HH
#define _LINPHONE_LOGGING_SERVICE_LISTENER_HH

#include <string>
#include "enums.hh"
#include "object.hh"






namespace linphone {

	class LoggingService;

	/**
	 *
	 */
	class LoggingServiceListener: public Listener {
	
		public:


	
		public:
			
		
			/**
			 * @brief Type of callbacks called each time liblinphone write a log message. 
			 *
			 * @param message Content of the message. 
			 */
			LINPHONECXX_PUBLIC virtual void onLogMessageWritten(const std::shared_ptr<linphone::LoggingService> & logService, const std::string & domain, linphone::LogLevel lev, const std::string & message) {};
			
			
	};

};

#endif // _LINPHONE_LOGGING_SERVICE_LISTENER_HH
