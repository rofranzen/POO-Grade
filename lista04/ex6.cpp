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
                int temp = v[j] * (v[j] > v[j + 1]) + v[j + 1] * (v[j] <= v[j + 1]);
                v[j + 1] = v[j] * (v[j] <= v[j + 1]) + v[j + 1] * (v[j] > v[j + 1]);
                v[j] = temp; 
                //cout << v[j+1] << endl;
          }
        }
    }

    std::vector<int> result;
    
   for (int i = 0; i < size; ++i) //i++
    {
        bool is_in_result=false; // sem if dessa vez
   
        for (int j = 0; j < result.size(); ++j){ //j++
                
            is_in_result = is_in_result || (result[j] == v[i]);
        }

        result.insert(result.end(),
                      (is_in_result || v[i] == n) ? 0 :
                      1, v[i]);
    }

    return result;
}
