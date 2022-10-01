#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <sstream>
using std::istringstream;
using std::ostringstream;

#include <map>
using std::map;
using std::multimap;
#include <set>
using std::set;

#include <unordered_map>
using std::unordered_map;
using std::unordered_multimap;

void mapL1(istringstream &iss)
{
    string word;
    map<string, int> words_count;
    set<string> words_set = {
        "the", "and", "a", "about", "to"};

    while (iss >> word)
    {
        if (words_set.find(word) == words_set.end() && word != "–")
            ++words_count[word];
    }
    for (const auto &word : words_count)
    {
        cout << word.first << " : " << word.second << endl;
    }
}


void test()
{
    string testStr = "Today’s post is about the language we use to talk about being creative. Creativity – being able to think of new and unusual ideas – is central to human life, and there are lots of great words to describe it.";
    istringstream iss(testStr);
    mapL1(iss);
}
