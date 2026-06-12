#ifndef REPLICATIONPATHWAY_H
#define REPLICATIONPATHWAY_H

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// ============================================================================
// DSA CONCEPT: DIJKSTRA'S ALGORITHM (Graph + Min-Heap/Priority Queue)
// ----------------------------------------------------------------------------
// Dijkstra's algorithm finds the shortest path (minimum latency) from a source
// node to all other nodes in a weighted graph.
//
// Key Features:
// - Graph Representation: Adjacency list with edge weights (latency) using 
//   `std::unordered_map<int, std::vector<std::pair<int, int>>>`.
// - Min-Heap: `std::priority_queue` with a custom comparator (`greater`) is used 
//   to always extract the node with the minimum tentative distance.
// - Time Complexity: O((V + E) log V) where V = Vertices, E = Edges.
// - Application: Optimal data replication route planning based on network latency.
// ============================================================================

class ReplicationPathway
{
private:
    unordered_map<int, vector<pair<int, int>>> graph;

public:
    void addLink();
    void shortestPath();
};

#endif