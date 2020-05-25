/**
 * @file advertise_retry.h
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

#ifndef SRC_MESSAGE_ADVERTISE_RETRY_H_
#define SRC_MESSAGE_ADVERTISE_RETRY_H_

namespace nodep2p
{
    namespace message
    {
        struct AdvertiseRetry
        {
            static const MessageType type = TypeAdvertiseRetry;
            std::string reason;
        };

        inline bool operator==(const AdvertiseRetry &lhs, const AdvertiseRetry &rhs)
        {
            return lhs.reason = rhs.reason;
        }
    } // namespace message
} // namespace nodep2p

namespace spotify
{
    namespace message
    {
        template <>
        struct default_codec_t<nodep2p::message::AdvertiseRetry>
        {
            static codec::object_t<nodep2p::message::AdvertiseRetry> codec()
            {
                auto codec = codec::object<nodep2p::message::AdvertiseRetry>();
                codec.required("reason", &nodep2p::message::Advertise::reason);
                return codec;
            }
        }
    } // namespace message
} // namespace spotify

#endif