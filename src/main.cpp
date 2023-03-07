// .\escalibur --source "H:\\DCIM" --output "C:\\user\files\images\"

#include <iostream>
#include <sys/stat.h>
using namespace std;
int checkDirectory(char* directory) 
{
    struct stat metadata;
    if (stat(directory, &metadata) == 0)
    {
        return 1;
    }
    return 0; 
}
int main(int argc, char **argv)
{
    char* source;
    char* output;

    for (int i = 0; i < argc; i++)
    {
        if (std::string_view(argv[i]) == "--source")
        {
            source = argv[i + 1];
        }
        else if (std::string_view(argv[i]) == "--output")
        {
            output = argv[i + 1];
        }
    }
    if (source != "")
    {
        cout << "Source destination: " << source << endl;
    }
    else
    {
        cout << "Source destination required. Please use the --source argument" << endl;
        return 0;
    }
    if (output != "")
    {
        cout << "Output destination: " << output << endl;
    }
    else
    {
        cout << "Output destination required. Please use the --output argument" << endl;
        return 0;
    }
    if (checkDirectory(source) != 1){
        cout << "invalid source directory";
    }
    if (checkDirectory(output) != 1 ){
        cout << "invalid output directory";
    }
}

