// WAP to print nth fibonacci

#include<iostream>
using namespace std;

void fibonacci(int N){
    int a=0, b= 1, nextTerm;

    if(N<=0){
        cout<<"Enter a positive number";
    } else if (N == 1){
            cout<<"Fibonacci series upto "<<N<<" term : "<<a<<endl;
        }else{
            cout<<"Fibonacci series upto "<<N<<" term : ";

            for(int i=1; i<=N; i++){
                cout<<a<<" ";
                nextTerm = a+b;
                a=b;
                b= nextTerm;
            }
            cout<<endl;
        }
    }

int main(){

    int n;
    cout<<"Enter the number of terms : ";
    cin>>n;
    fibonacci(n);
    
    return 0;
}