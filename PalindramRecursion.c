#include <stdio.h>
// Function to reverse the number recursively
int reverseNumber(int num, int rev) {
    if (num == 0)
        return rev;
    return reverseNumber(num / 10, rev * 10 + num % 10);
}

// Main function to check if palindrome
int isPalindrome(int num) {
    int reversed = reverseNumber(num, 0);
    return num == reversed;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (isPalindrome(n))
        printf("%d is a palindrome.\n", n);
    else
        printf("%d is not a palindrome.\n", n);

    return 0;
}