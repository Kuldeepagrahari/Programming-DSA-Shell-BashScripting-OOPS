class Solution {
public:
  
 vector<int>heap;   
void heapify(vector<int> &heap, int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && heap[l] > heap[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && heap[r] > heap[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(heap[i], heap[largest]);

		// Recursively heapify the affected sub-tree
		heapify(heap, n, largest);
	}
}

int pop(vector<int> &heap)
{
    // Write you code here.
    if(heap.size()==0)return -1;
	int ans=heap[0];
	
	
	heap[0]=heap[heap.size()-1];
	heap.pop_back();
    heapify(heap,heap.size(),0);
    return ans;
}



void push(vector<int> &heap, int x)
    {
          heap.push_back(x);

           // Posistion of the current inserted element.
           int pos=heap.size()-1;

           // Shifting the element up until it reaches the top most node if it is larger than its parent.
           while(pos>0)
           {
               int parent = (pos-1)/2;
               if(heap[pos] > heap[parent])
               {
                   swap(heap[parent],heap[pos]);
                   pos=parent;
              }
             else
             {
                 // As parent is larger the element now is in its correct position. 
                 break;
             }
         }
     }

     void build(vector<int>& nums,int k){
         for(int i=0;i<nums.size();i++){
           push(heap,nums[i]);
         }
        
     
     }
    int findKthLargest(vector<int>& nums, int k) {
        
      build(nums,k);
      for(int i=0;i<k-1;i++)pop(heap);
        return heap[0];
    }
};