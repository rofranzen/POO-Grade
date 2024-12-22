#include <stack>
#include <iostream>
//#include <math.h> //n precisa n

int elementok(std::stack<int>& pilha, int k) {
    std::stack<int> copia =pilha;
    //Essa pilha esta okays
    int count;
    //Sep pq tava bugando no codeblocks não tirar
    
    count = 0;

    while (!copia.empty()  ) {
        int topo = copia.top();
        copia.pop();

        if (topo % 2 == 0) {
            count++;
            if (count == k) {
                return topo;

        }
        }
    }

    return -1; //tlvz antes n vi resultad
}
