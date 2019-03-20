#include<iostream>
#include<fstream>
#include <stdio.h>

using namespace std;
int main(int a, char** b){
    int result;
    if(a != 3){
         cout<< "Error renaming file"<<endl;
         return 0;
    }
    result= rename( b[1] , b[2] );
    if ( result == 0 )
        cout<<" file successfully renamed "<<b[1] <<" to "<<b[2]<<endl;
    else
        cout<< "Error renaming file"<<endl;

    return 0;
}