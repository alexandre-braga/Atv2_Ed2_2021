#include "../include/lz77.hpp"

lz77::lz77(size_t Nd, size_t Nb){
    this->compDicionario = Nd;
    this->compBuffer = Nb;
}

std::vector<lz77Code> lz77::getCodigos(){
    return this->codigos;
}

size_t lz77::encontraMaior(std::string dicionario, std::string buffer, size_t& pos){
    
    size_t maior = 0;

    for (size_t i = 0, j = 0; i < this->compDicionario && j < this->compBuffer;){
        if(buffer[j] == '\0'){
            return maior;
        }
        if(dicionario[i] == buffer[j]){
            maior++;
            pos++;
            i++;
            j++;
        }
        else{
            i++;
        }
    }
	return maior;

}

void lz77::codifica(std::string entrada){

	std::string buffer;
	std::string dicionario;

	size_t i = 0;

    //Enquanto houver símbolos a codificar
	while (i < entrada.length())
	{
        lz77Code novoCodigo(0,0,'\0');
        /*Inicializa-se o buffer (de dimensão Nb) com os primeiros
        Nb símbolos da sequência a codificar*/
        buffer = entrada.substr(i, this->compBuffer);

        //Inicialmente o dicionário não contém nenhum símbolo
		if (i <= this->compDicionario){
			dicionario = entrada.substr(0, i);
        }
        else{
            dicionario = entrada.substr(i - this->compDicionario, this->compDicionario);
        }
         
        //Identificar no dicionário a maior sequência de símbolos
        //que também esteja presente no buffer (a começar no
        //cursor)

        /*p é a posição relativa (a contar do cursor) da maior
        sequência do dicionário*/
        size_t pAtual = novoCodigo.getP();

        //l é o comprimento da maior sequência
        size_t maior = encontraMaior(dicionario, buffer, pAtual);

        //c é o símbolo do buffer que se segue à sequência
        char simbolo = entrada[i+maior];
        if(i + maior >= entrada.length()){
            simbolo = '\0';
        }

        novoCodigo.setP(pAtual);
        novoCodigo.setL(maior);
        novoCodigo.setC(simbolo);

		this->codigos.push_back(novoCodigo);
        
        //Deslocar as janelas (dicionário + buffer) de l+1 símbolos
		i += maior + 1;
	}

}