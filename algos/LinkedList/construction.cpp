class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
    Node()
    {
        // yaha jaruri nhi ki hum this use kare kyuki upar this hamne parameter aur class member var me confusion na aye compiler ko ,isliye this use krte h
        this->data = 0;
        this->next = nullptr;
    }
};

class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        // code here
      Node *head = new Node(arr[0]);
    //   Node *ans = head;
      Node *move = head;   
    //   head =  move;
      int n = arr.size();
      
      for ( int i = 1 ; i < n ; i ++ ){
          Node *t = new Node(arr[i]);
          move -> next = t;
          move = t;
          
      }
      
      return head;
    }
};