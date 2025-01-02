// Print a pattern
// * * * * *
// * * * * *
// * * * * *
// * * * * *
// * * * * *

#include<iostream>
using namespace std;

int main() {

    int n=10;

    for(int i =0; i<n; i++){ // it will control the number of lines
        int m = 10;
        for(int j=0; j<m; j++){ // it will controll the no. of starts in each line
            cout<<"* ";
        }
        cout<<endl;

    }

    return 0;
}