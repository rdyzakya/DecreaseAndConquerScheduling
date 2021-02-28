# Tugas Kecil 2 Strategi Algoritma
Randy's Scheduling Algorithm (RSA)
*bukan algoritma kriptografi*

##Penjelasan :

Program ini bertujuan untuk menjadwalkan rencana mata kuliah dari file input txt user. Pada program ini diimplementasikan algoritma topological sort yang memakai strategi decrease and conquer. Decrease and Conquer merupakan strategi algoritma dalam menyelesaikan sebuah upa persoalan dengan setiap iterasi (atau rekursi) menjadi upa persoalan yang lebih kecil (bahkan memungkinkan sampai tidak ada upa persoalan lagi). Penjelasan rinci terkait algoritma topological sort di dalam program yaitu sebagai berikut:
1. File txt akan dibaca kemudian dikonversi menjadi graf berarah dengan definisi tiap entitasnya seperti pada source code program (Inisialisasi nilai-nilai graf)
2. Akan ditelusuri untuk semua node pada graf yang tidak memiliki predecessor (atau bisa dikatakan derajat masuknya = 0)
3. Node tanpa predecessor akan dihapus dari graf dan dimasukkan ke dalam sebuah senarai yang berisi node solusi untuk rekursi yang sekarang
4. Untuk node yang tersisa pada graf, hilangkan panah yang masuk yang diakibatkan oleh node yang telah dihapus (dalam program ini yaitu menghilangkan nama node predecessor dari senarai node predecessor pada atribut node)
5. Lakukan langkah 2-4 sampai semua node terpilih dan graf menjadi kosong(hanya berlaku untuk Directed Acyclic Graph)
6. Output solusi dari sorting node-node yang telah dipilih

##Cara menggunakan program :

1. Buka cmd (untuk Windows, untuk os lain perlu dicompile ulang untuk menyesuaikan ekstensi program)
2. Masuk ke dalam folder bin
3. Eksekusi program dengan mengetikkan nama program (disini program bernama RSA)
4. Masukkan nama file txt yang ada di dalam folder test (tanpa tambahan ".txt" saat menginput)

note : agar program dapat berjalan, file txt yang diinput harus berada di dalam folder test

'Author : Randy Zakya Suchrady - 13519061'