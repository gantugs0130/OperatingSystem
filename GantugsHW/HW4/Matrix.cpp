#include<iostream>
#include<cstdlib>
#include<pthread.h>
#define ax 3
#define bx 4
#define ay 4
#define by 3
using namespace std;

    long ehnii[ax][ay];
    long hoyrdoh[bx][by];
    long hariu[ax][by];
void *doIt(void * threadid){
    long tid;
    tid = (long)threadid;
    long mor = tid / by;
    long bagana = tid % ax;
    long sum = 0;
    for(int i = 0; i < ay; i++){
        sum  += ehnii[mor][i]*hoyrdoh[i][bagana];
    }
    hariu[mor][bagana] = sum;
    pthread_exit(NULL);
}
int main(){
    if(ay != bx){
        cout<<"hoyr matrits urjigdehgui zow utga oruulna uuu!!!";
        return 0;
    }else{
    for(int i = 0; i < ax; i++){
        for(int j = 0; j <ay; j++){
            ehnii[i][j] = 1;
        }
    }
    for(int i = 0; i < bx; i++){
        for(int j = 0; j < by; j++){
            hoyrdoh[i][j] = 2;
        }
    }
    pthread_t threads[ax*by];
    int rc;
    for(int i = 0; i<ax*by; i++){
        rc = pthread_create(&threads[i],NULL,doIt,(void *)i);
        if(rc){
            cout<<"error";
            exit(1);
        }
    }
    for(int i = 0; i < ax; i++){
        for(int j = 0; j < by; j++){
            cout<<hariu[i][j]<<"\t";
        }
        cout<<endl;
    }
    pthread_exit(NULL);
    }
}