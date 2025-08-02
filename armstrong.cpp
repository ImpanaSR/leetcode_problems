#include<iostream>
using namespace std;

int armstrong(int n){
    int copyN=n;
    int sumOfCubes=0;

    while(n!=0){
        int dig = n%10;
        sumOfCubes += (dig*dig*dig);

        n=n/10;
    }
    return sumOfCubes == copyN;
}
int main() {
    int  n = 153;

    if(armstrong(n)){
        cout<<"is a armstrong"<<endl;
    }else{
        cout<<"not a armstrong"<<endl;
    }
}