// .\escalibur --source "H:\\DCIM" --output "C:\\user\files\images\"

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    string source = "";
    string output = "";

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
}