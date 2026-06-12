# 🚀 Distributed Memory Grid Shard Cluster

<p align="center">
  <img src="https://readme-typing-svg.herokuapp.com/?lines=Distributed+Memory+Grid+Shard+Cluster;DSA+Final+Project;Hashing+%7C+Stack+%7C+Queue+%7C+Graphs;Dijkstra+%7C+Priority+Queue&center=true&width=800&height=50">
</p>

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-17-blue?style=for-the-badge">
  <img src="https://img.shields.io/badge/Problem%20Statement-84-orange?style=for-the-badge">
  <img src="https://img.shields.io/badge/University-ITM%20Skills%20University-blueviolet?style=for-the-badge">
  <img src="https://img.shields.io/badge/Status-Completed-success?style=for-the-badge">
</p>

---

## 👩‍🎓 Project Information

**Student Name:** Nandeni Tiwari

**University:** ITM Skills University

**Course:** Data Structures and Algorithms (DSA)

**Problem Statement Number:** 84

**Project Title:** Distributed Memory Grid Shard Cluster

---

## 📖 Overview

The **Distributed Memory Grid Shard Cluster** is a C++ based simulation of a distributed storage system inspired by concepts used in platforms such as Apache Cassandra and Hazelcast.

The project demonstrates how different Data Structures and Algorithms can be used to solve real-world distributed storage problems such as memory key management, request processing, recovery tracking, node verification, shortest path computation, network representation, and storage optimization.

This project was developed as part of the **DSA Final Project** and focuses on practical implementation of fundamental DSA concepts through a real-world inspired scenario.

---

## 🎯 Project Objective

The objective of this project is to simulate a distributed memory storage environment and demonstrate the practical use of Data Structures and Algorithms in managing storage operations efficiently.

The system showcases:

- Fast memory key lookup
- Recovery tracking
- FIFO request processing
- Efficient node searching
- Data block sorting
- Network connectivity representation
- Shortest path computation
- Storage eviction management

---

## 🏗️ System Architecture

```text
Client Request
       |
       v
 Catalog Index
       |
       v
 Recovery History
       |
       v
 Buffer Line
       |
       v
 Data Storage Node
       |
       +------------------+
       |                  |
       v                  v
Connectivity      Replication Pathway
 Network
       |
       v
 Priority Layout
```

---

## ⚙️ Modules Implemented

### 📌 Catalog Index

**DSA Used:** Hashing

Purpose:

- Store memory keys
- Map records to storage nodes
- Fast lookup and retrieval

Example:

```text
1001 -> UserProfile -> Node1
1002 -> MovieData -> Node2
```

---

### 📌 Recovery History

**DSA Used:** Stack

Purpose:

- Track write operations
- Recover most recent operation first

Example:

```text
WRITE UserProfile
WRITE MovieData
WRITE PaymentInfo
```

Recovery Order:

```text
PaymentInfo
MovieData
UserProfile
```

---

### 📌 Buffer Line

**DSA Used:** Queue

Purpose:

- Process incoming requests
- Maintain FIFO execution order

Example:

```text
READ UserProfile
WRITE MovieData
DELETE WatchHistory
```

---

### 📌 Registry Index

**DSA Used:** Binary Search

Purpose:

- Verify node membership
- Search efficiently within a sorted registry

Example:

```text
1 2 3 4 5 6 7 8 9 10
```

Search:

```text
Node 7
```

Output:

```text
Node Found
```

---

### 📌 Line Sorter

**DSA Used:** Merge Sort

Purpose:

- Rank data blocks based on compression benefit

Before Sorting:

```text
BlockA = 40
BlockB = 80
BlockC = 20
```

After Sorting:

```text
BlockB = 80
BlockA = 40
BlockC = 20
```

---

### 📌 Connectivity Network

**DSA Used:** Graph (Adjacency List)

Purpose:

- Represent node connectivity
- Model distributed network topology

Example:

```text
Node1 -> Node2
Node1 -> Node3
Node2 -> Node4
```

---

### 📌 Replication Pathway

**DSA Used:** Dijkstra's Algorithm

Purpose:

- Find minimum latency path between nodes
- Simulate efficient data replication

Example:

```text
1 -> 2 = 5 ms
1 -> 3 = 2 ms
3 -> 4 = 3 ms
```

Shortest Path:

```text
1 -> 3 -> 4
```

Total Latency:

```text
5 ms
```

---

### 📌 Priority Layout

**DSA Used:** Priority Queue (Min Heap)

Purpose:

- Remove oldest data block first
- Optimize storage utilization

Example:

```text
BlockA = Timestamp 10
BlockB = Timestamp 20
BlockC = Timestamp 30
```

Evicted:

```text
BlockA
```

---

## 🧠 DSA Concepts Demonstrated

| Module | DSA Concept |
|----------|----------|
| Catalog Index | Hashing |
| Recovery History | Stack |
| Buffer Line | Queue |
| Registry Index | Binary Search |
| Line Sorter | Merge Sort |
| Connectivity Network | Graph |
| Replication Pathway | Dijkstra Algorithm |
| Priority Layout | Priority Queue |

---

## 📊 Complexity Analysis

| Module | DSA Used | Time Complexity |
|----------|----------|----------|
| Catalog Index | Hashing | O(1) Average |
| Recovery History | Stack | O(1) |
| Buffer Line | Queue | O(1) |
| Registry Index | Binary Search | O(log n) |
| Line Sorter | Merge Sort | O(n log n) |
| Connectivity Network | Graph | O(V + E) |
| Replication Pathway | Dijkstra | O(E log V) |
| Priority Layout | Priority Queue | O(log n) |

Where:

- V = Number of Nodes
- E = Number of Connections

---

## 📂 Project Structure

```text
├── CatalogIndex.h
├── CatalogIndex.cpp
├── RecoveryHistory.h
├── RecoveryHistory.cpp
├── BufferLine.h
├── BufferLine.cpp
├── RegistryIndex.h
├── RegistryIndex.cpp
├── LineSorter.h
├── LineSorter.cpp
├── ConnectivityNetwork.h
├── ConnectivityNetwork.cpp
├── ReplicationPathway.h
├── ReplicationPathway.cpp
├── PriorityLayout.h
├── PriorityLayout.cpp
├── main.cpp
└── README.md
```

---

## ▶️ How to Run

### Compile

```bash
g++ *.cpp -o dsa
```

### Run

```bash
./dsa
```

---

## 📸 Output Screenshots

Add screenshots of:
## 📸 Output Screenshots

### Main Menu

<img width="558" alt="Main Menu" src="https://github.com/user-attachments/assets/7d7dbccb-bb8b-4b43-b1cb-0f4c374039d8" />

---

### Catalog Index Operations

<img width="446" alt="Catalog Index" src="https://github.com/user-attachments/assets/f55360b0-18b1-437a-bd16-e75e9fb7b65c" />

---

### Recovery History Operations

<img width="526" alt="Recovery History 1" src="https://github.com/user-attachments/assets/32750ce8-b700-4c61-b545-dc26fa5da209" />

<br>

<img width="482" alt="Recovery History 2" src="https://github.com/user-attachments/assets/4e5923ac-154b-47bc-9ca5-5ae9fa2e7477" />

---

### Buffer Line Processing

<img width="465" alt="Buffer Line 1" src="https://github.com/user-attachments/assets/c040843a-9047-4f5d-9177-96fc407ecc3c" />

<br>

<img width="495" alt="Buffer Line 2" src="https://github.com/user-attachments/assets/724ecdad-c613-413d-88c7-b42bfc08d106" />

---

### Registry Search

<img width="448" alt="Registry Search" src="https://github.com/user-attachments/assets/4c2267a0-a9c9-43af-bbd4-e907c3cbcc9f" />

---

### Line Sorter Output

<img width="498" alt="Line Sorter 1" src="https://github.com/user-attachments/assets/34094771-eb84-4bc5-b22c-6b5fd3ca2aca" />

<br>

<img width="481" alt="Line Sorter 2" src="https://github.com/user-attachments/assets/3ad65a1f-d2a4-4783-aaab-bf5149fb3fa9" />

<br>

<img width="484" alt="Line Sorter 3" src="https://github.com/user-attachments/assets/64b1e5be-f79b-4661-b251-6da091686208" />

---

### Connectivity Network

<img width="488" alt="Connectivity Network 1" src="https://github.com/user-attachments/assets/9835ef08-6d74-4422-bbbe-e1a500fbef3e" />

<br>

<img width="434" alt="Connectivity Network 2" src="https://github.com/user-attachments/assets/680a625d-7839-4534-9a56-14e3f41c0c6a" />

---

### Replication Pathway

<img width="488" alt="Replication Pathway 1" src="https://github.com/user-attachments/assets/f022f81e-2cd5-4120-95b7-e1e21734e6a0" />

<br>

<img width="446" alt="Replication Pathway 2" src="https://github.com/user-attachments/assets/e86bb52d-bd36-4810-8ef3-d4b3e6c7fae8" />

---

### Priority Layout

<img width="540" alt="Priority Layout 1" src="https://github.com/user-attachments/assets/cc3cc66e-4921-4854-9932-837bf6511416" />

<br>

<img width="470" alt="Priority Layout 2" src="https://github.com/user-attachments/assets/4eb992e7-c8e0-4592-b685-9942da6be755" />

<br>

<img width="411" alt="Priority Layout 3" src="https://github.com/user-attachments/assets/0da7c99d-de6d-471b-a595-5bc465436a1d" />



---

## 🎓 Academic Purpose

This project was developed as part of the **Data Structures and Algorithms Final Project** at **ITM Skills University**.

The implementation demonstrates how different Data Structures and Algorithms can be integrated into a single system to solve practical storage, networking, searching, sorting, and optimization problems.

---

## 🏁 Conclusion

The Distributed Memory Grid Shard Cluster successfully simulates the core operations of a distributed storage system using C++.

The project integrates Hashing, Stack, Queue, Binary Search, Merge Sort, Graphs, Dijkstra's Algorithm, and Priority Queue into a single application and demonstrates how appropriate DSA selection improves efficiency in real-world systems.

The implementation provides a simplified understanding of concepts used in distributed storage platforms such as Apache Cassandra and Hazelcast while fulfilling all requirements of Problem Statement 84.

---

⭐ If you found this project interesting, consider giving it a star!
