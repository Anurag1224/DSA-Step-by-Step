// square pattern for n

// 1 2 3 
// 4 5 6 
// 7 8 9

#include<iostream>
using namespace std;

int main() {
    int n, num=1;

    cout<<"Enter the value of n ";
    cin>>n;

    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<num<<" ";
            num = num++;
        }
        cout<<endl;
    }
    
    return 0;
}