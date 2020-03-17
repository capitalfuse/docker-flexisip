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

#ifndef _LINPHONE_CALL_STATS_HH
#define _LINPHONE_CALL_STATS_HH

#include <cstdint>
#include "enums.hh"
#include "object.hh"




struct _LinphoneCallStats;


namespace linphone {


	/**
	 * @brief The #CallStats objects carries various statistic informations regarding
	 * quality of audio or video streams. 
	 *
	 * To receive these informations periodically and as soon as they are computed,
	 * the application is invited to place a LinphoneCoreCallStatsUpdatedCb callback
	 * in the LinphoneCoreVTable structure it passes for instanciating the #Core
	 * object (see linphone_core_new ).
	 * 
	 * At any time, the application can access last computed statistics using
	 * linphone_call_get_audio_stats() or linphone_call_get_video_stats(). 
	 */
	class CallStats: public Object {
	
		public:

			CallStats(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneCallStats *cPtr() {return (_LinphoneCallStats *)mPrivPtr;}

	
		public:
			
		
			/**
			 * @brief Get the bandwidth measurement of the received stream, expressed in
			 * kbit/s, including IP/UDP/RTP headers. 
			 *
			 * @return The bandwidth measurement of the received stream in kbit/s. 
			 */
			LINPHONECXX_PUBLIC float getDownloadBandwidth() const;
			
			/**
			 * @brief Get the estimated bandwidth measurement of the received stream,
			 * expressed in kbit/s, including IP/UDP/RTP headers. 
			 *
			 * @return The estimated bandwidth measurement of the received stream in kbit/s. 
			 */
			LINPHONECXX_PUBLIC float getEstimatedDownloadBandwidth() const;
			
			/**
			 * @brief Get the state of ICE processing. 
			 *
			 * @return The state of ICE processing. 
			 */
			LINPHONECXX_PUBLIC linphone::IceState getIceState() const;
			
			/**
			 * @brief Get the IP address family of the remote peer. 
			 *
			 * @return The IP address family of the remote peer. 
			 */
			LINPHONECXX_PUBLIC linphone::AddressFamily getIpFamilyOfRemote() const;
			
			/**
			 * @brief Get the jitter buffer size in ms. 
			 *
			 * @return The jitter buffer size in ms. 
			 */
			LINPHONECXX_PUBLIC float getJitterBufferSizeMs() const;
			
			/**
			 * @brief Gets the cumulative number of late packets. 
			 *
			 * @return The cumulative number of late packets 
			 */
			LINPHONECXX_PUBLIC uint64_t getLatePacketsCumulativeNumber() const;
			
			/**
			 * @brief Gets the local late rate since last report. 
			 *
			 * @return The local late rate 
			 */
			LINPHONECXX_PUBLIC float getLocalLateRate() const;
			
			/**
			 * @brief Get the local loss rate since last report. 
			 *
			 * @return The local loss rate 
			 */
			LINPHONECXX_PUBLIC float getLocalLossRate() const;
			
			/**
			 * @brief Gets the remote reported interarrival jitter. 
			 *
			 * @return The interarrival jitter at last received receiver report 
			 */
			LINPHONECXX_PUBLIC float getReceiverInterarrivalJitter() const;
			
			/**
			 * @brief Gets the remote reported loss rate since last report. 
			 *
			 * @return The receiver loss rate 
			 */
			LINPHONECXX_PUBLIC float getReceiverLossRate() const;
			
			/**
			 * @brief Get the round trip delay in s. 
			 *
			 * @return The round trip delay in s. 
			 */
			LINPHONECXX_PUBLIC float getRoundTripDelay() const;
			
			/**
			 * @brief Get the bandwidth measurement of the received RTCP, expressed in kbit/s,
			 * including IP/UDP/RTP headers. 
			 *
			 * @return The bandwidth measurement of the received RTCP in kbit/s. 
			 */
			LINPHONECXX_PUBLIC float getRtcpDownloadBandwidth() const;
			
			/**
			 * @brief Get the bandwidth measurement of the sent RTCP, expressed in kbit/s,
			 * including IP/UDP/RTP headers. 
			 *
			 * @return The bandwidth measurement of the sent RTCP in kbit/s. 
			 */
			LINPHONECXX_PUBLIC float getRtcpUploadBandwidth() const;
			
			/**
			 * @brief Gets the local interarrival jitter. 
			 *
			 * @return The interarrival jitter at last emitted sender report 
			 */
			LINPHONECXX_PUBLIC float getSenderInterarrivalJitter() const;
			
			/**
			 * @brief Get the local loss rate since last report. 
			 *
			 * @return The sender loss rate 
			 */
			LINPHONECXX_PUBLIC float getSenderLossRate() const;
			
			/**
			 * @brief Get the type of the stream the stats refer to. 
			 *
			 * @return The type of the stream the stats refer to 
			 */
			LINPHONECXX_PUBLIC linphone::StreamType getType() const;
			
			/**
			 * @brief Get the bandwidth measurement of the sent stream, expressed in kbit/s,
			 * including IP/UDP/RTP headers. 
			 *
			 * @return The bandwidth measurement of the sent stream in kbit/s. 
			 */
			LINPHONECXX_PUBLIC float getUploadBandwidth() const;
			
			/**
			 * @brief Get the state of uPnP processing. 
			 *
			 * @return The state of uPnP processing. 
			 */
			LINPHONECXX_PUBLIC linphone::UpnpState getUpnpState() const;
			
			
	};

};

#endif // _LINPHONE_CALL_STATS_HH
