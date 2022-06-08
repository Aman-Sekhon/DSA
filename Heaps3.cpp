#include<iostream>
#include<queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pqmin;
priority_queue<int, vector<int>> pqmax;

void insert(int x){
    if(pqmax.size() == pqmin.size()){
        if(pqmax.size() == 0){
            pqmax.push(x);
        }
        else{
            if(x > pqmax.top()){
                pqmin.push(x);
            }
            else{
                pqmax.push(x);
            }
        }
    } else{
        if(pqmax.size() > pqmin.size()){
            if(x >= pqmax.top()){
                pqmin.push(x);
            } else{
                int temp = pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);
            }
        } else{
            if(x >= pqmin.top()){
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
            } else{
                pqmax.push(x);
            }
        }
    }
}

double findMedian(){
    if(pqmax.size() == pqmin.size()){
        return (pqmax.top() + pqmin.top())/2;
    } else if(pqmax.size() > pqmin.size()) {
        return pqmax.top();
    } else{
        return pqmin.top();
    }
}

int main(){
    insert(19);
    cout<<findMedian()<<endl;
    
    insert(18);
    cout<<findMedian()<<endl;
    
    insert(30);
    cout<<findMedian()<<endl;
    
    insert(21);
    cout<<findMedian()<<endl;
    
    insert(15);
    cout<<findMedian()<<endl;
    
    insert(10);
    cout<<findMedian()<<endl;
    return 0;
}