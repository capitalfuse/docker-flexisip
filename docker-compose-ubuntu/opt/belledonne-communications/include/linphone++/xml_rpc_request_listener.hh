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

#ifndef _LINPHONE_XML_RPC_REQUEST_LISTENER_HH
#define _LINPHONE_XML_RPC_REQUEST_LISTENER_HH

#include "object.hh"






namespace linphone {

	class XmlRpcRequest;

	/**
	 *
	 */
	class XmlRpcRequestListener: public Listener {
	
		public:


	
		public:
			
		
			/**
			 * @brief Callback used to notify the response to an XML-RPC request. 
			 *
			 * @param request LinphoneXmlRpcRequest object 
			 */
			LINPHONECXX_PUBLIC virtual void onResponse(const std::shared_ptr<linphone::XmlRpcRequest> & request) {};
			
			
	};

};

#endif // _LINPHONE_XML_RPC_REQUEST_LISTENER_HH
