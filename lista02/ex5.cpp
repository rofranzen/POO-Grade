#include <iostream>
#include <fstream>
#include <string>

class Arquivo
{
    std::string _conteudo;

public:

    Arquivo(std::string arquivo) {
        std::ifstream arq(arquivo);
        if (arq.is_open()) {
            std::string linha;
            while (std::getline(arq, linha)) {
                _conteudo += linha + "\n";
            }
            arq.close();
        } else {
            std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        }
    }
    std::string proxima_linha() {
        static size_t pos = 0;

        if (pos >= _conteudo.size()) {
            return "";
        }

        size_t inicio = pos;
        size_t fim = _conteudo.find('\n', inicio);

        if (fim == std::string::npos) {
            pos = _conteudo.size();
            return _conteudo.substr(inicio);
        } else {
            pos = fim + 1;
            return _conteudo.substr(inicio, fim - inicio);
        }
    }
    ~Arquivo() {
    }
};
