#include <iostream>
#include <dirent.h>
#include <sys/stat.h>
#include <fstream>
using namespace std;

void printFileNames(string directory) {
    string filepath;
    ifstream fin;
    DIR *dp;
    struct dirent *dirp; // the directory file
    struct stat filestat;

    dp = opendir(directory.c_str()); // open the directory
    if (dp == nullptr) // check and see if there was an error opening a given directory
    {
        cout << "Error(" << errno << ") opening " << directory << endl;
    }

    int i = 0;
    while ((dirp = readdir(dp)) != nullptr) // while files exist in the directory
    {
        if(i == 1 || i == 0) { // this is necessary because the first 2 lines that it tries to read are <directory>/. and <directory>/..
            i++;
            continue;
        }
        if (dirp == nullptr )
            break;

        filepath = directory + "/" + dirp->d_name;

        // If the file is a directory (or is in some way invalid) we'll skip it
        if (stat(filepath.c_str(), &filestat)) continue;
        if (S_ISDIR(filestat.st_mode))  { //If the file is a directory, recursive call to this function
            printFileNames(filepath);
        } else {
            cout << filepath <<endl; //else print out the name of the file
        }


        fin.close(); // be sure to close files

    }
    closedir(dp); // closing the directory
}

int main() {
    string directory = "input";
    printFileNames(directory);
    return 0;
}
