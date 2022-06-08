#include<iostream>
#include<climits>
#include<vector>
#include<map>
#include<queue>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;

    int sum = 0;
    int ans = INT_MAX;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    
    for(int i=0; i<k; i++){
        sum += a[i];
    }

    ans = min(ans, sum);
    for(int i=1; i<n-k+1; i++){
        sum -= a[i-1];
        sum += a[i+k-1];
        ans = min(ans, sum);
    }

    cout<<ans<<endl;
    return 0;
}