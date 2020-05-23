/**
 * @file public_key.h
 * @author  Rafael Medeiros
 * @brief 
 * @version 0.1
 * @date 2020-05-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once

#ifndef SRC_CRYPTOKEY_PUBLIC_KEY_H_
#define SRC_CRYPTOKEY_PUBLIC_KEY_H_

namespace nodep2p
{
    namespace cryptokey
    {
        class PublicKey
        {
        private:
            PublicKey(std::shared_ptr<crypto::PKI>);
            std::shared_ptr<crypto::PKI> _pki;

        public:
            static PublicKey string_from(const std::string &);
            static PublicKey gem();

            std::string encrypt(const std::string &) const;
            std::string serialize() const;
        };
    } // namespace cryptokey
} // namespace nodep2p

#endif /* SRC_CRYPTOKEY_PUBLIC_KEY_H */