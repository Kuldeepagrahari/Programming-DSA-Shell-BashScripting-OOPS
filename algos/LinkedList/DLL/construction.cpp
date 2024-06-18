  Node* constructDLL(vector<int>& arr) {
        // code here
        Node *head = new Node(arr[0]);
        Node *mover = head;
       
        int n = arr.size();
        
        for ( int i = 1 ; i <  n ; i ++ ){
            Node *t  =  new Node(arr[i]);
            t-> prev = mover;
            mover -> next = t;
            mover = t;
        }
        return head;
    }