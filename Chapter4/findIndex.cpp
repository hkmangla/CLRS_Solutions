#include "bits/stdc++.h"
using namespace std;
int m;
const int n = 4;

vector<int> mergeIndex(const vector<int>& res, int a[][n], int sz){
	std::vector<int> v;
	for(int i=0;i<sz;i++){
		int right;
		int left = res[i];
		if(i == sz-1 and res.size() == sz)
			right = n-1;
		else
			right = res[i+1];
		int minimum = a[i][left];
		int pos = left;
		for(int j=left;j<=right;j++){
			if(minimum > a[i][j]){
				minimum = a[i][j];
				pos = j;
			}
		}
		v.push_back(res[i]);
		v.push_back(pos);
	}
	if(res.size() > sz)
		v.push_back(res[res.size()-1]);
	return v;
}
vector<int> findIndex(int a[][n],int sz){
	if(sz == 1){
		int minimum = INT_MAX;
		std::vector<int> v;
		v.push_back(0);
		for(int i=0;i<n;i++){
			if(a[0][i] < minimum){
				minimum = a[0][i];
				v[0] = i;
			}
		}
		return v;
	}
	int b[sz/2 + 1][n], l=0;
	for(int i=0;i<sz;i+=2){
		for(int j=0;j<n;j++){
			b[i/2][j] = a[i][j];
		}
		l ++;
	}
	vector<int> evenResult = findIndex(b,l);
	l = 0;
	for(int i=1;i<sz;i+=2){
		for(int j=0;j<n;j++){
			b[i/2][j] = a[i][j];
		}
		l ++;
	}
	return mergeIndex(evenResult, b, l);
}
int main(){
	cin>>m;
	int a[m][n];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	vector<int> v = findIndex(a,m);
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
	return 0;
}