/*
* types.h
*
*  Created on: 22 de mai de 2020
*      Author: Rafael Medeiros
*/

#pragma once

#include <cstdint>

#ifndef SRC_MESSAGE_TYPES_H_
#define SRC_MESSAGE_TYPES_H_

namespace nodep2p
{
	namespace message
	{

		using MessageType = std::uint8_t;
		static const MessageType TypeAdvertise = 0;
		static const MessageType TypeAdvertiseChallenge = 1;
		static const MessageType TypeAdvertiseResponse = 2;
		static const MessageType TypeAdvertiseAbort = 3;
		static const MessageType TypeAdvertiseRetry = 4;
		static const MessageType TypePeerDisconnect = 5;
		static const MessageType TypePeerIdentification = 6;
		static const MessageType TypePeerChallenge = 7;
		static const MessageType TypePeerChallengeResponse = 8;
		static const MessageType TypePeerResponse = 9;
		static const MessageType TypePeerAcknowledgement = 10;

		inline std::string type_to_string(MessageType type)
		{
			switch (type)
			{
			case TypeAdvertise:
				return "Advertise";
			case TypeAdvertiseChallenge:
				return "AdvertiseChallenge";
			case TypeAdvertiseResponse:
				return "AdvertiseResponse";
			case TypeAdvertiseAbort:
				return "AdvertiseAbort";
			case TypeAdvertiseRetry:
				return "AdvertiseRetry";
			case TypePeerDisconnect:
				return "PeerDisconnect";
			case TypePeerIdentification:
				return "PeerIdentification";
			case TypePeerChallenge:
				return "PeerChallenge";
			case TypePeerChallengeResponse:
				return "PeerChallengeResponse";
			case TypePeerResponse:
				return "PeerResponse";
			case TypePeerAcknowledgement:
				return "PeerAcknowledgement";
			default:
				return "Unkkown(" + std::to_string(type) + ")";
			}
		}

	} // namespace message
} // namespace nodep2p

#endif /* SRC_MESSAGE_TYPES_H_ */
