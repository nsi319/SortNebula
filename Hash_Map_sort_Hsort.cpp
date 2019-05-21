#include<bits/stdc++.h>
using namespace std;

const long long int n=100000;      // max input range


void heapify(int arr[2][n],int n1,int i) {
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if (l < n1 && arr[0][l] > arr[0][largest])
		largest = l;

	if (r < n1 && arr[0][r] > arr[0][largest])
		largest = r;

	if (largest != i) {
		swap(arr[0][i], arr[0][largest]);
		swap(arr[1][i], arr[1][largest]);
		heapify(arr,n1,largest);
	}
}

void h_sort(int arr[2][n], int n1) {
	for (int i = n1 / 2 - 1; i >= 0; i--)
		heapify(arr,n1, i);

	for (int i=n1-1; i>=0; i--) {
		swap(arr[0][0],arr[0][i]);
		swap(arr[1][0],arr[1][i]);
		heapify(arr, i, 0);
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


    h_sort(v1,n1);                                  // sorting the linear array inclusive of swapping their respective index


    cout<<"Sorted array: "<<endl;

    for(j=0;j<n1;j++)

        cout<<"("<<v[0][v1[1][j]]<<","<<v[1][v1[1][j]]<<") ";           // printing original array with the found sequence of index
}




