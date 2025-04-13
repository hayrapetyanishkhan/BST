#include "BST.hpp"

int main() {
    BST<int> tree;

    std::cout << "Empty tree tests:\n";
    std::cout << "Search 10: " << tree.search(10) << "\n";
    std::cout << "Height: " << tree.Height() << "\n";
    tree.erase(10);

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    std::cout << "\nTraversal tests:\n";
    std::cout << "InOrder: ";
    tree.InOrderTraverse();
    std::cout << "\nPreOrder: ";
    tree.PreOrderTraverse();
    std::cout << "\nPostOrder: ";
    tree.PostOrderTraverse();
    std::cout << "\nIterativePre: ";
    tree.IterativePre();
    std::cout << "\nHeight: " << tree.Height() << "\n";

    std::cout << "\nSearch tests:\n";
    std::cout << "Search 30: " << tree.search(30) << "\n";
    std::cout << "IterativeSearch 30: " << tree.IterativeSearch(30) << "\n";
    std::cout << "Search 99: " << tree.search(99) << "\n";

    std::cout << "\nDeletion tests:\n";
    tree.erase(20);
    std::cout << "After deleting 20: ";
    tree.InOrderTraverse();
    tree.erase(70);
    std::cout << "\nAfter deleting 70: ";
    tree.InOrderTraverse();
    tree.erase(50);
    std::cout << "\nAfter deleting 50: ";
    tree.InOrderTraverse();
    std::cout << "\nHeight after deletions: " << tree.Height() << "\n";

    BST<int> tree2;
    tree2.insert(50);
    tree2.insert(30);
    tree2.insert(70);
    tree2.insert(20);
    tree2.insert(40);
    tree2.insert(60);
    tree2.insert(80);

    std::cout << "\nDuplicate insertion test:\n";
    tree2.insert(50);
    std::cout << "After duplicate insert: ";
    tree2.InOrderTraverse();
    std::cout << "\n";

    return 0;
}