#ifndef LZ77_HPP
#define LZ77_HPP

#include <vector>
#include <string>
#include "lz77Code.cpp"

class lz77
{
    private:
        size_t compBuffer;
        size_t compDicionario;
        std::vector<lz77Code> codigos;
    public:
        lz77(size_t Nd, size_t Nb);
        void codifica(std::string entrada);
};

#endif /* LZ77_HPP */