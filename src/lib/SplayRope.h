#ifndef SPLAY_ROPE
#define SPLAY_ROPE

#include <cstdio>
#include <string>
#include <iostream>
#include <stack>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Node {
public:
    char content;// the character this node represents
    long size; // size of the subtree of this node
    Node *left, *right, *parent;

    Node(char content, long size, Node* left, Node* right, Node* parent) {
        this->content = content;
        this->size = size;
        this->left = left;
        this->right = right;
        this->parent = parent;
    }
    void setContent(char content) {
        this->content = content;
    }
    void setSize(long size) {
        this->size = size;
    }
    void addSize(long addSize) {
        this->size += addSize;
    }
    char getContent() {
        return this->content;
    }
    int getSize() {
        return this->size;
    }
};

class SplayRope {
private:
    string s;
    Node* root;

public:
    SplayRope();
    SplayRope(const string& s);
    void updateCurNodeInformation(Node* v);
    void rotatefirst(Node* v);
    void rotatesecond(Node* v);
    void rotate(Node* node1, Node* node2);
    void splayAtNode(Node*& root, Node* v);
    Node* findNodeWithPos(Node*& root, int leftNum);
    void splitAtPos(Node* root, int c, Node*& left, Node*& right);
    Node* append(Node* left, Node* right);
    string substring(Node*& root, int startindex, int endindex);
    void remove(Node*& root, int startindex, int endindex);
    void insert(Node*& root, int k, Node*& subString);
    string inorder(Node* root);
    string toString();
    Node*& getRoot();
    void setRoot(Node* newRoot);
};

#endif