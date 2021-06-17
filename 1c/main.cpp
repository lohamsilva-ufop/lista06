#include <iostream>
#include <vector>
/*
Autor: Loham Santos da Silva
A sequencia Fibonnaci uma sequencia de números inteiros, começando normalmente por 0 e 1.
Cada termo subsequente (número de Fibonacci) corresponde a soma dos dois anteriores.
A sequência é definida pela fórmula abaixo:

Se n=0, retorna 0
Se n= 1, retorna 1;
Se n >1, calcula f(n-1) + f(n+1)

Utilizando programação dinâmica, deve-se armazenar um vetor com o valor dos subproblemas ja calculado.
*/

using namespace std;

//o vetor deve ser inicializado pois se n=1 e n =2, valor = 1.
void inicializaVetor(vector <int> &vet, int n){
    vet.push_back(0);
    vet.push_back(1);
    vet.push_back(1);

    for(int i=3; i<=n; i++){
        vet.push_back(-1);
    }
}


//ao chamar a funcao:
int fibonacci(int n, vector <int> &vet){
    //verifica se na posição enviada, o valor é -1: ou seja, não foi calculado
    if(vet[n] == -1){
        vet[n] = fibonacci(n-1, vet) + fibonacci(n-2, vet); //se nao for, chama recursivamente e encontra o valor.
    } else{
        return vet[n]; //se for diferente de zero, retorna o valor do subproblema para que ele nao seja calculado de novo.
    }
}


int main(){
    int numero;
    vector<int> vetor;

    cout << "Entre com um numero: ";
    cin >> numero;


    inicializaVetor(vetor, numero);

    cout << "O n-esimo termo fibonacci para " << numero << " e: " << fibonacci(numero, vetor);

    return 0;
}
