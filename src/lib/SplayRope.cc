#include "SplayRope.h"
#include <stack>

/**
 * Constructor without parameter
 **/ 
SplayRope::SplayRope() {
    root = NULL;
};

/**
 * Constructor with parameter string
 **/ 
SplayRope::SplayRope(const string& initials) {
    root = NULL;
    for (char c : initials) {
        root = append(root, new Node(c, 1, NULL, NULL, NULL));
    }
}

/**
 * Rotating operation used to maintain the balance of the tree
 * Time complexity: O(1)
 **/ 
void SplayRope::rotatefirst(Node* node) {
    Node* parent = node->parent;
    Node* grandparent = node->parent->parent;
    if (parent->left == node) {
        parent->left = node->right;
        node->right = parent;
    } else {
        parent->right = node->left;
        node->left = parent;
    }
    if (parent != NULL) {
        parent->size = 1;
        if (parent->left != NULL) {
            parent->size += parent->left->size;
            parent->left->parent = parent;
        }
        if (parent->right != NULL) {
            parent->size += parent->right->size;
            parent->right->parent = parent;
        }
    }
    if (node != NULL) {
        node->size = 1;
        if (node->left != NULL) {
            node->size += node->left->size;
            node->left->parent = node;
        }
        if (node->right != NULL) {
            node->size += node->right->size;
            node->right->parent = node;
        }
    }
    node->parent = grandparent;
    if (grandparent != NULL && grandparent->left == parent) {
        grandparent->left = node;
    } else if (grandparent != NULL) {
        grandparent->right = node;
    }
}

/**
 * Rotating operation used to maintain the balance of the tree
 * Time complexity: O(1)
 **/ 
void SplayRope::rotatesecond(Node* node) {
    Node* parent = node->parent;
    if (parent == NULL) return;
    Node* grandparent = parent->parent;
    if (grandparent == NULL) return;
    if ((grandparent->left == parent && parent->left == node) || (grandparent->right == parent && parent->right == node)) {
        rotatethird(parent, node);
    } else {
        rotatethird(node, node);
    }
}

/**
 * Splay operation at the node "*node"
 * "*node" becomes the new root after this operation
 * Time complexity: O(1)
 **/ 
void SplayRope::splayAtNode(Node*& root, Node* node) {
    if (node == NULL) return;
    while (node->parent != NULL) {
        if (node->parent->parent != NULL) {
            rotatesecond(node);
        } else {
            rotatefirst(node);
            break;
        }
    }
    root = node;
}

/**
 * split the string at index "c", form two strings with root of "*left" and "*right"
 * Time complexity: O(log(N))
 **/ 
void SplayRope::splitAtPos(Node* root, int pos, Node*& left, Node*& right) {
    Node* p = root;
    while (p != NULL) {
        if (pos == ((p->left == NULL ? 0 : p->left->size) + 1)) {
            break;
        } else if (pos <= (p->left == NULL ? 0 : p->left->size)) {
            p = p->left;
        } else if (pos >= ((p->left == NULL ? 0 : p->left->size) + 2)) {
            pos -= (p->left == NULL ? 0 : p->left->size) + 1;
            p = p->right;
        }
    }
    splayAtNode(root, p);
    right = p;
    splayAtNode(root, right);
    if (right == NULL) {
        left = root;
    } else {
        if (right->left != NULL) right->left->parent = NULL;
        Node* temp = right->left;
        right->left = NULL;
        left = temp;
        if (left != NULL) {
            left->size = 1;
            if (left->left != NULL) {
                left->size += left->left->size;
                left->left->parent = left;
            }
            if (left->right != NULL) {
                left->size += left->right->size;
                left->right->parent = left;
            }
        }
        if (right != NULL) {
            right->size = 1;
            if (right->left != NULL) {
                right->size += right->left->size;
                right->left->parent = right;
            }
            if (right->right != NULL) {
                right->size += right->right->size;
                right->right->parent = right;
            }
        }
    }
}

/**
 * append string b with root "*right" to string a with root "*left"
 * Time complexity: O(log(N))
 **/ 
Node* SplayRope::append(Node* left, Node* right) {
    if (left == NULL || right == NULL) return left == NULL ? right : left;
    Node* p = right;
    while (p->left != NULL) p = p->left;
    splayAtNode(right, p);
    right->left = left;
    if (right != NULL) {
        right->size = 1;
        if (right->left != NULL) {
            right->size += right->left->size;
            right->left->parent = right;
        }
        if (right->right != NULL) {
            right->size += right->right->size;
            right->right->parent = right;
        }
    }
    return right;
}

/**
 * get the subtring from "startindex"(included) tp "endindex"(included)
 * Time complexity: O(log(N) + T)
 **/ 
string SplayRope::substring(Node*& root, int l, int r) {
    Node *left = NULL;
    Node *right = NULL;
    Node *middle = NULL;
    Node *temp = NULL;
    splitAtPos(root, r + 2, temp, right);
    splitAtPos(temp, l + 1, left, middle);
    string res = subtreeToString(middle);
    root = append(append(left, middle), right);
    return res;
}

/**
 * remove the subtring from "startindex"(included) tp "endindex"(included)
 * Time complexity: O(log(N) + T)
 **/ 
void SplayRope::remove(Node*& root, int l, int r) {
    Node *left = NULL;
    Node *right = NULL;
    Node *middle = NULL;
    Node *temp = NULL;
    splitAtPos(root, r + 2, temp, right);
    splitAtPos(temp, l + 1, left, middle);
    
    root = append(left, right);
}

/**
 * insert a substring into the current string at index "idx"
 * Time complexity: O(log(N) + T)
 **/ 
void SplayRope::insert(Node*& root, int pos, Node*& newNode) {
    Node* left = NULL;
    Node* right = NULL;
    splitAtPos(root, pos, left, right);
    Node* temp = append(left, newNode);
    root = append(temp, right);
}

/**
 * return the string represetation of the subtree with root "root"
 * Time complexity: O(log(N) + T)
 **/ 
string SplayRope::subtreeToString(Node* root) {
    if (root == NULL) return "";
    stack<Node*> st;
    Node* curr = root;
    string res("");
    while (curr != NULL || !st.empty()) {
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        res.push_back(curr->content);
        curr = curr->right;
    }
    return res;
}

/**
 * avoid using this function due to risk of stack overflow!!!!!
 * 
 * Recursively get the string representation of the tree with root "*root" 
 * Time complexity: O(log(N) + T)
 **/ 
void SplayRope::recursiveSubtreeToString(Node*& root, string &res) {
    if (root == NULL) return;
    recursiveSubtreeToString(root->left, res);
    res += root->content;
    recursiveSubtreeToString(root->right, res);
}

/**
 * return the string represetation of the current string
 * Time complexity: O(N)
 **/
string SplayRope::toString() {
    return subtreeToString(root);
}

/**
 * get the root of this SplayRope class
 * Time complexity: O(1)
 **/ 
Node*& SplayRope::getRoot() {
    return root;
}

/**
 * set the root of this SplayRope class
 * Time complexity: O(1)
 **/ 
void SplayRope::setRoot(Node* newRoot) {
    root = newRoot;
}

/**
 * Rotating operation used to maintain the balance of the tree
 **/ 
void SplayRope::rotatethird(Node* node1, Node* node2) {
    rotatefirst(node1);
    rotatefirst(node2);
}