/**
 * @file pki.h
 * @author  Rafael Medeiros
 * @brief 
 * @version 0.1
 * @date 2020-05-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef SRC_CRYPTO_PKI_H_
#define SRC_CRYPTO_PKI_H_

namespace nodep2p
{
    namespace crypto
    {
        class PKI
        {
        public:
            virtual std::string public_encrypt(const std::string &message) const = 0;
            virtual std::string public_decrypt(const std::string &message) const = 0;
            virtual std::string private_encrypt(const std::string &message) const = 0;
            virtual std::string private_decrypt(const std::string &message) const = 0;
            virtual ~PKI();
            virtual std::string get_public_key_string() const = 0;
            virtual void write_to_file(const std::string &path) const = 0;
            virtual void write_to_file(const std::string &path, const std::string &password, const std::string &cipher) const = 0;
        };
    } // namespace crypto
} // namespace nodep2p

#endif /*