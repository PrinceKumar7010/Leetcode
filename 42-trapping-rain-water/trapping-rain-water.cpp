class Solution {
public:
    int trap(vector<int>& height) {
        int le = 0, ms = 0, re = 0, t = 0;
        bool found_le = false;
        unordered_map<int,int> map;
        // back
        for ( int i = 0; i < height.size(); i++)
        {
            if (!found_le)
            {
                if (height[i] == 0)
                    continue;

                if (i < height.size() - 1 && height[i] > height[i + 1]  )
                {
                    le = i++;
                    ms += height[i];
                    found_le = true;
                }
            }
            else
            {
                if (height[i] >= height[le])
                {
                    re = i--;
                    map[re] = 1;
                    t += (re - le - 1) * (height[le]<height[re]?height[le]:height[re]) - ms;
                    ms = 0;
                    le = 0;
                    found_le = false;
                }
                else
                {
                    ms += height[i];
                }
            }
            
        }

        // forth
        found_le = false; le = height.size() - 1; ms = 0; re = height.size() - 1;
        for ( int i = height.size() - 1; i >= 0 ; i--)
        {
            if (!found_le)
            {
                if (height[i] == 0)
                    continue;

                if (i <= 1)
                    continue;

                if (i >= 0 && height[i] > height[i - 1])
                {
                    le = i--;
                    ms += height[i];
                    found_le = true;
                }
            }
            else
            {
                if (height[i] >= height[le])
                {
                    re = i++;
                    if (map.find(le) == map.end())
                        t += (le - re - 1) * (height[le]<height[re]?height[le]:height[re]) - ms;
                    ms = 0;
                    le = height.size() - 1;
                    found_le = false;
                }
                else
                {
                    ms += height[i];
                }
            }
            
        }
        return t;
    }
};