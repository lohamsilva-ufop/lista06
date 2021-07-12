#include <iostream>
#include <vector>

using namespace std;
//função que imprime a solução encontrada.
void imprime_solucao(vector <vector <int>> &solucao){
    for(int i=0;i<solucao.size(); i++){
            for(int j=0;j<solucao[i].size(); j++){
                cout << solucao[i][j] << ",";
            }
            cout << endl;
        }
}


//função que verifica se a sentença é completa, ou seja: se todas as variáveis possuem atribuição.
bool verifica_completa(int a, int b, int c){
    if (b == NULL){ //trata  a varivel b, se caso ainda não possuir atribuição.
        b = 0;
    }

    if(c == NULL){ //trata  a varivel c, se caso ainda não possuir atribuição.
        c = 0;
    }
    //cout << "A: " << a << ", B: " << b << ", C: " << c << endl;

    //Se as variveis possuem valor maior que 0 - valor que esta no dominio, ela esta completa. Retorna true. Senao, false.
    if((a>0 && b > 0) && c > 0){
        return true;
    } else {
        return false;
    }
}


//funcao que verifica se é factivel, ou seja: se o valor das variaveis passam no criterio de a>b e b>c
bool verifica_factivel(int a, int b, int c){

    if(a>b && b>c){ //se a>b e b>c é factivel, portanto retorna true, senao false.
        return true;
    } else{
        return false;
    }
}

//a função backtracking  recebe como parametro, o vetor de solucoes, o dominio A, uma variavel de controle tamanho e o vetor de dominios.
bool backtracking(vector <vector <int>> &solucao, int dominio_a, int tamanho, vector <int> &dominio){
    //se o tamanho é igual a 4, ou seja: se o dominio de A chegou ao fim, retorna verdadeiro e para a função.
    if(tamanho == 4){
        return true;
    } else{ // senao verifica as possibilidades
            for(int i=0; i<=dominio.size();i++){ // ele verifica as possibilidades do dominio A com as variaveis b e c
                dominio_a = dominio[tamanho]; // a recebe o valor do dominio para comparar com os outros
                int b = dominio[i-1]; //b iré iterar com o dominio de A -1
                int c = dominio[i-2]; //c iré iterar com o dominio de A -2

                /* Exemplo da aula:
(   ), (1,   ), (1,1, ), (1,2,1), (1,3,2), (1,4,3) = NENHUM -> retorne conjunto vazio -> volte para a execução anterior
(   ), (2,   ), (2,1 ), (2,2,1), (2,3,2), (2,4,3) = NENHUM ->  retorne conjunto vazio -> volte para a execução anterior
(   ), (3,   ), (3,1 ), (3,2,1), (3,3,2), (3,4,3) = NENHUM -> retorne (3,2,1)
(   ), (4,   ), (4,1, ), (4,2,1), (4,3,2), (4,4,3) = NENHUM -> retorne (4,2,1),  (4,3,2)
 */


                //se os valores sao completos e factiveis, insere no vetor de solucoes. Se nao e, retorna e chega a proxima possibilidade
                if(verifica_completa(dominio_a,b,c) == true && verifica_factivel(dominio_a,b,c) == true){
                        vector <int> s;
                        s.push_back(dominio_a);
                        s.push_back(b);
                        s.push_back(c);
                        solucao.push_back(s);
                }

            }
            //depois disso, tamanho é iterado, ou seja: A irá receber o proximo valor de dominio
            tamanho = tamanho + 1;
            dominio_a = dominio[tamanho];
            //chama a função backtracking de novo, para verificar as proximas solucoes
            backtracking(solucao, dominio_a, tamanho, dominio);
    }
}



int main(){
    //cria o vetor de dominios
    vector <int> dominio {1,2,3,4};
    //cria a matriz de solucies
    vector <vector <int>> solucao;

    //chama a funcao backtracking
    backtracking(solucao,0,0,dominio);

    //se o vetor de solucoes esta cheio, significa que encontrou solucao: imprime, se nao achou,
    // ou seja, se o vetor tem tamanho 0, avisa que nao ha solucoes.
    if(solucao.size() != 0){
        cout << "Solucao utilizando backtracking: " << endl;
        imprime_solucao(solucao);
    } else {
        cout << "Nao houve solucao para o dominio utilizando backtracking. " << endl;
    }

    return 0;
}
