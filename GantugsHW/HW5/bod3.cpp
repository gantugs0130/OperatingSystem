    #include<iostream>
    using namespace std;
    int main(){

        long long int number;
        cin >> number;
        long long int b[100000][2];
        for(int it = 0; it<number; it++){
            long long int n,m,k;
            cin>>n>>m>>k;

            long long int answer = 4*k;
        

            
                cin>>b[0][0];
                cin>>b[0][1];
            long long int now = 1;
            long long int omnoh=0;
            for(long long int i=1; i<k; i++){
                cin>>b[i][0];
                cin>>b[i][1];
                
                if(b[i][0]==b[i-1][0]){
                    now ++; 
                    if(b[i][1]-1==b[i-1][1]){
                        answer-=2;
                    }
                    for(long long int j = 0; j < omnoh; j++){
                
                        if((b[i][0]-1) == b[i-now-j][0] && b[i][1]==b[i-j-now][1]){
                            answer-=2;
                            break;
                        }
                    }
                    
                    
                }else{
                    omnoh = now;
                    now = 1;
                    for(long long int j = 0; j < omnoh; j++){
                        if(b[i][0]-1 == b[i-now-j][0] && b[i][1]==b[i-j-now][1]){
                            answer-=2;
                            break;
                        }
                    }
                }
            }
            cout << answer<<endl;
        }

        
        return 0;
    }