#include <iostream>
#include <queue>
#include <string>
#include <cmath>

float resultP(float cof, int exp){
    float result;
    result = std:: pow(cof,exp);
    return result;
}

int main(){
    float cof; int exp; float result;
    std:: queue <float> fila;
    std:: cout << "Digite o coeficiente: " << std:: endl;
    std:: cin >> cof;
    std:: cout << "Digite o expoente: " << std:: endl;
    std:: cin >> exp;
    result = resultP(cof,exp);
    return 0;
}