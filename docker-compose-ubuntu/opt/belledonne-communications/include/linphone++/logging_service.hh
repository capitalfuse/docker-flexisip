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

#ifndef _LINPHONE_LOGGING_SERVICE_HH
#define _LINPHONE_LOGGING_SERVICE_HH

#include <string>
#include "enums.hh"
#include "object.hh"




struct _LinphoneLoggingService;


namespace linphone {

	class LoggingService;
	class LoggingServiceListener;

	/**
	 * @brief Singleton class giving access to logging features. 
	 *
	 */
	class LoggingService: public MultiListenableObject {
	
		public:

			LoggingService(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneLoggingService *cPtr() {return (_LinphoneLoggingService *)mPrivPtr;}

			LINPHONECXX_PUBLIC void addListener(const std::shared_ptr<LoggingServiceListener> &listener);
			LINPHONECXX_PUBLIC void removeListener(const std::shared_ptr<LoggingServiceListener> &listener);
	
		public:
			
		
			/**
			 * @brief Set the verbosity of the log. 
			 *
			 * For instance, a level of LinphoneLogLevelMessage will let pass fatal, error,
			 * warning and message-typed messages whereas trace and debug messages will be
			 * dumped out. 
			 */
			LINPHONECXX_PUBLIC void setLogLevel(linphone::LogLevel level);
			
			/**
			 * @brief Gets the log level mask. 
			 *
			 */
			LINPHONECXX_PUBLIC unsigned int getLogLevelMask() const;
			
			/**
			 * @brief Sets the types of messages that will be authorized to be written in the
			 * log. 
			 *
			 * @param mask Example: LinphoneLogLevelMessage|LinphoneLogLevelError will ONLY
			 * let pass message-typed and error messages. 
			 * 
			 * @note Calling that function reset the log level that has been specified by
			 * setLogLevel(). 
			 */
			LINPHONECXX_PUBLIC void setLogLevelMask(unsigned int mask);
			
			/**
			 * @brief Enables logging in a file. 
			 *
			 * That function enables an internal log handler that writes log messages in
			 * log-rotated files.
			 * 
			 * @param maxSize The maximal size of each part of the log. The log rotating is
			 * triggered each time the currently opened log part reach that limit. 
			 */
			LINPHONECXX_PUBLIC void setLogFile(const std::string & dir, const std::string & filename, size_t maxSize) const;
			
			;
			/**
			 * @brief Gets the singleton logging service object. 
			 *
			 * The singleton is automatically instantiated if it hasn't been done yet.
			 * 
			 * @return A pointer on the singleton. 
			 */
			LINPHONECXX_PUBLIC static std::shared_ptr<linphone::LoggingService> get();
			

		private:
			void *createCallbacks() override;
	};

};

#endif // _LINPHONE_LOGGING_SERVICE_HH
