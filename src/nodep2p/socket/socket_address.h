/**
 * @file socket_address.h
 * @author  Rafael Medeiros
 * @brief 
 * @version 0.1
 * @date 2020-05-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#pragma once
#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>

#ifndef SRC_SOCKET_ADDRESS_H_
#define SRC_SOCKET_ADDRESS_H_

namespace nodep2p
{
    namespace socket
    {
        class SocketAddress
        {
        public:
            SocketAddress(const std::string &ip, std::uint16_t port) : _ip(ip), _port(port) {}
            std::string ip() const { return _ip; }
            std::uint16_t port() const { return _port; }
            bool operator==(const SocketAddress &other)
            {
                return this->port() == other.port() && this->ip() == other.ip();
            }

        private:
            std::string _ip;
            std::uint16_t _port;
            friend std::ostream &operator<<(std::ostream &os, const SocketAddress &address)
            {
                os << address.ip() << ":" << address.port();
                return os;
            }
            friend bool operator==(const SocketAddress &address1, const SocketAddress &address2)
            {
                return address1.ip() == address2.ip() && address1.port() == address2.port();
            }
        }
    } // namespace socket
} // namespace nodep2p

namespace std
{
    template <>
    struct hash<nodep2p::socket::SocketAddress>
    {
        size_t operator()(const nodep2p::socket::SocketAddress &address) const
        {
            std::stringstream s;
            s << address;
            return hash<std::string>()(s.str());
        }
    }
} // namespace std

#endif /* SRC_SOCKET_ADDRESS_H_
