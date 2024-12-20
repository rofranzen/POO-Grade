#include <iostream>
#include <stdio.h>
#include <fstream>

class Arquivo
{
    std::string _conteudo;
    int _p;
    int _tam;

public:
    Arquivo(std::string arquivo): _p(0){
        std::ifstream arq(arquivo);
        _tam = 1;

        std::string linha;
        while (std::getline(arq, linha)) {
            _conteudo += linha + "\n";  // Adiciona cada linha lida ao conteúdo
            _tam++;
        }

        arq.close();  // Fecha o arquivo

    };

    std::string proxima_linha(){

        if (_p > _tam) {
            _p = 0;
        };

        size_t inicio = _p;
        size_t fim = _conteudo.find('\n', inicio);  // Encontra a posição da próxima quebra de linha

        if (fim == std::string::npos) {  // Se não encontrar '\n', significa que é a última linha
            _p = _conteudo.size();  // Marca o fim
            return _conteudo.substr(inicio);  // Retorna a última linha
        } else {
            _p = fim + 1;  // Avança para a próxima linha
            return _conteudo.substr(inicio, fim - inicio);  // Retorna a linha
        }

        _p++;
    };

    ~Arquivo(){

    };
};
