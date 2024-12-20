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
            _conteudo += linha + "\n";  // Adiciona cada linha lida ao conte�do
            _tam++;
        }

        arq.close();  // Fecha o arquivo

    };

    std::string proxima_linha(){

        if (_p > _tam) {
            _p = 0;
        };

        size_t inicio = _p;
        size_t fim = _conteudo.find('\n', inicio);  // Encontra a posi��o da pr�xima quebra de linha

        if (fim == std::string::npos) {  // Se n�o encontrar '\n', significa que � a �ltima linha
            _p = _conteudo.size();  // Marca o fim
            return _conteudo.substr(inicio);  // Retorna a �ltima linha
        } else {
            _p = fim + 1;  // Avan�a para a pr�xima linha
            return _conteudo.substr(inicio, fim - inicio);  // Retorna a linha
        }

        _p++;
    };

    ~Arquivo(){

    };
};
