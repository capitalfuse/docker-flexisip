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

#ifndef _LINPHONE_ADDRESS_HH
#define _LINPHONE_ADDRESS_HH

#include <string>
#include "enums.hh"
#include "object.hh"




struct _LinphoneAddress;


namespace linphone {

	class Address;

	/**
	 * @brief Object that represents a SIP address. 
	 *
	 * The #Address is an opaque object to represents SIP addresses, ie the content of
	 * SIP's 'from' and 'to' headers. A SIP address is made of display name, username,
	 * domain name, port, and various uri headers (such as tags). It looks like 'Alice
	 * <sip:alice@example.net>'. The #Address has methods to extract and manipulate
	 * all parts of the address. When some part of the address (for example the
	 * username) is empty, the accessor methods return nullptr. 
	 */
	class Address: public Object {
	
		public:

			Address(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneAddress *cPtr() {return (_LinphoneAddress *)mPrivPtr;}

	
		public:
			
		
			/**
			 * @brief Returns the display name. 
			 *
			 */
			LINPHONECXX_PUBLIC std::string getDisplayName() const;
			
			/**
			 * @brief Sets the display name. 
			 *
			 */
			LINPHONECXX_PUBLIC linphone::Status setDisplayName(const std::string & displayName);
			
			/**
			 * @brief Returns the domain name. 
			 *
			 */
			LINPHONECXX_PUBLIC std::string getDomain() const;
			
			/**
			 * @brief Sets the domain. 
			 *
			 */
			LINPHONECXX_PUBLIC linphone::Status setDomain(const std::string & domain);
			
			/**
			 * @brief returns true if address is a routable sip address 
			 *
			 */
			LINPHONECXX_PUBLIC bool isSip() const;
			
			/**
			 * @brief Get the value of the method parameter. 
			 *
			 */
			LINPHONECXX_PUBLIC std::string getMethodParam() const;
			
			/**
			 * @brief Set the value of the method parameter. 
			 *
			 */
			LINPHONECXX_PUBLIC void setMethodParam(const std::string & methodParam);
			
			/**
			 * @brief Get the password encoded in the address. 
			 *
			 * It is used for basic authentication (not recommended). 
			 * 
			 * @return the password, if any, nullptr otherwise. 
			 */
			LINPHONECXX_PUBLIC std::string getPassword() const;
			
			/**
			 * @brief Set the password encoded in the address. 
			 *
			 * It is used for basic authentication (not recommended). 
			 * 
			 * @param password the password to set. 
			 */
			LINPHONECXX_PUBLIC void setPassword(const std::string & password);
			
			/**
			 * @brief Get port number as an integer value, 0 if not present. 
			 *
			 */
			LINPHONECXX_PUBLIC int getPort() const;
			
			/**
			 * @brief Sets the port number. 
			 *
			 */
			LINPHONECXX_PUBLIC linphone::Status setPort(int port);
			
			/**
			 * @brief Returns the address scheme, normally "sip". 
			 *
			 */
			LINPHONECXX_PUBLIC std::string getScheme() const;
			
			/**
			 * @brief Returns true if address refers to a secure location (sips) 
			 *
			 */
			LINPHONECXX_PUBLIC bool getSecure() const;
			
			/**
			 * @brief Make the address refer to a secure location (sips scheme) 
			 *
			 * @param enabled  if address is requested to be secure. 
			 */
			LINPHONECXX_PUBLIC void setSecure(bool enabled);
			
			/**
			 * @brief Get the transport. 
			 *
			 */
			LINPHONECXX_PUBLIC linphone::TransportType getTransport() const;
			
			/**
			 * @brief Set a transport. 
			 *
			 */
			LINPHONECXX_PUBLIC linphone::Status setTransport(linphone::TransportType transport);
			
			/**
			 * @brief Returns the username. 
			 *
			 */
			LINPHONECXX_PUBLIC std::string getUsername() const;
			
			/**
			 * @brief Sets the username. 
			 *
			 */
			LINPHONECXX_PUBLIC linphone::Status setUsername(const std::string & username);
			
			/**
			 * @brief Returns the address as a string. 
			 *
			 * The returned char * must be freed by the application. Use ms_free(). 
			 */
			LINPHONECXX_PUBLIC std::string asString() const;
			
			/**
			 * @brief Returns the SIP uri only as a string, that is display name is removed. 
			 *
			 * The returned char * must be freed by the application. Use ms_free(). 
			 */
			LINPHONECXX_PUBLIC std::string asStringUriOnly() const;
			
			/**
			 * @brief Removes address's tags and uri headers so that it is displayable to the
			 * user. 
			 *
			 */
			LINPHONECXX_PUBLIC void clean();
			
			/**
			 * @brief Clones a #linphone::Address object. 
			 *
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Address> clone() const;
			
			/**
			 * @brief Compare two #linphone::Address taking the tags and headers into account. 
			 *
			 * @param address2 #linphone::Address object 
			 * 
			 * @return Boolean value telling if the #linphone::Address objects are equal. 
			 * 
			 * @see weakEqual() 
			 */
			LINPHONECXX_PUBLIC bool equal(const std::shared_ptr<const linphone::Address> & address2) const;
			
			/**
			 * @brief Get the header encoded in the address. 
			 *
			 * @param headerName the header name 
			 */
			LINPHONECXX_PUBLIC std::string getHeader(const std::string & headerName) const;
			
			/**
			 * @brief Get the value of a parameter of the address. 
			 *
			 * @param paramName The name of the parameter 
			 * 
			 * @return The value of the parameter 
			 */
			LINPHONECXX_PUBLIC std::string getParam(const std::string & paramName) const;
			
			/**
			 * @brief Get the value of a parameter of the URI of the address. 
			 *
			 * @param uriParamName The name of the parameter 
			 * 
			 * @return The value of the parameter 
			 */
			LINPHONECXX_PUBLIC std::string getUriParam(const std::string & uriParamName) const;
			
			/**
			 * @brief Tell whether a parameter is present in the address. 
			 *
			 * @param paramName The name of the parameter 
			 * 
			 * @return A boolean value telling whether the parameter is present in the address 
			 */
			LINPHONECXX_PUBLIC bool hasParam(const std::string & paramName) const;
			
			/**
			 * @brief Tell whether a parameter is present in the URI of the address. 
			 *
			 * @param uriParamName The name of the parameter 
			 * 
			 * @return A boolean value telling whether the parameter is present in the URI of
			 * the address 
			 */
			LINPHONECXX_PUBLIC bool hasUriParam(const std::string & uriParamName) const;
			
			/**
			 * @brief Removes the value of a parameter of the URI of the address. 
			 *
			 * @param uriParamName The name of the parameter 
			 */
			LINPHONECXX_PUBLIC void removeUriParam(const std::string & uriParamName);
			
			/**
			 * @brief Set a header into the address. 
			 *
			 * Headers appear in the URI with '?', such as
			 * <sip:test@linphone.org?SomeHeader=SomeValue>. 
			 * 
			 * @param headerValue the header value 
			 */
			LINPHONECXX_PUBLIC void setHeader(const std::string & headerName, const std::string & headerValue);
			
			/**
			 * @brief Set the value of a parameter of the address. 
			 *
			 * @param paramValue The new value of the parameter 
			 */
			LINPHONECXX_PUBLIC void setParam(const std::string & paramName, const std::string & paramValue);
			
			/**
			 * @brief Set the value of a parameter of the URI of the address. 
			 *
			 * @param uriParamValue The new value of the parameter 
			 */
			LINPHONECXX_PUBLIC void setUriParam(const std::string & uriParamName, const std::string & uriParamValue);
			
			/**
			 * @brief Compare two #linphone::Address ignoring tags and headers, basically just
			 * domain, username, and port. 
			 *
			 * @param address2 #linphone::Address object 
			 * 
			 * @return Boolean value telling if the #linphone::Address objects are equal. 
			 * 
			 * @see equal() 
			 */
			LINPHONECXX_PUBLIC bool weakEqual(const std::shared_ptr<const linphone::Address> & address2) const;
			
			
	};

};

#endif // _LINPHONE_ADDRESS_HH
