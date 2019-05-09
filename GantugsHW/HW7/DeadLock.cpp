#include<iostream>
using namespace std;

int need[5][4];
int avail[4] = { 1, 5, 2, 0 };
int ans[5];
int alloc[5][4] = { { 0, 0, 1, 2 },
                    { 1, 0, 0, 0 },
                    { 1, 3, 5, 4 },
                    { 0, 6, 3, 2 },
                    { 0, 0, 1, 4 }};

int max1[5][4] = { { 0, 0, 1, 2 },
                  { 1, 7, 5 ,0 },
                  { 2, 3, 5 ,6 },
                  { 0, 6, 5, 2 },
                  { 0, 6 ,5, 6 }};


bool isdeadlock(){
int n, m;
    n = 5;
    m = 4;
    int it = 0;
    bool iswork[n];
    for (int i = 0; i < n; i++) {
        iswork[i] = false;
    }

    for (int i = 0; i < n; i++) {
            cout <<" process "<< i <<" need = ";
        for (int j = 0; j < m; j++){
            need[i][j] = max1[i][j] - alloc[i][j];
             cout <<" "<<need[i][j];
        }
        cout << endl;
    }
    int y = 0;
    for (int l = 0; l < 5; l++) {
        for (int i = 0; i < n; i++) {

            if (iswork[i] == false) {
                bool ajilahboloh = true;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]){
                        ajilahboloh = false;
                        break;
                    }
                }
                if (ajilahboloh == true) {
                    ans[it++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    iswork[i] = true;
                }
            }
        }
    }
    bool deadlock = false;
    for(int i = 0; i < n; i++){
        if(!iswork[i]){
            cout << "deadlock uusne"<<endl;
            deadlock = true;
        }
    }
    return deadlock;
}

int main()
{



if(isdeadlock()==false){
   for(int i = 0; i < 5; i++)
        cout<<" process "<<(ans[i])<<" "<<endl;
        cout<<" gesen daraallaar ajilna"<<endl;
    }

    max1[1][0] = 0;
    max1[1][1] = 4;
    max1[1][2] = 2;
    max1[1][3] = 0;

    if(isdeadlock()==false){
        for(int i = 0; i < 5; i++)
        cout<<" process "<<(ans[i])<<" "<<endl;
        cout<<" gesen daraallaar ajilna"<<endl;
    }

    return (0);
}
