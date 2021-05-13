/**
 * @file p830_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-07
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-07
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
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        if(s.empty())
        {
            return res;
        }
        
        int start_index = 0;
        char last_ch = s[0];
        
        int curr_index = 0;
        char curr_ch = s[0];
        for(auto it = s.cbegin(); it != s.cend(); ++it)
        {
            
            curr_ch = *it;
            if(last_ch != curr_ch)
            {
                if(curr_index - start_index >= 3)
                {
                    vector<int> vec;
                    vec.push_back(start_index);
                    vec.push_back(curr_index-1);
                    res.push_back(vec);
                }
                start_index = curr_index;
            }
            last_ch = curr_ch;
            ++curr_index;
        }
        if(curr_index - start_index >= 3)
        {
                vector<int> vec;
                vec.push_back(start_index);
                vec.push_back(curr_index-1);
                res.push_back(vec);
        }
        return res;
    }
};