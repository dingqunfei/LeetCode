/**
 * @file p461_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-28
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-28
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
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int dis = 0;
        while(z)
        {
            /*
            更加优雅
            sum += z & 1;
		    z = z>>1;
            */
            dis += z % 2;
            z /= 2;
        }
        return dis;
    }
};