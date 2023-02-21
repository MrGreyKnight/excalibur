// .\escalibur --source "H:\\DCIM" --output "C:\\user\files\images\"

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    string source = "";
    string output = "";

    for (int i = 0; i < argc; i++ ){
        if (std::string_view(argv[i]) == "--source"){
            source = argv[i+1];
        }
        else if (std::string_view(argv[i]) == "--output"){
            output = argv[i+1];
        }
    }
    if (source != "") {
        cout << "This is the source..." << source << endl;
    } else {
        cout << "source is undefined" << endl;
        return 0; 
    }
    if (output != "") {
        cout << "This is the output..." << output << endl;
    } else {
        cout << "output is undefined" << endl;
        return 0; 
    }
}