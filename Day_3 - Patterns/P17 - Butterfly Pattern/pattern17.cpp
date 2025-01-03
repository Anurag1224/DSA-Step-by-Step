// Butterfly Pattern

// *             *
// * *         * *
// * * *     * * *
// * * * * * * * *
// * * * * * * * *
// * * *     * * *
// * *         * *
// *             *

#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the value of n ";
    cin>>n;

    for(int i=0; i<n; i++){

        //stars
        for(int j=0; j<=i; j++){
            cout<<"*";
        }
        //spaces
        for(int j=0; j<2*(n-i-1); j++){
            cout<<" ";
        }
        //stars
        for(int j=0; j<i+1; j++){
            cout<<"*";
        }
        
        cout<<endl;
    }

    for(int i=0; i<=n-1; i++){
        
        //stars
        for(int j=0; j<n-i; j++){
            cout<<"*";
        }
        //spaces
        for(int j=0; j<2*i; j++){
            cout<<" ";
        }
        //stars
        for(int j=0; j<n-i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}