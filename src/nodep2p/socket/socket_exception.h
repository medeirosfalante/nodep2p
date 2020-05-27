/**
 * @file socket_exception.h
 * @author  Rafael Medeiros
 * @brief 
 * @version 0.1
 * @date 2020-05-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once
#include <string>

#ifndef SRC_SOCKET_EXCEPTION_H_
#define SRC_SOCKET_EXCEPTION_H_

namespace nodep2p
{
    namespace socket
    {
        class SocketException : public std::exception
        {
        public:
            SocketException(const std::string &what) : _what(what) {}
            virtual const char *what() const noexcept override { return _what.c_str(); }

        private:
            std::string _what;
        }
    } // namespace socket
} // namespace nodep2p

#endif // SRC_SOCKET_EXCEPTION_H_ */