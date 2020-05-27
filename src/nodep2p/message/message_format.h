/**
 * @file message_format.h
 * @author  Rafael Medeiros
 * @brief 
 * @version 0.1
 * @date 2020-05-22
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once

#include <nodep2p/message/anonymous_message_format.h>
#include <nodep2p/message/types.h>
#include <nodep2p/version.h>
#include <spotify/json.hpp>
#ifndef SRC_MESSAGE_MESSAGE_FORMAT_H_
#define SRC_MESSAGE_MESSAGE_FORMAT_H_

namespace nodep2p
{
    namespace message
    {
        template <Class T>
        struct MessageFormat : AnonymousMessageFormat
        {
            message::MessageType type = T::type;
            T paylod;
        };

    } // namespace message

} // namespace nodep2p

namespace spotify
{
    namespace json
    {
        template <Class T>
        struct default_codec_t<nodep2p::message::MessageFormat<T>>
        {
            static codec::object_t<nodep2p::message::MessageFormat<T>> codec()
            {
                auto codec = codec::object<nodep2p::message::MessageFormat<T>>();
                codec.required("type", nodep2p::message::MessageFormat<T>::type);
                codec.required("paylod", nodep2p::message::MessageFormat<T>::paylod);
                return codec;
            }
        }
    } // namespace json
} // namespace spotify

#endif /* SRC_MESSAGE_MESSAGE_FORMAT */