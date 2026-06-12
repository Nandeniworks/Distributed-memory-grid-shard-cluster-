#include <iostream>
#include <limits>

#include "CatalogIndex.h"
#include "RecoveryHistory.h"
#include "BufferLine.h"
#include "RegistryIndex.h"
#include "LineSorter.h"
#include "ConnectivityNetwork.h"
#include "ReplicationPathway.h"
#include "PriorityLayout.h"

using namespace std;

// Helper function to read integers safely and prevent infinite CLI loops on invalid input
int getSafeInteger(const string& prompt)
{
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            return value;
        } else {
            cout << "\n[ERROR] Invalid input. Please enter a valid integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int main()
{
    CatalogIndex catalog;
    RecoveryHistory recovery;
    BufferLine buffer;
    RegistryIndex registry;
    LineSorter sorter;
    ConnectivityNetwork network;
    ReplicationPathway pathway;
    PriorityLayout layout;

    int choice;

    do
    {
        cout << "\n=========================================\n";
        cout << "   DISTRIBUTED MEMORY GRID SHARD CLUSTER\n";
        cout << "=========================================\n";
        cout << " 1. Catalog Index        (Hashing)\n";
        cout << " 2. Recovery History     (Stack)\n";
        cout << " 3. Buffer Line          (Queue)\n";
        cout << " 4. Registry Index       (Binary Search)\n";
        cout << " 5. Line Sorter          (Merge Sort)\n";
        cout << " 6. Connectivity Network (Graph Adjacency List)\n";
        cout << " 7. Replication Pathway  (Dijkstra's Shortest Path)\n";
        cout << " 8. Priority Layout      (Min-Heap / Eviction)\n";
        cout << " 9. Exit\n";
        cout << "=========================================\n";

        choice = getSafeInteger("Enter Choice (1-9): ");

        switch(choice)
        {
            case 1:
            {
                int ch = getSafeInteger("\n[Catalog Index Menu]\n1. Add Record\n2. Search Record\n3. Display Catalog\nEnter Choice: ");
                if(ch == 1) catalog.addRecord();
                else if(ch == 2) catalog.searchRecord();
                else if(ch == 3) catalog.displayCatalog();
                else cout << "Invalid option chosen.\n";
                break;
            }

            case 2:
            {
                int ch = getSafeInteger("\n[Recovery History Menu]\n1. Add Operation\n2. Recover (Undo) Operation\n3. Display History\nEnter Choice: ");
                if(ch == 1) recovery.addOperation();
                else if(ch == 2) recovery.undoOperation();
                else if(ch == 3) recovery.displayHistory();
                else cout << "Invalid option chosen.\n";
                break;
            }

            case 3:
            {
                int ch = getSafeInteger("\n[Buffer Line Menu]\n1. Add Request\n2. Process Request\n3. Display Pending Requests\nEnter Choice: ");
                if(ch == 1) buffer.addRequest();
                else if(ch == 2) buffer.processRequest();
                else if(ch == 3) buffer.displayRequests();
                else cout << "Invalid option chosen.\n";
                break;
            }

            case 4:
            {
                int ch = getSafeInteger("\n[Registry Index Menu]\n1. Display Registered Nodes\n2. Search Node\nEnter Choice: ");
                if(ch == 1) registry.displayNodes();
                else if(ch == 2) registry.searchNode();
                else cout << "Invalid option chosen.\n";
                break;
            }

            case 5:
            {
                int ch = getSafeInteger("\n[Line Sorter Menu]\n1. Add Block\n2. Sort Blocks (Rank by Benefit)\n3. Display Blocks\nEnter Choice: ");
                if(ch == 1) sorter.addBlock();
                else if(ch == 2) sorter.sortBlocks();
                else if(ch == 3) sorter.displayBlocks();
                else cout << "Invalid option chosen.\n";
                break;
            }

            case 6:
            {
                int ch = getSafeInteger("\n[Connectivity Network Menu]\n1. Add Connection\n2. Display Network Map\nEnter Choice: ");
                if(ch == 1) network.addConnection();
                else if(ch == 2) network.displayNetwork();
                else cout << "Invalid option chosen.\n";
                break;
            }

            case 7:
            {
                int ch = getSafeInteger("\n[Replication Pathway Menu]\n1. Add Weighted Link\n2. Find Shortest Pathway (Dijkstra)\nEnter Choice: ");
                if(ch == 1) pathway.addLink();
                else if(ch == 2) pathway.shortestPath();
                else cout << "Invalid option chosen.\n";
                break;
            }

            case 8:
            {
                int ch = getSafeInteger("\n[Priority Layout Menu]\n1. Add Block\n2. Evict Oldest Block\n3. Display Blocks\nEnter Choice: ");
                if(ch == 1) layout.addBlock();
                else if(ch == 2) layout.evictBlock();
                else if(ch == 3) layout.displayBlocks();
                else cout << "Invalid option chosen.\n";
                break;
            }

            case 9:
                cout << "\nExiting Distributed Memory Grid Shard Cluster. Goodbye!\n";
                break;

            default:
                cout << "\n[ERROR] Choice must be between 1 and 9.\n";
                break;
        }

    } while(choice != 9);

    return 0;
}