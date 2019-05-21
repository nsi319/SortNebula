#include<bits/stdc++.h>
using namespace std;

const long long int n=100000;

void swap_func(int* a, int* b){
    int t =*a;
    *a =*b;
    *b =t;
}
int part(int arr[2][n],int low,int high) {
    int pivot =arr[0][high];                // fixing pivot
    int i =(low - 1);

    for(int j=low;j<=high-1;j++) {
        if (arr[0][j]<=pivot) {
            i++;
            swap_func(&arr[0][i], &arr[0][j]); // swap values
            swap_func(&arr[1][i], &arr[1][j]); // swap index too
        }
    }
    swap_func(&arr[0][i + 1], &arr[0][high]); // swap value
    swap_func(&arr[1][i + 1], &arr[1][high]); // swap index

    return (i + 1);
}


void q_sort(int arr[2][n],int low,int high) {
    if (low<high) {
        int pi = part(arr, low, high);
        q_sort(arr,low,pi - 1);
        q_sort(arr,pi + 1,high);
    }
}

int main () {
   int i,j,x,y,maxi,n1;
   cout<<"Enter the number of values entered by user"<<endl;
   cin>>n1;
   int v[2][n];
   cin>>x>>y;
   maxi=y;                  //to find max y coordinate
   v[0][0]=x;
   v[1][0]=y;
   for(j=1;j<n1;j++) {
        cin>>x>>y;
        v[0][j]=x;
        v[1][j]=y;
        if(y>maxi)
            maxi=y;        // max y
   }
   int k = maxi;
   int ct=0;
   while(k>0) {
        ct++;               // no of digits of max of y
        k=k/10;
   }
   int val = pow(10,ct);
   int v1[2][n];
   for(j=0;j<n1;j++) {
        v1[0][j] = v[0][j]*val + v[1][j];                // combining the (x,y) as val*x + y for sorting linear array
        v1[1][j]=j;
    }


    q_sort(v1,0,n1-1);                                   // sorting the linear array inclusive of swapping their respective index
  

    cout<<"Sorted array: "<<endl;

    for(j=0;j<n1;j++)
        cout<<"("<<v[0][v1[1][j]]<<","<<v[1][v1[1][j]]<<") ";           // printing original array with the found sequence of index
}



