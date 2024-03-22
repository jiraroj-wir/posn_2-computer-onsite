#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& h) {
    int l=0,r=h.size()-1,lmax=INT_MIN,rmax=INT_MIN,ans=0;
    while(l<r){
        lmax=max(lmax,h[l]);
        rmax=max(rmax,h[r]);
        ans+=(lmax<rmax)?lmax-h[l++]:rmax-h[r--];
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, nums;
    vector<int> v;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> nums;
        v.push_back(nums); 
    }

    cout << trap(v) << endl;

    return 0;
}