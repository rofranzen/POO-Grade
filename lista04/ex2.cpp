#include <iostream>
#include <stack>
#include <queue>
#include <string>


std::string jogo(std::stack<int> cartas, std::queue<std::string> jogadores){
    //vec soma


    std::vector<int> soma;

    // noms
    std::vector<std::string> nomes;

    while ( !jogadores.empty()){ //Ate ficar vazio
        nomes.push_back( jogadores.front()   );
        soma.push_back(0);


        jogadores.pop(); //Tira um por um addicionado
    }

    int i = 0;

    while( !cartas.empty())


        {
        int carta = cartas.top();  //Pega topo
        cartas.pop(); //Remove uma

        soma[i]+= carta;
        i=(i +1)% nomes.size() ;
    }

    // Debug
    //std::cout << "Somas das cartas:" << std::endl; //weird stuff happening
    /*for (int i = 0; i < nomes.size(); i++) {

        std::cout << nomes[i]<< ": "<< soma[i] << std::endl;
    };*/

    // Ve venc e empate
    int vencedor_index = 0;

    int menor_soma = soma[0];

    for (int j = 1; j < nomes.size(); ++j)
    {
    if (soma[j] < menor_soma || (soma[j] == menor_soma && nomes[j]< nomes[vencedor_index]))
    {
        vencedor_index = j;
            menor_soma = soma[j];
        }
    }

    return nomes[vencedor_index]; //agr ta certo
};

