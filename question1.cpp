#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
    int val; //root value
    Node* left; //point to left child
    Node* right;  //point to right child
    Node(int x) : val(x), left(nullptr), right(nullptr) {} //initiating the Node
};

Node* buildTree(const vector<int>& levelOrder) { // reference for the speed, const so LevelOrder won't be modified

    Node* root = new Node(levelOrder[0]); // assign root Node, value first thing in levelOrder
    vector<Node*> queue = {root}; // initiating the queue
    int i = 1; // part of the queue system

    while (i < levelOrder.size()) { // while still inputing
        Node* current = queue[0];  //point current to the item in queue[0]
        queue.erase(queue.begin()); //erase queue[0] relation with the item

        if (levelOrder[i] != -1) { // if next item not -1
            current->left = new Node(levelOrder[i]); // because Level-Ordered input, assign to left children 
            queue.push_back(current->left); // add in queue 
        }
        i++; // to reach to next item

        if (i < levelOrder.size() && levelOrder[i] != -1) { // if not next item not -1
            current->right = new Node(levelOrder[i]); // because Level-Ordered input, assign to right children 
            queue.push_back(current->right); // add in queue 
        }
        i++;// to reach to next item
    }

    return root; // root for diameterOfTree use
}

int diameterOfTree(Node* root, int& diameter) {
    if (!root) return 0; // 0 when reach the end of tree

    int leftHeight = diameterOfTree(root->left, diameter); //calculate the height of the left subtree
    int rightHeight = diameterOfTree(root->right, diameter); //calculate the height of the right subtree

    diameter = max(diameter, leftHeight + rightHeight); // caculate sum of the heights of the left and right subtrees

    return max(leftHeight, rightHeight) + 1;// Return the height of the current node + 1(itselfy)
}
int main() {
    vector<int> levelOrder = {1, 2, -1,-1, 3, 4, 5,  -1, -1, -1, 6, -1, 7,-1, 8 ,-1,9}; // use vector<int> to recive inputs
    
    Node* root = buildTree(levelOrder); //go to class Node

    int diameter = 0; //initiating diameter
    diameterOfTree(root, diameter); // to find diameter

    cout << "Diameter of the tree: " << diameter << endl;

    return 0;
}