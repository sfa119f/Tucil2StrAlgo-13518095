#ifndef DCPERKALIANPOL_H
#define DCPERKALIANPOL_H

#include <vector>
using namespace std;

void DCMethod(vector<int> a, vector<int> b, vector<int> &h);
//Metode perkalian polinom a dan b menggunakan defide and conquer dengan hasil polinom h dan akan mencetak ke layar waktu, jumlah operasi tambah, dan jumlah operasi kali yang diperlukan

void Karatsuba(vector<int> a, vector<int> b, vector<int> &h, int *plusOp, int *timesOp);
//Algoritma karatsuba yang berbasis defide and conquer untuk menghitung perkalian polinom secara rekursif yang menghasilkan polinom h, jumlah operasi tambah plusOp, dan jumlah operasi kali timesOP

void Reduce(vector<int> a, vector<int> &h1, vector<int> &h2);
//Fungsi untuk membagi polinom a menjadi polinom h1 dan h2 dengan ukuran sama besar atau selisih 1

void SumPol(vector<int> a, vector<int> b, vector<int> &h);
//Fungsi untuk menjumlahkan polinom a dan b dan menghasilkan polinom h

void MinusPol(vector<int> a, vector<int> b, vector<int> &h);
//Fungsi untuk mengurangkan polinom a dengan b dan menghasilkan polinom h

int Smallest(int a, int b);
//Fungsi untuk menghasilkan integer nilai terkecil antara a dan b

void SwipeRPol(vector<int> &a, int n);
//Fungsi untuk mengalikan polinom a dengan x pangkat n

#endif