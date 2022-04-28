#include <iomanip>
#include <sstream>
#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

struct FunctionObject
{
    unsigned operator()() const
    {
        return 42;
    }
};

struct HashFunction
{
    size_t operator()(const string &s) {
        size_t result = 0;
        for (auto c: s)
        {
            result += c;
        }
        
        return result;
    }
};


int main() {
    unordered_set<string> setOfWords;

    auto hf = setOfWords.hash_function();

    for (string line; getline(cin, line);) 
    {
        istringstream sinp(line);
        string cmd;
        sinp >> cmd;

        if(cmd == "#") {
            for(size_t i = 0; i < setOfWords.bucket_count(); ++i) {
                cout << setw(4) << i << ": " << endl;
            
                for (auto it = setOfWords.begin(i); it != setOfWords.end(i); ++i)
                {
                    cout << " " << *it << endl;
                }
                
            }
        }
        else if (cmd == "+")
        {
            string word;
            sinp >> word;

            cout << "hash_value: " << hf(word) << endl;
            cout << "index: " << hf(word) % setOfWords.bucket_count();
            setOfWords.insert(word);
        }
        else if (cmd == "-")
        {
            string word;
            sinp >> word;

            cout << "hash_value: " << hf(word) << endl;
            cout << "index: " << hf(word) % setOfWords.bucket_count();
            setOfWords.erase(word);
        } else if (cmd == "?")
        {
            string word;
            sinp >> word;

            cout << "hash_value: " << hf(word) << endl;
            cout << "index: " << hf(word) % setOfWords.bucket_count();
            cout << (setOfWords.find(word) == setOfWords.end() ? "YES" : "NO") << '\n';
        }   
    }
}