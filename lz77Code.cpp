#include "include/lz77Code.hpp"

lz77Code::lz77Code(size_t p, size_t l, char c)
{
    this->p = p;
    this->l = l;
    this->c = c;
}

/*– Associar à sequência o código (p, l, c) onde
• p é a posição relativa (a contar do cursor) da maior sequência do
dicionário
• l é o comprimento da maior sequência
• c é o símbolo do buffer que se segue à sequência
*/