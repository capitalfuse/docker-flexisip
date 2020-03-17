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

#ifndef _LINPHONE_TUNNEL_CONFIG_HH
#define _LINPHONE_TUNNEL_CONFIG_HH

#include <string>
#include "object.hh"




struct _LinphoneTunnelConfig;


namespace linphone {


	/**
	 * @brief Tunnel settings. 
	 *
	 */
	class TunnelConfig: public Object {
	
		public:

			TunnelConfig(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneTunnelConfig *cPtr() {return (_LinphoneTunnelConfig *)mPrivPtr;}

	
		public:
			
		
			/**
			 * @brief Get the UDP packet round trip delay in ms for a tunnel configuration. 
			 *
			 * @return The UDP packet round trip delay in ms. 
			 */
			LINPHONECXX_PUBLIC int getDelay() const;
			
			/**
			 * @brief Set the UDP packet round trip delay in ms for a tunnel configuration. 
			 *
			 * @param delay The UDP packet round trip delay in ms considered as acceptable
			 * (recommended value is 1000 ms). 
			 */
			LINPHONECXX_PUBLIC void setDelay(int delay);
			
			/**
			 * @brief Get the IP address or hostname of the tunnel server. 
			 *
			 * @return The tunnel server IP address or hostname 
			 */
			LINPHONECXX_PUBLIC std::string getHost() const;
			
			/**
			 * @brief Set the IP address or hostname of the tunnel server. 
			 *
			 * @param host The tunnel server IP address or hostname 
			 */
			LINPHONECXX_PUBLIC void setHost(const std::string & host);
			
			/**
			 * @brief Get the IP address or hostname of the second tunnel server when using
			 * dual tunnel client. 
			 *
			 * @return The tunnel server IP address or hostname 
			 */
			LINPHONECXX_PUBLIC std::string getHost2() const;
			
			/**
			 * @brief Set the IP address or hostname of the second tunnel server when using
			 * dual tunnel client. 
			 *
			 * @param host The tunnel server IP address or hostname 
			 */
			LINPHONECXX_PUBLIC void setHost2(const std::string & host);
			
			/**
			 * @brief Get the TLS port of the tunnel server. 
			 *
			 * @return The TLS port of the tunnel server 
			 */
			LINPHONECXX_PUBLIC int getPort() const;
			
			/**
			 * @brief Set tls port of server. 
			 *
			 * @param port The tunnel server TLS port, recommended value is 443 
			 */
			LINPHONECXX_PUBLIC void setPort(int port);
			
			/**
			 * @brief Get the TLS port of the second tunnel server when using dual tunnel
			 * client. 
			 *
			 * @return The TLS port of the tunnel server 
			 */
			LINPHONECXX_PUBLIC int getPort2() const;
			
			/**
			 * @brief Set tls port of the second server when using dual tunnel client. 
			 *
			 * @param port The tunnel server TLS port, recommended value is 443 
			 */
			LINPHONECXX_PUBLIC void setPort2(int port);
			
			/**
			 * @brief Get the remote port on the tunnel server side used to test UDP
			 * reachability. 
			 *
			 * This is used when the mode is set auto, to detect whether the tunnel has to be
			 * enabled or not. 
			 * 
			 * @return The remote port on the tunnel server side used to test UDP reachability 
			 */
			LINPHONECXX_PUBLIC int getRemoteUdpMirrorPort() const;
			
			/**
			 * @brief Set the remote port on the tunnel server side used to test UDP
			 * reachability. 
			 *
			 * This is used when the mode is set auto, to detect whether the tunnel has to be
			 * enabled or not. 
			 * 
			 * @param remoteUdpMirrorPort The remote port on the tunnel server side used to
			 * test UDP reachability, set to -1 to disable the feature 
			 */
			LINPHONECXX_PUBLIC void setRemoteUdpMirrorPort(int remoteUdpMirrorPort);
			
			
	};

};

#endif // _LINPHONE_TUNNEL_CONFIG_HH
