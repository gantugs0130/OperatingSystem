#include<iostream>
#include<fstream>

using namespace std;
int main(int a, char** b){
        ofstream myfile;
        myfile.open (b[1]);
        for(int i = 2; i < a; i++)
        myfile << b[i] << " ";
        myfile.close();
        return 0;
}