#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack <int> pilhas;
    pilhas.push(1);
    pilhas.push(2);
    printf("%d",pilhas.top());
    pilhas.pop();
    printf("%d",pilhas.top());
    pilhas.pop();
    printf("",pilhas.empty());

    return 0;
}