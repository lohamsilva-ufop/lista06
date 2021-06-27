#include <iostream>
#include <vector>

using namespace std;

vector <int> peso;
vector <int> valor;
int F[5][6];


void inicializaMatrizF(int linha, int coluna){
    for(int i=0; i<linha; i++){


            for (int j=0; j<coluna; j++){
                    if(i==0){
                        F[i][j] = 0;
                    } else if (j==0){
                        F[i][j] = 0;
                    } else {
                        F[i][j] = 1;
                    }
            }

    }


}

int MFKnapsack(int quantidade, int capacidade){
    int v;

    if(F[quantidade][capacidade] < 0){
            if (capacidade < peso[quantidade]){
                    v = MFKnapsack(quantidade-1, capacidade);

            } else {
                    v = max(MFKnapsack(quantidade-1, capacidade), valor[quantidade] + MFKnapsack(quantidade-1, capacidade - peso[quantidade]));

            }
            F[quantidade][capacidade] = v;

    }

    return F[quantidade][capacidade];

}

int main(){

    peso.push_back(2);
    peso.push_back(1);
    peso.push_back(3);
    peso.push_back(2);


    valor.push_back(12);
    valor.push_back(10);
    valor.push_back(20);
    valor.push_back(15);

    int capacidade = 5;
    int quantidade = peso.size();


    inicializaMatrizF(quantidade+1, capacidade+1);

    cout << "A maior quantidade de itens possui valor: " << MFKnapsack(quantidade+1, capacidade+1);

    return 0;
}
