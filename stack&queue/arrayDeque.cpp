# include <iostream>
# include <vector>
using namespace std;

class ArrayDeque{
    private:
        vector<int> nums;
        int front;
        int queueSize;

    public:
        ArrayDeque(int capacity){
            nums.resize(capacity);  // we have already initialize in here with number zero.
            front = queueSize = 0;
        }

        int capacity(){
            return nums.size();
        }

        int size(){
            return queueSize;
        }

        bool isEmpty(){
            return queueSize==0;
        }

        int index(int i){
            return (i+capacity())%capacity();
        }
        void pushFront(int val){
            if(capacity()==queueSize){
                throw out_of_range("it's full");
            }
            else{
                front = index(front-1);
                nums[front] = val;
                queueSize++;
            }
        }

        void pushLast(int val){
            if (capacity() == queueSize){
                cout<<"It's full"<<endl;
                return;
            }
            int rear = index(front+queueSize);
            nums[rear-1] = val;
            queueSize--;
        }
        
        int popFirst(){
            if (queueSize == 0){
                cout<<"It's empty."<<endl;
                return;
            }
            int val = peekFirst();
            front = index(front+1);
            return val;
        }

        int popLast(){
            int last = peekLast();
            queueSize--;
            return last;
        }
        int peekFirst(){
            if (isEmpty())
                throw out_of_range("queue is empty.");
            return nums[front];
        }
        int peekLast(){
            if (isEmpty())
                throw out_of_range("queue is empty.");
            int val = index(front+queueSize-1);
            return nums[val];
        }
        
        vector<int> toVector(){
            vector<int> res(queueSize);
            for (int i = 0, j = front; i < queueSize; i++, j++) {
                res[i] = nums[index(j)];
            }
            return res;
        }
};
