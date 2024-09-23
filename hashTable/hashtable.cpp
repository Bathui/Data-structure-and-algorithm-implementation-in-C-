# include <iostream>
# include <vector>
using namespace std;
struct Pair {
    int key;
    string value;
    Pair(int key, string value){
        this->key = key;
        this->value = value;
    }
};

class hashTable{
    private:
        vector <Pair*> buckets;
    public:
        hashTable(){
            buckets = vector<Pair*>(100);
        }
        ~hashTable(){
            for (auto a:buckets) {
                delete a;
            }
            buckets.clear();
        }
        
        int hashFunc (int key) {
            int index = key%100;
            return index;
        }
        

        // search function
        string get (int key){
            int index = hashFunc(key);
            Pair* p = buckets[index];
            return (p==nullptr)?"": p->value;
        }

        void put(int key, string value){
            int index = hashFunc(key);
            Pair* p = new Pair(key, value);
            buckets[index] = p;
        }
        void remove (int key) {
            int index = hashFunc(key);
            delete buckets[index];
            buckets[index] = nullptr;
        }

        // Get all the value in the hashtable   
        vector<Pair*> getPairs(){
            vector <Pair*> p;
            for (Pair* a:buckets) {
                if (a != nullptr)
                    p.push_back(a);
            }
            return p;
        }

        vector<string> getValue(){
            vector<string> v;
            for (Pair* a:buckets){
                if (a!=nullptr){
                    v.push_back(a->value);
                }
            }
            return v;
        }

        vector<int> getKey(){
            vector<int> k;
            for (Pair* a:buckets){
                if (a!=nullptr){
                    k.push_back(a->key);
                }
            }
            return k;
        }

        void printAll(){
            for (Pair*a:getPairs())
                cout<<a->key<<"->"<<a->value<<endl;
        }
};

int main(){
    hashTable a;
    a.put(34,"got cha!");
    a.put(37,"oh yeah!");
    a.printAll();
}