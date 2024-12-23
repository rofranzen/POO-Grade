#include <vector>
#include <iostream>

typedef std::vector<std::vector<int>> Matriz;

void ordena_par(Matriz& M) {
    int n = M.size();
    auto continha = []
            (const std::vector<int>& linha) -> int {
    int count = 0;

    for (int num:linha) { //automatic if
        if (num%2 == 0) { //não par
            ++count;
            //cout << count << endl;
        }
    }
    return count;
    };
    bool trocou; //codeblocks n deixou 1 ou 0
    do
    {
        trocou = false;
        for (int i = 0; i < n - 1; ++i) {
            int pares_a = continha(M[i]);
            int pares_b = continha(M[i + 1]);

            if (pares_a > pares_b || (pares_a == pares_b && M[i] > M[i + 1])) {
                std::swap(M[i], M[i + 1]); //troca
                trocou = true;
            }
        }

    }
    while (trocou);
}
