 bool searchKey(int n, struct Node* head, int key) {
        // Code here
        while(head->next != nullptr){
            if ( head->data == key)return true;
            head = head->next;
        }
        return false;
    }