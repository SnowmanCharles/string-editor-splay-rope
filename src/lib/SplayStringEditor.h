#ifndef SPLAY_STRING_EDITOR
#define SPLAY_STRING_EDITOR

#include "SplayRope.h"

/**
 * SplayStringEditor class
 * 1. provide fast APIs to creat and edit texts
 * 2. most operations run in O(log(N)) time complexity, which is much faster than std::string library
 * 
 * Methods:
 * 1. void insert(int index, const string& s):
 *         1.1  Insert string "s" into the current string at index "index" 
 *         1.2  Time Complexity: O(log(N) + T)
 * 2. void remove(int startindex, int endindex):
 *         1.1  Remove substring between index "startindex" and "endindex"
 *         1.2  Time Complexity: O(log(N) + T)
 * 3. string substring(int startindex, int endindex):
 *         1.1  return substring between index "startindex" and "endindex"
 *         1.2  Time Complexity: O(log(N) + T)
 * 4. string tostring():
 *         1.1  return the string representation of the content in this editor
 *         1.2  Time Complexity: O(N)
 **/ 
class SplayStringEditor {
private:
    SplayRope rope;

public:
    SplayStringEditor();
    SplayStringEditor(const string& s);
    void insert(int index, const string& s);//O(log(S) + T)   ,  std::string: O(S + T)
    void remove(int startindex, int endindex);//O(log(S) + T)   ,  std::string: O(S + T)
    string substring(int startindex, int endindex);//O(log(S) + T)   ,  std::string: O(T)
    string tostring();//O(S)
};

#endif