#include <iostream>
#include "src/lib/SplayStringEditor.h"

int main() {
    cout << endl << endl << "******************************************************  Splay_String_Editor  VS  Std::String_Library  ********************************************************" << endl;
    //****************Testing with short strings********************************************************************************
    string s("12345");
    string add("12345");
    SplayStringEditor editor(s);
    cout << endl << endl << "****************Testing with short strings********************************************************************************" << endl;
    //testing insert
    cout << "*****Testing Insert*****" << endl;
    auto start = high_resolution_clock::now();
    for (int i = 1; i < 1000; i++) {
        editor.insert(i, add);
    }
    for (int i = 1; i < 1000; i++) {
        editor.insert(1000 - i, add);
    }
    auto end = high_resolution_clock::now();
    auto editor_short_insert = duration_cast<microseconds>(end - start); 
    cout << "Editor insert with short strings. Time cost: " << editor_short_insert.count() << endl;

    start = high_resolution_clock::now();
    for (int i = 1; i < 1000; i++) {
        s.insert(i - 1, add);
    }
    for (int i = 1; i < 1000; i++) {
        s.insert(1000 - i - 1, add);
    }
    end = high_resolution_clock::now();
    auto string_short_insert = duration_cast<microseconds>(end - start); 
    cout << "String insert with short strings. Time cost: " << string_short_insert.count() << endl;
    cout << "Is the insert result same?: " << (s == editor.tostring() ? "True" : "False") << endl;

    //testing remove
    cout << "*****Testing Remove*****" << endl;
    start = high_resolution_clock::now();
    for (int i = 1; i < 1000; i++) {
        editor.remove(i, i + 4);
    }
    end = high_resolution_clock::now();
    editor_short_insert = duration_cast<microseconds>(end - start); 
    cout << "Editor remove with short strings. Time cost: " << editor_short_insert.count() << endl;

    start = high_resolution_clock::now();
    for (int i = 1; i < 1000; i++) {
        s.erase(i, 5);
    }
    end = high_resolution_clock::now();
    string_short_insert = duration_cast<microseconds>(end - start); 
    cout << "String remove with short strings. Time cost: " << string_short_insert.count() << endl;
    cout << "Is the remove result same?: " << (s == editor.tostring() ? "True" : "False") << endl;

    //testing substring
    cout << "*****Testing substring*****" << endl;
    start = high_resolution_clock::now();
    for (int i = 1; i < 1000; i++) {
        editor.substring(0, 4);
    }
    end = high_resolution_clock::now();
    editor_short_insert = duration_cast<microseconds>(end - start); 
    cout << "Editor substring with short strings. Time cost: " << editor_short_insert.count() << endl;

    start = high_resolution_clock::now();
    for (int i = 1; i < 1000; i++) {
        s.substr(0, 5);
    }
    end = high_resolution_clock::now();
    string_short_insert = duration_cast<microseconds>(end - start); 
    cout << "String substring with short strings. Time cost: " << string_short_insert.count() << endl;
    cout << "Is the substring result same?: " << (s.substr(0, 5) == editor.substring(0, 4) ? "True" : "False") << endl;


    //****************Testing with median strings********************************************************************************
    cout << endl << endl << "****************Testing with median strings********************************************************************************" << endl;
    //testing insert
    cout << "*****Testing Insert*****" << endl;
    for (int i = 0; i < 7000; i++) {
        s += add;
    }
    SplayStringEditor editor1(s);
    editor = editor1;

    start = high_resolution_clock::now();
    for (int i = 1; i < 1000; i++) {
        editor.insert(i, add);
    }
    for (int i = 1; i < 1000; i++) {
        editor.insert(1000 - i, add);
    }
    end = high_resolution_clock::now();
    editor_short_insert = duration_cast<microseconds>(end - start); 
    cout << "Editor insert with median strings. Time cost: " << editor_short_insert.count() << endl;

    start = high_resolution_clock::now();
    for (int i = 1; i < 1000; i++) {
        s.insert(i - 1, add);
    }
    for (int i = 1; i < 1000; i++) {
        s.insert(1000 - i - 1, add);
    }
    end = high_resolution_clock::now();
    string_short_insert = duration_cast<microseconds>(end - start); 
    cout << "String insert with median strings. Time cost: " << string_short_insert.count() << endl;
    cout << "Is the insert result same?: " << (s == editor.tostring() ? "True" : "False") << endl;

   //testing remove
    cout << "*****Testing Remove*****" << endl;
    start = high_resolution_clock::now();
    for (int i = 1; i < 1000; i++) {
        editor.remove(i, i + 4);
    }
    end = high_resolution_clock::now();
    editor_short_insert = duration_cast<microseconds>(end - start); 
    cout << "Editor remove with median strings. Time cost: " << editor_short_insert.count() << endl;

    start = high_resolution_clock::now();
    for (int i = 1; i < 1000; i++) {
        s.erase(i, 5);
    }
    end = high_resolution_clock::now();
    string_short_insert = duration_cast<microseconds>(end - start); 
    cout << "String remove with median strings. Time cost: " << string_short_insert.count() << endl;
    cout << "Is the remove result same?: " << (s == editor.tostring() ? "True" : "False") << endl;

    //testing substring
    cout << "*****Testing substring*****" << endl;
    start = high_resolution_clock::now();
    for (int i = 1; i < 1000; i++) {
        editor.substring(0, 4);
    }
    end = high_resolution_clock::now();
    editor_short_insert = duration_cast<microseconds>(end - start); 
    cout << "Editor substring with median strings. Time cost: " << editor_short_insert.count() << endl;

    start = high_resolution_clock::now();
    for (int i = 1; i < 1000; i++) {
        s.substr(0, 5);
    }
    end = high_resolution_clock::now();
    string_short_insert = duration_cast<microseconds>(end - start); 
    cout << "String substring with median strings. Time cost: " << string_short_insert.count() << endl;
    cout << "Is the substring result same?: " << (s.substr(0, 5) == editor.substring(0, 4) ? "True" : "False") << endl;


    //****************Testing with long strings********************************************************************************
    cout << endl << endl << "****************Testing with long strings********************************************************************************" << endl;
    //testing insert
    cout << "*****Testing insert*****" << endl;
    for (int i = 0; i < 10000000; i++) {
        s += add;
    }
    SplayStringEditor editor2(s);
    editor = editor2;
    start = high_resolution_clock::now();
    for (int i = 1; i < 1000; i++) {
        editor.insert(i, add);
    }
    for (int i = 1; i < 1000; i++) {
        editor.insert(1000 - i, add);
    }
    end = high_resolution_clock::now();
    editor_short_insert = duration_cast<microseconds>(end - start); 
    cout << "Editor insert with large strings. Time cost: " << editor_short_insert.count() << endl;

    start = high_resolution_clock::now();
    for (int i = 1; i < 1000; i++) {
        s.insert(i - 1, add);
    }
    for (int i = 1; i < 1000; i++) {
        s.insert(1000 - i - 1, add);
    }
    end = high_resolution_clock::now();
    string_short_insert = duration_cast<microseconds>(end - start); 
    cout << "String insert with large strings. Time cost: " << string_short_insert.count() << endl;
    cout << "Is the insert result same?: " << (s == editor.tostring() ? "True" : "False") << endl;

    //testing remove
    cout << "*****Testing Remove*****" << endl;
    start = high_resolution_clock::now();
    for (int i = 1; i < 1000; i++) {
        editor.remove(i, i + 4);
    }
    end = high_resolution_clock::now();
    editor_short_insert = duration_cast<microseconds>(end - start); 
    cout << "Editor remove with long strings. Time cost: " << editor_short_insert.count() << endl;

    start = high_resolution_clock::now();
    for (int i = 1; i < 1000; i++) {
        s.erase(i, 5);
    }
    end = high_resolution_clock::now();
    string_short_insert = duration_cast<microseconds>(end - start); 
    cout << "String remove with long strings. Time cost: " << string_short_insert.count() << endl;
    cout << "Is the remove result same?: " << (s == editor.tostring() ? "True" : "False") << endl;

    //testing substring
    cout << "*****Testing substring*****" << endl;
    start = high_resolution_clock::now();
    for (int i = 1; i < 1000; i++) {
        editor.substring(0, 4);
    }
    end = high_resolution_clock::now();
    editor_short_insert = duration_cast<microseconds>(end - start); 
    cout << "Editor substring with long strings. Time cost: " << editor_short_insert.count() << endl;

    start = high_resolution_clock::now();
    for (int i = 1; i < 1000; i++) {
        s.substr(0, 5);
    }
    end = high_resolution_clock::now();
    string_short_insert = duration_cast<microseconds>(end - start); 
    cout << "String substring with long strings. Time cost: " << string_short_insert.count() << endl;
    cout << "Is the substring result same?: " << (s.substr(0, 5) == editor.substring(0, 4) ? "True" : "False") << endl;

    return EXIT_SUCCESS;
}