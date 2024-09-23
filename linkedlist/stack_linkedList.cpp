# include <iostream>
# include <vector>
using namespace std;
# include "ListNode.h"

class stack{
    private:
        ListNode<int>* head;
        int size;
    public:
        stack():head{nullptr}, size{0}{}
        ~stack(){
            freeMemory(head);
        }
        bool isEmpty(){
            return stack_size()==0;
        }
        int stack_size () {
            return size;
        }
        void push(int ele){
            ListNode<int>* temp = head;
            head = new ListNode<int>(ele);
            head->nextNode=temp;
            size++;
        }
        void pop(){
            int num = top();
            ListNode<int>* temp = head;
            head = temp->nextNode;
            delete temp;
            size--;
        }
        int top(){
            if(isEmpty()) 
                throw out_of_range("Stack is empty.");
            return head->getValue();
        }
};
int main(){
    return 1;
}