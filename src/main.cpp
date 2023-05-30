// .\excalibur.exe --source "G:\DCIM\105MSDCF" --output "G:\DCIM\105MSDCF"

#include <iostream>
#include <filesystem>
#include <sys/stat.h>
using namespace std;
namespace fs = std::filesystem;
int checkDirectory(char* directory) // defines the function for checking the directory. 
{
    struct stat metadata; // defining variable called metadata. variable is a struct type. 
    if (stat(directory, &metadata) == 0) // stat function returns 0 if something exists in the location we have provided. (Directory variable) And updates the metadata variable value to the metadata of the object that we found. (the "&" is a refrence to the metadata variable.)
    {
        if(metadata.st_mode&S_IFDIR) // checks if object is a directory using built in macro
        {
            cout<< "Directory found" << endl; // prints if directory is found. 
            return 1; 
        }
    }
    return 0;    
}
int inputValidation(char* source, char* output) // defines the funtion of input validation
{
    if (source != "") // if source is not empty
    {
        cout << "Source destination: " << &source << endl; // prints the contents of the source variable
    }
    else
    {
        cout << "Source destination required. Please use the --source argument" << endl; // prints error
        return 0;
    }
    if (output != "")
    {
        cout << "Output destination: " << &output << endl; // prints the contents of the output variable
    }
    else
    {
        cout << "Output destination required. Please use the --output argument" << endl; // prints error
        return 0;
    }
    if (strcmp(source, output)== 0){ // detects if source and output values are the same.
        cout <<"Source and output directories cannot be same."<< endl; // prints error
        return 0;
    }
    if (checkDirectory(source) != 1){ // checks if source value exists and is a directory 
        cout << "invalid source directory";
        return 0;
    }
    if (checkDirectory(output) != 1 ){ // checks if output value exists and is a directory
        cout << "invalid output directory";
        return 0;
    }
    return 1;
}
int main(int argc, char **argv) // defines the main function of the program
{
    char* source; // defines source as an array of characters
    char* output; // defines sources as an array of characters

    for (int i = 0; i < argc; i++) // while our itterator is smaller than check value,complete the code below and increment the itterator. 
    {
        if (std::string_view(argv[i]) == "--source") //looking at the argument value at the index of the itterator and comparing that with key what we are looking for.  
        {
            source = argv[i + 1]; // setting the source variable to the value at the location of itterator +1 in the argument value (array).
        }
        else if (std::string_view(argv[i]) == "--output") //looking at the argument value at the index of the itterator and comparing that with key what we are looking for.  
        {
            output = argv[i + 1]; // setting the output variable to the value at the location of itterator +1 in the argument value (array).
        }
    }
    if (inputValidation(source,output) == 0){
        return 0;
    }
    for (auto const& dir_entry : fs::recursive_directory_iterator(source))
    {
        cout << dir_entry << endl;
        std::filesystem::path file = dir_entry;
        std::string file_str = file.string();
        const char * file_ptr = file_str.c_str();  
        struct stat file_metadata;
        stat(file_ptr, &file_metadata);
        cout<< file_metadata.st_atime << endl;
        time_t t =  file_metadata.st_atime;
        cout << ctime(&t) << endl;

    }
}
