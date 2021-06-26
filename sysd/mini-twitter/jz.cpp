/**
 * Definition of Tweet:*/
class Tweet {
	public:
 	int id;
 	int user_id;
 	String text;
 	static Tweet create(int user_id, string tweet_text) {
 		// This will create a new tweet object,
 		// and auto fill id
 	}
}
 
class Node {
  public:
    int order;
    Tweet tweet;
    Node(int o, Tweet t) {
        order = o, tweet = t;
    }

    bool operator<(const Node &o) const {
        return order > o.order;
    }
};
//jz c++ code, shaun to read and understand
class MiniTwitter {
  private:
    map<int, set<int>> friends;
    map<int, vector<Node>> users_tweets;
    int order;

  public:
    MiniTwitter() {
        // initialize your data structure here.
        order = 0;
        friends.clear();
        users_tweets.clear();
    }

    // @param user_id an integer
    // @param tweet a string
    // return a tweet
    Tweet postTweet(int user_id, string tweet_text) {
        //  Write your code here
        Tweet tweet = Tweet::create(user_id, tweet_text);
        if (users_tweets.find(user_id) == users_tweets.end())
            users_tweets[user_id] = vector<Node>();
        order += 1;
        users_tweets[user_id].push_back(Node(order, tweet));
        return tweet;
    }

    // @param user_id an integer
    // return a list of 10 new feeds recently
    // and sort by timeline
    vector<Tweet> getNewsFeed(int user_id) {
        // Write your code here
        vector<Node> tmp;
        if (users_tweets.find(user_id) != users_tweets.end())
            tmp = getTen(users_tweets[user_id]);

        if (friends.find(user_id) != friends.end()) {
            for (set<int>::iterator it = friends[user_id].begin(); it != friends[user_id].end(); ++it) {
                int user = *it;
                if (users_tweets.find(user) != users_tweets.end()) {
                    vector<Node> temp = getTen(users_tweets[user]);
                    for (Node node : temp)
                        tmp.push_back(node);
                }
            }
        }
        sort(tmp.begin(), tmp.end());
        vector<Tweet> rt;
        for (int i = 0; i < tmp.size(); ++i) {
            if (i >= 10) break;
            rt.push_back(tmp[i].tweet);
        }
        return rt;
    }

    // @param user_id an integer
    // return a list of 10 new posts recently
    // and sort by timeline
    vector<Tweet> getTimeline(int user_id) {
        // Write your code here
        vector<Node> tmp;
        if (users_tweets.find(user_id) != users_tweets.end())
            tmp = getTen(users_tweets[user_id]);
        sort(tmp.begin(), tmp.end());
        vector<Tweet> rt;
        for (int i = 0; i < tmp.size(); ++i) {
            if (i >= 10) break;
            rt.push_back(tmp[i].tweet);
        }
        return rt;
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id follows to_user_id
    void follow(int from_user_id, int to_user_id) {
        // Write your code here
        if (friends.find(from_user_id) == friends.end())
            friends[from_user_id] = set<int>();
        friends[from_user_id].insert(to_user_id);
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id unfollows to_user_id
    void unfollow(int from_user_id, int to_user_id) {
        // Write your code here
        if (friends.find(from_user_id) == friends.end()) return;
        friends[from_user_id].erase(to_user_id);
    }

    vector<Node> getTen(vector<Node> &tmp) {
        int cnt = 0;
        vector<Node> v1;
        int n = tmp.size();
        for (int i = n - 1; i >= 0; --i) {
            cnt += 1;
            v1.push_back(tmp[i]);
            if (cnt >= 10) break;
        }
        return v1;
    }
};
