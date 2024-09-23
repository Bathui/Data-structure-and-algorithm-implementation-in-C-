#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<utility>
using namespace std;
struct Vertex{
    int val;
    Vertex(int x):val{x}{}
};

class GraphAdjList{
    private:
        unordered_map<Vertex*, vector<Vertex*>>adjList;
    public:
        GraphAdjList(const vector<vector<Vertex*>>&edges){
            for(vector<Vertex*>edge:edges){
                addVertex(edge[0]);
                addVertex(edge[1]);
                addEdge(edge[0],edge[1]);
            }
        }
        void remove(vector<Vertex*>&vec, Vertex *vet){
            for(int i = 0; i < vec.size();i++){
                if(vec[i]==vet){
                    vec.erase(vec.begin()+i);
                    break;
                }
            }
        }
        int size(){
            return adjList.size();
        }
        void addVertex(Vertex*a){
            if(adjList.count(a)){
                return;
            }
            adjList[a] = vector<Vertex*>();
        }
        void addEdge(Vertex*a, Vertex*b){
            if(!adjList.count(a)||!adjList.count(b)||a==b)
                throw invalid_argument("does not exist");
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        void removeVertex(Vertex* vet){
            if(!adjList.count(vet))
                throw invalid_argument("does not exist");
            adjList.erase(vet); //delete the linkedlist for vet
            for(auto &adj:adjList){
                remove(adj.second, vet);
            }
        }
        void print(){
            cout<<"Adjacent List:"<<endl;
            for(auto& adj:adjList){
                cout<<adj.first->val<<": "<<endl;
                printVector(adj.second);
            }
        }
        void printVector(vector<Vertex*> vec){
            for(auto a:vec){
                cout<<a->val<<" ";
            }
            cout<<"\n";
        }

};