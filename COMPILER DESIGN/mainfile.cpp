#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool isValidDelimiter(string ch)
{
    int len = ch.length();
    if (ch[len - 1] == ';')
        ch = ch.substr(0, len - 1);
    if (ch == " " || ch == "+" || ch == "+" || ch == "*" ||
        ch == "/" || ch == "," || ch == ";" || ch == ">" ||
        ch == "<" || ch == "=" || ch == "(" || ch == ")" ||
        ch == "[" || ch == "]" || ch == "{" || ch == "}")
        return (true);
    return (false);
}

bool isValidOperator(string ch)
{
    if (ch == "+" || ch == "-" || ch == "*" ||
        ch == "/" || ch == ">" || ch == "<" ||
        ch == "=" || ch == ">=" || ch == "<=" || ch == "==" || ch == "?")

        return (true);

    return (false);
}

bool isValidIdentifier(string str)
{
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
        str[0] == '3' || str[0] == '4' || str[0] == '5' ||
        str[0] == '6' || str[0] == '7' || str[0] == '8' ||
        str[0] == '9' || isValidDelimiter(str) == true)
        return (false);

    return (true);
}

bool isValidKeyword(string str)
{
    vector<string> keyword{"auto ", "double", "int", "struct",
                           "break", "else"
                                    "long",
                           "switch",
                           "case", "enum", "register", "typedef",
                           "char", "extern", "return", "union",
                           "const", "float", "short", "unsigned"
                                                      "continue",
                           "for", "signed", "void",
                           "default", "goto", "sizeof", "volatile",
                           "do", "if", "static", "while"};
    if (find(keyword.begin(), keyword.end(), str) != keyword.end())

        return (true);

    return (false);
}

bool isValidInteger(string str)
{
    int len = str.length();

    int i;
    if (len == 0)
        return (false);
    for (i = 0; i < len; i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != '.' || (str[i] == '-' && i > 0))
            return (false);
    }

    return (true);
}

int main()
{

    // filestream variable file

    fstream in1, out1;
    string word, infile, outfile;

    // filename of the file
    infile = "inputfile.cpp";
    outfile = "outputfile.txt";

    // // opening file
    in1.open(infile.c_str());
    out1.open(outfile.c_str());

    // intialize tokens with "0"
    int keyword = 0, identifier = 0, oper = 0, integer = 0, others = 0;

    // extracting words from the file
    out1 << "AFTER REMOVING THE WHITESPACES :  \n\n";
    while (in1 >> word)
    {
        //     // displaying content
        cout << word << " ";
        if (isValidKeyword(word))
            keyword++;
        else if (isValidIdentifier(word))
            identifier++;
        else if (isValidOperator(word))
            oper++;
        else if (isValidInteger(word))
            integer++;
        else
            others++;

        out1 << word;
    }
    out1 << "\n\nTOKEN ARE AS : \n";
    out1 << "1. KEYWORDS : " << keyword << "\n";
    out1 << "2. IDENTIFIERS : " << identifier << "\n";
    out1 << "3. OPERATOR : " << oper << "\n";
    out1 << "4. INTEGERS : " << integer << "\n";
    out1 << "5. OTHERS : " << others << "\n";

    in1.close();
    out1.close();

    return 0;
}