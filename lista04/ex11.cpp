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
    Pessoa(const std::string& dados) {

        std::istringstream stream(dados); //dados fornecidos
        std::string temp;

        //pega tb nome compost
        std::getline(stream, nome, ' '); 
        while (stream >> temp && temp != "tem") {
            nome += " " + temp;  //faz append do resto dps d aprimeira
        }

        //get age
        stream >> idade;
        //std::cout << "temp is "<<idade;

        //pula anos
        stream >> temp;
        //;;std::cout << "temp is "<< temp;

        //pula lixo
        stream >> temp >> temp >> temp;

        std::getline(stream, temp, ' '); //pula espaco
        std::getline(stream, cidade, '-');
        //stream >> temp;
        std::getline(stream, uf, ',');
        std::getline(stream, temp, ' '); //pula espaco
        std::getline(stream, pais);         // The rest is the country
    }

    friend std::ostream& operator<<(std::ostream& os, const Pessoa& p) {
        os << p.nome << "\n" << p.idade << "\n"
           << p.cidade << "\n" << p.uf << "\n" << p.pais;
        return os;
    }
};
