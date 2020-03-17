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

#ifndef _LINPHONE_CORE_LISTENER_HH
#define _LINPHONE_CORE_LISTENER_HH

#include <string>
#include "call.hh"
#include "enums.hh"
#include "chat_room.hh"
#include "core.hh"
#include "object.hh"






namespace linphone {

	class Core;
	class Call;
	class FriendList;
	class Event;
	class CallLog;
	class AuthInfo;
	class Friend;
	class PresenceModel;
	class ChatRoom;
	class Content;
	class CallStats;
	class ChatMessage;
	class InfoMessage;
	class ProxyConfig;

	/**
	 *
	 */
	class CoreListener: public Listener {
	
		public:


	
		public:
			
		
			/**
			 * @brief Callback for notifying progresses of transfers. 
			 *
			 * @param newCallState the state of the call to transfer target at the far end. 
			 */
			LINPHONECXX_PUBLIC virtual void onTransferStateChanged(const std::shared_ptr<linphone::Core> & lc, const std::shared_ptr<linphone::Call> & transfered, linphone::Call::State newCallState) {};
			
			/**
			 * @brief Callback prototype for reporting when a friend list has been added to
			 * the core friends list. 
			 *
			 * @param list LinphoneFriendList object 
			 */
			LINPHONECXX_PUBLIC virtual void onFriendListCreated(const std::shared_ptr<linphone::Core> & lc, const std::shared_ptr<linphone::FriendList> & list) {};
			
			/**
			 * @brief Callback prototype for notifying the application about changes of
			 * subscription states, including arrival of new subscriptions. 
			 *
			 */
			LINPHONECXX_PUBLIC virtual void onSubscriptionStateChanged(const std::shared_ptr<linphone::Core> & lc, const std::shared_ptr<linphone::Event> & lev, linphone::SubscriptionState state) {};
			
			/**
			 * @brief Callback to notify a new call-log entry has been added. 
			 *
			 * This is done typically when a call terminates. 
			 * 
			 * @param newcl the new call log entry added. 
			 */
			LINPHONECXX_PUBLIC virtual void onCallLogUpdated(const std::shared_ptr<linphone::Core> & lc, const std::shared_ptr<linphone::CallLog> & newcl) {};
			
			/**
			 * @brief Call state notification callback. 
			 *
			 * @param message a non nullptr informational message about the state. 
			 */
			LINPHONECXX_PUBLIC virtual void onCallStateChanged(const std::shared_ptr<linphone::Core> & lc, const std::shared_ptr<linphone::Call> & call, linphone::Call::State cstate, const std::string & message) {};
			
			/**
			 * @brief Callback for requesting authentication information to application or
			 * user. 
			 *
			 * @param method the type of authentication requested Application shall reply to
			 * this callback using linphone_core_add_auth_info. 
			 */
			LINPHONECXX_PUBLIC virtual void onAuthenticationRequested(const std::shared_ptr<linphone::Core> & lc, const std::shared_ptr<linphone::AuthInfo> & authInfo, linphone::AuthMethod method) {};
			
			/**
			 * @brief Reports presence model change for a specific URI or phone number of a
			 * friend. 
			 *
			 * @param presenceModel The new presence model 
			 */
			LINPHONECXX_PUBLIC virtual void onNotifyPresenceReceivedForUriOrTel(const std::shared_ptr<linphone::Core> & lc, const std::shared_ptr<linphone::Friend> & lf, const std::string & uriOrTel, const std::shared_ptr<const linphone::PresenceModel> & presenceModel) {};
			
			/**
			 * @brief Callback prototype telling that a LinphoneChatRoom state has changed. 
			 *
			 * @param cr The LinphoneChatRoom object for which the state has changed 
			 */
			LINPHONECXX_PUBLIC virtual void onChatRoomStateChanged(const std::shared_ptr<linphone::Core> & lc, const std::shared_ptr<linphone::ChatRoom> & cr, linphone::ChatRoom::State state) {};
			
			/**
			 * @brief Callback prototype. 
			 *
			 */
			LINPHONECXX_PUBLIC virtual void onBuddyInfoUpdated(const std::shared_ptr<linphone::Core> & lc, const std::shared_ptr<linphone::Friend> & lf) {};
			
			/**
			 * @brief Callback prototype for reporting network change either automatically
			 * detected or notified by linphone_core_set_network_reachable. 
			 *
			 * @param reachable true if network is reachable. 
			 */
			LINPHONECXX_PUBLIC virtual void onNetworkReachable(const std::shared_ptr<linphone::Core> & lc, bool reachable) {};
			
			/**
			 * @brief Callback prototype for notifying the application about notification
			 * received from the network. 
			 *
			 */
			LINPHONECXX_PUBLIC virtual void onNotifyReceived(const std::shared_ptr<linphone::Core> & lc, const std::shared_ptr<linphone::Event> & lev, const std::string & notifiedEvent, const std::shared_ptr<const linphone::Content> & body) {};
			
			/**
			 * @brief Reports that a new subscription request has been received and wait for a
			 * decision. 
			 *
			 * Status on this subscription request is notified by changing policy  for this
			 * friend 
			 * 
			 * @param url of the subscriber 
			 */
			LINPHONECXX_PUBLIC virtual void onNewSubscriptionRequested(const std::shared_ptr<linphone::Core> & lc, const std::shared_ptr<linphone::Friend> & lf, const std::string & url) {};
			
			/**
			 * @brief Callback for receiving quality statistics for calls. 
			 *
			 * @param stats the call statistics. 
			 */
			LINPHONECXX_PUBLIC virtual void onCallStatsUpdated(const std::shared_ptr<linphone::Core> & lc, const std::shared_ptr<linphone::Call> & call, const std::shared_ptr<const linphone::CallStats> & stats) {};
			
			/**
			 * @brief Report status change for a friend previously added  to LinphoneCore. 
			 *
			 * @param lf Updated LinphoneFriend . 
			 */
			LINPHONECXX_PUBLIC virtual void onNotifyPresenceReceived(const std::shared_ptr<linphone::Core> & lc, const std::shared_ptr<linphone::Friend> & lf) {};
			
			/**
			 * @brief Function prototype used by
			 * #linphone_core_cbs_set_ec_calibrator_audio_init(). 
			 *
			 * @param lc The core. 
			 */
			LINPHONECXX_PUBLIC virtual void onEcCalibrationAudioInit(const std::shared_ptr<linphone::Core> & lc) {};
			
			/**
			 * @brief Chat message callback prototype. 
			 *
			 * @param room LinphoneChatRoom involved in this conversation. Can be be created
			 * by the framework in case the from  is not present in any chat room. 
			 */
			LINPHONECXX_PUBLIC virtual void onMessageReceived(const std::shared_ptr<linphone::Core> & lc, const std::shared_ptr<linphone::ChatRoom> & room, const std::shared_ptr<linphone::ChatMessage> & message) {};
			
			/**
			 * @brief Function prototype used by
			 * #linphone_core_cbs_set_ec_calibrator_result(). 
			 *
			 * @param delayMs The measured delay if available. 
			 */
			LINPHONECXX_PUBLIC virtual void onEcCalibrationResult(const std::shared_ptr<linphone::Core> & lc, linphone::EcCalibratorStatus status, int delayMs) {};
			
			/**
			 * @brief Callback prototype for notifying the application about subscription
			 * received from the network. 
			 *
			 */
			LINPHONECXX_PUBLIC virtual void onSubscribeReceived(const std::shared_ptr<linphone::Core> & lc, const std::shared_ptr<linphone::Event> & lev, const std::string & subscribeEvent, const std::shared_ptr<const linphone::Content> & body) {};
			
			/**
			 * @brief Callback prototype for receiving info messages. 
			 *
			 * @param msg the info message. 
			 */
			LINPHONECXX_PUBLIC virtual void onInfoReceived(const std::shared_ptr<linphone::Core> & lc, const std::shared_ptr<linphone::Call> & call, const std::shared_ptr<const linphone::InfoMessage> & msg) {};
			
			/**
			 * @brief Chat room marked as read callback. 
			 *
			 * @param room LinphoneChatRoom that has been marked as read. 
			 */
			LINPHONECXX_PUBLIC virtual void onChatRoomRead(const std::shared_ptr<linphone::Core> & lc, const std::shared_ptr<linphone::ChatRoom> & room) {};
			
			/**
			 * @brief Registration state notification callback prototype. 
			 *
			 */
			LINPHONECXX_PUBLIC virtual void onRegistrationStateChanged(const std::shared_ptr<linphone::Core> & lc, const std::shared_ptr<linphone::ProxyConfig> & cfg, linphone::RegistrationState cstate, const std::string & message) {};
			
			/**
			 * @brief Callback prototype for reporting when a friend list has been removed
			 * from the core friends list. 
			 *
			 * @param list LinphoneFriendList object 
			 */
			LINPHONECXX_PUBLIC virtual void onFriendListRemoved(const std::shared_ptr<linphone::Core> & lc, const std::shared_ptr<linphone::FriendList> & list) {};
			
			/**
			 * @brief Callback prototype. 
			 *
			 */
			LINPHONECXX_PUBLIC virtual void onReferReceived(const std::shared_ptr<linphone::Core> & lc, const std::string & referTo) {};
			
			/**
			 * @brief Callback prototype telling the result of decoded qrcode. 
			 *
			 * @param result The result of the decoded qrcode 
			 */
			LINPHONECXX_PUBLIC virtual void onQrcodeFound(const std::shared_ptr<linphone::Core> & lc, const std::string & result) {};
			
			/**
			 * @brief Callback prototype for configuring status changes notification. 
			 *
			 * @param message informational message. 
			 */
			LINPHONECXX_PUBLIC virtual void onConfiguringStatus(const std::shared_ptr<linphone::Core> & lc, linphone::ConfiguringState status, const std::string & message) {};
			
			/**
			 * @brief Callback notifying that a new LinphoneCall (either incoming or outgoing)
			 * has been created. 
			 *
			 * @param call The newly created LinphoneCall object 
			 */
			LINPHONECXX_PUBLIC virtual void onCallCreated(const std::shared_ptr<linphone::Core> & lc, const std::shared_ptr<linphone::Call> & call) {};
			
			/**
			 * @brief Callback prototype for notifying the application about changes of
			 * publish states. 
			 *
			 */
			LINPHONECXX_PUBLIC virtual void onPublishStateChanged(const std::shared_ptr<linphone::Core> & lc, const std::shared_ptr<linphone::Event> & lev, linphone::PublishState state) {};
			
			/**
			 * @brief Call encryption changed callback. 
			 *
			 * @param authenticationToken an authentication_token, currently set for ZRTP kind
			 * of encryption only. 
			 */
			LINPHONECXX_PUBLIC virtual void onCallEncryptionChanged(const std::shared_ptr<linphone::Core> & lc, const std::shared_ptr<linphone::Call> & call, bool on, const std::string & authenticationToken) {};
			
			/**
			 * @brief Is composing notification callback prototype. 
			 *
			 * @param room LinphoneChatRoom involved in the conversation. 
			 */
			LINPHONECXX_PUBLIC virtual void onIsComposingReceived(const std::shared_ptr<linphone::Core> & lc, const std::shared_ptr<linphone::ChatRoom> & room) {};
			
			/**
			 * @brief Chat message not decrypted callback prototype. 
			 *
			 * @param room LinphoneChatRoom involved in this conversation. Can be be created
			 * by the framework in case the from  is not present in any chat room. 
			 */
			LINPHONECXX_PUBLIC virtual void onMessageReceivedUnableDecrypt(const std::shared_ptr<linphone::Core> & lc, const std::shared_ptr<linphone::ChatRoom> & room, const std::shared_ptr<linphone::ChatMessage> & message) {};
			
			/**
			 * @brief Callback prototype for reporting log collection upload progress
			 * indication. 
			 *
			 * @param lc LinphoneCore object 
			 */
			LINPHONECXX_PUBLIC virtual void onLogCollectionUploadProgressIndication(const std::shared_ptr<linphone::Core> & lc, size_t offset, size_t total) {};
			
			/**
			 * @brief Callback prototype telling that a LinphoneChatRoom subject has changed. 
			 *
			 * @param cr The LinphoneChatRoom object for which the subject has changed 
			 */
			LINPHONECXX_PUBLIC virtual void onChatRoomSubjectChanged(const std::shared_ptr<linphone::Core> & lc, const std::shared_ptr<linphone::ChatRoom> & cr) {};
			
			/**
			 * @brief Callback prototype for reporting the result of a version update check. 
			 *
			 * @param url The url where to download the new version if the result is
			 * #LinphoneVersionUpdateCheckNewVersionAvailable 
			 */
			LINPHONECXX_PUBLIC virtual void onVersionUpdateCheckResultReceived(const std::shared_ptr<linphone::Core> & lc, linphone::VersionUpdateCheckResult result, const std::string & version, const std::string & url) {};
			
			/**
			 * @brief Function prototype used by
			 * #linphone_core_cbs_set_ec_calibrator_audio_uninit(). 
			 *
			 * @param lc The core. 
			 */
			LINPHONECXX_PUBLIC virtual void onEcCalibrationAudioUninit(const std::shared_ptr<linphone::Core> & lc) {};
			
			/**
			 * @brief Global state notification callback. 
			 *
			 * @param message informational message. 
			 */
			LINPHONECXX_PUBLIC virtual void onGlobalStateChanged(const std::shared_ptr<linphone::Core> & lc, linphone::GlobalState gstate, const std::string & message) {};
			
			/**
			 * @brief Callback prototype for reporting log collection upload state change. 
			 *
			 * @param info Additional information: error message in case of error state, URL
			 * of uploaded file in case of success. 
			 */
			LINPHONECXX_PUBLIC virtual void onLogCollectionUploadStateChanged(const std::shared_ptr<linphone::Core> & lc, linphone::Core::LogCollectionUploadState state, const std::string & info) {};
			
			/**
			 * @brief Callback for being notified of DTMFs received. 
			 *
			 * @param dtmf the ascii code of the dtmf 
			 */
			LINPHONECXX_PUBLIC virtual void onDtmfReceived(const std::shared_ptr<linphone::Core> & lc, const std::shared_ptr<linphone::Call> & call, int dtmf) {};
			
			/**
			 * @brief Chat message callback prototype. 
			 *
			 * @param room LinphoneChatRoom involved in this conversation. Can be be created
			 * by the framework in case the from  is not present in any chat room. 
			 */
			LINPHONECXX_PUBLIC virtual void onMessageSent(const std::shared_ptr<linphone::Core> & lc, const std::shared_ptr<linphone::ChatRoom> & room, const std::shared_ptr<linphone::ChatMessage> & message) {};
			
			
	};

};

#endif // _LINPHONE_CORE_LISTENER_HH
