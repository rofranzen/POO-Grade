#include <iostream>

#include <vector>

using namespace std;




std::vector<int> retira(std::vector<int> v, int n)
{

    //bubble sort
    int size=v.size();
    for(int i=0;i<size - 1;++i){ //i++

       for (int j = 0; j < size - 1 - i; ++j){ //j++

          if (v[j] > v[j + 1])
          {
                    //troca el
                int temp = v[j]; //temp
                v[j] = v[j + 1];
                v[j + 1] = temp;
                //cout << v[j+1] << endl;
          }
        }
    }

    std::vector<int> result;

for (int i = 0; i < size; ++i) {
        bool found = false; //se nao igual n

        for (int j = 0; j < result.size(); ++j){
            if (result[j] == v[i]) {

                found = true;
                break;

              }
        }

        //entao se n for adiciona
        if (!found && v[i] != n)
            {
            result.push_back( v[i] );
        }
    }

    return result;
}
