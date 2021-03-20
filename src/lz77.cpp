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
    size_t ultimoMaior = 0;
    size_t posAtual = 0;
    size_t ultimoPosMaior = 0;
    size_t contador = 0;
    bool repeticao = false;

    std::cerr << "\ndicionarioInteiro: " << dicionario << " bufferInteiro: " << buffer << std::endl;
    //2 for é uma opção
    for (size_t i = 0, j = 0; i < this->compDicionario && j < this->compBuffer;){
        
        std::cerr << "dicionario: " << dicionario[i] << " buffer: " << buffer[j] << std::endl;
        
        //verificação normal
        posAtual = i;
        while(dicionario[i] == buffer[j]){
            maior++;
            if(repeticao == false){
                posAtual++;
                pos = posAtual - maior;
            }
            i++;
            j++;
            //repetição do dicionario pra l > p
            if(maior > 0 && dicionario[i] == '\0'){
                i = i - maior;
                repeticao = true;
            }
            
        }
        //std::cerr << "pos: " << pos << "posAtual: " << posAtual << " maior: " << maior << std::endl;
        i = contador;
        contador++;
        j = 0;
        if (maior > ultimoMaior){
            ultimoMaior = maior;
            ultimoPosMaior = pos;
        }
        maior = 0;
    }
    if(ultimoMaior >= maior){
        pos = ultimoPosMaior;
        return ultimoMaior;
    }
    else
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

        std::cerr << "\npAtual: " << pAtual << std::endl;
        if(maior != 0){
            pAtual = dicionario.size() - pAtual;
        }
        else
            pAtual = 0;
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


std::string lz77::decodifica(std::vector<lz77Code>& codigos)
{
	std::string decodificado;

	for (auto& code : codigos)
	{
		size_t p = decodificado.size() - code.getP();

		for(size_t i = 0; i < code.getL(); i++, p++) {
            decodificado.push_back(decodificado[p]);
        }

		if (code.getC() != '\0')
			decodificado.push_back(code.getC());
	}
	return decodificado;
}