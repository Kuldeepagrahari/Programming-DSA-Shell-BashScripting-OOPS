 Node *insertAtBegining(Node *head, int x) {
       // Your code here
       Node *t = new Node(x);
       t -> next = head;
       head = t;
       return head;
    }
    
    
    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  {
       // Your code here
         
         Node *t = new Node(x);
         if( head == nullptr) head = t;
         else {
         Node *mover = head;
         while ( mover -> next != nullptr ){
             mover = mover->next;
         }
         
         mover -> next = t;
         }
        //  t -> next = nullptr;
         return head;
    } 