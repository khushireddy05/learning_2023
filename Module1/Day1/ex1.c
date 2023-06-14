/*Write a function to find biggest of 2 numbers using 
    - if else
    - ternary operator*/

#include <stdio.h>

int main(){
    int using_ifelse(int a, int b){
    if (a > b){
        return a;
    }
    else{
        return b;
    }
    }

    int using_ternary(int a, int b) {
    return (a > b) ? a : b;
    }
    return 0;
}
