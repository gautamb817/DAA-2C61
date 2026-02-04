#include <iostream>
#include <queue>
#include <string>

using namespace std;


struct Node {
    char ch;
    int freq;
    Node *left;
    Node *right;
};


Node* createNode(char ch, int freq) {
    Node* node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}


struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};


void printCodes(Node* root, string code) {
    if (root == NULL)
        return;

    
    if (root->left == NULL && root->right == NULL) {
        cout << root->ch << "\t\t" << code << endl;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    char characters[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequencies[] = {5, 9, 12, 13, 16, 45};
    int N = 6;

    priority_queue<Node*, vector<Node*>, Compare> pq;

    
    for (int i = 0; i < N; i++) {
        pq.push(createNode(characters[i], frequencies[i]));
    }

    
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* merged = createNode('$', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }

    
    Node* root = pq.top();

    cout << "Character\tHuffman Code\n";
    printCodes(root, "");

    return 0;
}
