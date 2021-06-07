#include <iostream>
#include <functional>

struct Node
{
    int value;
    Node* left = nullptr;
    Node* right = nullptr;

    // Constructor
    Node() {};

    // Overloaded Constructor
    Node(int value) : value(value) {}

    // Overloaded Constructor
    Node(int value, Node* left, Node* right) : value(value), left(left), right(right) {}
};

void ForEachPreOrder(Node* n, std::function<void(Node*)> fn)
{
    if (n == nullptr)
        return;

    // Invoke the fn for each node
    fn(n);

    ForEachPreOrder(n->left, fn);
    ForEachPreOrder(n->right, fn);
}
void PrintNode(Node* n)
{
    if (n == nullptr)std::cout << "you fucking suck: " << std::endl;
    else  std::cout << n->value << ", ";
}

void PreOrderPrint(Node* n)
{
    if (n == nullptr)
        return;
    
    std::cout << n->value << std::endl;
    
    PreOrderPrint(n->left);
    PreOrderPrint(n->right);
}
void PostOrderPrint(Node* n)
{
    if (n == nullptr)
        return;

    PostOrderPrint(n->left);
    PostOrderPrint(n->right);

    std::cout << n->value << std::endl;
}
Node* Find(Node* n, int value)
{
    if (n == nullptr)return nullptr;
    if (value > n->value)return Find(n->right, value);
    if (value < n->value)return Find(n->left, value);
    return n;
    
}
void Insert(Node *&root, Node *nodeToInsert)
{
    if (root == nullptr) root = nodeToInsert;
    else if (nodeToInsert->value > root->value) Insert(root->right, nodeToInsert);
    else if (nodeToInsert->value < root->value) Insert(root->left, nodeToInsert);
}
Node* minValueNode(Node* node)
    {
        Node* currentNode = node;
        while (currentNode && currentNode->left != nullptr)
        {
            currentNode = currentNode->left;
        }
        return currentNode;
    }
Node* Remove(Node* root, Node* node)
{
    if (node == nullptr) return nullptr;
    if (node->value < root->value)
        root->left = Remove(root->left, node);
    else if (node->value > root->value)
        root->right = Remove(root->right, node);
    else
    {
        if (root->left == nullptr)
        {
            Node* temp = root->right;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node* temp = root->left;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->value = temp->value;
        root->right = Remove(root->right, temp);
    }
    return root;
}
int Height(Node *n)
{
    return 0;
}
int Depth(Node *root, Node *n)
{
    return 0;
}
int main(int argc, char** argv)
{

    Node* root = nullptr;
    Insert(root, new Node(6));
    Insert(root, new Node(9));
    Insert(root, new Node(2));
    Insert(root, new Node(1));
    Insert(root, new Node(8));
    Insert(root, new Node(15));
    Insert(root, new Node(13));
    Insert(root, new Node(11));
    Insert(root, new Node(18));

    ForEachPreOrder(root, PrintNode);
    std::cout << std::endl;
    Remove(root, Find(root, 9));

    ForEachPreOrder(root, PrintNode);

    return 0;
}