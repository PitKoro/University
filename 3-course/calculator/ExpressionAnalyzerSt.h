#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

/// Результат разбора выражения - число либо текст ошибки
class ParseResult
{
    double result1;
    string error1;

public:
    /// Конструирует корректный результат (число)
    ParseResult(double result){
        result1=result;
    }

    /// Конструирует ошибочный результат
    ParseResult(string error){
        error1=error;
    }

    /// Возвращает значение, показывающее, есть ли ошибка
    bool is_error(){
        if(error1!=""){
            return true;
        }
        else
        {
            return false;
        }
    }

    /// Возвращает число
    double get_result()
    {
        return result1;
    }

    /// Возвращает текст ошибки
    string get_error(){
        return error1;
    }

};


/// Типы токенов - перечисление, где каждому имени компилятором автоматически сопоставляется целое число.
enum TokenType
{
    EMPTY,
    NUMBER,
    OPER,
    UNKNOWN // Не пойми что - ошибка разбора
};


/// Токен (лексема, слово) - число, строка, пусто либо не пойми что.
class Token
{
    char oper;
    double number;
    char unknown;


    TokenType type;


public:
    Token(char str){
        if(str=='+'||str=='-'){
            type=OPER;
            oper=str;
        }
        else{
           type=UNKNOWN;
           unknown=str;
        }
    }

    Token(double num)
    {
        number=num;
        type=NUMBER;
    }

    Token()
    {
       type=EMPTY;
    }

    bool is_number()
    {
        if(type==NUMBER)
        {
            return true;
        }
        else{
            return false;
        }
    }

    bool is_empty()
    {
        if(type==EMPTY)
        {
            return true;
        }

        else{
            return false;
        }
    }

     bool is_oper()
     {
        if(type==OPER)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

   char get_oper()
    {
        return oper;
    }


   double get_number()
   {
    return number;
   }


    void debug()
   {
    if(type==EMPTY)
    {
        cout<<"Token type="<<type<<"=="<<EMPTY<<endl;
    }
    if(type==UNKNOWN){
            cout<<"Token type="<<type<<"=="<<unknown<<endl;
    }
    if(type==NUMBER){
            cout<<"Token type="<<type<<"=="<<number<<endl;
    }
    if(type==OPER)
    {
        cout<<"Token type="<<type<<"=="<<oper<<endl;
    }
   };
};



/// Разбивает строку на токены
class Tokenizer
{
    string expr1;
    int cur=0;
public:
    /// Конструирует новый объект - при этом запоминается строка для разбора
    Tokenizer(string expr)
    {
        expr1=expr;
    };


    /// Возвращает следующий токен из запомненной строки.
    /// Если строка кончилась, возвращает пустой токен token.is_empty()=true
    /// Если в строке ерунда - возвращает токен с type=UNKNOWN
Token next_token()
{
     string strfordouble="";
     for(cur; cur<expr1.length();cur++)
     {
            if(expr1[cur]=='-'||expr1[cur]=='+')
            {
                cur++;
                return Token(expr1[cur-1]);
            }
            else if(isdigit(expr1[cur]))
            {


                int cur0=cur;
                while(cur<expr1.length()&&isdigit(expr1[cur]))
                {
                    cur++;
                }

                if(cur<expr1.length()&&expr1[cur]=='.')
                {

                    cur++;
                    int tmp=cur;

                    while(cur<expr1.length()&&isdigit(expr1[cur]))
                    {
                        cur++;
                    }

                    if(tmp==cur)
                    {
                        return Token(expr1[cur-1]);
                    }
                }

                double dbl=atof(expr1.substr(cur0,cur-cur0).c_str());
                return Token(atof(expr1.substr(cur0,(cur-cur0)).c_str()));
            }
            else
            {
                cur++;
                return Token(expr1[cur-1]);
            }
    }

    return Token();
}

};

/// Применяет оператор к аргументам num1 и num2 и записывает результат в result
/// Возвращает true, если оператор известен, иначе false
bool apply_op(char op, double num1, double num2, double* result)
{
    if (op == '+')
    {
        *result = num1 + num2;
    }
    else if (op == '-')
    {
        *result = num1 - num2;
    }
    else
    {
        return false;
    }

    return true;
}


/// Разбирает арифметическое выражение и считает результат
ParseResult eval(string expr)
{
    /*
     * Грамматика
     *
     * Expression = Number [op Number]*
     * op = '+' | '-'
     * Number = Digit+[.Digit+]
     * Digit = '0' | '1' | ... | '8' | '9'
     *
     * (где [] - необязательная часть выражения
     * something* - выражение something может повторяться 0 и более раз
     * something+ - выражение something должно быть - по крайней мере 1 раз. Но можно и много раз подряд.
     * )
    */


    Tokenizer tok = Tokenizer(expr);
    Token t1 = tok.next_token();

    if (!t1.is_number())
    {
        return ParseResult("Expected number");
    }

    double result = t1.get_number();

    while(true)
    {
        Token op_token = tok.next_token();
        if (op_token.is_empty())
        {
            break;
        }

        if (!op_token.is_oper())
        {
            return ParseResult("Expected operator");
        }

        Token num_token = tok.next_token();
        if (!num_token.is_number())
        {
            return ParseResult("Expected number");
        }

        char op = op_token.get_oper();
        if (!apply_op(op, result, num_token.get_number(), &result))
        {
            return ParseResult(string("Unknown operator ") + op);
        }
    }

    return ParseResult(result);
}

