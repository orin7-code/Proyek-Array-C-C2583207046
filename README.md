# SISTEM MONITORING STOK DAN PENJUALAN KANTIN KAMPUS

## Identitas Mahasiswa

| Keterangan | Identitas |
|---|---|
| Nama | Orin Rismaya |
| NIM | C2583207046 |
| Kelas | PTI3A |
| Program Studi | Pendidikan Teknologi Informasi |
| Fakultas | Fakultas Keguruan dan Ilmu Pendidikan |
| Universitas | Universitas Muhammadiyah Tasikmalaya |
| Mata Kuliah | Algoritma dan Pemrograman Lanjut |
| Dosen Pengampu | Taofik Muhammad, M.Kom |

---

## 1. Deskripsi Proyek

Sistem Monitoring Stok dan Penjualan Kantin Kampus merupakan aplikasi berbasis console yang dibuat menggunakan bahasa pemrograman C.

Program ini bertujuan untuk membantu pengelola kantin dalam mengelola data produk, memantau ketersediaan stok, melakukan transaksi penjualan, mencari produk, mengurutkan data produk, serta menampilkan laporan penjualan secara otomatis.

Program ini menggunakan array sebagai struktur data utama dan menerapkan konsep dasar pemrograman C seperti percabangan, perulangan, fungsi, pencarian, dan pengurutan.

## 2. Tujuan Program

- Mempermudah pengelolaan data produk kantin.
- Memantau jumlah stok barang.
- Menghitung transaksi penjualan secara otomatis.
- Mengetahui jumlah produk yang telah terjual.
- Menampilkan total pendapatan dan produk terlaris.
- Meminimalkan kesalahan dalam pencatatan penjualan.

## 3. Fitur Program

Program memiliki beberapa fitur utama, yaitu:

1. **Lihat Daftar Produk**  
   Menampilkan nama produk, harga, stok, dan jumlah terjual.

2. **Tambah Produk**  
   Menambahkan produk baru ke dalam daftar dengan batas maksimal 50 produk.

3. **Ubah Produk**  
   Mengubah harga dan stok produk yang sudah tersedia.

4. **Transaksi Penjualan**  
   Melakukan pembelian beberapa jenis produk dalam satu transaksi serta menghitung total pembayaran.

5. **Tambah Stok**  
   Menambahkan jumlah persediaan produk.

6. **Cari Produk**  
   Mencari produk berdasarkan nama.

7. **Urutkan Produk**  
   Mengurutkan produk berdasarkan harga termurah atau jumlah penjualan terbanyak.

8. **Laporan Penjualan**  
   Menampilkan jumlah setiap produk yang terjual, total unit terjual, total pendapatan, dan produk terlaris.

9. **Cek Stok Menipis**  
   Menampilkan produk yang memiliki stok kurang dari 5.

## 4. Penerapan Array

Array digunakan sebagai struktur data utama dalam program untuk menyimpan dan mengelola informasi produk.

Adapun array yang digunakan adalah:

| Nama Array | Tipe Data | Fungsi |
|---|---|---|
| nama[MAX][PANJANG] | char | Menyimpan nama produk |
| harga[MAX] | double | Menyimpan harga produk |
| stok[MAX] | int | Menyimpan jumlah stok |
| terjual[MAX] | int | Menyimpan jumlah produk terjual |

Keterangan:
- Array dua dimensi digunakan untuk menyimpan nama produk.
- Array satu dimensi digunakan untuk menyimpan harga, stok, dan jumlah terjual.
- Kapasitas maksimal penyimpanan adalah 50 produk.
- Program menyediakan 5 produk sebagai data awal.

## 5. Teknologi yang Digunakan

- Bahasa Pemrograman: C
- IDE: Code::Blocks
- Compiler: GCC
- Struktur Data: Array
- Sistem: Console Application

## 6. Cara Menjalankan Program

Berikut langkah-langkah untuk menjalankan program:

1. Buka aplikasi Code::Blocks.
2. Buat file baru dengan ekstensi `.c`.
3. Salin kode program ke dalam file `main.c`.
4. Simpan file program.
5. Klik menu **Build and Run** atau tekan tombol **F9**.
6. Program akan berjalan pada jendela console.
7. Pilih menu sesuai fitur yang ingin digunakan.

### Kompilasi melalui Terminal

Jika menggunakan GCC, jalankan perintah:

```bash
gcc main.c -o kantin
```

Kemudian jalankan program:

```bash
./kantin
```

Untuk Windows:

```bash
kantin.exe
```

## 7. Pengujian Program

Pengujian dilakukan untuk memastikan seluruh fitur berjalan sesuai dengan ketentuan tugas.

| No. | Skenario Pengujian | Hasil yang Diharapkan | Status |
|---|---|---|---|
| 1 | Menambahkan produk baru | Produk berhasil ditambahkan | Berhasil |
| 2 | Transaksi beberapa produk | Subtotal dan total pembayaran benar | Berhasil |
| 3 | Pembaruan stok | Stok dan jumlah terjual berubah | Berhasil |
| 4 | Pembelian melebihi stok | Transaksi ditolak dan stok tetap | Berhasil |
| 5 | Menampilkan laporan | Unit, pendapatan, dan produk terlaris tampil | Berhasil |
| 6 | Pengurutan produk | Data terurut sesuai pilihan | Berhasil |
| 7 | Pencarian dan pengecekan stok | Hasil pencarian dan peringatan stok tampil | Berhasil |

## 8. Dokumentasi Screenshot

Berikut merupakan dokumentasi hasil pengujian program.

### A. Tampilan Menu Utama

![Menu Utama](screenshots/menu-utama.png)

### B. Daftar Produk

![Daftar Produk](screenshots/daftar-produk.png)

### C. Tambah Produk

![Tambah Produk](screenshots/tambah-produk.png)

### D. Transaksi Penjualan

![Transaksi Penjualan](screenshots/transaksi.png)

### E. Laporan Penjualan

![Laporan Penjualan](screenshots/laporan-penjualan.png)

### F. Pengurutan Produk

![Pengurutan Produk](screenshots/pengurutan.png)

### G. Pengecekan Stok Menipis

![Cek Stok](screenshots/cek-stok.png)

*Catatan: Ganti seluruh gambar dengan screenshot hasil pengujian program sendiri. Pastikan nama file gambar sesuai dengan lokasi yang dituliskan.*

## 9. Struktur Repository

Susunan file dalam repository GitHub:

```text
Proyek-Array-C-NIM/
│
├── main.c
├── README.md
│
└── screenshots/
    ├── menu-utama.png
    ├── daftar-produk.png
    ├── tambah-produk.png
    ├── transaksi.png
    ├── laporan-penjualan.png
    ├── pengurutan.png
    └── cek-stok.png
```

## 10. Kesimpulan

Melalui pembuatan proyek ini, mahasiswa dapat menerapkan konsep dasar pemrograman bahasa C, khususnya penggunaan array satu dimensi dan dua dimensi, fungsi, percabangan, perulangan, pencarian, serta pengurutan data.

Aplikasi Sistem Monitoring Stok dan Penjualan Kantin Kampus diharapkan dapat membantu proses pengelolaan produk, pencatatan transaksi, pemantauan stok, dan penyusunan laporan penjualan secara lebih mudah dan terstruktur.

---

**Dibuat oleh:** Orin Rismaya  
**Program Studi:** Pendidikan Teknologi Informasi  
**Universitas Muhammadiyah Tasikmalaya  
**Tahun Akademik:** 2026/2027
