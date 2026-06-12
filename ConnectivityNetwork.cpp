#include "ConnectivityNetwork.h"
#include <limits>
#include <algorithm>

// DSA CONCEPT: Graph using Adjacency List
// Instead of a fixed-size array that crashes for nodes >= 10, we use std::map<int, std::vector<int>>.
// This allows any integer Node ID and maps it to a list of connected nodes (adjacency list).
// Since it's an undirected graph, adding a link from u to v means we add v to graph[u] and u to graph[v].

void ConnectivityNetwork::addConnection()
{
    int u, v;

    cout << "Enter First Node ID: ";
    while (!(cin >> u)) {
        cout << "Invalid input. Enter integer Node ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter Second Node ID: ";
    while (!(cin >> v)) {
        cout << "Invalid input. Enter integer Node ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Check if connection already exists to avoid duplicate edges
    auto &u_list = graph[u];
    if (find(u_list.begin(), u_list.end(), v) == u_list.end()) {
        graph[u].push_back(v);
        graph[v].push_back(u);
        cout << "\nConnection between Node " << u << " and Node " << v << " Added Successfully!\n";
    } else {
        cout << "\nConnection already exists between Node " << u << " and Node " << v << "!\n";
    }
}

void ConnectivityNetwork::displayNetwork()
{
    if(graph.empty())
    {
        cout << "\nConnectivity Network is Empty. Add connections first.\n";
        return;
    }

    cout << "\n----- Connectivity Network Adjacency List -----\n";
    for(const auto &pair : graph)
    {
        int node = pair.first;
        const auto &adjList = pair.second;

        cout << "Node " << node << " -> connected to nodes: [";
        for(size_t i = 0; i < adjList.size(); ++i)
        {
            cout << adjList[i];
            if(i < adjList.size() - 1)
                cout << ", ";
        }
        cout << "]\n";
    }
    cout << "-----------------------------------------------\n";
}