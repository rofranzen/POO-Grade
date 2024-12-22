#include <stack>
#include <iostream>

int elementok(std::stack<int>& pilha, int k) {
    std::stack<int> copia = pilha;
    int count = 0;

    while (!copia.empty()) {
        int topo = copia.top();
        copia.pop();

        if (topo % 2 == 0) {
            count++;
            if (count == k) {
                return topo;
            }
        }
    }

    return -1;
}
