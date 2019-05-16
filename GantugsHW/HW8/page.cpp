#include<iostream>
using namespace std;

int refrence[20] = {7, 2, 3, 1, 2, 5, 3, 4, 6, 7, 7, 1, 0, 5, 4, 6, 2, 3, 0 , 1};
//{7, 2, 3, 1, 2, 5, 3, 4, 6, 7, 7, 1, 0, 5, 4, 6, 2, 3, 0 , 1}
//{1, 2, 3, 2, 1, 4, 3, 5, 6, 4, 3, 5, 3, 5, 6, 7, 2, 1, 5 , 7};
int frame = 3;



    void fifo(){
        int husnegt[3] = {-1, -1, -1};
        int number = 0;
        int x = 0;
        for(int i = 0; i < 20; i++){
            bool a = false;
            for(int j = 0; j < 3; j++){
                if(refrence[i] == husnegt[j]){

                    a = true;
                    break;
                }
            }
            if(!a){
                husnegt[x] = refrence[i];
                x++;
                if(x==3){
                    x = 0;
                }
                number++;
            }
        }
        cout <<"FIFO => "<< number<<endl;
    }
    void lru(){
        int husnegt[3] = {-1, -1, -1};
        int number = 0;
        int x = 0;
        int b[3]={0,0,0};
        for(int i = 0; i < 20; i++){
            bool a = false;
            for(int j = 0; j < 3; j++){
                if(refrence[i] == husnegt[j]){
                    b[j] = 0;
                    a = true;
                }else{
                    b[j]++;
                }

            }
            if(!a){
                if(b[0] > b[1] && b[0]>b[2]){
                    x = 0;
                }
                if(b[1]>b[0] && b[1]>b[2]){
                    x = 1;
                }
                if(b[2]>b[1] && b[2]>b[0]){
                    x = 2;
                }

                if(b[0]==b[1]&& b[0]==b[2]){
                    x = 0;
                }else{
                    if(b[1]==b[2]){
                    x = 1;}
                }
                husnegt[x] = refrence[i];
                  b[x] = 0;
                  for(int l = 0; l < 3; l++){
                        if(l!=x){
                            b[l]++;
                        }
                    }
                number++;
            }
        }
        cout <<"LRU => "<< number<<endl;
    }

    void optimal(){
        int husnegt[3] = {-1, -1, -1};
        int number = 0;
        int x = 0;
        for(int i = 0; i < 20; i++){
            bool a = false;
            for(int j = 0; j < 3; j++){
                if(refrence[i] == husnegt[j]){
                    a = true;
                    break;
                }
            }
            if(!a){
                    bool p[3];
                    p[0] = false;
                    p[1] = false;
                    p[2] = false;
                    int y[3]= {0,0,0};
                        for(int l=0; l<3;l++){
                                for(int j = i + 1; j < 20; j++){
                                     if(husnegt[l]==refrence[j]){
                                        y[l] = j;
                                        p[l] = true;
                                        break;
                                    }
                                }

                        }

                if(!p[0]){
                    x = 0;
                }else{
                    if(!p[1]){
                        x = 1;
                    }else{
                        if(!p[2]){
                            x = 2;
                            }else{
                                if(y[0]>y[1]&&y[0]>y[2]){
                                    x = 0;
                                }
                                if(y[1]>y[0]&&y[1]>y[2]){
                                    x = 1;
                                }
                                if(y[2]>y[1]&&y[2]>y[0]){
                                    x = 2;
                                }
                            }
                    }
                }

                husnegt[x] = refrence[i];
                number++;
            }
        }
        cout <<"OPTIMAL => "<< number<<endl;
    }

int main(){
    fifo();
    lru();
    optimal();
    return 0;
}
