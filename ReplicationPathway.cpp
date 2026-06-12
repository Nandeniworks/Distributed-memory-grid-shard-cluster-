#include "ReplicationPathway.h"
#include <limits>
#include <unordered_map>
#include <algorithm>

// DSA CONCEPT: Dijkstra's Algorithm
// This algorithm computes the shortest path between a source node and a destination node
// based on edge weights (representing network latencies in milliseconds).
// It maintains a tentative distance for each vertex and selects the unvisited node
// with the smallest tentative distance using a priority queue (Min-Heap).

void ReplicationPathway::addLink()
{
    int u, v, latency;

    cout << "Enter Source Node ID: ";
    while (!(cin >> u)) {
        cout << "Invalid input. Enter integer Node ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter Destination Node ID: ";
    while (!(cin >> v)) {
        cout << "Invalid input. Enter integer Node ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter Latency (ms): ";
    while (!(cin >> latency) || latency < 0) {
        cout << "Invalid latency. Enter positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Undirected graph representation
    graph[u].push_back({v, latency});
    graph[v].push_back({u, latency});

    cout << "\nLink Added: Node " << u << " <-> Node " << v << " (Latency: " << latency << " ms)\n";
}

void ReplicationPathway::shortestPath()
{
    if (graph.empty()) {
        cout << "\nNo links exist in the Replication Network. Add links first.\n";
        return;
    }

    int source, destination;

    cout << "Enter Source Node ID: ";
    while (!(cin >> source)) {
        cout << "Invalid input. Enter integer Node ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter Destination Node ID: ";
    while (!(cin >> destination)) {
        cout << "Invalid input. Enter integer Node ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Distance map to handle any dynamic integer Node IDs
    unordered_map<int, int> dist;
    const int INF = 1e9;

    // Initialize all known nodes to infinity
    for (auto &pair : graph) {
        dist[pair.first] = INF;
        for (auto &edge : pair.second) {
            dist[edge.first] = INF;
        }
    }

    // Ensure source and destination are initialized
    dist[source] = INF;
    dist[destination] = INF;

    // Min-Heap Priority Queue: elements are pair<distance, node_id>
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[source] = 0;
    pq.push({0, source});

    while(!pq.empty())
    {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // If we found a longer path, discard it
        if (d > dist[node])
            continue;

        // Traverse neighbors
        auto it = graph.find(node);
        if (it != graph.end()) {
            for(const auto &edge : it->second)
            {
                int next = edge.first;
                int weight = edge.second;

                if(dist[next] > dist[node] + weight)
                {
                    dist[next] = dist[node] + weight;
                    pq.push({dist[next], next});
                }
            }
        }
    }

    cout << "\n--- Replication Pathway Latency Path ---\n";
    if(dist[destination] == INF) {
        cout << "Result: Path from Node " << source << " to Node " << destination << " NOT FOUND!\n";
    } else {
        cout << "Result: Shortest path found!\n";
        cout << "Minimum Latency: " << dist[destination] << " ms\n";
    }
    cout << "----------------------------------------\n";
}