char *input="aaaabbba"
char *output="a4b3a1"

char *compress(char *input) {
    int cnt = 0, pos = 0;
    char curr = 0;
    for(int i = 0; i <= strlen(input); i++) {
        if(input[i] != curr) {
            if(cnt != 0) {
                input[pos] = curr;
                input[pos + 1] = cnt + '0';
                pos += 2;
            }
            curr = input[i];
            cnt = 1;
        }
        else
            cnt += 1;
    }
    input[pos] = 0;
}