//Name: Amit
//Roll Number: 25/DA/012
//11. Write a program to implement Huffman Coding for data compression.
#include <iostream>
#include <queue>
using namespace std;

// Node of Huffman Tree
struct Node
{
    char data;
    int frequency;

    Node *left;
    Node *right;

    Node(char d, int f)
    {
        data = d;
        frequency = f;
        left = NULL;
        right = NULL;
    }
};

// Compare nodes based on frequency
struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->frequency > b->frequency;
    }
};

// Generate Huffman Codes
void generateCodes(Node *root, string code)
{
    if (root == NULL)
        return;

    // Leaf node
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << "\t" << root->frequency
             << "\t" << code << endl;
        return;
    }

    generateCodes(root->left, code + "0");
    generateCodes(root->right, code + "1");
}

int main()
{
    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    priority_queue<Node *, vector<Node *>, Compare> pq;

    cout << "Enter character and frequency:\n";

    for (int i = 0; i < n; i++)
    {
        char ch;
        int freq;

        cin >> ch >> freq;

        Node *newNode = new Node(ch, freq);
        pq.push(newNode);
    }

    // Build Huffman Tree
    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();

        Node *right = pq.top();
        pq.pop();

        Node *newNode = new Node('$',
                                 left->frequency + right->frequency);

        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    Node *root = pq.top();

    cout << "\nHuffman Codes:\n";
    cout << "Character\tFrequency\tCode\n";

    generateCodes(root, "");

    return 0;
}