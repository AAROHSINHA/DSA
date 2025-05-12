#include <stdio.h>

void func1(int n){
    if(n > 0){
        printf("%d\n", n);
        func1(n - 1);
    }
}

void func2(int n){
    if(n > 0){
        func2(n - 1);
        printf("%d\n", n);
    }
}


// sum of n terms
int sum(int n){
    if(n > 0){
        return sum(n - 1) + n;
    }
    return 0;
}

// static variables
int funcAdd1(int n){
    static int x = 0;
    if(n > 0){
        x++;
        return funcAdd1(n - 1) + x;
    }
    return 0;
}

// global variables
int y = 5;
int funcAdd2(int n){
    if(n > 0){
        y++;
        return funcAdd2(n - 1) + y;
    }
    return 0;
}

// Tree Recursion
void TreeFun(int n){
    if(n > 0){
        printf("%d\n", n);
        TreeFun(n - 1);
        TreeFun(n - 1);
    }
}

/*
// Indirect Recursion
void funA(int n){
    if(n > 0){
        printf("%d ", n);
        funB(n - 1);
    }
}

void funB(int n){
    if(n > 0){
        printf("%d ", n);
        funA(n / 2);
    }
}
*/


// NESTED RECURSION
int NestedFunc(int n){
    if(n > 100){
        return n - 10;
    }else{
        return NestedFunc(NestedFunc(n + 11));
    }
}


int main(){
    printf("%d\n", NestedFunc(95));
    return 0;
}
