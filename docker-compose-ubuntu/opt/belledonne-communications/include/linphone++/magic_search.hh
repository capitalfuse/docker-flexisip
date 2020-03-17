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

#ifndef _LINPHONE_MAGIC_SEARCH_HH
#define _LINPHONE_MAGIC_SEARCH_HH

#include <string>
#include <list>
#include "object.hh"




struct _LinphoneMagicSearch;


namespace linphone {

	class SearchResult;

	/**
	 * @brief A #MagicSearch is used to do specifics searchs. 
	 *
	 */
	class MagicSearch: public Object {
	
		public:

			MagicSearch(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneMagicSearch *cPtr() {return (_LinphoneMagicSearch *)mPrivPtr;}

	
		public:
			
		
			/**
			 *
			 * @return the delimiter used to find matched filter word 
			 */
			LINPHONECXX_PUBLIC std::string getDelimiter() const;
			
			/**
			 * @brief Set the delimiter used to find matched filter word. 
			 *
			 * @param delimiter delimiter (example "-_.,") 
			 */
			LINPHONECXX_PUBLIC void setDelimiter(const std::string & delimiter);
			
			/**
			 *
			 * @return if the search is limited 
			 */
			LINPHONECXX_PUBLIC bool getLimitedSearch() const;
			
			/**
			 * @brief Enable or disable the limited search. 
			 *
			 * @param limited 
			 */
			LINPHONECXX_PUBLIC void setLimitedSearch(bool limited);
			
			/**
			 *
			 * @return the maximum value used to calculate the weight in search 
			 */
			LINPHONECXX_PUBLIC unsigned int getMaxWeight() const;
			
			/**
			 * @brief Set the maximum value used to calculate the weight in search. 
			 *
			 * @param weight maximum weight 
			 */
			LINPHONECXX_PUBLIC void setMaxWeight(unsigned int weight);
			
			/**
			 *
			 * @return the minimum value used to calculate the weight in search 
			 */
			LINPHONECXX_PUBLIC unsigned int getMinWeight() const;
			
			/**
			 * @brief Set the minimum value used to calculate the weight in search. 
			 *
			 * @param weight minimum weight 
			 */
			LINPHONECXX_PUBLIC void setMinWeight(unsigned int weight);
			
			/**
			 *
			 * @return the number of the maximum SearchResult which will be return 
			 */
			LINPHONECXX_PUBLIC unsigned int getSearchLimit() const;
			
			/**
			 * @brief Set the number of the maximum SearchResult which will be return. 
			 *
			 * @param limit 
			 */
			LINPHONECXX_PUBLIC void setSearchLimit(unsigned int limit);
			
			/**
			 *
			 * @return if the delimiter search is used 
			 */
			LINPHONECXX_PUBLIC bool getUseDelimiter();
			
			/**
			 * @brief Enable or disable the delimiter in search. 
			 *
			 * @param enable 
			 */
			LINPHONECXX_PUBLIC void setUseDelimiter(bool enable);
			
			/**
			 * @brief Create a sorted list of SearchResult from SipUri, Contact name, Contact
			 * displayname, Contact phone number, which match with a filter word The last item
			 * list will be an address formed with "filter" if a proxy config exist During the
			 * first search, a cache is created and used for the next search Use
			 * resetSearchCache() to begin a new search. 
			 *
			 * @param domain domain which we want to search only
			 * 
			 * 
			 * @return sorted list of A list of #SearchResult objects. LinphoneSearchResult 
			 * The objects inside the list are freshly allocated with a reference counter
			 * equal to one, so they need to be freed on list destruction with
			 * bctbx_list_free_with_data() for instance.   
			 */
			LINPHONECXX_PUBLIC std::list<std::shared_ptr<linphone::SearchResult>> getContactListFromFilter(const std::string & filter, const std::string & domain) const;
			
			/**
			 * @brief Reset the cache to begin a new search. 
			 *
			 */
			LINPHONECXX_PUBLIC void resetSearchCache();
			
			
	};

};

#endif // _LINPHONE_MAGIC_SEARCH_HH
