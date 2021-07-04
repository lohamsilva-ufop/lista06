#include <iostream>
#include <vector>

using namespace std;
constexpr int nao_encontrado = -1;

//vector <vector <int>> representacao;
struct no{
    vector <int> adjacencias;
    int valor;
};
struct grafo {
    vector <vector <int>> representacao;
    int quantidade_nos;
};

grafo inicializa_grafo(int num_dimensoes){
    grafo novo;
    for (int i=0; i<num_dimensoes; i++){
            vector <int> g;
            for (int j=0; j<num_dimensoes; j++){
                g.push_back(0);
            }
        novo.representacao.push_back(g);
    }
    novo.quantidade_nos = num_dimensoes;
    return novo;
}

vector <no> lista_de_nos(grafo g) {
    vector <no> lista;
    for(int i = 0; i < g.quantidade_nos; i++) {
        no atual;
        atual.valor = i;
        for(int j = 0; j < g.quantidade_nos; j++) {
            if(g.representacao[i][j] == 1) {
                atual.adjacencias.push_back(j);
            }
        }
        lista.push_back(atual);
    }

    return lista;
}



void mostra_grafo(grafo g){
    for (int i=0; i<g.quantidade_nos; i++){
            for (int j=0; j<g.quantidade_nos; j++){
                cout << g.representacao[i][j] << ",";
            }
            cout << endl;
    }
}
void mostra_nos(vector <no> lista) {
    for (int i=0; i<lista.size(); i++){
        cout << endl << "Valor: " << lista[i].valor << endl << "Adjacencias: ";
        for (int j=0; j<lista[i].adjacencias.size(); j++){
            cout << lista[i].adjacencias[j] << ",";
        }
        cout << endl;
    }
}


int verifica_grafo(vector<no> lista_nos, no no_inicial, no no_atual, no no_anterior){
    int valor_no_encontrado = nao_encontrado;

    if(no_atual.adjacencias.size() == 0){
        return nao_encontrado;
    }

    for (int i=0; i<no_atual.adjacencias.size(); i++){

        if((no_atual.valor != no_anterior.valor)
           && (no_anterior.valor == no_atual.adjacencias[i])){
            continue;
        }

        if(no_inicial.valor == no_atual.adjacencias[i]){
          return no_atual.valor;
        }

        if((valor_no_encontrado = verifica_grafo(lista_nos, no_inicial,
                lista_nos[no_atual.adjacencias[i]], no_atual)) != nao_encontrado)
            return valor_no_encontrado;
    }
    return nao_encontrado;
}

void backtracking (vector <vector <int>> &grafo){

}

int main(){
    grafo meu_grafo = inicializa_grafo(5);
    vector<no> meus_nos;

    /* Representação exemplo: http://www.inf.ufsc.br/grafos/temas/hamiltoniano/hamiltoniano.htm
    0 1 2 3 4
0     1   1 1
1   1   1   1
2     1   1
3   1   1   1
4   1   1   1

*/

    meu_grafo.representacao[0][1] = 1;
    meu_grafo.representacao[0][3] = 1;
    meu_grafo.representacao[0][4] = 1;
    meu_grafo.representacao[1][0] = 1;
    meu_grafo.representacao[1][2] = 1;
    meu_grafo.representacao[1][4] = 1;
    meu_grafo.representacao[2][1] = 1;
    meu_grafo.representacao[2][3] = 1;
    meu_grafo.representacao[3][0] = 1;
    meu_grafo.representacao[3][2] = 1;
    meu_grafo.representacao[3][4] = 1;
    meu_grafo.representacao[4][0] = 1;
    meu_grafo.representacao[4][2] = 1;
    meu_grafo.representacao[4][4] = 1;


    cout << "grafo demonstrado atraves da matriz de adjacencias: " << endl;
    mostra_grafo(meu_grafo);

    meus_nos = lista_de_nos(meu_grafo);
    mostra_nos(meus_nos);
    if(verifica_grafo(meus_nos, meus_nos[0], meus_nos[0], meus_nos[0]) != nao_encontrado)
        cout << endl << "Encontrei! Fecha ciclo Hamiltoniano" << endl;
    else
        cout << endl << "Não fecha o ciclo!" << endl;

    return 0;
}
