/**
 * @file p412_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-29
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-29
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
    vector<string> fizzBuzz(int n) {
        vector<string> strVec;
        for(int i = 1; i <= n; ++i)
        {
            if(i%3 == 0 && i%5 == 0)
            {
                strVec.push_back("FizzBuzz");
            }
            else if(i%3 == 0)
            {
                strVec.push_back("Fizz");
            }
            else if(i%5 == 0)
            {
                strVec.push_back("Buzz");
            }
            else
            {
                strVec.push_back(to_string(i));
            }
        }
        return strVec;
    }
};