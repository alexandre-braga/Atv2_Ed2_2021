#ifndef LZ77_HPP
#define LZ77_HPP

#include <vector>
#include <string>
#include "lz77Code.hpp"

class lz77
{
    private:
        size_t compBuffer;
        size_t compDicionario;
        std::vector<lz77Code> codigos;
    public:
        lz77(size_t Nd, size_t Nb);
        std::vector<lz77Code> getCodigos();
        size_t encontraMaior(std::string dicionario, std::string buffer, size_t& pos);
        void codifica(std::string entrada);
};

std::ostream& operator<<(std::ostream& out, lz77Code& code);

#endif /* LZ77_HPP */