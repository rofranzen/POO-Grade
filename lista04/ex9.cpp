#include <iostream>
#include <vector>
#include <string>
std::vector<double> notas(const std::string& s)
{
    
  std::vector<double> result;
  std::string temp = "";
  
  
  bool isNota = false; //bool precisa e nao 1 ou 0 dnv
  
  for (char c : s){ //if
    if (c == ',' ){
       if(isNota) {
        result.push_back(std::stod(temp));
       }
      isNota = !isNota;
      temp = "";
    }
    else
    {
      temp = temp + c;
      //cout << "temp " << temp << endl;
    }
  }
  
  if (isNota == true) {
    result.push_back(  std::stod(temp));
  }
  
  return result;
}
