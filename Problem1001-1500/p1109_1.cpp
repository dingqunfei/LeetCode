/**
 * @file p1109_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-30
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-30
 * Version     : 1.0
 * Author      : dqflying
 * Lisence     : 
 * Description : 
 * 
 * 
 * 
 * 
 */

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> seats(n, 0);

        //seats[0] = bookings[0][2];

        for(int i = 0; i < bookings.size(); ++i)
        {
            seats[bookings[i][0]-1] += bookings[i][2];
            if(bookings[i][1] < n)
            {
                seats[bookings[i][1]] -= bookings[i][2];
            }
        }
        for(int i = 1; i < n; ++i)
        {
            seats[i] += seats[i-1];
        }
        return seats;
    }
};
