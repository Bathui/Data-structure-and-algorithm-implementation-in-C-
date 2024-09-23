#ifndef LISTNODE_H
    #define LISTNODE_H
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
#endif