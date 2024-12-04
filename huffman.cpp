#include <iostream>
using namespace std;

// Definir um node
struct Node{
    int freq;
    Node* left;
    Node* right;

    Node(int new_freq)
    {
        freq = new_freq;
        left = nullptr;
        right = nullptr;
    }
};

/*
n = |C|
Q = C
for i = 1 to n-1
    allocate a new node z
    x = extract_min(Q)
    y = extract_min(Q)
    z.left = x
    z.right = y
    z.freq = x.freq + y.freq
    insert(Q, z)
return extract_min(Q)
*/

int main(){
    // Create
    Node* head = new Node(77);
    head->right = new Node(43);
    head->left = new Node(34);

    // Print the original list
    cout << head->freq << "\n";
    cout << head->right->freq << "\n";
    cout << head->left->freq << "\n";

    return 0;
}
