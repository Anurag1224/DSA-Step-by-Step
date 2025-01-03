// Floyd's triangle pattern

// 1
// 2 3
// 4 5 6
// 7 8 9 10

#include <iostream>
using namespace std;

int main() {
    
    int n, num=1;
    cout<<"Enter the value of n ";
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout<<num<<" ";
            num++;
        }
        cout<<endl;
    }
    return 0;
}