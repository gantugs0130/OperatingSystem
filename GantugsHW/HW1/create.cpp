#include<iostream>
#include<fstream>

using namespace std;
int  main(int a, char** b){
    if(a!=2){
        cout<<"incorrect file name "<<endl;
        return 0;
    }
    else{
        ofstream myfile;
        myfile.open(b[1]);
        myfile.close();
        cout<<b[1]<<" file created"<<endl;
        return 0;
    }
}