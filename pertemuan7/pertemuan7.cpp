#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int const jml_katalog = 5;
//inisiasi variable global jml_katalog

struct Produk {
    int id;
    string nama_produk;
    int harga;
};
//inisiasi variable global produk bertipe struct

struct ItemKeranjang {
    string nama;
    int harga;
    int qty;
    int subtotal;
};
//inisiasi variable global ItemKeranjang bertipe struct

Produk katalog[5] = {
    {1, "Minyak Goreng 2L", 34000},
    {2, "Beras 5kg", 65000},
    {3, "Gula pasir 250gr", 10000},
    {4, "Mie Instant", 3500},
    {5, "Teh Celup", 8000}
};
//katalog produk global

//Function menampilkan katalog
void tampilkanKatalog()
//Deklarasi fungsi tampilkanKatalog
{
    cout << "\n--- Katalog Produk ---" << endl;
    for (int i = 0; i < jml_katalog; i++) {
        cout << katalog[i].id << ". " << katalog[i].nama_produk << "\t- Rp " << katalog[i].harga << endl;
    }
    //Menampilkan "--- Katalog Produk ---"
    //dengan perulangan ketika i jumlahnya kurang dari jml_katalog
    //tampilkan data katalog hingga memenuhi kondisi tersebut
}

//Menghitung Subtotal dan mengembalikan operasi harga * qty
int hitungSubtotal(int harga, int qty) {
    return harga * qty;
}

//Menghitung Diskon dan mengembalikan hasil dari diskon. 
int hitungDiskon(double total) {
    //Deklarasi fungsi hitungDiskon
    if (total >= 100000) {
        return total * 0.10;
    } else {
        return 0;
    }
    //Diskon hanya untuk pembelian diatas 100000
}

//Tambah Item ke Keranjang
void SubRoutine_TambahKeranjang(Produk katalog[], ItemKeranjang keranjang[], int &totalItem) {
    //deklarasi function SubRoutine_TambahKeranjang
    int idInput, qtyInput, i;
    bool found = false;
    //deklarasi variable idInput, i, & qtyInput sebagai integer
    //deklarasi variable found bertipe string dan bernilai false

    tampilkanKatalog();
    //menampilkan katalog produk

    cout << "Masukkan ID Barang: ";
    cin >> idInput;
    cout << "Masukkan Jumlah: ";
    cin >> qtyInput;
    //menampilkan output "Masukkan ID Barang: "
    //memasukkan value ke variable idInput
    //menampilkan output "Masukkan jumlah: "
    //memasukkan value ke variable qtyInput

    //cari data di array katalog
    for (int i = 0; i < jml_katalog; i++) {
        if (katalog[i].id == idInput) {
            found = true;

            keranjang[totalItem].nama = katalog[i].nama_produk;
            keranjang[totalItem].harga = katalog[i].harga;
            keranjang[totalItem].qty = qtyInput;
            keranjang[totalItem].subtotal = hitungSubtotal(katalog[i].harga, qtyInput);
            //Memanggil fungsi hitungSubtotal untuk menghitung hasil dari harga dan quantitynya

            totalItem = totalItem + 1;
            cout << "Barang berhasil ditambahkan ke keranjang!" << endl;
            //menambahkan jumlah totalItem
            //menampilkan "Barang berhasil ditambahkan ke keranjang!"
            break;
        }
    }
    //perulangan jika i kurang dari jml_katalog
    //mencari data berdasarkan idInput yang akan disesuaikan dengan id pada Produk

    if (!found) {
        cout << "ID Barang tidak ditemukan!";
    }
    //Jika barang tidak ditemukan menampilkan pesan "ID Barang tidak ditemukan!"
}

//Lihat keranjang
void SubRoutine_LihatKeranjang(ItemKeranjang keranjang[], int &totalItem) {
    //deklarasi function SubRoutine_LihatKeranjang
    int i;
    //deklarasi variable i bertipe int

    if (totalItem == 0) {
        cout << "Keranjang kamu masih kosong!" << endl;
        //Jika totalItem == 0 maka keranjang kosong akan diarahkan ke menu awal untuk menambahkan barang dahulu
    }
    else {
        cout << "\n --- Isi Keranjang Belanja ---" << endl;
        cout << left << setw(4)  << "No" 
             << setw(20) << "Nama Barang" 
             << setw(8)  << "Qty" 
             << setw(15) << "Harga" 
             << "Subtotal" << endl;
        //Pengaturan kolom/header tabel

        for (int i = 0; i < totalItem; i++) {
            cout << left << setw(4) << (i + 1)
                << setw(20) << keranjang[i].nama
                << setw(8) << keranjang[i].qty
                << "Rp " << setw(12) << keranjang[i].harga
                << "Rp " << keranjang[i].subtotal << endl;
        }
        //Menampilkan totalItem/item yang ada dikeranjang
    }
    //menampilkan isi keranjang
}

//Hapus item dari keranjang 
void SubRoutine_HapusItem(ItemKeranjang keranjang[], int &totalItem) {
    //mendeklarasikan function SubRoutine_HapusItem 

    int nomorHapus, index, i;
    //Deklarasi variable internal nomorHapus, index, i bertipe int

    if (totalItem == 0) {
        cout << "Keranjang kosong! Tidak ada item yang bisa dihapus." << endl;
        //jika  totalItem == 0 tampilkan kalo keranjang kosong
    }
    else {
        SubRoutine_LihatKeranjang(keranjang, totalItem);
        //panggil fungsi SubRoutine_LihatKeranjang untuk menampilkan daftar barang di keranjang

        cout << "Masukkan nomor item yang ingin dihapus: ";
        cin >> nomorHapus;
        //Untuk input nomor mana/barang mana yg mau dihapus

        if (nomorHapus >= 1 && nomorHapus <= totalItem) {
            index = nomorHapus -  1;
            //jika nomorHapus lebihd ari 1 dan masih didalam range jumlah totalItem maka akan menghapus barang melalui urutan index

            //Array Shift
            for (int i = index; i < totalItem - 1; i++) {
                keranjang[i] = keranjang[i + 1];
            }

            totalItem = totalItem - 1;
            cout << "Item berhasil dihapus dari keranjang!" << endl; 
            //Mengurangi totalItem by -1
            //menampilkan item berhasil dihapus
        }
        else {
            cout << "Nomor Item tidak valid!" << endl;
            //Jika nomor item tidak ditemukan maka nomor tidak valid
        }
    }
}

//pembayaran dan cetak struk
void SubRoutine_Pembayaran(ItemKeranjang keranjang[], int& totalItem) {
    //deklarasi function SubRoutine_Pembayaran
    int grandTotal, diskon, totalAkhir, bayar, kembalian, i;
    //Deklarasi variable grandTotal, diskon, totalAkhir, bayar, kemnalian, i sebagai integer

    if (totalItem == 0) {
        cout << "Keranjang masih kosong! Belanja terlebih dahulu." << endl;
        return;
        //jika keranjang 0 tampilkan Keranjang masih kosong! Belanja terlebih dahulu.
    }

    //Menghitung grandTotal
    grandTotal = 0;
    for (int i = 0; i < totalItem; i++) {
        grandTotal = grandTotal + keranjang[i].subtotal;
    }
    //Perulangan untuk menghitung grandTotal berdasarkan jumlah isi keranjang

    //menghitung diskon dan total akhir
    diskon = hitungDiskon(grandTotal);
    totalAkhir = grandTotal - diskon;

    cout << "Grand Total : Rp " << grandTotal << endl;
    cout << "Diskon      : Rp " << diskon << endl;
    cout << "Total Akhir : Rp " << totalAkhir << endl;
    //Menampilkan Grand total, diskon dan total akhir

    do {
        //validasi proses pembayaran
        cout << "Masukkan Uang Pembayaran: Rp ";
        cin >> bayar;
        //Meminta user untuk input nominal bayar dan diinputkan ke variable bayar

        if (bayar < totalAkhir) {
            cout << "Uang pembayaran kurang! Silahkan masukkan nominal yang cukup!" << endl;
        }
        //jika value dari variable bayar lebih sedikit dari total akhir uang pembayaran kurang
    } while (bayar < totalAkhir);
    //kondisi akan diulangi selama variable bayar masih lebih kecil valuenya dari variable totalAkhir

    kembalian = bayar - totalAkhir;
    //uang kembalian didapat dari bayar - totalAkhir

    //Cetak Struk belanja
    cout << "\n-----------------------" << endl;
    cout << "    Struk Pembelian    " << endl;
    cout << "-----------------------" << endl;
    
    for (int i = 0; i < totalItem; i++) {
        cout << setw(20) << keranjang[i].nama << setw(8) << " x"
            << keranjang[i].qty << setw(8) << " = Rp "
            << setw(8) << keranjang[i].subtotal << endl;
    }
    //Perulangan untuk mwncetak list dari barang yang ada dikeranjang

    cout << "-----------------------" << endl;
    cout << "Grand Total : Rp " << grandTotal << endl;
    cout << "Diskon      : Rp " << diskon << endl;
    cout << "Total Akhir : Rp " << totalAkhir << endl;
    cout << "Bayar       : Rp " << bayar << endl;
    cout << "Kembalian   : Rp " << kembalian << endl;
    cout << "-----------------------\n" << endl;

    totalItem = 0;
    //Set totalItem ke 0 untuk mengulangi proses lagi

}

int main()
{
    //deklarasi variabel struct keranjang (maks 100 item), int totalItems, int pilihan
    ItemKeranjang keranjang[100];
    int totalItem = 0;
    int pilihan;

    //Menu Utama
    do {
        cout << "\n --- Selamat Datang di Minimarket Sukamaju! ---" << endl;
        cout << "1. Tambah item ke Keranjang" << endl;
        cout << "2. Lihat Keranjang" << endl;
        cout << "3. Hapus Item dari Keranjang" << endl;
        cout << "4. Pembayaran & Cetak Struk" << endl;
        cout << "5. Keluar" << endl;
        //Menampilkan menu utama

        cout << "\nPilih Opsi diatas (1/2/3/4/5) : ";
        //menampilkan pilihan opsi yang bisa dilakukan

        cin >> pilihan;
        //input nomor kedalam variable pilihan

        switch (pilihan) {
        case 1 :
            SubRoutine_TambahKeranjang(katalog, keranjang, totalItem);
            break;
            //opsi 1 untuk menambahkan barang ke keranjang

        case 2 : 
            SubRoutine_LihatKeranjang(keranjang, totalItem);
            break;
            //opsi 2 untuk menampilkan barang yang ada di keranjang

        case 3 : 
            SubRoutine_HapusItem(keranjang, totalItem);
            break;
            //opsi 3 untuk menghapus item yang ada di keranjang

        case 4 :
            SubRoutine_Pembayaran(keranjang, totalItem);
            break;
            //opsi 4 untuk melakukan pembayaran dan print struk pembelian

        case 5 :
            cout << "Terima Kasih telah berkunjung ke Minimarket Sukamaju!" << endl;
            break;
            //opsi 5 akan menampilkan "Terima Kasih telah berkunjung ke Minimarket Sukamaju!"

        default :
            cout << "Pilihan tidak valid! Silahkan coba lagi." << endl;
            //default akan menampilkan Pilihan tidak valid! Silahkan coba lagi.
        }
    } while (pilihan != 5);
    //akan diulangi selama variable pilihanb tidak bervalue 5

    cout << "Terima Kasih telah berbelanja!" << endl;
    //menampilkan Terima Kasih telah berbelanja!


}
