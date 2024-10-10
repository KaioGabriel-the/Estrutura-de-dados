#include <iostream>
using namespace std;

int main() {
    int centena, dezena, unidade, numero, invertido;
    cout << "Digite um número de três digitos: " << endl;
    cin >> numero;

    centena = numero / 100;
    dezena = (numero % 100)/10;
    unidade = (numero % 100) % 10;
    invertido = unidade * 100 + dezena * 10 + centena;
    cout << "O número invertido é " << invertido << endl;
    return 0;
}