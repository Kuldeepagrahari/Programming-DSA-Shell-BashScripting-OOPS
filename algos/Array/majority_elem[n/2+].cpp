int majorityElement(vector<int>& nums) {
      // moore's voting algo
  int pos_ans = -1;                         jo majority me h , vo atleast ek jagah par dominate
 int cnt = 0;
 int i = 0 ;                                  karega hi, bhale baaki jagah equal occurrence ho 
 int n = nums.size();
 while (i < n ){
if ( cnt == 0 ){                                  jaye
pos_ans = nums[i];
cnt = 1;
 }
else if ( pos_ans != nums[i] ){
cnt--;
 }
else {
 cnt ++;
 }
 i++;
  }
 return pos_ans;
