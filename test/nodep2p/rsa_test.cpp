
#include <boost/test/unit_test.hpp>
#include <nodep2p/crypto/rsa.h>
#include <iostream>
#include <nodep2p/crypto/crypto_exception.h>

namespace nodep2p
{
    namespace test
    {
        namespace
        {
            const auto message = "bitcoin";
        }
        BOOST_AUTO_TEST_SUITE(rsa_test)
        BOOST_AUTO_TEST_CASE(ShouldEncryptPublicAndDecryptPrivate)
        {
            const auto key = crypto::RSA::generate();
            const auto encrypted_message = key->public_encrypt(message);
            BOOST_ASSERT(message != encrypted_message);
            const auto decrypted_message = key->private_decrypt(encrypted_message);
            BOOST_ASSERT(decrypted_message == message);
        }
        BOOST_AUTO_TEST_CASE(ShouldEncryptPrivateAndDecryptPublic)
        {
            const auto key = crypto::RSA::generate();
            const auto encrypted_message = key->private_encrypt(message);
            BOOST_ASSERT(message != encrypted_message);
            const auto decrypted_message = key->public_decrypt(encrypted_message);
            BOOST_ASSERT(decrypted_message == message);
        }
        BOOST_AUTO_TEST_CASE(ShouldNotEncryptPublicAndDecryptPublic)
        {
            const auto key = crypto::RSA::generate();
            const auto encrypted_message = key->public_encrypt(message);
            BOOST_ASSERT(message != encrypted_message);
            try
            {
                const auto decrypted_message = key->public_decrypt(encrypted_message);
                BOOST_FAIL("Should have thrown CryptoException");
            }
            catch (const crypto::CryptoException &e)
            {
            }
        }

        BOOST_AUTO_TEST_CASE(ShouldNotEncryptPrivateAndDecryptPrivate)
        {
            const auto key = crypto::RSA::generate();
            const auto encrypted_message = key->private_encrypt(message);
            BOOST_ASSERT(message != encrypted_message);
            try
            {
                const auto decrypted_message = key->private_decrypt(encrypted_message);
                BOOST_FAIL("Should have thrown CryptoException");
            }
            catch (const crypto::CryptoException &e)
            {
            }
        }

        BOOST_AUTO_TEST_CASE(ShouldEncryptMaxBytes)
        {
            const auto key = crypto::RSA::generate();
            const auto message =
                std::string(crypto::RSA::max_data_size(DefaultKeySize), 'z');
            const auto encrypted_message = key->public_encrypt(message);
            BOOST_ASSERT(message != encrypted_message);
            const auto decrypted_message = key->private_decrypt(encrypted_message);
            BOOST_ASSERT(decrypted_message == message);
        }

        BOOST_AUTO_TEST_CASE(ShouldSerialiseAndDeserialiseKey)
        {
            const auto key = crypto::RSA::generate();
            const auto key_str = key->get_public_key_string();
            const auto restored_key = crypto::RSA::from_public_key(key_str);
            const auto message_encrypted = key->public_encrypt(message);
            const auto message_encrypted_restored = restored_key->public_encrypt(message);
            const auto message_decrypted = key->private_decrypt(message_encrypted);
            const auto message_decrypted_restored =
                key->private_decrypt(message_encrypted_restored);
            BOOST_ASSERT(message == message_decrypted);
            BOOST_ASSERT(message_decrypted == message_decrypted_restored);
        }

        BOOST_AUTO_TEST_SUITE_END()

    } // namespace test
} // namespace nodep2p