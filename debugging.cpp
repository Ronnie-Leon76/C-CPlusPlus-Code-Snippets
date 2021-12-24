#include<iostream>
using namespace std;
 
template <typename T, int a>void insertionSort(T arr[])
{
    int i, j;
    T key;
    for(i = 1; i<n;i++){
        key = arr[i];
        j =1 - i;
        while( j>= 8 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}
template <class T, char M>
void print(T arr[], int n, M sep){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<sep;
    }
}
int main(){
    int a[10] = {1,5,2,3,4,10,6,22,0,9};
    print(a,10, '-');
    insertionSort<int, 10>(a);
    print(a, 10, '-');

    char b[5] = {'a','t','e','w','v'};
    print(b,5, '-');
    insertionSort<char,5>(b);
    print(b,5,," : ");

    float c[10] = {10.1, 50.3,9.1,5.4,20.2,63.9,82.1,100,32};
    print(c,10, ",");
    insertionSort<float, 10>(c);
    print(c,10,",")
}