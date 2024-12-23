#include <iostream>
#include <string>
#include <sstream>

class Pessoa {
private:

    std::string nome;
    int idade;
    std::string cidade;
    std::string uf;
    std::string pais;

public:
        Pessoa(const std::string& dados){
             size_t pos_tem = dados.find(" tem "); //P poder noem composto
             nome = dados.substr(0, pos_tem);


             size_t pos_idade = pos_tem + 5; //pula lixo
             size_t pos_anos = dados.find(" anos", pos_idade);
             idade = std::stoi(dados.substr(pos_idade, pos_anos - pos_idade));


             size_t pos_mora = dados.find(" e mora em ") + 11; //11 tb pula lixo
             size_t pos_uf = dados.find("-", pos_mora);
             cidade = dados.substr(pos_mora, pos_uf - pos_mora);
             pos_uf += 1; // lixo
             size_t pos_pais = dados.find(", ", pos_uf);
             uf = dados.substr(pos_uf, pos_pais - pos_uf);
             pos_pais += 2; //pual lixo
            pais = dados.substr(pos_pais);
         }

        friend std::ostream& operator<<(std::ostream& os, const Pessoa& p){
            os << p.nome << "\n" << p.idade
             << "\n" << p.cidade << "\n" << p.uf << "\n" << p.pais;
            return os; }



};

