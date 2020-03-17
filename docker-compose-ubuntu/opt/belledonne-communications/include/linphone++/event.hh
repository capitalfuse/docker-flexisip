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

#ifndef _LINPHONE_EVENT_HH
#define _LINPHONE_EVENT_HH

#include <string>
#include "enums.hh"
#include "object.hh"




struct _LinphoneEvent;


namespace linphone {

	class Core;
	class ErrorInfo;
	class Address;
	class Content;
	class EventListener;

	/**
	 * @brief Object representing an event state, which is subcribed or published. 
	 *
	 * @see Core::publish() 
	 * 
	 * @see Core::subscribe() 
	 */
	class Event: public MultiListenableObject {
	
		public:

			Event(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneEvent *cPtr() {return (_LinphoneEvent *)mPrivPtr;}

			LINPHONECXX_PUBLIC void addListener(const std::shared_ptr<EventListener> &listener);
			LINPHONECXX_PUBLIC void removeListener(const std::shared_ptr<EventListener> &listener);
	
		public:
			
		
			/**
			 * @brief Returns back pointer to the #Core that created this #linphone::Event. 
			 *
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<linphone::Core> getCore() const;
			
			/**
			 * @brief Get full details about an error occured. 
			 *
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::ErrorInfo> getErrorInfo() const;
			
			/**
			 * @brief Get the "from" address of the subscription. 
			 *
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::Address> getFrom() const;
			
			/**
			 * @brief Get the name of the event as specified in the event package RFC. 
			 *
			 */
			LINPHONECXX_PUBLIC std::string getName() const;
			
			/**
			 * @brief Get publish state. 
			 *
			 * If the event object was not created by a publish mechanism, LinphonePublishNone
			 * is returned. 
			 */
			LINPHONECXX_PUBLIC linphone::PublishState getPublishState() const;
			
			/**
			 * @brief Return reason code (in case of error state reached). 
			 *
			 */
			LINPHONECXX_PUBLIC linphone::Reason getReason() const;
			
			/**
			 * @brief Get the "contact" address of the subscription. 
			 *
			 * @return The "contact" address of the subscription 
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::Address> getRemoteContact() const;
			
			/**
			 * @brief Get the resource address of the subscription or publish. 
			 *
			 */
			LINPHONECXX_PUBLIC std::shared_ptr<const linphone::Address> getResource() const;
			
			/**
			 * @brief Get subscription direction. 
			 *
			 * If the object wasn't created by a subscription mechanism,
			 * LinphoneSubscriptionInvalidDir is returned. 
			 */
			LINPHONECXX_PUBLIC linphone::SubscriptionDir getSubscriptionDir();
			
			/**
			 * @brief Get subscription state. 
			 *
			 * If the event object was not created by a subscription mechanism,
			 * LinphoneSubscriptionNone is returned. 
			 */
			LINPHONECXX_PUBLIC linphone::SubscriptionState getSubscriptionState() const;
			
			/**
			 * @brief Accept an incoming subcription. 
			 *
			 */
			LINPHONECXX_PUBLIC linphone::Status acceptSubscription();
			
			/**
			 * @brief Add a custom header to an outgoing susbscription or publish. 
			 *
			 * @param value the header's value. 
			 */
			LINPHONECXX_PUBLIC void addCustomHeader(const std::string & name, const std::string & value);
			
			/**
			 * @brief Deny an incoming subscription with given reason. 
			 *
			 */
			LINPHONECXX_PUBLIC linphone::Status denySubscription(linphone::Reason reason);
			
			/**
			 * @brief Obtain the value of a given header for an incoming subscription. 
			 *
			 * @param name header's name 
			 * 
			 * @return the header's value or nullptr if such header doesn't exist. 
			 */
			LINPHONECXX_PUBLIC std::string getCustomHeader(const std::string & name);
			
			/**
			 * @brief Send a notification. 
			 *
			 * @param body an optional body containing the actual notification data. 
			 * 
			 * @return 0 if successful, -1 otherwise. 
			 */
			LINPHONECXX_PUBLIC linphone::Status notify(const std::shared_ptr<const linphone::Content> & body);
			
			/**
			 * @brief Prevent an event from refreshing its publish. 
			 *
			 * This is useful to let registrations to expire naturally (or) when the
			 * application wants to keep control on when refreshes are sent. The refreshing
			 * operations can be resumed with ProxyConfig::refreshRegister(). 
			 */
			LINPHONECXX_PUBLIC void pausePublish();
			
			/**
			 * @brief Refresh an outgoing publish keeping the same body. 
			 *
			 * @return 0 if successful, -1 otherwise. 
			 */
			LINPHONECXX_PUBLIC linphone::Status refreshPublish();
			
			/**
			 * @brief Refresh an outgoing subscription keeping the same body. 
			 *
			 * @return 0 if successful, -1 otherwise. 
			 */
			LINPHONECXX_PUBLIC linphone::Status refreshSubscribe();
			
			/**
			 * @brief Send a publish created by Core::createPublish(). 
			 *
			 * @param body the new data to be published 
			 */
			LINPHONECXX_PUBLIC linphone::Status sendPublish(const std::shared_ptr<const linphone::Content> & body);
			
			/**
			 * @brief Send a subscription previously created by Core::createSubscribe(). 
			 *
			 * @param body optional content to attach with the subscription. 
			 * 
			 * @return 0 if successful, -1 otherwise. 
			 */
			LINPHONECXX_PUBLIC linphone::Status sendSubscribe(const std::shared_ptr<const linphone::Content> & body);
			
			/**
			 * @brief Terminate an incoming or outgoing subscription that was previously
			 * acccepted, or a previous publication. 
			 *
			 * The #linphone::Event shall not be used anymore after this operation, unless the
			 * application explicitely took a reference on the object with linphone_event_ref. 
			 */
			LINPHONECXX_PUBLIC void terminate();
			
			/**
			 * @brief Update (refresh) a publish. 
			 *
			 * @param body the new data to be published 
			 */
			LINPHONECXX_PUBLIC linphone::Status updatePublish(const std::shared_ptr<const linphone::Content> & body);
			
			/**
			 * @brief Update (refresh) an outgoing subscription, changing the body. 
			 *
			 * @param body an optional body to include in the subscription update, may be
			 * nullptr.    
			 */
			LINPHONECXX_PUBLIC linphone::Status updateSubscribe(const std::shared_ptr<const linphone::Content> & body);
			
			
		private:
			void *createCallbacks() override;
	};

};

#endif // _LINPHONE_EVENT_HH
