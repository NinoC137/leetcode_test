#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int LCS(char *A, char *B) {
    int m = strlen(A);
    int n = strlen(B);
    int dp[m+1][n+1];

    int endingIndex;

    // 初始化边界条件
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                endingIndex = i - 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    char* str = (char*)malloc((dp[m][n] + 1) * sizeof(char));
    strcpy(str, &A[endingIndex - dp[m][n] + 1]);
    printf("string: %s\r\n", str);

    // 返回最终结果
    return dp[m][n];
}

int main() {
    char A[] = "ABCBDAB";
    char B[] = "BDCAB";
    printf("Length of LCS is %d\n", LCS(A, B));
    return 0;
}