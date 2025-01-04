// Functions to print binomial coefficient nCr for n and r 

#include<iostream>
using namespace std;

int factN(int a){
    int fact = 1;
    for(int i = 1; i<=a; i++){
        fact*=i;
    }
    return fact;
}

int nCr(int n, int r){
    int fact_n = factN(n);
    int fact_r = factN(r);
    int fact_nmr = factN (n-r);

    return fact_n/(fact_r * fact_nmr);
}

int main(){
    int n,r;
    cout<<"Enter the value of "<<endl;
    cout<<"n = ";
    cin>>n;
    cout<<"r = ";
    cin>>r;
    cout<<nCr(n,r)<<endl;
    cout<<"binomial coefficient of "<< n<<"C"<<r << " is "<<factN(n)/(factN(r)* factN(n-r));
    return 0;
}