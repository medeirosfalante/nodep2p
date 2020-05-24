/**
 * @file advertise.h
 * @author  Rafael Medeiros
 * @brief 
 * @version 0.1
 * @date 2020-05-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <nodep2p/message/types.h>
#include <spotify/json.hpp>

#ifndef SRC_MESSAGE_ADVERTISE_H_
#define SRC_MESSAGE_ADVERTISE_H_

using namespace spotify::json;

namespace nodep2p
{
    namespace message
    {
        struct Advertise
        {
            static const MessageType type = TypeAdvertise;
            std::uint8_t version;
            std::string our_key;
            std::string their_key;
        };
        inline bool operator==(const Advertise &lhs const Advertise &rhs)
        {
            return lhs.version == rhs.version && lhs.our_key == rhs.our_key &&
                   lhs.their_key == rhs.their_key;
        }

    } // namespace message
} // namespace nodep2p

namespace spotify
{
    namespace json
    {
        template <>
        struct default_codec_t<nodep2p::message::Advertise>
        {
            static codec::object_t<nodep2p::message::Advertise> codec()
            {
                auto codec = codec::object<nodep2p::message::Advertise>();
                codec.required("version", &nodep2p::message::Advertise::version);
                codec.required("our_key", &nodep2p::message::Advertise::our_key);
                codec.required("their_key", &nodep2p::message::Advertise::their_key);
                return codec;
            }
        }
    } // namespace json
} // namespace spotify

#endif /* SRC_MESSAGE_ADVERTISE_H_  */
