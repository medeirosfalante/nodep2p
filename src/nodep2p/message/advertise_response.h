/**
 * @file advertise_response.h
 * @author  Rafael Medeiros
 * @brief 
 * @version 0.1
 * @date 2020-05-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#pragma once

#include <spotify/json.hpp>
#include <nodep2p/message/types.h>

#ifndef SRC_MESSAGE_ADVERTISE_RESPONSE_H_
#define SRC_MESSAGE_ADVERTISE_RESPONSE_H_

namespace nodep2p
{
    namespace message
    {
        struct AdvertiseResponse
        {
            static const MessageType type = TypeAdvertiseResponse;
            std::string nonce;
        };
        inline bool operator==(const AdvertiseResponse &lhs, const AdvertiseResponse &rhs)
        {
            return lhs.nonce == rhs.nonce;
        }
    } // namespace message
} // namespace nodep2p

namespace spotify
{
    namespace json
    {
        template <>
        struct default_codec_t<nodep2p::message::AdvertiseResponse>
        {
            static codec::object_t<nodep2p::message::AdvertiseResponse> codec()
            {
                auto codec = codec::object<nodep2p::message::AdvertiseResponse>();
                codec.required("nonce", &nodep2p::message::Advertise::nonce);
                return codec;
            }
        }
    } // namespace json
} // namespace spotify

#endif /* SRC_MESSAGE_ADVERTISE_RESPONSE_H */