#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
class MaxHeap{
    private:
        vector<int> max_heap;
        int size(){
            return max_heap.size();
        }
        int left(int i){
            return 2*i+1;
        }
        int right(int i){
            return 2*i+2;
        }
        int parent(int i){
            return (i-1)/2;
        }
        int max(){
            return max_heap[0];
        }
        void siftup(int i){
            while(true){
                int p = parent(i);
                if(p<0||max_heap[p]>=max_heap[i]){
                    break;
                }
                swap(max_heap[p], max_heap[i]);
                i = p;
            }
        }
        void siftDown(int i){
            while(true){
                int l = left(i);
                int r = right(i);
                int mx = i;
                if(l<size()&&max_heap[l]>max_heap[mx])
                    mx = l;
                if(r<size()&&max_heap[r]>max_heap[mx])
                    mx = r;
                if(mx==i)
                    break;
                swap(max_heap[i], max_heap[mx]);
                i = mx;
            }
        }

    public:
        void push(int val){
            max_heap.push_back(val);
            siftup(max_heap.size());
        }
        
        void pop(int i){
            if(max_heap.empty()){
                throw out_of_range("This is an empty heap!");
            }
            
            swap(max_heap[0], max_heap[size()-1]);
            max_heap.pop_back();
            siftDown(0);
        }

        MaxHeap(vector<int>& v){
            max_heap = v;
            for(int i = size()-1; i>=0; i--){
                siftDown(i);
            }
        }
};