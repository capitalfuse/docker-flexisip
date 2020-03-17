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

#ifndef _LINPHONE_PLAYER_HH
#define _LINPHONE_PLAYER_HH

#include <string>
#include "player.hh"
#include "object.hh"




struct _LinphonePlayer;


namespace linphone {

	class Core;
	class PlayerListener;

	/**
	 * @brief Player interface. 
	 *
	 */
	class Player: public MultiListenableObject {
	
		public:
			/**
			* The state of a LinphonePlayer. 
			*
			*/
			enum class State {
				/**
				* No file is opened for playing. 
				*/
				Closed,
				/**
				* The player is paused. 
				*/
				Paused,
				/**
				* The player is playing. 
				*/
				Playing
			};


			Player(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphonePlayer *cPtr() {return (_LinphonePlayer *)mPrivPtr;}

			LINPHONECXX_PUBLIC void addListener(const std::shared_ptr<PlayerListener> &listener);
			LINPHONECXX_PUBLIC void removeListener(const std::shared_ptr<PlayerListener> &listener);
	
		public:
			
		
			/**
			 * @brief Returns the #Core object managing this player's call, if any. 
			 *
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Core> getCore() const;
			
			/**
			 * @brief Get the current position in the opened file. 
			 *
			 * @return The current position in the opened file 
			 */
			LINPHONECXX_PUBLIC int getCurrentPosition();
			
			/**
			 * @brief Get the duration of the opened file. 
			 *
			 * @return The duration of the opened file 
			 */
			LINPHONECXX_PUBLIC int getDuration();
			
			/**
			 * @brief Get the current state of a player. 
			 *
			 * @return The current state of the player. 
			 */
			LINPHONECXX_PUBLIC State getState();
			
			/**
			 * @brief Close the opened file. 
			 *
			 */
			LINPHONECXX_PUBLIC void close();
			
			/**
			 * @brief Open a file for playing. 
			 *
			 * @param filename The path to the file to open 
			 */
			LINPHONECXX_PUBLIC linphone::Status open(const std::string & filename);
			
			/**
			 * @brief Pause the playing of a file. 
			 *
			 * @return 0 on success, a negative value otherwise 
			 */
			LINPHONECXX_PUBLIC linphone::Status pause();
			
			/**
			 * @brief Seek in an opened file. 
			 *
			 * @param timeMs The time we want to go to in the file (in milliseconds). 
			 * 
			 * @return 0 on success, a negative value otherwise. 
			 */
			LINPHONECXX_PUBLIC linphone::Status seek(int timeMs);
			
			/**
			 * @brief Start playing a file that has been opened with open(). 
			 *
			 * @return 0 on success, a negative value otherwise 
			 */
			LINPHONECXX_PUBLIC linphone::Status start();
			
			
		private:
			void *createCallbacks() override;
	};

};

#endif // _LINPHONE_PLAYER_HH
