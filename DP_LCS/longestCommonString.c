#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listNode {
    char* str;
    struct listNode* next;
};

// 创建链表节点
struct listNode* createNode(char* str) {
    struct listNode* newNode = (struct listNode*)malloc(sizeof(struct listNode));
    newNode->str = str;
    newNode->next = NULL;
    return newNode;
}

// 打印链表
void printList(struct listNode* head) {
    struct listNode* temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->str);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 查找两个字符串的最长公共子串
char* findLongestCommonSubstring(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int maxLen = 0;
    int endingIndex = 0;
    
    int dp[len1+1][len2+1]; // 动态规划表
    
    // 初始化DP表
    memset(dp, 0, sizeof(dp));

    // 填充DP表
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endingIndex = i - 1;
                }
            }
        }
    }

    if (maxLen == 0) {
        return "";
    }

    // 提取最长公共子串
    char* longestCommonSubstring = (char*)malloc((maxLen + 1) * sizeof(char));
    strncpy(longestCommonSubstring, &str1[endingIndex - maxLen + 1], maxLen);
    longestCommonSubstring[maxLen] = '\0';
    
    return longestCommonSubstring;
}

// 遍历链表并查找最长的公共子串
char* findLongestCommonSubstringInList(struct listNode* head) {
    if (head == NULL || head->next == NULL) {
        return ""; // 空链表或只有一个节点
    }

    struct listNode* current = head->next;
    char* longestCommonSubstring = head->str;

    while (current != NULL) {
        char* commonSubstring = findLongestCommonSubstring(longestCommonSubstring, current->str);
        longestCommonSubstring = commonSubstring;
        current = current->next;
    }

    return longestCommonSubstring;
}

int main() {
    struct listNode* head = createNode("babcde");
    head->next = createNode("abcde");
    head->next->next = createNode("zabcde");
    head->next->next->next = createNode("xyabcde");

    printf("Original list:\n");
    printList(head);

    char* longestCommonSubstring = findLongestCommonSubstringInList(head);

    printf("Longest common substring: %s\n", longestCommonSubstring);

    return 0;
}
