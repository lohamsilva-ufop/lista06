#include <iostream>
#include <vector>

using namespace std;

/*
Aluno: Loham Santos da Silva - PCC104 - UFOP
O problema da moeda consiste em retornar o numero minimo de moedas que um troco pode possuir.
O algoritmo abaixo foi implementado com base na explicação do site:
https://panda.ime.usp.br/panda/static/pythonds_pt/04-Recursao/11-programacaoDinamica.html
*/

void inicializaVetor(vector <int> &moedas, int tamanho){
    for(int i=0; i<tamanho; i++){
        moedas.push_back(-1);
    }
}

int changeMakingProblem(vector <int> moedas, vector <int> memoria, int valor_troco){
    int restante_moedas; //variavel que conta a quantidade de moedas que restam para o troco

    // verifica se na posição do valor de troco constante do vetor memoria é igual a -1. Se for, ele faz a chamada recursiva
    if(memoria[valor_troco] == -1){

        // caso base
        //se o valor do troco é igual a 0
        if(valor_troco == 0){
            restante_moedas = 0; //nao resta mais moedas para troco
        } else{ //senao
            restante_moedas = valor_troco + 1; //senao, ainda há moedas: pega-se o valor do troco + 1 (por já ter usado uma moeda)
                for(int i=0; i<moedas.size(); i++){ //faça um for de 0 ate a quantidade de moedas
                    if(valor_troco >= moedas[i]){ //se o valor do troco é maior ou igual a moeda da posicao especifica
                        //verifica-se a quantidade minima de moedas que eu preciso para o troco usando essa moeda
                        int valor_troco_subtraido = changeMakingProblem(moedas, memoria, valor_troco-moedas[i]) + 1; //chamo a função recursiva passando o vetor de moeda e o valor do troco subtraído pelo valor da moeda do for + 1 (por ter subtraído uma moeda)
                        //qual é a melhor solução?
                        if( valor_troco_subtraido < restante_moedas ){ //se o valor do troco subtraído (o valor retornado pela chamada rec é menor que o restante de moedas)
                            restante_moedas = valor_troco_subtraido; //o restante de moedas recebe o valor retornado pela funcao recursiva (atualiza)
                        }
                    }
                }
        }
        memoria[valor_troco] = restante_moedas; // memoria na posição do valor do troco atualizado recebe o valor do restante de moedas
    } else{
        restante_moedas = memoria[valor_troco];  //senao, restante de moedas recebe o valor e retorna o restante
    }
    return restante_moedas; //retorna o restante
}


int main(){
    //cria o vetor de moedas e inicializa com os valores de moedas Brasileiras
    vector <int> moedas;
    moedas.push_back(1);
    moedas.push_back(2);
    moedas.push_back(5);
    moedas.push_back(10);
    moedas.push_back(20);
    moedas.push_back(50);
    moedas.push_back(100);
    moedas.push_back(200);


    int quantidade_moedas = moedas.size();

    //pega o valor do troco
    int troco = 81;

    //cria o vetor memoria para inserir os resultados e evitar recomputação
    vector <int> memoria;

    //inicializa o vetor memoria com -1
    inicializaVetor(memoria, troco+1);

    cout << "Quantidade de moedas: " << moedas.size() << endl;
    cout << "Valor do troco: " << troco << endl;

    cout << "A menor quantidade de moedas utilziadas para o troco e: " << changeMakingProblem(moedas, memoria, troco);

    return 0;
}
