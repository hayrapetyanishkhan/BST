# Binary Search Tree (BST) in C++

This project is an implementation of a **generic Binary Search Tree (BST)** using C++ templates.
It includes recursive and iterative methods for insertion, searching, traversal, and deletion.

## ✨ Features

* **Generic implementation** (works with any comparable data type)
* **Insert**

  * Recursive `insert`
  * Iterative `IterativeInsert`
* **Search**

  * Recursive `search`
  * Iterative `IterativeSearch`
* **Delete** (`erase`)
* **Traversals**

  * Recursive: Preorder, Inorder, Postorder
  * Iterative: Preorder, Inorder, Postorder
  * Breadth-First Search (BFS / Level Order)
* **Tree Properties**

  * Height calculation
  * Minimum / Maximum node
  * Successor and Predecessor
* **Memory Management**

  * Copy constructor, move constructor
  * Copy assignment, move assignment
  * Destructor (proper cleanup)

## 🛠️ Requirements

* C++17 or later
* Standard libraries only (`<iostream>`, `<queue>`, `<stack>`, `<algorithm>`)

## 📂 Project Structure

```
BST.hpp      # Class definition
BST.tpp      # Class implementation (templated functions)
main.cpp     # Example usage
```

## 🚀 How to Build & Run

```bash
g++ -std=c++17 main.cpp -o bst
./bst
```

## 📌 Example Output

```
InOrder: 3 5 7 10 12 15 18 
PreOrder: 10 5 3 7 15 12 18 
PostOrder: 3 7 5 12 18 15 10 
Iterative InOrder: 3 5 7 10 12 15 18 
Iterative PreOrder: 10 5 3 7 15 12 18 
Iterative PostOrder: 3 7 5 12 18 15 10 
Searching for 7: Found
Searching for 20: Not Found
After Erasing 7, InOrder: 3 5 10 12 15 18 
After Erasing 10, InOrder: 3 5 12 15 18 
Tree Height: 3
Copy Tree InOrder: 3 5 12 15 18 
Searching for 12 in copied tree: Found
```

## 📖 Learning Outcomes

This project demonstrates:

* Template programming in C++
* Recursive vs. iterative approaches
* Proper use of **RAII** and **rule of five** (copy/move constructors and assignments, destructor)
* Tree algorithms and memory management

## 📬 Author

**Ishkhan Hayrapetyan**
[GitHub Profile](https://github.com/hayrapetyanishkhan)
