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

#ifndef _ENUMS_HH
#define _ENUMS_HH

namespace linphone {
	
	/**
	 * Enum describing RTP AVPF activation modes. 
	 * 
	 */
	enum class AVPFMode {
		/**
		 * Use default value defined at upper level. 
		 */
		Default = -1,
		/**
		 * AVPF is disabled. 
		 */
		Disabled,
		/**
		 * AVPF is enabled. 
		 */
		Enabled
	};

	/**
	 * Enum algorithm checking. 
	 * 
	 */
	enum class AccountCreatorAlgoStatus {
		/**
		 * Algorithm ok. 
		 */
		Ok,
		/**
		 * Algorithm not supported. 
		 */
		NotSupported
	};

	/**
	 * Enum describing Ip family. 
	 * 
	 */
	enum class AddressFamily {
		/**
		 * IpV4. 
		 */
		Inet,
		/**
		 * IpV6. 
		 */
		Inet6,
		/**
		 * Unknown. 
		 */
		Unspec
	};

	/**
	 * Enum describing type of audio route. 
	 * 
	 */
	enum class AudioRoute {
		/**
		 */
		Earpiece,
		/**
		 */
		Speaker
	};

	/**
	 * Enum describing the authentication methods. 
	 * 
	 */
	enum class AuthMethod {
		/**
		 * Digest authentication requested. 
		 */
		HttpDigest,
		/**
		 * Client certificate requested. 
		 */
		Tls
	};

	/**
	 * LinphoneChatRoomBackend is used to indicate the backend implementation of a
	 * chat room. 
	 * 
	 */
	enum class ChatRoomBackend {
		/**
		 * Basic (client-to-client) chat room. 
		 */
		Basic = 1<<0,
		/**
		 * Server-based chat room. 
		 */
		FlexisipChat = 1<<1
	};

	/**
	 * LinphoneChatRoomCapabilities is used to indicate the capabilities of a chat
	 * room. 
	 * 
	 */
	enum class ChatRoomCapabilities {
		/**
		 * No capabilities. 
		 */
		None = 0,
		/**
		 * No server. 
		 */
		Basic = 1<<0,
		/**
		 * Supports RTT. 
		 */
		RealTimeText = 1<<1,
		/**
		 * Use server (supports group chat) 
		 */
		Conference = 1<<2,
		/**
		 * Special proxy chat room flag. 
		 */
		Proxy = 1<<3,
		/**
		 * Chat room migratable from Basic to Conference. 
		 */
		Migratable = 1<<4,
		/**
		 * A communication between two participants (can be Basic or Conference) 
		 */
		OneToOne = 1<<5,
		/**
		 * Chat room is encrypted. 
		 */
		Encrypted = 1<<6
	};

	/**
	 * LinphoneChatRoomEncryptionBackend is used to indicate the encryption engine
	 * used by a chat room. 
	 * 
	 */
	enum class ChatRoomEncryptionBackend {
		/**
		 * No encryption. 
		 */
		None = 0,
		/**
		 * Lime x3dh encryption. 
		 */
		Lime = 1<<0
	};

	/**
	 * TODO move to encryption engine object when available
	 * LinphoneChatRoomSecurityLevel is used to indicate the encryption security level
	 * of a chat room. 
	 * 
	 */
	enum class ChatRoomSecurityLevel {
		/**
		 * Security failure. 
		 */
		Unsafe,
		/**
		 * No encryption. 
		 */
		ClearText,
		/**
		 * Encrypted. 
		 */
		Encrypted,
		/**
		 * Encrypted and verified. 
		 */
		Safe
	};

	/**
	 * LinphoneGlobalState describes the global state of the #Core object. 
	 * 
	 */
	enum class ConfiguringState {
		/**
		 */
		Successful,
		/**
		 */
		Failed,
		/**
		 */
		Skipped
	};

	/**
	 * Consolidated presence information: 'online' means the user is open for
	 * communication, 'busy' means the user is open for communication but involved in
	 * an other activity, 'do not disturb' means the user is not open for
	 * communication, and 'offline' means that no presence information is available. 
	 * 
	 */
	enum class ConsolidatedPresence {
		/**
		 */
		Online,
		/**
		 */
		Busy,
		/**
		 */
		DoNotDisturb,
		/**
		 */
		Offline
	};

	/**
	 * Enum describing the result of the echo canceller calibration process. 
	 * 
	 */
	enum class EcCalibratorStatus {
		/**
		 * The echo canceller calibration process is on going. 
		 */
		InProgress,
		/**
		 * The echo canceller calibration has been performed and produced an echo delay
		 * measure. 
		 */
		Done,
		/**
		 * The echo canceller calibration process has failed. 
		 */
		Failed,
		/**
		 * The echo canceller calibration has been performed and no echo has been
		 * detected. 
		 */
		DoneNoEcho
	};

	/**
	 * Enum describing the status of a LinphoneFriendList operation. 
	 * 
	 */
	enum class FriendCapability {
		/**
		 */
		None = 0,
		/**
		 */
		GroupChat = 1<<0,
		/**
		 */
		LimeX3Dh = 1<<1
	};

	/**
	 * LinphoneGlobalState describes the global state of the #Core object. 
	 * 
	 */
	enum class GlobalState {
		/**
		 * State in which we're in after Core::stop(). 
		 */
		Off,
		/**
		 * Transient state for when we call Core::start() 
		 */
		Startup,
		/**
		 * Indicates #Core has been started and is up and running. 
		 */
		On,
		/**
		 * Transient state for when we call Core::stop() 
		 */
		Shutdown,
		/**
		 * Transient state between Startup and On if there is a remote provisionning URI
		 * configured. 
		 */
		Configuring,
		/**
		 * #Core state after being created by linphone_factory_create_core, generally
		 * followed by a call to Core::start() 
		 */
		Ready
	};

	/**
	 * Enum describing ICE states. 
	 * 
	 */
	enum class IceState {
		/**
		 * ICE has not been activated for this call or stream. 
		 */
		NotActivated,
		/**
		 * ICE processing has failed. 
		 */
		Failed,
		/**
		 * ICE process is in progress. 
		 */
		InProgress,
		/**
		 * ICE has established a direct connection to the remote host. 
		 */
		HostConnection,
		/**
		 * ICE has established a connection to the remote host through one or several
		 * NATs. 
		 */
		ReflexiveConnection,
		/**
		 * ICE has established a connection through a relay. 
		 */
		RelayConnection
	};

	/**
	 * 
	 */
	enum class LimeState {
		/**
		 * Lime is not used at all. 
		 */
		Disabled,
		/**
		 * Lime is always used. 
		 */
		Mandatory,
		/**
		 * Lime is used only if we already shared a secret with remote. 
		 */
		Preferred
	};

	/**
	 * 
	 */
	enum class LogCollectionState {
		/**
		 */
		Disabled,
		/**
		 */
		Enabled,
		/**
		 */
		EnabledWithoutPreviousLogHandler
	};

	/**
	 * Verbosity levels of log messages. 
	 * 
	 */
	enum class LogLevel {
		/**
		 * Level for debug messages. 
		 */
		Debug = 1,
		/**
		 * Level for traces. 
		 */
		Trace = 1<<1,
		/**
		 * Level for information messages. 
		 */
		Message = 1<<2,
		/**
		 * Level for warning messages. 
		 */
		Warning = 1<<3,
		/**
		 * Level for error messages. 
		 */
		Error = 1<<4,
		/**
		 * Level for fatal error messages. 
		 */
		Fatal = 1<<5
	};

	/**
	 * Indicates for a given media the stream direction. 
	 * 
	 */
	enum class MediaDirection {
		/**
		 */
		Invalid = -1,
		/**
		 */
		Inactive,
		/**
		 * No active media not supported yet. 
		 */
		SendOnly,
		/**
		 * Send only mode. 
		 */
		RecvOnly,
		/**
		 * recv only mode 
		 */
		SendRecv
	};

	/**
	 * Enum describing type of media encryption types. 
	 * 
	 */
	enum class MediaEncryption {
		/**
		 * No media encryption is used. 
		 */
		None,
		/**
		 * Use SRTP media encryption. 
		 */
		SRTP,
		/**
		 * Use ZRTP media encryption. 
		 */
		ZRTP,
		/**
		 * Use DTLS media encryption. 
		 */
		DTLS
	};

	/**
	 * Basic status as defined in section 4.1.4 of RFC 3863. 
	 * 
	 */
	enum class PresenceBasicStatus {
		/**
		 * This value means that the associated contact element, if any, is ready to
		 * accept communication. 
		 */
		Open,
		/**
		 * This value means that the associated contact element, if any, is unable to
		 * accept communication. 
		 */
		Closed
	};

	/**
	 * Defines privacy policy to apply as described by rfc3323. 
	 * 
	 */
	enum class Privacy {
		/**
		 * Privacy services must not perform any privacy function. 
		 */
		None = 0,
		/**
		 * Request that privacy services provide a user-level privacy function. 
		 */
		User = 1,
		/**
		 * Request that privacy services modify headers that cannot be set arbitrarily by
		 * the user (Contact/Via). 
		 */
		Header = 2,
		/**
		 * Request that privacy services provide privacy for session media. 
		 */
		Session = 4,
		/**
		 * rfc3325 The presence of this privacy type in a Privacy header field indicates
		 * that the user would like the Network Asserted Identity to be kept private with
		 * respect to SIP entities outside the Trust Domain with which the user
		 * authenticated. 
		 */
		Id = 8,
		/**
		 * Privacy service must perform the specified services or fail the request. 
		 */
		Critical = 16,
		/**
		 * Special keyword to use privacy as defined either globally or by proxy using
		 * ProxyConfig::setPrivacy() 
		 */
		Default = 32768
	};

	/**
	 * Enum for publish states. 
	 * 
	 */
	enum class PublishState {
		/**
		 * Initial state, do not use. 
		 */
		None,
		/**
		 * An outgoing publish was created and submitted. 
		 */
		Progress,
		/**
		 * Publish is accepted. 
		 */
		Ok,
		/**
		 * Publish encoutered an error, Event::getReason() gives reason code. 
		 */
		Error,
		/**
		 * Publish is about to expire, only sent if [sip]->refresh_generic_publish
		 * property is set to 0. 
		 */
		Expiring,
		/**
		 * Event has been un published. 
		 */
		Cleared
	};

	/**
	 * Enum describing various failure reasons or contextual information for some
	 * events. 
	 * 
	 */
	enum class Reason {
		/**
		 * No reason has been set by the core. 
		 */
		None,
		/**
		 * No response received from remote. 
		 */
		NoResponse,
		/**
		 * Authentication failed due to bad credentials or resource forbidden. 
		 */
		Forbidden,
		/**
		 * The call has been declined. 
		 */
		Declined,
		/**
		 * Destination of the call was not found. 
		 */
		NotFound,
		/**
		 * The call was not answered in time (request timeout) 
		 */
		NotAnswered,
		/**
		 * Phone line was busy. 
		 */
		Busy,
		/**
		 * Unsupported content. 
		 */
		UnsupportedContent,
		/**
		 * Transport error: connection failures, disconnections etc... 
		 */
		IOError,
		/**
		 * Do not disturb reason. 
		 */
		DoNotDisturb,
		/**
		 * Operation is unauthorized because missing credential. 
		 */
		Unauthorized,
		/**
		 * Operation is rejected due to incompatible or unsupported media parameters. 
		 */
		NotAcceptable,
		/**
		 * Operation could not be executed by server or remote client because it didn't
		 * have any context for it. 
		 */
		NoMatch,
		/**
		 * Resource moved permanently. 
		 */
		MovedPermanently,
		/**
		 * Resource no longer exists. 
		 */
		Gone,
		/**
		 * Temporarily unavailable. 
		 */
		TemporarilyUnavailable,
		/**
		 * Address incomplete. 
		 */
		AddressIncomplete,
		/**
		 * Not implemented. 
		 */
		NotImplemented,
		/**
		 * Bad gateway. 
		 */
		BadGateway,
		/**
		 * Server timeout. 
		 */
		ServerTimeout,
		/**
		 * Unknown reason. 
		 */
		Unknown
	};

	/**
	 * LinphoneRegistrationState describes proxy registration states. 
	 * 
	 */
	enum class RegistrationState {
		/**
		 * Initial state for registrations. 
		 */
		None,
		/**
		 * Registration is in progress. 
		 */
		Progress,
		/**
		 * Registration is successful. 
		 */
		Ok,
		/**
		 * Unregistration succeeded. 
		 */
		Cleared,
		/**
		 * Registration failed. 
		 */
		Failed
	};

	/**
	 * Enum describing the stream types. 
	 * 
	 */
	enum class StreamType {
		/**
		 */
		Audio,
		/**
		 */
		Video,
		/**
		 */
		Text,
		/**
		 */
		Unknown
	};

	/**
	 * Enum controlling behavior for incoming subscription request. 
	 * 
	 */
	enum class SubscribePolicy {
		/**
		 * Does not automatically accept an incoming subscription request. 
		 */
		SPWait,
		/**
		 * Rejects incoming subscription request. 
		 */
		SPDeny,
		/**
		 * Automatically accepts a subscription request. 
		 */
		SPAccept
	};

	/**
	 * Enum for subscription direction (incoming or outgoing). 
	 * 
	 */
	enum class SubscriptionDir {
		/**
		 * Incoming subscription. 
		 */
		Incoming,
		/**
		 * Outgoing subscription. 
		 */
		Outgoing,
		/**
		 * Invalid subscription direction. 
		 */
		InvalidDir
	};

	/**
	 * Enum for subscription states. 
	 * 
	 */
	enum class SubscriptionState {
		/**
		 * Initial state, should not be used. 
		 */
		None,
		/**
		 * An outgoing subcription was sent. 
		 */
		OutgoingProgress,
		/**
		 * An incoming subcription is received. 
		 */
		IncomingReceived,
		/**
		 * Subscription is pending, waiting for user approval. 
		 */
		Pending,
		/**
		 * Subscription is accepted. 
		 */
		Active,
		/**
		 * Subscription is terminated normally. 
		 */
		Terminated,
		/**
		 * Subscription was terminated by an error, indicated by Event::getReason() 
		 */
		Error,
		/**
		 * Subscription is about to expire, only sent if [sip]->refresh_generic_subscribe
		 * property is set to 0. 
		 */
		Expiring
	};

	/**
	 * Enum listing frequent telephony tones. 
	 * 
	 */
	enum class ToneID {
		/**
		 * Not a tone. 
		 */
		Undefined,
		/**
		 * Busy tone. 
		 */
		Busy,
		/**
		 */
		CallWaiting,
		/**
		 * Call waiting tone. 
		 */
		CallOnHold,
		/**
		 * Call on hold tone. 
		 */
		CallLost
	};

	/**
	 * Enum describing transport type for LinphoneAddress. 
	 * 
	 */
	enum class TransportType {
		/**
		 */
		Udp,
		/**
		 */
		Tcp,
		/**
		 */
		Tls,
		/**
		 */
		Dtls
	};

	/**
	 * Enum describing uPnP states. 
	 * 
	 */
	enum class UpnpState {
		/**
		 * uPnP is not activate 
		 */
		Idle,
		/**
		 * uPnP process is in progress 
		 */
		Pending,
		/**
		 * Internal use: Only used by port binding. 
		 */
		Adding,
		/**
		 * Internal use: Only used by port binding. 
		 */
		Removing,
		/**
		 * uPnP is not available 
		 */
		NotAvailable,
		/**
		 * uPnP is enabled 
		 */
		Ok,
		/**
		 * uPnP processing has failed 
		 */
		Ko,
		/**
		 * IGD router is blacklisted. 
		 */
		Blacklisted
	};

	/**
	 * Enum describing the result of a version update check. 
	 * 
	 */
	enum class VersionUpdateCheckResult {
		/**
		 */
		UpToDate,
		/**
		 */
		NewVersionAvailable,
		/**
		 */
		Error
	};

	/**
	 * Enum describing the types of argument for LinphoneXmlRpcRequest. 
	 * 
	 */
	enum class XmlRpcArgType {
		/**
		 */
		None,
		/**
		 */
		Int,
		/**
		 */
		String,
		/**
		 */
		StringStruct
	};

	/**
	 * Enum describing the status of a LinphoneXmlRpcRequest. 
	 * 
	 */
	enum class XmlRpcStatus {
		/**
		 */
		Pending,
		/**
		 */
		Ok,
		/**
		 */
		Failed
	};

	/**
	 * Enum describing the ZRTP SAS validation status of a peer URI. 
	 * 
	 */
	enum class ZrtpPeerStatus {
		/**
		 * Peer URI unkown or never validated/invalidated the SAS. 
		 */
		Unknown,
		/**
		 * Peer URI SAS rejected in database. 
		 */
		Invalid,
		/**
		 * Peer URI SAS validated in database. 
		 */
		Valid
	};

	
	typedef int Status;
};

#endif //_ENUMS_HH
