#ifndef CONNECTIVITYNETWORK_H
#define CONNECTIVITYNETWORK_H

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// ============================================================================
// DSA CONCEPT: GRAPH (Adjacency List)
// ----------------------------------------------------------------------------
// A Graph is a non-linear data structure consisting of vertices (nodes) and 
// edges (connections). Here, we represent a cluster connectivity network.
// We use an Adjacency List implemented using `std::map<int, std::vector<int>>`.
//
// Key Features:
// - Map key: represents a Node ID.
// - Map value: list of adjacent Node IDs.
// - Supports dynamic node IDs (not limited to 0-9) and prevents out-of-bounds errors.
// - Space Complexity: O(V + E) where V is vertices and E is edges.
// ============================================================================

class ConnectivityNetwork
{
private:
    map<int, vector<int>> graph;

public:
    void addConnection();
    void displayNetwork();
};

#endif