#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

int i = 0;
char s[10];
int n;
int k=1;

/* Function declaration*/
void S();
void A();
void B();
void Accept();
void Reject();
void Parser();

////////////

int main()
{
   
    cout << "Given this grammar : " << endl;
    cout << "S -> aBc/bcA" << endl;
    cout << "A -> bB/a" << endl;
    cout << "B -> aA/b" << endl;
    cout << "Enter the number of strings" << endl;
    cin >> n;
    while (n>0)
    {   
        cout << "Enter the string " << k++ << endl;
        cin>>s;
        i=0;
        Parser();
        n--;
    }
    
    
    return 0;
}

////////////

 void Parser()
    {
    S();
    if (s[i] == NULL){
        Accept();
        }
    }

////////////

void S()
{
    if (s[i] == 'a')
    {
        i++;
        B();
        if (s[i] == 'c')
            i++;
        else
            Reject();
    }
    else if (s[i] == 'b')
    {
        i++;
        if (s[i] == 'c')
        {
            i++;
            A();
        }
        else
            Reject();
    }
    else{
        Reject();
    }
}

////////////

void A() 
{
    if (s[i] == 'b'){
        i++;
        B();
    }
    else if( s[i] == 'a'){
        i++;
    }
    else
        Reject();
}

////////////

void B() 
{
    if (s[i] == 'a'){
        i++;
        A();
    }
    else if( s[i] == 'b'){
        i++;
    }
    else
        Reject();
}

////////////

void Reject()
{
    cout << "string is invalid" << endl;
}

////////////

void Accept()
{
    cout << "string is valid" << endl;
}

