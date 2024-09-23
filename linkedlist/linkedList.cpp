# include <iostream>
using namespace std;

template <typename T>
class ListNode{
    public:
        ListNode(T value){
            this->value = value;
            nextNode = nullptr;
        }
        T getValue(){
            return value;
        }
        ListNode<T>* nextNode;
    private:
        T value;
        
};
template <typename T>
void freeMemory(ListNode<T>*head){
    while (head!=nullptr) {
        ListNode<T>*temp = head;
        head = temp->nextNode;
        delete temp;
    }
}
template <typename T>
//Insert Node
void insertNode(ListNode<T>* c, ListNode<T>* p){
    ListNode<T> * temp = c->nextNode;
    c->nextNode = p;
    p->nextNode = temp;
}
template <typename T>
//Delete Node
void remove(ListNode<T>* n0){
    if (n0->nextNode == nullptr) return;
    ListNode<T>* temp = n0->nextNode;
    ListNode<T>* n1 = temp->nextNode;
    n0->nextNode = n1;
    delete temp;
}

template <typename T>
void printElement(ListNode<T>* head) {
    ListNode<T>* node = head;
    while (node!=nullptr) {
        cout<<node->getValue()<<endl;
        node = node->nextNode;
    }
    
}
template <typename T>
T findIndex(ListNode<T>* head, T target){
    int index = 0;
    while (head!=nullptr) {
        if (head->getValue()==target) return index;
        head = head->nextNode;
        index++;
    }
    return -1;
}


int main(){
    ListNode<int>* a = new ListNode<int>(4);
    ListNode<int>* b = new ListNode<int>(5);
    ListNode<int>* c = new ListNode<int>(6);
    a->nextNode = b;
    b->nextNode = c;
    cout<<"first"<<endl;
    printElement(a);
    remove(b);
    cout<<"second"<<endl;
    printElement(a);
    cout<<"third"<<endl;
    ListNode<int>* d = new ListNode<int>(10);
    insertNode(a, d);
    printElement(a);
    cout<<"fourth"<<endl;
    cout<<findIndex(a,10)<<endl;
}