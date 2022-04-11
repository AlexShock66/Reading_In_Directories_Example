#include <iostream>
#include <dirent.h>
#include <sys/stat.h>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

void open_dir_using_dirent(const string& directory) {
    string filepath;
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

        filepath = directory + "/" + dirp->d_name;

        // If the file is a directory (or is in some way invalid) we'll skip it
        if (stat(filepath.c_str(), &filestat)) continue;
        if (S_ISDIR(filestat.st_mode))  { //If the file is a directory, recursive call to this function
            open_dir_using_dirent(filepath);
        } else {
            cout << filepath <<endl; //else print out the name of the file
        }
    }
    closedir(dp); // closing the directory
}

void open_dir_using_filesystem(const string& directory){
    for (const auto & entry : fs::recursive_directory_iterator(directory)){
        if (entry.is_regular_file()) {
            if (entry.path().extension().string() == ".txt") {
                string filename = entry.path().c_str();
                std::cout << filename << std::endl;
            }
        }
    }
}


int main() {
    string directory = "input"; // This should be the absolute path to your data folder
    std::cout<<"\n================ Finding all .txt files using Dirent.h ================"<<std::endl;
    open_dir_using_dirent(directory);


    std::cout<<"\n================ Finding all .txt files using Filesystem ================"<<std::endl;
    // If you are using filesystem then you should change the set(CMAKE_CXX_STANDARD 14) in your CMakeLists.txt to set(CMAKE_CXX_STANDARD 17)
    open_dir_using_filesystem(directory);
    return 0;

    /*  EXPECTED OUTPUT:
         input/input_2/inside_input_2_01.txt
         input/input_2/inside_input_2_02.txt
         input/input_3/inside_input_3_01.txt
         input/input_3/inside_input_3_02.txt
         input/inside_input_01.txt
         Process finished with exit code 0
     */
}
