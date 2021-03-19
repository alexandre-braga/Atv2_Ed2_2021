/*Inicializa-se o buffer (de dimensão Nb) com os primeiros
Nb símbolos da sequência a codificar
• Inicialmente o dicionário não contém nenhum símbolo
• Enquanto houver símbolos a codificar
– Identificar no dicionário a maior sequência de símbolos
que também esteja presente no buffer (a começar no
cursor)
– Associar à sequência o código (p, l, c) onde
• p é a posição relativa (a contar do cursor) da maior sequência do
dicionário
• l é o comprimento da maior sequência
• c é o símbolo do buffer que se segue à sequência
– Deslocar as janelas (dicionário + buffer) de l+1 símbolos
*/