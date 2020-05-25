/**
 * @file advertise_challenge.h
 * @author  Rafael Medeiros
 * @brief 
 * @version 0.1
 * @date 2020-05-24
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#pragma once

#include <spotify/json.hpp>
#include <nodep2p/message/types.h>
#ifndef SRC_MESSAGE_ADVERTISE_CHALLENGE_H_
#define SRC_MESSAGE_ADVERTISE_CHALLENGE_H_

namespace nodep2p
{
    namespace message
    {
        struct AdvertiseChallenge
        {
            static const MessageType type TypeAdvertiseChallenge;
            std::string encrypted_nonce;
        };
        inline bool operator==(const AdvertiseChallenge &lhs, const AdvertiseChallenge &rhs)
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
        struct default_codec_t<nodep2p::message::AdvertiseChallenge>
        {
            static codec::object_t<nodep2p::message::AdvertiseChallenge> codec()
            {
                auto codec = codec::object<nodep2p::message::AdvertiseChallenge>();
                codec.required("encrypted_nonce", &nodep2p::message::Advertise::encrypted_nonce);
                return codec;
            }
        }

    } // namespace json
} // namespace spotify

#endif /* SRC_MESSAGE_ADVERTISE_CHALLENGE_H_ */
