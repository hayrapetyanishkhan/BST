#include "BST.hpp"

template<typename T>
BST<T>::TreeNode::TreeNode(T value) : val{value} {}

template<typename T>
BST<T>::TreeNode::TreeNode(const TreeNode& rhs)
{
    val = rhs.val;
    left = rhs.left ? new TreeNode(*rhs.left) : nullptr;
    right = rhs.right ? new TreeNode(*rhs.right) : nullptr;
}

template<typename T>
BST<T>::TreeNode::TreeNode(TreeNode&& rhs)
{
    val = std::move(rhs.val);
    left = std::exchange(rhs.left,nullptr);
    right = std::exchange(rhs.right,nullptr);
}

template<typename T>
typename BST<T>::TreeNode& BST<T>::TreeNode::operator=(const TreeNode& rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    val = rhs.val;
    delete left;
    delete right;
    left = rhs.left ? new TreeNode(*rhs.left) : nullptr;
    right = rhs.right ? new TreeNode(*rhs.right) : nullptr;
    return *this;
}

template<typename T>
typename BST<T>::TreeNode& BST<T>::TreeNode::operator=(TreeNode&& rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    val = std::move(rhs.val);
    delete left;
    delete right;
    left = std::exchange(rhs.left,nullptr);
    right = std::exchange(rhs.right,nullptr);
    return *this;
}

template<typename T>
BST<T>::TreeNode::~TreeNode()
{
    delete left;
    delete right;
}

template<typename T>
BST<T>::BST(const BST& rhs)
{
    root = rhs.root ? new TreeNode(*rhs.root) : nullptr;
}

template<typename T>
BST<T>::BST(BST&& rhs)
{
    root = std::exchange(rhs.root,nullptr);
}

template<typename T>
BST<T>& BST<T>::operator=(const BST& rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    delete root;
    root = rhs.root ? new TreeNode(*rhs.root) : nullptr;
    return *this;
}

template<typename T>
BST<T>& BST<T>::operator=(BST&& rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    delete root;
    root = std::exchange(rhs.root,nullptr);
    return *this;
}

template<typename T>
BST<T>::~BST()
{
    delete root;
}

template<typename T>
void BST<T>::insert(T value)
{
    root = insertHelper(root,value);
}

template<typename T>
typename BST<T>::TreeNode* BST<T>::insertHelper(TreeNode* node,T value)
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
    TreeNode* current = root;
    TreeNode* parent{};
    while(current)
    {
        parent = current;
        if(current->val > value) current = current->left;
        else if(current->val < value) current = current->right;
        else return;
    }
    TreeNode* node = new TreeNode(value);
    if(parent->val > value)
    {
        parent->left = node;
    }
    else
    {
        parent->right = node;
    }
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
void BST<T>::erase(T value)
{
    root = eraseHelper(root,value);
}

template<typename T>
typename BST<T>::TreeNode* BST<T>::eraseHelper(TreeNode* node,T value)
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
void BST<T>::IterativePreOrder()
{
    if(!root) return;
    std::stack<TreeNode*> stack;
    stack.push(root);
    while(!stack.empty())
    {
        TreeNode* node = stack.top();
        stack.pop();
        std::cout << node->val << " ";
        if(node->right)
        {
            stack.push(node->right);
        }
        if(node->left)
        {
            stack.push(node->left);
        }
    } 
}

template<typename T>
void BST<T>::IterativeInOrder()
{
    if(!root) return;
    std::stack<TreeNode*> stack;
    TreeNode* current = root;
    while(!stack.empty() || current)
    {
        while(current)
        {
            stack.push(current);
            current = current->left;
        }
        current = stack.top(); stack.pop();
        std::cout << current->val << " ";
        current = current->right;
    }
}

template<typename T>
void BST<T>::IterativePostOrder()
{
    if(!root) return;
    std::stack<TreeNode*> s1,s2;
    s1.push(root);
    while(!s1.empty())
    {
        TreeNode* node = s1.top(); 
        s1.pop();
        s2.push(node);
        if(node->left) s1.push(node->left);
        if(node->right) s1.push(node->right);
    }
    while(!s2.empty())
    {
        std::cout << s2.top()->val << " ";
        s2.pop();
    }

    //Solution 2
    // if(!root) return;
    // stack<TreeNode*> st;
    // TreeNode* current = root;
    // TreeNode* lastVisited{};
    // while(!st.empty() || current) 
    // {
    //     if(current) 
    //     {
    //         st.push(current);
    //         current = current->left;
    //     } 
    //     else 
    //     {
    //         TreeNode* topNode = st.top();
    //         if(topNode->right && lastVisited != topNode->right) 
    //         {
    //             current = topNode->right;
    //         } 
    //         else 
    //         {
    //             std::cout << topNode->val << " ";
    //             lastVisited = topNode;
    //             st.pop();
    //         }
    //     }
    // }
}

template<typename T>
void BST<T>::PreOrderTraverse()
{
    PreOrder(root);
}

template<typename T>
void BST<T>::InOrderTraverse()
{
    InOrder(root);
}

template<typename T>
void BST<T>::PostOrderTraverse()
{
    PostOrder(root);
}

template<typename T>
int BST<T>::Height()
{
    return getHeight(root);
}

template<typename T>
typename BST<T>::TreeNode* BST<T>::getMin(TreeNode* node)
{
    if(!node) return node;
    while(node->left)
    {
        node = node->left;
    }
    return node;
}

template<typename T>
typename BST<T>::TreeNode* BST<T>::getMax(TreeNode* node)
{
    if(!node) return node;
    while(node->right)
    {
        node = node->right;
    }
    return node;
}

template<typename T>
typename BST<T>::TreeNode* BST<T>::getSuccessor(TreeNode* node)
{
    if(!node) return node;
    if(node->right)
    {
        return getMin(node->right);
    }
    TreeNode* successor{};
    TreeNode* current = root;
    while(current)
    {
        if(current->val > node->val)
        {
            successor = current;
            current = current->left;
        }
        else if(current->val < node->val)
        {
            current = current->right; 
        }
        else
        {
            return successor;
        }
    }
    return nullptr;
}

template<typename T>
typename BST<T>::TreeNode* BST<T>::getPredecessor(TreeNode* node)
{
    if(!node) return node;
    if(node->left)
    {
        return getMax(node->left);
    }
    TreeNode* predecessor{};
    TreeNode* current = root;
    while(current)
    {
        if(current->val > node->val)
        {
            current = current->left;
        }
        else if(current->val < node->val)
        {
            predecessor = current;
            current = current->right;
        }
        else
        {
            return predecessor;
        }
    }
    return nullptr;
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
void BST<T>::InOrder(TreeNode* node)
{
    if(!node) return;
    InOrder(node->left);
    std::cout << node->val << " ";
    InOrder(node->right);
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
int BST<T>::getHeight(TreeNode* node)
{
    if(!node) return 0;
    int left = getHeight(node->left);
    int right = getHeight(node->right);
    return std::max(left,right) + 1;
}