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

adrNode createNode(int id, string nama, string kategori, int harga);

adrNode insert(adrNode root, int id, string nama, string kategori, int harga);

adrNode search(adrNode root, int key);

void preOrder(adrNode root);

void inOrder(adrNode root);

void postOrder(adrNode root);

void findMinPrice(adrNode root);

#endif /* restoran_hpp */
