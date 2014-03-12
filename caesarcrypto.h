#ifndef CAESARCRYPTO_H
#define CAESARCRYPTO_H

#include "ICryptographer.h"
#include <unordered_map>

class CaesarCrypto : public ICryptographer
{
    std::unordered_map<char, char> translate_map;
    std::unordered_map<char, char> reverse_map;

public:
    CaesarCrypto(int shift);
    ~CaesarCrypto();

    std::string Encrypt(const std::string& text) override;
    std::string Decrypt(const std::string& text) override;
};

#endif // CAESARCRYPTO_H
