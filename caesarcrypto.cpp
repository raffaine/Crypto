#include "caesarcrypto.h"

#include <sstream>

CaesarCrypto::CaesarCrypto(int shift) {
    for(int c = 0; c < 255; ++c) {
        translate_map[char(c)] = char(c);
        reverse_map[char(c)] = char(c);
    }

    const int count = (int('z') - int('a'))+1;

    const int start_l = int('a');
    int nc = (count + shift)%count;
    for(char c = 'a'; c <= 'z'; ++c) {
        translate_map[c] = char(start_l + (nc % count));
        reverse_map[translate_map[c]] = c;
        ++nc;
    }

    const int start_u = int('A');
    nc = (count + shift)%count;
    for(char c = 'A'; c <= 'Z'; ++c) {
        translate_map[c] = char(start_u + (nc % count));
        reverse_map[translate_map[c]] = c;
        ++nc;
    }
}

CaesarCrypto::~CaesarCrypto() {
}

std::string CaesarCrypto::Encrypt(const std::string& text) {
    std::ostringstream oss;

    for( auto c : text ) {
        oss << translate_map[c];
    }

    return oss.str();
}

std::string CaesarCrypto::Decrypt(const std::string& text) {
    std::ostringstream oss;

    for( auto c : text ) {
        oss << reverse_map[c];
    }

    return oss.str();
}
