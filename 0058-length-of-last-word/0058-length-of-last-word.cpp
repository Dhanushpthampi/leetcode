class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int count=0;

        if(n==0){
            return -1;
        }
        
        for(int i=n-1;i>=0;i--){

           
            if(s[i]!= ' '){
                count=count+1;
            }else{
                if(count>0){
                     return count;
                }
               
            }

        }
        
        return count;
    }
};