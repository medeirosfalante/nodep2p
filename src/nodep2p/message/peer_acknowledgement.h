/**
 * @file peer_acknowledgement.h
 * @author  Rafael Medeiros
 * @brief 
 * @version 0.1
 * @date 2020-05-29
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once

#include <nodep2p/message/types.h>
#include <spotify/json.hpp>

using namespace spotify::json;

#ifndef SRC_MESSAGE_PEER_ACKNOWLEDGEMENT_H_
#define SRC_MESSAGE_PEER_ACKNOWLEDGEMENT_H_

namespace nodep2p
{
    namespace message
    {
        struct PeerAcknowledgement
        {
            static const MessageType type = TypePeerAcknowledgement;
        };
    }; // namespace message
} // namespace nodep2p

namespace spotify
{
    namespace json
    {
        template <>
        struct default_codec_t<nodep2p::message::PeerAcknowledgement>
        {
            static codec::object_t<nodep2p::message::PeerAcknowledgement> codec()
            {
                auto codec = codec::object<nodep2p::message::PeerAcknowledgement>();
                return codec;
            }
        }
    } // namespace json
} // namespace spotify
#endif /*SRC_MESSAGE_PEER_ACKNOWLEDGEMENT_H_ */