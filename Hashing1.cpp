#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<iomanip>     //for setting width
using namespace std;
int main(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    map<int, int> freq;
    for(int i=0; i<n; i++){
        freq[a[i]]++;
    }

    map<int,int> :: iterator it;
    for(it=freq.begin(); it!=end(); it++){
        cout << setw(2) << it->first << setw(3) << it->second << endl;
    }

    return 0;
}