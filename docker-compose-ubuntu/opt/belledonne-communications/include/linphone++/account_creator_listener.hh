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

#ifndef _LINPHONE_ACCOUNT_CREATOR_LISTENER_HH
#define _LINPHONE_ACCOUNT_CREATOR_LISTENER_HH

#include <string>
#include "account_creator.hh"
#include "object.hh"






namespace linphone {

	class AccountCreator;

	/**
	 *
	 */
	class AccountCreatorListener: public Listener {
	
		public:


	
		public:
			
		
			/**
			 * @brief Callback to notify a response of server. 
			 *
			 * @param status The status of the LinphoneAccountCreator test existence operation
			 * that has just finished 
			 */
			LINPHONECXX_PUBLIC virtual void onActivateAccount(const std::shared_ptr<linphone::AccountCreator> & creator, linphone::AccountCreator::Status status, const std::string & resp) {};
			
			/**
			 * @brief Callback to notify a response of server. 
			 *
			 * @param status The status of the LinphoneAccountCreator test existence operation
			 * that has just finished 
			 */
			LINPHONECXX_PUBLIC virtual void onActivateAlias(const std::shared_ptr<linphone::AccountCreator> & creator, linphone::AccountCreator::Status status, const std::string & resp) {};
			
			/**
			 * @brief Callback to notify a response of server. 
			 *
			 * @param status The status of the LinphoneAccountCreator test existence operation
			 * that has just finished 
			 */
			LINPHONECXX_PUBLIC virtual void onIsAccountLinked(const std::shared_ptr<linphone::AccountCreator> & creator, linphone::AccountCreator::Status status, const std::string & resp) {};
			
			/**
			 * @brief Callback to notify a response of server. 
			 *
			 * @param status The status of the LinphoneAccountCreator test existence operation
			 * that has just finished 
			 */
			LINPHONECXX_PUBLIC virtual void onLinkAccount(const std::shared_ptr<linphone::AccountCreator> & creator, linphone::AccountCreator::Status status, const std::string & resp) {};
			
			/**
			 * @brief Callback to notify a response of server. 
			 *
			 * @param status The status of the LinphoneAccountCreator test existence operation
			 * that has just finished 
			 */
			LINPHONECXX_PUBLIC virtual void onIsAliasUsed(const std::shared_ptr<linphone::AccountCreator> & creator, linphone::AccountCreator::Status status, const std::string & resp) {};
			
			/**
			 * @brief Callback to notify a response of server. 
			 *
			 * @param status The status of the LinphoneAccountCreator test existence operation
			 * that has just finished 
			 */
			LINPHONECXX_PUBLIC virtual void onIsAccountActivated(const std::shared_ptr<linphone::AccountCreator> & creator, linphone::AccountCreator::Status status, const std::string & resp) {};
			
			/**
			 * @brief Callback to notify a response of server. 
			 *
			 * @param status The status of the LinphoneAccountCreator test existence operation
			 * that has just finished 
			 */
			LINPHONECXX_PUBLIC virtual void onLoginLinphoneAccount(const std::shared_ptr<linphone::AccountCreator> & creator, linphone::AccountCreator::Status status, const std::string & resp) {};
			
			/**
			 * @brief Callback to notify a response of server. 
			 *
			 * @param status The status of the LinphoneAccountCreator test existence operation
			 * that has just finished 
			 */
			LINPHONECXX_PUBLIC virtual void onIsAccountExist(const std::shared_ptr<linphone::AccountCreator> & creator, linphone::AccountCreator::Status status, const std::string & resp) {};
			
			/**
			 * @brief Callback to notify a response of server. 
			 *
			 * @param status The status of the LinphoneAccountCreator test existence operation
			 * that has just finished 
			 */
			LINPHONECXX_PUBLIC virtual void onUpdateAccount(const std::shared_ptr<linphone::AccountCreator> & creator, linphone::AccountCreator::Status status, const std::string & resp) {};
			
			/**
			 * @brief Callback to notify a response of server. 
			 *
			 * @param status The status of the LinphoneAccountCreator test existence operation
			 * that has just finished 
			 */
			LINPHONECXX_PUBLIC virtual void onRecoverAccount(const std::shared_ptr<linphone::AccountCreator> & creator, linphone::AccountCreator::Status status, const std::string & resp) {};
			
			/**
			 * @brief Callback to notify a response of server. 
			 *
			 * @param status The status of the LinphoneAccountCreator test existence operation
			 * that has just finished 
			 */
			LINPHONECXX_PUBLIC virtual void onCreateAccount(const std::shared_ptr<linphone::AccountCreator> & creator, linphone::AccountCreator::Status status, const std::string & resp) {};
			
			
	};

};

#endif // _LINPHONE_ACCOUNT_CREATOR_LISTENER_HH
