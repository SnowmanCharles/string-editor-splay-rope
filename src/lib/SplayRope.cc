#include "SplayRope.h"

SplayRope::SplayRope() {
    root = NULL;
};

SplayRope::SplayRope(const string& initials) {
    root = NULL;
    for (char c : initials) {
        root = append(root, new Node(c, 1, NULL, NULL, NULL));
    }
    this->s = initials;
}

void SplayRope::updateCurNodeInformation(Node* node) {
    if (node == NULL) return;
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

void SplayRope::rotatefirst(Node* node) {
    if (node == NULL || node->parent == NULL) return;
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
        updateCurNodeInformation(parent);
    }
    if (node != NULL) {
        updateCurNodeInformation(node);
    }
    node->parent = grandparent;
    if (grandparent != NULL && grandparent->left == parent) {
        grandparent->left = node;
    } else if (grandparent != NULL) {
        grandparent->right = node;
    }
}

void SplayRope::rotatesecond(Node* node) {
    Node* parent = node->parent;
    if (parent == NULL) return;
    Node* grandparent = parent->parent;
    if (grandparent == NULL) return;
    if ((grandparent->left == parent && parent->left == node) || (grandparent->right == parent && parent->right == node)) {
        rotate(parent, node);
    } else {
        rotate(node, node);
    }
}

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

Node* SplayRope::findNodeWithPos(Node*& root, int pos) {
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
    return p;
}

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
        updateCurNodeInformation(left);
        updateCurNodeInformation(right);
    }
}

Node* SplayRope::append(Node* left, Node* right) {
    if (left == NULL || right == NULL) return left == NULL ? right : left;
    Node* p = right;
    while (p->left != NULL) p = p->left;
    splayAtNode(right, p);
    right->left = left;
    updateCurNodeInformation(right);
    return right;
}

string SplayRope::substring(Node*& root, int l, int r) {
    Node *left = NULL;
    Node *right = NULL;
    Node *middle = NULL;
    Node *temp = NULL;
    splitAtPos(root, r + 2, temp, right);
    splitAtPos(temp, l + 1, left, middle);
    string res = inorder(middle);
    root = append(append(left, middle), right);
    return res;
}

void SplayRope::remove(Node*& root, int l, int r) {
    Node *left = NULL;
    Node *right = NULL;
    Node *middle = NULL;
    Node *temp = NULL;
    splitAtPos(root, r + 2, temp, right);
    splitAtPos(temp, l + 1, left, middle);
    
    root = append(left, right);
}

void SplayRope::insert(Node*& root, int pos, Node*& newNode) {
    Node* left = NULL;
    Node* right = NULL;
    splitAtPos(root, pos, left, right);
    Node* temp = append(left, newNode);
    root = append(temp, right);
}

string SplayRope::inorder(Node* root) {
    if (root == NULL) return "";
    stack<Node*> st;
    Node* p = root;
    while (p != NULL) {
        st.push(p);
        p = p->left;
    }
    string res("");
    while (!st.empty()) {
        p = st.top();
        st.pop();
        res.push_back(p->content);
        p = p->right;
        while (p != NULL) {
            st.push(p);
            p = p->left;
        }
    }
    return res;
}

string SplayRope::toString() {
    return inorder(root);
}

Node*& SplayRope::getRoot() {
    return root;
}

void SplayRope::setRoot(Node* newRoot) {
    root = newRoot;
}

void SplayRope::rotate(Node* node1, Node* node2) {
    rotatefirst(node1);
    rotatefirst(node2);
}