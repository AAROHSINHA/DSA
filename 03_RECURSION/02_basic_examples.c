#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// 1. SUM OF FIRST n NATURAL NUMBER
int sum(int n){
    if(n == 0){
        return 0;
    }
    return n + sum(n - 1);
}

// 2. Factorial of a number
int fact(int n){
    if(n <= 1){
        return 1;
    }
    return n*fact(n - 1);
}

// 3. m to the power n
int power(int m, int n){
    if(n == 0){
        return 1;
    }
    return m*power(m, n - 1);
}

// Mean of n elements - 
/*
 SUM of (n - 1) elemsnts + nth
_________________________________
            n
*/

double mean(int n) {
    if (n <= 0) {
        return 0.0; // Handle invalid input
    } else if (n == 1) {
        return 1.0; // Base case
    } else {
        return (mean(n - 1) * (n - 1) + n) / n;
    }
}

// 4. sum of n numbers
int sum2(int n){
    if(n == 1){
        return 1;
    }
    return n + sum(n - 1);
}

// 5. Decimal to binary number using recursion
void convertToBinary(int num){
    if(num == 0){
        return;
    }
    convertToBinary(num/2);
    if(num%2 == 0){
        printf("0");
    }else{
        printf("1");
    }
}

// 6. SUM OF DIGITS
int sum_of_digit(int n){
    if(n == 0){
        return 0;
    }
    return (n%10) + sum_of_digit(n/10);
}

// 7. FACTORIAL
int factorial(int n){
    if(n <= 1){
        return 1;
    }
    return n * factorial(n - 1);
}


// 8. GET MAXIMUM AND MINIMUM ELEMENTS OF AN ARRAY
int getMax(int A[], int n){
    if(n == 0){
        return -1;
    }
    return fmax(getMax(A, n - 1), A[n - 1]);
}
int getMin(int A[], int n){
    if(n == 0){
        return 2147483647;
    }
    return fmin(getMin(A, n - 1), A[n - 1]);

}

// 9. COUNT NUMBER OF SET BITS
int CountSetBits(int n){
    if(n == 0){
        return 0;
    }
    return (n%2) + CountSetBits(n/2);
}

// 10. Fibonacci
int findFibonacci(int n) {
    // base case n = 0 , n = 1
    if (n == 0) {
       return 0;
    } else if (n == 1) {
       return 1;
    } else {
       return findFibonacci(n - 2) + findFibonacci(n - 1);
    }
 }
 
 int* fibonacciNumbers(int n) {
    int* ans = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
       ans[i] = findFibonacci(i);
    }
    return ans;
 }

// reverse fibonacci
void fibR(int n, int a, int b){
    if(n > 0){
        fibR(n - 1, b, a + b);
        printf("%d ", a);
    }
}

// first uppercase letter in a string (Iterative and Recursive)
// -> iterations
char IFirstUCase(char str[], int n){
    for(int i = 0; i < n; i+=1){
        int ascii = (int)str[i];
        if(ascii >= 65 && ascii <= 90){
            return str[i];
        }
    }
    return '_';
}
// -> recursive
char RFirstUCase(char str[], int start, int n){
    if(start == n){
        return '_';
    }
    if((int)str[start] >= 65 && (int)str[start] <= 90){
        return str[start];
    }
    return RFirstUCase(str, start + 1, n);
}

 
int main() {
    char str[] = "abCdefg";
    printf("%c\n", IFirstUCase(str, 7));
    printf("%c\n", RFirstUCase(str, 0, 7));
    return 0;
 }

