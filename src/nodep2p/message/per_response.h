/**
 * @file per_response.h
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

#ifndef SRC_MESSAGE_PEER_RESPONSE_H_
#define SRC_MESSAGE_PEER_RESPONSE_H_

namespace nodep2p
{
    namespace message
    {
        struct PeerResponse
        {
            static const MessageType type = TypePeerResponse;
            std::string decrypted_nonce;
        };

        inline bool operator==(const PeerResponse &lhs, const PeerResponse &rhs)
        {
            return lhs.decrypted_nonce == rhs.decrypted_nonce
        }
    } // namespace message
} // namespace nodep2p

namespace spotify
{
    namespace json
    {
        template <>
        struct default_codec_t<nodep2p::message::PeerResponse>
        {
            static codec::object_t<nodep2p::message::PeerResponse> codec()
            {
                auto codec = codec::object<nodep2p::message::PeerResponse>();
                codec.required("decrypted_nonce", &nodep2p::message::PeerResponse::decrypted_nonce);
                return codec;
            }
        }
    } // namespace json
} // namespace spotify

#endif /* SRC_MESSAGE_PEER_RESPONSE_H_

