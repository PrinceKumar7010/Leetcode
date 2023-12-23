class Solution {
public:
    bool isPathCrossing(string path) {
        std::set<std::pair<int, int>> visited;
        visited.insert({0, 0});
        int x = 0, y = 0;
        for (char direction : path) {
            if (direction == 'N') y++;
            else if (direction == 'S') y--;
            else if (direction == 'E') x++;
            else x--;

            auto currentPos = std::make_pair(x, y);
            if (visited.find(currentPos) != visited.end()) {
                return true; // Path crosses itself
            } else {
                visited.insert(currentPos);
            }
        }

        return false; // Path does not cross itself
    }
};