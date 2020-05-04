#include "SplayStringEditor.h"

using namespace std;

SplayStringEditor::SplayStringEditor() {}

SplayStringEditor::SplayStringEditor(const string& s) {
    SplayRope newRope(s);   
    rope = newRope; 
}

void SplayStringEditor::insert(int index, const string& s) {//O(log(S) + T)   S:length of original string,   T:length of the inserted string
    SplayRope newRope(s);                                   //std::string: O(S + T)
    rope.insert(rope.getRoot(), index, newRope.getRoot());
}

void SplayStringEditor::remove(int startindex, int endindex) {//O(log(S) + T)    S:length of original string    T = endindex - startindex + 1
    rope.remove(rope.getRoot(), startindex, endindex);        //std::string: O(S + T)
}

string SplayStringEditor::substring(int startindex, int endindex) {//O(log(S) + T)    S:length of original string    T = endindex - startindex + 1
    return rope.substring(rope.getRoot(), startindex, endindex);   //std::string: O(T)
}

string SplayStringEditor::tostring() {//O(S)
    return rope.toString();           //std::string: O(S)
}


