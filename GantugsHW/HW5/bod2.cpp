#include <iostream>
using namespace std;

int main() {
	long long int number;
    cin >> number;
    long long int urt;
    char ug[1000000];
    for(long long int it=0; it<number; it++){
        long long int sum = 0;
        cin >> urt;
        
        char useg;
        for(long long int i = 0; i < urt; i++){
            cin >> ug[i];
        }
        cin >> useg;
        long long int ind = -1;
        for(long long int i = 0; i<urt; i++){
            if(ug[i]==useg){
                sum += (i-ind)*(urt-i);
                ind = i;
            }
        }
        cout<<sum<<endl;
    }
	return 0;
}
