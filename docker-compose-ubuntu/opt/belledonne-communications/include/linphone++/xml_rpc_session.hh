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

#ifndef _LINPHONE_XML_RPC_SESSION_HH
#define _LINPHONE_XML_RPC_SESSION_HH

#include <string>
#include "enums.hh"
#include "object.hh"




struct _LinphoneXmlRpcSession;


namespace linphone {

	class XmlRpcRequest;

	/**
	 * @brief The #XmlRpcSession object used to send XML-RPC requests and handle their
	 * responses. 
	 *
	 */
	class XmlRpcSession: public Object {
	
		public:

			XmlRpcSession(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneXmlRpcSession *cPtr() {return (_LinphoneXmlRpcSession *)mPrivPtr;}

	
		public:
			
		
			/**
			 * @brief Creates a #XmlRpcRequest from a #linphone::XmlRpcSession. 
			 *
			 * @param method the function name to call 
			 * 
			 * @return a #XmlRpcRequest object 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::XmlRpcRequest> createRequest(linphone::XmlRpcArgType returnType, const std::string & method);
			
			/**
			 * @brief Stop and unref an XML rpc session. 
			 *
			 * Pending requests will be aborted. 
			 */
			LINPHONECXX_PUBLIC void release();
			
			/**
			 * @brief Send an XML-RPC request. 
			 *
			 * @param request The #XmlRpcRequest to be sent. 
			 */
			LINPHONECXX_PUBLIC void sendRequest(const std::shared_ptr<linphone::XmlRpcRequest> & request);
			
			
	};

};

#endif // _LINPHONE_XML_RPC_SESSION_HH
