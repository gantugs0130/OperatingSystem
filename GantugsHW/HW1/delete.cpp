#include<iostream>
#include<fstream>
#include <stdio.h>
using namespace std;
int main(int a, char** b){

  if(a!=2){
    cout<<"Wrong file name"<<endl;
    return 0;
  }
    if( remove( b[1] ) != 0 )
    cout<<"Wrong file name"<<endl;
  else
    cout<<b[1]<<" successfully deleted"<<endl;
    return 0;
}