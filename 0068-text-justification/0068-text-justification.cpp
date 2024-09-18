class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> ans;
        int i=0;
        while(i<n){
            int currLen = words[i].length();
            int end =i+1;
// in the if block apart from words length we are doing end-i also because we need to make sure there is atleast one empty space between two words but in currlen we are keeping only length of words so everytime we are calculating the space and checking if it exceeds
// I will suggest to dry run it on sample test case ...
            while(end<n && currLen + words[end].length()+end-i <=maxWidth){
                currLen+=words[end].length();
                end++;
            }
// We calculated number of words so that we can evenly divide space between them
            int num_Word = end-i; // number of word in this line
            int total_Space = maxWidth-currLen; // total space in line
            int space_bw_words = num_Word==1?total_Space:total_Space/(num_Word-1);  // confirmed space between each word
            int extra_space = num_Word==1?0:total_Space%(num_Word-1); 
           // after dividing the space evenly between words this is the extra space which we will start inserting from left as given in question
            string line="";
// if it is last line all spaces shoul be at end
            if(end==n){
                line = words[i];
                for(int k =i+1;k<end;k++){
                    line = line+' '+words[k];
                    total_Space--;
                }
                if(total_Space>0)
                line+=string(total_Space,' ');            

            }
// for other lines we will insert word then confirmed space between them and then extra space if available starting from left.
            else{
                for(int k =i;k<end;k++){
                    line = line+words[k];
                    if(line.length()<maxWidth){
                        line+=string(space_bw_words,' ');
                    }
                    if(extra_space>0){
                        line+=' ';
                        extra_space--;
                    }
                }
            }
            i=end;
            ans.push_back(line); 
        }
        return ans;
    }
};