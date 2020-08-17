#ifndef MAKEPRINTPOL_H
#define MAKEPRINTPOL_H

#include <vector>
using namespace std;

void KoefPol(vector<int> &a, int n);
//Membuat polinom berderajat n dengan koefisiennya acak dari 0 hingga 10

void PrintPol(vector<int> a); 
//Print polinom berderajat

void AsgPrint(int n); 
//Print tanda dari sebuah konstanta untuk derajat>0

void ConsPrint(int n, int p); 
//Print konstanta polinom untuk derajat>0. Jika konstanta=1, maka tidak diprint ke layar

#endif