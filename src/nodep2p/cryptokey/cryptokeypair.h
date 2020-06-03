/**
 * @file cryptokeypair.h
 * @author  Rafael Medeiros
 * @brief 
 * @version 0.1
 * @date 2020-05-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once

#include <nodep2p/crypto/pki.h>

#ifndef SRC_CRYPTOKEY_CRYPTO_KEY_PAIR_H_
#define SRC_CRYPTOKEY_CRYPTO_KEY_PAIR_H_

namespace nodep2p
{
    namespace cryptokey
    {
        class CryptoKeyPair
        {
        public:
            static CryptoKeyPair generate();
            static CryptoKeyPair from_pem(const std::string &path);

            std::string public_encrypt(const std::string &message) const;
            std::string private_decrypt(const std::string &message) const;
            std::string get_serialised_public_key() const;

        private:
            CryptoKeyPair(std::shared_ptr<crypto::PKI>);

            std::shared_ptr<crypto::PKI> _pki;
        };

    } // namespace cryptokey
} // namespace nodep2p

#endif /* SRC_CRYPTOKEY_CRYPTO_KEY_PAIR_H_ */