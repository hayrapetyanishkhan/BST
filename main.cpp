#include "BST.hpp"

int main() {
    BST<int> tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    std::cout << "InOrder: ";
    tree.InOrderTraverse();
    std::cout << std::endl;

    std::cout << "PreOrder: ";
    tree.PreOrderTraverse();
    std::cout << std::endl;

    std::cout << "PostOrder: ";
    tree.PostOrderTraverse();
    std::cout << std::endl;

    std::cout << "Iterative InOrder: ";
    tree.IterativeInOrder();
    std::cout << std::endl;

    std::cout << "Iterative PreOrder: ";
    tree.IterativePreOrder();
    std::cout << std::endl;

    std::cout << "Iterative PostOrder: ";
    tree.IterativePostOrder();
    std::cout << std::endl;

    std::cout << "Searching for 7: " << (tree.search(7) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for 20: " << (tree.search(20) ? "Found" : "Not Found") << std::endl;

    tree.erase(7);
    std::cout << "After Erasing 7, InOrder: ";
    tree.InOrderTraverse();
    std::cout << std::endl;

    tree.erase(10);
    std::cout << "After Erasing 10, InOrder: ";
    tree.InOrderTraverse();
    std::cout << std::endl;

    std::cout << "Tree Height: " << tree.Height() << std::endl;

    BST<int> treeCopy(tree);
    std::cout << "Copy Tree InOrder: ";
    treeCopy.InOrderTraverse();
    std::cout << std::endl;

    std::cout << "Searching for 12 in copied tree: " << (treeCopy.search(12) ? "Found" : "Not Found") << std::endl;

    return 0;
}
