#include "BST.hpp"

template<typename T>
void BST<T>::PreOrderTraverse()
{
    PreOrder(root);
}

template<typename T>
void BST<T>::PreOrder(TreeNode* node)
{
    if(!node) return;
    std::cout << node->val << " ";
    PreOrder(node->left);
    PreOrder(node->right);
}

template<typename T>
void BST<T>::InOrderTraverse()
{
    InOrder(root);
}

template<typename T>
void BST<T>::InOrder(TreeNode* node)
{
    if(!node) return;
    InOrder(node->left);
    std::cout << node->val << " ";
    InOrder(node->right);
}

template<typename T>
void BST<T>::PostOrderTraverse()
{
    PostOrder(root);
}

template<typename T>
void BST<T>::PostOrder(TreeNode* node)
{
    if(!node) return;
    PostOrder(node->left);
    PostOrder(node->right);
    std::cout << node->val << " ";
}

template<typename T>
bool BST<T>::search(T value)
{
    return searchHelper(root,value);
}

template<typename T>
bool BST<T>::searchHelper(TreeNode* node,T value)
{
    if(!node) return false;
    if(node->val == value) return true;
    if(node->val > value) return searchHelper(node->left,value);
    else return searchHelper(node->right,value);
}

template<typename T>
bool BST<T>::IterativeSearch(T value)
{
    TreeNode* node = root;
    while(node)
    {
        if(node->val == value)
        {
            return true;
        }
        if(node->val > value)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    return false;
}

template<typename T>
int BST<T>::Height()
{
    return getHeight(root);
}

template<typename T>
int BST<T>::getHeight(TreeNode* node)
{
    if(!node) return 0;
    int left = getHeight(node->left);
    int right = getHeight(node->right);
    return std::max(left,right) + 1;
}

template<typename T>
void BST<T>::insert(T value)
{
    root = insertHelper(root,value);
}

template<typename T>
BST<T>::TreeNode* BST<T>::insertHelper(TreeNode* node,T value)
{
    if(!node) return new TreeNode(value);
    if(node->val > value) 
    {
        node->left =  insertHelper(node->left,value);
    }
    else if(node->val < value)
    {
        node->right =  insertHelper(node->right,value);
    }
    return node;
}

template<typename T>
void BST<T>::IterativeInsert(T value)
{
    if(!root) 
    {
        root = new TreeNode(value);
        return;
    }
    TreeNode* Root = root;
    TreeNode* parent = nullptr;
    while(Root)
    {
        parent = Root;
        if(Root->val > value) Root = Root->left;
        else if(Root->val < value) Root = Root->right;
        else return;
    }
    TreeNode* obj = new TreeNode(value);
    if(parent->val > value)
    {
        parent->left = obj;
    }
    else
    {
        parent->right = obj;
    }
}

template<typename T>
void BST<T>::erase(T value)
{
    root = eraseHelper(root,value);
}

template<typename T>
BST<T>::TreeNode* BST<T>::eraseHelper(TreeNode* node,T value)
{
    if(!node) return node;
    if(node->val > value)
    {
        node->left = eraseHelper(node->left,value);
    }
    else if(node->val < value)
    {
        node->right = eraseHelper(node->right,value);
    }
    else
    {   
        TreeNode* result{};
        if(!node->left)
        {
            result = node->right;
            node->right = nullptr;
            delete node;
            return result;
        }
        else if(!node->right)
        {   
            result = node->left;
            node->left = nullptr;
            delete node;
            return result;
        }
        else
        {
            result = getMin(node->right);
            node->val = result->val;
            node->right = eraseHelper(node->right,node->val);
        }
    }
    return node;
}

template<typename T>
BST<T>::TreeNode* BST<T>::getMin(TreeNode* node)
{
    if(!node) return node;
    while(node->left)
    {
        node = node->left;
    }
    return node;
}

template<typename T>
BST<T>::TreeNode* BST<T>::getMax(TreeNode* node)
{
    if(!node) return node;
    while(node->right)
    {
        node = node->right;
    }
    return node;
}

template<typename T>
void BST<T>::IterativePre()
{
    if(!root) return;
    std::stack<TreeNode*> stack;
    stack.push(root);
    while(!stack.empty())
    {
        TreeNode* tmp = stack.top();
        stack.pop();
        std::cout << tmp->val << " ";
        if(tmp->right)
        {
            stack.push(tmp->right);
        }
        if(tmp->left)
        {
            stack.push(tmp->left);
        }
    } 
}

template<typename T>
BST<T>::TreeNode* BST<T>::getPredecessor(TreeNode* node)
{
    if(!node) return node;
    if(node->left)
    {
        return getMax(node->left);
    }
    TreeNode* ancestor{};
    TreeNode* current = root;
    while(current)
    {
        if(current->val > node->val)
        {
            ancestor = current;
            current = current->left;
        }
        else if(current->val < node->val)
        {
            ancestor = current;
            current = current->right;
        }
        else
        {
            return ancestor;
        }
    }
    return nullptr;
}

template<typename T>
BST<T>::TreeNode* BST<T>::getSuccessor(TreeNode* node)
{
    if(!node) return node;
    if(node->right)
    {
        return getMin(node->right);
    }
    TreeNode* ancestor{};
    TreeNode* current = root;
    while(current)
    {
        if(current->val > node->val)
        {
            ancestor = current;
            current = current->left;
        }
        else if(current->val < node->val)
        {
            current = current->right; 
        }
        else
        {
            return ancestor;
        }
    }
    return nullptr;
}