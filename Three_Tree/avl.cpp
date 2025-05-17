#include <iostream>
#include <stack>
#include <queue>

#define LH -1 // Left Higher
#define EH 0  // Equal Height
#define RH 1  // Right Higher
using namespace std;
/*
        15/05/2025, Created the file and  Initialized all Functions
                    Definition to Insert() function
        16/05/2025, Fix bug in the Insert() function
        17/05/2025, Fix bug in the Insert() function
*/
// ------------------------- Data Struture -------------------------------------
struct NODE
{
    int key, height;
    NODE *p_left, *p_right;
};

// ------------------------- Initialize Functions -------------------------------
NODE *createNode(int data);
void Insert(NODE *&pRoot, int x);
void Remove(NODE *&pRoot, int x);
bool isAVL(NODE *pRoot);

vector<vector<NODE *>> LevelOrder(NODE *pRoot);
vector<int> LNR(NODE *pRoot);
bool isBST(NODE *pRoot);
// ------------------------- Other Functions
int max(int X, int Y)
{
    return (X > Y) ? X : Y;
}

bool isBST(NODE *pRoot)
{
    // Empty  Tree
    if (pRoot == nullptr)
        return 0;

    vector<int> key_list = LNR(pRoot);
    int index = 1;
    while (index < key_list.size())
    {
        if (key_list[index - 1] >= key_list[index])
            return false;
        index++;
    }
    return true;
}

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

// ------------------------- Functions Definitions ------------------------------
// Rotates & Balance Tree Functions
// Rotate the tree to the left when the tree unbalance Right
void Left_Rotate(NODE *&TREE)
{
    NODE *rotate = TREE->p_right;

    TREE->p_right = rotate->p_left;
    rotate->p_left = TREE;
    TREE = rotate;
}
// Rotate the Tree to the right when the tree unbalance Left
void Right_Rotate(NODE *&TREE)
{
    NODE *rotate = TREE->p_left;

    TREE->p_left = rotate->p_right;
    rotate->p_right = TREE;
    TREE = rotate;
}
// Double Rotate: Left Right when the Tree is Unbalance on the Left-Right branch
void LeftRight_Rotate(NODE *&TREE)
{
    NODE *parent = TREE->p_left; // rotate's parent node
    NODE *rotate = parent->p_right;

    parent->p_right = rotate->p_left;
    TREE->p_left = rotate->p_right;

    rotate->p_left = parent;
    rotate->p_right = TREE;

    TREE = rotate;
}
// Double Rotate: Right Left  when the Tree is Unbalance on the Right-Left branch
void RightLeft_Rotate(NODE *&TREE)
{
    NODE *parent = TREE->p_right;
    NODE *rotate = parent->p_left;

    parent->p_left = rotate->p_right;
    TREE->p_right = rotate->p_left;

    rotate->p_left = TREE;
    rotate->p_right = parent;

    TREE = rotate;
}
// ------------------------- Balance an AVL Tree
// Balance the Left Tree when the Left Tree is Higher than the Right
void Left_Balance(NODE *&TREE)
{
    NODE *left_child = TREE->p_left;

    int balance_factor = (left_child->p_right != nullptr) ? left_child->p_right->height : -1;
    balance_factor -= (left_child->p_left != nullptr) ? left_child->p_left->height : -1;
    // Left-Left unbalance
    if (balance_factor == LH)
    {
        TREE->height -= 2;
        Right_Rotate(TREE);
    }
    // Left-Right unbalance
    else
    {
        NODE *right_grandchild = left_child->p_right;
        TREE->height -= 2;
        right_grandchild->height += 1;
        left_child->height -= 1;
        LeftRight_Rotate(TREE);
    }
}
// Balanace the Right Tree when the Right Tree is Higher than the Left
void Right_Balance(NODE *&TREE)
{
    NODE *right_child = TREE->p_right;

    int right_child_factor = (right_child->p_right != nullptr) ? right_child->p_right->height : -1;
    right_child_factor -= (right_child->p_left != nullptr) ? right_child->p_left->height : -1;
    if (right_child_factor == RH)
    {
        TREE->height -= 2;
        Left_Rotate(TREE);
    }
    else
    {
        NODE *left_grandchild = right_child->p_left;
        TREE->height -= 2;
        left_grandchild->height += 1;
        right_child->height -= 1;
        RightLeft_Rotate(TREE);
    }
}
// --------------------------------------------------------------------------------
NODE *createNode(int data)
{
    NODE *add = new NODE;
    add->key = data;
    add->height = 0;
    add->p_left = add->p_right = nullptr;

    return add;
}

//  Insert an Node to an AVL tree
void Insert(NODE *&pRoot, int x)
{
    // Empty Tree
    if (pRoot == nullptr)
    {
        NODE *add = createNode(x);
        pRoot = add;
        return;
    }
    // use a stack to contains the path( for adjust the height of each node in the path)
    stack<NODE *> stack_node;
    NODE *parent = pRoot;
    while (parent != nullptr)
    {
        stack_node.push(parent);
        if (x < parent->key)
            parent = parent->p_left;
        else if (x > parent->key)
            parent = parent->p_right;
        else
            return; // Tree already has this value
    }

    //  Add a new Node to the Tree
    NODE *add = createNode(x);

    if (x < stack_node.top()->key)
        stack_node.top()->p_left = add;
    else
        stack_node.top()->p_right = add;

    int height = 0; // Adjust the height of the path bottom up
    while (!stack_node.empty())
    {
        NODE *parent = stack_node.top();
        stack_node.pop();
        // Adjust the height of each node
        // Only adjust  if the new Node added make the tree taller
        if (height >= parent->height)
            parent->height = ++height;
        else
            break; // the Tree is balance, no need to Adjust further
        // Rotate the Unbalance part
        int left_height = (parent->p_left != nullptr) ? parent->p_left->height : -1;
        int right_height = (parent->p_right != nullptr) ? parent->p_right->height : -1;

        if (right_height - left_height == 2)
            Right_Balance(parent);
        else if (right_height - left_height == -2)
            Left_Balance(parent);
        else
        {
            continue;
        } // the Tree is still balance

        // Relink if there is rotate
        if (!stack_node.empty())
            (parent->key < stack_node.top()->key) ? stack_node.top()->p_left = parent : stack_node.top()->p_right = parent;
        else
            pRoot = parent;

        --height; // Balance reduces the height by 1
    }
}

bool isAVL(NODE *pRoot)
{
    // Empty Tree
    if (pRoot == nullptr)
        return false;
    // Check if the tree is BST tree
    if (!isBST(pRoot))
        return false;
    // check if the different of the high on both branch is less than 2
    queue<NODE *> queue_node;
    queue_node.push(pRoot);
    while (!queue_node.empty())
    {
        NODE *parent = queue_node.front();
        queue_node.pop();

        // Default for  Empty Tree
        int left_height = -1;
        int right_height = -1;
        // Get the Height & Check  for the subtree on Both branch
        if (parent->p_left != nullptr)
        {
            left_height = parent->p_left->height;
            queue_node.push(parent->p_left);
        }
        if (parent->p_right != nullptr)
        {
            right_height = parent->p_right->height;
            queue_node.push(parent->p_right);
        }

        // Check if the tree is balanace or not
        if (abs(right_height - left_height) >= 2)
            return false; // Unbalance Sub-Tree
    }
    return true;
}
vector<vector<NODE *>> LevelOrder(NODE *pRoot)
{
    vector<vector<NODE *>> result;
    // Empty Tree
    if (pRoot == nullptr)
        return result;
    // Set of Node in Each Level
    queue<NODE *> node_line;
    // Get the first node
    node_line.push(pRoot);

    while (!node_line.empty())
    {
        vector<NODE *> level;
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
            level.push_back(node);
            --size;
        }
        result.push_back(level);
    }
    return result;
}

// Remove a Node from a AVL tree
void Remove(NODE *&pRoot, int x)
{
    // Empty Tree
    if (pRoot == nullptr)
        return;

    // Find the Node, remember the path by put it to the stack
    stack<NODE *> ancestor; // Ancestor of the Remove node
    NODE *node = pRoot;
    while (node != nullptr)
    {
        ancestor.push(node);

        if (x < node->key)
            node = node->p_left;
        else if (x > node->key)
            node = node->p_right;
        else
            break; // Found the Remove Node
    }
    if (node == nullptr)
        return; // No Node with such value was found

    // Remove the Node, save the height
    ancestor.pop();         // pop the del node out
    switch ((node->p_left != nullptr) + (node->p_right != nullptr))
    {
    // Leaf Node/Root
    case 0:
    {
        // Leaf Node
        if (!ancestor.empty())
            (node->key < ancestor.top()->key) ? ancestor.top()->p_left = nullptr : ancestor.top()->p_right = nullptr;
        // Root Node
        else
            pRoot = nullptr;
        delete node;
        break;
    }
    //  Remove node has 1 child
    case 1:
    {
        NODE *child = (node->p_left != nullptr) ? node->p_left : node->p_right;
        if (!ancestor.empty())
            (child->key < ancestor.top()->key) ? ancestor.top()->p_left = child : ancestor.top()->p_right = child;
        else
            pRoot = child;
        delete node;
        break;
    }
    // Remove node has 2 childs
    case 2:
    {
        // Get the Right Most  node on the Left branch as the Replace node
        ancestor.push(node);
        NODE *replace = node->p_left; // Remove the replace Node instead

        while (replace->p_right)
        {
            ancestor.push(replace);
            replace = replace->p_right;
        }
        // Remove replace node
        int  tmp = replace->key;
        ancestor.top()->p_right = replace->p_left;
        node->key = tmp;
        delete replace;
        break;
    }
    }

    // Adjust the height & Rebalance the Tree
    // If the height of the parent node still depend on the delete node continue to  balance
    // the Height  only reduce at most 1 since these only 1 node is removed each time

    while (!ancestor.empty())
    {
        
        // Adjust the Heigth of the Ancestor Node
        NODE* parent = ancestor.top(); ancestor.pop();
        // Compare the high of the left branch & the right branch
        int left_height = (parent->p_left != nullptr) ? parent->p_left->height:-1;
        int right_height =  (parent->p_right != nullptr) ? parent->p_right->height:-1;

        parent->height = max(left_height,right_height) +1;

        // Removes Node mades the Height of nodes change
        if (abs(right_height - left_height))
        {
            // The sub-Tree is unbalance on the right Branch
            if (right_height - left_height == 2)
                Right_Balance(parent);
            // The sub-Ttee is unbalance on the left Branch
            else if (right_height - left_height == -2)
                Left_Balance(parent);
            else continue;

            // Relink after Rotation
            if (!ancestor.empty())
                (parent->key < ancestor.top()->key) ? ancestor.top()->p_left = parent: ancestor.top()->p_right = parent;
            else pRoot = parent;
        }
        // Continue to check further ancestor
        else continue;

        // Check if Unbalance Occurs
        // If Unbalance then ReBalance the Tree
        // If not then stop since the Tree still Balance
    }
}

int main()
{
    NODE *TREE = createNode(50);
    Insert(TREE, 10);
    Insert(TREE, 20);
    Insert(TREE, 5);
    Insert(TREE, 60);
    Insert(TREE, 70);
    Insert(TREE, 30);
    Insert(TREE, 40);
    Insert(TREE, 15);
    Insert(TREE, 16);
    Insert(TREE, 4);
    Insert(TREE, 3);
    Insert(TREE, 1);
    Insert(TREE, 0);


    vector<vector<NODE *>> level = LevelOrder(TREE);
    for (vector<NODE *> list : level)
    {
        for (NODE *x : list)
            cout << x->key << " -- " << x->height << "\t\t";
        cout << endl;
    }
    cout << endl;

    Remove(TREE, 20); Remove(TREE, 3);
    Remove(TREE, 0); Remove(TREE, 16);

    level = LevelOrder(TREE);
    for (vector<NODE *> list : level)
    {
        for (NODE *x : list)
            cout << x->key << " -- " << x->height << "\t\t";
        cout << endl;
    }
    cout << endl;

    if (isAVL(TREE))
        cout << "The tree is an AVL tree\n";
    else
        cout << "The Tree is not an AVL tree\n";
}