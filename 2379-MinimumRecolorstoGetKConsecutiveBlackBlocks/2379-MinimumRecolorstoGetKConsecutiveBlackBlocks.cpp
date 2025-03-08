class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int black = 0;
        int white = 0;
        for(int i = 0; i < k; i++){
            if(blocks[i] == 'W')
                white++;
            else if(blocks[i] == 'B')
                black++;
        }
        int maxBlacksInWindow = black;
        for(int i = k; i < blocks.length(); i++){
            if(blocks[i-k] == 'B')
                black--;
            if(blocks[i] == 'B')
                black++;
            maxBlacksInWindow = max(maxBlacksInWindow, black);
        }
        return k-maxBlacksInWindow;
    }
};