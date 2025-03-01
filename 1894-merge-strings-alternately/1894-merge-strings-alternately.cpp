class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string answer;
        string small,large;
        if(word1.length()<word2.length())
        {
            small=word1;
        large=word2;
        } 
        else{
            small = word2;
            large=word1;
        } 

        for(int i=0;i<small.length();i++){
            answer=answer+word1[i];
            answer=answer+word2[i];
        }
        answer=answer+large.substr(small.length());
        return answer;
    }
};