# include <iostream>
# include <unordered_map>
# include <algorithm>
using namespace std;
int main(){
    unordered_map<int, string> map;
    map[12356] = "run";
    map[23414] = "executed";
    map[445234] = "finished";
    for (auto a:map) {
        cout<<a.first<<" "<<a.second<<endl;
    }
    
}