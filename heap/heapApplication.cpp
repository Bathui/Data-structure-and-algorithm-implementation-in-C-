#include<iostream>
#include<queue>
#define min_heap priority_queue<int, vector<int>, greater<int>>
#define max_heap priority_queue<int, vector<int>, less<int>>
using namespace std;

int main(){
    min_heap a;
    max_heap b;
    b.push(3);
    b.push(4);
    b.push(5);

    b.pop();
    b.pop();
    b.pop();

    vector<int> v ={1,3,2,4,0};
    priority_queue<int, vector<int>, less<int>>(v.begin(), v.end());

    
}