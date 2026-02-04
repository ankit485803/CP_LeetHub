class Solution {
public:
    int simulate(int red, int blue, bool startRed) {
        int height = 0;
        int row = 1;
        bool isRed = startRed;

        while (true) {
            if (isRed) {
                if (red < row) break;
                red -= row;
            } else {
                if (blue < row) break;
                blue -= row;
            }
            height++;
            row++;
            isRed = !isRed;
        }
        return height;
    }

    int maxHeightOfTriangle(int red, int blue) {
        return max(simulate(red, blue, true),
                   simulate(red, blue, false));
    }
};
