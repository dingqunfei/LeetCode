typedef pair<int, int> Point;
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int minX = rectangles[0][0], minY = rectangles[0][1], maxX = rectangles[0][2], maxY = rectangles[0][3];
        long long area = 0;
        map<Point, int> cnt;
        for(auto& rect: rectangles)
        {
            area += ((long long)rect[2] - (long long)rect[0]) * ((long long)rect[3] - (long long)rect[1]);
            minX = min(minX, rect[0]);
            minY = min(minY, rect[1]);
            maxX = max(maxX, rect[2]);
            maxY = max(maxY, rect[3]);
            
            Point point1({rect[0], rect[1]});
            Point point2({rect[0], rect[3]});
            Point point3({rect[2], rect[1]});
            Point point4({rect[2], rect[3]});

            cnt[point1] += 1;
            cnt[point2] += 1;
            cnt[point3] += 1;
            cnt[point4] += 1;
        }
        if(area != (long long)(maxY - minY) * (maxX - minX))
        {
            return false;
        }
        Point pointMinMin({minX, minY});
        Point pointMinMax({minX, maxY});
        Point pointMaxMin({maxX, minY});
        Point pointMaxMax({maxX, maxY});
        int tang = 0;
        for(auto& item: cnt)
        {
            if(item.second % 2 != 0)
            {
                ++tang;
            }
        }
        if(tang != 4)
        {
            return false;
        }
        if(cnt[pointMinMin] != 1 && cnt[pointMinMin] != 3)
        {
            return false;
        }
        if(cnt[pointMinMax] != 1 && cnt[pointMinMax] !=3)
        {
            return false;
        }
        if(cnt[pointMaxMin] != 1 && cnt[pointMaxMin] !=3)
        {
            return false;
        }
        if(cnt[pointMaxMax] != 1 && cnt[pointMaxMax] !=3)
        {
            return false;
        }

        return true;
    }
};