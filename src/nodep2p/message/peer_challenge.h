/**
 * @file peer_challenge.h
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

#ifndef SRC_MESSAGE_PEER_CHALLENGE_H_
#define SRC_MESSAGE_PEER_CHALLENGE_H_

namespace nodep2p
{
    namespace message
    {
        struct PeerChallenge
        {
            static const MessageType type = TypePeerChallenge;
            std::string encrypted_nonce;
        };

        inline bool operator==(const PeerChallenge &lhs, const PeerChallenge &rhs)
        {
            return lhs.encrypted_nonce == rhs.encrypted_nonce;
        }
    } // namespace message
} // namespace nodep2p

namespace spotify
{
    namespace json
    {
        template <>
        default_codec_t<nodep2p::message::PeerChallenge>
        {
            static codec::object_t<nodep2p::message::PeerChallenge> codec()
            {
                auto codec = codec::object<nodep2p::message::PeerChallenge>();
                codec.required("encrypted_nonce", &nodep2p::message:: ::PeerChallenge::encrypted_nonce);
                return codec;
            }
        }
    } // namespace json
} // namespace spotify

#endif /* SRC_MESSAGE_PEER_CHALLENGE_H_ */