#include<iostream>
#include<vector>
using namespace std;
void binarySearch(vector<int>&a, int num){
    int first = 0;
    int last = a.size()-1;
    while(first<=last){
        int mid = first+1/2*(first-last);
        if(a[mid]==num){
            cout<<"found!"<<endl;
            break;
        }
        else if(a[mid]>num)
            last = mid-1;
        else
            first = mid+1;
    }
    if(first>last)
        cout<<"not found"<<endl;
}

int binarySearchInsertion_simple(vector<int>& vec, int num){ // this is the insertion function for the array that does not contain the num
    int i = 0, j = vec.size()-1;
    while(i<=j){
        int mid = i+(j-i)/2;
        if(vec[mid] == num) 
            return mid;
        else if(vec[mid]>num)
            j = mid-1;
        else
            i = mid + 1;
    }
    return i;
}

int binarySearchInsertion(vector<int>& vec, int num){
    int i = 0, j = vec.size()-1;
    while(i<=j){
        int mid = i+(j-i)/2;
        if(vec[mid]>num)
            j = mid-1;
        else if(vec[mid]<num)
            i = mid+1;
        else
            j = mid-1;
    }
    return i;       
}
int bs_LeftEdge(vector<int>&v, int num){
    int i = binarySearchInsertion(v, num);
    if(v[i]!=num||i==v.size())
        return -1;
    else{
        return i;
    }
}

int bs_RightEdge(vector<int>&v, int num){
    int i = bs_LeftEdge(v, num+1)-1;
    if(v[i]!=num||i<0)
        return -1;
    return i;
}

int main(){
    vector <int> a{1,2,3,4,5,6};
   
    binarySearch(a,2);
}