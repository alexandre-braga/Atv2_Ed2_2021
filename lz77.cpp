/*Inicializa-se o buffer (de dimensão Nb) com os primeiros
Nb símbolos da sequência a codificar
• Inicialmente o dicionário não contém nenhum símbolo
• Enquanto houver símbolos a codificar
– Identificar no dicionário a maior sequência de símbolos
que também esteja presente no buffer (a começar no
cursor)
– Deslocar as janelas (dicionário + buffer) de l+1 símbolos
*/

#include "include/lz77.hpp"

lz77::lz77(size_t Nd, size_t Nb){
    this->compDicionario = Nd;
    this->compBuffer = Nb;
}

void lz77::codifica(std::string entrada){

}