/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 */

// @lc code=start

#include <string.h>

int main() {
    char* s = "cccc";
    int start_index = 0, end_index = 0;
    
    char* str_ptr = s;
    int str_len = strlen(str_ptr);

    if(str_len < 2){
        // return s;
    }

    char* final_str = (char*)malloc(str_len + 1);

    char dp[str_len][str_len];
    memset(dp, 0, sizeof(dp));
    int max = 1;

    for(int i = 0; i < str_len; i++){
        dp[i][i] = 1;
    }

    // 处理长度为 2 的子串
    for (int i = 0; i < str_len - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
            start_index = i;
            max = 2;
        }
    }

    // 处理长度大于 2 的子串
    for (int len = 3; len <= str_len; len++) {  //先假设回文串长度为3,再寻找有没有长度为4的回文串,直到寻找到str_len的长度
        for (int i = 0; i <= str_len - len; i++) {
            int j = i + len - 1;    //以len为观测窗口的宽度, 进行遍历匹配
            
            if (s[i] == s[j] && dp[i + 1][j - 1]) { //先前初始化了dp[i][i] = 1, 这里第一次遍历时(len=3)的dp[i+1][j-1]就必定为 1
                dp[i][j] = 1;//表示s[i]与s[j]相同
                start_index = i;
                max = len;
            }
        }
    }

    // for(int j = 0; j < str_len; j++){
    //     for(int i = 0; i < j; i++){
    //         if(s[i] != s[j]){
    //             dp[i][j] = 0;                
    //         }else{
    //             if((j - i) < 3){
    //                 dp[i][j] = 1;
    //             }else{
    //                 dp[i][j] = dp[i+1][j-1];
    //             }
    //         }

    //         if(dp[i][j]){
    //             max = j - i + 1;
    //             start_index = i;
    //         }
    //     }
    // }

    str_ptr += start_index;
    strncpy(final_str, str_ptr, max);
    final_str[max] = '\0';

    printf("%s", final_str);

    // return final_str;
}
// @lc code=end