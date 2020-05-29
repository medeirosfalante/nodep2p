/**
 * @file crypto_exception.h
 * @author  Rafael Medeiros
 * @brief 
 * @version 0.1
 * @date 2020-05-29
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <string>

#ifndef SRC_CRYPTO_EXCEPTION_H_
#define SRC_CRYPTO_EXCEPTION_H_

class CryptoException : public std::exception
{
public:
    CryptoException(const std::string &what) : _what(what) {}
    virtual const char *what() const noexcept override { return _what.c_str(); }

private:
    std::string _what;
}

#endif /*SRC_CRYPTO_EXCEPTION_H_ */
