#include<bits/stdc++.h>
using namespace std;

class MonotonicStack {
    stack<int> st;
    vector<int> v;
    int n;
    public:
    MonotonicStack(vector<int>& arr) {
        v = arr;
        n = arr.size();
    }
    void nextGreater(vector<int>& ng){
        for(int i = n - 1; i >= 0; i--){
            if(st.empty()) ng[i] = n;
            else if(v[st.top()] > v[i]){
                ng[i] = st.top();
            }
            else{
                while(!st.empty() && v[st.top()] <= v[i]){
                    st.pop();
                }
                if(!st.empty()){
                    ng[i] = st.top();
                }
                else{
                    ng[i] = n;
                }
            }
            st.push(i); 
        }
        while(!st.empty())
            st.pop();
}

void nextSmaller(vector<int>& ns){
        for(int i = n - 1; i >= 0; i--){
                if(st.empty()) ns[i] = n;
                else if(v[st.top()] < v[i]){
                    ns[i] = st.top();
                }
                else{
                    while(!st.empty() && v[st.top()] >= v[i]){
                        st.pop();
                    }
                    if(!st.empty()){
                        ns[i] = st.top();
                    }
                    else{
                        ns[i] = n;
                    }
                }
                st.push(i); 
            }
            while(!st.empty())
                st.pop();
}
void previousGreater(vector<int>& pg){
    for(int i = 0; i < n; i++){
        if(st.empty()) pg[i] = -1;
        else if(v[st.top()] > v[i]){
            pg[i] = st.top();
        }
        else{
            while(!st.empty() && v[st.top()] < v[i]){
                st.pop();
            }
            if(!st.empty()){
                pg[i] = st.top();
            }
            else{
                pg[i] = -1;
            }
        }
        st.push(i);
    }
    while (!st.empty())
        st.pop();
}
void previousSmaller(vector<int>& ps){
    for(int i = 0; i < n; i++){
        if(st.empty()) ps[i] = -1;
        else if(v[st.top()] < v[i]){
            ps[i] = st.top();
        }
        else{
            while(!st.empty() && v[st.top()] > v[i]){
                st.pop();
            }
            if(!st.empty()){
                ps[i] = st.top();
            }
            else{
                ps[i] = -1;
            }
        }
        st.push(i);
    }
    while (!st.empty())
        st.pop();
}
};
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    MonotonicStack ms(v);
    vector<int> ng(n);
    vector<int> ns(n);
    vector<int> pg(n);
    vector<int> ps(n);
    ms.nextGreater(ng);
    ms.nextSmaller(ns);
    ms.previousGreater(pg);
    ms.previousSmaller(ps);
   
    for(int i = 0; i < n; i++){
        cout << "previous smaller of " << v[i] << " is at " << pg[i] << endl; 
    }
   
}