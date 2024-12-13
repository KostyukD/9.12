#include <iostream>
#include <fstream>

using namespace std;

bool isValidHTML(const string& filename) 
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "File not found." << endl;
        return false;
    }

    char ch;
    int tagDepth = 0;
    bool insideTag = false;

    while (file.get(ch)) 
    {
        if (ch == '<')
        {
            insideTag = true;
            tagDepth++;
        }
        else if (ch == '>')
        {
            if (insideTag)
            {
                insideTag = false;
                tagDepth--;
            }
            else {
                return false;
            }
        }
        else {
            if (insideTag)
            {
                if (ch == '/')
                {
                    if (tagDepth <= 0) 
                    {
                        return false;
                    }
                    tagDepth--;
                }
            }
        }
    }

    return tagDepth == 0;
}

int main() 
{
    string filename;
    cout << "Enter the path to the HTML file: ";
    cin >> filename;

    if (isValidHTML(filename)) 
    {
        cout << "The HTML file is valid." << endl;
    }
    else 
    {
        cout << "The HTML file is invalid." << endl;
    }
}
