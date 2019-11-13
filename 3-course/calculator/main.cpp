#include <iostream>
#include <string>
#include "ExpressionAnalyzerSt.h"

using namespace std;

void TestTokenizer(string expr);


int main()
{
    cout << "Input expression: ";
    string expr;
    getline(cin, expr);
    //TestTokenizer(expr);
    ParseResult result = eval(expr);

    if (result.is_error())
    {
        cout << "ERROR: " << result.get_error() << endl;
    }
    else
    {    cout<<endl;
        cout << "Result is " << result.get_result() << endl;
    }

    return 0;
}

void TestTokenizer(string expr)
{
    Tokenizer test = Tokenizer(expr);
    bool exit = false;

    while(!exit)
    {
        Token t = test.next_token();
        t.debug();

        exit = t.is_empty();
        cout<<"t.is_empty()=="<<t.is_empty()<<endl;

    }
}
