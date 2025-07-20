// https://leetcode.com/problems/maximum-units-on-a-truck/

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](auto &v1, auto &v2) {
            return v1[1] > v2[1];
        });

        int items = 0;
        for (auto &boxes : boxTypes) {
            if (truckSize == 0) {
                break;
            }
            int &nItems = boxes[1], &count = boxes[0];
            items += (nItems * min(count, truckSize));
            truckSize -= min(count, truckSize);
        }

        return items;
    }
};