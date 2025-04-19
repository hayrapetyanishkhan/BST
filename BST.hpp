#ifndef BST_HPP
#define BST_HPP

#include <iostream>

template<typename T>
class BST
{
    struct TreeNode
    {
        //Constructors
        TreeNode() = default;
        TreeNode(T value);
        TreeNode(const TreeNode& rhs);
        TreeNode(TreeNode&& rhs);

        //Assignment Operators
        TreeNode& operator=(const TreeNode& rhs);
        TreeNode& operator=(TreeNode&& rhs);

        //Destructor
        ~TreeNode();
        
        //Data members
        TreeNode* left{};
        TreeNode* right{};
        T val;
    };
public:
    BST() = default;
    BST(const BST& rhs);
    BST(BST&& rhs);

    BST& operator=(const BST& rhs);
    BST& operator=(BST&& rhs);

    ~BST();

    void insert(T value);
    void IterativeInsert(T value);
    
    bool search(T value);
    bool IterativeSearch(T val);

    void erase(T value);

    void IterativePreOrder();
    void IterativeInOrder();
    void IterativePostOrder();

    void PreOrderTraverse();
    void InOrderTraverse();
    void PostOrderTraverse();

    int Height();
private:
    TreeNode* getMin(TreeNode* node);
    TreeNode* getMax(TreeNode* node);

    TreeNode* getSuccessor(TreeNode* node);
    TreeNode* getPredecessor(TreeNode* node);
private:
    void PreOrder(TreeNode* node);
    void InOrder(TreeNode* node);
    void PostOrder(TreeNode* node);

    int getHeight(TreeNode* node);
private:
    TreeNode* insertHelper(TreeNode* node,T value);

    bool searchHelper(TreeNode* node,T value);

    TreeNode* eraseHelper(TreeNode* node,T value);
private:
    TreeNode* root{};
};

#include "BST.tpp"

#endif