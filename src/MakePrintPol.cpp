#include "MakePrintPol.hpp"
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

void KoefPol(vector<int> &a, int n){
    for(int i=0; i<n; i++) a.push_back(rand()%11); 
}

void PrintPol(vector<int> a){
    if(a.size()>0){
        cout<<a[0] ;
        if(a.size()>1){
            ConsPrint(a[1], 1);
            for(int i=2; i<a.size(); i++){
                ConsPrint(a[i], i);
            }
        }
        cout<<endl;
    }
    else { cout<<"Tidak ada polinom"<<endl; }
}

void AsgPrint(int n){
    if(n<0) cout<<" - ";
    else cout<<" + ";
}

void ConsPrint(int n, int p){
    if(n!=0){
        AsgPrint(n);
        if(n!=1){
            if(n<1) cout<<n*-1;
            else cout<<n;
        }
        cout<<"x";
        if(p!=1) cout<<"^"<<p;
    }
}