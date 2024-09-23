#include<iostream>
#include<vector>
using namespace std;
class graphAdjMat{
    private:
        vector<int> vertices;
        vector<vector<int>> adjMat;
    public:
        graphAdjMat(const vector<int>&vertices,  const vector<vector<int>> &edges){
            for(int val: vertices){
                addVertex(val);
            }
            for(const vector<int> &edge: edges){
                addEdges(edge[0], edge[1]);
            }
        }
        void addVertex(int val){
            int n = size();
            vertices.push_back(val);
            adjMat.push_back(vector<int>(n,0));
            for (vector<int>&row:adjMat) {
                row.push_back(0);
            }
        }
        void removeVertex(int index){
            if(index>=size()){
                throw out_of_range("not exist");
            }
            //delete the row
            vertices.erase(vertices.begin()+index);
            //delete the column
            for(vector<int>row:adjMat){
                row.erase(row.begin()+index);
            }
        }

        void addEdges(int i, int j){
            if(i<0||j<0||i>=size()||j>=size()||i==j)
                throw out_of_range("does not exist");
            adjMat[i][j] = 1;
            adjMat[j][i] = 1;
        }
        void removeEdges(int i, int j){
            if(i<0||j<0||i>=size()||j>=size()||i==j)
                throw out_of_range("does not exist");
            adjMat[i][j] = 0;
            adjMat[j][i] = 0;
        }
        int size(){
            return vertices.size();
        }
};
