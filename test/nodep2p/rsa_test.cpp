
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
        BOOST_AUTO_TEST_SUITE_END()

    } // namespace test
} // namespace nodep2p