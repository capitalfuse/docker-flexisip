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

#ifndef _LINPHONE_NAT_POLICY_HH
#define _LINPHONE_NAT_POLICY_HH

#include <string>
#include "object.hh"




struct _LinphoneNatPolicy;


namespace linphone {

	class Core;

	/**
	 * @brief Policy to use to pass through NATs/firewalls. 
	 *
	 */
	class NatPolicy: public Object {
	
		public:

			NatPolicy(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneNatPolicy *cPtr() {return (_LinphoneNatPolicy *)mPrivPtr;}

	
		public:
			
		
			/**
			 * @brief Returns the #Core object managing this nat policy, if any. 
			 *
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Core> getCore() const;
			
			/**
			 * @brief Tell whether ICE is enabled. 
			 *
			 * @return Boolean value telling whether ICE is enabled. 
			 */
			LINPHONECXX_PUBLIC bool iceEnabled() const;
			
			/**
			 * @brief Enable ICE. 
			 *
			 * ICE can be enabled without STUN/TURN, in which case only the local candidates
			 * will be used. 
			 * 
			 * @param enable Boolean value telling whether to enable ICE. 
			 */
			LINPHONECXX_PUBLIC void enableIce(bool enable);
			
			/**
			 * @brief Tell whether STUN is enabled. 
			 *
			 * @return Boolean value telling whether STUN is enabled. 
			 */
			LINPHONECXX_PUBLIC bool stunEnabled() const;
			
			/**
			 * @brief Enable STUN. 
			 *
			 * If TURN is also enabled, TURN will be used instead of STUN. 
			 * 
			 * @param enable Boolean value telling whether to enable STUN. 
			 */
			LINPHONECXX_PUBLIC void enableStun(bool enable);
			
			/**
			 * @brief Get the STUN/TURN server to use with this NAT policy. 
			 *
			 * Used when STUN or TURN are enabled. 
			 * 
			 * @return The STUN server used by this NAT policy. 
			 */
			LINPHONECXX_PUBLIC std::string getStunServer() const;
			
			/**
			 * @brief Set the STUN/TURN server to use with this NAT policy. 
			 *
			 * Used when STUN or TURN are enabled. 
			 * 
			 * @param stunServer The STUN server to use with this NAT policy. 
			 */
			LINPHONECXX_PUBLIC void setStunServer(const std::string & stunServer);
			
			/**
			 * @brief Get the username used to authenticate with the STUN/TURN server. 
			 *
			 * The authentication will search for a #AuthInfo with this username. If it is not
			 * set the username of the currently used #ProxyConfig is used to search for a
			 * LinphoneAuthInfo. 
			 * 
			 * @return The username used to authenticate with the STUN/TURN server. 
			 */
			LINPHONECXX_PUBLIC std::string getStunServerUsername() const;
			
			/**
			 * @brief Set the username used to authenticate with the STUN/TURN server. 
			 *
			 * The authentication will search for a #AuthInfo with this username. If it is not
			 * set the username of the currently used #ProxyConfig is used to search for a
			 * LinphoneAuthInfo. 
			 * 
			 * @param username The username used to authenticate with the STUN/TURN server. 
			 */
			LINPHONECXX_PUBLIC void setStunServerUsername(const std::string & username);
			
			/**
			 * @brief Tell whether TURN is enabled. 
			 *
			 * @return Boolean value telling whether TURN is enabled. 
			 */
			LINPHONECXX_PUBLIC bool turnEnabled() const;
			
			/**
			 * @brief Enable TURN. 
			 *
			 * If STUN is also enabled, it is ignored and TURN is used. 
			 * 
			 * @param enable Boolean value telling whether to enable TURN. 
			 */
			LINPHONECXX_PUBLIC void enableTurn(bool enable);
			
			/**
			 * @brief Tell whether uPnP is enabled. 
			 *
			 * @return Boolean value telling whether uPnP is enabled. 
			 */
			LINPHONECXX_PUBLIC bool upnpEnabled() const;
			
			/**
			 * @brief Enable uPnP. 
			 *
			 * This has the effect to disable every other policies (ICE, STUN and TURN). 
			 * 
			 * @param enable Boolean value telling whether to enable uPnP. 
			 */
			LINPHONECXX_PUBLIC void enableUpnp(bool enable);
			
			/**
			 * @brief Clear a NAT policy (deactivate all protocols and unset the STUN server). 
			 *
			 */
			LINPHONECXX_PUBLIC void clear();
			
			/**
			 * @brief Start a STUN server DNS resolution. 
			 *
			 */
			LINPHONECXX_PUBLIC void resolveStunServer();
			
			
	};

};

#endif // _LINPHONE_NAT_POLICY_HH
