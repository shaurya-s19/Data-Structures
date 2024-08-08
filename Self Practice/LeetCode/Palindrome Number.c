bool isPalindrome(int x) {
    //Check if num is negative and return false if it is
    if(x<0) return false;

    //Storing x in another variable num to check for palindrome
    long long int num = x;
    int remainder;
    int reverse = 0;
    const int MAX_INT = 2147483647; //Max size of 32-bit signed integer

    //Reversing integer
    while(num != 0 ){
        remainder = num % 10;

        //Checking for Overflow
        if (reverse > (MAX_INT - remainder) / 10) return false;

        reverse = reverse * 10 + remainder;
        num /= 10;
    }

    //Check if palindrome
    if(reverse == x) return true;
    return false;
}
