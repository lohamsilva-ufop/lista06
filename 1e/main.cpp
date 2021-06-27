#include <iostream>
#include <vector>

/*
Nome: Loham Santos da Silva = PCC104 UFOP
O algoritmo foi criado com base na bibliografia utilizada na disciplina
Coletor de moedas - Coins collection.

Calcular o maior número de moedas que um robô pode coletar em um tabuleiro n × m
começando em (1, 1) e movendo para a direita e para baixo do canto superior esquerdo para o canto direito inferior
*/

using namespace std;

void inicializaVetor(vector<vector <int>> &moedas, int linha, int coluna){
    for(int i=0; i<linha; i++){
            vector<int> m;
        for(int j=0; j<coluna; j++){
            m.push_back(0);
        }
        moedas.push_back(m);
    }
}

int coinCollection(vector<vector <int>> &moedas, int linha, int coluna){
    //cria a matriz que irá computar a coleção de moedas
    vector<vector <int>> F;

    //inicializa a matriz F com os valores da matriz de moedas
    F = moedas;

    for(int j=1; j<coluna; j++){
        F[1][j] = F[1][j-1]+ moedas[1][j];
    }


    for(int i=1; i<linha; i++){
        F[i][1] = F[i-1][1]+ moedas[i][1];
            for(int j=1; j<coluna; j++){
                F[i][j] = max(F[i-1][j],F[i][j-1])+ moedas[i][j];
            }
    }

    return F[linha-1][coluna-1];
}


int main(){
    //cria a matriz onde conterá o grid com as moedas
    vector<vector <int>> moedas;

    //chama a função que inicializa o grid com 0
    inicializaVetor(moedas, 5, 6);

    //insere em determinadas posições as moedas
    moedas[0][4] = 1;
    moedas[1][1] = 1;
    moedas[1][3] = 1;
    moedas[2][3] = 1;
    moedas[2][5] = 1;
    moedas[3][2] = 1;
    moedas[3][5] = 1;
    moedas[4][0] = 1;
    moedas[4][4] = 1;

    //chama a função que fará a coleta de moedas
    cout << "A maior quantidade de moedas coletadas foi: "<< coinCollection(moedas, 5, 6);

    return 0;
}
