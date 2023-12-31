/*
Group D-10

A palindrome is a string of character that is the same forward and backward.
Typically, punctuation, capitalization, and spaces are ignored.
For example, "Poor Dan is in a droop" is a palindrome, as can be seen by examining the characters
"poor danisina droop and observing that they are the same forward and backward.
One way to check for a palindrome is to reverse the characters in the string and then compare with
them the original-in a palindrome, the sequence will be identical. Write C++ program with functions-

1. to print original string followed by reverse string using stack
2. to check whether given string is palindrome or not
*/

#include<iostream>
#include<stdlib.h>
#define SIZE 20


using namespace std;


class mystack
{
   private:
          int top;
          char S[SIZE];
   public:
          mystack();
          void push(char);
          char pop();
          bool isEmpty();
          bool isFull();
};


mystack::mystack()
{
    top=-1;
}

bool mystack::isFull()
{
    if(top==SIZE-1)
        return 1;
    else
        return 0;
}

bool mystack::isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

void mystack::push(char x)
{
    if(!isFull())
    {
        top++;
        S[top]=x;
    }
    else
        cout<<"\n]t Stack Overflow!!";
}

char mystack::pop()
{
    char x = S[top];
    top--;
    return x;
}

void convert_str(char s1[], char s2[])
{
    int j=0;
    for(int i=0; s1[i]!='\0'; i++)
    {
        if(s1[i] <='z' && s1[i]>='a')
            s2[j++]= s1[i];

        if(s1[i] <='Z' && s1[i]>='A')
            s2[j++]= s1[i]+32;

    }
    s2[j]='\0';
}

int main()
{
	int ch,flag;
	char str[80],strc[80];
    int i;
	mystack st;
	system("clear");
	do
	{
		cout<<"\n\t 1 : Find Reverse of string";
		cout<<"\n\t 2 : Check string Palindrome";
		cout<<"\n\t 3 : Exit";
		cout<<"\n\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1 : cout<<"\n\t Enter the string to be reverse : ";
			         cin.ignore();
			         cin.getline(str,79);
			         cout<<"\n Original String : "<<str;
			         for(int i=0; str[i]!='\0'; i++)
			              st.push(str[i]);

                     cout<<"\n\t Reverse String : ";
                     while(!st.isEmpty())
                        cout<<st.pop();
                     break;

            case 2:  cout<<"\n\t Enter the string to be checked for palindrome : ";
			         cin.ignore();
			         cin.getline(str,79);
			         cout<<"\n Original String : "<<str;
			         convert_str(str,strc);
			         for(int i=0; strc[i]!='\0'; i++)
			              st.push(strc[i]);

                     flag=1;
                     i=0;
                     while(!st.isEmpty())
                     {
                         if(strc[i] != st.pop())
                            flag=0;
                            break;
                     }
                     if(flag==1)
                        cout<<"\n\t String is Palindrome ";
                     else
                        cout<<"\n\t String is not palindrome";
                     break;

			case 3 : cout<<"\nEnd of Program\n";
					 break;
			default: cout<<"\nInvalid choice !! Try again\n\n";
		}
	}while(ch != 3);
	return 0;
}
