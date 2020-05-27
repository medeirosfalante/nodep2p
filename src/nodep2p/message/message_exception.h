/**
 * @file message_exception.h
 * @author  Rafael Medeiros
 * @brief 
 * @version 0.1
 * @date 2020-05-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once

#include <nodep2p/message/anonymous_message_format.h>
#include <nodep2p/message/types.h>
#include <nodep2p/version.h>
#include <spotify/json.hpp>
#ifndef SRC_MESSAGE_MESSAGE_EXCEPTION_H_
#define SRC_MESSAGE_MESSAGE_EXCEPTION_H_

namespace nodep2p
{
    namespace message
    {
        class MessageException : public std::exception
        {
        public:
            MessageException(const std::string &what) {}
            virtual const char *what() const noexcept override { return _what.c_str(); }

        private:
            std::string _what;
        };
    } // namespace message

} // namespace nodep2p

#endif /* SRC_MESSAGE_MESSAGE_FORM