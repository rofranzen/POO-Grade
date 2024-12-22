#include <iostream>
#include <fstream>
#include <string>

class Arquivo {
    std::string _conteudo;

public:
    Arquivo(const std::string& arquivo) {
        std::ifstream arq(arquivo);
        if (arq.is_open()) {
            std::string linha;
            while (std::getline(arq, linha)) {
                _conteudo += linha + "\n";
            }
            arq.close();
        }
    }

    std::string proxima_linha(size_t& pos) const{
        if (pos >= _conteudo.size()){
            return "";
        }
        size_t inicio = pos;
        size_t fim = _conteudo.find('\n', inicio);

        if(fim == std::string::npos) {
            pos = _conteudo.size();
            return _conteudo.substr(inicio);
        }
        else{
            pos = fim + 1;
            return _conteudo.substr(inicio, fim - inicio);
        }
    }

class Iterator {
    const Arquivo& _arquivo;
    size_t _pos;

public:
    Iterator(const Arquivo& arquivo, size_t pos) : _arquivo(arquivo), _pos(pos) {}

    bool operator!=(const Iterator& other) const{
        return _pos != other._pos;
    }

    std::string operator*() {
        return _arquivo.proxima_linha(_pos);

    }

    Iterator& operator++(){

        return *this;
    }
};

Iterator end() const{
    return Iterator(*this, _conteudo.size());
}

Iterator begin() const{
    return Iterator(*this, 0);
}
};
