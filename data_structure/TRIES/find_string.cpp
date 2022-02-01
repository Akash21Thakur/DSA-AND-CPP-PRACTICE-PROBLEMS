#include <iostream>
#include <unordered_map>
using namespace std;

class node
{
public:
    char data;
    unordered_map<char, node *> children;
    bool terminal;
    int flag = 0;

    node(char d)
    {
        data = d;
        terminal = false;
        flag = 1;
    }
};

class Trie
{
    node *root;
    int count;

public:
    Trie()
    {
        root = new node('\0');
        count = 0;
    }

    void insert(char *w)
    {
        node *temp = root;

        for (int i = 0; w[i] != '\0'; i++)
        {
            char ch = w[i];

            if (temp->children.count(ch))
            {
                temp->flag++;
                temp = temp->children[ch];
            }
            else
            {
                node *n = new node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }


        temp->terminal = true;
    }

    bool find(char *w)
    {
        node *temp = root;
        for (int i = 0; w[i] != '\0'; i++)
        {
            char ch = w[i];
            if (temp->children.count(ch) == 0)
                return false;
            else
            {
                temp = temp->children[ch];
            }
        }
        return temp->terminal;
    }

    string findUniquePrefix(char *w)
    {
        node *temp = root;
        int len = -1;
        int i = 0;
        for (; w[i] != '\0'; i++)
        {
            char ch = w[i];
            if (temp->flag == 1)
            {
                break;
            }
            temp = temp->children[ch];
        }
        if (w[i] == '\0')
            return "-1";
        else
        {
            string s;
            for (int j = 0; j <= i; j++)
                s.push_back(w[j]);
            return s;
        }
    }
};

int main()
{
    Trie t;
    char words[][10] = {"akash", "hello", "not", "news", "apple"};
    // char w[10];
    // cin>>w;

    for (int i = 0; i < 5; i++)
        t.insert(words[i]);

    //  if(t.find(w))
    //    cout<<"Present"<<endl;
    // else
    //    cout<<"Absent"<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout << words[i] << " => " << t.findUniquePrefix(words[i]) << endl;
    }
}
