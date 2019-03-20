#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    DIR *a;
    a  = opendir(".");
    while (readdir(a) != NULL) {
        cout<< "\t"<<string(readdir(a)->d_name)<<endl;
    }
    closedir(a);
    return 0;
}