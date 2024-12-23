#include <iostream>
#include <vector>
#include <string>

void ordena_strings(std::vector<std::string>& vetor){
    
    int n = vetor.size();

    //bubble sort
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) { //Precisa do -1 ou buga
            //Compara les tamanhos
            if (vetor[j].size() > vetor[j + 1].size())
                {
            std::swap(vetor[j], vetor[j + 1]);
            }
            
            //desempate
            else if (vetor[j].size() == vetor[j + 1].size() && vetor[j] < vetor[j + 1]) {
                    
                    
                std::swap(vetor[j], vetor[j + 1]);
        }
        }
    }
}
