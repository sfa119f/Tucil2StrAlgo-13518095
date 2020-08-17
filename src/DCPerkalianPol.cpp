//
#include "DCPerkalianPol.hpp"
#include <time.h>
#include <vector>
#include <iostream>
using namespace std;

void DCMethod(vector<int> a, vector<int> b, vector<int> &h){
    int plusOp=0, timesOp=0;
    double t1 = clock();
    Karatsuba(a,b,h,&plusOp,&timesOp);
    //PrintPol(h);
    double t2 = clock();
    cout<<"Waktu proses DC   : "<<double((t2-t1)*1000)/CLOCKS_PER_SEC<<" ms"<<endl;
    cout<<"Operasi tambah DC : "<<plusOp<<endl;
    cout<<"Operasi kali DC   : "<<timesOp<<endl;
}

void Karatsuba(vector<int> a, vector<int> b, vector<int> &h, int *plusOp, int *timesOp){
    if(a.size()==1 && b.size()==1){
        h.push_back(a[0]*b[0]);
        *timesOp+=1;
    }
    else{
        vector<int> a0, a1, b0, b1;
        vector<int> c0, c1, c2;
        vector<int> temp0, temp1, temp2;
        vector<int> r, s;
        
        //Pecah Polinomial
        Reduce(a, a0, a1);
        Reduce(b, b0, b1);

        //menghitung c0,c1,c2
        Karatsuba(a0, b0, c0, plusOp, timesOp);
        Karatsuba(a1, b1, c2, plusOp, timesOp);

        SumPol(a0, a1, temp0);
        *plusOp+= Smallest(a0.size(), a1.size());
        SumPol(b0, b1, temp1);
        *plusOp+= Smallest(b0.size(), b1.size());
        Karatsuba(temp0, temp1, temp2, plusOp, timesOp);

        SumPol(c0, c2, r);
        *plusOp+= Smallest(c0.size(), c1.size());
        MinusPol(temp2, r, c1);
        *plusOp+= Smallest(temp2.size(), r.size());

        //gabung c0,c1,c2
        SwipeRPol(c1, a0.size());
        SwipeRPol(c2, a0.size()*2);
        SumPol(c1,c2,s);
        *plusOp+= Smallest(c1.size(), c2.size());
        SumPol(c0,s,h);
        *plusOp+= Smallest(c0.size(), s.size());
    }
}

void Reduce(vector<int> a, vector<int> &h1, vector<int> &h2){
    for(int i=0; i<a.size()/2; i++) h1.push_back(a[i]);
    for(int i=a.size()/2; i<a.size(); i++) h2.push_back(a[i]);
}

void SumPol(vector<int> a, vector<int> b, vector<int> &h){
    int n, hn;
    if(a.size()>b.size()){
        hn=a.size(); n=b.size();
        for(int i=n; i<hn; i++) h.push_back(a[i]);    
    }
    else{
        hn=b.size(); n=a.size();
        for(int i=n; i<hn; i++) h.push_back(b[i]);
    }
    for(int i=n-1; i>=0; i--) h.insert(h.begin(), a[i]+b[i]);
}

void MinusPol(vector<int> a, vector<int> b, vector<int> &h){
    int n, hn;
    if(a.size()>b.size()){
        hn=a.size(); n=b.size();
        for(int i=n; i<hn; i++) h.push_back(a[i]);    
    }
    else{
        hn=b.size(); n=a.size();
        for(int i=n; i<hn; i++) h.push_back(b[i]*-1);
    }
    for(int i=n-1; i>=0; i--) h.insert(h.begin(), a[i]-b[i]);
}

int Smallest(int a, int b){
    if(a>b) return b;
    else return a;
}

void SwipeRPol(vector<int> &a, int n){
    int degree = a.size()-1;
    for(int i=0; i<n; i++) a.push_back(0);
    for(int i=degree; i>=0; i--) a[i+n] = a[i];
    for(int i=0; i<n; i++) a[i]=0;
}