#include "menu.hpp"

adrNode createNode(int id, string nama, int harga) {
    adrNode p = new MenuNode;
    p->id = id;
    p->nama = nama;
    p->harga = harga;
    p->child = nullptr;
    p->sibling = nullptr;
    return p;
}

void addChild(adrNode parent, adrNode child) {
    if (parent->child == nullptr) {
        parent->child = child;
    } else {
        adrNode temp = parent->child;
        while (temp->sibling != nullptr) {
            temp = temp->sibling;
        }
        temp->sibling = child;
    }
}

// Pre Order
void preOrder(adrNode root) {
    if (root != nullptr) {
        cout << "[" << root->id << "] " << root->nama;
        if (root->harga > 0)
            cout << " - Rp" << root->harga;
        cout << endl;

        preOrder(root->child);
        preOrder(root->sibling);
    }
}

void inOrder(adrNode root) {
    if (root != nullptr) {
        inOrder(root->child);
        cout << "[" << root->id << "] " << root->nama << endl;
        inOrder(root->sibling);
    }
}

void postOrder(adrNode root) {
    if (root != nullptr) {
        postOrder(root->child);
        cout << "[" << root->id << "] " << root->nama << endl;
        postOrder(root->sibling);
    }
}

adrNode searchById(adrNode root, int id) {
    if (root == nullptr)
        return nullptr;

    if (root->id == id)
        return root;

    adrNode found = searchById(root->child, id);
    if (found != nullptr)
        return found;

    return searchById(root->sibling, id);
}

void findMinPrice(adrNode root, adrNode &minNode) {
    if (root == nullptr)
        return;

    if (root->harga > 0) {
        if (minNode == nullptr || root->harga < minNode->harga) {
            minNode = root;
        }
    }

    findMinPrice(root->child, minNode);
    findMinPrice(root->sibling, minNode);
}

