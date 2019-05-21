#include<bits/stdc++.h>
using namespace std;

const long long int n=100000;             // max input range

void merge_arr(int arr[2][n],int l,int m,int r) {
    int i, j, k;
    int n1=m-l+1;
    int n2=r-m;
    int Left[2][n1], Right[2][n2];

    for (i=0;i<n1;i++) {
        Left[0][i] = arr[0][l+i];           // copy val
        Left[1][i] = arr[1][l+i];           // copy index
    }
    for (j=0;j<n2;j++) {
        Right[0][j] = arr[0][m+1+j];
        Right[1][j] = arr[1][m+1+j];
    }

    i = 0;   //for first subarray
    j = 0;   //for second subarray
    k = l;   //for merged array

    while (i<n1 && j<n2) {
        if (Left[0][i]<=Right[0][j]) {
            arr[0][k]=Left[0][i];
            arr[1][k]=Left[1][i];
            i++;
        }
        else {
            arr[0][k]=Right[0][j];
            arr[1][k]=Right[1][j];
            j++;
        }
        k++;
    }
    // remaining element direct copy
    while(i<n1) {
        arr[0][k]=Left[0][i];
        arr[1][k]=Left[1][i];
        i++;
        k++;
    }
    while(j<n2) {
        arr[0][k]=Right[0][j];
        arr[1][k]=Right[1][j];
        j++;
        k++;
    }
}

void m_sort(int arr[2][n], int l, int r) {
    if (l<r) {
        int m = l+(r-l)/2;
        m_sort(arr, l, m);  // sort first
        m_sort(arr, m+1, r); // sort second
        merge_arr(arr,l,m,r); // merge sorted parts
    }
}
int main () {
   int i,j,x,y,maxi,n1;
   int v[2][n];

   cout<<"Enter the number of values entered by user"<<endl;
   cin>>n1;

   cout<<"Enter each of the pairs with space in between"<<endl;
   cin>>x>>y;

   maxi=y;                  //to find max y coordinate
   v[0][0]=x;
   v[1][0]=y;

   for(j=1;j<n1;j++) {
        cin>>x>>y;
        v[0][j]=x;
        v[1][j]=y;
        if (y>maxi)
            maxi=y;        // max y
   }

   int k = maxi;
   int ct=0;               // count variable
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


    m_sort(v1,0,n1-1);                                  // sorting the linear array inclusive of swapping their respective index


    cout<<"Sorted array: "<<endl;

    for(j=0;j<n1;j++)

        cout<<"("<<v[0][v1[1][j]]<<","<<v[1][v1[1][j]]<<") ";           // printing original array with the found sequence of index
}



