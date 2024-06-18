//Function to insert a new node at given position in doubly linked list.
void addNode(Node *head, int pos, int data)
{
   // Your code here

   Node *newNode = new Node(data);       
   Node *t = head;
   while ( pos  && t->next != nullptr ){
       pos--;
       t = t -> next;
   }
   
   if ( t -> next == nullptr){
        t -> next = newNode;
        newNode -> prev = t;
   }
   else {
        Node *t2 = t -> next;
        t -> next = newNode;
        newNode -> prev = t;
        newNode -> next = t2;
        t2 -> prev = newNode;
   }
       
   
}