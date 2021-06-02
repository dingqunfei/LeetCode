/**
 * @file p342_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-06-02
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-06-02
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
    bool isPowerOfFour(int n) {
        //小于0，或者1的个数不为1，则不是4的幂
        if(n < 0 || n&(n-1))
        {
            return false;
        }
        //4的幂，一定是(3+1)*(3+1)*(3+1).....
        //展开来，一定满足n%3==1
        return n%3==1;
        //4的这1个1，会出现在奇数位，那么，判断一下奇数位中有没有出现1
        //使用0101 0101 0101 0101 0101 0101 0101 0101来判断
        //return n & 0x55555555;
    }
};