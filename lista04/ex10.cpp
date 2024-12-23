#include <iostream>
#include <vector>
#include <string>

void ordena_versoes(std::vector<std::string>& versoes) {

    auto comparar=[]
            (const std::string& v1, const std::string& v2) {
        size_t i = 0;

        size_t j = 0;
        while (i < v1.size() || j < v2.size()  ){

            int num1 = 0, num2 = 0;

            while (i < v1.size() && v1[i] != '.')
            {
                num1 = num1*10 + (v1[i] - '0'); //works better with chracter
                //cout << num
                i++;

            }
            while (j < v2.size() && v2[j] != '.') { // != ','
                num2 = num2*10 + (v2[j] - '0');

                j++;
            }
            if (num1 < num2)
              return true;
            if (num1 > num2)
                return false;
            i++;j++; //Pular o ponto
        }
        return false;
    };

    for(size_t i = 0; i < versoes.size(); ++i)
        { //bubble sort. ++i ta melhor nessa lista
        for(size_t j = 0; j < versoes.size() - 1 - i; ++j)
        {
          if ( comparar(versoes[j+1], versoes[j]))
          {
            std::swap(versoes[j],versoes[j+1]);
          }
        }
    }
}
