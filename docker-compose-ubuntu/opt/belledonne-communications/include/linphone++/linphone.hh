/*
linphone.hh
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

#ifndef _LINPHONE_HH
#define _LINPHONE_HH

#include "enums.hh"
#include "account_creator_listener.hh"
#include "xml_rpc_request_listener.hh"
#include "event_listener.hh"
#include "logging_service_listener.hh"
#include "chat_room_listener.hh"
#include "chat_message_listener.hh"
#include "player_listener.hh"
#include "call_listener.hh"
#include "friend_list_listener.hh"
#include "core_listener.hh"
#include "nat_policy.hh"
#include "video_activation_policy.hh"
#include "presence_service.hh"
#include "transports.hh"
#include "participant.hh"
#include "conference_params.hh"
#include "info_message.hh"
#include "presence_activity.hh"
#include "call.hh"
#include "config.hh"
#include "participant_imdn_state.hh"
#include "tunnel.hh"
#include "event.hh"
#include "magic_search.hh"
#include "vcard.hh"
#include "chat_room_params.hh"
#include "participant_device.hh"
#include "conference.hh"
#include "core.hh"
#include "buffer.hh"
#include "friend_list.hh"
#include "headers.hh"
#include "dial_plan.hh"
#include "address.hh"
#include "factory.hh"
#include "call_stats.hh"
#include "account_creator.hh"
#include "event_log.hh"
#include "error_info.hh"
#include "tunnel_config.hh"
#include "presence_note.hh"
#include "presence_person.hh"
#include "range.hh"
#include "xml_rpc_session.hh"
#include "auth_info.hh"
#include "chat_room.hh"
#include "chat_message.hh"
#include "presence_model.hh"
#include "search_result.hh"
#include "participant_device_identity.hh"
#include "call_log.hh"
#include "im_notif_policy.hh"
#include "xml_rpc_request.hh"
#include "payload_type.hh"
#include "player.hh"
#include "video_definition.hh"
#include "content.hh"
#include "proxy_config.hh"
#include "call_params.hh"
#include "logging_service.hh"
#include "friend.hh"

#endif // _LINPHONE_HH
