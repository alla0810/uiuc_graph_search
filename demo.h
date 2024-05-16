===========================================================================
                                  Welcome                                  
===========================================================================

Make sure to inspect informalTests() in main.cpp to turn on the available
informal tests. The terminal output for each test is lengthy, so you may
want to only activate one test at a time.

If the diagram plots in the terminal cause problems with screen readers,
then please adjust the verbosity settings in the informalTests function.

Remember that the informal tests are to help you debug with detailed text
output. They are not the same tests used to grade your code. You can also
run unit tests on your code that are more similar to our autograder.
Those are defined in the file(s) in the tests/ subdirectory. Since those
other unit tests are separate from the main program, you must compile and
run them separately by using this command in the terminal:

  make clean && make test && ./test

===========================================================================
                               Demonstrations                               
===========================================================================

========================= Using std::unordered_set =========================

In this project, we use std::unordered_set in several places to represent
collections of items having some shared property. A set contains value copies
of objects, and it contains no duplicates; inserting the same item twice has
no effect. In C++, the unordered set type uses hashing internally, so the
key type must support equality comparison and std::hash. Unlike the unordered
map type, the keys for an unordered set do not have associated values. We only
care whether a given key has been inserted or not.

This is an alternative to "labeling" vertices with some status, for example.
If an algorithm tells you to label vertices as "visited", you could instead
make a set for all the visited vertices, and insert copies of vertices to the
visited set when you want to record that they have been visited.

For example, we could make a set to contain unique integers like this:

  std::unordered_set<int> favoriteNumbers;

Then we can insert some items with insert():

Inserting 7.
size() is now: 1
Inserting 42.
size() is now: 2
Inserting 42 again. (This doesn't change anything.)
size() is now: 2
At this point, the set contains 7 and 42. (It only has a single copy of 42.)

Iterating over std::unordered_set contents. (These may not be in any order.)
 Set contains: 42
 Set contains: 7

And then we can use count() to query if an item is in the set or not, and we
can remove items from the set with erase(). Remeber that since a set contains
unique items, we only ever expect a count of 1 or 0.

Counting the key 7 (expecting 1): 1
Erasing 7.
Counting the key 7 (expecting 0): 0

============= Undirected edge representation with IntPairPair =============

Our GridGraph class doesn't explicitly store edges since it uses an adjacency
list scheme (actually, an adjacency map and set scheme in our implementation).
However, sometimes we may want to examine the undirected edges of the graph
as explcit items. For example, GridGraph::printDetails makes a set of unique
edges in order to display terminal output.

This is where we have to be careful, because IntPairPair is just a pair of
pairs, so it doesn't guarantee the (A,B)==(B,A) equality that we would expect
for an undrected edge representation.

Creating some points using IntPair:
pointA:  (2,3) 
pointB:  (1,3) 

Creating IntPairPair AB from {pointA, pointB} and BA from {pointB, pointA}.
Now is (AB == BA)? false
Hashing AB: 9445207459810090351
Hashing BA: 10204181085685683894

If you wanted to extend the code further, you could make a derived class
based on IntPairPair that would ensure that edges (A,B) and (B,A) would
automatically be tested equal and identically hashed. For this
assignment, the provided code does that manually in a few places,
such as in GridGraph::printDetails.

==================== Various ways to initialize objects ====================

As you examine the provided code, you may see objects being initialized in
various ways. Remember that in C++11 and newer, there are compiler features
that can infer (detect) the correct STL types automatically, which can help
you write neater code.

Our IntPair type is based on std::pair<int,int>. The lines below all construct
the same IntPair. The last one uses an "initializer list" in braces {}, which
can be used wherever the type can be understood correctly by the compiler.

  IntPair point1 = IntPair(1,2);
  IntPair point2 = std::make_pair(1,2);
  auto point3 = IntPair(1,2);
  IntPair point4 = {1,2};

Displaying print output for all four objects:
 (1,2)  (1,2)  (1,2)  (1,2) 

Verifying equality:
  point1 == point2 : true
  point2 == point3 : true
  point3 == point4 : true

However, if you're not explicit enough, the compilation may fail.
The compiler needs to be able to tell if you mean IntPair, std::vector,
or something else, based on the structure of the variable and how you use it.
The following may or may not work, depending on the context of your code:

  auto point5 = {1,2}; // Probably too vague

================= Skipping informal tests for Exercise 1. =================

================= Skipping informal tests for Exercise 2. =================

================= Skipping informal tests for Exercise 3. =================


Informal tests finished without crashing, but the output may have been incorrect.
Please scroll to the top of the output to read the diagnostics.
If any tests were disabled, you can enable them in the informalTests
function in main.cpp.
