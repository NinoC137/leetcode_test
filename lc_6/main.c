/*
 * @lc app=leetcode.cn id=6 lang=c
 *
 * [6] Z 字形变换
 */

// @lc code=start
char* convert(char* s, int numRows) {
    char* ptr = s;
    char martix[numRows * 2][numRows * 2];
    memset(martix, 0, sizeof(martix));

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
            printf("1: [%d][%d] val: %c\r\n", cow, raw, *ptr);
        }else{
            int cow, raw;
            cow = count - numRows + 1 + offset_cow;
            raw = numRows * 2 - count - 2;
            martix[cow][raw] = *ptr;
            printf("2: [%d][%d] val: %c\r\n", cow, raw, *ptr);
        }
        ptr++;
    }

    for(int i = 0; i < numRows * 2; i++){
        for(int j = 0; j < numRows * 2; j++){
            printf("%c ", martix[j][i]);
        }
        printf("\r\n");
    }

    char* res = malloc(numRows * numRows);
    memset(res, 0, numRows * numRows);
    int counter = 0;
    for(int i = 0; i < numRows * 2; i++){
        for(int j = 0; j < numRows * 2; j++){
            if(martix[j][i] != 0){
                printf("%c", martix[j][i]);
                // *res++ = martix[j][i];
                counter++;
            }
        }
    }
    res[counter] = '\0';

    return res;
}

int main(){
    char* str = "PAYPALISHIRING";
    int num = 3;
    convert(str, num);
}
// @lc code=end

