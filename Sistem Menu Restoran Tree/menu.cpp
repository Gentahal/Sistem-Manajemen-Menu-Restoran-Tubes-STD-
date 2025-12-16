#include "menu.hpp"

adrNode createNode(int id, string nama, string kategori, int harga) {
    adrNode p = new MenuNode;
    p->id = id;
    p->nama = nama;
    p->kategori = kategori;
    p->harga = harga;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

adrNode insert(adrNode root, int id, string nama, string kategori, int harga) {
    if (root == nullptr) {
        return createNode(id, nama, kategori, harga);
    }
    
    if (id < root->id) {
        root->left = insert(root->left, id, nama, kategori, harga);
    } else if (id > root->id) {
        root->right = insert(root->right, id, nama, kategori, harga);
    } else {
        cout << "Duplikat: ID Menu " << id << " sudah ada dalam sistem." << endl;
    }
    return root;
}

adrNode search(adrNode root, int key) {
    if (root == nullptr || root->id == key) {
        return root;
    }
    
    if (key < root->id) {
        return search(root->left, key);
    }
    
    return search(root->right, key);
}

void preOrder(adrNode root) {
    if (root != nullptr) {
        cout << "[" << root->id << "] " << root->nama << " (" << root->kategori << ")" << endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(adrNode root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << "[" << root->id << "] " << root->nama << " - Rp" << root->harga << endl;
        inOrder(root->right);
    }
}

void postOrder(adrNode root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << "[" << root->id << "] " << root->nama << endl;
    }
}

void findMinPrice(adrNode root) {
    if (root == nullptr) {
        cout << "Tree kosong." << endl;
        return;
    }
    
    adrNode current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    cout << "Menu Termurah (ID Terkecil): " << current->nama << " dengan harga Rp" << current->harga << endl;
}
