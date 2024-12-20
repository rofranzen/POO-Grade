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
      if (_ligada){
        _canal++;
      }
  };
  void canal_baixo(){
      if (_ligada){
        _canal--;
      }
  };
  friend std::ostream& operator<<(std::ostream &out, const Televisao &tv){
      out << "(" << (tv._ligada ? "ligada" : "desligada") << ", " << tv._canal << ")";
      return out;
  };
};
