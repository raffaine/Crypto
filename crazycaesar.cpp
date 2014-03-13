#include "crazycaesar.h"

#include <sstream>

CrazyCaesar::CrazyCaesar(int seed) :
    seed(seed),
    engine(seed)
{
}

CrazyCaesar::~CrazyCaesar() {

}

const int count = (int('z') - int('a'))+1;

char rightShift(char base, char c, int shift) {
    return base + (((c - base) + shift) % count);
}

char leftShift(char base, char c, int shift) {
    return base + (((c - base) + ((count - shift) % count)) % count);
}

std::string CrazyCaesar::Encrypt(const std::string& text) {
    std::ostringstream oss;
    std::uniform_int_distribution<int> udist(1, 5);

    const int start_u = int('A');
    const int start_l = int('a');

    engine.seed(seed);

    for(auto c : text) {
        if( c >= 'a' && c <= 'z' ) {
            oss << rightShift(start_l, c, udist(engine));
        } else if (c >= 'A' && c <= 'Z') {
            oss << rightShift(start_u, c, udist(engine));
        } else {
            oss << c;
        }
    }

    return oss.str();
}

std::string CrazyCaesar::Decrypt(const std::string& text) {
    std::ostringstream oss;
    std::uniform_int_distribution<int> udist(1, 5);

    const int start_u = int('A');
    const int start_l = int('a');

    engine.seed(seed);

    for(auto c : text) {
        if( c >= 'a' && c <= 'z' ) {
            oss << leftShift(start_l, c, udist(engine));
        } else if (c >= 'A' && c <= 'Z') {
            oss << leftShift(start_u, c, udist(engine));
        } else {
            oss << c;
        }
    }

    return oss.str();
}
