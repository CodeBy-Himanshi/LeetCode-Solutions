int maxProduct(int n) {
    int largest = 0;
    int second_largest = 0;
    while (n > 0) {
        int current_digit = n % 10;
        if (current_digit > largest) {
            second_largest = largest;
            largest = current_digit;
        }
        else if(current_digit > second_largest)
            second_largest = current_digit;
        n /= 10;
    }
    return largest * second_largest;
}