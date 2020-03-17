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

#ifndef _LINPHONE_ERROR_INFO_HH
#define _LINPHONE_ERROR_INFO_HH

#include <string>
#include "enums.hh"
#include "object.hh"




struct _LinphoneErrorInfo;


namespace linphone {

	class ErrorInfo;

	/**
	 * @brief Object representing full details about a signaling error or status. 
	 *
	 * All #ErrorInfo object returned by the liblinphone API are readonly and
	 * transcients. For safety they must be used immediately after obtaining them. Any
	 * other function call to the liblinphone may change their content or invalidate
	 * the pointer. 
	 */
	class ErrorInfo: public Object {
	
		public:

			ErrorInfo(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneErrorInfo *cPtr() {return (_LinphoneErrorInfo *)mPrivPtr;}

	
		public:
			
		
			/**
			 * @brief Get textual phrase from the error info. 
			 *
			 * This is the text that is provided by the peer in the protocol (SIP). 
			 * 
			 * @return The error phrase 
			 */
			LINPHONECXX_PUBLIC std::string getPhrase() const;
			
			/**
			 * @brief Assign phrase to a #linphone::ErrorInfo object. 
			 *
			 * @param phrase the phrase explaining the error 
			 */
			LINPHONECXX_PUBLIC void setPhrase(const std::string & phrase);
			
			/**
			 * @brief Get protocol from the error info. 
			 *
			 * @return The protocol 
			 */
			LINPHONECXX_PUBLIC std::string getProtocol() const;
			
			/**
			 * @brief Assign protocol name to a #linphone::ErrorInfo object. 
			 *
			 * @param proto the protocol name 
			 */
			LINPHONECXX_PUBLIC void setProtocol(const std::string & proto);
			
			/**
			 * @brief Get the status code from the low level protocol (ex a SIP status code). 
			 *
			 * @return The status code 
			 */
			LINPHONECXX_PUBLIC int getProtocolCode() const;
			
			/**
			 * @brief Assign protocol code to a #linphone::ErrorInfo object. 
			 *
			 * @param code the protocol code 
			 */
			LINPHONECXX_PUBLIC void setProtocolCode(int code);
			
			/**
			 * @brief Get reason code from the error info. 
			 *
			 * @return A LinphoneReason 
			 */
			LINPHONECXX_PUBLIC linphone::Reason getReason() const;
			
			/**
			 * @brief Assign reason LinphoneReason to a #linphone::ErrorInfo object. 
			 *
			 * @param reason reason from LinphoneReason enum 
			 */
			LINPHONECXX_PUBLIC void setReason(linphone::Reason reason);
			
			/**
			 * @brief Get Retry-After delay second from the error info. 
			 *
			 * @return The Retry-After delay second 
			 */
			LINPHONECXX_PUBLIC int getRetryAfter() const;
			
			/**
			 * @brief Assign retry-after value to a #linphone::ErrorInfo object. 
			 *
			 * @param retryAfter the retry-after value 
			 */
			LINPHONECXX_PUBLIC void setRetryAfter(int retryAfter);
			
			/**
			 * @brief Get pointer to chained #linphone::ErrorInfo set in sub_ei. 
			 *
			 * It corresponds to a Reason header in a received SIP response. 
			 * 
			 * @return #linphone::ErrorInfo pointer defined in the ei object. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ErrorInfo> getSubErrorInfo() const;
			
			/**
			 * @brief Set the sub_ei in #linphone::ErrorInfo to another LinphoneErrorInfo. 
			 *
			 * Used when a reason header is to be added in a SIP response. The first level
			 * #linphone::ErrorInfo defines the SIP response code and phrase, the second (sub)
			 * #LinphoneErroInfo defining the content of the Reason header. 
			 * 
			 * @param appendedEi #linphone::ErrorInfo to append 
			 */
			LINPHONECXX_PUBLIC void setSubErrorInfo(const std::shared_ptr<linphone::ErrorInfo> & appendedEi);
			
			/**
			 * @brief Provides additional information regarding the failure. 
			 *
			 * With SIP protocol, the content of "Warning" headers are returned. 
			 * 
			 * @return More details about the failure 
			 */
			LINPHONECXX_PUBLIC std::string getWarnings() const;
			
			/**
			 * @brief Assign warnings to a #linphone::ErrorInfo object. 
			 *
			 */
			LINPHONECXX_PUBLIC void setWarnings(const std::string & warnings);
			
			/**
			 * @brief Assign information to a #linphone::ErrorInfo object. 
			 *
			 * @param warning warning message 
			 */
			LINPHONECXX_PUBLIC void set(const std::string & protocol, linphone::Reason reason, int code, const std::string & statusString, const std::string & warning);
			
			
	};

};

#endif // _LINPHONE_ERROR_INFO_HH
