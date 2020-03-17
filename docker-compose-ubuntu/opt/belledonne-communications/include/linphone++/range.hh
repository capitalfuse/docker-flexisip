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

#ifndef _LINPHONE_RANGE_HH
#define _LINPHONE_RANGE_HH

#include "object.hh"




struct _LinphoneRange;


namespace linphone {


	/**
	 * @brief Structure describing a range of integers. 
	 *
	 */
	class Range: public Object {
	
		public:

			Range(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneRange *cPtr() {return (_LinphoneRange *)mPrivPtr;}

	
		public:
			
		
			/**
			 * @brief Gets the higher value of the range. 
			 *
			 * @return The higher value 
			 */
			LINPHONECXX_PUBLIC int getMax() const;
			
			/**
			 * @brief Sets the higher value of the range. 
			 *
			 * @param max the value to set 
			 */
			LINPHONECXX_PUBLIC void setMax(int max);
			
			/**
			 * @brief Gets the lower value of the range. 
			 *
			 * @return The lower value 
			 */
			LINPHONECXX_PUBLIC int getMin() const;
			
			/**
			 * @brief Sets the lower value of the range. 
			 *
			 * @param min the value to set 
			 */
			LINPHONECXX_PUBLIC void setMin(int min);
			
			
	};

};

#endif // _LINPHONE_RANGE_HH
