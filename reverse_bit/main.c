#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    uint32_t tmp = n;
    uint32_t count = 0;
    uint32_t num = 0x80000000;
    for(uint32_t index = 0; index < 32; index++){
        if( (num & tmp) != 0){
            break;
        }else{
            count++;
            num >>= 1;
        }
    }

    for (int i = 0; i < (32 - count); i++) {
        // 将当前最低位添加到result中
        result = (result << 1) | (n & 1);
        // 右移n以处理下一位
        n >>= 1;
    }
    return result;
}

int main() {
    char str_buffer[20];

    fgets(str_buffer, sizeof(str_buffer), stdin);

    uint32_t num_1;

    char* token;
    uint32_t count_arr = 0;
    uint32_t arr[1000] = {0};

    token = strtok(str_buffer, " ");
    arr[count_arr++] = atoi(token);
    while (token != NULL) {
        token = strtok(NULL, " ");
        arr[count_arr++] = atoi(token); // 转换为整数
    }

    for(int i = 0; i < count_arr - 1; i++){
        uint32_t reversedNum = reverseBits(arr[i]);
        printf("%d ", reversedNum);
    }
    printf("\r\n");
    
    return 0;
}
