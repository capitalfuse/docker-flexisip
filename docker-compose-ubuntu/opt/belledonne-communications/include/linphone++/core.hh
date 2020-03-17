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

#ifndef _LINPHONE_CORE_HH
#define _LINPHONE_CORE_HH

#include <string>
#include <list>
#include "enums.hh"
#include "call.hh"
#include "presence_activity.hh"
#include "object.hh"




struct _LinphoneCore;


namespace linphone {

	class PayloadType;
	class Range;
	class AuthInfo;
	class CallLog;
	class Call;
	class ChatRoom;
	class Conference;
	class Config;
	class Address;
	class VideoDefinition;
	class FriendList;
	class ProxyConfig;
	class ImNotifPolicy;
	class NatPolicy;
	class PresenceModel;
	class Transports;
	class Tunnel;
	class VideoActivationPolicy;
	class CallParams;
	class Friend;
	class AccountCreator;
	class ChatRoomParams;
	class ConferenceParams;
	class Content;
	class InfoMessage;
	class Player;
	class MagicSearch;
	class Event;
	class PresenceActivity;
	class PresenceNote;
	class PresencePerson;
	class PresenceService;
	class XmlRpcSession;
	class CoreListener;

	/**
	 * @brief Linphone core main object created by function linphone_core_new . 
	 *
	 */
	class Core: public MultiListenableObject {
		friend class Factory;
	
		public:
			/**
			* LinphoneCoreLogCollectionUploadState is used to notify if log collection upload
			* have been succesfully delivered or not. 
			*
			*/
			enum class LogCollectionUploadState {
				/**
				* Delivery in progress. 
				*/
				InProgress,
				/**
				* Log collection upload successfully delivered and acknowledged by remote end
				* point. 
				*/
				Delivered,
				/**
				* Log collection upload was not delivered. 
				*/
				NotDelivered
			};


			Core(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneCore *cPtr() {return (_LinphoneCore *)mPrivPtr;}

			LINPHONECXX_PUBLIC void addListener(const std::shared_ptr<CoreListener> &listener);
			LINPHONECXX_PUBLIC void removeListener(const std::shared_ptr<CoreListener> &listener);
	
		public:
			
		
			/**
			 * @brief Returns which adaptive rate algorithm is currently configured for future
			 * calls. 
			 *
			 * @see setAdaptiveRateAlgorithm() 
			 */
			LINPHONECXX_PUBLIC std::string getAdaptiveRateAlgorithm() const;
			
			/**
			 * @brief Sets adaptive rate algorithm. 
			 *
			 * It will be used for each new calls starting from now. Calls already started
			 * will not be updated. 
			 * 
			 * @param algorithm the adaptive rate control algorithm. Currently two values are
			 * supported: 'advanced', which is the default value, or 'basic'. 
			 */
			LINPHONECXX_PUBLIC void setAdaptiveRateAlgorithm(const std::string & algorithm);
			
			/**
			 * @brief Returns whether adaptive rate control is enabled. 
			 *
			 * @see enableAdaptiveRateControl() 
			 */
			LINPHONECXX_PUBLIC bool adaptiveRateControlEnabled() const;
			
			/**
			 * @brief Enable adaptive rate control. 
			 *
			 * Adaptive rate control consists in using RTCP feedback provided information to
			 * dynamically control the output bitrate of the audio and video encoders, so that
			 * we can adapt to the network conditions and available bandwidth. Control of the
			 * audio encoder is done in case of audio-only call, and control of the video
			 * encoder is done for audio & video calls. Adaptive rate control feature is
			 * enabled by default. 
			 */
			LINPHONECXX_PUBLIC void enableAdaptiveRateControl(bool enabled);
			
			/**
			 * @brief Tells whether the audio adaptive jitter compensation is enabled. 
			 *
			 * @return  if the audio adaptive jitter compensation is enabled, true otherwise. 
			 */
			LINPHONECXX_PUBLIC bool audioAdaptiveJittcompEnabled();
			
			/**
			 * @brief Enable or disable the audio adaptive jitter compensation. 
			 *
			 * @param enable  to enable the audio adaptive jitter compensation, true to
			 * disable it. 
			 */
			LINPHONECXX_PUBLIC void enableAudioAdaptiveJittcomp(bool enable);
			
			/**
			 * @brief Get the DSCP field for outgoing audio streams. 
			 *
			 * The DSCP defines the quality of service in IP packets. 
			 * 
			 * @return The current DSCP value 
			 */
			LINPHONECXX_PUBLIC int getAudioDscp() const;
			
			/**
			 * @brief Set the DSCP field for outgoing audio streams. 
			 *
			 * The DSCP defines the quality of service in IP packets. 
			 * 
			 * @param dscp The DSCP value to set 
			 */
			LINPHONECXX_PUBLIC void setAudioDscp(int dscp);
			
			/**
			 * @brief Returns the nominal audio jitter buffer size in milliseconds. 
			 *
			 * @return The nominal audio jitter buffer size in milliseconds 
			 */
			LINPHONECXX_PUBLIC int getAudioJittcomp();
			
			/**
			 * @brief Sets the nominal audio jitter buffer size in milliseconds. 
			 *
			 * The value takes effect immediately for all running and pending calls, if any. A
			 * value of 0 disables the jitter buffer. 
			 */
			LINPHONECXX_PUBLIC void setAudioJittcomp(int milliseconds);
			
			/**
			 * @brief Use to get multicast address to be used for audio stream. 
			 *
			 * @return an ipv4/6 multicast address or default value 
			 */
			LINPHONECXX_PUBLIC std::string getAudioMulticastAddr() const;
			
			/**
			 * @brief Use to set multicast address to be used for audio stream. 
			 *
			 * @param ip an ipv4/6 multicast address 
			 * 
			 * @return 0 in case of success 
			 */
			LINPHONECXX_PUBLIC linphone::Status setAudioMulticastAddr(const std::string & ip);
			
			/**
			 * @brief Use to get multicast state of audio stream. 
			 *
			 * @return true if subsequent calls will propose multicast ip set by
			 * linphone_core_set_audio_multicast_addr 
			 */
			LINPHONECXX_PUBLIC bool audioMulticastEnabled() const;
			
			/**
			 * @brief Use to enable multicast rtp for audio stream. 
			 *
			 * If enabled, outgoing calls put a multicast address from
			 * linphone_core_get_video_multicast_addr into audio cline. In case of outgoing
			 * call audio stream is sent to this multicast address. For incoming calls
			 * behavior is unchanged. 
			 * 
			 * @param yesno if yes, subsequent calls will propose multicast ip set by
			 * linphone_core_set_audio_multicast_addr 
			 */
			LINPHONECXX_PUBLIC void enableAudioMulticast(bool yesno);
			
			/**
			 * @brief Use to get multicast ttl to be used for audio stream. 
			 *
			 * @return a time to leave value 
			 */
			LINPHONECXX_PUBLIC int getAudioMulticastTtl() const;
			
			/**
			 * @brief Use to set multicast ttl to be used for audio stream. 
			 *
			 * @param ttl value or -1 if not used. [0..255] default value is 1 
			 * 
			 * @return 0 in case of success 
			 */
			LINPHONECXX_PUBLIC linphone::Status setAudioMulticastTtl(int ttl);
			
			/**
			 * @brief Return the list of the available audio payload types. 
			 *
			 * @return A list of #PayloadType objects. LinphonePayloadType  A freshly
			 * allocated list of the available payload types. The list must be destroyed with
			 * bctbx_list_free() after usage. The elements of the list haven't to be unref. 
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::PayloadType>> getAudioPayloadTypes();
			
			/**
			 * @brief Redefine the list of the available payload types. 
			 *
			 * @param payloadTypes A list of #PayloadType objects. LinphonePayloadType  The
			 * new list of payload types. The core does not take ownership on it. 
			 */
			LINPHONECXX_PUBLIC void setAudioPayloadTypes(const std::list<std::shared_ptr<linphone::PayloadType>> & payloadTypes);
			
			/**
			 * @brief Gets the UDP port used for audio streaming. 
			 *
			 * @return The UDP port used for audio streaming 
			 */
			LINPHONECXX_PUBLIC int getAudioPort() const;
			
			/**
			 * @brief Sets the UDP port used for audio streaming. 
			 *
			 * A value of -1 will request the system to allocate the local port randomly. This
			 * is recommended in order to avoid firewall warnings. 
			 * 
			 * @param port The UDP port to use for audio streaming 
			 */
			LINPHONECXX_PUBLIC void setAudioPort(int port);
			
			/**
			 * @brief Get the audio port range from which is randomly chosen the UDP port used
			 * for audio streaming. 
			 *
			 * @return a #Range object 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Range> getAudioPortsRange() const;
			
			/**
			 * @brief Returns an unmodifiable list of currently entered #AuthInfo. 
			 *
			 * @return A list of #AuthInfo objects. LinphoneAuthInfo  
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::AuthInfo>> getAuthInfoList() const;
			
			/**
			 * @brief Return AVPF enablement. 
			 *
			 * See setAvpfMode() . 
			 * 
			 * @return The current AVPF mode 
			 */
			LINPHONECXX_PUBLIC linphone::AVPFMode getAvpfMode() const;
			
			/**
			 * @brief Enable RTCP feedback (also known as RTP/AVPF profile). 
			 *
			 * Setting LinphoneAVPFDefault is equivalent to LinphoneAVPFDisabled. This setting
			 * can be overriden per #ProxyConfig with ProxyConfig::setAvpfMode(). The value
			 * set here is used for calls placed or received out of any proxy configured, or
			 * if the proxy config is configured with LinphoneAVPFDefault. 
			 * 
			 * @param mode The AVPF mode to use. 
			 */
			LINPHONECXX_PUBLIC void setAvpfMode(linphone::AVPFMode mode);
			
			/**
			 * @brief Return the avpf report interval in seconds. 
			 *
			 * @return The current AVPF report interval in seconds 
			 */
			LINPHONECXX_PUBLIC int getAvpfRrInterval() const;
			
			/**
			 * @brief Set the avpf report interval in seconds. 
			 *
			 * This value can be overriden by the proxy config using
			 * ProxyConfig::setAvpfRrInterval(). 
			 * 
			 * @param interval The report interval in seconds 
			 */
			LINPHONECXX_PUBLIC void setAvpfRrInterval(int interval);
			
			/**
			 * @brief Get the list of call logs (past calls). 
			 *
			 * @return A list of #CallLog objects. LinphoneCallLog  
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::CallLog>> getCallLogs();
			
			/**
			 * @brief Gets the database filename where call logs will be stored. 
			 *
			 * @return filesystem path 
			 */
			LINPHONECXX_PUBLIC std::string getCallLogsDatabasePath();
			
			/**
			 * @brief Sets the database filename where call logs will be stored. 
			 *
			 * If the file does not exist, it will be created.
			 * 
			 * @param path filesystem path 
			 */
			LINPHONECXX_PUBLIC void setCallLogsDatabasePath(const std::string & path);
			
			/**
			 * @brief Gets the current list of calls. 
			 *
			 * Note that this list is read-only and might be changed by the core after a
			 * function call to iterate(). Similarly the #Call objects inside it might be
			 * destroyed without prior notice. To hold references to #Call object into your
			 * program, you must use linphone_call_ref. 
			 * 
			 * @return A list of #Call objects. LinphoneCall  
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::Call>> getCalls();
			
			/**
			 * @brief Get the number of Call. 
			 *
			 * @return The current number of calls 
			 */
			LINPHONECXX_PUBLIC int getCallsNb() const;
			
			/**
			 * @brief Get the camera sensor rotation. 
			 *
			 * This is needed on some mobile platforms to get the number of degrees the camera
			 * sensor is rotated relative to the screen. 
			 * 
			 * @return The camera sensor rotation in degrees (0 to 360) or -1 if it could not
			 * be retrieved 
			 */
			LINPHONECXX_PUBLIC int getCameraSensorRotation();
			
			/**
			 * @brief Gets the name of the currently assigned sound device for capture. 
			 *
			 * @return The name of the currently assigned sound device for capture 
			 */
			LINPHONECXX_PUBLIC std::string getCaptureDevice();
			
			/**
			 * @brief Sets the sound device used for capture. 
			 *
			 * @param devid The device name as returned by linphone_core_get_sound_devices 
			 * 
			 * @return 0 
			 */
			LINPHONECXX_PUBLIC linphone::Status setCaptureDevice(const std::string & devid);
			
			/**
			 * @brief Get path to the database file used for storing chat messages. 
			 *
			 * @return file path or nullptr if not exist 
			 * 
			 * @deprecated 2018-01-10 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED std::string getChatDatabasePath() const;
			
			/**
			 * @brief Set the chat database path. 
			 *
			 * @param path the database path 
			 * 
			 * @deprecated 2018-01-10: Use only for migration purposes 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED void setChatDatabasePath(const std::string & path);
			
			/**
			 * @brief Returns whether chat is enabled. 
			 *
			 */
			LINPHONECXX_PUBLIC bool chatEnabled() const;
			
			/**
			 * @brief Returns an list of chat rooms. 
			 *
			 * @return A list of #ChatRoom objects. LinphoneChatRoom  
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::ChatRoom>> getChatRooms();
			
			/**
			 * @brief Get a pointer on the internal conference object. 
			 *
			 * @return A pointer on #Conference or nullptr if no conference are going on 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Conference> getConference();
			
			/**
			 * @brief Get the set input volume of the local participant. 
			 *
			 * @return A value inside [0.0 ; 1.0] 
			 */
			LINPHONECXX_PUBLIC float getConferenceLocalInputVolume();
			
			/**
			 * @brief Tells whether the conference server feature is enabled. 
			 *
			 * @return A boolean value telling whether the conference server feature is
			 * enabled or not 
			 */
			LINPHONECXX_PUBLIC bool conferenceServerEnabled() const;
			
			/**
			 * @brief Enable the conference server feature. 
			 *
			 * This has the effect to listen of the conference factory uri to create new
			 * conferences when receiving INVITE messages there. 
			 * 
			 * @param enable A boolean value telling whether to enable or disable the
			 * conference server feature 
			 */
			LINPHONECXX_PUBLIC void enableConferenceServer(bool enable);
			
			/**
			 * @brief Get the number of participant in the running conference. 
			 *
			 * The local participant is included in the count only if it is in the conference. 
			 * 
			 * @return The number of participant 
			 */
			LINPHONECXX_PUBLIC int getConferenceSize();
			
			/**
			 * @brief Returns the LpConfig object used to manage the storage (config) file. 
			 *
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Config> getConfig() const;
			
			/**
			 * @brief Get my consolidated presence. 
			 *
			 * @return My consolidated presence 
			 */
			LINPHONECXX_PUBLIC linphone::ConsolidatedPresence getConsolidatedPresence() const;
			
			/**
			 * @brief Set my consolidated presence. 
			 *
			 * @param presence LinphoneConsolidatedPresence value 
			 */
			LINPHONECXX_PUBLIC void setConsolidatedPresence(linphone::ConsolidatedPresence presence);
			
			/**
			 * @brief Gets the current call. 
			 *
			 * @return The current call or nullptr if no call is running 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Call> getCurrentCall() const;
			
			/**
			 * @brief Get the remote address of the current call. 
			 *
			 * @return The remote address of the current call or nullptr if there is no
			 * current call. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::Address> getCurrentCallRemoteAddress();
			
			/**
			 * @brief Get the effective video definition provided by the camera for the
			 * captured video. 
			 *
			 * When preview is disabled or not yet started this function returns a 0x0 video
			 * definition. 
			 * 
			 * @return The captured #VideoDefinition
			 * 
			 * @see setPreviewVideoDefinition() 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::VideoDefinition> getCurrentPreviewVideoDefinition() const;
			
			/**
			 * @brief Retrieves the first list of #Friend from the core. 
			 *
			 * @return the first #FriendList object or nullptr 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::FriendList> getDefaultFriendList() const;
			
			/**
			 *
			 * @return the default proxy configuration, that is the one used to determine the
			 * current identity. 
			 * 
			 * @return The default proxy configuration. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ProxyConfig> getDefaultProxyConfig() const;
			
			/**
			 * @brief Sets the default proxy. 
			 *
			 * This default proxy must be part of the list of already entered
			 * LinphoneProxyConfig. Toggling it as default will make #linphone::Core use the
			 * identity associated with the proxy configuration in all incoming and outgoing
			 * calls. 
			 * 
			 * @param config The proxy configuration to use as the default one. 
			 */
			LINPHONECXX_PUBLIC void setDefaultProxyConfig(const std::shared_ptr<linphone::ProxyConfig> & config);
			
			/**
			 * @brief Get the name of the default mediastreamer2 filter used for rendering
			 * video on the current platform. 
			 *
			 * This is for advanced users of the library, mainly to expose mediastreamer video
			 * filter name and status. 
			 * 
			 * @return The default video display filter 
			 */
			LINPHONECXX_PUBLIC std::string getDefaultVideoDisplayFilter();
			
			/**
			 * @brief Gets the delayed timeout See setDelayedTimeout() for details. 
			 *
			 * @return The current delayed timeout in seconds 
			 */
			LINPHONECXX_PUBLIC int getDelayedTimeout();
			
			/**
			 * @brief Set the in delayed timeout in seconds. 
			 *
			 * After this timeout period, a delayed call (internal call initialisation or
			 * resolution) is resumed. 
			 * 
			 * @param seconds The new delayed timeout 
			 */
			LINPHONECXX_PUBLIC void setDelayedTimeout(int seconds);
			
			/**
			 * @brief Gets the current device orientation. 
			 *
			 * @return The current device orientation
			 * 
			 * @see setDeviceRotation() 
			 */
			LINPHONECXX_PUBLIC int getDeviceRotation();
			
			/**
			 * @brief Tells the core the device current orientation. 
			 *
			 * This can be used by capture filters on mobile devices to select between
			 * portrait/landscape mode and to produce properly oriented images. The exact
			 * meaning of the value in rotation if left to each device specific
			 * implementations. IOS supported values are 0 for UIInterfaceOrientationPortrait
			 * and 270 for UIInterfaceOrientationLandscapeRight. 
			 * 
			 * @param rotation The orientation to use 
			 */
			LINPHONECXX_PUBLIC void setDeviceRotation(int rotation);
			
			/**
			 * @brief Tells whether DNS search (use of local domain if the fully qualified
			 * name did return results) is enabled. 
			 *
			 * @return  if DNS search is enabled, true if disabled. 
			 */
			LINPHONECXX_PUBLIC bool dnsSearchEnabled() const;
			
			/**
			 * @brief Enable or disable DNS search (use of local domain if the fully qualified
			 * name did return results). 
			 *
			 * @param enable  to enable DNS search, true to disable it. 
			 */
			LINPHONECXX_PUBLIC void enableDnsSearch(bool enable);
			
			/**
			 * @brief Forces liblinphone to use the supplied list of dns servers, instead of
			 * system's ones. 
			 *
			 * @param servers A list of const char * objects. const char *  A list of strings
			 * containing the IP addresses of DNS servers to be used. Setting to nullptr
			 * restores default behaviour, which is to use the DNS server list provided by the
			 * system. The list is copied internally. 
			 */
			LINPHONECXX_PUBLIC void setDnsServers(const std::list<std::string> & servers);
			
			/**
			 * @brief Forces liblinphone to use the supplied list of dns servers, instead of
			 * system's ones and set dns_set_by_app at true or false according to value of
			 * servers list. 
			 *
			 * @param servers A list of const char * objects. const char *  A list of strings
			 * containing the IP addresses of DNS servers to be used. Setting to nullptr
			 * restores default behaviour, which is to use the DNS server list provided by the
			 * system. The list is copied internally. 
			 */
			LINPHONECXX_PUBLIC void setDnsServersApp(const std::list<std::string> & servers);
			
			/**
			 * @brief Tells if the DNS was set by an application. 
			 *
			 * @return  if DNS was set by app, true otherwise. 
			 */
			LINPHONECXX_PUBLIC bool getDnsSetByApp();
			
			/**
			 * @brief Tells whether DNS SRV resolution is enabled. 
			 *
			 * @return  if DNS SRV resolution is enabled, true if disabled. 
			 */
			LINPHONECXX_PUBLIC bool dnsSrvEnabled() const;
			
			/**
			 * @brief Enable or disable DNS SRV resolution. 
			 *
			 * @param enable  to enable DNS SRV resolution, true to disable it. 
			 */
			LINPHONECXX_PUBLIC void enableDnsSrv(bool enable);
			
			/**
			 * @brief Retrieve the maximum available download bandwidth. 
			 *
			 * This value was set by setDownloadBandwidth(). 
			 */
			LINPHONECXX_PUBLIC int getDownloadBandwidth() const;
			
			/**
			 * @brief Sets maximum available download bandwidth This is IP bandwidth, in
			 * kbit/s. 
			 *
			 * This information is used signaled to other parties during calls (within SDP
			 * messages) so that the remote end can have sufficient knowledge to properly
			 * configure its audio & video codec output bitrate to not overflow available
			 * bandwidth.
			 * 
			 * @param bw the bandwidth in kbits/s, 0 for infinite 
			 */
			LINPHONECXX_PUBLIC void setDownloadBandwidth(int bw);
			
			/**
			 * @brief Get audio packetization time linphone expects to receive from peer. 
			 *
			 * A value of zero means that ptime is not specified. 
			 */
			LINPHONECXX_PUBLIC int getDownloadPtime();
			
			/**
			 * @brief Set audio packetization time linphone expects to receive from peer. 
			 *
			 * A value of zero means that ptime is not specified. 
			 */
			LINPHONECXX_PUBLIC void setDownloadPtime(int ptime);
			
			/**
			 * @brief Returns true if echo cancellation is enabled. 
			 *
			 * @return A boolean value telling whether echo cancellation is enabled or
			 * disabled 
			 */
			LINPHONECXX_PUBLIC bool echoCancellationEnabled() const;
			
			/**
			 * @brief Enables or disable echo cancellation. 
			 *
			 * Value is saved and used for subsequent calls. This actually controls software
			 * echo cancellation. If hardware echo cancellation is available, it will be
			 * always used and activated for calls, regardless of the value passed to this
			 * function. When hardware echo cancellation is available, the software one is of
			 * course not activated. 
			 * 
			 * @param val A boolean value telling whether echo cancellation is to be enabled
			 * or disabled. 
			 */
			LINPHONECXX_PUBLIC void enableEchoCancellation(bool val);
			
			/**
			 * @brief Get the name of the mediastreamer2 filter used for echo cancelling. 
			 *
			 * @return The name of the mediastreamer2 filter used for echo cancelling 
			 */
			LINPHONECXX_PUBLIC std::string getEchoCancellerFilterName() const;
			
			/**
			 * @brief Set the name of the mediastreamer2 filter to be used for echo
			 * cancelling. 
			 *
			 * This is for advanced users of the library. 
			 * 
			 * @param filtername The name of the mediastreamer2 filter to be used for echo
			 * cancelling 
			 */
			LINPHONECXX_PUBLIC void setEchoCancellerFilterName(const std::string & filtername);
			
			/**
			 * @brief Tells whether echo limiter is enabled. 
			 *
			 * @return  if the echo limiter is enabled, true otherwise. 
			 */
			LINPHONECXX_PUBLIC bool echoLimiterEnabled() const;
			
			/**
			 * @brief Enables or disable echo limiter. 
			 *
			 * @param val  to enable echo limiter, true to disable it. 
			 */
			LINPHONECXX_PUBLIC void enableEchoLimiter(bool val);
			
			/**
			 * @brief Sets expected available upload bandwidth This is IP bandwidth, in
			 * kbit/s. 
			 *
			 * This information is used by liblinphone together with remote side available
			 * bandwidth signaled in SDP messages to properly configure audio & video codec's
			 * output bitrate.
			 * 
			 * @param bw the bandwidth in kbits/s, 0 for infinite 
			 */
			LINPHONECXX_PUBLIC void setExpectedBandwidth(int bw);
			
			/**
			 * @brief Get the globaly set http file transfer server to be used for content
			 * type application/vnd.gsma.rcs-ft-http+xml. 
			 *
			 * @return URL of the file server like https://file.linphone.org/upload.php 
			 */
			LINPHONECXX_PUBLIC std::string getFileTransferServer();
			
			/**
			 * @brief Globaly set an http file transfer server to be used for content type
			 * application/vnd.gsma.rcs-ft-http+xml. 
			 *
			 * This value can also be set for a dedicated account using
			 * linphone_proxy_config_set_file_transfer_server 
			 * 
			 * @param serverUrl URL of the file server like
			 * https://file.linphone.org/upload.php 
			 */
			LINPHONECXX_PUBLIC void setFileTransferServer(const std::string & serverUrl);
			
			/**
			 * @brief Sets whether or not to start friend lists subscription when in
			 * foreground. 
			 *
			 * @param enable whether or not to enable the feature 
			 */
			LINPHONECXX_PUBLIC void enableFriendListSubscription(bool enable);
			
			/**
			 * @brief Gets the database filename where friends will be stored. 
			 *
			 * @return filesystem path 
			 */
			LINPHONECXX_PUBLIC std::string getFriendsDatabasePath();
			
			/**
			 * @brief Sets the database filename where friends will be stored. 
			 *
			 * If the file does not exist, it will be created.
			 * 
			 * @param path filesystem path 
			 */
			LINPHONECXX_PUBLIC void setFriendsDatabasePath(const std::string & path);
			
			/**
			 * @brief Retrieves the list of #FriendList from the core. 
			 *
			 * @return A list of #FriendList objects. LinphoneFriendList  a list of
			 * #FriendList 
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::FriendList>> getFriendsLists() const;
			
			/**
			 * @brief Returns true if hostname part of primary contact is guessed
			 * automatically. 
			 *
			 */
			LINPHONECXX_PUBLIC bool getGuessHostname();
			
			/**
			 * @brief Tells #linphone::Core to guess local hostname automatically in primary
			 * contact. 
			 *
			 */
			LINPHONECXX_PUBLIC void setGuessHostname(bool val);
			
			/**
			 * @brief Get http proxy address to be used for signaling. 
			 *
			 * @return hostname of IP adress of the http proxy (can be nullptr to disable). 
			 */
			LINPHONECXX_PUBLIC std::string getHttpProxyHost() const;
			
			/**
			 * @brief Set http proxy address to be used for signaling during next channel
			 * connection. 
			 *
			 * Use linphone_core_set_network_reachable FASLE/true to force channel restart. 
			 * 
			 * @param host Hostname of IP adress of the http proxy (can be nullptr to
			 * disable). 
			 */
			LINPHONECXX_PUBLIC void setHttpProxyHost(const std::string & host);
			
			/**
			 * @brief Get http proxy port to be used for signaling. 
			 *
			 * @return port of the http proxy. 
			 */
			LINPHONECXX_PUBLIC int getHttpProxyPort() const;
			
			/**
			 * @brief Set http proxy port to be used for signaling. 
			 *
			 * @param port of the http proxy. 
			 */
			LINPHONECXX_PUBLIC void setHttpProxyPort(int port);
			
			/**
			 * @brief Gets the default identity SIP address. 
			 *
			 * This is an helper function. If no default proxy is set, this will return the
			 * primary contact ( see getPrimaryContact() ). If a default proxy is set it
			 * returns the registered identity on the proxy. 
			 * 
			 * @return The default identity SIP address 
			 */
			LINPHONECXX_PUBLIC std::string getIdentity();
			
			/**
			 * @brief Get the #ImNotifPolicy object controlling the instant messaging
			 * notifications. 
			 *
			 * @return A #ImNotifPolicy object. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ImNotifPolicy> getImNotifPolicy() const;
			
			/**
			 * @brief Gets the in call timeout See setInCallTimeout() for details. 
			 *
			 * @return The current in call timeout in seconds 
			 */
			LINPHONECXX_PUBLIC int getInCallTimeout();
			
			/**
			 * @brief Set the in call timeout in seconds. 
			 *
			 * After this timeout period, the call is automatically hangup. 
			 * 
			 * @param seconds The new timeout in seconds 
			 */
			LINPHONECXX_PUBLIC void setInCallTimeout(int seconds);
			
			/**
			 * @brief Returns the incoming call timeout See setIncTimeout() for details. 
			 *
			 * @return The current incoming call timeout in seconds 
			 */
			LINPHONECXX_PUBLIC int getIncTimeout();
			
			/**
			 * @brief Set the incoming call timeout in seconds. 
			 *
			 * If an incoming call isn't answered for this timeout period, it is automatically
			 * declined. 
			 * 
			 * @param seconds The new timeout in seconds 
			 */
			LINPHONECXX_PUBLIC void setIncTimeout(int seconds);
			
			/**
			 * @brief Tells whether IPv6 is enabled or not. 
			 *
			 * @return A boolean value telling whether IPv6 is enabled or not
			 * 
			 * @see enableIpv6() for more details on how IPv6 is supported in liblinphone. 
			 */
			LINPHONECXX_PUBLIC bool ipv6Enabled();
			
			/**
			 * @brief Turns IPv6 support on or off. 
			 *
			 * @param val A boolean value telling whether to enable IPv6 support 
			 */
			LINPHONECXX_PUBLIC void enableIpv6(bool val);
			
			/**
			 * @brief Check whether the device is echo canceller calibration is required. 
			 *
			 * @return  if it is required, true otherwise 
			 */
			LINPHONECXX_PUBLIC bool isEchoCancellerCalibrationRequired();
			
			/**
			 * @brief Returns whether or not friend lists subscription are enabled. 
			 *
			 * @return whether or not the feature is enabled 
			 */
			LINPHONECXX_PUBLIC bool isFriendListSubscriptionEnabled();
			
			/**
			 * @brief Indicates whether the local participant is part of a conference. 
			 *
			 * @warning That function automatically fails in the case of conferences using a
			 * conferencet server (focus). If you use such a conference, you should use
			 * Conference::removeParticipant() instead. 
			 * 
			 * @return  if the local participant is in a conference, true otherwise. 
			 */
			LINPHONECXX_PUBLIC bool isInConference() const;
			
			/**
			 * @brief Tells whether there is an incoming invite pending. 
			 *
			 * @return A boolean telling whether an incoming invite is pending or not. 
			 */
			LINPHONECXX_PUBLIC bool isIncomingInvitePending();
			
			/**
			 * @brief Check if the configured media encryption is mandatory or not. 
			 *
			 * @return  if media encryption is mandatory; true otherwise. 
			 */
			LINPHONECXX_PUBLIC bool isMediaEncryptionMandatory();
			
			/**
			 * @brief return network state either as positioned by the application or by
			 * linphone itself. 
			 *
			 */
			LINPHONECXX_PUBLIC bool isNetworkReachable();
			
			/**
			 * @brief Is signaling keep alive enabled. 
			 *
			 * @return A boolean value telling whether signaling keep alive is enabled 
			 */
			LINPHONECXX_PUBLIC bool keepAliveEnabled();
			
			/**
			 * @brief Enables signaling keep alive, small udp packet sent periodically to keep
			 * udp NAT association. 
			 *
			 * @param enable A boolean value telling whether signaling keep alive is to be
			 * enabled 
			 */
			LINPHONECXX_PUBLIC void enableKeepAlive(bool enable);
			
			/**
			 * @brief Get the latest outgoing call log. 
			 *
			 * @return {LinphoneCallLog} 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::CallLog> getLastOutgoingCallLog();
			
			/**
			 * @brief Tells wether LIME X3DH is enabled or not. 
			 *
			 * @return The current lime state 
			 */
			LINPHONECXX_PUBLIC bool limeX3DhEnabled() const;
			
			/**
			 * @brief Tells to LinphoneCore to use LIME X3DH. 
			 *
			 * @param enable A boolean value telling whether to enable or disable LIME X3DH 
			 */
			LINPHONECXX_PUBLIC void enableLimeX3Dh(bool enable);
			
			/**
			 * @brief Get the x3dh server url. 
			 *
			 */
			LINPHONECXX_PUBLIC std::string getLimeX3DhServerUrl();
			
			/**
			 * @brief Set the x3dh server url. 
			 *
			 * If empty, this function will disable LIME X3DH from core. Otherwise, or if
			 * different from the existing value, this will (re-)initialize the LIME X3DH
			 * engine. 
			 * 
			 * @param url The x3dh server url 
			 */
			LINPHONECXX_PUBLIC void setLimeX3DhServerUrl(const std::string & url);
			
			/**
			 * @brief Get the linphone specs value telling what functionalities the linphone
			 * client supports. 
			 *
			 * @return The linphone specs telling what functionalities the linphone client
			 * supports
			 * 
			 * @deprecated Use linphone_core_get_linphone_specs_list instead. Deprecated since
			 * 2019-02-07 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED std::string getLinphoneSpecs() const;
			
			/**
			 * @brief Set the linphone specs value telling what functionalities the linphone
			 * client supports. 
			 *
			 * @param specs The linphone specs to set
			 * 
			 * @deprecated Use linphone_core_set_linphone_specs_list or
			 * linphone_core_add_linphone_spec instead. Deprecated since 2019-02-07 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED void setLinphoneSpecs(const std::string & specs);
			
			/**
			 * @brief Get the list of linphone specs string values representing what
			 * functionalities the linphone client supports. 
			 *
			 * @return A list of char * objects. char *  a list of supported specs. The list
			 * must be freed with bctbx_list_free() after usage 
			 */
			LINPHONECXX_PUBLIC std::list<std::string> getLinphoneSpecsList();
			
			/**
			 * @brief Set the linphone specs list value telling what functionalities the
			 * linphone client supports. 
			 *
			 * @param specs A list of char * objects. char *  The list of string specs to set 
			 */
			LINPHONECXX_PUBLIC void setLinphoneSpecsList(const std::list<std::string> & specs);
			
			/**
			 * @brief Gets the url of the server where to upload the collected log files. 
			 *
			 * @return The url of the server where to upload the collected log files. 
			 */
			LINPHONECXX_PUBLIC std::string getLogCollectionUploadServerUrl();
			
			/**
			 * @brief Set the url of the server where to upload the collected log files. 
			 *
			 * @param serverUrl The url of the server where to upload the collected log files. 
			 */
			LINPHONECXX_PUBLIC void setLogCollectionUploadServerUrl(const std::string & serverUrl);
			
			/**
			 * @brief Get the maximum number of simultaneous calls Linphone core can manage at
			 * a time. 
			 *
			 * All new call above this limit are declined with a busy answer 
			 * 
			 * @return max number of simultaneous calls 
			 */
			LINPHONECXX_PUBLIC int getMaxCalls();
			
			/**
			 * @brief Set the maximum number of simultaneous calls Linphone core can manage at
			 * a time. 
			 *
			 * All new call above this limit are declined with a busy answer 
			 * 
			 * @param max number of simultaneous calls 
			 */
			LINPHONECXX_PUBLIC void setMaxCalls(int max);
			
			/**
			 * @brief Gets the size under which incoming files in chat messages will be
			 * downloaded automatically. 
			 *
			 * @return The size in bytes, -1 if autodownload feature is disabled, 0 to
			 * download them all no matter the size 
			 */
			LINPHONECXX_PUBLIC int getMaxSizeForAutoDownloadIncomingFiles();
			
			/**
			 * @brief Sets the size under which incoming files in chat messages will be
			 * downloaded automatically. 
			 *
			 * @param size The size in bytes, -1 to disable the autodownload feature, 0 to
			 * download them all no matter the size 
			 */
			LINPHONECXX_PUBLIC void setMaxSizeForAutoDownloadIncomingFiles(int size);
			
			/**
			 * @brief Gets the name of the currently assigned sound device for media. 
			 *
			 * @return The name of the currently assigned sound device for capture 
			 */
			LINPHONECXX_PUBLIC std::string getMediaDevice();
			
			/**
			 * @brief Sets the sound device used for media. 
			 *
			 * @param devid The device name as returned by linphone_core_get_sound_devices 
			 * 
			 * @return 0 
			 */
			LINPHONECXX_PUBLIC linphone::Status setMediaDevice(const std::string & devid);
			
			/**
			 * @brief Get the media encryption policy being used for RTP packets. 
			 *
			 * @return The media encryption policy being used. 
			 */
			LINPHONECXX_PUBLIC linphone::MediaEncryption getMediaEncryption();
			
			/**
			 * @brief Choose the media encryption policy to be used for RTP packets. 
			 *
			 * @param menc The media encryption policy to be used. 
			 * 
			 * @return 0 if successful, any other value otherwise. 
			 */
			LINPHONECXX_PUBLIC linphone::Status setMediaEncryption(linphone::MediaEncryption menc);
			
			/**
			 * @brief Define whether the configured media encryption is mandatory, if it is
			 * and the negotation cannot result in the desired media encryption then the call
			 * will fail. 
			 *
			 * If not an INVITE will be resent with encryption disabled. 
			 * 
			 * @param m  to set it mandatory; true otherwise. 
			 */
			LINPHONECXX_PUBLIC void setMediaEncryptionMandatory(bool m);
			
			/**
			 * @brief This method is called by the application to notify the linphone core
			 * library when the media (RTP) network is reachable. 
			 *
			 * This is for advanced usage, when SIP and RTP layers are required to use
			 * different interfaces. Most applications just need setNetworkReachable(). 
			 */
			LINPHONECXX_PUBLIC void setMediaNetworkReachable(bool value);
			
			/**
			 * @brief Tells whether the microphone is enabled. 
			 *
			 * @return  if the microphone is enabled, true if disabled. 
			 */
			LINPHONECXX_PUBLIC bool micEnabled();
			
			/**
			 * @brief Enable or disable the microphone. 
			 *
			 * @param enable  to enable the microphone, true to disable it. 
			 */
			LINPHONECXX_PUBLIC void enableMic(bool enable);
			
			/**
			 * @brief Get microphone gain in db. 
			 *
			 * @return The current microphone gain 
			 */
			LINPHONECXX_PUBLIC float getMicGainDb();
			
			/**
			 * @brief Allow to control microphone level: gain in db. 
			 *
			 * @param level The new microphone level 
			 */
			LINPHONECXX_PUBLIC void setMicGainDb(float level);
			
			/**
			 * @brief Get the number of missed calls. 
			 *
			 * Once checked, this counter can be reset with resetMissedCallsCount(). 
			 * 
			 * @return The number of missed calls. 
			 */
			LINPHONECXX_PUBLIC int getMissedCallsCount();
			
			/**
			 * @brief Returns the maximum transmission unit size in bytes. 
			 *
			 */
			LINPHONECXX_PUBLIC int getMtu() const;
			
			/**
			 * @brief Sets the maximum transmission unit size in bytes. 
			 *
			 * This information is useful for sending RTP packets. Default value is 1500. 
			 * 
			 * @param mtu The MTU in bytes 
			 */
			LINPHONECXX_PUBLIC void setMtu(int mtu);
			
			/**
			 * @brief Get the public IP address of NAT being used. 
			 *
			 * @return The public IP address of NAT being used. 
			 */
			LINPHONECXX_PUBLIC std::string getNatAddress() const;
			
			/**
			 * @brief Set the public IP address of NAT when using the firewall policy is set
			 * to use NAT. 
			 *
			 * @param addr The public IP address of NAT to use. 
			 */
			LINPHONECXX_PUBLIC void setNatAddress(const std::string & addr);
			
			/**
			 * @brief Get The policy that is used to pass through NATs/firewalls. 
			 *
			 * It may be overridden by a NAT policy for a specific proxy config. 
			 * 
			 * @return #NatPolicy object in use.
			 * 
			 * @see ProxyConfig::getNatPolicy() 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::NatPolicy> getNatPolicy() const;
			
			/**
			 * @brief Set the policy to use to pass through NATs/firewalls. 
			 *
			 * It may be overridden by a NAT policy for a specific proxy config. 
			 * 
			 * @param policy #NatPolicy object
			 * 
			 * @see ProxyConfig::setNatPolicy() 
			 */
			LINPHONECXX_PUBLIC void setNatPolicy(const std::shared_ptr<linphone::NatPolicy> & policy);
			
			/**
			 * @brief Get the native window handle of the video preview window. 
			 *
			 * @return The native window handle of the video preview window 
			 */
			LINPHONECXX_PUBLIC void * getNativePreviewWindowId() const;
			
			/**
			 * @brief Set the native window id where the preview video (local camera) is to be
			 * displayed. 
			 *
			 * This has to be used in conjonction with usePreviewWindow(). MacOS, Linux,
			 * Windows: if not set or zero the core will create its own window, unless the
			 * special id -1 is given. 
			 * 
			 * @param id The native window id where the preview video is to be displayed 
			 */
			LINPHONECXX_PUBLIC void setNativePreviewWindowId(void * id);
			
			/**
			 * @brief Get the native window handle of the video window. 
			 *
			 * @return The native window handle of the video window 
			 */
			LINPHONECXX_PUBLIC void * getNativeVideoWindowId() const;
			
			/**
			 * @brief Set the native video window id where the video is to be displayed. 
			 *
			 * For MacOS, Linux, Windows: if not set or LINPHONE_VIDEO_DISPLAY_AUTO the core
			 * will create its own window, unless the special id LINPHONE_VIDEO_DISPLAY_NONE
			 * is given. 
			 */
			LINPHONECXX_PUBLIC void setNativeVideoWindowId(void * id);
			
			/**
			 * @brief This method is called by the application to notify the linphone core
			 * library when network is reachable. 
			 *
			 * Calling this method with true trigger linphone to initiate a registration
			 * process for all proxies. Calling this method disables the automatic network
			 * detection mode. It means you must call this method after each network state
			 * changes. 
			 */
			LINPHONECXX_PUBLIC void setNetworkReachable(bool value);
			
			/**
			 * @brief Gets the value of the no-rtp timeout. 
			 *
			 * When no RTP or RTCP packets have been received for a while #linphone::Core will
			 * consider the call is broken (remote end crashed or disconnected from the
			 * network), and thus will terminate the call. The no-rtp timeout is the duration
			 * above which the call is considered broken. 
			 * 
			 * @return The value of the no-rtp timeout in seconds 
			 */
			LINPHONECXX_PUBLIC int getNortpTimeout() const;
			
			/**
			 * @brief Sets the no-rtp timeout value in seconds. 
			 *
			 * @param seconds The no-rtp timeout value to use in seconds
			 * 
			 * @see getNortpTimeout() for details. 
			 */
			LINPHONECXX_PUBLIC void setNortpTimeout(int seconds);
			
			/**
			 * @brief Get the wav file that is played when putting somebody on hold, or when
			 * files are used instead of soundcards (see setUseFiles()). 
			 *
			 * The file is a 16 bit linear wav file. 
			 * 
			 * @return The path to the file that is played when putting somebody on hold. 
			 */
			LINPHONECXX_PUBLIC std::string getPlayFile() const;
			
			/**
			 * @brief Sets a wav file to be played when putting somebody on hold, or when
			 * files are used instead of soundcards (see setUseFiles()). 
			 *
			 * The file must be a 16 bit linear wav file. 
			 * 
			 * @param file The path to the file to be played when putting somebody on hold. 
			 */
			LINPHONECXX_PUBLIC void setPlayFile(const std::string & file);
			
			/**
			 * @brief Gets the name of the currently assigned sound device for playback. 
			 *
			 * @return The name of the currently assigned sound device for playback 
			 */
			LINPHONECXX_PUBLIC std::string getPlaybackDevice();
			
			/**
			 * @brief Sets the sound device used for playback. 
			 *
			 * @param devid The device name as returned by linphone_core_get_sound_devices 
			 * 
			 * @return 0 
			 */
			LINPHONECXX_PUBLIC linphone::Status setPlaybackDevice(const std::string & devid);
			
			/**
			 * @brief Get playback gain in db before entering sound card. 
			 *
			 * @return The current playback gain 
			 */
			LINPHONECXX_PUBLIC float getPlaybackGainDb();
			
			/**
			 * @brief Allow to control play level before entering sound card: gain in db. 
			 *
			 * @param level The new play level 
			 */
			LINPHONECXX_PUBLIC void setPlaybackGainDb(float level);
			
			/**
			 * @brief Returns the preferred video framerate, previously set by
			 * setPreferredFramerate(). 
			 *
			 * @return frame rate in number of frames per seconds. 
			 */
			LINPHONECXX_PUBLIC float getPreferredFramerate();
			
			/**
			 * @brief Set the preferred frame rate for video. 
			 *
			 * Based on the available bandwidth constraints and network conditions, the video
			 * encoder remains free to lower the framerate. There is no warranty that the
			 * preferred frame rate be the actual framerate. used during a call. Default value
			 * is 0, which means "use encoder's default fps value". 
			 * 
			 * @param fps the target frame rate in number of frames per seconds. 
			 */
			LINPHONECXX_PUBLIC void setPreferredFramerate(float fps);
			
			/**
			 * @brief Get the preferred video definition for the stream that is captured and
			 * sent to the remote party. 
			 *
			 * @return The preferred #VideoDefinition 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::VideoDefinition> getPreferredVideoDefinition() const;
			
			/**
			 * @brief Set the preferred video definition for the stream that is captured and
			 * sent to the remote party. 
			 *
			 * All standard video definitions are accepted on the receive path. 
			 * 
			 * @param vdef #VideoDefinition object 
			 */
			LINPHONECXX_PUBLIC void setPreferredVideoDefinition(const std::shared_ptr<linphone::VideoDefinition> & vdef);
			
			/**
			 * @brief Sets the preferred video size by its name. 
			 *
			 * This is identical to linphone_core_set_preferred_video_size except that it
			 * takes the name of the video resolution as input. Video resolution names are:
			 * qcif, svga, cif, vga, 4cif, svga ...
			 * 
			 * @deprecated Use Factory::createVideoDefinitionFromName() and
			 * setPreferredVideoDefinition() instead 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED void setPreferredVideoSizeByName(const std::string & name);
			
			/**
			 * @brief Get my presence model. 
			 *
			 * @return A #PresenceModel object, or nullptr if no presence model has been set. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::PresenceModel> getPresenceModel() const;
			
			/**
			 * @brief Set my presence model. 
			 *
			 * @param presence #PresenceModel 
			 */
			LINPHONECXX_PUBLIC void setPresenceModel(const std::shared_ptr<linphone::PresenceModel> & presence);
			
			/**
			 * @brief Get the definition of the captured video. 
			 *
			 * @return The captured #VideoDefinition if it was previously set by
			 * setPreviewVideoDefinition(), otherwise a 0x0 LinphoneVideoDefinition. 
			 * 
			 * @see setPreviewVideoDefinition() 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::VideoDefinition> getPreviewVideoDefinition() const;
			
			/**
			 * @brief Set the video definition for the captured (preview) video. 
			 *
			 * This method is for advanced usage where a video capture must be set
			 * independently of the definition of the stream actually sent through the call.
			 * This allows for example to have the preview window in High Definition even if
			 * due to bandwidth constraint the sent video definition is small. Using this
			 * feature increases the CPU consumption, since a rescaling will be done
			 * internally. 
			 * 
			 * @param vdef #VideoDefinition object 
			 */
			LINPHONECXX_PUBLIC void setPreviewVideoDefinition(const std::shared_ptr<linphone::VideoDefinition> & vdef);
			
			/**
			 * @brief Sets the preview video size by its name. 
			 *
			 * See linphone_core_set_preview_video_size for more information about this
			 * feature.
			 * 
			 * Video resolution names are: qcif, svga, cif, vga, 4cif, svga ...
			 * 
			 * @deprecated Use Factory::createVideoDefinitionFromName() and
			 * setPreviewVideoDefinition() instead 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED void setPreviewVideoSizeByName(const std::string & name);
			
			/**
			 * @brief Returns the default identity when no proxy configuration is used. 
			 *
			 */
			LINPHONECXX_PUBLIC std::string getPrimaryContact();
			
			/**
			 * @brief Sets the local "from" identity. 
			 *
			 * This data is used in absence of any proxy configuration or when no default
			 * proxy configuration is set. See #ProxyConfig 
			 */
			LINPHONECXX_PUBLIC linphone::Status setPrimaryContact(const std::string & contact);
			
			/**
			 * @brief Same as getPrimaryContact() but the result is a #Address object instead
			 * of const char *. 
			 *
			 * @deprecated Use createPrimaryContactParsed() instead. Deprecated since
			 * 2018-10-22. 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED std::shared_ptr<linphone::Address> getPrimaryContactParsed();
			
			/**
			 * @brief Get provisioning URI. 
			 *
			 * @return the provisioning URI. 
			 */
			LINPHONECXX_PUBLIC std::string getProvisioningUri() const;
			
			/**
			 * @brief Set URI where to download xml configuration file at startup. 
			 *
			 * This can also be set from configuration file or factory config file, from
			 * [misc] section, item "config-uri". Calling this function does not load the
			 * configuration. It will write the value into configuration so that configuration
			 * from remote URI will take place at next #linphone::Core start. 
			 * 
			 * @param uri the http or https uri to use in order to download the configuration.
			 * Passing nullptr will disable remote provisioning. 
			 * 
			 * @return -1 if uri could not be parsed, 0 otherwise. Note that this does not
			 * check validity of URI endpoint nor scheme and download may still fail. 
			 */
			LINPHONECXX_PUBLIC linphone::Status setProvisioningUri(const std::string & uri);
			
			/**
			 * @brief Returns an unmodifiable list of entered proxy configurations. 
			 *
			 * @return A list of #ProxyConfig objects. LinphoneProxyConfig  
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::ProxyConfig>> getProxyConfigList() const;
			
			/**
			 * @brief Tells whether QRCode is enabled in the preview. 
			 *
			 * @return A boolean value telling whether QRCode is enabled in the preview. 
			 */
			LINPHONECXX_PUBLIC bool qrcodeVideoPreviewEnabled() const;
			
			/**
			 * @brief Controls QRCode enablement. 
			 *
			 * @param val A boolean value telling whether the QRCode is enabled in the
			 * preview. 
			 */
			LINPHONECXX_PUBLIC void enableQrcodeVideoPreview(bool val);
			
			/**
			 * @brief Gets if realtime text is enabled or not. 
			 *
			 * @return true if realtime text is enabled, false otherwise 
			 */
			LINPHONECXX_PUBLIC bool realtimeTextEnabled();
			
			/**
			 * @brief Get the wav file where incoming stream is recorded, when files are used
			 * instead of soundcards (see setUseFiles()). 
			 *
			 * This feature is different from call recording (CallParams::setRecordFile()) The
			 * file is a 16 bit linear wav file. 
			 * 
			 * @return The path to the file where incoming stream is recorded. 
			 */
			LINPHONECXX_PUBLIC std::string getRecordFile() const;
			
			/**
			 * @brief Sets a wav file where incoming stream is to be recorded, when files are
			 * used instead of soundcards (see setUseFiles()). 
			 *
			 * This feature is different from call recording (CallParams::setRecordFile()) The
			 * file will be a 16 bit linear wav file. 
			 * 
			 * @param file The path to the file where incoming stream is to be recorded. 
			 */
			LINPHONECXX_PUBLIC void setRecordFile(const std::string & file);
			
			/**
			 * @brief Get the ring back tone played to far end during incoming calls. 
			 *
			 */
			LINPHONECXX_PUBLIC std::string getRemoteRingbackTone() const;
			
			/**
			 * @brief Specify a ring back tone to be played to far end during incoming calls. 
			 *
			 * @param ring The path to the ring back tone to be played. 
			 */
			LINPHONECXX_PUBLIC void setRemoteRingbackTone(const std::string & ring);
			
			/**
			 * @brief Tells whether NACK context is enabled or not. 
			 *
			 * @return A boolean value telling whether NACK context is enabled or not 
			 */
			LINPHONECXX_PUBLIC bool retransmissionOnNackEnabled();
			
			/**
			 * @brief Turns NACK context on or off. 
			 *
			 * @param val A boolean value telling whether to enable NACK context 
			 */
			LINPHONECXX_PUBLIC void enableRetransmissionOnNack(bool val);
			
			/**
			 * @brief Returns the path to the wav file used for ringing. 
			 *
			 * @return The path to the wav file used for ringing 
			 */
			LINPHONECXX_PUBLIC std::string getRing() const;
			
			/**
			 * @brief Sets the path to a wav file used for ringing. 
			 *
			 * The file must be a wav 16bit linear. Local ring is disabled if null. 
			 * 
			 * @param path The path to a wav file to be used for ringing 
			 */
			LINPHONECXX_PUBLIC void setRing(const std::string & path);
			
			/**
			 * @brief Tells whether the ring play is enabled during an incoming early media
			 * call. 
			 *
			 */
			LINPHONECXX_PUBLIC bool getRingDuringIncomingEarlyMedia() const;
			
			/**
			 * @brief Enable or disable the ring play during an incoming early media call. 
			 *
			 * @param enable A boolean value telling whether to enable ringing during an
			 * incoming early media call. 
			 */
			LINPHONECXX_PUBLIC void setRingDuringIncomingEarlyMedia(bool enable);
			
			/**
			 * @brief Returns the path to the wav file used for ringing back. 
			 *
			 * @return The path to the wav file used for ringing back 
			 */
			LINPHONECXX_PUBLIC std::string getRingback() const;
			
			/**
			 * @brief Sets the path to a wav file used for ringing back. 
			 *
			 * Ringback means the ring that is heard when it's ringing at the remote party.
			 * The file must be a wav 16bit linear. 
			 * 
			 * @param path The path to a wav file to be used for ringing back 
			 */
			LINPHONECXX_PUBLIC void setRingback(const std::string & path);
			
			/**
			 * @brief Gets the name of the currently assigned sound device for ringing. 
			 *
			 * @return The name of the currently assigned sound device for ringing 
			 */
			LINPHONECXX_PUBLIC std::string getRingerDevice();
			
			/**
			 * @brief Sets the sound device used for ringing. 
			 *
			 * @param devid The device name as returned by linphone_core_get_sound_devices 
			 * 
			 * @return 0 
			 */
			LINPHONECXX_PUBLIC linphone::Status setRingerDevice(const std::string & devid);
			
			/**
			 * @brief Gets the path to a file or folder containing the trusted root CAs (PEM
			 * format) 
			 *
			 * @return The path to a file or folder containing the trusted root CAs 
			 */
			LINPHONECXX_PUBLIC std::string getRootCa();
			
			/**
			 * @brief Sets the path to a file or folder containing trusted root CAs (PEM
			 * format) 
			 *
			 * @param path The path to a file or folder containing trusted root CAs 
			 */
			LINPHONECXX_PUBLIC void setRootCa(const std::string & path);
			
			/**
			 * @brief Sets the trusted root CAs (PEM format) 
			 *
			 * @param data The trusted root CAs as a string 
			 */
			LINPHONECXX_PUBLIC void setRootCaData(const std::string & data);
			
			/**
			 * @brief Media offer control param for SIP INVITE. 
			 *
			 * @return true if INVITE has to be sent whitout SDP. 
			 */
			LINPHONECXX_PUBLIC bool sdp200AckEnabled() const;
			
			/**
			 * @brief Control when media offer is sent in SIP INVITE. 
			 *
			 * @param enable true if INVITE has to be sent whitout SDP. 
			 */
			LINPHONECXX_PUBLIC void enableSdp200Ack(bool enable);
			
			/**
			 * @brief Tells whether video self view during call is enabled or not. 
			 *
			 * @return A boolean value telling whether self view is enabled 
			 * 
			 * @see enableSelfView() for details. 
			 */
			LINPHONECXX_PUBLIC bool selfViewEnabled() const;
			
			/**
			 * @brief Enables or disable self view during calls. 
			 *
			 * @param val A boolean value telling whether to enable self view Self-view refers
			 * to having local webcam image inserted in corner of the video window during
			 * calls. This function works at any time, including during calls. 
			 */
			LINPHONECXX_PUBLIC void enableSelfView(bool val);
			
			/**
			 * @brief Returns the session expires value, 0 by default, which means session
			 * expires disabled. 
			 *
			 */
			LINPHONECXX_PUBLIC int getSessionExpiresValue() const;
			
			/**
			 * @brief Sets the session expires value, 0 by default, which means session
			 * expires disabled. 
			 *
			 */
			LINPHONECXX_PUBLIC void setSessionExpiresValue(int expires) const;
			
			/**
			 * @brief Get the DSCP field for SIP signaling channel. 
			 *
			 * The DSCP defines the quality of service in IP packets. 
			 * 
			 * @return The current DSCP value 
			 */
			LINPHONECXX_PUBLIC int getSipDscp() const;
			
			/**
			 * @brief Set the DSCP field for SIP signaling channel. 
			 *
			 * The DSCP defines the quality of service in IP packets. 
			 * 
			 * @param dscp The DSCP value to set 
			 */
			LINPHONECXX_PUBLIC void setSipDscp(int dscp);
			
			/**
			 * @brief This method is called by the application to notify the linphone core
			 * library when the SIP network is reachable. 
			 *
			 * This is for advanced usage, when SIP and RTP layers are required to use
			 * different interfaces. Most applications just need setNetworkReachable(). 
			 */
			LINPHONECXX_PUBLIC void setSipNetworkReachable(bool value);
			
			/**
			 * @brief Get the SIP transport timeout. 
			 *
			 * @return The SIP transport timeout in milliseconds. 
			 */
			LINPHONECXX_PUBLIC int getSipTransportTimeout();
			
			/**
			 * @brief Set the SIP transport timeout. 
			 *
			 * @param timeoutMs The SIP transport timeout in milliseconds. 
			 */
			LINPHONECXX_PUBLIC void setSipTransportTimeout(int timeoutMs);
			
			/**
			 * @brief Gets the list of the available sound devices. 
			 *
			 * @return A list of char * objects. char *  An unmodifiable array of strings
			 * contanining the names of the available sound devices that is nullptr terminated 
			 */
			LINPHONECXX_PUBLIC std::list<std::string> getSoundDevicesList() const;
			
			/**
			 * @brief Get the path to the image file streamed when "Static picture" is set as
			 * the video device. 
			 *
			 * @return The path to the image file streamed when "Static picture" is set as the
			 * video device. 
			 */
			LINPHONECXX_PUBLIC std::string getStaticPicture();
			
			/**
			 * @brief Set the path to the image file to stream when "Static picture" is set as
			 * the video device. 
			 *
			 * @param path The path to the image file to use. 
			 */
			LINPHONECXX_PUBLIC linphone::Status setStaticPicture(const std::string & path);
			
			/**
			 * @brief Get the frame rate for static picture. 
			 *
			 * @return The frame rate used for static picture. 
			 */
			LINPHONECXX_PUBLIC float getStaticPictureFps();
			
			/**
			 * @brief Set the frame rate for static picture. 
			 *
			 * @param fps The new frame rate to use for static picture. 
			 */
			LINPHONECXX_PUBLIC linphone::Status setStaticPictureFps(float fps);
			
			/**
			 * @brief Get the STUN server address being used. 
			 *
			 * @return The STUN server address being used. 
			 */
			LINPHONECXX_PUBLIC std::string getStunServer() const;
			
			/**
			 * @brief Set the STUN server address to use when the firewall policy is set to
			 * STUN. 
			 *
			 * @param server The STUN server address to use. 
			 */
			LINPHONECXX_PUBLIC void setStunServer(const std::string & server);
			
			/**
			 * @brief Returns a null terminated table of strings containing the file format
			 * extension supported for call recording. 
			 *
			 * @return A list of char * objects. char *  the supported formats, typically
			 * 'wav' and 'mkv' 
			 */
			LINPHONECXX_PUBLIC std::list<std::string> getSupportedFileFormatsList();
			
			/**
			 * @brief Return the list of the available text payload types. 
			 *
			 * @return A list of #PayloadType objects. LinphonePayloadType  A freshly
			 * allocated list of the available payload types. The list must be destroyed with
			 * bctbx_list_free() after usage. The elements of the list haven't to be unref. 
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::PayloadType>> getTextPayloadTypes();
			
			/**
			 * @brief Redefine the list of the available payload types. 
			 *
			 * @param payloadTypes A list of #PayloadType objects. LinphonePayloadType  The
			 * new list of payload types. The core does not take ownership on it. 
			 */
			LINPHONECXX_PUBLIC void setTextPayloadTypes(const std::list<std::shared_ptr<linphone::PayloadType>> & payloadTypes);
			
			/**
			 * @brief Gets the UDP port used for text streaming. 
			 *
			 * @return The UDP port used for text streaming 
			 */
			LINPHONECXX_PUBLIC int getTextPort() const;
			
			/**
			 * @brief Sets the UDP port used for text streaming. 
			 *
			 * A value if -1 will request the system to allocate the local port randomly. This
			 * is recommended in order to avoid firewall warnings. 
			 * 
			 * @param port The UDP port to use for text streaming 
			 */
			LINPHONECXX_PUBLIC void setTextPort(int port);
			
			/**
			 * @brief Get the text port range from which is randomly chosen the UDP port used
			 * for text streaming. 
			 *
			 * @return a #Range object 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Range> getTextPortsRange() const;
			
			/**
			 * @brief Gets the TLS certificate. 
			 *
			 * @return the TLS certificate or nullptr if not set yet 
			 */
			LINPHONECXX_PUBLIC std::string getTlsCert() const;
			
			/**
			 * @brief Sets a TLS certificate used for TLS authentication The certificate won't
			 * be stored, you have to set it after each #linphone::Core startup. 
			 *
			 * @param tlsCert the TLS certificate 
			 */
			LINPHONECXX_PUBLIC void setTlsCert(const std::string & tlsCert);
			
			/**
			 * @brief Gets the path to the TLS certificate file. 
			 *
			 * @return the TLS certificate path or nullptr if not set yet 
			 */
			LINPHONECXX_PUBLIC std::string getTlsCertPath() const;
			
			/**
			 * @brief Sets a TLS certificate path used for TLS authentication The path will be
			 * stored in the rc file and automatically restored on startup. 
			 *
			 * @param tlsCertPath path to the TLS certificate 
			 */
			LINPHONECXX_PUBLIC void setTlsCertPath(const std::string & tlsCertPath);
			
			/**
			 * @brief Gets the TLS key. 
			 *
			 * @return the TLS key or nullptr if not set yet 
			 */
			LINPHONECXX_PUBLIC std::string getTlsKey() const;
			
			/**
			 * @brief Sets a TLS key used for TLS authentication The key won't be stored, you
			 * have to set it after each #linphone::Core startup. 
			 *
			 * @param tlsKey the TLS key 
			 */
			LINPHONECXX_PUBLIC void setTlsKey(const std::string & tlsKey);
			
			/**
			 * @brief Gets the path to the TLS key file. 
			 *
			 * @return the TLS key path or nullptr if not set yet 
			 */
			LINPHONECXX_PUBLIC std::string getTlsKeyPath() const;
			
			/**
			 * @brief Sets a TLS key path used for TLS authentication The path will be stored
			 * in the rc file and automatically restored on startup. 
			 *
			 * @param tlsKeyPath path to the TLS key 
			 */
			LINPHONECXX_PUBLIC void setTlsKeyPath(const std::string & tlsKeyPath);
			
			/**
			 * @brief Retrieves the port configuration used for each transport (udp, tcp,
			 * tls). 
			 *
			 * A zero value port for a given transport means the transport is not used. A
			 * value of LC_SIP_TRANSPORT_RANDOM (-1) means the port is to be chosen randomly
			 * by the system. 
			 * 
			 * @return A #Transports structure with the configured ports 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Transports> getTransports();
			
			/**
			 * @brief Sets the ports to be used for each of transport (UDP or TCP) A zero
			 * value port for a given transport means the transport is not used. 
			 *
			 * A value of LC_SIP_TRANSPORT_RANDOM (-1) means the port is to be choosen
			 * randomly by the system. 
			 * 
			 * @param transports A #LinphoneSipTransports structure giving the ports to use 
			 * 
			 * @return 0 
			 */
			LINPHONECXX_PUBLIC linphone::Status setTransports(const std::shared_ptr<const linphone::Transports> & transports);
			
			/**
			 * @brief Retrieves the real port number assigned for each sip transport (udp,
			 * tcp, tls). 
			 *
			 * A zero value means that the transport is not activated. If
			 * LC_SIP_TRANSPORT_RANDOM was passed to linphone_core_set_sip_transports, the
			 * random port choosed by the system is returned. 
			 * 
			 * @return A #Transports structure with the ports being used 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Transports> getTransportsUsed();
			
			/**
			 * @brief get tunnel instance if available 
			 *
			 * @return #Tunnel or nullptr if not available 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Tunnel> getTunnel() const;
			
			/**
			 * @brief Return the global unread chat message count. 
			 *
			 * @return The global unread chat message count. 
			 */
			LINPHONECXX_PUBLIC int getUnreadChatMessageCount() const;
			
			/**
			 * @brief Return the unread chat message count for all active local address. 
			 *
			 * (Primary contact + proxy configs.) 
			 * 
			 * @return The unread chat message count. 
			 */
			LINPHONECXX_PUBLIC int getUnreadChatMessageCountFromActiveLocals() const;
			
			/**
			 * @brief Retrieve the maximum available upload bandwidth. 
			 *
			 * This value was set by setUploadBandwidth(). 
			 */
			LINPHONECXX_PUBLIC int getUploadBandwidth() const;
			
			/**
			 * @brief Sets maximum available upload bandwidth This is IP bandwidth, in kbit/s. 
			 *
			 * This information is used by liblinphone together with remote side available
			 * bandwidth signaled in SDP messages to properly configure audio & video codec's
			 * output bitrate.
			 * 
			 * @param bw the bandwidth in kbits/s, 0 for infinite 
			 */
			LINPHONECXX_PUBLIC void setUploadBandwidth(int bw);
			
			/**
			 * @brief Set audio packetization time linphone will send (in absence of
			 * requirement from peer) A value of 0 stands for the current codec default
			 * packetization time. 
			 *
			 */
			LINPHONECXX_PUBLIC int getUploadPtime();
			
			/**
			 * @brief Set audio packetization time linphone will send (in absence of
			 * requirement from peer) A value of 0 stands for the current codec default
			 * packetization time. 
			 *
			 */
			LINPHONECXX_PUBLIC void setUploadPtime(int ptime);
			
			/**
			 * @brief Return the external ip address of router. 
			 *
			 * In some cases the uPnP can have an external ip address but not a usable uPnP
			 * (state different of Ok).
			 * 
			 * @return a null terminated string containing the external ip address. If the the
			 * external ip address is not available return null. 
			 */
			LINPHONECXX_PUBLIC std::string getUpnpExternalIpaddress() const;
			
			/**
			 * @brief Return the internal state of uPnP. 
			 *
			 * @return an LinphoneUpnpState. 
			 */
			LINPHONECXX_PUBLIC linphone::UpnpState getUpnpState() const;
			
			/**
			 * @brief Gets whether linphone is currently streaming audio from and to files,
			 * rather than using the soundcard. 
			 *
			 * @return A boolean value representing whether linphone is streaming audio from
			 * and to files or not. 
			 */
			LINPHONECXX_PUBLIC bool getUseFiles();
			
			/**
			 * @brief Ask the core to stream audio from and to files, instead of using the
			 * soundcard. 
			 *
			 * @param yesno A boolean value asking to stream audio from and to files or not. 
			 */
			LINPHONECXX_PUBLIC void setUseFiles(bool yesno);
			
			/**
			 * @brief Indicates whether SIP INFO is used to send digits. 
			 *
			 * @return A boolean value telling whether SIP INFO is used to send digits 
			 */
			LINPHONECXX_PUBLIC bool getUseInfoForDtmf();
			
			/**
			 * @brief Sets whether SIP INFO is to be used to send digits. 
			 *
			 * @param useInfo A boolean value telling whether to use SIP INFO to send digits 
			 */
			LINPHONECXX_PUBLIC void setUseInfoForDtmf(bool useInfo);
			
			/**
			 * @brief Indicates whether RFC2833 is used to send digits. 
			 *
			 * @return A boolean value telling whether RFC2833 is used to send digits 
			 */
			LINPHONECXX_PUBLIC bool getUseRfc2833ForDtmf();
			
			/**
			 * @brief Sets whether RFC2833 is to be used to send digits. 
			 *
			 * @param useRfc2833 A boolean value telling whether to use RFC2833 to send digits 
			 */
			LINPHONECXX_PUBLIC void setUseRfc2833ForDtmf(bool useRfc2833);
			
			/**
			 *
			 * @return liblinphone's user agent as a string. 
			 */
			LINPHONECXX_PUBLIC std::string getUserAgent();
			
			/**
			 * @brief Get the path to the directory storing the user's certificates. 
			 *
			 * @return The path to the directory storing the user's certificates. 
			 */
			LINPHONECXX_PUBLIC std::string getUserCertificatesPath();
			
			/**
			 * @brief Set the path to the directory storing the user's x509 certificates (used
			 * by dtls) 
			 *
			 * @param path The path to the directory to use to store the user's certificates. 
			 */
			LINPHONECXX_PUBLIC void setUserCertificatesPath(const std::string & path);
			
			/**
			 * @brief Get the default policy for video. 
			 *
			 * See setVideoActivationPolicy() for more details. 
			 * 
			 * @return The video policy being used 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::VideoActivationPolicy> getVideoActivationPolicy() const;
			
			/**
			 * @brief Sets the default policy for video. 
			 *
			 * This policy defines whether:
			 * 
			 */
			LINPHONECXX_PUBLIC void setVideoActivationPolicy(const std::shared_ptr<const linphone::VideoActivationPolicy> & policy);
			
			/**
			 * @brief Tells whether the video adaptive jitter compensation is enabled. 
			 *
			 * @return  if the video adaptive jitter compensation is enabled, true otherwise. 
			 */
			LINPHONECXX_PUBLIC bool videoAdaptiveJittcompEnabled();
			
			/**
			 * @brief Enable or disable the video adaptive jitter compensation. 
			 *
			 * @param enable  to enable the video adaptive jitter compensation, true to
			 * disable it. 
			 */
			LINPHONECXX_PUBLIC void enableVideoAdaptiveJittcomp(bool enable);
			
			/**
			 * @brief Tells whether video capture is enabled. 
			 *
			 * @return  if video capture is enabled, true if disabled. 
			 */
			LINPHONECXX_PUBLIC bool videoCaptureEnabled();
			
			/**
			 * @brief Enable or disable video capture. 
			 *
			 * This function does not have any effect during calls. It just indicates the
			 * #linphone::Core to initiate future calls with video capture or not. 
			 * 
			 * @param enable  to enable video capture, true to disable it. 
			 */
			LINPHONECXX_PUBLIC void enableVideoCapture(bool enable);
			
			/**
			 * @brief Returns the name of the currently active video device. 
			 *
			 * @return The name of the currently active video device 
			 */
			LINPHONECXX_PUBLIC std::string getVideoDevice() const;
			
			/**
			 * @brief Sets the active video device. 
			 *
			 * @param id The name of the video device to use as returned by
			 * linphone_core_get_video_devices 
			 */
			LINPHONECXX_PUBLIC linphone::Status setVideoDevice(const std::string & id);
			
			/**
			 * @brief Gets the list of the available video capture devices. 
			 *
			 * @return A list of char * objects. char *  An unmodifiable array of strings
			 * contanining the names of the available video capture devices that is nullptr
			 * terminated 
			 */
			LINPHONECXX_PUBLIC std::list<std::string> getVideoDevicesList() const;
			
			/**
			 * @brief Tells whether video display is enabled. 
			 *
			 * @return  if video display is enabled, true if disabled. 
			 */
			LINPHONECXX_PUBLIC bool videoDisplayEnabled();
			
			/**
			 * @brief Enable or disable video display. 
			 *
			 * This function does not have any effect during calls. It just indicates the
			 * #linphone::Core to initiate future calls with video display or not. 
			 * 
			 * @param enable  to enable video display, true to disable it. 
			 */
			LINPHONECXX_PUBLIC void enableVideoDisplay(bool enable);
			
			/**
			 * @brief Get the name of the mediastreamer2 filter used for rendering video. 
			 *
			 * @return The currently selected video display filter 
			 */
			LINPHONECXX_PUBLIC std::string getVideoDisplayFilter();
			
			/**
			 * @brief Set the name of the mediastreamer2 filter to be used for rendering
			 * video. 
			 *
			 * This is for advanced users of the library, mainly to workaround hardware/driver
			 * bugs. 
			 */
			LINPHONECXX_PUBLIC void setVideoDisplayFilter(const std::string & filtername);
			
			/**
			 * @brief Get the DSCP field for outgoing video streams. 
			 *
			 * The DSCP defines the quality of service in IP packets. 
			 * 
			 * @return The current DSCP value 
			 */
			LINPHONECXX_PUBLIC int getVideoDscp() const;
			
			/**
			 * @brief Set the DSCP field for outgoing video streams. 
			 *
			 * The DSCP defines the quality of service in IP packets. 
			 * 
			 * @param dscp The DSCP value to set 
			 */
			LINPHONECXX_PUBLIC void setVideoDscp(int dscp);
			
			/**
			 * @brief Returns true if either capture or display is enabled, true otherwise. 
			 *
			 * same as ( linphone_core_video_capture_enabled |
			 * linphone_core_video_display_enabled ) 
			 */
			LINPHONECXX_PUBLIC bool videoEnabled();
			
			/**
			 * @brief Returns the nominal video jitter buffer size in milliseconds. 
			 *
			 * @return The nominal video jitter buffer size in milliseconds 
			 */
			LINPHONECXX_PUBLIC int getVideoJittcomp();
			
			/**
			 * @brief Sets the nominal video jitter buffer size in milliseconds. 
			 *
			 * The value takes effect immediately for all running and pending calls, if any. A
			 * value of 0 disables the jitter buffer. 
			 */
			LINPHONECXX_PUBLIC void setVideoJittcomp(int milliseconds);
			
			/**
			 * @brief Use to get multicast address to be used for video stream. 
			 *
			 * @return an ipv4/6 multicast address, or default value 
			 */
			LINPHONECXX_PUBLIC std::string getVideoMulticastAddr() const;
			
			/**
			 * @brief Use to set multicast address to be used for video stream. 
			 *
			 * @param ip an ipv4/6 multicast address 
			 * 
			 * @return 0 in case of success 
			 */
			LINPHONECXX_PUBLIC linphone::Status setVideoMulticastAddr(const std::string & ip);
			
			/**
			 * @brief Use to get multicast state of video stream. 
			 *
			 * @return true if subsequent calls will propose multicast ip set by
			 * linphone_core_set_video_multicast_addr 
			 */
			LINPHONECXX_PUBLIC bool videoMulticastEnabled() const;
			
			/**
			 * @brief Use to enable multicast rtp for video stream. 
			 *
			 * If enabled, outgoing calls put a multicast address from
			 * linphone_core_get_video_multicast_addr into video cline. In case of outgoing
			 * call video stream is sent to this multicast address. For incoming calls
			 * behavior is unchanged. 
			 * 
			 * @param yesno if yes, subsequent outgoing calls will propose multicast ip set by
			 * linphone_core_set_video_multicast_addr 
			 */
			LINPHONECXX_PUBLIC void enableVideoMulticast(bool yesno);
			
			/**
			 * @brief Use to get multicast ttl to be used for video stream. 
			 *
			 * @return a time to leave value 
			 */
			LINPHONECXX_PUBLIC int getVideoMulticastTtl() const;
			
			/**
			 * @brief Use to set multicast ttl to be used for video stream. 
			 *
			 * @param ttl value or -1 if not used. [0..255] default value is 1 
			 * 
			 * @return 0 in case of success 
			 */
			LINPHONECXX_PUBLIC linphone::Status setVideoMulticastTtl(int ttl);
			
			/**
			 * @brief Return the list of the available video payload types. 
			 *
			 * @return A list of #PayloadType objects. LinphonePayloadType  A freshly
			 * allocated list of the available payload types. The list must be destroyed with
			 * bctbx_list_free() after usage. The elements of the list haven't to be unref. 
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::PayloadType>> getVideoPayloadTypes();
			
			/**
			 * @brief Redefine the list of the available video payload types. 
			 *
			 * @param payloadTypes A list of #PayloadType objects. LinphonePayloadType  The
			 * new list of codecs. The core does not take ownership on it. 
			 */
			LINPHONECXX_PUBLIC void setVideoPayloadTypes(const std::list<std::shared_ptr<linphone::PayloadType>> & payloadTypes);
			
			/**
			 * @brief Gets the UDP port used for video streaming. 
			 *
			 * @return The UDP port used for video streaming 
			 */
			LINPHONECXX_PUBLIC int getVideoPort() const;
			
			/**
			 * @brief Sets the UDP port used for video streaming. 
			 *
			 * A value of -1 will request the system to allocate the local port randomly. This
			 * is recommended in order to avoid firewall warnings. 
			 * 
			 * @param port The UDP port to use for video streaming 
			 */
			LINPHONECXX_PUBLIC void setVideoPort(int port);
			
			/**
			 * @brief Get the video port range from which is randomly chosen the UDP port used
			 * for video streaming. 
			 *
			 * @return a #Range object 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Range> getVideoPortsRange() const;
			
			/**
			 * @brief Get the video preset used for video calls. 
			 *
			 * @return The name of the video preset used for video calls (can be nullptr if
			 * the default video preset is used). 
			 */
			LINPHONECXX_PUBLIC std::string getVideoPreset() const;
			
			/**
			 * @brief Set the video preset to be used for video calls. 
			 *
			 * @param preset The name of the video preset to be used (can be nullptr to use
			 * the default video preset). 
			 */
			LINPHONECXX_PUBLIC void setVideoPreset(const std::string & preset);
			
			/**
			 * @brief Tells whether video preview is enabled. 
			 *
			 * @return A boolean value telling whether video preview is enabled 
			 */
			LINPHONECXX_PUBLIC bool videoPreviewEnabled() const;
			
			/**
			 * @brief Controls video preview enablement. 
			 *
			 * @param val A boolean value telling whether the video preview is to be shown
			 * Video preview refers to the action of displaying the local webcam image to the
			 * user while not in call. 
			 */
			LINPHONECXX_PUBLIC void enableVideoPreview(bool val);
			
			/**
			 * @brief Enable or disable video source reuse when switching from preview to
			 * actual video call. 
			 *
			 * This source reuse is useful when you always display the preview, even before
			 * calls are initiated. By keeping the video source for the transition to a real
			 * video call, you will smooth out the source close/reopen cycle.
			 * 
			 * This function does not have any effect durfing calls. It just indicates the
			 * #linphone::Core to initiate future calls with video source reuse or not. Also,
			 * at the end of a video call, the source will be closed whatsoever for now. 
			 * 
			 * @param enable  to enable video source reuse. true to disable it for subsequent
			 * calls. 
			 */
			LINPHONECXX_PUBLIC void enableVideoSourceReuse(bool enable);
			
			/**
			 * @brief Tells whether Wifi only mode is enabled or not. 
			 *
			 * @return A boolean value telling whether Wifi only mode is enabled or not 
			 */
			LINPHONECXX_PUBLIC bool wifiOnlyEnabled();
			
			/**
			 * @brief Turns Wifi only mode on or off. 
			 *
			 * @param val A boolean value telling whether to enable IPv6 support 
			 */
			LINPHONECXX_PUBLIC void enableWifiOnly(bool val);
			
			/**
			 * @brief Get a pointer to the sqlite db holding zrtp/lime cache. 
			 *
			 * @return An sqlite3 pointer cast to a void one or nullptr if cache is not
			 * available(not enabled at compile or access failed) 
			 */
			LINPHONECXX_PUBLIC void * getZrtpCacheDb();
			
			/**
			 * @brief Get the path to the file storing the zrtp secrets cache. 
			 *
			 * @return The path to the file storing the zrtp secrets cache. 
			 */
			LINPHONECXX_PUBLIC std::string getZrtpSecretsFile();
			
			/**
			 * @brief Set the path to the file storing the zrtp secrets cache. 
			 *
			 * @param file The path to the file to use to store the zrtp secrets cache. 
			 */
			LINPHONECXX_PUBLIC void setZrtpSecretsFile(const std::string & file);
			
			/**
			 * @brief Accept an incoming call. 
			 *
			 * Basically the application is notified of incoming calls within the
			 * call_state_changed callback of the LinphoneCoreVTable structure, where it will
			 * receive a LinphoneCallIncoming event with the associated #Call object. The
			 * application can later accept the call using this method. 
			 * 
			 * @param call The #Call object representing the call to be answered 
			 * 
			 * @return 0 on success, -1 on failure
			 * 
			 * @deprecated Use Call::accept() instead. Deprecated since 2017-02-13. 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED linphone::Status acceptCall(const std::shared_ptr<linphone::Call> & call);
			
			/**
			 * @brief Accept call modifications initiated by other end. 
			 *
			 * This call may be performed in response to a #LinphoneCallUpdatedByRemote state
			 * notification. When such notification arrives, the application can decide to
			 * call linphone_core_defer_update_call() so that it can have the time to prompt
			 * the user. Call::getRemoteParams() can be used to get information about the call
			 * parameters requested by the other party, such as whether a video stream is
			 * requested.
			 * 
			 * When the user accepts or refuse the change, acceptCallUpdate() can be done to
			 * answer to the other party. If params is nullptr, then the same call parameters
			 * established before the update request will continue to be used (no change). If
			 * params is not nullptr, then the update will be accepted according to the
			 * parameters passed. Typical example is when a user accepts to start video, then
			 * params should indicate that video stream should be used (see
			 * CallParams::enableVideo()). 
			 * 
			 * @param params A #CallParams object describing the call parameters to accept 
			 * 
			 * @return 0 if successful, -1 otherwise (actually when this function call is
			 * performed outside ot #LinphoneCallUpdatedByRemote state)
			 * 
			 * @deprecated Use Call::acceptUpdate() instead. Deprecated since 2017-02-13. 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED linphone::Status acceptCallUpdate(const std::shared_ptr<linphone::Call> & call, const std::shared_ptr<const linphone::CallParams> & params);
			
			/**
			 * @brief Accept an incoming call, with parameters. 
			 *
			 * Basically the application is notified of incoming calls within the
			 * call_state_changed callback of the LinphoneCoreVTable structure, where it will
			 * receive a LinphoneCallIncoming event with the associated #Call object. The
			 * application can later accept the call using this method. 
			 * 
			 * @param params The specific parameters for this call, for example whether video
			 * is accepted or not. Use nullptr to use default parameters 
			 * 
			 * @return 0 on success, -1 on failure
			 * 
			 * @deprecated Use Call::acceptWithParams() instead. Deprecated since 2017-02-13. 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED linphone::Status acceptCallWithParams(const std::shared_ptr<linphone::Call> & call, const std::shared_ptr<const linphone::CallParams> & params);
			
			/**
			 * @brief Accept an early media session for an incoming call. 
			 *
			 * This is identical as calling acceptEarlyMediaWithParams() with nullptr call
			 * parameters. 
			 * 
			 * @param call The incoming call to accept 
			 * 
			 * @return 0 if successful, -1 otherwise
			 * 
			 * @see acceptEarlyMediaWithParams() 
			 * 
			 * @deprecated Use Call::acceptEarlyMedia() instead. Deprecated since 2017-02-13. 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED linphone::Status acceptEarlyMedia(const std::shared_ptr<linphone::Call> & call);
			
			/**
			 * @brief When receiving an incoming, accept to start a media session as
			 * early-media. 
			 *
			 * This means the call is not accepted but audio & video streams can be
			 * established if the remote party supports early media. However, unlike after
			 * call acceptance, mic and camera input are not sent during early-media, though
			 * received audio & video are played normally. The call can then later be fully
			 * accepted using acceptCall() or acceptCallWithParams(). 
			 * 
			 * @param params The call parameters to use (can be nullptr) 
			 * 
			 * @return 0 if successful, -1 otherwise
			 * 
			 * @deprecated Use Call::acceptEarlyMediaWithParams() instead. 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED linphone::Status acceptEarlyMediaWithParams(const std::shared_ptr<linphone::Call> & call, const std::shared_ptr<const linphone::CallParams> & params);
			
			/**
			 * @brief Add all current calls into the conference. 
			 *
			 * If no conference is running a new internal conference context is created and
			 * all current calls are added to it. 
			 * 
			 * @return 0 if succeeded. Negative number if failed 
			 */
			LINPHONECXX_PUBLIC linphone::Status addAllToConference();
			
			/**
			 * @brief Adds authentication information to the #linphone::Core. 
			 *
			 * That piece of information will be used during all SIP transactions that require
			 * authentication. 
			 * 
			 * @param info The #AuthInfo to add. 
			 */
			LINPHONECXX_PUBLIC void addAuthInfo(const std::shared_ptr<const linphone::AuthInfo> & info);
			
			/**
			 * @brief Add a friend to the current buddy list, if subscription attribute  is
			 * set, a SIP SUBSCRIBE message is sent. 
			 *
			 * @param fr #Friend to add 
			 * 
			 * @deprecated use FriendList::addFriend() instead. 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED void addFriend(const std::shared_ptr<linphone::Friend> & fr);
			
			/**
			 * @brief Add a friend list. 
			 *
			 * @param list #FriendList object 
			 */
			LINPHONECXX_PUBLIC void addFriendList(const std::shared_ptr<linphone::FriendList> & list);
			
			/**
			 * @brief Add the given linphone specs to the list of functionalities the linphone
			 * client supports. 
			 *
			 * @param spec The spec to add 
			 */
			LINPHONECXX_PUBLIC void addLinphoneSpec(const std::string & spec);
			
			/**
			 * @brief Add a proxy configuration. 
			 *
			 * This will start registration on the proxy, if registration is enabled. 
			 */
			LINPHONECXX_PUBLIC linphone::Status addProxyConfig(const std::shared_ptr<linphone::ProxyConfig> & config);
			
			/**
			 * @brief This function controls signaling features supported by the core. 
			 *
			 * They are typically included in a SIP Supported header. 
			 * 
			 * @param tag The feature tag name 
			 */
			LINPHONECXX_PUBLIC void addSupportedTag(const std::string & tag);
			
			/**
			 * @brief Add a participant to the conference. 
			 *
			 * If no conference is going on a new internal conference context is created and
			 * the participant is added to it. 
			 * 
			 * @param call The current call with the participant to add 
			 * 
			 * @return 0 if succeeded. Negative number if failed 
			 */
			LINPHONECXX_PUBLIC linphone::Status addToConference(const std::shared_ptr<linphone::Call> & call);
			
			/**
			 * @brief Checks if a new version of the application is available. 
			 *
			 * @param currentVersion The current version of the application 
			 */
			LINPHONECXX_PUBLIC void checkForUpdate(const std::string & currentVersion);
			
			/**
			 * @brief Clear all authentication information. 
			 *
			 */
			LINPHONECXX_PUBLIC void clearAllAuthInfo();
			
			/**
			 * @brief Erase the call log. 
			 *
			 */
			LINPHONECXX_PUBLIC void clearCallLogs();
			
			/**
			 * @brief Erase all proxies from config. 
			 *
			 */
			LINPHONECXX_PUBLIC void clearProxyConfig();
			
			/**
			 * @brief Create a #AccountCreator and set Linphone Request callbacks. 
			 *
			 * @param xmlrpcUrl The URL to the XML-RPC server. Must be NON nullptr. 
			 * 
			 * @return The new #AccountCreator object. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::AccountCreator> createAccountCreator(const std::string & xmlrpcUrl);
			
			/**
			 * @brief Create a #Address object by parsing the user supplied address, given as
			 * a string. 
			 *
			 * @param address String containing the user supplied address 
			 * 
			 * @return The create #Address object 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Address> createAddress(const std::string & address);
			
			/**
			 * @brief Create an authentication information with default values from Linphone
			 * core. 
			 *
			 * @param domain String containing the SIP domain for which this authentication
			 * information is valid, if it has to be restricted for a single SIP domain. 
			 * 
			 * @return #AuthInfo with default values set
			 * 
			 * @deprecated use Factory::createAuthInfo() instead. 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED std::shared_ptr<linphone::AuthInfo> createAuthInfo(const std::string & username, const std::string & userid, const std::string & passwd, const std::string & ha1, const std::string & realm, const std::string & domain);
			
			/**
			 * @brief Creates a fake LinphoneCallLog. 
			 *
			 * @param quality call quality 
			 * 
			 * @return LinphoneCallLog object 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::CallLog> createCallLog(const std::shared_ptr<linphone::Address> & from, const std::shared_ptr<linphone::Address> & to, linphone::Call::Dir dir, int duration, time_t startTime, time_t connectedTime, linphone::Call::Status status, bool videoEnabled, float quality);
			
			/**
			 * @brief Create a #CallParams suitable for inviteWithParams(),
			 * acceptCallWithParams(), acceptEarlyMediaWithParams(), acceptCallUpdate(). 
			 *
			 * The parameters are initialized according to the current #linphone::Core
			 * configuration and the current state of the LinphoneCall. 
			 * 
			 * @param call #Call for which the parameters are to be build, or nullptr in the
			 * case where the parameters are to be used for a new outgoing call.    
			 * 
			 * @return A new #CallParams object 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::CallParams> createCallParams(const std::shared_ptr<linphone::Call> & call);
			
			/**
			 * @brief Create a chat room. 
			 *
			 * @param participants A list of #Address objects. LinphoneAddress  The initial
			 * list of participants of the chat room 
			 * 
			 * @return The newly created chat room. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ChatRoom> createChatRoom(const std::shared_ptr<const linphone::ChatRoomParams> & params, const std::string & subject, const std::list<std::shared_ptr<linphone::Address>> & participants);
			
			/**
			 *
			 * @param participants A list of #Address objects. LinphoneAddress  The initial
			 * list of participants of the chat room 
			 * 
			 * @return The newly created chat room. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ChatRoom> createChatRoom(const std::string & subject, const std::list<std::shared_ptr<linphone::Address>> & participants);
			
			/**
			 *
			 * @param participant #Address representing the initial participant to add to the
			 * chat room 
			 * 
			 * @return The newly created chat room. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ChatRoom> createChatRoom(const std::shared_ptr<const linphone::ChatRoomParams> & params, const std::shared_ptr<const linphone::Address> & localAddr, const std::shared_ptr<const linphone::Address> & participant);
			
			/**
			 *
			 * @param participant #Address representing the initial participant to add to the
			 * chat room 
			 * 
			 * @return The newly created chat room. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ChatRoom> createChatRoom(const std::shared_ptr<const linphone::Address> & participant);
			
			/**
			 * @brief Create a chat room. 
			 *
			 * @param participants A list of #Address objects. LinphoneAddress  The initial
			 * list of participants of the chat room 
			 * 
			 * @return The newly created chat room. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ChatRoom> createChatRoom(const std::shared_ptr<const linphone::ChatRoomParams> & params, const std::shared_ptr<const linphone::Address> & localAddr, const std::string & subject, const std::list<std::shared_ptr<linphone::Address>> & participants);
			
			/**
			 * @brief Create a client-side group chat room. 
			 *
			 * When calling this function the chat room is only created at the client-side and
			 * is empty. You need to call ChatRoom::addParticipants() to create at the server
			 * side and add participants to it. Also, the created chat room will not be a
			 * one-to-one chat room even if ChatRoom::addParticipants() is called with only
			 * one participant.
			 * 
			 * @param fallback Boolean value telling whether we should plan on being able to
			 * fallback to a basic chat room if the client-side group chat room creation fails 
			 * 
			 * @return The newly created client-side group chat room. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ChatRoom> createClientGroupChatRoom(const std::string & subject, bool fallback);
			
			/**
			 * @brief Create a client-side group chat room. 
			 *
			 * When calling this function the chat room is only created at the client-side and
			 * is empty. You need to call ChatRoom::addParticipants() to create at the server
			 * side and add participants to it. Also, the created chat room will not be a
			 * one-to-one chat room even if ChatRoom::addParticipants() is called with only
			 * one participant.
			 * 
			 * @param encrypted Boolean value telling whether we should apply encryption or
			 * not on chat messages sent and received on this room. 
			 * 
			 * @return The newly created client-side group chat room. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ChatRoom> createClientGroupChatRoom(const std::string & subject, bool fallback, bool encrypted);
			
			/**
			 * @brief Create some default conference parameters for instanciating a a
			 * conference with createConferenceWithParams(). 
			 *
			 * @return conference parameters. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ConferenceParams> createConferenceParams();
			
			/**
			 * @brief Create a conference. 
			 *
			 * @param params Parameters of the conference. See #ConferenceParams. 
			 * 
			 * @return A pointer on the freshly created conference. That object will be
			 * automatically freed by the core after calling terminateConference(). 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Conference> createConferenceWithParams(const std::shared_ptr<const linphone::ConferenceParams> & params);
			
			/**
			 * @brief Create a #Config object from a user config file. 
			 *
			 * @param filename The filename of the config file to read to fill the
			 * instantiated #Config 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Config> createConfig(const std::string & filename);
			
			/**
			 * @brief Create a content with default values from Linphone core. 
			 *
			 * @return #Content object with default values set 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Content> createContent();
			
			/**
			 * @brief Creates and returns the default chat room parameters. 
			 *
			 * @return LinphoneChatRoomParams 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ChatRoomParams> createDefaultChatRoomParams();
			
			/**
			 * @brief Create a default LinphoneFriend. 
			 *
			 * @return The created #Friend object 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Friend> createFriend();
			
			/**
			 * @brief Create a new empty #FriendList object. 
			 *
			 * @return A new #FriendList object. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::FriendList> createFriendList();
			
			/**
			 * @brief Create a #Friend from the given address. 
			 *
			 * @param address A string containing the address to create the #Friend from 
			 * 
			 * @return The created #Friend object 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Friend> createFriendWithAddress(const std::string & address);
			
			/**
			 * @brief Creates an empty info message. 
			 *
			 * @return a new LinphoneInfoMessage.
			 * 
			 * The info message can later be filled with information using
			 * InfoMessage::addHeader() or InfoMessage::setContent(), and finally sent with
			 * linphone_core_send_info_message(). 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::InfoMessage> createInfoMessage();
			
			/**
			 * @brief Create an independent media file player. 
			 *
			 * This player support WAVE and MATROSKA formats. 
			 * 
			 * @param windowId Id of the drawing window. Depend of video out 
			 * 
			 * @return A pointer on the new instance. nullptr if faild. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Player> createLocalPlayer(const std::string & soundCardName, const std::string & videoDisplayName, void * windowId);
			
			/**
			 * @brief Create a #MagicSearch object. 
			 *
			 * @return The create #MagicSearch object 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::MagicSearch> createMagicSearch();
			
			/**
			 * @brief Create a new #NatPolicy object with every policies being disabled. 
			 *
			 * @return A new #NatPolicy object. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::NatPolicy> createNatPolicy();
			
			/**
			 * @brief Create a new #NatPolicy by reading the config of a #linphone::Core
			 * according to the passed ref. 
			 *
			 * @param ref The reference of a NAT policy in the config of the #linphone::Core 
			 * 
			 * @return A new #NatPolicy object. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::NatPolicy> createNatPolicyFromConfig(const std::string & ref);
			
			/**
			 * @brief Create an out-of-dialog notification, specifying the destination
			 * resource, the event name. 
			 *
			 * The notification can be send with Event::notify(). 
			 * 
			 * @param event the event name 
			 * 
			 * @return a #Event holding the context of the notification. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Event> createNotify(const std::shared_ptr<const linphone::Address> & resource, const std::string & event);
			
			/**
			 * @brief Create a publish context for a one-shot publish. 
			 *
			 * After being created, the publish must be sent using Event::sendPublish(). The
			 * #Event is automatically terminated when the publish transaction is finished,
			 * either with success or failure. The application must not call
			 * Event::terminate() for such one-shot publish. 
			 * 
			 * @param event the event name 
			 * 
			 * @return the #Event holding the context of the publish. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Event> createOneShotPublish(const std::shared_ptr<const linphone::Address> & resource, const std::string & event);
			
			/**
			 * @brief Create a #PresenceActivity with the given type and description. 
			 *
			 * @param description An additional description of the activity to set for the
			 * activity. Can be nullptr if no additional description is to be added. 
			 * 
			 * @return The created #PresenceActivity object. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::PresenceActivity> createPresenceActivity(linphone::PresenceActivity::Type acttype, const std::string & description);
			
			/**
			 * @brief Create a default LinphonePresenceModel. 
			 *
			 * @return The created #PresenceModel object. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::PresenceModel> createPresenceModel();
			
			/**
			 * @brief Create a #PresenceModel with the given activity type and activity
			 * description. 
			 *
			 * @param description An additional description of the activity to set for the
			 * activity. Can be nullptr if no additional description is to be added. 
			 * 
			 * @return The created #PresenceModel object. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::PresenceModel> createPresenceModelWithActivity(linphone::PresenceActivity::Type acttype, const std::string & description);
			
			/**
			 * @brief Create a #PresenceModel with the given activity type, activity
			 * description, note content and note language. 
			 *
			 * @param lang The language of the note to be added to the created model. 
			 * 
			 * @return The created #PresenceModel object. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::PresenceModel> createPresenceModelWithActivityAndNote(linphone::PresenceActivity::Type acttype, const std::string & description, const std::string & note, const std::string & lang);
			
			/**
			 * @brief Create a #PresenceNote with the given content and language. 
			 *
			 * @param lang The language of the note to be created. 
			 * 
			 * @return The created #PresenceNote object. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::PresenceNote> createPresenceNote(const std::string & content, const std::string & lang);
			
			/**
			 * @brief Create a #PresencePerson with the given id. 
			 *
			 * @param id The id of the person to be created. 
			 * 
			 * @return The created #PresencePerson object. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::PresencePerson> createPresencePerson(const std::string & id);
			
			/**
			 * @brief Create a #PresenceService with the given id, basic status and contact. 
			 *
			 * @param contact A string containing a contact information corresponding to the
			 * service to be created. 
			 * 
			 * @return The created #PresenceService object. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::PresenceService> createPresenceService(const std::string & id, linphone::PresenceBasicStatus basicStatus, const std::string & contact);
			
			/**
			 * @brief Same as getPrimaryContact() but the result is a #Address object instead
			 * of const char *. 
			 *
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Address> createPrimaryContactParsed();
			
			/**
			 * @brief Create a proxy config with default values from Linphone core. 
			 *
			 * @return #ProxyConfig with default values set 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ProxyConfig> createProxyConfig();
			
			/**
			 * @brief Create a publish context for an event state. 
			 *
			 * After being created, the publish must be sent using Event::sendPublish(). After
			 * expiry, the publication is refreshed unless it is terminated before. 
			 * 
			 * @param expires the lifetime of event being published, -1 if no associated
			 * duration, in which case it will not be refreshed. 
			 * 
			 * @return the #Event holding the context of the publish. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Event> createPublish(const std::shared_ptr<const linphone::Address> & resource, const std::string & event, int expires);
			
			/**
			 * @brief Create an outgoing subscription, specifying the destination resource,
			 * the event name, and an optional content body. 
			 *
			 * If accepted, the subscription runs for a finite period, but is automatically
			 * renewed if not terminated before. Unlike subscribe() the subscription isn't
			 * sent immediately. It will be send when calling Event::sendSubscribe(). 
			 * 
			 * @param expires the whished duration of the subscription 
			 * 
			 * @return a #Event holding the context of the created subcription. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Event> createSubscribe(const std::shared_ptr<const linphone::Address> & resource, const std::shared_ptr<linphone::ProxyConfig> & proxy, const std::string & event, int expires);
			
			/**
			 * @brief Create an outgoing subscription, specifying the destination resource,
			 * the event name, and an optional content body. 
			 *
			 * If accepted, the subscription runs for a finite period, but is automatically
			 * renewed if not terminated before. Unlike subscribe() the subscription isn't
			 * sent immediately. It will be send when calling Event::sendSubscribe(). 
			 * 
			 * @param expires the whished duration of the subscription 
			 * 
			 * @return a #Event holding the context of the created subcription. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Event> createSubscribe(const std::shared_ptr<const linphone::Address> & resource, const std::string & event, int expires);
			
			/**
			 * @brief Create a #XmlRpcSession for a given url. 
			 *
			 * @param url The URL to the XML-RPC server. Must be NON nullptr. 
			 * 
			 * @return The new #XmlRpcSession object. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::XmlRpcSession> createXmlRpcSession(const std::string & url);
			
			/**
			 * @brief Decline a pending incoming call, with a reason. 
			 *
			 * @param reason The reason for rejecting the call: LinphoneReasonDeclined or
			 * LinphoneReasonBusy 
			 * 
			 * @return 0 on success, -1 on failure
			 * 
			 * @deprecated Use Call::decline() instead. Deprecated since 2017-02-13. 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED linphone::Status declineCall(const std::shared_ptr<linphone::Call> & call, linphone::Reason reason);
			
			/**
			 * @brief When receiving a #LinphoneCallUpdatedByRemote state notification,
			 * prevent #linphone::Core from performing an automatic answer. 
			 *
			 * When receiving a #LinphoneCallUpdatedByRemote state notification (ie an
			 * incoming reINVITE), the default behaviour of #linphone::Core is defined by the
			 * "defer_update_default" option of the "sip" section of the config. If this
			 * option is 0 (the default) then the #linphone::Core automatically answers the
			 * reINIVTE with call parameters unchanged. However when for example when the
			 * remote party updated the call to propose a video stream, it can be useful to
			 * prompt the user before answering. This can be achieved by calling
			 * deferCallUpdate() during the call state notification, to deactivate the
			 * automatic answer that would just confirm the audio but reject the video. Then,
			 * when the user responds to dialog prompt, it becomes possible to call
			 * acceptCallUpdate() to answer the reINVITE, with eventually video enabled in the
			 * #CallParams argument.
			 * 
			 * The #LinphoneCallUpdatedByRemote notification can also arrive when receiving an
			 * INVITE without SDP. In such case, an unchanged offer is made in the 200Ok, and
			 * when the ACK containing the SDP answer is received,
			 * #LinphoneCallUpdatedByRemote is triggered to notify the application of possible
			 * changes in the media session. However in such case defering the update has no
			 * meaning since we just generating an offer.
			 * 
			 * @param call The call for which to defer the update 
			 * 
			 * @return 0 if successful, -1 if the deferCallUpdate() was done outside a valid
			 * #LinphoneCallUpdatedByRemote notification
			 * 
			 * @deprecated Use Call::deferUpdate() instead 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED linphone::Status deferCallUpdate(const std::shared_ptr<linphone::Call> & call);
			
			/**
			 * @brief Removes a chatroom including all message history from the LinphoneCore. 
			 *
			 * @param cr A #ChatRoom object 
			 */
			LINPHONECXX_PUBLIC void deleteChatRoom(const std::shared_ptr<linphone::ChatRoom> & cr);
			
			/**
			 * @brief Inconditionnaly disable incoming chat messages. 
			 *
			 * @param denyReason the deny reason (LinphoneReasonNone has no effect). 
			 */
			LINPHONECXX_PUBLIC void disableChat(linphone::Reason denyReason);
			
			/**
			 * @brief Enable reception of incoming chat messages. 
			 *
			 * By default it is enabled but it can be disabled with disableChat(). 
			 */
			LINPHONECXX_PUBLIC void enableChat();
			
			/**
			 * @brief Tells to #linphone::Core to use Linphone Instant Messaging encryption. 
			 *
			 * @param val The new lime state
			 * 
			 * @deprecated Use linphone_core_enable_lime_x3dh instead. Depreacted since
			 * 2019-02-04 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED void enableLime(linphone::LimeState val);
			
			/**
			 * @brief Call this method when you receive a push notification. 
			 *
			 * It will ensure the proxy configs are correctly registered to the proxy server,
			 * so the call or the message will be correctly delivered. 
			 */
			LINPHONECXX_PUBLIC void ensureRegistered();
			
			/**
			 * @brief This method is called by the application to notify the linphone core
			 * library when it enters background mode. 
			 *
			 */
			LINPHONECXX_PUBLIC void enterBackground();
			
			/**
			 * @brief Join the local participant to the running conference. 
			 *
			 * @return 0 if succeeded. Negative number if failed 
			 */
			LINPHONECXX_PUBLIC linphone::Status enterConference();
			
			/**
			 * @brief This method is called by the application to notify the linphone core
			 * library when it enters foreground mode. 
			 *
			 */
			LINPHONECXX_PUBLIC void enterForeground();
			
			/**
			 * @brief Returns whether a specific file format is supported. 
			 *
			 * @see linphone_core_get_supported_file_formats 
			 * 
			 * @param fmt The format extension (wav, mkv). 
			 */
			LINPHONECXX_PUBLIC bool fileFormatSupported(const std::string & fmt);
			
			/**
			 * @brief Find authentication info matching realm, username, domain criteria. 
			 *
			 * First of all, (realm,username) pair are searched. If multiple results (which
			 * should not happen because realm are supposed to be unique), then domain is
			 * added to the search. 
			 * 
			 * @param sipDomain the SIP domain name (optional) 
			 * 
			 * @return a #AuthInfo 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::AuthInfo> findAuthInfo(const std::string & realm, const std::string & username, const std::string & sipDomain);
			
			/**
			 * @brief Search from the list of current calls if a remote address match uri. 
			 *
			 * @param uri which should match call remote uri 
			 * 
			 * @return #Call or nullptr is no match is found 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Call> findCallFromUri(const std::string & uri) const;
			
			/**
			 * @brief Get the call log matching the call id, or nullptr if can't be found. 
			 *
			 * @param callId Call id of the call log to find 
			 * 
			 * @return {LinphoneCallLog} 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::CallLog> findCallLogFromCallId(const std::string & callId);
			
			/**
			 * @brief Find a chat room. 
			 *
			 * No reference is transfered to the application. The #linphone::Core keeps a
			 * reference on the chat room. 
			 * 
			 * @param localAddr a linphone address. 
			 * 
			 * @return #ChatRoom where messaging can take place. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ChatRoom> findChatRoom(const std::shared_ptr<const linphone::Address> & peerAddr, const std::shared_ptr<const linphone::Address> & localAddr) const;
			
			/**
			 * @brief Retrieves a list of #Address sort and filter. 
			 *
			 * @param sipOnly Only sip address or not 
			 * 
			 * @return A list of #Address objects. LinphoneAddress  a list of filtered
			 * #Address + the #Address created with the filter 
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::Address>> findContactsByChar(const std::string & filter, bool sipOnly);
			
			/**
			 * @brief Search a #Friend by its address. 
			 *
			 * @param addr The address to use to search the friend. 
			 * 
			 * @return The #Friend object corresponding to the given address. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Friend> findFriend(const std::shared_ptr<const linphone::Address> & addr) const;
			
			/**
			 * @brief Search all #Friend matching an address. 
			 *
			 * @param addr The address to use to search the friends. 
			 * 
			 * @return A list of #Friend objects. LinphoneFriend  a list of #Friend
			 * corresponding to the given address. 
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::Friend>> findFriends(const std::shared_ptr<const linphone::Address> & addr) const;
			
			/**
			 * @brief Find a one to one chat room. 
			 *
			 * No reference is transfered to the application. The #linphone::Core keeps a
			 * reference on the chat room. 
			 * 
			 * @param participantAddr a linphone address. 
			 * 
			 * @return #ChatRoom where messaging can take place. 
			 * 
			 * @deprecated Use linphone_core_find_one_to_one_chat_room_2 instead 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED std::shared_ptr<linphone::ChatRoom> findOneToOneChatRoom(const std::shared_ptr<const linphone::Address> & localAddr, const std::shared_ptr<const linphone::Address> & participantAddr) const;
			
			/**
			 * @brief Find a one to one chat room. 
			 *
			 * No reference is transfered to the application. The #linphone::Core keeps a
			 * reference on the chat room. 
			 * 
			 * @param encrypted whether to look for an encrypted chat room or not 
			 * 
			 * @return #ChatRoom where messaging can take place. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ChatRoom> findOneToOneChatRoom(const std::shared_ptr<const linphone::Address> & localAddr, const std::shared_ptr<const linphone::Address> & participantAddr, bool encrypted) const;
			
			/**
			 * @brief Get the call with the remote_address specified. 
			 *
			 * @param remoteAddress The remote address of the call that we want to get 
			 * 
			 * @return The call if it has been found, nullptr otherwise 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Call> getCallByRemoteAddress(const std::string & remoteAddress) const;
			
			/**
			 * @brief Get the call with the remote_address specified. 
			 *
			 * @param remoteAddress 
			 * 
			 * @return the #Call of the call if found 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Call> getCallByRemoteAddress2(const std::shared_ptr<const linphone::Address> & remoteAddress) const;
			
			/**
			 * @brief Get the list of call logs (past calls). 
			 *
			 * At the contrary of linphone_core_get_call_logs, it is your responsibility to
			 * unref the logs and free this list once you are done using it. 
			 * 
			 * @param peerAddr A #Address object. 
			 * 
			 * @return A list of #CallLog objects. LinphoneCallLog  The objects inside the
			 * list are freshly allocated with a reference counter equal to one, so they need
			 * to be freed on list destruction with bctbx_list_free_with_data() for instance. 
			 *  
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::CallLog>> getCallHistory(const std::shared_ptr<const linphone::Address> & peerAddr, const std::shared_ptr<const linphone::Address> & localAddr);
			
			/**
			 * @brief Get the list of call logs (past calls) that matches the given #Address. 
			 *
			 * At the contrary of linphone_core_get_call_logs, it is your responsibility to
			 * unref the logs and free this list once you are done using it. 
			 * 
			 * @param addr #Address object 
			 * 
			 * @return A list of #CallLog objects. LinphoneCallLog  The objects inside the
			 * list are freshly allocated with a reference counter equal to one, so they need
			 * to be freed on list destruction with bctbx_list_free_with_data() for instance. 
			 *  
			 * 
			 * @deprecated Use linphone_core_get_call_history_2 instead. Deprecated since
			 * 2018-10-29. 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED std::list<std::shared_ptr<linphone::CallLog>> getCallHistoryForAddress(const std::shared_ptr<const linphone::Address> & addr);
			
			/**
			 * @brief Get a basic chat room. 
			 *
			 * If it does not exist yet, it will be created. No reference is transfered to the
			 * application. The #linphone::Core keeps a reference on the chat room. 
			 * 
			 * @param localAddr a linphone address. 
			 * 
			 * @return #ChatRoom where messaging can take place. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ChatRoom> getChatRoom(const std::shared_ptr<const linphone::Address> & peerAddr, const std::shared_ptr<const linphone::Address> & localAddr);
			
			/**
			 * @brief Get a basic chat room whose peer is the supplied address. 
			 *
			 * If it does not exist yet, it will be created. No reference is transfered to the
			 * application. The #linphone::Core keeps a reference on the chat room. 
			 * 
			 * @param addr a linphone address. 
			 * 
			 * @return #ChatRoom where messaging can take place. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ChatRoom> getChatRoom(const std::shared_ptr<const linphone::Address> & addr);
			
			/**
			 * @brief Get a basic chat room for messaging from a sip uri like
			 * sip:joe@sip.linphone.org. 
			 *
			 * If it does not exist yet, it will be created. No reference is transfered to the
			 * application. The #linphone::Core keeps a reference on the chat room. 
			 * 
			 * @param to The destination address for messages. 
			 * 
			 * @return #ChatRoom where messaging can take place. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ChatRoom> getChatRoomFromUri(const std::string & to);
			
			/**
			 * @brief Search a #Friend by its reference key. 
			 *
			 * @param key The reference key to use to search the friend. 
			 * 
			 * @return The #Friend object corresponding to the given reference key. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Friend> getFriendByRefKey(const std::string & key) const;
			
			/**
			 * @brief Retrieves the list of #Friend from the core that has the given display
			 * name. 
			 *
			 * @param name the name of the list 
			 * 
			 * @return the first #FriendList object or nullptr 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::FriendList> getFriendListByName(const std::string & name) const;
			
			/**
			 * @brief Get payload type from mime type and clock rate. 
			 *
			 * This function searches in audio and video codecs for the given payload type
			 * name and clockrate. 
			 * 
			 * @param channels number of channels, can be
			 * LINPHONE_FIND_PAYLOAD_IGNORE_CHANNELS 
			 * 
			 * @return Returns nullptr if not found. If a #PayloadType is returned, it must be
			 * released with linphone_payload_type_unref after using it. 
			 * 
			 * @warning The returned payload type is allocated as a floating reference i.e.
			 * the reference counter is initialized to 0. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::PayloadType> getPayloadType(const std::string & type, int rate, int channels);
			
			/**
			 *
			 * @param idkey An arbitrary idkey string associated to a proxy configuration 
			 * 
			 * @return the proxy configuration for the given idkey value, or nullptr if none
			 * found 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::ProxyConfig> getProxyConfigByIdkey(const std::string & idkey);
			
			/**
			 * @brief Return the unread chat message count for a given local address. 
			 *
			 * @param address #Address object. 
			 * 
			 * @return The unread chat message count. 
			 */
			LINPHONECXX_PUBLIC int getUnreadChatMessageCountFromLocal(const std::shared_ptr<const linphone::Address> & address) const;
			
			/**
			 * @brief Get the zrtp sas validation status for a peer uri. 
			 *
			 * Once the SAS has been validated or rejected, the status will never return to
			 * Unknown (unless you delete your cache) 
			 * 
			 * @param addr the peer uri
			 * 
			 * @return - LinphoneZrtpPeerStatusUnknown: this uri is not present in cache OR
			 * during calls with the active device, SAS never was validated or rejected
			 * 
			 */
			LINPHONECXX_PUBLIC linphone::ZrtpPeerStatus getZrtpStatus(const std::string & addr);
			
			/**
			 * @brief Check whether the device has a hardware echo canceller. 
			 *
			 * @return  if it does, true otherwise 
			 */
			LINPHONECXX_PUBLIC bool hasBuiltinEchoCanceller();
			
			/**
			 * @brief Check whether the device is flagged has crappy opengl. 
			 *
			 * @return  if crappy opengl flag is set, true otherwise 
			 */
			LINPHONECXX_PUBLIC bool hasCrappyOpengl();
			
			/**
			 * @brief Tells whether there is a call running. 
			 *
			 * @return A boolean value telling whether a call is currently running or not 
			 */
			LINPHONECXX_PUBLIC bool inCall() const;
			
			/**
			 * @brief See linphone_proxy_config_normalize_sip_uri for documentation. 
			 *
			 * Default proxy config is used to parse the address. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Address> interpretUrl(const std::string & url);
			
			/**
			 * @brief Initiates an outgoing call. 
			 *
			 * The application doesn't own a reference to the returned LinphoneCall object.
			 * Use linphone_call_ref to safely keep the LinphoneCall pointer valid within your
			 * application.
			 * 
			 * @param url The destination of the call (sip address, or phone number). 
			 * 
			 * @return A #Call object or nullptr in case of failure 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Call> invite(const std::string & url);
			
			/**
			 * @brief Initiates an outgoing call given a destination #Address The #Address can
			 * be constructed directly using linphone_address_new, or created by
			 * interpretUrl(). 
			 *
			 * The application doesn't own a reference to the returned #Call object. Use
			 * linphone_call_ref to safely keep the #Call pointer valid within your
			 * application. 
			 * 
			 * @param addr The destination of the call (sip address). 
			 * 
			 * @return A #Call object or nullptr in case of failure 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Call> inviteAddress(const std::shared_ptr<const linphone::Address> & addr);
			
			/**
			 * @brief Initiates an outgoing call given a destination #Address The #Address can
			 * be constructed directly using linphone_address_new, or created by
			 * interpretUrl(). 
			 *
			 * The application doesn't own a reference to the returned #Call object. Use
			 * linphone_call_ref to safely keep the #Call pointer valid within your
			 * application. 
			 * 
			 * @param params Call parameters 
			 * 
			 * @return A #Call object or nullptr in case of failure 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Call> inviteAddressWithParams(const std::shared_ptr<const linphone::Address> & addr, const std::shared_ptr<const linphone::CallParams> & params);
			
			/**
			 * @brief Initiates an outgoing call according to supplied call parameters The
			 * application doesn't own a reference to the returned #Call object. 
			 *
			 * Use linphone_call_ref to safely keep the #Call pointer valid within your
			 * application. 
			 * 
			 * @param params Call parameters 
			 * 
			 * @return A #Call object or nullptr in case of failure 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Call> inviteWithParams(const std::string & url, const std::shared_ptr<const linphone::CallParams> & params);
			
			/**
			 * @brief Checks if the given media filter is loaded and usable. 
			 *
			 * This is for advanced users of the library, mainly to expose mediastreamer video
			 * filter status. 
			 * 
			 * @param filtername the filter name 
			 * 
			 * @return true if the filter is loaded and usable, false otherwise 
			 */
			LINPHONECXX_PUBLIC bool isMediaFilterSupported(const std::string & filtername);
			
			/**
			 * @brief Main loop function. 
			 *
			 * It is crucial that your application call it periodically.
			 * 
			 * iterate() performs various backgrounds tasks:
			 * 
			 */
			LINPHONECXX_PUBLIC void iterate();
			
			/**
			 * @brief Make the local participant leave the running conference. 
			 *
			 * @return 0 if succeeded. Negative number if failed 
			 */
			LINPHONECXX_PUBLIC linphone::Status leaveConference();
			
			/**
			 * @brief Tells if lime is available. 
			 *
			 * @deprecated Use linphone_core_lime_x3dh_available instead. Depreacted since
			 * 2019-02-04 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED bool limeAvailable() const;
			
			/**
			 * @brief Returns the lime state. 
			 *
			 * @return The current lime state
			 * 
			 * @deprecated Use linphone_core_lime_x3dh_enabled instead. Depreacted since
			 * 2019-02-04 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED linphone::LimeState limeEnabled() const;
			
			/**
			 * @brief Tells if LIME X3DH is available. 
			 *
			 */
			LINPHONECXX_PUBLIC bool limeX3DhAvailable() const;
			
			/**
			 * @brief Update current config with the content of a xml config file. 
			 *
			 * @param xmlUri the path to the xml file 
			 */
			LINPHONECXX_PUBLIC void loadConfigFromXml(const std::string & xmlUri);
			
			/**
			 * @brief Check if a media encryption type is supported. 
			 *
			 * @param menc LinphoneMediaEncryption 
			 * 
			 * @return whether a media encryption scheme is supported by the #linphone::Core
			 * engine 
			 */
			LINPHONECXX_PUBLIC bool mediaEncryptionSupported(linphone::MediaEncryption menc) const;
			
			/**
			 * @brief Migrates the call logs from the linphonerc to the database if not done
			 * yet. 
			 *
			 */
			LINPHONECXX_PUBLIC void migrateLogsFromRcToDb();
			
			/**
			 * @brief Migrate configuration so that all SIP transports are enabled. 
			 *
			 * Versions of linphone < 3.7 did not support using multiple SIP transport
			 * simultaneously. This function helps application to migrate the configuration so
			 * that all transports are enabled. Existing proxy configuration are added a
			 * transport parameter so that they continue using the unique transport that was
			 * set previously. This function must be used just after creating the core, before
			 * any call to iterate() 
			 * 
			 * @return 1 if migration was done, 0 if not done because unnecessary or already
			 * done, -1 in case of error. 
			 */
			LINPHONECXX_PUBLIC linphone::Status migrateToMultiTransport();
			
			/**
			 * @brief Notify all friends that have subscribed. 
			 *
			 * @param presence #PresenceModel to notify 
			 */
			LINPHONECXX_PUBLIC void notifyAllFriends(const std::shared_ptr<linphone::PresenceModel> & presence);
			
			/**
			 * @brief Notifies the upper layer that a presence status has been received by
			 * calling the appropriate callback if one has been set. 
			 *
			 * This method is for advanced usage, where customization of the liblinphone's
			 * internal behavior is required. 
			 * 
			 * @param lf the #Friend whose presence information has been received. 
			 */
			LINPHONECXX_PUBLIC void notifyNotifyPresenceReceived(const std::shared_ptr<linphone::Friend> & lf);
			
			/**
			 * @brief Notifies the upper layer that a presence model change has been received
			 * for the uri or telephone number given as a parameter, by calling the
			 * appropriate callback if one has been set. 
			 *
			 * This method is for advanced usage, where customization of the liblinphone's
			 * internal behavior is required. 
			 * 
			 * @param presenceModel the #PresenceModel that has been modified 
			 */
			LINPHONECXX_PUBLIC void notifyNotifyPresenceReceivedForUriOrTel(const std::shared_ptr<linphone::Friend> & lf, const std::string & uriOrTel, const std::shared_ptr<const linphone::PresenceModel> & presenceModel);
			
			/**
			 * @brief Pause all currently running calls. 
			 *
			 * @return 0 
			 */
			LINPHONECXX_PUBLIC linphone::Status pauseAllCalls();
			
			/**
			 * @brief Pauses the call. 
			 *
			 * If a music file has been setup using setPlayFile(), this file will be played to
			 * the remote user.
			 * 
			 * The only way to resume a paused call is to call resumeCall(). 
			 * 
			 * @param call The call to pause 
			 * 
			 * @return 0 on success, -1 on failure
			 * 
			 * @see resumeCall() 
			 * 
			 * @deprecated Use Call::pause() instead. Deprecated since 2017-02-13. 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED linphone::Status pauseCall(const std::shared_ptr<linphone::Call> & call);
			
			/**
			 * @brief Plays a dtmf sound to the local user. 
			 *
			 * @param durationMs Duration in ms, -1 means play until next further call to
			 * stopDtmf() 
			 */
			LINPHONECXX_PUBLIC void playDtmf(char dtmf, int durationMs);
			
			/**
			 * @brief Plays an audio file to the local user. 
			 *
			 * This function works at any time, during calls, or when no calls are running. It
			 * doesn't request the underlying audio system to support multiple playback
			 * streams. 
			 * 
			 * @param audiofile The path to an audio file in wav PCM 16 bit format 
			 * 
			 * @return 0 on success, -1 on error 
			 */
			LINPHONECXX_PUBLIC linphone::Status playLocal(const std::string & audiofile);
			
			/**
			 * @brief Call generic OpenGL render for a given core. 
			 *
			 */
			LINPHONECXX_PUBLIC void previewOglRender() const;
			
			/**
			 * @brief Publish an event state. 
			 *
			 * This first create a #Event with createPublish() and calls Event::sendPublish()
			 * to actually send it. After expiry, the publication is refreshed unless it is
			 * terminated before. 
			 * 
			 * @param body the actual published data 
			 * 
			 * @return the #Event holding the context of the publish. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Event> publish(const std::shared_ptr<const linphone::Address> & resource, const std::string & event, int expires, const std::shared_ptr<const linphone::Content> & body);
			
			/**
			 * @brief Redirect the specified call to the given redirect URI. 
			 *
			 * @param redirectUri The URI to redirect the call to 
			 * 
			 * @return 0 if successful, -1 on error.
			 * 
			 * @deprecated Use Call::redirect() instead. Deprecated since 2017-02-13. 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED linphone::Status redirectCall(const std::shared_ptr<linphone::Call> & call, const std::string & redirectUri);
			
			/**
			 * @brief force registration refresh to be initiated upon next iterate 
			 *
			 */
			LINPHONECXX_PUBLIC void refreshRegisters();
			
			/**
			 * @brief Black list a friend. 
			 *
			 * same as Friend::setIncSubscribePolicy() with LinphoneSPDeny policy; 
			 * 
			 * @param lf #Friend to add 
			 */
			LINPHONECXX_PUBLIC void rejectSubscriber(const std::shared_ptr<linphone::Friend> & lf);
			
			/**
			 * @brief Reload mediastreamer2 plugins from specified directory. 
			 *
			 * @param path the path from where plugins are to be loaded, pass nullptr to use
			 * default (compile-time determined) plugin directory. 
			 */
			LINPHONECXX_PUBLIC void reloadMsPlugins(const std::string & path);
			
			/**
			 * @brief Update detection of sound devices. 
			 *
			 * Use this function when the application is notified of USB plug events, so that
			 * list of available hardwares for sound playback and capture is updated. 
			 */
			LINPHONECXX_PUBLIC void reloadSoundDevices();
			
			/**
			 * @brief Update detection of camera devices. 
			 *
			 * Use this function when the application is notified of USB plug events, so that
			 * list of available hardwares for video capture is updated. 
			 */
			LINPHONECXX_PUBLIC void reloadVideoDevices();
			
			/**
			 * @brief Removes an authentication information object. 
			 *
			 * @param info The #AuthInfo to remove. 
			 */
			LINPHONECXX_PUBLIC void removeAuthInfo(const std::shared_ptr<const linphone::AuthInfo> & info);
			
			/**
			 * @brief Remove a specific call log from call history list. 
			 *
			 * This function destroys the call log object. It must not be accessed anymore by
			 * the application after calling this function. 
			 * 
			 * @param callLog #CallLog object to remove. 
			 */
			LINPHONECXX_PUBLIC void removeCallLog(const std::shared_ptr<linphone::CallLog> & callLog);
			
			/**
			 * @brief Removes a friend list. 
			 *
			 * @param list #FriendList object 
			 */
			LINPHONECXX_PUBLIC void removeFriendList(const std::shared_ptr<linphone::FriendList> & list);
			
			/**
			 * @brief Remove a call from the conference. 
			 *
			 * @param call a call that has been previously merged into the conference.
			 * 
			 * After removing the remote participant belonging to the supplied call, the call
			 * becomes a normal call in paused state. If one single remote participant is left
			 * alone together with the local user in the conference after the removal, then
			 * the conference is automatically transformed into a simple call in
			 * StreamsRunning state. The conference's resources are then automatically
			 * destroyed.
			 * 
			 * In other words, unless leaveConference() is explicitly called, the last remote
			 * participant of a conference is automatically put in a simple call in running
			 * state.
			 * 
			 * @return 0 if successful, -1 otherwise. 
			 */
			LINPHONECXX_PUBLIC linphone::Status removeFromConference(const std::shared_ptr<linphone::Call> & call);
			
			/**
			 * @brief Remove the given linphone specs from the list of functionalities the
			 * linphone client supports. 
			 *
			 * @param spec The spec to remove 
			 */
			LINPHONECXX_PUBLIC void removeLinphoneSpec(const std::string & spec);
			
			/**
			 * @brief Removes a proxy configuration. 
			 *
			 * #linphone::Core will then automatically unregister and place the proxy
			 * configuration on a deleted list. For that reason, a removed proxy does NOT need
			 * to be freed. 
			 */
			LINPHONECXX_PUBLIC void removeProxyConfig(const std::shared_ptr<linphone::ProxyConfig> & config);
			
			/**
			 * @brief Remove a supported tag. 
			 *
			 * @param tag The tag to remove
			 * 
			 * @see addSupportedTag() 
			 */
			LINPHONECXX_PUBLIC void removeSupportedTag(const std::string & tag);
			
			/**
			 * @brief Reset the counter of missed calls. 
			 *
			 */
			LINPHONECXX_PUBLIC void resetMissedCallsCount();
			
			/**
			 * @brief Resumes a call. 
			 *
			 * The call needs to have been paused previously with pauseCall(). 
			 * 
			 * @param call The call to resume 
			 * 
			 * @return 0 on success, -1 on failure
			 * 
			 * @see pauseCall() 
			 * 
			 * @deprecated Use Call::resume() instead. Deprecated since 2017-02-13. 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED linphone::Status resumeCall(const std::shared_ptr<linphone::Call> & call);
			
			/**
			 * @brief Sets the UDP port range from which to randomly select the port used for
			 * audio streaming. 
			 *
			 * @param maxPort The upper bound of the audio port range to use 
			 */
			LINPHONECXX_PUBLIC void setAudioPortRange(int minPort, int maxPort);
			
			/**
			 * @brief Assign an audio file to be played locally upon call failure, for a given
			 * reason. 
			 *
			 * @param audiofile a wav file to be played when such call failure happens. 
			 */
			LINPHONECXX_PUBLIC void setCallErrorTone(linphone::Reason reason, const std::string & audiofile);
			
			/**
			 * @brief Set the rectangle where the decoder will search a QRCode. 
			 *
			 * @param h height 
			 */
			LINPHONECXX_PUBLIC void setQrcodeDecodeRect(const int x, const int y, const int w, const int h);
			
			/**
			 * @brief Sets the UDP port range from which to randomly select the port used for
			 * text streaming. 
			 *
			 * @param maxPort The upper bound of the text port range to use 
			 */
			LINPHONECXX_PUBLIC void setTextPortRange(int minPort, int maxPort);
			
			/**
			 * @brief Set the user agent string used in SIP messages. 
			 *
			 * Set the user agent string used in SIP messages as "[ua_name]/[version]". No
			 * slash character will be printed if nullptr is given to "version". If nullptr is
			 * given to "ua_name" and "version" both, the User-agent header will be empty.
			 * 
			 * This function should be called just after linphone_factory_create_core ideally. 
			 * 
			 * @param version Version of the user agent. 
			 */
			LINPHONECXX_PUBLIC void setUserAgent(const std::string & uaName, const std::string & version);
			
			/**
			 * @brief Sets the UDP port range from which to randomly select the port used for
			 * video streaming. 
			 *
			 * @param maxPort The upper bound of the video port range to use 
			 */
			LINPHONECXX_PUBLIC void setVideoPortRange(int minPort, int maxPort);
			
			/**
			 * @brief Tells whether a specified sound device can capture sound. 
			 *
			 * @param device the device name as returned by linphone_core_get_sound_devices 
			 * 
			 * @return A boolean value telling whether the specified sound device can capture
			 * sound 
			 */
			LINPHONECXX_PUBLIC bool soundDeviceCanCapture(const std::string & device);
			
			/**
			 * @brief Tells whether a specified sound device can play sound. 
			 *
			 * @param device the device name as returned by linphone_core_get_sound_devices 
			 * 
			 * @return A boolean value telling whether the specified sound device can play
			 * sound 
			 */
			LINPHONECXX_PUBLIC bool soundDeviceCanPlayback(const std::string & device);
			
			/**
			 * @brief Check if a call will need the sound resources in near future (typically
			 * an outgoing call that is awaiting response). 
			 *
			 * In liblinphone, it is not possible to have two independant calls using sound
			 * device or camera at the same time. In order to prevent this situation, an
			 * application can use soundResourcesLocked() to know whether it is possible at a
			 * given time to start a new outgoing call. When the function returns true, an
			 * application should not allow the user to start an outgoing call. 
			 * 
			 * @return A boolean value telling whether a call will need the sound resources in
			 * near future 
			 */
			LINPHONECXX_PUBLIC bool soundResourcesLocked();
			
			/**
			 * @brief Start a #linphone::Core object after it has been instantiated and not
			 * automatically started. 
			 *
			 * Also re-initialize a #linphone::Core object that has been stopped using stop().
			 * Must be called only if LinphoneGlobalState is either Ready of Off. State will
			 * changed to Startup, Configuring and then On.
			 * 
			 * @return 0: success, -1: global failure, -2: could not connect database 
			 */
			LINPHONECXX_PUBLIC linphone::Status start();
			
			/**
			 * @brief Start recording the running conference. 
			 *
			 * @param path Path to the file where the recording will be written 
			 * 
			 * @return 0 if succeeded. Negative number if failed 
			 */
			LINPHONECXX_PUBLIC linphone::Status startConferenceRecording(const std::string & path);
			
			/**
			 * @brief Special function to warm up dtmf feeback stream. 
			 *
			 * linphone_core_stop_dtmf_stream must() be called before entering FG mode 
			 */
			LINPHONECXX_PUBLIC void startDtmfStream();
			
			/**
			 * @brief Starts an echo calibration of the sound devices, in order to find
			 * adequate settings for the echo canceler automatically. 
			 *
			 * @return LinphoneStatus whether calibration has started or not. 
			 */
			LINPHONECXX_PUBLIC linphone::Status startEchoCancellerCalibration();
			
			/**
			 * @brief Start the simulation of call to test the latency with an external
			 * device. 
			 *
			 * @param rate Sound sample rate. 
			 */
			LINPHONECXX_PUBLIC linphone::Status startEchoTester(unsigned int rate);
			
			/**
			 * @brief Stop a #linphone::Core object after it has been instantiated and
			 * started. 
			 *
			 * If stopped, it can be started again using start(). Must be called only if
			 * LinphoneGlobalState is either On. State will changed to Shutdown and then Off.
			 */
			LINPHONECXX_PUBLIC void stop();
			
			/**
			 * @brief Stop recording the running conference. 
			 *
			 * @return 0 if succeeded. Negative number if failed 
			 */
			LINPHONECXX_PUBLIC linphone::Status stopConferenceRecording();
			
			/**
			 * @brief Stops playing a dtmf started by playDtmf(). 
			 *
			 */
			LINPHONECXX_PUBLIC void stopDtmf();
			
			/**
			 * @brief Special function to stop dtmf feed back function. 
			 *
			 * Must be called before entering BG mode 
			 */
			LINPHONECXX_PUBLIC void stopDtmfStream();
			
			/**
			 * @brief Stop the simulation of call. 
			 *
			 */
			LINPHONECXX_PUBLIC linphone::Status stopEchoTester();
			
			/**
			 * @brief Whenever the liblinphone is playing a ring to advertise an incoming call
			 * or ringback of an outgoing call, this function stops the ringing. 
			 *
			 * Typical use is to stop ringing when the user requests to ignore the call. 
			 */
			LINPHONECXX_PUBLIC void stopRinging();
			
			/**
			 * @brief Create an outgoing subscription, specifying the destination resource,
			 * the event name, and an optional content body. 
			 *
			 * If accepted, the subscription runs for a finite period, but is automatically
			 * renewed if not terminated before. 
			 * 
			 * @param body an optional body, may be nullptr.    
			 * 
			 * @return a #Event holding the context of the created subcription. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Event> subscribe(const std::shared_ptr<const linphone::Address> & resource, const std::string & event, int expires, const std::shared_ptr<const linphone::Content> & body);
			
			/**
			 * @brief Take a photo of currently from capture device and write it into a jpeg
			 * file. 
			 *
			 * Note that the snapshot is asynchronous, an application shall not assume that
			 * the file is created when the function returns.
			 * 
			 * @param file a path where to write the jpeg content. 
			 * 
			 * @return 0 if successfull, -1 otherwise (typically if jpeg format is not
			 * supported). 
			 */
			LINPHONECXX_PUBLIC linphone::Status takePreviewSnapshot(const std::string & file);
			
			/**
			 * @brief Terminates all the calls. 
			 *
			 * @return 0 
			 */
			LINPHONECXX_PUBLIC linphone::Status terminateAllCalls();
			
			/**
			 * @brief Terminates a call. 
			 *
			 * @param call The LinphoneCall object representing the call to be terminated 
			 * 
			 * @return 0 on success, -1 on failure
			 * 
			 * @deprecated Use Call::terminate() instead. Deprecated since 2017-02-13. 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED linphone::Status terminateCall(const std::shared_ptr<linphone::Call> & call);
			
			/**
			 * @brief Terminate the running conference. 
			 *
			 * If it is a local conference, all calls inside it will become back separate
			 * calls and will be put in #LinphoneCallPaused state. If it is a conference
			 * involving a focus server, all calls inside the conference will be terminated. 
			 * 
			 * @return 0 if succeeded. Negative number if failed 
			 */
			LINPHONECXX_PUBLIC linphone::Status terminateConference();
			
			/**
			 * @brief Performs a simple call transfer to the specified destination. 
			 *
			 * The remote endpoint is expected to issue a new call to the specified
			 * destination. The current call remains active and thus can be later paused or
			 * terminated. It is possible to follow the progress of the transfer provided that
			 * transferee sends notification about it. In this case, the
			 * transfer_state_changed callback of the LinphoneCoreVTable is invoked to notify
			 * of the state of the new call at the other party. The notified states are
			 * #LinphoneCallOutgoingInit , #LinphoneCallOutgoingProgress,
			 * #LinphoneCallOutgoingRinging and #LinphoneCallConnected. 
			 * 
			 * @param referTo The destination the call is to be refered to 
			 * 
			 * @return 0 on success, -1 on failure
			 * 
			 * @deprecated Use Call::transfer() instead. Deprecated since 2017-02-13. 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED linphone::Status transferCall(const std::shared_ptr<linphone::Call> & call, const std::string & referTo);
			
			/**
			 * @brief Transfers a call to destination of another running call. 
			 *
			 * This is used for "attended transfer" scenarios.
			 * 
			 * The transfered call is supposed to be in paused state, so that it is able to
			 * accept the transfer immediately. The destination call is a call previously
			 * established to introduce the transfered person. This method will send a
			 * transfer request to the transfered person. The phone of the transfered is then
			 * expected to automatically call to the destination of the transfer. The receiver
			 * of the transfer will then automatically close the call with us (the 'dest'
			 * call). It is possible to follow the progress of the transfer provided that
			 * transferee sends notification about it. In this case, the
			 * transfer_state_changed callback of the LinphoneCoreVTable is invoked to notify
			 * of the state of the new call at the other party. The notified states are
			 * #LinphoneCallOutgoingInit , #LinphoneCallOutgoingProgress,
			 * #LinphoneCallOutgoingRinging and #LinphoneCallConnected. 
			 * 
			 * @param dest A running call whose remote person will receive the transfer 
			 * 
			 * @return 0 on success, -1 on failure
			 * 
			 * @deprecated Use Call::transferToAnother() instead. Deprecated since 2017-02-13. 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED linphone::Status transferCallToAnother(const std::shared_ptr<linphone::Call> & call, const std::shared_ptr<linphone::Call> & dest);
			
			/**
			 * @brief Updates a running call according to supplied call parameters or
			 * parameters changed in the LinphoneCore. 
			 *
			 * In this version this is limited to the following use cases:
			 * 
			 * 
			 * @param params The new call parameters to use (may be nullptr) 
			 * 
			 * @return 0 if successful, -1 otherwise.
			 * 
			 * @deprecated Use Call::update() instead. Deprecated since 2017-02-13. 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED linphone::Status updateCall(const std::shared_ptr<linphone::Call> & call, const std::shared_ptr<const linphone::CallParams> & params);
			
			/**
			 * @brief Upload the log collection to the configured server url. 
			 *
			 */
			LINPHONECXX_PUBLIC void uploadLogCollection();
			
			/**
			 * @brief Tells the core to use a separate window for local camera preview video,
			 * instead of inserting local view within the remote video window. 
			 *
			 * @param yesno  to use a separate window, true to insert the preview in the
			 * remote video window. 
			 */
			LINPHONECXX_PUBLIC void usePreviewWindow(bool yesno);
			
			/**
			 * @brief Specify whether the tls server certificate must be verified when
			 * connecting to a SIP/TLS server. 
			 *
			 * @param yesno A boolean value telling whether the tls server certificate must be
			 * verified 
			 */
			LINPHONECXX_PUBLIC void verifyServerCertificates(bool yesno);
			
			/**
			 * @brief Specify whether the tls server certificate common name must be verified
			 * when connecting to a SIP/TLS server. 
			 *
			 * @param yesno A boolean value telling whether the tls server certificate common
			 * name must be verified 
			 */
			LINPHONECXX_PUBLIC void verifyServerCn(bool yesno);
			
			/**
			 * @brief Test if video is supported. 
			 *
			 */
			LINPHONECXX_PUBLIC bool videoSupported();
			
			;
			/**
			 * @brief Compress the log collection in a single file. 
			 *
			 * @return The path of the compressed log collection file (to be freed calling
			 * ms_free()). 
			 */
			LINPHONECXX_PUBLIC static std::string compressLogCollection();
			
;
			/**
			 * @brief Enable the linphone core log collection to upload logs on a server. 
			 *
			 * @param state #LinphoneLogCollectionState value telling whether to enable log
			 * collection or not. 
			 */
			LINPHONECXX_PUBLIC static void enableLogCollection(linphone::LogCollectionState state);
			
;
			/**
			 * @brief Get the max file size in bytes of the files used for log collection. 
			 *
			 * @return The max file size in bytes of the files used for log collection. 
			 */
			LINPHONECXX_PUBLIC static size_t getLogCollectionMaxFileSize();
			
;
			/**
			 * @brief Get the path where the log files will be written for log collection. 
			 *
			 * @return The path where the log files will be written. 
			 */
			LINPHONECXX_PUBLIC static std::string getLogCollectionPath();
			
;
			/**
			 * @brief Get the prefix of the filenames that will be used for log collection. 
			 *
			 * @return The prefix of the filenames used for log collection. 
			 */
			LINPHONECXX_PUBLIC static std::string getLogCollectionPrefix();
			
;
			/**
			 * @brief Get defined log level mask. 
			 *
			 * @return The loglevel parameter is a bitmask parameter. Therefore to enable only
			 * warning and error messages, use ORTP_WARNING | ORTP_ERROR. To disable logs,
			 * simply set loglevel to 0. 
			 * 
			 * @deprecated Use LoggingService::getLogLevelMask() instead. Deprecated since
			 * 2017-10-10. 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED static unsigned int getLogLevelMask();
			
;
			/**
			 * @brief Returns liblinphone's version as a string. 
			 *
			 */
			LINPHONECXX_PUBLIC static std::string getVersion();
			
;
			/**
			 * @brief Tells whether the linphone core log collection is enabled. 
			 *
			 * @return The state of the linphone core log collection. 
			 */
			LINPHONECXX_PUBLIC static linphone::LogCollectionState logCollectionEnabled();
			
;
			/**
			 * @brief Reset the log collection by removing the log files. 
			 *
			 */
			LINPHONECXX_PUBLIC static void resetLogCollection();
			
;
			/**
			 * @brief Enable logs serialization (output logs from either the thread that
			 * creates the linphone core or the thread that calls iterate()). 
			 *
			 * Must be called before creating the linphone core. 
			 */
			LINPHONECXX_PUBLIC static void serializeLogs();
			
;
			/**
			 * @brief Set the max file size in bytes of the files used for log collection. 
			 *
			 * Warning: this function should only not be used to change size dynamically but
			 * instead only before calling @see linphone_core_enable_log_collection. If you
			 * increase max size on runtime, logs chronological order COULD be broken. 
			 * 
			 * @param size The max file size in bytes of the files used for log collection. 
			 */
			LINPHONECXX_PUBLIC static void setLogCollectionMaxFileSize(size_t size);
			
;
			/**
			 * @brief Set the path of a directory where the log files will be written for log
			 * collection. 
			 *
			 * @param path The path where the log files will be written. 
			 */
			LINPHONECXX_PUBLIC static void setLogCollectionPath(const std::string & path);
			
;
			/**
			 * @brief Set the prefix of the filenames that will be used for log collection. 
			 *
			 * @param prefix The prefix to use for the filenames for log collection. 
			 */
			LINPHONECXX_PUBLIC static void setLogCollectionPrefix(const std::string & prefix);
			
;
			/**
			 * @brief Define the log level using mask. 
			 *
			 * The loglevel parameter is a bitmask parameter. Therefore to enable only warning
			 * and error messages, use ORTP_WARNING | ORTP_ERROR. To disable logs, simply set
			 * loglevel to 0.
			 * 
			 * @param mask A bitmask of the log levels to set. 
			 * 
			 * @deprecated Use LoggingService::setLogLevel() instead. Deprecated since
			 * 2017-10-10. 
			 */
			LINPHONECXX_PUBLIC LINPHONECXX_DEPRECATED static void setLogLevelMask(unsigned int mask);
			
;
			/**
			 * @brief True if tunnel support was compiled. 
			 *
			 */
			LINPHONECXX_PUBLIC static bool tunnelAvailable();
			
;
			/**
			 * @brief Return the availability of uPnP. 
			 *
			 * @return true if uPnP is available otherwise return false. 
			 */
			LINPHONECXX_PUBLIC static bool upnpAvailable();
			
;
			/**
			 * @brief Tells whether VCARD support is builtin. 
			 *
			 * @return  if VCARD is supported, true otherwise. 
			 */
			LINPHONECXX_PUBLIC static bool vcardSupported();
			

		private:
			void *createCallbacks() override;
	};

};

#endif // _LINPHONE_CORE_HH
