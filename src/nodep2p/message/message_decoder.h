/**
 * @file message_decoder.h
 * @author  Rafael Medeiros
 * @brief 
 * @version 0.1
 * @date 2020-05-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#pragma once


#include <spotify/json/decode.hpp>
#include <spotify/json/decode_exception.hpp>
#include <nodep2p/message/message_format.h>

#ifndef SRC_MESSAGE_DECODER_H
#define SRC_MESSAGE_DECODER_H

namespace nodep2p{
    namespace message{
        template <Class T>
        static message::MessageFormat<T> decode(const std::string &message){
            try{
                return spotify::json::decode<message::MessageFormat<T>>(message);
            } catch(const spotify::json:::decode_exception &e)
            {
                throw message::MessageException(
                    "Don't decode "+message_type_string
                )
            }
        }
    }
}


#endif /* SRC_MESSAGE_DECODER_H */


