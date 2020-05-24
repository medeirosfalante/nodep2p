/**
 * @file advertise_abort.h
 * @author  Rafael Medeiros
 * @brief 
 * @version 0.1
 * @date 2020-05-24
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <nodep2p/message/types.h>
#include <spotify/json.hpp>

using namespace spotify::json;

#ifndef SRC_MESSAGE_ADVERTISE_ABORT_H_
#define SRC_MESSAGE_ADVERTISE_ABORT_H_

namespace nodep2p
{

    namespace message
    {
        struct advertiseAbort
        {
            static const MessageType type = AdvertiseAbort;
            std::string reason;
        };
        inline bool operator==(const AdvertiseAbort &lhs, const AdvertiseAbort &rhs)
        {
            return lhs.reason == rhs.reason;
        }
    } // namespace message

} // namespace nodep2p

namespace spotify
{
    namespace json
    {
        template <>
        struct default_codec_t<nodep2p::message::advertiseAbort>
        {
            static codec::object_t<nodep2p::message::advertiseAbort> codec()
            {
                auto codec = codec::object<nodep2p::message::AdvertiseAbort>();
                codec.required("reason", &nodep2p::message::Advertise::reason);
                return codec;
            }
        }
    } // namespace json
} // namespace spotify

#endif /* SRC_MESSAGE_ADVERTISE_ABORT_H_ */
