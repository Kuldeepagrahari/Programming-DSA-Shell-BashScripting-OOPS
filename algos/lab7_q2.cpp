#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    char ch;
    Node* left;
    Node* right;
    // we cannot give argument char ch to constructor otherwise it will be using char ch of defined in Node not arguments'
    Node ( char c, int d ){
        data = d;
        left = nullptr;
        ch = c;
        right = nullptr;
    }
};
class cmp {
    public: 
    bool operator()(Node*a, Node*b ){
        return a->data > b->data;
    }
};

class huffman {
    public:

    
    void traverse( Node* root, vector<pair<char,string>> &ans, string temp ){

        if ( root -> left == nullptr && root -> right == nullptr ){
            ans.push_back ( { root->ch,temp } );
            return;
        }

        traverse ( root -> left, ans, temp+ '0' );
        traverse ( root-> right , ans, temp + '1' );
    }


    vector< pair < char, string > > huffman_encoding ( string s, vector<int> freq, int N ){

        priority_queue< Node*, vector<Node*> , cmp > pq;

        for ( int  i = 0 ;i < N ; i++ ){
            Node* newNode = new Node(s[i],freq[i]);
            pq.push ( newNode );
        }

        while ( pq.size() > 1 ){
            Node* l = pq.top();
            pq.pop();
            Node* r = pq.top();
            pq.pop();
            Node* newNode = new Node('$', l->data + r->data );
            newNode->left = l;
            newNode->right = r;
            pq.push(newNode); 
        }

        Node* root = pq.top();
        vector<pair<char,string>> ans;
        string temp;
        traverse( root, ans, temp );
        return ans;

    }
};



int main(){
    int N = 5;
    string s = "qptad";
    vector<int> freq = { 3,23,30,12,18 };
    huffman obj;
     clock_t starter, ender;

    starter = clock();
    vector< pair < char, string > > ans = obj.huffman_encoding ( s,freq , N );
    ender = clock();

    double time_taken = double(ender - starter) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
    

    for ( int i= 0; i< N; i++ ){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    // O(n*logn)
    
}

