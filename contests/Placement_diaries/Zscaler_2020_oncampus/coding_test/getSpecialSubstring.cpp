/*
 * Complete the 'getSpecialSubstring' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 *  3. STRING charValue
 */

/*
 * 3. Intelligent Substring
 * 
 * There are two types of characters in a particular language: special and normal.
 * A character is special if its value is 1 and normal if its value is 0. Given
 * string s, return the length of longest substring of s that contains at most k normal 
 * characters. Whether a character is normal is determined by a 26-digit bit string
 * named charValue. Each digit in charValue corresponds to a lowercase letter in
 * the English alphabet.
 * 
 * Example:
 * s = 'abcde'
 * 
 * alphabet  = abcdefghijklmnopqrstuvwxyz
 * charValue = 10101111111111111111111111
 * 
 * The only normal characters in the language (according to charValue) are b and d. The
 * string s contains both af these characters
 * 
 * if k = 1
 * length of longest substring of s that contains at most k normal characters is 3
 * 
 * if k = 2
 * length of longest substring of s that contains at most k normal characters is 5
 */

char* st;
int gk, n;
char* gcharValue;
bool isPossible(int l) {
    int cnt = 0;
    for(int i = 0; i < l; i++)
        if(gcharValue[st[i] - 'a'] == '0')
            cnt += 1;
    // printf("%d\n", cnt);
    int mincnt = cnt;
    for(int i = l; i < n; i++) {
        if(gcharValue[st[i - l] - 'a'] == '0')
            cnt -= 1;
        if(gcharValue[st[i] - 'a'] == '0')
            cnt += 1;
        mincnt = cnt < mincnt ? cnt : mincnt;
    }
    return mincnt <= gk;
}

int getSpecialSubstring(char* s, int k, char* charValue) {
    st = s;
    gk = k;
    gcharValue = charValue;
    n = strlen(s);
    int low = 0, high = n, mid, ans;
    // printf("%d\n", isPossible(2));
    while(low <= high) {
        mid = (low + high) / 2;
        // printf("%d %d %d\n", low, mid, high);
        if(isPossible(mid)) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}