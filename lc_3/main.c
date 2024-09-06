int main() {
    char* s = "pwwkew";
    // int final_len = 0;
    
    // char* str_ptr = s;

    // char hashmap[256] = {0};

    // int iscontinue = 0;
    // int longest_len = 0;

    // while(*s != '\0'){
    //     iscontinue = 0;

    //     if(hashmap[*s] == 0){
    //         hashmap[*s] = 1;
    //         final_len++;
    //         iscontinue = 1;
    //     }
        
    //     if(iscontinue == 0){
    //         memset(hashmap, 0, sizeof(hashmap));
    //         final_len = 1;
    //         hashmap[*s] = 1;
    //     }

    //     longest_len = (longest_len > final_len)? longest_len : final_len;
    //     s++;   
    // }

    // final_len = longest_len;
    // return final_len;

    int start = 0, end = 0, maxlen = 0;
    char map[256] = {0};
    map[*(s+start)] = 1;

    //dvdf
    //pwwkew

    while( *(s+end) != '\0' )
    {
        maxlen = maxlen>(end-start+1)?maxlen:(end-start+1);
        end++;
        while( 0 != map[*(s+end) ] )//将要加入的新元素与map内元素冲突
        {
            map[*(s+start)] = 0;
            start++;
        }
        map[*(s+end)] = 1;
    }

    return maxlen;
}