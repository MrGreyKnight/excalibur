// .\escalibur --source "H:\\DCIM" --output "C:\\user\files\images\"

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    for (int i = 0; i < argc; i++ ){
        cout << argv[i] << endl; 
        if (std::string_view(argv[i]) == "--source"){
            cout << "source found at index " << i << endl;
        }
        else if (std::string_view(argv[i]) == "--output"){
            cout << " output found at index" << i << endl;
        }
    }
}