/**
 * @file base64.h
 * @author  Rafael Medeiros
 * @brief 
 * @version 0.1
 * @date 2020-06-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef BASE64_H_C0CE2A47_D10E_42C9_A27C_C883944E704A
#define BASE64_H_C0CE2A47_D10E_42C9_A27C_C883944E704A

#include <string>

std::string base64_encode(unsigned char const *, unsigned int len);
std::string base64_decode(std::string const &s);

#endif /* BASE64_H_C0CE2A47_D10E_42C9_A27C_C883944E704A */