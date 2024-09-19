class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // ok i am going to be uing boyer-moore Majority algorithm
        int count=0;
        int candidate=0;

        for(int num:nums){
            if(count==0){
                candidate=num;
                count++;
            }else if(num==candidate){
                count++;
            }else{
                count--;
            }
        }

        //i have no idea how and why it works though
        return candidate;
    }
};