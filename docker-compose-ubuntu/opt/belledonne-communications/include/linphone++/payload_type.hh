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

#ifndef _LINPHONE_PAYLOAD_TYPE_HH
#define _LINPHONE_PAYLOAD_TYPE_HH

#include <string>
#include "object.hh"




struct _LinphonePayloadType;


namespace linphone {


	/**
	 * @brief Object representing an RTP payload type. 
	 *
	 */
	class PayloadType: public Object {
	
		public:

			PayloadType(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphonePayloadType *cPtr() {return (_LinphonePayloadType *)mPrivPtr;}

	
		public:
			
		
			/**
			 * @brief Get the number of channels. 
			 *
			 * @return The number of channels. 
			 */
			LINPHONECXX_PUBLIC int getChannels() const;
			
			/**
			 * @brief Get the clock rate of a payload type. 
			 *
			 * @return [in] The clock rate in Hz. 
			 */
			LINPHONECXX_PUBLIC int getClockRate() const;
			
			/**
			 * @brief Return a string describing a payload type. 
			 *
			 * The format of the string is <mime_type>/<clock_rate>/<channels>. 
			 * 
			 * @return The description of the payload type. Must be release after use. 
			 */
			LINPHONECXX_PUBLIC std::string getDescription() const;
			
			/**
			 * @brief Get a description of the encoder used to provide a payload type. 
			 *
			 * @return The description of the encoder. Can be nullptr if the payload type is
			 * not supported by Mediastreamer2. 
			 */
			LINPHONECXX_PUBLIC std::string getEncoderDescription() const;
			
			/**
			 * @brief Check whether the payload is usable according the bandwidth targets set
			 * in the core. 
			 *
			 * @return  if the payload type is usable. 
			 */
			LINPHONECXX_PUBLIC bool isUsable() const;
			
			/**
			 * @brief Tells whether the specified payload type represents a variable bitrate
			 * codec. 
			 *
			 * @return  if the payload type represents a VBR codec, true instead. 
			 */
			LINPHONECXX_PUBLIC bool isVbr() const;
			
			/**
			 * @brief Get the mime type. 
			 *
			 * @return The mime type. 
			 */
			LINPHONECXX_PUBLIC std::string getMimeType() const;
			
			/**
			 * @brief Get the normal bitrate in bits/s. 
			 *
			 * @return The normal bitrate in bits/s or -1 if an error has occured. 
			 */
			LINPHONECXX_PUBLIC int getNormalBitrate() const;
			
			/**
			 * @brief Change the normal bitrate of a payload type. 
			 *
			 * @param bitrate The new bitrate in bits/s. 
			 */
			LINPHONECXX_PUBLIC void setNormalBitrate(int bitrate);
			
			/**
			 * @brief Returns the payload type number assigned for this codec. 
			 *
			 * @return The number of the payload type. 
			 */
			LINPHONECXX_PUBLIC int getNumber() const;
			
			/**
			 * @brief Force a number for a payload type. 
			 *
			 * The #Core does payload type number assignment automatically. This function is
			 * mainly to be used for tests, in order to override the automatic assignment
			 * mechanism. 
			 * 
			 * @param number The number to assign to the payload type. 
			 */
			LINPHONECXX_PUBLIC void setNumber(int number);
			
			/**
			 * @brief Get the format parameters for incoming streams. 
			 *
			 * @return The format parameters as string. 
			 */
			LINPHONECXX_PUBLIC std::string getRecvFmtp() const;
			
			/**
			 * @brief Set the format parameters for incoming streams. 
			 *
			 * @param recvFmtp The new format parameters as string. The string will be copied. 
			 */
			LINPHONECXX_PUBLIC void setRecvFmtp(const std::string & recvFmtp);
			
			/**
			 * @brief Get the format parameters for outgoing streams. 
			 *
			 * @return The format parameters as string. 
			 */
			LINPHONECXX_PUBLIC std::string getSendFmtp() const;
			
			/**
			 * @brief Set the format parameters for outgoing streams. 
			 *
			 * @param sendFmtp The new format parameters as string. The string will be copied. 
			 */
			LINPHONECXX_PUBLIC void setSendFmtp(const std::string & sendFmtp);
			
			/**
			 * @brief Get the type of a payload type. 
			 *
			 * @return The type of the payload e.g. PAYLOAD_AUDIO_CONTINUOUS or PAYLOAD_VIDEO. 
			 */
			LINPHONECXX_PUBLIC int getType() const;
			
			/**
			 * @brief Enable/disable a payload type. 
			 *
			 * @param enabled Set true for enabling and true for disabling. 
			 * 
			 * @return 0 for success, -1 for failure. 
			 */
			LINPHONECXX_PUBLIC int enable(bool enabled);
			
			/**
			 * @brief Check whether a palyoad type is enabled. 
			 *
			 * @return  if enabled, true if disabled. 
			 */
			LINPHONECXX_PUBLIC bool enabled() const;
			
			
	};

};

#endif // _LINPHONE_PAYLOAD_TYPE_HH
