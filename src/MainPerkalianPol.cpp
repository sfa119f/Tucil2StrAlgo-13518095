#include "MakePrintPol.hpp"
#include "BFPerkalianPol.hpp"
#include "DCPerkalianPol.hpp"
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    cout<<endl;
    vector<int> a, b, BF, DC;
    KoefPol(a,n+1);
    KoefPol(b,n+1);
    cout<<"Polinom A :"<<endl;
    PrintPol(a);
    cout<<endl;
    cout<<"Polinom B :"<<endl;
    PrintPol(b);
    cout<<endl;
    BFMethod(a,b,BF);
    cout<<"Hasil perkalian Polinom dengan BF :"<<endl;
    PrintPol(BF);
    cout<<endl;
    DCMethod(a,b,DC);
    cout<<"Hasil perkalian Polinom dengan DC :"<<endl;
    PrintPol(DC);
}
