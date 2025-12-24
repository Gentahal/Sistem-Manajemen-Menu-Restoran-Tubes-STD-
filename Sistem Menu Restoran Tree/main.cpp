#include <iostream>
#include "menu.hpp"

int main() {
    // Level 1
    adrNode root = createNode(1, "MENU RESTORAN", 0);

    // Level 2
    adrNode makanan = createNode(10, "MAKANAN", 0);
    adrNode minuman = createNode(20, "MINUMAN", 0);

    addChild(root, makanan);
    addChild(root, minuman);

    // Level 3 - Makanan
    addChild(makanan, createNode(101, "Steak Sapi", 150000));
    addChild(makanan, createNode(102, "Ayam Bakar", 45000));

    // Level 3 - Minuman
    addChild(minuman, createNode(201, "Es Teh", 5000));
    addChild(minuman, createNode(202, "Jus Jeruk", 15000));

    int pilihan, id;
    adrNode hasil;

    do {
        cout << "\n=== SISTEM MENU RESTORAN (TREE) ===" << endl;
        cout << "1. Tampilkan Pre-Order" << endl;
        cout << "2. Tampilkan In-Order" << endl;
        cout << "3. Tampilkan Post-Order" << endl;
        cout << "4. Cari Menu (ID)" << endl;
        cout << "5. Menu Termurah" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                preOrder(root);
                break;

            case 2:
                inOrder(root);
                break;

            case 3:
                postOrder(root);
                break;

            case 4:
                cout << "Masukkan ID: ";
                cin >> id;
                hasil = searchById(root, id);
                if (hasil != nullptr)
                    cout << "Ditemukan: " << hasil->nama << endl;
                else
                    cout << "Menu tidak ditemukan." << endl;
                break;

            case 5: {
                adrNode minNode = nullptr;
                findMinPrice(root, minNode);
                if (minNode != nullptr)
                    cout << "Menu Termurah: " << minNode->nama
                         << " - Rp" << minNode->harga << endl;
                break;
            }

            case 0:
                cout << "Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak valid." << endl;
        }

    } while (pilihan != 0);

    return 0;
}

