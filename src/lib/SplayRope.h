#ifndef SPLAY_ROPE
#define SPLAY_ROPE

#include <string>

using namespace std;

/**
 * Node class used to represent each character in the string.
 *
 * Attributes:
 * 1. content: the character this node represents
 * 2. size: size of the subtree of this node
 * 3. *left, *right, *parent: pointer to left child, right child, parent child
 * 
 **/
class Node {
public:
    char content;// the character this node represents
    long size; // size of the subtree of this node
    Node *left, *right, *parent; //pointer to left child, right child, parent child

    //constructor
    Node(char content, long size, Node* left, Node* right, Node* parent) {
        this->content = content;
        this->size = size;
        this->left = left;
        this->right = right;
        this->parent = parent;
    }

    //setters
    void setContent(char content) {
        this->content = content;
    }
    void setSize(long size) {
        this->size = size;
    }

    //increase the value of size by one
    void addSize(long addSize) {
        this->size += addSize;
    }

    //getters
    char getContent() {
        return this->content;
    }
    int getSize() {
        return this->size;
    }
};


/**
 * SplayRope class
 * 1. A tree like data structure constructed based on Splay Tree and Rope Data Structor
 * 2. Always keep balanced through three rotating operations
 * 
 * Attributes:
 * 1. *root: the root of this tree like data structure
 * 
 * Time complexity:
 * 1. setRoot: O(1)
 * 2. rotatefirst: O(1)
 * 3. rotatesecond: O(1)
 * 4. rotatethird: O(1)
 * 5. splayAtNode: O(log(N))           where N is the size of the tree
 * 6. splitAtPos: O(log(N))            where N is the size of the tree
 * 7. append: O(log(N))                where N is the size of the tree
 * 8. substring: O(log(N) + T)         where N is the size of the tree, T is the length of substring
 * 9. remove: O(log(N) + T)            where N is the size of the tree, T is the length of substring
 * 10. insert: O(log(N) + T)           where N is the size of the tree, T is the length of substring
 * 11. subtreeToString: O(log(N) + T)  where N is the size of the sub tree, T is the length of subtree
 * 12. toString: O(N)                  where N is the size of the tree
 * 13. getRoot: O(1)
 * 
 **/
class SplayRope {
private:
    Node *root;

public:
    SplayRope();
    SplayRope(const string& s);

    //Three different rotating operations used to maintain the balance of this SplayRope data structure
    void rotatefirst(Node* v);
    void rotatesecond(Node* v);
    void rotatethird(Node* node1, Node* node2);

    void splayAtNode(Node*& root, Node* v);//Splay operation on specific node "node".
    void splitAtPos(Node* root, int c, Node*& left, Node*& right);//split the string at index "c", form two strings with root of "*left" and "*right"
    Node* append(Node* left, Node* right);//append string b with root "*right" to string a with root "*left"
    string substring(Node*& root, int startindex, int endindex);//get the subtring from "startindex"(included) tp "endindex"(included)
    void remove(Node*& root, int startindex, int endindex);//remove the subtring from "startindex"(included) tp "endindex"(included)
    void insert(Node*& root, int idx, Node*& subString);//insert a substring into the current string at index "idx"
    string subtreeToString(Node* root);//return the string represetation of the subtree with root "root"
    void recursiveSubtreeToString(Node*& root, string &s);// avoid using this function due to risk of stack overflow
    string toString();//return the string represetation of the current string
    Node*& getRoot();//get the root of this SplayRope class
    void setRoot(Node* newRoot);//set the root of this SplayRope class
};

#endif