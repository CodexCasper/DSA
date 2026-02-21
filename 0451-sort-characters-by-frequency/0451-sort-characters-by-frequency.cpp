class Solution {
public:
    string frequencySort(string s) {
/*      //TC:O(n)frequency + O(n)outer loop + O(n) inner loop + O(n) string creation == O(n*n) , SC:O(n)
        //counting the freq using hashmap easily as it builds a table 
        // i.e => tree
        //freq = { 't':1 , 'r':1 , 'e':2 }
        unordered_map<char,int> freq;

        // called range based for-loops , which means go thorugh every charc in string s one at a time and store each in c
        // equavalent to for(int i = 0;i<s.size();i++) char c = s[i];
        // c = 't' -> freq['t'] = 1
        // c = 'r' -> freq['r'] = 1
        // c = 'e' -> freq['e'] = 1
        // c = 'e' -> freq['e'] = 2
        for( char c : s ) freq[c]++;

        string ans = "";

        int n = s.size();

        //we are traversing from end bcoz no character freq can be greater then length of string
        for( int f = n ; f >=0 ; f++ ){
            
            // p is a pair pair<const char, int>
            // so p.first = character 
            // p.second = frequency
            // & is the reference mean instaed of copying the pair we refer to the original element in the map
            for( auto &p : freq ){

                //simply checking the freq and appending the char of size f in the string 
                if( p.second == f ) ans += string(f,p.first);
            }
        }
        return ans;
        */
        //TC:O(n), SC:O(n)
        unordered_map<char,int> freq;

        for( char c : s ) freq[c]++;

        vector<vector<char>> bucket(s.size() + 1);
        
        //putting characters into bucket based on freq
        //bucket[1] = {t,r}
        //bucket[2] = {e}
        //this let su directly jump to highest frequency
        for( auto &p : freq ) bucket[p.second].push_back(p.first);

        string ans = "";
        
        //f = 4 -> empty
        //f = 3 -> empty
        //f = 2 -> {e} -> add "ee"
        //f = 1 -> {t,r} -> add " t ,r "
        for(int f = s.size() ; f >= 0 ; f--){
            for(char c : bucket[f]) ans += string(f,c);
        }
        return ans;
    }
    //Recognize pattern
    //value range is small / bounded
    //AND
    //you repeatedly search for elements with value X
    //Use bucket sort / counting sort
    //This trick appears in:

 //  Top K frequent elements

   //Sort by frequency

//Group numbers by count

//Rearrange string by frequency

//Task scheduling problems
};