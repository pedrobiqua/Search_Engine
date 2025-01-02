#ifndef PAGE_RANK_H
#define PAGE_RANK_H

#include <list>
#include <map>

namespace page_rank {
using namespace std;

/**
 * @class Graph
 * @brief Represents a directed graph used to compute the PageRank algorithm.
 *
 * The `Graph` class allows adding edges, calculating the PageRank of each node,
 * and printing the graph. It uses an adjacency list to represent the graph.
 *
 * Example of usage:
 * @code
 * page_rank::Graph graph;
 * graph.add_edge(0, 1);
 * graph.add_edge(1, 2);
 * auto pageRank = graph.compute_page_rank();
 * graph.print();
 * @endcode
 */
class Graph {
   public:
    /**
     * @brief Adds a directed edge between two vertices.
     *
     * This function adds a directed edge from `u` to `v` in the graph.
     *
     * @param u Source vertex of the edge.
     * @param v Destination vertex of the edge.
     */
    void add_edge(int u, int v);

    /**
     * @brief Computes the PageRank of all the vertices in the graph.
     *
     * This function uses the PageRank algorithm to calculate the score of
     * each vertex in the graph, iterating until the maximum number of
     * iterations is reached or the variation is smaller than the specified
     * tolerance.
     *
     * @param damping_factor Damping factor used in the PageRank calculation.
     * Default value is 0.85.
     * @param max_iterations Maximum number of iterations for the algorithm.
     * Default value is 100.
     * @param tol Tolerance for the convergence of the algorithm. Default value
     * is 1e-6.
     * @param on_print Flag to control if the iterations should be printed.
     * Default value is `false`.
     * @return A map containing the PageRank of each vertex, where the key is
     * the vertex and the value is the PageRank.
     */
    auto compute_page_rank(double damping_factor = 0.85,
                           int max_iterations = 100,
                           double tol = 1e-6,
                           bool on_print = false) -> map<int, double>;

    /**
     * @brief Prints the adjacency list of the graph.
     *
     * This function prints the connections of all vertices in the graph.
     */
    void print();

    /**
     * @brief Gets the adjacency list of the graph.
     *
     * This function returns a constant reference to the adjacency list of the
     * graph.
     *
     * @return Constant reference to the adjacency list map.
     */
    const map<int, list<int>>& get_adjList() const { return adjList_; }

   private:
    /**
     * @brief Adjacency list of the graph.
     *
     * The graph is represented by a map, where the keys are the vertices and
     * the values are lists of integers representing the adjacent vertices.
     */
    map<int, list<int>> adjList_;
};

}  // namespace page_rank

#endif  // PAGE_RANK_H
