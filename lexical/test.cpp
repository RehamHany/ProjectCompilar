#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
using namespace std;
/* Array of keywords*/
int isKeyword(char buffer[])
{
    char keywords[32][10] =
        {"auto", "break", "main", "case", "char", "const", "continue", "default",

         "do", "double", "else", "enum", "extern", "float", "for", "goto",

         "if", "int", "long", "register", "return", "short", "signed",

         "sizeof", "static", "struct", "switch", "union",
         
         "unsigned", "void", "volatile", "while"};
    int i, flag = 0;

    for (i = 0; i < 32; ++i)
    {
        if (strcmp(keywords[i], buffer) == 0)
        {
            flag = 1;
            break;
        }
    }

    return flag;
}
int main()
{
    
    char ch, buffer[15], operators[] = "+-*/%=<>" , specialCaracter[]= "(){}[],.:'" , logicalSembol[]="&|!?";


    ifstream fin("lexicalinput.txt"); 
    int i, j = 0;

    if (!fin.is_open())
    {
        cout << "error while opening the file\n";
        exit(0);
    }

    while (!fin.eof())
    {
        ch = fin.get();

        for (i = 0; i < 8; ++i)
        {
            if (ch == operators[i])
                cout << ch << " is operator\n";
        }

        for (i = 0; i < 11; ++i)
        {
            if (ch == specialCaracter[i])
                cout << ch << " is SpecialCaracter\n";
        }

         for (i = 0; i < 4; ++i)
        {
            if (ch == logicalSembol[i])
                cout << ch << " is LogicalSymbol\n";
        }

        if(ch==';'){
             cout << ch << " is Semicolon\n";
        }



        if (isalnum(ch))
        {
            buffer[j++] = ch;
        }
        else if ((ch == ' ' || ch == '\n') && (j != 0))
        {
            buffer[j] = '\0';
            j = 0;

            if (isKeyword(buffer) == 1)
                cout << buffer << " is keyword\n";
            else
                cout << buffer << " is identifier\n";
        }
    }

    fin.close(); // close input file

    return 0;
}