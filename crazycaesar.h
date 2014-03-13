#ifndef CRAZYCAESAR_H
#define CRAZYCAESAR_H

#include "ICryptographer.h"
#include <random>

class CrazyCaesar : public ICryptographer
{
    int seed;

    std::default_random_engine engine;

public:
    CrazyCaesar(int seed);
    ~CrazyCaesar();

    std::string Encrypt(const std::string& text) override;
    std::string Decrypt(const std::string& text) override;
};

#endif // CRAZYCAESAR_H
