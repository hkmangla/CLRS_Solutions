#include "bits/stdc++.h"
using namespace std;
int mergeInversion(int a[],int p,int q,int rr){
	int n1 = q-p+1;
	int n2 = rr-q;
	int l[n1+1],r[n2+1];
	int j=0,k=0;
	for(int i=0;i<n1;i++) l[i] = a[p+i];
	for(int i=0;i<n2;i++) r[i] = a[q+1+i];
	bool flag = false, flag2 = false;
	int ans = 0;
	for(int i=p;i<=rr;i++){
		if(!flag and (flag2 or l[j]<=r[k])){
			a[i] = l[j];
			ans += k;
			j++;
			if(j==n1) flag = true;
		}
		else{
			a[i] = r[k];
			k++;
			if(k==n2) flag2 = true;
		}
	}
	return ans;
}

int Inversions(int arr[], int a,int b){
	if(b<=a) return 0;
	int mid = (a+b)/2;
	int ans = 0;
	ans += Inversions(arr, a,mid);
	ans += Inversions(arr, mid+1,b);
	return ans + mergeInversion(arr,a,mid,b);
}
int main(){
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	cout<<Inversions(a,0,n-1)<<endl;
}