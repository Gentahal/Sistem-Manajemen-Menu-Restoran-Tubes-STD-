#include <iostream>
#include "menu.hpp"

int main() {

    adrNode root = createNode(1, "MENU RESTORAN", 0);

    adrNode makanan = createNode(10, "MAKANAN", 0);
    adrNode minuman = createNode(20, "MINUMAN", 0);

    addChild(root, makanan);
    addChild(root, minuman);

    adrNode mainCourse = createNode(100, "MAIN COURSE", 0);
    adrNode dessert    = createNode(110, "DESSERT", 0);
    adrNode beverage   = createNode(200, "BEVERAGE", 0);

    addChild(makanan, mainCourse);
    addChild(makanan, dessert);
    addChild(minuman, beverage);

    addChild(mainCourse, createNode(1001, "Steak Sapi", 150000));
    addChild(mainCourse, createNode(1002, "Ayam Bakar", 45000));

    // Dessert
    addChild(dessert, createNode(1101, "Puding Coklat", 20000));
    addChild(dessert, createNode(1102, "Es Krim Vanilla", 18000));

    // Beverage
    addChild(beverage, createNode(2001, "Es Teh", 5000));
    addChild(beverage, createNode(2002, "Jus Jeruk", 15000));

    int pilihan, id;
    adrNode hasil;

    do {
        cout << "\n=== SISTEM MENU RESTORAN (RECURSIVE TREE) ===" << endl;
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

