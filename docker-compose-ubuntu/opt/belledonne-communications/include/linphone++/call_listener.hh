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

#ifndef _LINPHONE_CALL_LISTENER_HH
#define _LINPHONE_CALL_LISTENER_HH

#include <string>
#include "call.hh"
#include "object.hh"






namespace linphone {

	class Call;
	class InfoMessage;
	class Headers;
	class CallStats;

	/**
	 *
	 */
	class CallListener: public Listener {
	
		public:


	
		public:
			
		
			/**
			 * @brief Callback for notifying a snapshot taken. 
			 *
			 * @param filepath the name of the saved file 
			 */
			LINPHONECXX_PUBLIC virtual void onSnapshotTaken(const std::shared_ptr<linphone::Call> & call, const std::string & filepath) {};
			
			/**
			 * @brief Call state notification callback. 
			 *
			 * @param message An informational message about the state. 
			 */
			LINPHONECXX_PUBLIC virtual void onStateChanged(const std::shared_ptr<linphone::Call> & call, linphone::Call::State cstate, const std::string & message) {};
			
			/**
			 * @brief Callback for notifying progresses of transfers. 
			 *
			 * @param cstate The state of the call to transfer target at the far end. 
			 */
			LINPHONECXX_PUBLIC virtual void onTransferStateChanged(const std::shared_ptr<linphone::Call> & call, linphone::Call::State cstate) {};
			
			/**
			 * @brief Callback for notifying a received TMMBR. 
			 *
			 * @param tmmbr the value of the received TMMBR 
			 */
			LINPHONECXX_PUBLIC virtual void onTmmbrReceived(const std::shared_ptr<linphone::Call> & call, int streamIndex, int tmmbr) {};
			
			/**
			 * @brief Callback for receiving info messages. 
			 *
			 * @param msg LinphoneInfoMessage object. 
			 */
			LINPHONECXX_PUBLIC virtual void onInfoMessageReceived(const std::shared_ptr<linphone::Call> & call, const std::shared_ptr<const linphone::InfoMessage> & msg) {};
			
			/**
			 * @brief Call encryption changed callback. 
			 *
			 * @param authenticationToken An authentication_token, currently set for ZRTP kind
			 * of encryption only. 
			 */
			LINPHONECXX_PUBLIC virtual void onEncryptionChanged(const std::shared_ptr<linphone::Call> & call, bool on, const std::string & authenticationToken) {};
			
			/**
			 * @brief Callback for notifying the processing SIP ACK messages. 
			 *
			 * @param isReceived if true this ACK is an incoming one, otherwise it is an ACK
			 * about to be sent. 
			 */
			LINPHONECXX_PUBLIC virtual void onAckProcessing(const std::shared_ptr<linphone::Call> & call, const std::shared_ptr<linphone::Headers> & ack, bool isReceived) {};
			
			/**
			 * @brief Callback for being notified of received DTMFs. 
			 *
			 * @param dtmf The ascii code of the dtmf 
			 */
			LINPHONECXX_PUBLIC virtual void onDtmfReceived(const std::shared_ptr<linphone::Call> & call, int dtmf) {};
			
			/**
			 * @brief Callback to notify a next video frame has been decoded. 
			 *
			 * @param call LinphoneCall for which the next video frame has been decoded 
			 */
			LINPHONECXX_PUBLIC virtual void onNextVideoFrameDecoded(const std::shared_ptr<linphone::Call> & call) {};
			
			/**
			 * @brief Callback for receiving quality statistics for calls. 
			 *
			 * @param stats LinphoneCallStats object 
			 */
			LINPHONECXX_PUBLIC virtual void onStatsUpdated(const std::shared_ptr<linphone::Call> & call, const std::shared_ptr<const linphone::CallStats> & stats) {};
			
			
	};

};

#endif // _LINPHONE_CALL_LISTENER_HH
