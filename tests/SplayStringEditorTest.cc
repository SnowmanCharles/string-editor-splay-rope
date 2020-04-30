#include "gtest/gtest.h"
#include "src/lib/SplayStringEditor.h"

//******************************************Test insert Operation***************************************************
TEST(InsertWithShortString, InsertWithShortString) {
    string s, add;
    for (int i = 0; i < 10; i++) {
        s += "abc";
        add += "123";
    }
    SplayStringEditor editor(s);
    editor.insert(16, add);
    s.insert(15, add);
    EXPECT_EQ(editor.tostring(), s);
}

TEST(InsertWithMedianString, InsertWithMedianString) {
    string s, add;
    for (int i = 0; i < 1000; i++) {
        s += "abc";
        add += "123";
    }
    SplayStringEditor editor(s);
    editor.insert(1136, add);
    s.insert(1135, add);
    EXPECT_EQ(editor.tostring(), s);
}

TEST(InsertWithLongString, InsertWithLongString) {
    string s, add;
    for (int i = 0; i < 100000; i++) {
        s += "abc";
        add += "123";
    }
    SplayStringEditor editor(s);
    editor.insert(112416, add);
    s.insert(112415, add);
    EXPECT_EQ(editor.tostring(), s);
}


//******************************************Test remove Operation***************************************************
TEST(RemoveWithShortString, RemoveWithShortString) {
    string s;
    for (int i = 0; i < 10; i++) {
        s += "abc";
    }
    SplayStringEditor editor(s);
    int start = 10, len = 10;
    editor.remove(start, start + len - 1);
    s.erase(start, len);
    EXPECT_EQ(editor.tostring(), s);
}

TEST(RemoveWithMedianString, RemoveWithMedianString) {
    string s;
    for (int i = 0; i < 1000; i++) {
        s += "abc";
    }
    SplayStringEditor editor(s);
    int start = 1000, len = 1000;
    editor.remove(start, start + len - 1);
    s.erase(start, len);
    EXPECT_EQ(editor.tostring(), s);
}

TEST(RemoveWithLongString, RemoveWithLongString) {
    string s;
    for (int i = 0; i < 100000; i++) {
        s += "abc";
    }
    SplayStringEditor editor(s);
    int start = 100000, len = 100000;
    editor.remove(start, start + len - 1);
    s.erase(start, len);
    EXPECT_EQ(editor.tostring(), s);
}

// //******************************************Test substing Operation***************************************************
TEST(SubstingWithShortString, SubstingWithShortString) {
    string s;
    for (int i = 0; i < 10; i++) {
        s += "abc";
    }
    SplayStringEditor editor(s);
    int start = 10, len = 10;
    string actual = editor.substring(start, start + len - 1);
    string expected = s.substr(start, len);
    EXPECT_EQ(editor.tostring(), s);
}

TEST(SubstingWithMedianString, SubstingWithMedianString) {
    string s;
    for (int i = 0; i < 1000; i++) {
        s += "abc";
    }
    SplayStringEditor editor(s);
    int start = 1000, len = 1000;
    string actual = editor.substring(start, start + len - 1);
    string expected = s.substr(start, len);
    EXPECT_EQ(editor.tostring(), s);
}

TEST(SubstingWithLongString, SubstingWithLongString) {
    string s;
    for (int i = 0; i < 100000; i++) {
        s += "abc";
    }
    SplayStringEditor editor(s);
    int start = 100000, len = 100000;
    string actual = editor.substring(start, start + len - 1);
    string expected = s.substr(start, len);
    EXPECT_EQ(editor.tostring(), s);
}


// //******************************************Test tostring Operation***************************************************
TEST(TostringWithShortString, TostringWithShortString) {
    string s;
    for (int i = 0; i < 10; i++) {
        s += "abc";
    }
    SplayStringEditor editor(s);
    EXPECT_EQ(editor.tostring(), s);
}

TEST(TostringWithMedianString, TostringWithMedianString) {
    string s;
    for (int i = 0; i < 1000; i++) {
        s += "abc";
    }
    SplayStringEditor editor(s);
    EXPECT_EQ(editor.tostring(), s);
}

TEST(TostringWithLongString, TostringWithLongString) {
    string s;
    for (int i = 0; i < 100000; i++) {
        s += "abc";
    }
    SplayStringEditor editor(s);
    EXPECT_EQ(editor.tostring(), s);
}