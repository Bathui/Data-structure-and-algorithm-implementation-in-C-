#include <iostream>
#include <vector>

using namespace std;
struct Pair {
    int key;
    string value;
    Pair(int key, string value){
        this->key = key;
        this->value = value;
    }
};
class Hashtable_SC{
    private:
        vector<vector<Pair*>> buckets;
        int size;
        int capacity;
        double loadThres;
        int extendRatio;
    
    public:
        Hashtable_SC():size(0),capacity(4),loadThres(3.0/4.0), extendRatio{2}{
            buckets.resize(capacity);
        }
        ~Hashtable_SC(){
            for (auto bucket: buckets) {
                for (Pair* p: bucket ) {
                    delete p;
                }
                bucket.clear();
            }
        }
        int hashFunc(int key){
            return key%capacity;
        }
        double loadFactor(){
            return (double)size/(double)capacity;
        }
        string get (int key){
            int index = hashFunc(key);
            for(Pair* p:buckets[index]){
                if(p->key==key) return p->value;
            }
            return "";
        }
        void put (int key, string value){
            if(loadFactor()>loadThres) extend();
            int index = hashFunc(key);
            for (Pair* p:buckets[index]) {
                if(p->key==key) {value = p->value; return;}
            }
            buckets[index].push_back(new Pair(key, value));
            size++;
        }

        void remove(int key){
            int index = hashFunc(key);
            auto& bucket = buckets[index];
            for (int i = 0; i < bucket.size(); i++) {
                if(bucket[i]->key==key){
                    Pair* tmp = bucket[i];
                    bucket.erase(bucket.begin()+i);
                    delete tmp;
                    size--;
                    return;
                }
            }
        }
        void extend(){
            cout<<"Start"<<endl;
            vector<vector<Pair*>> temp = buckets;
            capacity *= extendRatio;
            buckets.clear();
            size = 0;
            buckets.resize(capacity);
            for (auto& bucket:temp) {
                for (Pair*p:bucket) {
                    put(p->key, p->value);
                    delete p;
                }
                bucket.clear();
            }
        }

        void print(){
            for (auto& bucket:buckets) {
                for(Pair* p:bucket){
                    cout<<p->key<<"->"<<p->value<<endl;
                }
            }
        }
};
int main(){
    Hashtable_SC a;
    a.put(1, "helloworld");
    a.put(2, "hello");
    a.put(3, "world");
    a.put(4, "GOOd Job");
    a.print();
    a.put(5, "gOOd");
    a.put(6, "JoB");
    a.print();
}