/**
 * @file message_util.h
 * @author  Rafael Medeiros
 * @brief 
 * @version 0.1
 * @date 2020-05-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#pragma once

#ifndef SRC_MESSAGE_MESSAGE_UTIL_H_
#define SRC_MESSAGE_MESSAGE_UTIL_H_

namespace nodep2p
{
    namespace message
    {
        template <class T>
        inline void send_and_log(std::shared_ptr<Socket> socket,
                                 const Message<T> &message)
        {
            const auto json = encode(message.format());
        };
    } // namespace message
} // namespace nodep2p

#endif /* SRC_MESSAGE_MESSAGE_UTIL_H */