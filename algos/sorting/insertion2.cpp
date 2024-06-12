 int select(int arr[], int i, int n)
    {
        // code here such that selectionSort() sorts arr[]
        int mini = arr[i];
        int ind = i;
        
        for ( int j = i; j < n ; j++ ){
            if ( arr[j] < mini ){
                mini = arr[j];
                ind = j;
            }
        }
        return ind;
        
    }
     
    void selectionSort(int arr[], int n)
    {
       //code here
       for ( int i = 0 ; i < n ; i++ ){
           int min_ind = select(arr, i, n);
           swap(arr[i], arr[min_ind]);
       }
       
    }