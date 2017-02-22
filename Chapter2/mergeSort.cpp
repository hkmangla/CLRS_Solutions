#include "bits/stdc++.h"
using namespace std;
void merge(int a[],int p,int q,int rr){
	int n1 = q-p+1;
	int n2 = rr-q;
	int l[n1+1],r[n2+1];
	int j=0,k=0;
	for(int i=0;i<n1;i++) l[i] = a[p+i];
	for(int i=0;i<n2;i++) r[i] = a[q+1+i];
	bool flag = false, flag2 = false;
	for(int i=p;i<=rr;i++){
		if(!flag and (flag2 or l[j]<=r[k])){
			a[i] = l[j];
			j++;
			if(j==n1) flag = true;
		}
		else{
			a[i] = r[k];
			k++;
			if(k==n2) flag2 = true;
		}
	}
}

void mergeSort(int arr[], int a,int b){
	if(b<=a) return;
	int mid = (a+b)/2;
	mergeSort(arr, a,mid);
	mergeSort(arr, mid+1,b);
	merge(arr,a,mid,b);
}
int main(){
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	mergeSort(a,0,n-1);
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<endl;
}