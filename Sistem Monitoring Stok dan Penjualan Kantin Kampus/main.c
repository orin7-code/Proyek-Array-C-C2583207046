
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 50
#define PANJANG 50

// Array utama
char nama[MAX][PANJANG];
double harga[MAX];
int stok[MAX];
int terjual[MAX];

int jumlahProduk = 5;
double totalPendapatan = 0;

// Data awal kantin
void dataAwal() {
    strcpy(nama[0], "Ayam Bawang putih");
    harga[0] = 15000;
    stok[0] = 20;
    terjual[0] = 0;

    strcpy(nama[1], "Ayam Ketumbar");
    harga[1] = 12000;
    stok[1] = 15;
    terjual[1] = 0;

    strcpy(nama[2], "Nasi Putih");
    harga[2] = 3000;
    stok[2] = 30;
    terjual[2] = 0;

    strcpy(nama[3], "Air Mineral");
    harga[3] = 3000;
    stok[3] = 25;
    terjual[3] = 0;

    strcpy(nama[4], "Es Teh");
    harga[4] = 5000;
    stok[4] = 10;
    terjual[4] = 0;
}

// Input angka dengan validasi
int inputInt(const char *pesan) {
    char buffer[100];
    char *akhir;
    long nilai;

    while (1) {
        printf("%s", pesan);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
            continue;

        nilai = strtol(buffer, &akhir, 10);

        while (isspace((unsigned char)*akhir))
            akhir++;

        if (akhir == buffer || *akhir != '\0') {
            printf("Input harus berupa angka bulat!\n");
            continue;
        }

        if (nilai < -2147483647L || nilai > 2147483647L) {
            printf("Angka terlalu besar!\n");
            continue;
        }

        return (int)nilai;
    }
}

// Input harga dengan validasi
double inputDouble(const char *pesan) {
    char buffer[100];
    char *akhir;
    double nilai;

    while (1) {
        printf("%s", pesan);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
            continue;

        nilai = strtod(buffer, &akhir);

        while (isspace((unsigned char)*akhir))
            akhir++;

        if (akhir == buffer || *akhir != '\0' ||
            nilai < 0 || nilai > 1000000000000.0) {
            printf("Masukkan angka yang valid dan tidak negatif!\n");
            continue;
        }

        return nilai;
    }
}

// Input teks
void inputTeks(const char *pesan, char teks[]) {
    printf("%s", pesan);
    fgets(teks, PANJANG, stdin);
    teks[strcspn(teks, "\n")] = '\0';
}

// Membandingkan teks tanpa membedakan huruf besar/kecil
int samaTeks(const char a[], const char b[]) {
    int i = 0;

    while (a[i] && b[i]) {
        if (tolower((unsigned char)a[i]) !=
            tolower((unsigned char)b[i]))
            return 0;
        i++;
    }

    return a[i] == '\0' && b[i] == '\0';
}

// Mencari teks di dalam nama produk
int mengandungTeks(const char teks[], const char cari[]) {
    int i, j;

    if (cari[0] == '\0')
        return 1;

    for (i = 0; teks[i] != '\0'; i++) {
        for (j = 0; cari[j] != '\0'; j++) {
            if (tolower((unsigned char)teks[i+j]) !=
                tolower((unsigned char)cari[j]))
                break;
        }

        if (cari[j] == '\0')
            return 1;
    }

    return 0;
}

// Menampilkan daftar produk
void tampilProduk() {
    int i;

    printf("\n================ DAFTAR PRODUK ================\n");
    printf("%-5s %-22s %-15s %-10s %-10s\n",
           "No", "Nama Produk", "Harga", "Stok", "Terjual");

    for (i = 0; i < jumlahProduk; i++) {
        printf("%-5d %-22s Rp%-13.0f %-10d %-10d\n",
               i + 1, nama[i], harga[i],
               stok[i], terjual[i]);
    }

    printf("================================================\n");
}

// Menambahkan produk baru
void tambahProduk() {
    char namaBaru[PANJANG];
    int i;

    if (jumlahProduk >= MAX) {
        printf("Kapasitas produk sudah penuh!\n");
        return;
    }

    inputTeks("Masukkan nama produk: ", namaBaru);

    if (strlen(namaBaru) == 0) {
        printf("Nama produk tidak boleh kosong!\n");
        return;
    }

    for (i = 0; i < jumlahProduk; i++) {
        if (samaTeks(nama[i], namaBaru)) {
            printf("Produk sudah terdaftar!\n");
            return;
        }
    }

    strcpy(nama[jumlahProduk], namaBaru);

    harga[jumlahProduk] = inputDouble("Masukkan harga: Rp");
    stok[jumlahProduk] = inputInt("Masukkan stok awal: ");

    if (stok[jumlahProduk] < 0) {
        printf("Stok tidak boleh negatif!\n");
        return;
    }

    terjual[jumlahProduk] = 0;
    jumlahProduk++;

    printf("Produk berhasil ditambahkan!\n");
}

// Mencari produk berdasarkan nama
int cariIndeks(const char cari[]) {
    int i;

    for (i = 0; i < jumlahProduk; i++) {
        if (samaTeks(nama[i], cari))
            return i;
    }

    return -1;
}

void cariProduk() {
    char cari[PANJANG];
    int i, ditemukan = 0;

    inputTeks("Masukkan nama produk yang dicari: ", cari);

    printf("\nHasil pencarian:\n");

    for (i = 0; i < jumlahProduk; i++) {
        if (mengandungTeks(nama[i], cari)) {
            printf("%d. %s | Harga: Rp%.0f | Stok: %d\n",
                   i + 1, nama[i], harga[i], stok[i]);
            ditemukan = 1;
        }
    }

    if (!ditemukan)
        printf("Produk tidak ditemukan!\n");
}

// Mengubah harga dan stok produk
void ubahProduk() {
    int nomor;

    tampilProduk();

    nomor = inputInt("Pilih nomor produk yang akan diubah: ");

    if (nomor < 1 || nomor > jumlahProduk) {
        printf("Nomor produk tidak ditemukan!\n");
        return;
    }

    nomor--;

    printf("Produk: %s\n", nama[nomor]);

    harga[nomor] = inputDouble("Masukkan harga baru: Rp");

    stok[nomor] = inputInt("Masukkan stok baru: ");

    if (stok[nomor] < 0) {
        printf("Stok tidak boleh negatif!\n");
        return;
    }

    printf("Data produk berhasil diperbarui!\n");
}

// Menambah stok produk
void tambahStok() {
    int nomor, jumlah;

    tampilProduk();

    nomor = inputInt("Pilih nomor produk: ");

    if (nomor < 1 || nomor > jumlahProduk) {
        printf("Produk tidak ditemukan!\n");
        return;
    }

    jumlah = inputInt("Masukkan jumlah stok tambahan: ");

    if (jumlah <= 0 || stok[nomor - 1] > 2147483647 - jumlah) {
        printf("Jumlah stok tidak valid!\n");
        return;
    }

    stok[nomor - 1] += jumlah;

    printf("Stok berhasil ditambahkan!\n");
    printf("Stok sekarang: %d\n", stok[nomor - 1]);
}

// Transaksi beberapa produk
void transaksi() {
    int pembelian[MAX] = {0};
    int nomor, jumlah, i;
    double subtotal, total = 0;
    int adaPembelian = 0;

    tampilProduk();

    printf("\n========== TRANSAKSI PENJUALAN ==========\n");
    printf("Masukkan 0 pada nomor produk untuk selesai.\n");

    while (1) {
        nomor = inputInt("\nNomor produk: ");

        if (nomor == 0)
            break;

        if (nomor < 1 || nomor > jumlahProduk) {
            printf("Nomor produk tidak ditemukan!\n");
            continue;
        }

        i = nomor - 1;

        printf("Produk: %s\n", nama[i]);
        printf("Stok tersedia: %d\n", stok[i]);

        jumlah = inputInt("Jumlah pembelian: ");

        if (jumlah <= 0) {
            printf("Jumlah pembelian harus lebih dari 0!\n");
            continue;
        }

        if (jumlah > stok[i] - pembelian[i]) {
            printf("Stok tidak mencukupi! Pembelian ditolak.\n");
            continue;
        }

        pembelian[i] += jumlah;
        adaPembelian = 1;

        printf("Produk berhasil dimasukkan ke transaksi.\n");
    }

    if (!adaPembelian) {
        printf("\nTidak ada transaksi yang diproses.\n");
        return;
    }

    printf("\n============== STRUK PEMBELIAN ==============\n");

    for (i = 0; i < jumlahProduk; i++) {
        if (pembelian[i] > 0) {
            subtotal = harga[i] * pembelian[i];
            total += subtotal;

            printf("%-20s x %-4d = Rp%.0f\n",
                   nama[i], pembelian[i], subtotal);
        }
    }

    printf("----------------------------------------------\n");
    printf("TOTAL PEMBAYARAN : Rp%.0f\n", total);
    printf("==============================================\n");

    // Memperbarui stok dan jumlah terjual
    for (i = 0; i < jumlahProduk; i++) {
        if (pembelian[i] > 0) {
            stok[i] -= pembelian[i];
            terjual[i] += pembelian[i];
        }
    }

    totalPendapatan += total;

    printf("Transaksi berhasil!\n");
    printf("Stok produk telah diperbarui.\n");
}

// Mengurutkan produk
void tukarProduk(int a, int b) {
    char tempNama[PANJANG];
    double tempHarga;
    int tempStok, tempTerjual;

    strcpy(tempNama, nama[a]);
    strcpy(nama[a], nama[b]);
    strcpy(nama[b], tempNama);

    tempHarga = harga[a];
    harga[a] = harga[b];
    harga[b] = tempHarga;

    tempStok = stok[a];
    stok[a] = stok[b];
    stok[b] = tempStok;

    tempTerjual = terjual[a];
    terjual[a] = terjual[b];
    terjual[b] = tempTerjual;
}

void urutkanProduk() {
    int pilihan, i, j;

    printf("\n========== PENGURUTAN PRODUK ==========\n");
    printf("1. Harga termurah\n");
    printf("2. Penjualan terbanyak\n");

    pilihan = inputInt("Pilih pengurutan: ");

    if (pilihan != 1 && pilihan != 2) {
        printf("Pilihan tidak tersedia!\n");
        return;
    }

    for (i = 0; i < jumlahProduk - 1; i++) {
        for (j = 0; j < jumlahProduk - i - 1; j++) {

            if ((pilihan == 1 && harga[j] > harga[j+1]) ||
                (pilihan == 2 && terjual[j] < terjual[j+1])) {

                tukarProduk(j, j+1);
            }
        }
    }

    printf("\nProduk berhasil diurutkan!\n");
    tampilProduk();
}

// Laporan penjualan
void laporanPenjualan() {
    int i;
    int totalUnit = 0;
    int terlaris = 0;

    printf("\n============= LAPORAN PENJUALAN =============\n");

    printf("%-22s %-15s\n", "Nama Produk", "Jumlah Terjual");

    for (i = 0; i < jumlahProduk; i++) {
        printf("%-22s %-15d\n", nama[i], terjual[i]);

        totalUnit += terjual[i];

        if (terjual[i] > terjual[terlaris])
            terlaris = i;
    }

    printf("----------------------------------------------\n");
    printf("Total Unit Terjual : %d\n", totalUnit);
    printf("Total Pendapatan   : Rp%.0f\n", totalPendapatan);

    if (totalUnit > 0) {
        printf("Produk Terlaris    : %s\n", nama[terlaris]);
        printf("Jumlah Terjual     : %d unit\n", terjual[terlaris]);
    } else {
        printf("Produk Terlaris    : Belum ada penjualan\n");
    }

    printf("==============================================\n");
}

// Mengecek stok menipis
void cekStok() {
    int i, ditemukan = 0;

    printf("\n========== PRODUK DENGAN STOK MENIPIS ==========\n");

    for (i = 0; i < jumlahProduk; i++) {
        if (stok[i] < 5) {
            printf("%s | Stok tersisa: %d\n",
                   nama[i], stok[i]);
            ditemukan = 1;
        }
    }

    if (!ditemukan)
        printf("Tidak ada produk dengan stok kurang dari 5.\n");
}

// Menu utama
int main() {
    int pilihan;

    dataAwal();

    do {
        printf("\n");
        printf("============================================\n");
        printf("   SISTEM MONITORING STOK DAN PENJUALAN\n");
        printf("             KANTIN KAMPUS\n");
        printf("============================================\n");
        printf("1. Lihat Daftar Produk\n");
        printf("2. Tambah Produk\n");
        printf("3. Ubah Produk\n");
        printf("4. Transaksi Penjualan\n");
        printf("5. Tambah Stok\n");
        printf("6. Cari Produk\n");
        printf("7. Urutkan Produk\n");
        printf("8. Laporan Penjualan\n");
        printf("9. Cek Stok Menipis\n");
        printf("0. Keluar\n");
        printf("============================================\n");

        pilihan = inputInt("Pilih menu: ");

        switch (pilihan) {
            case 1:
                tampilProduk();
                break;

            case 2:
                tambahProduk();
                break;

            case 3:
                ubahProduk();
                break;

            case 4:
                transaksi();
                break;

            case 5:
                tambahStok();
                break;

            case 6:
                cariProduk();
                break;

            case 7:
                urutkanProduk();
                break;

            case 8:
                laporanPenjualan();
                break;

            case 9:
                cekStok();
                break;

            case 0:
                printf("\nTerima kasih telah menggunakan program!\n");
                break;

            default:
                printf("\nPilihan menu tidak tersedia!\n");
        }

    } while (pilihan != 0);

    return 0;
}
