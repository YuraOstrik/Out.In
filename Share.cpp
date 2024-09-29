#include <fstream>
#include <iostream>
#include <cstring>
#include <Windows.h>

using namespace std;

int main()
{

    ifstream in;
    in.open("HTMLPage.htm", ios::in);

    if (in)
    {
        const int size = 300;
        int lineNumber = 0; 
        bool error = false; 

        do {
            char buffer[size] = {};
            lineNumber++; 

            in.getline(buffer, size);

         

            bool openBracket = false;

         
            for (int i = 0; i < strlen(buffer); i++)
            {
                if (buffer[i] == '<')
                {
                    if (openBracket)
                    {
                        
                        cout << "Error < " << lineNumber << endl;
                        error = true;
                    }
                    openBracket = true; 
                }
                else if (buffer[i] == '>')
                {
                    if (!openBracket)
                    {
                   
                        cout << "Error > " << lineNumber << endl;
                        error = true;
                    }
                    openBracket = false;
                }
            }

      
            if (openBracket)
            {
                cout << " Oups < > " << lineNumber << endl;
                error = true;
            }

        } while (in);

        if (!error)
        {
            cout << "Good job" << endl;
        }

        in.close();
    }
    else
    {
        cout << "File does not exist" << endl;
    }

    return 0;
}
