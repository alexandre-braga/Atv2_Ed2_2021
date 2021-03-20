#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "include/lz77Code.hpp"
#include "include/lz77.hpp"

#define ERR_INVAL_ARGS 1
#define ERR_FALHA_ARQ  2

int main(int argc, char *argv[])
{
    const char *nomeDoPrograma = *argv;

    if (argc < 2)
    {
        std::cerr << nomeDoPrograma << ": nenhum arquivo fornecido\n";
        return ERR_INVAL_ARGS;
    }

    while (--argc){
        std::string nomeDoArquivo = *++argv;
        std::ifstream arquivo(nomeDoArquivo);
        
        if (!arquivo.is_open()) {
            std::cerr << nomeDoPrograma << ": falha ao abrir o arquivo: `" << nomeDoArquivo << "`\n";
            return ERR_FALHA_ARQ;
        }

        std::string Stringentrada;
        std::getline(arquivo, Stringentrada, (char) EOF);

        size_t Nb, Nd;
        std::cout << "Defina o comprimento do dicionario: ";
        std::cin >> Nd;
        std::cout << "Defina o comprimento do buffer: ";
        std::cin >> Nb;

        lz77 codificador(Nd, Nb);

        codificador.codifica(Stringentrada);

        std::ofstream saida("saida.txt");
        std::vector<lz77Code> codigos = codificador.getCodigos();
            
        for (size_t i = 0; i < codigos.size(); i++) {
            saida << codigos.at(i) << " ";
        }
        std::string stringOriginal = codificador.decodifica(codigos);
        std::cerr << "\nString Original: " << stringOriginal << std::endl;
        saida.close();
        arquivo.close();
    }
    return 0;
}