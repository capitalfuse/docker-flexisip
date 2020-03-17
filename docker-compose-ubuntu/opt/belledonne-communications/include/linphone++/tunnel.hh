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

#ifndef _LINPHONE_TUNNEL_HH
#define _LINPHONE_TUNNEL_HH

#include <list>
#include <string>
#include "tunnel.hh"
#include "object.hh"




struct _LinphoneTunnel;


namespace linphone {

	class TunnelConfig;

	/**
	 * @brief Linphone tunnel object. 
	 *
	 */
	class Tunnel: public Object {
	
		public:
			/**
			* Enum describing the tunnel modes. 
			*
			*/
			enum class Mode {
				/**
				* The tunnel is disabled. 
				*/
				Disable,
				/**
				* The tunnel is enabled. 
				*/
				Enable,
				/**
				* The tunnel is enabled automatically if it is required. 
				*/
				Auto
			};


			Tunnel(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneTunnel *cPtr() {return (_LinphoneTunnel *)mPrivPtr;}

	
		public:
			
		
			/**
			 * @brief Returns whether the tunnel is activated. 
			 *
			 * If mode is set to auto, this gives indication whether the automatic detection
			 * determined that tunnel was necessary or not. 
			 * 
			 * @return  if tunnel is in use, true otherwise. 
			 */
			LINPHONECXX_PUBLIC bool getActivated() const;
			
			/**
			 * @brief Get the dual tunnel client mode. 
			 *
			 * @return  if dual tunnel client mode is enabled, true otherwise 
			 */
			LINPHONECXX_PUBLIC bool dualModeEnabled() const;
			
			/**
			 * @brief Sets whether or not to use the dual tunnel client mode. 
			 *
			 * By default this feature is disabled. After enabling it, add a server with 2
			 * hosts and 2 ports for the feature to work. 
			 * 
			 * @param dualModeEnabled  to enable it, true to disable it 
			 */
			LINPHONECXX_PUBLIC void enableDualMode(bool dualModeEnabled);
			
			/**
			 * @brief Get the tunnel mode. 
			 *
			 * @return The current LinphoneTunnelMode 
			 */
			LINPHONECXX_PUBLIC Mode getMode() const;
			
			/**
			 * @brief Set the tunnel mode. 
			 *
			 * The tunnel mode can be 'enable', 'disable' or 'auto' If the mode is set to
			 * 'auto', the tunnel manager will try to established an RTP session with the
			 * tunnel server on the UdpMirrorPort. If the connection fail, the tunnel is
			 * automatically activated whereas the tunnel is automatically disabled if the
			 * connection succeed. 
			 * 
			 * @param mode The desired LinphoneTunnelMode 
			 */
			LINPHONECXX_PUBLIC void setMode(Mode mode);
			
			/**
			 * @brief Get added servers. 
			 *
			 * @return A list of #TunnelConfig objects. LinphoneTunnelConfig  
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::TunnelConfig>> getServers() const;
			
			/**
			 * @brief Check whether tunnel is set to transport SIP packets. 
			 *
			 * @return A boolean value telling whether SIP packets shall pass through the
			 * tunnel 
			 */
			LINPHONECXX_PUBLIC bool sipEnabled() const;
			
			/**
			 * @brief Set whether SIP packets must be directly sent to a UA or pass through
			 * the tunnel. 
			 *
			 * @param enable If true, SIP packets shall pass through the tunnel 
			 */
			LINPHONECXX_PUBLIC void enableSip(bool enable);
			
			/**
			 * @brief Add a tunnel server configuration. 
			 *
			 * @param tunnelConfig #TunnelConfig object 
			 */
			LINPHONECXX_PUBLIC void addServer(const std::shared_ptr<linphone::TunnelConfig> & tunnelConfig);
			
			/**
			 * @brief Remove all tunnel server addresses previously entered with addServer() 
			 *
			 */
			LINPHONECXX_PUBLIC void cleanServers();
			
			/**
			 * @brief Check whether the tunnel is connected. 
			 *
			 * @return A boolean value telling if the tunnel is connected 
			 */
			LINPHONECXX_PUBLIC bool connected() const;
			
			/**
			 * @brief Force reconnection to the tunnel server. 
			 *
			 * This method is useful when the device switches from wifi to Edge/3G or vice
			 * versa. In most cases the tunnel client socket won't be notified promptly that
			 * its connection is now zombie, so it is recommended to call this method that
			 * will cause the lost connection to be closed and new connection to be issued. 
			 */
			LINPHONECXX_PUBLIC void reconnect();
			
			/**
			 * @brief Remove a tunnel server configuration. 
			 *
			 * @param tunnelConfig #TunnelConfig object 
			 */
			LINPHONECXX_PUBLIC void removeServer(const std::shared_ptr<linphone::TunnelConfig> & tunnelConfig);
			
			/**
			 * @brief Set an optional http proxy to go through when connecting to tunnel
			 * server. 
			 *
			 * @param passwd Optional http proxy password. Use nullptr if not needed. 
			 */
			LINPHONECXX_PUBLIC void setHttpProxy(const std::string & host, int port, const std::string & username, const std::string & passwd);
			
			/**
			 * @brief Set authentication info for the http proxy. 
			 *
			 * @param passwd Password 
			 */
			LINPHONECXX_PUBLIC void setHttpProxyAuthInfo(const std::string & username, const std::string & passwd);
			
			
	};

};

#endif // _LINPHONE_TUNNEL_HH
