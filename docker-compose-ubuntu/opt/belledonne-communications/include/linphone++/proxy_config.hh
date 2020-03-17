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

#ifndef _LINPHONE_PROXY_CONFIG_HH
#define _LINPHONE_PROXY_CONFIG_HH

#include <cstdint>
#include <string>
#include <list>
#include "enums.hh"
#include "object.hh"




struct _LinphoneProxyConfig;


namespace linphone {

	class Address;
	class Core;
	class ProxyConfig;
	class ErrorInfo;
	class NatPolicy;
	class AuthInfo;

	/**
	 * @brief The #ProxyConfig object represents a proxy configuration to be used by
	 * the #Core object. 
	 *
	 * Its fields must not be used directly in favour of the accessors methods. Once
	 * created and filled properly the #ProxyConfig can be given to #Core with
	 * Core::addProxyConfig(). This will automatically triggers the registration, if
	 * enabled.
	 * 
	 * The proxy configuration are persistent to restarts because they are saved in
	 * the configuration file. As a consequence, after linphone_core_new there might
	 * already be a list of configured proxy that can be examined with
	 * Core::getProxyConfigList().
	 * 
	 * The default proxy (see linphone_core_set_default_proxy ) is the one of the list
	 * that is used by default for calls. 
	 */
	class ProxyConfig: public Object {
	
		public:

			ProxyConfig(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneProxyConfig *cPtr() {return (_LinphoneProxyConfig *)mPrivPtr;}

	
		public:
			
		
			/**
			 * @brief Indicates whether AVPF/SAVPF is being used for calls using this proxy
			 * config. 
			 *
			 * @return True if AVPF/SAVPF is enabled, false otherwise. 
			 */
			LINPHONECXX_PUBLIC bool avpfEnabled();
			
			/**
			 * @brief Get enablement status of RTCP feedback (also known as AVPF profile). 
			 *
			 * @return the enablement mode, which can be LinphoneAVPFDefault (use
			 * LinphoneCore's mode), LinphoneAVPFEnabled (avpf is enabled), or
			 * LinphoneAVPFDisabled (disabled). 
			 */
			LINPHONECXX_PUBLIC linphone::AVPFMode getAvpfMode() const;
			
			/**
			 * @brief Enable the use of RTCP feedback (also known as AVPF profile). 
			 *
			 * @param mode the enablement mode, which can be LinphoneAVPFDefault (use
			 * LinphoneCore's mode), LinphoneAVPFEnabled (avpf is enabled), or
			 * LinphoneAVPFDisabled (disabled). 
			 */
			LINPHONECXX_PUBLIC void setAvpfMode(linphone::AVPFMode mode);
			
			/**
			 * @brief Get the interval between regular RTCP reports when using AVPF/SAVPF. 
			 *
			 * @return The interval in seconds. 
			 */
			LINPHONECXX_PUBLIC uint8_t getAvpfRrInterval() const;
			
			/**
			 * @brief Set the interval between regular RTCP reports when using AVPF/SAVPF. 
			 *
			 * @param interval The interval in seconds (between 0 and 5 seconds). 
			 */
			LINPHONECXX_PUBLIC void setAvpfRrInterval(uint8_t interval);
			
			/**
			 * @brief Get the conference factory uri. 
			 *
			 * @return The uri of the conference factory 
			 */
			LINPHONECXX_PUBLIC std::string getConferenceFactoryUri() const;
			
			/**
			 * @brief Set the conference factory uri. 
			 *
			 * @param uri The uri of the conference factory 
			 */
			LINPHONECXX_PUBLIC void setConferenceFactoryUri(const std::string & uri);
			
			/**
			 * @brief Return the contact address of the proxy config. 
			 *
			 * @return a #Address correspong to the contact address of the proxy config. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::Address> getContact() const;
			
			/**
			 *
			 * @return previously set contact parameters. 
			 */
			LINPHONECXX_PUBLIC std::string getContactParameters() const;
			
			/**
			 * @brief Set optional contact parameters that will be added to the contact
			 * information sent in the registration. 
			 *
			 * @param contactParams a string contaning the additional parameters in text form,
			 * like "myparam=something;myparam2=something_else"
			 * 
			 * The main use case for this function is provide the proxy additional information
			 * regarding the user agent, like for example unique identifier or apple push id.
			 * As an example, the contact address in the SIP register sent will look like
			 * <sip:joe@15.128.128.93:50421>;apple-push-id=43143-DFE23F-2323-FA2232. 
			 */
			LINPHONECXX_PUBLIC void setContactParameters(const std::string & contactParams);
			
			/**
			 *
			 * @return previously set contact URI parameters. 
			 */
			LINPHONECXX_PUBLIC std::string getContactUriParameters() const;
			
			/**
			 * @brief Set optional contact parameters that will be added to the contact
			 * information sent in the registration, inside the URI. 
			 *
			 * @param contactUriParams a string containing the additional parameters in text
			 * form, like "myparam=something;myparam2=something_else"
			 * 
			 * The main use case for this function is provide the proxy additional information
			 * regarding the user agent, like for example unique identifier or apple push id.
			 * As an example, the contact address in the SIP register sent will look like
			 * <sip:joe@15.128.128.93:50421;apple-push-id=43143-DFE23F-2323-FA2232>. 
			 */
			LINPHONECXX_PUBLIC void setContactUriParameters(const std::string & contactUriParams);
			
			/**
			 * @brief Get the #Core object to which is associated the #linphone::ProxyConfig. 
			 *
			 * @return The #Core object to which is associated the #linphone::ProxyConfig. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Core> getCore() const;
			
			/**
			 * @brief Get the dependency of a #linphone::ProxyConfig. 
			 *
			 * @return The proxy config this one is dependent upon, or nullptr if not marked
			 * dependent 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ProxyConfig> getDependency();
			
			/**
			 * @brief Mark this proxy configuration as being dependent on the given one. 
			 *
			 * The dependency must refer to a proxy config previously added to the core and
			 * which idkey property is defined.
			 * 
			 * @see setIdkey()
			 * 
			 * The proxy configuration marked as dependent will wait for successful
			 * registration on its dependency before triggering its own.
			 * 
			 * Once registered, both proxy configurations will share the same contact address
			 * (the 'dependency' one).
			 * 
			 * This mecanism must be enabled before the proxy configuration is added to the
			 * core
			 */
			LINPHONECXX_PUBLIC void setDependency(const std::shared_ptr<linphone::ProxyConfig> & dependency);
			
			/**
			 *
			 * @return whether liblinphone should replace "+" by "00" in dialed numbers
			 * (passed to linphone_core_invite ). 
			 */
			LINPHONECXX_PUBLIC bool getDialEscapePlus() const;
			
			/**
			 * @brief Sets whether liblinphone should replace "+" by international calling
			 * prefix in dialed numbers (passed to linphone_core_invite ). 
			 *
			 */
			LINPHONECXX_PUBLIC void setDialEscapePlus(bool val);
			
			/**
			 *
			 * @return dialing prefix. 
			 */
			LINPHONECXX_PUBLIC std::string getDialPrefix() const;
			
			/**
			 * @brief Sets a dialing prefix to be automatically prepended when inviting a
			 * number with Core::invite(); This dialing prefix shall usually be the country
			 * code of the country where the user is living, without "+". 
			 *
			 */
			LINPHONECXX_PUBLIC void setDialPrefix(const std::string & prefix);
			
			/**
			 * @brief Get the domain name of the given proxy config. 
			 *
			 * @return The domain name of the proxy config. 
			 */
			LINPHONECXX_PUBLIC std::string getDomain() const;
			
			/**
			 * @brief Get the reason why registration failed when the proxy config state is
			 * LinphoneRegistrationFailed. 
			 *
			 * @return The reason why registration failed for this proxy config. 
			 */
			LINPHONECXX_PUBLIC linphone::Reason getError() const;
			
			/**
			 * @brief Get detailed information why registration failed when the proxy config
			 * state is LinphoneRegistrationFailed. 
			 *
			 * @return The details why registration failed for this proxy config. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::ErrorInfo> getErrorInfo() const;
			
			/**
			 *
			 * @return the duration of registration. 
			 */
			LINPHONECXX_PUBLIC int getExpires() const;
			
			/**
			 * @brief Sets the registration expiration time in seconds. 
			 *
			 */
			LINPHONECXX_PUBLIC void setExpires(int expires);
			
			/**
			 *
			 * @return the SIP identity that belongs to this proxy configuration. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::Address> getIdentityAddress() const;
			
			/**
			 * @brief Sets the user identity as a SIP address. 
			 *
			 * This identity is normally formed with display name, username and domain, such
			 * as: Alice <sip:alice@example.net> The REGISTER messages will have from and to
			 * set to this identity. 
			 */
			LINPHONECXX_PUBLIC linphone::Status setIdentityAddress(const std::shared_ptr<const linphone::Address> & identity);
			
			/**
			 * @brief Get the idkey property of a #linphone::ProxyConfig. 
			 *
			 * @return The idkey string, or nullptr 
			 */
			LINPHONECXX_PUBLIC std::string getIdkey();
			
			/**
			 * @brief Set the idkey property on the given proxy configuration. 
			 *
			 * This property can the be referenced by another proxy config 'depends_on' to
			 * create a dependency relation between them. @see
			 * linphone_proxy_config_set_depends_on()
			 * 
			 * @param idkey The idkey string to associate to the given #linphone::ProxyConfig 
			 */
			LINPHONECXX_PUBLIC void setIdkey(const std::string & idkey);
			
			/**
			 * @brief Indicates whether to add to the contact parameters the push notification
			 * information. 
			 *
			 * @return True if push notification informations should be added, false
			 * otherwise. 
			 */
			LINPHONECXX_PUBLIC bool isPushNotificationAllowed() const;
			
			/**
			 * @brief Get The policy that is used to pass through NATs/firewalls when using
			 * this proxy config. 
			 *
			 * If it is set to nullptr, the default NAT policy from the core will be used
			 * instead. 
			 * 
			 * @return #NatPolicy object in use. 
			 * 
			 * @see Core::getNatPolicy() 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::NatPolicy> getNatPolicy() const;
			
			/**
			 * @brief Set the policy to use to pass through NATs/firewalls when using this
			 * proxy config. 
			 *
			 * If it is set to nullptr, the default NAT policy from the core will be used
			 * instead. 
			 * 
			 * @param policy #NatPolicy object 
			 * 
			 * @see Core::setNatPolicy() 
			 */
			LINPHONECXX_PUBLIC void setNatPolicy(const std::shared_ptr<linphone::NatPolicy> & policy);
			
			/**
			 * @brief Get default privacy policy for all calls routed through this proxy. 
			 *
			 * @return Privacy mode 
			 */
			LINPHONECXX_PUBLIC unsigned int getPrivacy() const;
			
			/**
			 * @brief Set default privacy policy for all calls routed through this proxy. 
			 *
			 * @param privacy LinphonePrivacy to configure privacy 
			 */
			LINPHONECXX_PUBLIC void setPrivacy(unsigned int privacy);
			
			/**
			 *
			 * @return  if PUBLISH request is enabled for this proxy. 
			 */
			LINPHONECXX_PUBLIC bool publishEnabled() const;
			
			/**
			 * @brief Indicates either or not, PUBLISH must be issued for this
			 * #linphone::ProxyConfig. 
			 *
			 * In case this #linphone::ProxyConfig has been added to #Core, follows the edit()
			 * rule. 
			 * 
			 * @param val if true, publish will be engaged 
			 */
			LINPHONECXX_PUBLIC void enablePublish(bool val);
			
			/**
			 * @brief get the publish expiration time in second. 
			 *
			 * Default value is the registration expiration value. 
			 * 
			 * @return expires in second 
			 */
			LINPHONECXX_PUBLIC int getPublishExpires() const;
			
			/**
			 * @brief Set the publish expiration time in second. 
			 *
			 * @param expires in second 
			 */
			LINPHONECXX_PUBLIC void setPublishExpires(int expires);
			
			/**
			 * @brief Indicates whether to add to the contact parameters the push notification
			 * information. 
			 *
			 * @param allow True to allow push notification information, false otherwise. 
			 */
			LINPHONECXX_PUBLIC void setPushNotificationAllowed(bool allow);
			
			/**
			 * @brief Get the route of the collector end-point when using quality reporting. 
			 *
			 * This SIP address should be used on server-side to process packets directly
			 * before discarding packets. Collector address should be a non existing account
			 * and will not receive any messages. If nullptr, reports will be send to the
			 * proxy domain. 
			 * 
			 * @return The SIP address of the collector end-point. 
			 */
			LINPHONECXX_PUBLIC std::string getQualityReportingCollector() const;
			
			/**
			 * @brief Set the route of the collector end-point when using quality reporting. 
			 *
			 * This SIP address should be used on server-side to process packets directly
			 * before discarding packets. Collector address should be a non existing account
			 * and will not receive any messages. If nullptr, reports will be send to the
			 * proxy domain. 
			 * 
			 * @param collector route of the collector end-point, if nullptr PUBLISH will be
			 * sent to the proxy domain. 
			 */
			LINPHONECXX_PUBLIC void setQualityReportingCollector(const std::string & collector);
			
			/**
			 * @brief Indicates whether quality statistics during call should be stored and
			 * sent to a collector according to RFC 6035. 
			 *
			 * @return True if quality repotring is enabled, false otherwise. 
			 */
			LINPHONECXX_PUBLIC bool qualityReportingEnabled();
			
			/**
			 * @brief Indicates whether quality statistics during call should be stored and
			 * sent to a collector according to RFC 6035. 
			 *
			 * @param enable True to store quality statistics and send them to the collector,
			 * false to disable it. 
			 */
			LINPHONECXX_PUBLIC void enableQualityReporting(bool enable);
			
			/**
			 * @brief Get the interval between interval reports when using quality reporting. 
			 *
			 * @return The interval in seconds, 0 means interval reports are disabled. 
			 */
			LINPHONECXX_PUBLIC int getQualityReportingInterval();
			
			/**
			 * @brief Set the interval between 2 interval reports sending when using quality
			 * reporting. 
			 *
			 * If call exceed interval size, an interval report will be sent to the collector.
			 * On call termination, a session report will be sent for the remaining period.
			 * Value must be 0 (disabled) or positive. 
			 * 
			 * @param interval The interval in seconds, 0 means interval reports are disabled. 
			 */
			LINPHONECXX_PUBLIC void setQualityReportingInterval(int interval);
			
			/**
			 * @brief Get the realm of the given proxy config. 
			 *
			 * @return The realm of the proxy config. 
			 */
			LINPHONECXX_PUBLIC std::string getRealm() const;
			
			/**
			 * @brief Set the realm of the given proxy config. 
			 *
			 * @param realm New realm value. 
			 */
			LINPHONECXX_PUBLIC void setRealm(const std::string & realm);
			
			/**
			 * @brief Get the persistent reference key associated to the proxy config. 
			 *
			 * The reference key can be for example an id to an external database. It is
			 * stored in the config file, thus can survive to process exits/restarts.
			 * 
			 * @return The reference key string that has been associated to the proxy config,
			 * or nullptr if none has been associated. 
			 */
			LINPHONECXX_PUBLIC std::string getRefKey() const;
			
			/**
			 * @brief Associate a persistent reference key to the proxy config. 
			 *
			 * The reference key can be for example an id to an external database. It is
			 * stored in the config file, thus can survive to process exits/restarts.
			 * 
			 * @param refkey The reference key string to associate to the proxy config. 
			 */
			LINPHONECXX_PUBLIC void setRefKey(const std::string & refkey);
			
			/**
			 *
			 * @return  if registration to the proxy is enabled. 
			 */
			LINPHONECXX_PUBLIC bool registerEnabled() const;
			
			/**
			 * @brief Indicates either or not, REGISTRATION must be issued for this
			 * #linphone::ProxyConfig. 
			 *
			 * In case this #linphone::ProxyConfig has been added to #Core, follows the edit()
			 * rule. 
			 * 
			 * @param val if true, registration will be engaged 
			 */
			LINPHONECXX_PUBLIC void enableRegister(bool val);
			
			/**
			 *
			 * @return the route set for this proxy configuration. 
			 * 
			 * @deprecated Use getRoutes() instead. 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED std::string getRoute() const;
			
			/**
			 * @brief Sets a SIP route. 
			 *
			 * When a route is set, all outgoing calls will go to the route's destination if
			 * this proxy is the default one (see linphone_core_set_default_proxy ). @return
			 * -1 if route is invalid, 0 otherwise. 
			 */
			LINPHONECXX_PUBLIC linphone::Status setRoute(const std::string & route);
			
			/**
			 * @brief Gets the list of the routes set for this proxy config. 
			 *
			 * @return A list of const char * objects. const char *  the list of routes. 
			 */
			LINPHONECXX_PUBLIC std::list<std::string> getRoutes() const;
			
			/**
			 * @brief Sets a list of SIP route. 
			 *
			 * When a route is set, all outgoing calls will go to the route's destination if
			 * this proxy is the default one (see linphone_core_set_default_proxy ). 
			 * 
			 * @param routes A A list of const char * objects. const char *  of routes 
			 * 
			 * @return -1 if routes are invalid, 0 otherwise. 
			 */
			LINPHONECXX_PUBLIC linphone::Status setRoutes(const std::list<std::string> & routes);
			
			/**
			 *
			 * @return the proxy's SIP address. 
			 */
			LINPHONECXX_PUBLIC std::string getServerAddr() const;
			
			/**
			 * @brief Sets the proxy address. 
			 *
			 * Examples of valid sip proxy address are:
			 * 
			 */
			LINPHONECXX_PUBLIC linphone::Status setServerAddr(const std::string & serverAddr);
			
			/**
			 * @brief Get the registration state of the given proxy config. 
			 *
			 * @return The registration state of the proxy config. 
			 */
			LINPHONECXX_PUBLIC linphone::RegistrationState getState() const;
			
			/**
			 * @brief Get the transport from either service route, route or addr. 
			 *
			 * @return The transport as a string (I.E udp, tcp, tls, dtls) 
			 */
			LINPHONECXX_PUBLIC std::string getTransport() const;
			
			/**
			 * @brief Return the unread chat message count for a given proxy config. 
			 *
			 * @return The unread chat message count. 
			 */
			LINPHONECXX_PUBLIC int getUnreadChatMessageCount() const;
			
			/**
			 * @brief Commits modification made to the proxy configuration. 
			 *
			 */
			LINPHONECXX_PUBLIC linphone::Status done();
			
			/**
			 * @brief Starts editing a proxy configuration. 
			 *
			 * Because proxy configuration must be consistent, applications MUST call edit()
			 * before doing any attempts to modify proxy configuration (such as identity,
			 * proxy address and so on). Once the modifications are done, then the application
			 * must call done() to commit the changes. 
			 */
			LINPHONECXX_PUBLIC void edit();
			
			/**
			 * @brief Find authentication info matching proxy config, if any, similarly to
			 * linphone_core_find_auth_info. 
			 *
			 * @return a #AuthInfo matching proxy config criteria if possible, nullptr if
			 * nothing can be found. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::AuthInfo> findAuthInfo() const;
			
			/**
			 * @brief Obtain the value of a header sent by the server in last answer to
			 * REGISTER. 
			 *
			 * @param headerName the header name for which to fetch corresponding value 
			 * 
			 * @return the value of the queried header. 
			 */
			LINPHONECXX_PUBLIC std::string getCustomHeader(const std::string & headerName);
			
			/**
			 * @brief Detect if the given input is a phone number or not. 
			 *
			 * @param username string to parse. 
			 * 
			 * @return  if input is a phone number, true otherwise. 
			 */
			LINPHONECXX_PUBLIC bool isPhoneNumber(const std::string & username);
			
			/**
			 * @brief Normalize a human readable phone number into a basic string. 
			 *
			 * 888-444-222 becomes 888444222 or +33888444222 depending on the
			 * #linphone::ProxyConfig object. This function will always generate a normalized
			 * username if input is a phone number. 
			 * 
			 * @param username the string to parse 
			 * 
			 * @return  if input is an invalid phone number, normalized phone number from
			 * username input otherwise. 
			 */
			LINPHONECXX_PUBLIC std::string normalizePhoneNumber(const std::string & username);
			
			/**
			 * @brief Normalize a human readable sip uri into a fully qualified
			 * LinphoneAddress. 
			 *
			 * A sip address should look like DisplayName <sip:username@domain:port> .
			 * Basically this function performs the following tasks
			 * 
			 * 
			 * The result is a syntactically correct SIP address. 
			 * 
			 * @param username the string to parse 
			 * 
			 * @return  if invalid input, normalized sip address otherwise. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Address> normalizeSipUri(const std::string & username);
			
			/**
			 * @brief Prevent a proxy config from refreshing its registration. 
			 *
			 * This is useful to let registrations to expire naturally (or) when the
			 * application wants to keep control on when refreshes are sent. However,
			 * linphone_core_set_network_reachable(lc,true) will always request the proxy
			 * configs to refresh their registrations. The refreshing operations can be
			 * resumed with refreshRegister(). 
			 */
			LINPHONECXX_PUBLIC void pauseRegister();
			
			/**
			 * @brief Refresh a proxy registration. 
			 *
			 * This is useful if for example you resuming from suspend, thus IP address may
			 * have changed. 
			 */
			LINPHONECXX_PUBLIC void refreshRegister();
			
			/**
			 * @brief Set the value of a custom header sent to the server in REGISTERs
			 * request. 
			 *
			 * @param headerValue the header's value 
			 */
			LINPHONECXX_PUBLIC void setCustomHeader(const std::string & headerName, const std::string & headerValue);
			
			
	};

};

#endif // _LINPHONE_PROXY_CONFIG_HH
