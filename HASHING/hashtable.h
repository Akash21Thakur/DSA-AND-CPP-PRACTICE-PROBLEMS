#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class node
{
public:
    string key;
    T val;
    node<T> *next;

    node(string s, T value)
    {
        this->key = s;
        this->val = value;
        next = NULL;
    }

    ~node()
    {
        if (next != NULL)
            delete next;
    }
};

template <typename T>
class HashTable
{
    node<T> **table;
    int current_size;
    int table_size;

    int hashmap(string key)
    {
        int idx = 0;
        int p = 1;

        for (int j = 0; j < key.length(); j++)
        {
            idx = idx + (key[j] * p) % table_size;
            idx = idx % table_size;
            p = (p * 27) % table_size;
        }
        return idx;
    }

    void rehash()
    {
        node<T> **oldTable = table;
        int oldTableSize = table_size;
        table_size = 2 * table_size;

        table = new node<T> *[table_size];

        for (int i = 0; i < table_size; i++)
            table[i] = NULL;

        current_size = 0;

        // assigning new indices to all the key
        for (int i = 0; i < oldTableSize; i++)
        {
            node<T> *temp = oldTable[i];
            while (temp != NULL)
            {
                insert(temp->key, temp->val);
                temp = temp->next;
            }
            if (oldTable[i] != NULL)
            {
                delete oldTable[i];
            }
        }
        delete[] oldTable;
    }

public:
    HashTable(int ts = 7)
    {
        table_size = ts;
        current_size = 0;
        table = new node<T> *[table_size];
        for (int i = 0; i < table_size; i++)
            table[i] = NULL;
    }

    T& operator[](string s)
    {
        T *f = search(s);
        if (f == NULL)
        {
            T garbage;
            insert(s, garbage);
            f = search(s);
        }
        return *f;
    }

    void insert(string key, T value)
    {
        int idx = hashmap(key);
        node<T> *n = new node<T>(key, value);

        n->next = table[idx]; // inserts always at the head
        table[idx] = n;       //,,,,,,,,,,,,
        current_size++;

        // rehash...
        float load_factor = (current_size * 1.0) / table_size;
        if (load_factor > 0.7)
            rehash();
    }

    void print()
    {
        for (int i = 0; i < table_size; i++)
        {
            cout << "Bucket " << i << " -> ";
            node<T> *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->key << " - "; //<<temp->val;
                temp = temp->next;
            }
            cout << endl;
        }
    }

    T *search(string s)
    {
        int idx = hashmap(s);
        node<T> *temp = table[idx];
        while (temp != NULL)
        {
            if (temp->key == s)
                
            return &temp->val;

            temp = temp->next;
        }
        return NULL;
    }

    void erase(string s)
    {
        int idx = hashmap(s);
        node<T> *temp = table[idx];
        if (temp->key == s)
        {
            table[idx] = temp->next;
            temp->next=NULL;
            delete temp;
            return;
        }
        node<T> *prev = temp;
        temp=temp->next;
        while (temp != NULL)
        {
            if (temp->key == s)
            {
                prev->next = temp->next;
                temp->next=NULL;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }
};
