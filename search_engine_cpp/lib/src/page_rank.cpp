#include "page_rank.h"
#include <iostream>
#include <ostream>

void page_rank::Graph::add_edge(int u, int v) {
    adjList_[u].push_back(v);
}

void page_rank::Graph::print() {
    cout << "adjList_" << endl;
    for (auto& i : adjList_) {
        cout << i.first << " -> ";
        for (auto& j : i.second) {
            cout << j << " ";
        }
        cout << endl;
    }
}

auto page_rank::Graph::compute_page_rank(double damping_factor,
                                         int max_iterations,
                                         double tol,
                                         bool on_print) -> map<int, double> {
    // Inicializa o PageRank de todas as páginas
    map<int, double> page_rank;
    int num_nodes = adjList_.size();
    for (auto& node : adjList_) {
        page_rank[node.first] = 1.0 / num_nodes;
    }

    for (int it = 0; it < max_iterations; ++it) {
        map<int, double> new_page_rank;
        // Inicializa o novo PageRank de todas as páginas
        for (auto& node : adjList_) {
            new_page_rank[node.first] = (1.0 - damping_factor) / num_nodes;
        }

        // Calcula o novo PageRank baseado nos links de entrada
        for (auto& node : adjList_) {
            int u = node.first;
            const list<int>& neighbors = node.second;
            double shared_rank = page_rank[u] / neighbors.size();
            for (int v : neighbors) {
                new_page_rank[v] += damping_factor * shared_rank;
            }
        }

        // Verifica se houve convergência
        double diff = 0.0;
        for (auto& node : adjList_) {
            diff += abs(new_page_rank[node.first] - page_rank[node.first]);
        }
        if (diff < tol) {
            break;
        }

        page_rank = new_page_rank;
    }

    // Imprime os resultados do PageRank
    if (on_print) {
        cout << "PageRank:" << endl;
        for (auto& node : page_rank) {
            cout << "Node " << node.first << ": " << node.second << endl;
        }
    }

    return page_rank;
}
