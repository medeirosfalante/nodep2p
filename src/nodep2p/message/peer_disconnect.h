/**
 * @file peer_disconnect.h
 * @author  Rafael Medeiros
 * @brief 
 * @version 0.1
 * @date 2020-05-29
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once

#include <nodep2p/message/types.h>
#include <spotify/json.hpp>

using namespace spotify::json;

#ifndef SRC_MESSAGE_PEER_DISCONNECT_H_
#define SRC_MESSAGE_PEER_DISCONNECT_H_

namespace nodep2p
{
    namespace message
    {
        struct PeerDisconnect
        {
            static const MessageType type = TypePeerDisconnect;
            std::uint16_t port;
        };

        inline bool operator==(const PeerDisconnect &lhs, const PeerDisconnect &rhs)
        {
            return lhs.port == rhs.port;
        }
    } // namespace message
} // namespace nodep2p

namespace spotify
{
    namespace json
    {
        template <>
        struct default_codec_t<nodep2p::message::PeerDisconnect>
        {
            static codec::object_t<nodep2p::message::PeerDisconnect> codec()
            {
                auto codec = codec::object<nodep2p::message::PeerDisconnect>();
                codec.required("port", &nodep2p::message::PeerDisconnect::port);
                return codec;
            }
        }
    } // namespace json
} // namespace spotify

#endif /* SRC_MESSAGE_PEER_DISCONNECT_H_ */