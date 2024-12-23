#include <iostream>

using namespace std;

#include <string>

std::string retira(std::string texto, char c) {
    // Cria uma nova string para armazenar o resultado
    std::string resultado;

    // Itera pela string e copia o pedido
    for (char caractere:texto) {
        if(caractere != c){
            resultado+=caractere;
            
        }
    }
    return resultado;
}
