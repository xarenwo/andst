#include <iostream>
#include <time.h>
using namespace std;


long int fib_rec(int n) {
    long int result;
    if(n==1 || n==2) {
        result = 1;
    } else {
        result = fib_rec(n-1) + fib_rec(n-2);
    }
    return result;
}

long fibo_bot_up(int n) {
    long int fibo[n+2];
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i=2; i<=n; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    return fibo[n];
}


int main () {
    clock_t tStart = clock();
    int mem[60] = {0};
    //cout << fib_rec(56) << endl;
    cout << fibo_bot_up(600) << endl;
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
