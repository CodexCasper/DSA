class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        //TC:O(n logn) we sort so nlogn and loop over the arr multiplee times so (n)
        //SC:O(n) 
        //store the curr elments in temp arr to sort it
        //temp [] = 40 10 20 30
        vector<int> temp = arr;

        //now use sort fn to sort it so that we can directly find rank
        //10 20 30 40
        sort(temp.begin(),temp.end());

        //map so that we can directly store the rank of each element by traversing from start [ empty ]
        unordered_map<int, int> rankMap;
        
        //given rank starts from 1
        int rank = 1;
        for(int num : temp){
            //if the element is not in the map then give it a rank
            if(rankMap.find(num) == rankMap.end()){
                rankMap[num] = rank;
                rank++;
            }
        }
        //to store ans 
        vector<int> result;
        for(int x : arr){
            result.push_back(rankMap[x]);
        }
        return result;
    }
};