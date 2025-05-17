#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;

/*
        14/05/2025, Create the File & Start Initialize functions
        15/05/2025, Fix all the bug and continue Implement functions from Remove() function
        15/05/2025, Complete all functions and testing
*/
// ------------------------------ Data Structure -------------------------
struct NODE
{
    int key;
    NODE *p_left, *p_right;
};

// ------------------------------ Initialize Functions --------------------
NODE *Search(NODE *pRoot, int x);
void Insert(NODE *&pRoot, int x);
void Remove(NODE *&pRoot, int x);
NODE *createTree(int a[], int n);
void removeTree(NODE *&pRoot);
int Height(NODE *pRoot);
int countLess(NODE *pRoot, int x);
int countGreater(NODE *pRoot, int x);
bool isBST(NODE *pRoot);
bool isFullBST(NODE *pRoot);

// -------------------------------- Fucntion Definition --------------------
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
// Create a New Node
NODE *createNode(int data)
{
    NODE *add = new NODE;
    add->key = data;
    add->p_left = nullptr;
    add->p_right = nullptr;

    return add;
}
// Searching  for a Node
// Return the Node* node with such value
NODE *Search(NODE *pRoot, int x)
{
    // Empty Tree
    if (pRoot == nullptr)
        return nullptr;

    if (pRoot->p_left != nullptr && x < pRoot->key)
        return Search(pRoot->p_left, x);
    if (pRoot->p_right != nullptr && x > pRoot->key)
        return Search(pRoot->p_right, x);
    if (x == pRoot->key)
        return pRoot;

    return nullptr; // Cannot find Node with such value
}
// Insert a Node to the Binary Tree
void Insert(NODE *&pRoot, int x)
{
    // Insert to an Empty Tree
    if (pRoot == nullptr)
    {
        NODE *add = createNode(x);
        pRoot = add;
        return;
    }

    if (x < pRoot->key)
    {
        // Left already occured, moves to  the next Node to Insert
        if (pRoot->p_left != nullptr)
            Insert(pRoot->p_left, x);
        // Add new Node to the Left
        else
        {
            NODE *add = createNode(x);
            pRoot->p_left = add;
        }
    }
    if (x > pRoot->key)
    {
        // Right is already Occurs, moves  to the next Node to Insert
        if (pRoot->p_right != nullptr)
            Insert(pRoot->p_right, x);
        // Add new Node to the Right
        else
        {
            NODE *add = createNode(x);
            pRoot->p_right = add;
        }
    }
    // If there is Node with such value x then do nothing
    return;
}
// Remove a Node with with the specific given value
void Remove(NODE *&pRoot, int x)
{
    // Empty Tree
    if (pRoot == nullptr)
        return;

    // Move to the delete node
    stack<NODE *> stack_node; // Contains the path  to the node
    NODE *del = pRoot;
    while (del != nullptr && del->key != x)
    {
        if (x < del->key)
        {
            stack_node.push(del);
            del = del->p_left;
        }
        else if (x > del->key)
        {
            stack_node.push(del);
            del = del->p_right;
        }
        else
            break; // found the delete node
    }
    if (del == nullptr)
        return; // No Node with the Key value was found

    // Delete the del node  base on the number of its child node
    switch ((del->p_left != nullptr) + (del->p_right != nullptr))
    {
    case 0:
        // Delete the leaf node
        if (!stack_node.empty())
        {
            (stack_node.top()->p_left == del) ? stack_node.top()->p_left = nullptr : stack_node.top()->p_right = nullptr;
            delete del;
        }
        // Delete the Root node
        else
        {
            delete pRoot;
            pRoot = nullptr;
        }
        break;
    case 1:
    {
        // Del node is root node
        if (stack_node.empty())
        {
            pRoot = (del->p_left != nullptr) ? del->p_left : del->p_right;
            delete del;
        }
        // Otherwise
        else
        {
            // Relink the del's parent node with del's child
            NODE *child = (del->p_left != nullptr) ? del->p_left : del->p_right;
            (stack_node.top()->p_left == del) ? stack_node.top()->p_left = child : stack_node.top()->p_right = child;
            delete del;
        }
        break;
    }
    default:
    {
        // Get the right most children on the left branch
        NODE *rightmost = del->p_left;
        while (rightmost->p_right)
        {
            stack_node.push(rightmost);
            rightmost = rightmost->p_right;
        }

        // Delete the child node instead of del node
        int replace = rightmost->key;
        Remove(stack_node.top(), replace);
        del->key = replace;
        break;
    }
    }
    return;
}
// Create a Binary Search tree from an array
NODE *createTree(int a[], int n)
{
    // Empty input
    if (n < 0) return nullptr;

    NODE* pRoot = createNode(a[0]);
    int index = 1;
    while  (index <  n)
    {
        Insert(pRoot, a[index]);
        index++;
    }
    return pRoot;
}
// Remove Entire Tree from the giving node
void removeTree(NODE *&pRoot)
{
    // Empty Tree
    if (pRoot == nullptr) return;

    // Using Post-Order to delete each node
    if (pRoot->p_left != nullptr) removeTree(pRoot->p_left);
    if (pRoot->p_right != nullptr) removeTree(pRoot->p_right);
    // Isolate each node and delete it
    pRoot->p_left = nullptr;
    pRoot->p_right =  nullptr;
    delete pRoot; pRoot = nullptr;
}
// Find the Height of a Binary Search Tree
int Height(NODE *pRoot)
{
    // Empty Tree
    if (pRoot == nullptr) return -1;

    int left_height = 0, right_height = 0;      // the height of the left branch & the right branch
    // get the height of left & right branch
    if (pRoot->p_left) left_height += Height(pRoot->p_left)+1;
    if (pRoot->p_right) right_height += Height(pRoot->p_right)+1;

    return (left_height > right_height)  ? left_height: right_height;
}
// Count Number of Node in the Tree Smaller than a Given value
// If a Node has key smaller than the given value then cnt the node and both left & right branch(since node has key < given value)
// so there can still have value smaller than on the right branch
// If the node is greater than then just go to the left
// Other wise count the node it self and the left branch
int countLess(NODE *pRoot, int x)
{
    // Empty Tree
    if (pRoot == nullptr) return 0;
    
    int cnt = 0;
    // Cnt node on both branch
    if (pRoot->key < x)
    {
        // count the current node
        cnt++;
        // count on left & right branch
        cnt  += countLess(pRoot->p_left, x);
        cnt += countLess(pRoot->p_right, x);
    }
    // Only cnt node on the left
    else cnt += countLess(pRoot->p_left,x);

    return cnt;
}
// Same  Logic with the CountLess() but only check on branch with nodes have key > given value
int countGreater(NODE *pRoot, int x)
{
    // Empty Case
    if (pRoot == nullptr) return 0;

    int cnt = 0;
    if (pRoot->key  > x)
    {
        cnt++;  // Count the current node
        // There is still vlaue > x in both branch
        cnt  += countGreater(pRoot->p_left, x);
        cnt += countGreater(pRoot->p_right, x);
    }
    // Only right brach has value > x
    else  cnt += countGreater(pRoot->p_right, x);

    return cnt;
}

// check if a Tree is a Binary Search Tree
// time complexity:  O(n), space complexity O(n)
// another solution that has time complexity: O(n), space complexity: O(1)
bool isBST(NODE* pRoot)
{
    // Empty  Tree
    if (pRoot == nullptr) return 0;

    vector <int> key_list = LNR(pRoot);
    int index = 1;
    while (index < key_list.size())
    {
        if (key_list[index-1] >= key_list[index]) return false;
        index++;
    }
    return true;
}
// Check ifa Tree is a Binary Seach Tree is a FULL BST
bool isFullBST(NODE *pRoot)
{
    if (pRoot == nullptr) return false;
    if (!isBST(pRoot)) return false;    // Check if it's a BST Tree first

    int height = Height(pRoot);         // Get the high of the Tree
    // Get all the Node in the height - 1 level
    queue <NODE*> queue_node; queue_node.push(pRoot);
    int cnt = 0;
    while (cnt < height - 1)
    {
        int size = queue_node.size();
        if (size != pow(2,cnt)) return false;   // The Level has number of node != 2^x ==> not a full binary tree
        // Get all node of each level
        while (size > 0)
        {
            NODE* node = queue_node.front(); queue_node.pop();
            // push the node of the next level  into the queue
            if (node->p_left != nullptr) queue_node.push(node->p_left);
            if (node->p_right != nullptr) queue_node.push(node->p_right);

            --size;
        }
        cnt++;
    }

    // Check if all the node in level  height -1 has 0|2 childs
    while (!queue_node.empty())
    {
        NODE* tmp = queue_node.front(); queue_node.pop();
        if ((tmp->p_left != nullptr) != (tmp->p_right != nullptr)) return false;
    }

    return true;
}
