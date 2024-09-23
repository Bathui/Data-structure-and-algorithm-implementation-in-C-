#include <iostream>
#include <vector>
using namespace std;

struct Pair{
    int key;
    string value;
    Pair(int key, string value){
        this->key = key;
        this->value = value;
    }
};
class HashTable{
    private:
        int capacity = 4, extendRatio = 2;
        const double loadThres = 2.0/3.0;
        vector<Pair*> buckets;
        int size;
        Pair* TOMBSTONE = new Pair{-1, "-1"};

    public:
        HashTable():size{0}, buckets(capacity, nullptr){  // in here using braces will cause confusion
                                                          // there is another way of using initialize-list to construct it 
        }
        int hashFunction(int key){
            return key%capacity;
        }
        
        double loadFactor(){
            return (double)size/capacity;
        }

        int findBucket(int key){
            int index = hashFunction(key);
            int firstTombStone = -1;
            while (buckets[index]!=nullptr) {
                if(key==buckets[index]->key){
                    if(firstTombStone!=-1){
                        buckets[firstTombStone] = buckets[index];
                        buckets[index] = TOMBSTONE;
                        return firstTombStone;
                    }
                    return index;
                }
                if (firstTombStone==-1&&buckets[index]==TOMBSTONE) {
                    firstTombStone = index;
                }
                index = (1+index)%capacity;
            }
            return (firstTombStone==-1)? index:firstTombStone; 
        }
        string get(int key){
            int index = findBucket(key);
            if(buckets[index] != nullptr&&buckets[index]!=TOMBSTONE){
                    return buckets[index]->value;
            }
            return "";
        }

        void put(int key, string value){
            // cout<<"check"<<endl;
            if (loadFactor()>loadThres) extend();

            int index = findBucket(key);
            if(buckets[index]!=nullptr&&buckets[index]!=TOMBSTONE){
                buckets[index]->value = value;
                return;
            }
            buckets[index] = new Pair(key, value);
            size++;
        }

        void remove(int key){
            int index = findBucket(key);
            if(buckets[index]!=nullptr&&buckets[index]!=TOMBSTONE){
                delete buckets[index];
                buckets[index] = TOMBSTONE;
                size--;
            }
        }
        void extend(){
            capacity *= extendRatio;
            vector <Pair*> tmp = buckets;
            buckets.clear();
            buckets = vector<Pair*>(capacity, nullptr);
            size = 0;
            for (Pair*p:tmp) {
                if(p!=nullptr||p!=TOMBSTONE) {
                    put(p->key, p->value);
                    delete p;
                }
            }
            tmp.clear();
        }
        
        void print(){
            for(Pair*p:buckets){
                if(p==nullptr){
                    cout<<"NUll pointer"<<endl;
                }
                else if(p==TOMBSTONE) 
                    cout<<"TOMBSTONE"<<endl;
                else
                    cout<<p->key<<"->"<<p->value<<endl;
            }
        }
};
int main(){
    HashTable a;
    a.put(2,"hello");
    a.put(3,"well");
    a.put(5, "farewell");
    a.print();
    a.remove(2);
    a.print();
}