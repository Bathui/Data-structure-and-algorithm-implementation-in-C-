#include<iostream>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> topKheap(vector<int>&a,int k){
        if(k>a.size()){
            throw out_of_range("select too much");
        }
        priority_queue<int, vector<int>, greater<int>> heap;
        for(int i = 0; i < k; i++){
            heap.push(a[i]);
        }
        for(int i = k; i < a.size(); i++){
            if(heap.top()<a[i]){
                heap.pop();
                heap.push(a[i]);
            }

        }
        return heap;
}
int main(){
    vector <int> a {1,9,4,7,6};
    priority_queue<int, vector<int>, greater<int>> b= topKheap(a,3);
    while(!b.empty()){
        cout<<b.top()<<endl;
        b.pop();
    }
}