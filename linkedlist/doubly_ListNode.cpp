# include <iostream>
# include <vector>
using namespace std;

struct DoublyListNode{
    int val;
    DoublyListNode* next;
    DoublyListNode* prev;
    DoublyListNode(int val):val{val}, next{nullptr}, prev{nullptr}{}
};

class LinkedListDeque{
    private:
        DoublyListNode* front, *rear;
        int queSize;
    public:
        LinkedListDeque():front(nullptr), rear(nullptr){}
        ~LinkedListDeque(){
            DoublyListNode* cur = front, *pre;
            while (cur!=nullptr) {
                pre = cur;
                cur = cur->next;
                delete pre;
            }
        }
        int size() {
            return queSize;
        }

        bool isEmpty(){
            return queSize==0;
        }

        void push (int num, bool isFront){
            DoublyListNode* node = new DoublyListNode (num);
            if (isEmpty()) 
                front = rear = node;
            else if (isFront){
                front->prev = node;
                node->next = front;
                front = node;
            }
            else{
                rear->next = node;
                node->prev = rear;
                rear = node;
            }
            queSize++;
        } 
        void pushFirst(int num){
            push(num, true);
        }
        void pushLast(int num){
            push(num, false);
        }
        int pop(bool isFront){
            if (isEmpty())
                throw out_of_range("The queue is empty.");
            int val;
            if(isFront){
                val = front->val;
                DoublyListNode* node = front->next;
                if (node!=nullptr){
                    node->prev = nullptr;
                    front->next = nullptr;
                }
                delete front;
                front = node;               
            } 
            else {
                val = rear->val;
                DoublyListNode* node = rear->prev;
                if (node!=nullptr){
                    node->next = nullptr;
                    rear->prev = nullptr;
                }
                delete rear;
                rear = node;
            }
            queSize--;
            return val;
        }
        int popFirst(){
            return pop(true);
        }
        int popLast(){
            return pop(false);
        }
        int peekFront(){
            if (isEmpty())
                throw out_of_range("The queue is empty.");
            return front->val;
        }
        int peekLast(){
            if(isEmpty())
                throw out_of_range("The queue is empty.");
            return rear->val;
        }
        
        vector<int> toVector(){
            DoublyListNode* node = front;
            vector <int> res(size());
            for (int i = 0; i < size(); i++) {
                res[i] = node->val;
                node = node->next;
            }
            return res;
        }
};
