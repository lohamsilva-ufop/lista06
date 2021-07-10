#include <iostream>
#include <vector>

using namespace std;

bool verifica_completa(int solucao){

}

bool verifica_factivel(int solucao){

}

int backtracking(int solucao, int variavel, vector <int> &dominio, int d){
    if(verifica_completa(solucao) == true && verifica_factivel(solucao) == true){
          return solucao;
    } else{
        for(int i=0;i<dominio.size(); i++){
            int valor;
            int teste_factivel = solucao + valor;
                if(verifica_factivel(teste_factivel) == true){
                        return backtracking(teste_factivel, variavel, dominio, d);
                }
        }

    }
    return 0;
}




int main(){
    vector <int> dominio {1,2,3,4};
    return 0;
}
