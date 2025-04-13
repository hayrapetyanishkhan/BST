#ifndef BST_HPP
#define BST_HPP

#include <iostream>

template<typename T>
class BST
{
    struct TreeNode
    {
        TreeNode* left{};
        TreeNode* right{};
        T val;
        TreeNode(T value) : val{value} {}
        ~TreeNode()
        {
            delete left;
            delete right;
        }
    };
public:
    BST() {}
    void insert(T value);
    void IterativeInsert(T value);
    bool search(T value);
    bool IterativeSearch(T val);
    void erase(T value);

    void IterativePre();
    void PreOrderTraverse();
    void InOrderTraverse();
    void PostOrderTraverse();
    int Height(); // the height of the root node
    TreeNode* getMin(TreeNode* node);
    TreeNode* getMax(TreeNode* node);
    TreeNode* getSuccessor(TreeNode* node);
    TreeNode* getPredecessor(TreeNode* node);

    ~BST() { delete root; }

    //called on the BST object for a specific node
    void PreOrder(TreeNode* node); // start traversing from the node
    void InOrder(TreeNode* node);
    void PostOrder(TreeNode* node);
    int getHeight(TreeNode* node); // height of the node
private:
    TreeNode* insertHelper(TreeNode* node,T value);
    bool searchHelper(TreeNode* node,T value);
    TreeNode* eraseHelper(TreeNode* node,T value);
private:
    TreeNode* root{};
};

#include "BST.tpp"

#endif