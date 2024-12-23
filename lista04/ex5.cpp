#include <iostream>
#include <map>
#include <utility> //tlvz da p deleta

typedef std::map<std::pair<int, int>, int> Matriz;

Matriz soma( const Matriz& A, const Matriz& B) {

    Matriz matriziticha;
  //Ignora a chave
    for (const auto& elementoA :A) {
        if (elementoA.first != std::make_pair(-1, -1)){
            matriziticha[elementoA.first] +=elementoA.second;
        }

        //Odeio codeblocks concertar rro aq (result 2 a mais)
    }

    //Ignorar chave tb
    for (const auto& elementoB : B){


        if (elementoB.first!=std::make_pair(-1,-1))
        {
    matriziticha[elementoB.first]+= elementoB.second;
    }
    }

    if (A.find({-1, -1}) != A.end()) { //Add tam ao result
    matriziticha[{-1, -1}] = A.at({-1, -1});
    }

    else if (B.find({-1, -1}) != B.end() ) {
    matriziticha[ {-1, -1} ]= B.at({-1,-1});}

        //imprimirMatriz(matriziticha);
    return matriziticha;
}

//debug
/*
void imprimirMatriz(const Matriz& m) {
    for (const auto& elem :m) {
    std::cout << elem.first.first << " "<< elem.first.second << " " << elem.second << std::endl;
}
}*/
