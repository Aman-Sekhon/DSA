#include<bits/stdc++.h>
using namespace std;
struct Item
{
    int value, weight;

    Item(int value, int weight){
        this->value = value;
        this->weight = weight;
    }
};

bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value/(double)a.weight;
    double r2= (double)b.value/ (double)b.weight;
    return r1>r2;
}
double fractionalknapsack(int w, struct Item arr[], int n)
{
    sort(arr, arr+n, cmp);

    int currentweight = 0;
    double finalvalue=0.0;

    for(int i =0; i<n; i++){
        if( currentweight + arr[i].weight <= w){
            currentweight += arr[i].weight;
            finalvalue += arr[i].value;
        } else {
            int remaining = w-currentweight;
            finalvalue += arr[i].value * ((double)remaining/(double)arr[i].weight);
            break;
        }
    }

    return finalvalue;
}

int32_t main(){
    int w = 50;
    Item arr[] = {{60,10}, {100, 20}, {120, 30}};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Maximum value that we can obtain: " << fractionalknapsack(w, arr, n) << endl;
    return 0;
}