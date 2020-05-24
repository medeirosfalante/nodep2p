/*
* anonymous_message_format.h
*
*  Created on: 22 de mai de 2020
*      Author: Rafael Medeiros
*/

#pragma once

#include <cstdint>
#include <nodep2p/message/types.h>
#include <spotify/json.hpp>

#ifndef SRC_MESSAGE_ANONYMOUS_MESSAGE_FORMAT_H_
#define SRC_MESSAGE_ANONYMOUS_MESSAGE_FORMAT_H_

namespace nodep2p
{
    namespace message
    {
        struct AnonymousMessageFormat
        {
            message:: : MesageType type;
        }

    } // namespace message
    
} // namespace nodep2p

namespace spotify
{
    namespace json
    {
        template <>
        struct default_codec_t<nodep2p::message::AnonymousMessageFormat>
        {
            static codec::object_t<nodep2p::message::AnonymousMessageFormat> codec()
            {
                auto codec = codec::object<nodep2p::message::AnonymousMessageFormat>()
                {
                    codec.required("type", &nodep2p::message::AnonymousMessageFormat::type);
                    return codec;
                }
            }
        }
    } // namespace json
} // namespace spotify

#endif /* SRC_MESSAGE_ANONYMOUS_MESSAGE_FORMAT_H_ */
