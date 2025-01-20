# Sistem Aplikasi Administrasi Bank GoBanking

Project ini dibuat sebagai kelengkapan tugas akhir dari mata kuliah Algoritma Pemrograman pada bidang studi Informatika di STMIK Amikom Surakarta. Sistem Aplikasi Administrasi Bank GoBanking dirancang untuk membantu pengelolaan administrasi perbankan secara efisien dan terstruktur.

## Fitur Utama

### 1. Management Nasabah
   - Pembuatan akun dan rekening baru
   - Mengelola data nasabah
   - Pencarian data nasabah
### 2. Transaksi Perbankan
   - Penarikan tunai
   - Setoran tunai
   - Transfer rekening
### 3. Management Rekening
   - Mengelola data rekening
   - Pencarian data rekening
   - Cek saldo dan aktivitas rekening
### 4. Management Karyawan
   - Mengelola data karyawan
   - Pencarian data karyawan

## Techstack

- Bahasa pemrograman: C++ (untuk sistem aplikasi) dan Typescript (untuk sistem rest api)
- Framework: .NET Framework (untuk membuat antar muka aplikasi) dan Express.js (untuk membuat rest-api)
- Library: Prisma.js (untuk penghubung database)
- Databse: MySQL (menyimpan data)

## Cara Menjalankan
jalankan perintah di bawah ini menggunakan terminal (command promp) di komputer anda!, **pastikan juga komputer anda telah terinstall Microsoft Visual Studio 2022 (Desktop development with c++, .NET desktop development & Build tools), Database MySQL dan tools tambahakan seperti: [nlohmann/json](https://github.com/nlohmann/json) serta [libcurl](https://github.com/curl/curl)**

### Aplikasi
- Clone repository ini ```git clone https://github.com/fushigo/GoBanking```
- Pindahkan folder aplikasi ke dalam ```C:\Users\nama device anda\source\repos```
- Buka aplikasi microsoft visual studio 2022
- Buka folder project
- Tekan tombol run

### Rest-API
- Clone repository ini ```git clone https://github.com/fushigo/GoBanking```
- Masuk ke folder rest-api ```cd rest-api```
- Buat file .env dan tambahkan ```DATABASE_URL= "URL DATABASE ANDA"```
- ``` bash
  #instalation
  npm install

  #building
  npm run build
  
  #running
  npm run start
  ```
- Buka browser dan akses rest-api di http://localhost::3000

## Kontributor
 - [Rizky Andika Sukma](https://github.com/fushigo)
 - [Anang Setaji](https://github.com/iKzuu)
 - [Ahi Kurniawan](https://github.com/Strangerr01)
 - [Rizal Tegar]("/")
