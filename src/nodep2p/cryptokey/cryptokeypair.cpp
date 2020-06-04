/**
 * @file cryptokeypair.cpp
 * @author  Rafael Medeiros
 * @brief 
 * @version 0.1
 * @date 2020-06-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <nodep2p/crypto/rsa.h>
#include <nodep2p/cryptokey/cryptokeypair.h>

namespace nodep2p
{
    namespace cryptokey
    {
        CryptoKeyPair CryptoKeyPair::generate()
        {
            return CryptoKeyPair(nodep2p::crypto::RSA::generate());
        }
        CryptoKeyPair CryptoKeyPair::from_pem(const std::string &path)
        {
            return CryptoKeyPair(nodep2p::crypto::RSA::from_pem(path));
        }
        CryptoKeyPair::CryptoKeyPair(std::shared_ptr<nodep2p::crypto::PKI> pki) : _pki(pki) {}

        std::string CryptoKeyPair::public_encrypt(const std::string &message) const
        {
            return _pki->public_encrypt(message);
        }
        std::string CryptoKeyPair::private_decrypt(const std::string &encrypted) const
        {
            return _pki->private_decrypt(encrypted);
        }
        std::string CryptoKeyPair::get_serialised_public_key() const
        {
            return _pki->get_public_key_string();
        }

    } // namespace cryptokey

} // namespace nodep2p