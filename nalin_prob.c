#include <stdio.h>
#include <setjmp.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#define LEN 50

jmp_buf po;

void print_T() {
    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime ( &rawtime );
    printf ( "Current local time and date: %s", asctime (timeinfo) );
}



static void ti() {
    print_T();
    longjmp(po,1);
}
int funcall(int reply) {


    static int p;
    p = 0;
    signal(SIGALRM, ti);
    int q = setjmp(po);
    if(q == 0)  
        printf("the value BEFORE setjmp %d for reply %d\n", p, reply);
    else 
        printf("the value AFTER setjmp %d for reply %d\n", p, reply);
    alarm(5);

    if(p > 0) {
        printf("INVOKING THE ALARM");
        alarm(0);
        return -1;
    }

    p++;    
    for(int i = 0; i < 10000; i++){ 
        for(int j = 0; j < 1000; j++);
    }
    return 0;

}

int main() {

    int a;
    int reply;
    time_t start, end;
    for(reply=0; ; reply++) {
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~ITERATION NUMBER  %d\n", reply);

        time(&start);
        a = funcall(reply);
        time(&end);
        double tin = difftime(end, start);
        printf("*********************ITERATION END  and a returned is %d after %f\n", a, tin );
        double tidiff = difftime(end, start);
        if(a < 0 && reply==10)
            break;     
        }
}
