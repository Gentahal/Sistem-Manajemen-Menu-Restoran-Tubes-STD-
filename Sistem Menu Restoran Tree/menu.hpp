#ifndef menu_hpp
#define menu_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

typedef struct MenuNode *adrNode;

struct MenuNode {
    int id;
    string nama;
    string kategori;
    int harga;
    adrNode left;
    adrNode right;
};

adrNode createNode_NIM(int id, string nama, string kategori, int harga);

adrNode insert_NIM(adrNode root, int id, string nama, string kategori, int harga);

adrNode search_NIM(adrNode root, int key);

void preOrder_NIM(adrNode root);

void inOrder_NIM(adrNode root);

void postOrder_NIM(adrNode root);

void findMinPrice_NIM(adrNode root);

#endif /* restoran_hpp */
