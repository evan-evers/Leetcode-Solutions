//Original problem: https://leetcode.com/problems/isomorphic-strings/

#include <iostream>
#include <utility>
#include <unordered_map>
#include <string>
using namespace std;

bool isIsomorphic(string s, string t) {
    unordered_map<char,int> s_map, t_map; //stores the unique characters that are in each string
    for (int i = 0; i < s.length(); i++)    //since s.length() = t.length(), we don't need to worry about checking for different sizes
    {
        //look for the current character in s_map
        if (s_map.find(s[i]) == s_map.end()) 
        {   //if we didn't find the current character in the map, put it in the map as a key with a numerical value to identify it for comparisons
            s_map.insert(pair<char,int>(s[i],s_map.size()));
        }
        //look for the current character in t_map
        if (t_map.find(t[i]) == t_map.end())
        {   //if we didn't find the current character in the map, put it in the map as a key with a numerical value to identify it for comparisons
            t_map.insert(pair<char, int>(t[i], t_map.size()));
        }

        //if the identified character has a different number, the strings have a variance in their order of characters and aren't isomorphic
        if (s_map[s[i]] != t_map[t[i]])
            return false;
    }

    return true;    //return true if the whole thing's been gone through without incident
}
