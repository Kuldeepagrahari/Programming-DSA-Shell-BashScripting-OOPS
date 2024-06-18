  int getCount(struct Node* head){
        int l = 1;
        while ( head->next != nullptr) {
            head= head->next;
            l++;
        }
        return l;
        //Code here
    
    }