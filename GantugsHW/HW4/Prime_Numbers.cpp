#include<iostream>
#include<cstdlib>
#include<pthread.h>

using namespace std;

bool isPrimeNumber(long x){
    bool y = true;
    if(x == 1){
        y = false;
    }
    for(long i=2; i < x; i++){
        if(x % i == 0){
            y = false;
        }
    }
    return y;
}
void *doIt(void * threadid){
    long tid;
    tid = (long)threadid;
    if(isPrimeNumber(tid)){
        cout << tid  <<"is prime number"<<endl;
    }
    pthread_exit(NULL);
}
int main(){
    pthread_t threads[100];
    int rc;
    for(int i = 1; i<101; i++){
        rc = pthread_create(&threads[i],NULL,doIt,(void *)i);
        

        if(rc){
            cout<<"error";
            exit(1);
        }
    }
    pthread_exit(NULL);



}