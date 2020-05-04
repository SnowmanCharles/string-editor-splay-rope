#include "SplayStringEditor.h"

using namespace std;

/**
 * constructor without parameter
 **/ 
SplayStringEditor::SplayStringEditor() {}

/**
 * constructor with parameter string "s"
 **/ 
SplayStringEditor::SplayStringEditor(const string& s) {
    SplayRope newRope(s);   
    rope = newRope; 
}

/**
 * Insert string "s" into the current string at index "index" 
 * Time Complexity: O(log(N) + T)
 **/ 
void SplayStringEditor::insert(int index, const string& s) {
    SplayRope newRope(s);                                   
    rope.insert(rope.getRoot(), index, newRope.getRoot());
}

/**
 * Remove substring between index "startindex" and "endindex"
 * Time Complexity: O(log(N) + T)
 **/ 
void SplayStringEditor::remove(int startindex, int endindex) {
    rope.remove(rope.getRoot(), startindex, endindex);        
}

/**
 * return substring between index "startindex" and "endindex"
 * Time Complexity: O(log(N) + T)
 **/ 
string SplayStringEditor::substring(int startindex, int endindex) {
    return rope.substring(rope.getRoot(), startindex, endindex);   
}

/**
 * return the string representation of the content in this editor
 * Time Complexity: O(N)
 **/ 
string SplayStringEditor::tostring() {
    return rope.toString();           
}


