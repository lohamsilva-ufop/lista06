#include <iostream>
#include <vector>

using namespace std;

int rainha_fixa = 0;


void imprimeCandidatos(vector<int> &solucao_parcial){
    for(int i=0; i<solucao_parcial.size(); i++){
        cout << solucao_parcial[i] << ",";
    }
}

int encontrarCandidatos(int rainhas, vector<int> &solucao_parcial, int linha_pesquisada){
    for (int coluna_candidata=0; coluna_candidata<rainhas; coluna_candidata++){
            for (int linha=0; linha<linha_pesquisada; linha++){
                // a rainha deve verificar se alguem esta na mesma coluna com ela,
                 //na mesma linha a[i] == c
                if(solucao_parcial[linha] == linha_pesquisada){


                // diagonal a[i] - c == (i - candidato)
                } else if(solucao_parcial[linha] - linha_pesquisada == linha - linha_pesquisada){

                } else{

                }

            }

        solucao_parcial[linha_pesquisada] = linha_pesquisada;

        }
       return solucao_parcial[linha_pesquisada];
    }



int backtracking(int rainhas, vector<int> &solucao_parcial, int coluna_escolhida, int fim){
    if(fim == rainhas){
        return 1;
    } else if(coluna_escolhida == rainha_fixa) {
        backtracking(rainhas, solucao_parcial, coluna_escolhida+1, fim+1);
    } else {
        int c = encontrarCandidatos(rainhas, solucao_parcial, 0);
        solucao_parcial.push_back(c);
        backtracking(rainhas, solucao_parcial, coluna_escolhida+1, fim+1);
    }
}

int main(){
    int rainhas;

    cout << "Digite o numero de rainhas: ";
    cin >> rainhas;

    vector<int> solucao_parcial;
    solucao_parcial.push_back(0);



    if(backtracking(rainhas, solucao_parcial, 0, 0) ==1) {
        imprimeCandidatos(solucao_parcial);
    }

    return 0;
}
