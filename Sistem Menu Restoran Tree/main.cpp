#include <iostream>
#include "menu.hpp"

int main(int argc, const char * argv[]) {
    adrNode root = nullptr;
    
    int pilihan, id, harga;
    string nama, kategori;
    
    root = insert_NIM(root, 50, "Steak Sapi", "Makanan", 150000);
    root = insert_NIM(root, 30, "Ayam Bakar", "Makanan", 45000);
    root = insert_NIM(root, 70, "Pasta Carbonara", "Makanan", 60000);
    root = insert_NIM(root, 20, "Es Teh", "Minuman", 5000);
    root = insert_NIM(root, 40, "Jus Jeruk", "Minuman", 15000);

    do {
        cout << "\n=== RESTORAN BINARY TREE SYSTEM ===" << endl;
        cout << "1. Insert Menu Baru" << endl;
        cout << "2. Tampilkan Menu (In-Order / Terurut)" << endl;
        cout << "3. Tampilkan Struktur Tree (Pre-Order)" << endl;
        cout << "4. Cari Menu (Search by ID)" << endl;
        cout << "5. Menu Termurah (Find Min)" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: "; cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                cout << "Masukkan ID (Angka Unik): "; cin >> id;
                cin.ignore(); // Membersihkan buffer
                cout << "Nama Menu: "; getline(cin, nama);
                cout << "Kategori: "; getline(cin, kategori);
                cout << "Harga: "; cin >> harga;
                root = insert_NIM(root, id, nama, kategori, harga);
                break;
                
            case 2:
                cout << "\n--- Daftar Menu (In-Order) ---" << endl;
                inOrder_NIM(root);
                break;
                
            case 3:
                cout << "\n--- Struktur Hierarki (Pre-Order) ---" << endl;
                preOrder_NIM(root);
                break;
                
            case 4:
                cout << "Masukkan ID yang dicari: "; cin >> id;
                {
                    adrNode hasil = search_NIM(root, id);
                    if (hasil != nullptr) {
                        cout << "DITEMUKAN: " << hasil->nama << " | " << hasil->kategori << " | Rp" << hasil->harga << endl;
                    } else {
                        cout << "Menu dengan ID " << id << " TIDAK DITEMUKAN." << endl;
                    }
                }
                break;
            
            case 5:
                findMinPrice_NIM(root);
                break;
                
            case 0:
                cout << "Program Selesai." << endl;
                break;
                
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (pilihan != 0);
    
    return 0;
}
