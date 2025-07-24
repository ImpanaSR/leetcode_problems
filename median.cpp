#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void merge(vector<int> num1, vector<int> num2, vector <int>& num3, int m, int n){
    int i=0,j=0,k=0;
    while(i<m && j<n){
        if(num1[i]<num2[j]){
            num3[k]=num1[i];
            i++;
            k++;
        }
        else{
            num3[k]=num2[j];
            j++;
            k++;
        }
    }
    while(i<m){
        num3[k]=num1[i];
        i++;
        k++;
    }
    while(j<n){
        num3[k]=num2[j];
        j++;
        k++;
    }
}

int main(){

    vector<int>num1 = {1,3,5};
    vector<int>num2 = {2,4,6};
    int m = num1.size();
    int n = num2.size();
    vector<int> num3(m+n);

    merge(num1, num2, num3, m, n);

    cout<<"Merged array: ";
    for(int x: num3){
        cout<<x<<endl;
    }

    double median;
    int total = m+n;
    if(total % 2==0){
        median = (num3[total/2-1]+num3[total/2])/2.0;
    }
    else{
        median = num3[total/2];
    }
    cout<<"Median: "<<median<<endl;
    return 0;
}
// using built-in functions

// double findMedian(vector<int> arr){
//     int n = arr.size();

//     sort(arr.begin(), arr.end());

//     if(n%2 != 0) {
//         return arr[n/2];
//     }
//     else {
//         return (arr[n/2-1] + arr[n/2])/2.0;
//     }
// }

// int main(){
//     vector<int> arr = {10, 30, 20, 40, 50};
//     double median = findMedian(arr);
//     cout<<"Median: "<<median<<endl;
//     return 0;
// }
