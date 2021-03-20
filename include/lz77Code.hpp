#ifndef LZ77CODE_HPP
#define LZ77CODE_HPP

#include <iostream>
class lz77Code {
    private:
        size_t p, l;
        char c;
    public:
        lz77Code(size_t p, size_t l , char c);
        void setP(size_t p);
        void setL(size_t l);
        void setC(char c);
        size_t getP();
        size_t getL();
        char getC();
};

std::ostream& operator<<(std::ostream& out, lz77Code& code);

#endif /* LZ77CODE_HPP */