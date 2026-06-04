class Twitter {
private:
        //DS to store the tweets of each user as a vector of (timestamp , twweetid)
        unordered_map<int , vector<pair<int,int>>> tweets;
        //DS to store the set of followees for each user 
        unordered_map<int , unordered_set<int>> following;
        //global time counter to sort tweets
        int time;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        //Min-heap to store tweets based on timestamp
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<>> pq;
        ///insert user's own tweets
        for(auto& t : tweets[userId]){
            pq.push(t);
            if(pq.size() > 10){
                //since we need only most recent one(only 10) if size exceeds then minheap will remove the oldest one
                pq.pop();
            }
        }

        //inserts tweets of followee to whom user follows
        for(int followee : following[userId]){
            for(auto& t : tweets[followee]){
                pq.push(t);
                if(pq.size() > 10){
                    pq.pop();
                }
            }
        }
        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */