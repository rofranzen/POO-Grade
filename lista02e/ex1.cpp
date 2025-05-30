#include <iostream>

class Televisao
{
  bool _ligada;
  int _canal;

public:
  Televisao(bool ligada = false, int canal = 1){
      _ligada = ligada;
      _canal = canal;
  };
  void liga(){
      _ligada = true;
  };
  void desliga(){
      _ligada = false;
  };
  void canal_cima(){
      //std::cout << "\nLast channel was: "<< _canal;
      _canal = (_canal % 100) + _ligada;
      //std::cout << "\n Next channel: " << _canal;
  };
  void canal_baixo(){
      _canal = (99 + _canal - 1*_ligada ) % 100 +1;
  };
  friend std::ostream& operator<<(std::ostream &out, const Televisao &tv){
      const char* estados[] = { "desligada", "ligada" };
      out << "(" << estados[tv._ligada] << ", " << tv._canal << ")";

      return out;
  };
};
