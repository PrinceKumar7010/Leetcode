class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> lost,players; //we used map to retain sorted order property
        vector<vector<int>> ans(2);
        for(auto it : matches)
        {
            lost[it[1]]++;   //increment count of lost matches
            //store all players in a map
            players[it[0]]++; 
            players[it[1]]++;
        }
        for(auto it : players) //iterate on the list of all players
        {
          if(lost[it.first] == 0) //if no match is lost
           ans[0].push_back(it.first);
          else if(lost[it.first] == 1) //if only 1 match is lost
           ans[1].push_back(it.first);
        }
    return ans;
    }
};