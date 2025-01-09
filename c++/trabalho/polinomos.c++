#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>

class Polinomo{

    public:
        float coefiente;
        int expoente;

        Polinomo(float coef, int exp){
            coefiente = coef;
            expoente = exp;
        };


    std::string toString(){
        std::ostringstream oss;
        oss << coefiente << "x^" << expoente;
        return oss.str();
    }
};

void exibir(std:: queue<Polinomo>& fila){
    std::queue<Polinomo> filaCop = fila;
    std::cout << "Polinômios ordenados (do maior expoente para o menor):" << std::endl;
    while (!filaCop.empty()) {
        std::cout << filaCop.front().toString() << std::endl;
        filaCop.pop();
    }
}
bool compararPolinomo(const Polinomo& p1, const Polinomo& p2) {
    return p1.expoente > p2.expoente;  // Ordem decrescente por expoente
}


// Função para ordenar os polinômios na fila
void ordenarPolinomo(std::queue<Polinomo>& fila) {
    std::vector<Polinomo> vetorPolinomios;

    // Transferindo os elementos da fila para o vetor
    while (!fila.empty()) {
        vetorPolinomios.push_back(fila.front());
        fila.pop();
    }

    // Ordenando o vetor pelo expoente
    std::sort(vetorPolinomios.begin(), vetorPolinomios.end(), compararPolinomo);

    // Transferindo os elementos de volta para a fila
    for (const auto& polinomo : vetorPolinomios) {
        fila.push(polinomo);
    }
}

void add(std:: queue<Polinomo>& fila, const Polinomo polinomo){
    if(polinomo.expoente >= 0){
        fila.push(polinomo);
        ordenarPolinomo(fila);
    }
}

int main(){
    float cof; int exp; float result;
    std:: queue <Polinomo> fila;
    Polinomo polinomo00(3,2);
    add(fila, polinomo00);
    Polinomo polinomo01(1,3);
    add(fila,polinomo01);
    exibir(fila);
    return 0;
}