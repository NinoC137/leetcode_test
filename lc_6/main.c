/*
 * @lc app=leetcode.cn id=6 lang=c
 *
 * [6] Z 字形变换
 */

// @lc code=start
char* convert(char* s, int numRows) {
    char* ptr = s;
    char martix[1001][1001] = {0};
    // memset(martix, 0, sizeof(martix));

    if(numRows == 1){
        return s;
    }

    int count = 0;
    int offset_cow = 0;
    int offset_raw = 0;

    for(int i = 0; *ptr != '\0'; i++){
        count = i % (numRows * 2 - 2);
        
        if(i == (numRows * 2 - 2)){
            offset_cow += numRows - 1;
            offset_raw++;
            i = 0;
        }

        if(count < numRows){
            int cow, raw;
            cow = offset_cow;
            raw = count % numRows;
            martix[cow][raw] = *ptr; 
            // printf("1: [%d][%d] val: %c\r\n", cow, raw, *ptr);
        }else{
            int cow, raw;
            cow = count - numRows + 1 + offset_cow;
            raw = numRows * 2 - count - 2;
            martix[cow][raw] = *ptr;
            // printf("2: [%d][%d] val: %c\r\n", cow, raw, *ptr);
        }
        ptr++;
    }

    // for(int i = 0; i < numRows * 2; i++){
    //     for(int j = 0; j < numRows * 2; j++){
    //         printf("%c ", martix[j][i]);
    //     }
    //     printf("\r\n");
    // }

    char* res = malloc(1001 * 1001);
    memset(res, 0,1001 * 1001);

    char* res_ptr = res;

    int counter = 0;
    for(int i = 0; i < 1001; i++){
        for(int j = 0; j < 1001; j++){
            // if((martix[j][i] <= 'z' && martix[j][i] >= 'a') || (martix[j][i] <= 'Z' && martix[j][i] >= 'A'))
            if(martix[j][i] != 0)
            {
                printf("%c", martix[j][i]);
                *res_ptr++ = martix[j][i];
                counter++;
            }
        }
    }
    *res_ptr = '\0';

    return res;
}

int main(){
    char* str = "PAYPALISHIRING";
    int num = 3;
    convert(str, num);
}
// @lc code=end

