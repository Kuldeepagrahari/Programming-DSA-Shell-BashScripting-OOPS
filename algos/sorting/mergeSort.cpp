 void merge(int arr[], int l, int m, int r)
    {
        int Ll = m - l + 2;
        int Rl = r - m + 1;
        int L[Ll];
        int R[Rl];
        L[Ll-1] = INT_MAX;
        R[Rl-1] = INT_MAX;
        int ind = 0;
        for ( int i = l ; i <= m; i++ ){
            L[ind++] = arr[i];
        }
        ind = 0;
        for ( int i = m + 1 ; i <= r ; i++ ){
            R[ind++] = arr[i];
        }
        int k = l, i = 0, j = 0;
        
        while (k <= r){
            if ( L[i] > R[j] ){
                arr[k++] = R[j++];
            }
            else {
                arr[k++] = L[i++];
            }
        }
    }
    
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if ( r == l )return;
        int mid = l + ( r - l ) /2 ;
        mergeSort(arr, l, mid );
        mergeSort(arr, mid, r);
        merge(arr, l, mid, r);
          
        
    }