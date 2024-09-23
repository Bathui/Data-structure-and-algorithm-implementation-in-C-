#include<iostream>
#include<unordered_set>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
struct Vertex{
    int val;
    Vertex(int x):val{x}{}
};
class GraphAdjList{
    public:
        unordered_map<Vertex*, vector<Vertex*>>adjList;
    public:
        GraphAdjList() = default;
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
void dfsHelper(vector<Vertex*>& res,GraphAdjList &graph, unordered_set<Vertex*>&visited, Vertex* vet){
    res.push_back(vet);
    visited.insert(vet);
    for(Vertex* adjVet: graph.adjList[vet]){
        if(visited.count(adjVet))
            continue;
        dfsHelper(res, graph, visited, adjVet);
    }
}
vector<Vertex*> dfs(Vertex* start, GraphAdjList& g){
    vector<Vertex*> res;
    unordered_set<Vertex*> visited; 
    dfsHelper(res, g, visited, start);
    return res;
}

int main(){
    Vertex* a = new Vertex(0);
    Vertex* b = new Vertex(1);
    Vertex* c = new Vertex(2);
    Vertex* d = new Vertex(3);
    Vertex* e = new Vertex(4);
    Vertex* f = new Vertex(5);
    Vertex* g = new Vertex(6);
    Vertex* h = new Vertex(7);
    Vertex* k = new Vertex(8);

    GraphAdjList gp;
    gp.addVertex(a);
    gp.addVertex(b);
    gp.addVertex(c);
    gp.addVertex(d);
    gp.addVertex(e);
    gp.addVertex(f);
    gp.addVertex(g);
    gp.addVertex(h);
    gp.addVertex(k);

    gp.addEdge(a,b);
    gp.addEdge(a,d);
    gp.addEdge(b,c);
    gp.addEdge(b,e);
    gp.addEdge(c,f);
    gp.addEdge(d,e);
    gp.addEdge(d,g);
    gp.addEdge(e,f);
    gp.addEdge(e,h);
    gp.addEdge(f,k);
    gp.addEdge(g,h);
    gp.addEdge(h,k);

    // gp.print();
    vector<Vertex*> v = dfs(a, gp);
    // cout<<v[0]->val<<endl;
    for(Vertex* x: v){
        cout<<x->val<<endl;
    }
}