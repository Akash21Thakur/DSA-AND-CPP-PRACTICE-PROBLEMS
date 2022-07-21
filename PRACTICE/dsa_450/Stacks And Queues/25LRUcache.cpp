//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
public:
    //(key,{itr,val})-->map
    unordered_map<int, pair<list<int>::iterator, int>> mp;

    // dll of key...direct access first and last node...
    list<int> dll;

    int cap;
    LRUCache(int capacity)
    {
        this->cap = capacity;
    }

    // NOTE: erase takes O(n) not O(1)

    // move to first...when get or updation
    //  void moveToFirst(int key)
    //  {
    //      dll.erase(mp[key].first); //remove from current position
    //      dll.push_front(key);    //most recent use...so add at front
    //      mp[key].first=dll.begin();    //update the address...value remains unchanged
    //  }

    int get(int key)
    {
        auto itr = mp.find(key);
        if (itr == mp.end())
            return -1;

        // else found...so move to first and return the value
        // moveToFirst(key);
        // splice is used instead as does in O(1)
        dll.splice(dll.begin(), dll, mp[key].first);
        return mp[key].second;
    }

    void set(int key, int value)
    {
        auto itr = mp.find(key);
        if (itr != mp.end()) // found than update
        {
            mp[key].second = value;                      // update val
            dll.splice(dll.begin(), dll, mp[key].first); // most recently used
        }
        else // not found ...so new entry in the list and map too
        {
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            cap--; // decrease the capacity
        }

        if (cap < 0) // element==capacity
        {
            mp.erase(dll.back());

            dll.pop_back();
            cap++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends