/**
 * @file peer_identification.h
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

#ifndef SRC_MESSAGE_PEER_IDENTIFICATION_H_
#define SRC_MESSAGE_PEER_IDENTIFICATION_H_

namespace nodep2p
{
    namespace message
    {
        struct PeerIdentification
        {
            static const MessageType type = TypePeerIdentification;
            std::uint8_t version;
            std::string ip;
            string::uint16_t port;
        };

        inline bool operator==(const PeerIdentification &lhs, const PeerIdentification &rhs)
        {
            return lhs.version == rhs.version && lhs.ip == rhs.ip && lhs.port == rhs.port;
        }
    } // namespace message
} // namespace nodep2p

namespace spotify
{
    namespace json
    {
        template <>
        struct default_codec_t<nodep2p::message::PeerIdentification>
        {
            static codec::object_t<nodep2p::message::PeerIdentification> codec()
            {
                auto codec = codec::object<nodep2p::message::PeerIdentification>();
                codec.required("version", &nodep2p::message::PeerIdentification::version);
                codec.required("ip", &nodep2p::message::PeerIdentification::ip);
                codec.required("port", &nodep2p::message::PeerIdentification::port);
                return codec;
            }
        }
    } // namespace json
} // namespace spotify

#endif /* SRC_MESSAGE_PEER_IDENTIFICATION_H_ */