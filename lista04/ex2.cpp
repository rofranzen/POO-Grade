#include <iostream>
#include <stack>
#include <queue>
#include <string>

std::string jogo(std::stack<int> cartas, std::queue<std::string> jogadores){

    int soma[3] = {0,0,0};
    std::string nomes[3];
    for (int i = 0; i < 3; i++) {
        nomes[i] = jogadores.front();
        jogadores.pop();
        //cout << "chegouu";
    };

    int i =0;
    while(!cartas.empty() ){
        int carta = cartas.top();
        cartas.pop();

        soma[i] += carta;
        i = (i + 1) % 3;
    }

    int vencedor_index = 0;
    int menor_soma = soma[0];
    //cout << "soma[0]" << soma[0];



    for (int j = 1; j < 3; ++j){
        if (soma[j] < menor_soma || (soma[j]==menor_soma && nomes[j]<nomes[vencedor_index])) {
            vencedor_index = j;
            menor_soma = soma[j];
            
        }
    }

    return nomes[vencedor_index]; //return deu
}
