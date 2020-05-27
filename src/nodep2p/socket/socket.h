/**
 * @file socket.h
 * @author  Rafael Medeiros
 * @brief 
 * @version 0.1
 * @date 2020-05-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#pragma once
#include <iostream>
#include <netint/in.h>
#include <nodep2p/socket/socket_address.h>
#include <nodep2p/socket/socket_exception.h>
#ifndef SRC_SOCKET_SOCKET_H_
#define SRC_SOCKET_SOCKET_H_

namespace nodep2p
{
    namespace socket
    {
        const int RECV_BUFFER_SIZE = 1024;
    }
    class Socket
    {
    public:
        Socket(const socket::SocketAddress &socket_address);
        Socket(int socket_fd);
        ~Socket();
        virtual void send(const std::string &);
        virtual std::string receive();
        socket::SocketAddress get_socket_address();
        void close();

    private:
        Socket(const Socket &) = delete;

        void _connect();
        void _check_is_open();

        int _socket_fd;
        bool _is_open;
        struct socketaddr_in _address;
    };
} // namespace nodep2p

#endif /* SRC_SOCKET_SOCKET_H_ */