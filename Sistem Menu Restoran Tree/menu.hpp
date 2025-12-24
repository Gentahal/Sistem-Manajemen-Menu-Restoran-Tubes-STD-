#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string>
using namespace std;

typedef struct MenuNode* adrNode;

struct MenuNode {
    int id;
    string nama;
    int harga;

    adrNode child;
    adrNode sibling;
};

adrNode createNode(int id, string nama, int harga);
void addChild(adrNode parent, adrNode child);
void preOrder(adrNode root);
void inOrder(adrNode root);
void postOrder(adrNode root);
adrNode searchById(adrNode root, int id);
void findMinPrice(adrNode root, adrNode &minNode);

#endif

