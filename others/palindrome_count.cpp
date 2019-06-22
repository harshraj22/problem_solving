// https://codereview.stackexchange.com/a/146424

// Counts the number of palindromic numbers between two given numbers a and b.
//
// 121 is palindromic, 123 is not.
//
// Input is "n", the number of tests, and then n pairs of "a b".

#include <stdio.h>

static int numPalindrome(int num);
static int constructPalindrome(int palPrefix, int numLength);

int main(void){
    int a = 0;
    int b = 0;
    int n = 0;

    scanf("%d", &n);
    while (n-- > 0) {
        scanf("%d %d", &a, &b);
        printf("%d\n", numPalindrome(b) - numPalindrome(a-1));
    }
    return 0;
}

// Returns the number of palindromes between 1 and num.  If the input is 0,
// this function will return 0.
static int numPalindrome(int num){
    int numLength = 0;
    int palLength = 0;
    int palPrefix = 0;
    int temp      = 0;
    int i         = 0;

    // Example 1: num = 12345678
    // Example 2: num = 123456789

    // Find the length of the number, in digits.  Examples: 8 and 9
    for (numLength=0, temp = num; temp != 0; temp /= 10)
        numLength++;

    // Find the palindrome prefix, which is the front half of the number,
    // rounding up the length.
    //
    // Examples: palLength = 4    and 5
    //           palPrefix = 1234 and 12345
    palLength = (numLength+1) / 2;
    palPrefix = num;
    for (i=0; i < numLength - palLength; i++)
        palPrefix /= 10;

    // Check whether the palindrome formed by palPrefix is greater than num.
    // If it is, we subtract one from palPrefix because the last palindrome
    // is not usable.
    //
    // Example 1: Is 12344321  greater than 12345678?
    // Example 2: Is 123454321 greater than 123456789?
    if (constructPalindrome(palPrefix, numLength) > num)
        palPrefix--;

    // So right now, we have palPrefix being 1234 and 12345 for the two
    // examples.  The number of palindromes less than num is close to
    // palPrefix*2.  The reason is, for each number from 1..palPrefix, you can
    // can construct two palindromes, one of odd length where the last digit
    // is not repeated, and one of even length where all digits are repeated.
    //
    // 25  -> 252    2552
    // 256 -> 25652  256652
    //
    // Starting with all these, palindromes, we adjust the count depending
    // on whether the original number had an even or odd number of digits.
    //
    // For even numLength, we are missing some palindromes, for example:
    //
    // num       = 12345678
    // palPrefix = 1234
    //
    // We can create a palindrome with prefix higher than 1234 that is still
    // less than num.  For example, choose 2345:
    //
    // 2345 -> 2345432
    //
    // So for each number from 1235..9999, we should add one to the count.
    // In other words, add 10^prefixLength - 1 - palPrefix to the count.
    //
    // For odd numLength, we have too many palindromes.  Some of the
    // palindromes already created are not usable.  For example:
    //
    // num       = 12345678
    // palPrefix = 12345
    //
    // 12345 -> 1234554321 (too big, 10 digits)
    //
    // So for all the max digit prefixes, we can only use 1 of the 2
    // palindromes.  So we should subtract some from the count.  The number we
    // need to subtract in this case is: (12345 - 9999).  In other words,
    // subtract palPrefix - (10^(prefixLength-1) - 1) prefixes.
    palPrefix *= 2;
    if (numLength & 1) {
        // Subtract off adjustment for odd length.
        int adjustment = 1;
        for (i=1;i<palLength;i++)
            adjustment *= 10;
        palPrefix -= (palPrefix/2 - adjustment + 1);
    } else {
        // Add adjustment for even length.
        int adjustment = 1;
        for (i=0;i<palLength;i++)
            adjustment *= 10;
        palPrefix += (adjustment - 1 - palPrefix/2);
    }
    return palPrefix;
}

/**
 * Constructs a palindrome from a prefix.  Examples:
 *
 * Prefix = 1234  numLength = 8, returns 12344321
 * Prefix = 12345 numLength = 9, returns 123454321
 */
static int constructPalindrome(int palPrefix, int numLength){
    int front = palPrefix; // Starts at 1234, builds to 12340000
    int back  = 0;         // Starts at 0   , builds to 4321

    // If the number length is odd, we do not want to repeat the last digit
    // of the prefix, so skip it here.
    if (numLength & 1)
        palPrefix /= 10;

    // For each digit in the remaining prefix, remove the last digit and
    // place it on the back of "back".  In other words, we are reversing
    // palPrefix into "back".
    while (palPrefix != 0) {
        int digit = palPrefix % 10;

        palPrefix /= 10;
        back       = back * 10 + digit;
        front     *= 10;
    }
    return front + back;
}