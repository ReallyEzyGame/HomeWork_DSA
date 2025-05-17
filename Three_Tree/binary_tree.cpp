#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

/*
        14/05/2025, Create file binary_tree.cpp: definition for all functions
        14/05/2025, Complete and Testing all Functions
*/

//  ----------------------- DATA STRUCTURE -------------------------
typedef struct NODE
{
    int key;
    NODE *p_left, *p_right;
} NODE;

// ------------------------ FUNCTION DECLEAREATOIN -----------------------
NODE *createNode(int data);
vector<int> NLR(NODE *pRoot);
vector<int> LNR(NODE *pRoot);
vector<int> LRN(NODE *pRoot);
vector<vector<int>> LevelOrder(NODE *pRoot);
int countNode(NODE *pRoot);
int sumNode(NODE *pRoot);
int heightNode(NODE *pRoot, int value);
int Level(NODE *pRoot, NODE *p);
int countLeaf(NODE *pRoot);

// -------------------------- FUNCTION DEFINITION ---------------------------
NODE *createNode(int data)
{
    NODE *add = new NODE;
    add->key = data;
    add->p_left = nullptr;
    add->p_right = nullptr;

    return add;
}

// Pre-order Treversal in Binary Tree
vector<int> NLR(NODE *pRoot)
{
    vector<int> Node_list;

    // Empty Tree
    if (pRoot == nullptr)
    {
        return Node_list;
    }

    stack<NODE *> order; // Save node hasn't visist
    order.push(pRoot);

    // Preorder Traversal
    while (!order.empty())
    {
        NODE *node = order.top();
        order.pop();
        Node_list.push_back(node->key);

        if (node->p_right != nullptr)
            order.push(node->p_right);
        if (node->p_left != nullptr)
            order.push(node->p_left);
    }

    return Node_list;
}
// Inorder - Traversal a on Binary Tree
vector<int> LNR(NODE *pRoot)
{
    vector<int> result;
    // Empty case
    if (pRoot == nullptr)
        return result;
    // Get the Node on the p_left brnach
    vector<int> p_left_branch = LNR(pRoot->p_left);
    for (int x : p_left_branch)
        result.push_back(x);
    // Get the Node on the pRoot
    result.push_back(pRoot->key);
    // Get the Node on the p_right branch
    vector<int> p_right_branch = LNR(pRoot->p_right);
    for (int x : p_right_branch)
        result.push_back(x);

    return result;
}
// Post - Traversal on a Binary Tree
vector<int> LRN(NODE *pRoot)
{
    vector<int> result;

    // Empty case
    if (pRoot == nullptr)
        return result;

    // Get the Node on the p_left brnach
    vector<int> p_left_branch = LRN(pRoot->p_left);
    for (int x : p_left_branch)
        result.push_back(x);

    // Get the Node on the p_right branch
    vector<int> p_right_branch = LRN(pRoot->p_right);
    for (int x : p_right_branch)
        result.push_back(x);

    // Get the Node on the pRoot
    result.push_back(pRoot->key);

    return result;
}
// Level Order Traversal on a Binary Tree
vector<vector<int>> LevelOrder(NODE *pRoot)
{
    vector<vector<int>> result;
    // Empty Tree
    if (pRoot == nullptr)
        return result;
    // Set of Node in Each Level
    queue<NODE *> node_line;
    // Get the first node
    node_line.push(pRoot);

    while (!node_line.empty())
    {
        vector<int> level;
        int size = node_line.size();
        while (size > 0)
        {
            NODE *node = node_line.front();
            node_line.pop();
            // get the next level
            if (node->p_left != nullptr)
                node_line.push(node->p_left);
            if (node->p_right != nullptr)
                node_line.push(node->p_right);
            // get the result of the current level
            level.push_back(node->key);
            --size;
        }
        result.push_back(level);
    }
    return result;
}
// the Number of Node in the Binary Tree
int countNode(NODE *pRoot)
{
    int total = 0;
    // Empty case
    if (pRoot == nullptr)
        return total;
    // Count the Node on the p_left brnach
    total += countNode(pRoot->p_left);
    // count the pRoot
    total += 1;
    // count the Node on the p_right branch
    total += countNode(pRoot->p_right);

    return total;
}

int sumNode(NODE *pRoot)
{
    int total = 0;
    // Empty case
    if (pRoot == nullptr)
        return total;
    // Count the Node on the p_left brnach
    total += sumNode(pRoot->p_left);
    // count the pRoot
    total += pRoot->key;
    // count the Node on the p_right branch
    total += sumNode(pRoot->p_right);

    return total;
}

// Get the height of a Current node
int maxDepth(NODE *pRoot, int depth = 0, int max = 0)
{
    if (pRoot->p_left != nullptr)
        return maxDepth(pRoot->p_left, depth + 1, max);
    if (pRoot->p_right != nullptr)
        return maxDepth(pRoot->p_right, depth + 1, max);

    return (depth > max) ? max = depth : max;
}
// Return the height of a Specific Node, if no Node was Found return -1
int heightNode(NODE *pRoot, int value)
{
    if (pRoot == nullptr)
        return -1; // Empty Tree
    int p_left = heightNode(pRoot->p_left, value);
    int p_right = heightNode(pRoot->p_right, value);

    if (value == pRoot->key)
        return maxDepth(pRoot);
    return (p_left > p_right) ? p_left : p_right;
}

int Level(NODE *pRoot, NODE *p)
{
    // Empty Tree
    if (pRoot == nullptr)
        return -1;

    int level_cnt = 0;
    queue<NODE *> level;
    // Push the first node to make sure the queue has node
    level.push(pRoot);
    // Level Order - Traversal
    while (!level.empty())
    {
        int size = level.size();
        while (size > 0)
        {
            // Check each node in the same level
            NODE *tmp = level.front();
            level.pop();
            if (tmp == p)
                return level_cnt;
            // get the next level
            if (tmp->p_left != nullptr)
                level.push(tmp->p_left);
            if (tmp->p_right != nullptr)
                level.push(tmp->p_right);

            --size;
        }
        level_cnt++;
    }
    return -1; // Cannot find such node
}
// Count and return the total leaf node of a tree
int countLeaf(NODE *pRoot)
{
    // Empty Tree
    if (pRoot == nullptr)
        return -1;

    queue<NODE *> level;
    // Push the first node to make sure the queue has node
    level.push(pRoot);
    int leaf_cnt;
    // Level Order - Traversal
    while (!level.empty())
    {
        vector<int> list; // Contains nodes of each level
        int size = level.size();
        int level_cnt = size; // Count nodes of each level
        while (size > 0)
        {
            // Check each node in the same level
            NODE *tmp = level.front();
            level.pop();
            // get the next level
            if (tmp->p_left != nullptr)
                level.push(tmp->p_left);
            if (tmp->p_right != nullptr)
                level.push(tmp->p_right);

            --size;
        }
        leaf_cnt = level_cnt;
    }
    return leaf_cnt;
}
