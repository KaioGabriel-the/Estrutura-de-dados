#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

void ts(const vector<list<int>>& adj) {
    int n = adj.size();
    vector<int> pred(n, 0); // grau de entrada de cada vértice
    queue<int> fila;

    // Conta o número de predecessores (grau de entrada)
    for (int u = 0; u < n; ++u) {
        for (int v : adj[u]) {
            pred[v]++;
        }
    }

    // Insere vértices com grau de entrada 0 na fila
    for (int i = 0; i < n; ++i) {
        if (pred[i] == 0) {
            fila.push(i);
        }
    }

    vector<int> ordenacao;

    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();
        ordenacao.push_back(u);

        for (int v : adj[u]) {
            pred[v]--;
            if (pred[v] == 0) {
                fila.push(v);
            }
        }
    }

  
    if (ordenacao.size() < n) {
        cout << "⚠️ O grafo é cíclico. Ordenação topológica não é possível.\n";
    } else {
        cout << "✅ Ordenação Topológica (ts): ";
        for (int v : ordenacao) {
            cout << v << " ";
        }
        cout << endl;
    }
}

// Função para verificar se um valor já está no caminho
bool pertence(int valor, const vector<int>& caminho) {
    return find(caminho.begin(), caminho.end(), valor) != caminho.end();
}

// Função para exibir caminho invertido (da origem ao destino)
void exibe_caminho(const vector<int>& caminho) {
    for (int i = caminho.size() - 1; i >= 0; --i) {
        cout << caminho[i];
        if (i > 0) cout << " -> ";
    }
    cout << endl;
}

// DFS com pilha e caminho
void dfs(int v, int w, const vector<list<int>>& adj) {
    stack<vector<int>> pilha;
    pilha.push({v});

    while (!pilha.empty()) {
        vector<int> caminho = pilha.top();
        pilha.pop();

        int atual = caminho.back();

        if (atual == w) {
            exibe_caminho(caminho);
        } else {
            for (int vizinho : adj[atual]) {
                if (!pertence(vizinho, caminho)) {
                    vector<int> novo_caminho = caminho;
                    novo_caminho.push_back(vizinho);
                    pilha.push(novo_caminho);
                }
            }
        }
    }
}

// BFS com caminho de v até w
void bfs(int v, int w, const vector<list<int>>& adj) {
    queue<vector<int>> fila;
    fila.push({v});

    while (!fila.empty()) {
        vector<int> caminho = fila.front();
        fila.pop();

        int atual = caminho.back();

        if (atual == w) {
            exibe_caminho(caminho);
        } else {
            for (int vizinho : adj[atual]) {
                if (!pertence(vizinho, caminho)) {
                    vector<int> novo_caminho = caminho;
                    novo_caminho.push_back(vizinho);
                    fila.push(novo_caminho);
                }
            }
        }
    }
}

// Função auxiliar de DFS para ordenação topológica
void dfs_topologico(int v, vector<bool>& visitado, stack<int>& pilha, const vector<list<int>>& adj) {
    visitado[v] = true;

    for (int vizinho : adj[v]) {
        if (!visitado[vizinho]) {
            dfs_topologico(vizinho, visitado, pilha, adj);
        }
    }

    pilha.push(v);
}

// Ordenação topológica principal
void ordenacao_topologica(const vector<list<int>>& adj) {
    int n = adj.size();
    vector<bool> visitado(n, false);
    stack<int> pilha;

    for (int i = 0; i < n; ++i) {
        if (!visitado[i]) {
            dfs_topologico(i, visitado, pilha, adj);
        }
    }

    cout << "Ordenação Topológica:\n";
    while (!pilha.empty()) {
        cout << pilha.top() << " ";
        pilha.pop();
    }
    cout << endl;
}

int main() {
    int num_vertices = 5;
    vector<list<int>> adj(num_vertices);

    // Criando o grafo
    // 0 -> 1, 2
    // 1 -> 3
    // 2 -> 3, 4
    // 3 -> 4
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(4);

    int origem = 0;
    int destino = 4;

    cout << "Caminhos (BFS) de " << origem << " até " << destino << ":\n";
    bfs(origem, destino, adj);

    cout << "\nCaminhos (DFS) de " << origem << " até " << destino << ":\n";
    dfs(origem, destino, adj);

    cout << "\n";
    ordenacao_topologica(adj);

    return 0;
}
