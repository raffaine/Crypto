#ifndef ICRYPTOGRAPHER_H
#define ICRYPTOGRAPHER_H

#include <string>

class ICryptographer {
public:
    virtual ~ICryptographer() {}

    virtual std::string Encrypt(const std::string& text) = 0;
    virtual std::string Decrypt(const std::string& text) = 0;
};

#endif // ICRYPTOGRAPHER_H
