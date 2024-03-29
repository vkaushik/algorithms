/* 
 * Given a binary tree, print out all of its root-to-leaf paths one per line.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

struct Node {
  int data;
  Node *left, *right;
};
Node* createNode(int data);
void printRootLeaf(Node *root);
void _printRootLeaf(Node *root, string pre);
void deleteTree(Node *root);
void levelOrderTraversal(Node *root);

int main() {
  Node *root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->left->right = createNode(5);
  levelOrderTraversal(root);
  printRootLeaf(root);
  deleteTree(root);
  return 0;
}

void printRootLeaf(Node *root) {
  string pre = "";
  _printRootLeaf(root, pre );
}

void _printRootLeaf(Node *root, string pre) {
  if(!root->left && !root->right) {
    cout << endl << pre << root->data << endl;
    return;
  }
  else {
    stringstream ss;
    ss << (root->data);
    pre += ss.str();
    cout << "pre " << pre;
    if(!(root->left))
      _printRootLeaf(root->left, pre);
    if(!(root->right))
      _printRootLeaf(root->right, pre);
  }
}

void deleteTree(Node *root) {

}

Node* createNode(int data) {
  Node* temp = new Node;
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

void levelOrderTraversal(Node *root) {
  cout << endl << "LevelOrder ";
  if(!root) return;
  queue<Node*> q;
  q.push(root);
  while(!q.empty()) {
    root = q.front();
    q.pop();
    cout << root->data << " ";
    if(root->left)
      q.push(root->left);
    if(root->right)
      q.push(root->right);
  }
  cout << endl;
}
