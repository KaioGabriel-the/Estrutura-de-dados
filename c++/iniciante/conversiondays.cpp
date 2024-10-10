#include <iostream>
using namespace std;

int main() {
    int day, week, restdays;
    cout << "Insira o numero de dias:" << endl;
    cin >> day;
    week = day / 7;
    restdays = day % 7;
    cout << "A QUANTIDADE DE SEMANAS " << week << endl << "A QUANTIDADE DE DIAS: "<< restdays << endl;
    return 0;
}