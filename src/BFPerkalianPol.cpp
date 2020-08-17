#include "BFPerkalianPol.hpp"
#include <time.h>
#include <vector>
#include <iostream>
using namespace std;

void BFMethod(vector<int> a, vector<int> b, vector<int> &h){
    double t1 = clock();
    h.resize(a.size()+b.size()-1);
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<a.size(); j++){
            h[i+j]+=a[i]*b[j];
        }
    }
    double t2 = clock();
    cout<<"Waktu proses BF   : "<<t2-t1<<" ms"<<endl;
    cout<<"Operasi tambah BF : "<<a.size()*b.size()<<endl;
    cout<<"Operasi kali BF   : "<<a.size()*b.size()<<endl;
}