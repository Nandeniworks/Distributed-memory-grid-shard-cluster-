#include "CatalogIndex.h"
#include <limits>

// DSA CONCEPT: Hashing
// In this module, the catalog stores Memory Records mapped by a unique key.
// By using std::unordered_map (Hash Table), search and insertion occur in O(1) average time complexity.
// This matches the data distribution layer in production clusters (like Cassandra's partition key hashing).

void CatalogIndex::addRecord()
{
    int key;
    MemoryRecord record;

    cout << "\nEnter Memory Key (Integer): ";
    while (!(cin >> key)) {
        cout << "Invalid key. Please enter a valid integer key: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter Data Name (e.g., UserProfile): ";
    cin >> record.dataName;

    cout << "Enter Node Name (e.g., Node1): ";
    cin >> record.nodeName;

    catalog[key] = record;

    cout << "\nRecord Added Successfully to Catalog!\n";
}

void CatalogIndex::searchRecord()
{
    if (catalog.empty()) {
        cout << "\nCatalog is Empty. Add records first.\n";
        return;
    }

    int key;
    cout << "\nEnter Memory Key to Search (Integer): ";
    while (!(cin >> key)) {
        cout << "Invalid key. Please enter a valid integer key: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Hash table lookup: O(1) average time complexity
    auto it = catalog.find(key);

    if(it != catalog.end())
    {
        cout << "\n--- Memory Key Found (via Hash Table) ---\n";
        cout << "Key       : " << it->first << endl;
        cout << "Data Name : " << it->second.dataName << endl;
        cout << "Node Name : " << it->second.nodeName << endl;
        cout << "-----------------------------------------\n";
    }
    else
    {
        cout << "\nMemory Key " << key << " Not Found in Catalog!\n";
    }
}

void CatalogIndex::displayCatalog()
{
    if(catalog.empty())
    {
        cout << "\nCatalog is Empty.\n";
        return;
    }

    cout << "\n----- Catalog Records (Stored via Hashing) -----\n";
    cout << "Format: [Key] -> [Data Record] -> [Assigned Node]\n";
    cout << "-------------------------------------------------\n";

    for(auto &entry : catalog)
    {
        cout << "  " << entry.first
             << " -> " << entry.second.dataName
             << " -> " << entry.second.nodeName
             << endl;
    }
    cout << "-------------------------------------------------\n";
}