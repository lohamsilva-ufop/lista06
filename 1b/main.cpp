#include <iostream>
/*
Autor: Loham Santos da Silva
A sequencia Fibonnaci uma sequencia de números inteiros, começando normalmente por 0 e 1.
Cada termo subsequente (número de Fibonacci) corresponde a soma dos dois anteriores.
A sequência é definida pela fórmula abaixo:

Se n=0, retorna 0
Se n= 1, retorna 1;
Se n >1, calcula f(n-1) + f(n+1)
*/

using namespace std;

int fibonacci(int n){

    if(n<=0){
        return 0;
    } else if(n == 1){
        return 1;
    } else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main()
{
    int numero;

    cout << "Entre com um numero: ";
    cin >> numero;
    cout << "O n-esimo termo fibonacci para " << numero << " e: " << fibonacci(numero);
}
