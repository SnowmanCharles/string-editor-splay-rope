#ifndef SPLAY_STRING_EDITOR
#define SPLAY_STRING_EDITOR

#include "SplayRope.h"

class SplayStringEditor {
private:
    SplayRope rope;

public:
    SplayStringEditor();
    SplayStringEditor(const string& s);
    void insert(int index, const string& s);
    void remove(int startindex, int endindex);
    string substring(int startindex, int endindex);
    string tostring();
};

#endif