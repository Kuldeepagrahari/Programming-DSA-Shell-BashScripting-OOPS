 void insert(int arr[], int i)
    {
        //code here
        int j = i - 1;
        int next_min = arr[i];
        while ( j >= 0 && arr[j] > next_min ){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = next_min;
        // for ( int i  = 0; i  < n ; i ++ ) cout << arr[i] << " ";
        // cout << endl;
    }
    
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        //code here
        for ( int i = 1 ; i < n ; i ++ ){
            
            insert(arr, i);
        }
        
        
    }