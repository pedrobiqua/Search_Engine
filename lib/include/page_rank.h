#ifndef PAGE_RANK_H
#define PAGE_RANK_H

#include <iostream>
#include <list>
#include <map>
#include <ostream>

namespace page_rank {
using namespace std;
class Graph {
public:
  void add_edge(int u, int v);
  auto compute_page_rank(double damping_factor = 0.85, int max_iterations = 100,
                         double tol = 1e-6,
                         bool on_print = false) -> map<int, double>;
  void print();

  const map<int, list<int>>& get_adjList() const { return adjList_; }

private:
  // Lista da adjacencia
  map<int, list<int>> adjList_;
};
} // namespace page_rank
#endif // PAGE_RANK_H
