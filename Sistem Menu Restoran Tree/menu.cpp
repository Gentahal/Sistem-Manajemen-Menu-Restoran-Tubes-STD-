#include "menu.hpp"

adrNode createNode_NIM(int id, string nama, string kategori, int harga) {
    adrNode p = new MenuNode;
    p->id = id;
    p->nama = nama;
    p->kategori = kategori;
    p->harga = harga;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

adrNode insert_NIM(adrNode root, int id, string nama, string kategori, int harga) {
    if (root == nullptr) {
        return createNode_NIM(id, nama, kategori, harga);
    }
    
    if (id < root->id) {
        root->left = insert_NIM(root->left, id, nama, kategori, harga);
    } else if (id > root->id) {
        root->right = insert_NIM(root->right, id, nama, kategori, harga);
    } else {
        cout << "Duplikat: ID Menu " << id << " sudah ada dalam sistem." << endl;
    }
    return root;
}

adrNode search_NIM(adrNode root, int key) {
    if (root == nullptr || root->id == key) {
        return root;
    }
    
    if (key < root->id) {
        return search_NIM(root->left, key);
    }
    
    return search_NIM(root->right, key);
}

void preOrder_NIM(adrNode root) {
    if (root != nullptr) {
        cout << "[" << root->id << "] " << root->nama << " (" << root->kategori << ")" << endl;
        preOrder_NIM(root->left);
        preOrder_NIM(root->right);
    }
}

void inOrder_NIM(adrNode root) {
    if (root != nullptr) {
        inOrder_NIM(root->left);
        cout << "[" << root->id << "] " << root->nama << " - Rp" << root->harga << endl;
        inOrder_NIM(root->right);
    }
}

void postOrder_NIM(adrNode root) {
    if (root != nullptr) {
        postOrder_NIM(root->left);
        postOrder_NIM(root->right);
        cout << "[" << root->id << "] " << root->nama << endl;
    }
}

void findMinPrice_NIM(adrNode root) {
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
