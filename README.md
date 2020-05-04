# string-editor-splay-rope
A string editor based on splay tree and rope

OverView
1. This project implements a SplayStringEditor which allows very fast text creating and very fast text editing
2. Provides very fast string editing operations. Provides O(log(S) + T) inserting, removing, and substring operations, where S is the original string length, T is the inserting or removing string length. 
3. Have very excellent performance compared with std::string when dealing with large strings, which is a normal case in text editing. 

Implementation
1. Use Object Oriented design
2. Implementation based on Splay Tree and Rope data structure
3. Splay Tree: An execelent balanced tree data structure (key operations: rotating and splay)
4. Rope: Tree shape data structure storing string content
5. Complete unit test on SplayStringEditor

User guide
1. Run main.cc to see detailed comparison with the operations of std::string when operating on small size strings, median size strings, and large size strings.
2. Users can use the SplayRope class to implement more operation in this SplayStringEditor

Links
[1. DemoVedio](https://drive.google.com/open?id=1_2dbQ1lbmMQBpxbphpiCMT_cMbfsLvzh)
[2. GitHub Link](https://github.com/SnowmanCharles/string-editor-splay-rope.git)

Possible future work
1. Optimize the performance of this SplayRope data structure on small size and median size strings
2. Implement more operations in SplayStringEditor based on SplayRope
3. Implement UI
4. Make it a web based application