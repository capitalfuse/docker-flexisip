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

#ifndef _LINPHONE_CALL_PARAMS_HH
#define _LINPHONE_CALL_PARAMS_HH

#include <string>
#include "enums.hh"
#include "object.hh"




struct _LinphoneCallParams;


namespace linphone {

	class VideoDefinition;
	class PayloadType;
	class CallParams;

	/**
	 * @brief The #CallParams is an object containing various call related parameters. 
	 *
	 * It can be used to retrieve parameters from a currently running call or modify
	 * the call's characteristics dynamically. 
	 */
	class CallParams: public Object {
	
		public:

			CallParams(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneCallParams *cPtr() {return (_LinphoneCallParams *)mPrivPtr;}

	
		public:
			
		
			/**
			 * @brief Refine bandwidth settings for this call by setting a bandwidth limit for
			 * audio streams. 
			 *
			 * As a consequence, codecs whose bitrates are not compatible with this limit
			 * won't be used. 
			 * 
			 * @param bw The audio bandwidth limit to set in kbit/s. 
			 */
			LINPHONECXX_PUBLIC void setAudioBandwidthLimit(int bw);
			
			/**
			 * @brief Get the audio stream direction. 
			 *
			 * @return The audio stream direction associated with the call params. 
			 */
			LINPHONECXX_PUBLIC linphone::MediaDirection getAudioDirection() const;
			
			/**
			 * @brief Set the audio stream direction. 
			 *
			 * @param dir The audio stream direction associated with this call params. 
			 */
			LINPHONECXX_PUBLIC void setAudioDirection(linphone::MediaDirection dir);
			
			/**
			 * @brief Tell whether audio is enabled or not. 
			 *
			 * @return A boolean value telling whether audio is enabled or not. 
			 */
			LINPHONECXX_PUBLIC bool audioEnabled() const;
			
			/**
			 * @brief Enable audio stream. 
			 *
			 * @param enabled A boolean value telling whether to enable audio or not. 
			 */
			LINPHONECXX_PUBLIC void enableAudio(bool enabled);
			
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
			 * 
			 * 
			 */
			LINPHONECXX_PUBLIC void enableAudioMulticast(bool yesno);
			
			/**
			 * @brief Indicate whether sending of early media was enabled. 
			 *
			 * @return A boolean value telling whether sending of early media was enabled. 
			 */
			LINPHONECXX_PUBLIC bool earlyMediaSendingEnabled() const;
			
			/**
			 * @brief Enable sending of real early media (during outgoing calls). 
			 *
			 * @param enabled A boolean value telling whether to enable early media sending or
			 * not. 
			 */
			LINPHONECXX_PUBLIC void enableEarlyMediaSending(bool enabled);
			
			/**
			 * @brief Tell whether the call is part of the locally managed conference. 
			 *
			 * @warning If a conference server is used to manage conferences, that function
			 * does not return true even if the conference is running. If you want to test
			 * whether the conference is running, you should test whether
			 * Core::getConference() return a non-null pointer. 
			 * 
			 * @return A boolean value telling whether the call is part of the locally managed
			 * conference. 
			 */
			LINPHONECXX_PUBLIC bool getLocalConferenceMode() const;
			
			/**
			 * @brief Tell whether the call has been configured in low bandwidth mode or not. 
			 *
			 * This mode can be automatically discovered thanks to a stun server when
			 * activate_edge_workarounds=1 in section [net] of configuration file. An
			 * application that would have reliable way to know network capacity may not use
			 * activate_edge_workarounds=1 but instead manually configure low bandwidth mode
			 * with enableLowBandwidth(). When enabled, this param may transform a call
			 * request with video in audio only mode. 
			 * 
			 * @return A boolean value telling whether the low bandwidth mode has been
			 * configured/detected. 
			 */
			LINPHONECXX_PUBLIC bool lowBandwidthEnabled() const;
			
			/**
			 * @brief Indicate low bandwith mode. 
			 *
			 * Configuring a call to low bandwidth mode will result in the core to activate
			 * several settings for the call in order to ensure that bitrate usage is lowered
			 * to the minimum possible. Typically, ptime (packetization time) will be
			 * increased, audio codec's output bitrate will be targetted to 20kbit/s provided
			 * that it is achievable by the codec selected after SDP handshake. Video is
			 * automatically disabled. 
			 * 
			 * @param enabled A boolean value telling whether to activate the low bandwidth
			 * mode or not. 
			 */
			LINPHONECXX_PUBLIC void enableLowBandwidth(bool enabled);
			
			/**
			 * @brief Get the kind of media encryption selected for the call. 
			 *
			 * @return The kind of media encryption selected for the call. 
			 */
			LINPHONECXX_PUBLIC linphone::MediaEncryption getMediaEncryption() const;
			
			/**
			 * @brief Set requested media encryption for a call. 
			 *
			 * @param enc The media encryption to use for the call. 
			 */
			LINPHONECXX_PUBLIC void setMediaEncryption(linphone::MediaEncryption enc);
			
			/**
			 * @brief Get requested level of privacy for the call. 
			 *
			 * @return The privacy mode used for the call. 
			 */
			LINPHONECXX_PUBLIC unsigned int getPrivacy() const;
			
			/**
			 * @brief Set requested level of privacy for the call. 
			 *
			 *  javascript  
			 * 
			 * @param privacy The privacy mode to used for the call. 
			 */
			LINPHONECXX_PUBLIC void setPrivacy(unsigned int privacy);
			
			/**
			 * @brief Use to get real time text following rfc4103. 
			 *
			 * @return returns true if call rtt is activated. 
			 */
			LINPHONECXX_PUBLIC bool realtimeTextEnabled() const;
			
			/**
			 * @brief Use to enable real time text following rfc4103. 
			 *
			 * If enabled, outgoing calls put a m=text line in SDP offer . 
			 * 
			 * @param yesno if yes, subsequent outgoing calls will propose rtt 
			 */
			LINPHONECXX_PUBLIC linphone::Status enableRealtimeText(bool yesno);
			
			/**
			 * @brief Get the framerate of the video that is received. 
			 *
			 * @return The actual received framerate in frames per seconds, 0 if not
			 * available. 
			 */
			LINPHONECXX_PUBLIC float getReceivedFramerate() const;
			
			/**
			 * @brief Get the definition of the received video. 
			 *
			 * @return The received #VideoDefinition 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::VideoDefinition> getReceivedVideoDefinition() const;
			
			/**
			 * @brief Get the path for the audio recording of the call. 
			 *
			 * @return The path to the audio recording of the call. 
			 */
			LINPHONECXX_PUBLIC std::string getRecordFile() const;
			
			/**
			 * @brief Enable recording of the call. 
			 *
			 * This function must be used before the call parameters are assigned to the call.
			 * The call recording can be started and paused after the call is established with
			 * Call::startRecording() and linphone_call_pause_recording(). 
			 * 
			 * @param path A string containing the path and filename of the file where
			 * audio/video streams are to be written. The filename must have either .mkv or
			 * .wav extention. The video stream will be written only if a MKV file is given. 
			 */
			LINPHONECXX_PUBLIC void setRecordFile(const std::string & path);
			
			/**
			 * @brief Get the RTP profile being used. 
			 *
			 * @return The RTP profile. 
			 */
			LINPHONECXX_PUBLIC std::string getRtpProfile() const;
			
			/**
			 * @brief Get the framerate of the video that is sent. 
			 *
			 * @return The actual sent framerate in frames per seconds, 0 if not available. 
			 */
			LINPHONECXX_PUBLIC float getSentFramerate() const;
			
			/**
			 * @brief Get the definition of the sent video. 
			 *
			 * @return The sent #VideoDefinition 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::VideoDefinition> getSentVideoDefinition() const;
			
			/**
			 * @brief Get the session name of the media session (ie in SDP). 
			 *
			 * Subject from the SIP message can be retrieved using getCustomHeader() and is
			 * different. 
			 * 
			 * @return The session name of the media session. 
			 */
			LINPHONECXX_PUBLIC std::string getSessionName() const;
			
			/**
			 * @brief Set the session name of the media session (ie in SDP). 
			 *
			 * Subject from the SIP message (which is different) can be set using
			 * linphone_call_params_set_custom_header(). 
			 * 
			 * @param name The session name to be used. 
			 */
			LINPHONECXX_PUBLIC void setSessionName(const std::string & name);
			
			/**
			 * @brief Get the audio payload type that has been selected by a call. 
			 *
			 * @return The selected payload type. nullptr is returned if no audio payload type
			 * has been seleced by the call. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::PayloadType> getUsedAudioPayloadType() const;
			
			/**
			 * @brief Get the text payload type that has been selected by a call. 
			 *
			 * @return The selected payload type. nullptr is returned if no text payload type
			 * has been seleced by the call. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::PayloadType> getUsedTextPayloadType() const;
			
			/**
			 * @brief Get the video payload type that has been selected by a call. 
			 *
			 * @return The selected payload type. nullptr is returned if no video payload type
			 * has been seleced by the call. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::PayloadType> getUsedVideoPayloadType() const;
			
			/**
			 * @brief Get the video stream direction. 
			 *
			 * @return The video stream direction associated with the call params. 
			 */
			LINPHONECXX_PUBLIC linphone::MediaDirection getVideoDirection() const;
			
			/**
			 * @brief Set the video stream direction. 
			 *
			 * @param dir The video stream direction associated with this call params. 
			 */
			LINPHONECXX_PUBLIC void setVideoDirection(linphone::MediaDirection dir);
			
			/**
			 * @brief Tell whether video is enabled or not. 
			 *
			 * @return A boolean value telling whether video is enabled or not. 
			 */
			LINPHONECXX_PUBLIC bool videoEnabled() const;
			
			/**
			 * @brief Enable video stream. 
			 *
			 * @param enabled A boolean value telling whether to enable video or not. 
			 */
			LINPHONECXX_PUBLIC void enableVideo(bool enabled);
			
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
			 * call video stream is sent to this multicast address.  For incoming calls
			 * behavior is unchanged. 
			 * 
			 * @param yesno if yes, subsequent outgoing calls will propose multicast ip set by
			 * linphone_core_set_video_multicast_addr 
			 */
			LINPHONECXX_PUBLIC void enableVideoMulticast(bool yesno);
			
			/**
			 * @brief Add a custom SIP header in the INVITE for a call. 
			 *
			 * @param headerValue The content of the header to add. 
			 */
			LINPHONECXX_PUBLIC void addCustomHeader(const std::string & headerName, const std::string & headerValue);
			
			/**
			 * @brief Add a custom attribute related to all the streams in the SDP exchanged
			 * within SIP messages during a call. 
			 *
			 * @param attributeValue The content value of the attribute to add. 
			 */
			LINPHONECXX_PUBLIC void addCustomSdpAttribute(const std::string & attributeName, const std::string & attributeValue);
			
			/**
			 * @brief Add a custom attribute related to a specific stream in the SDP exchanged
			 * within SIP messages during a call. 
			 *
			 * @param attributeValue The content value of the attribute to add. 
			 */
			LINPHONECXX_PUBLIC void addCustomSdpMediaAttribute(linphone::StreamType type, const std::string & attributeName, const std::string & attributeValue);
			
			/**
			 * @brief Clear the custom SDP attributes related to all the streams in the SDP
			 * exchanged within SIP messages during a call. 
			 *
			 */
			LINPHONECXX_PUBLIC void clearCustomSdpAttributes();
			
			/**
			 * @brief Clear the custom SDP attributes related to a specific stream in the SDP
			 * exchanged within SIP messages during a call. 
			 *
			 * @param type The type of the stream to clear the custom SDP attributes from. 
			 */
			LINPHONECXX_PUBLIC void clearCustomSdpMediaAttributes(linphone::StreamType type);
			
			/**
			 * @brief Copy an existing #linphone::CallParams object to a new
			 * #linphone::CallParams object. 
			 *
			 * @return A copy of the #linphone::CallParams object. 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::CallParams> copy() const;
			
			/**
			 * @brief Get a custom SIP header. 
			 *
			 * @param headerName The name of the header to get. 
			 * 
			 * @return The content of the header or nullptr if not found. 
			 */
			LINPHONECXX_PUBLIC std::string getCustomHeader(const std::string & headerName) const;
			
			/**
			 * @brief Get a custom SDP attribute that is related to all the streams. 
			 *
			 * @param attributeName The name of the attribute to get. 
			 * 
			 * @return The content value of the attribute or nullptr if not found. 
			 */
			LINPHONECXX_PUBLIC std::string getCustomSdpAttribute(const std::string & attributeName) const;
			
			/**
			 * @brief Get a custom SDP attribute that is related to a specific stream. 
			 *
			 * @param attributeName The name of the attribute to get. 
			 * 
			 * @return The content value of the attribute or nullptr if not found. 
			 */
			LINPHONECXX_PUBLIC std::string getCustomSdpMediaAttribute(linphone::StreamType type, const std::string & attributeName) const;
			
			
	};

};

#endif // _LINPHONE_CALL_PARAMS_HH
