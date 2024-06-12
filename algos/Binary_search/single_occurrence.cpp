class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();

        int l = 0, r = n - 1, x = n - 1;
        while (r >= l)
        {
            int mid = l + (r - l) / 2;

            if (mid == 0 || mid == n - 1)
                return nums[mid];

            else if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            {
                return nums[mid];
            }
            
            else if (nums[mid] == nums[mid - 1])
            {
                if ((x - mid) & 1)
                    l = mid + 1;
                else
                    r = mid - 1;
            }

            else
            {
                if ((x - mid) & 1)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            cout << mid;
        }
        return -1;
    }
};