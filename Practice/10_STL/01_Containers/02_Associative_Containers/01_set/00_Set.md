
✅ std::set Key Properties
Stores unique elements.

Elements are always sorted in ascending order (by default using <).

Backed by Red-Black Tree (self-balancing BST).

Provides logarithmic time complexity for insert, delete, and search.


insert()	Insert element
emplace()	In-place insert
find()	Find element
count()	Check presence
erase()	Remove element
clear()	Remove all
size()	Size of set
empty()	Empty check
begin()/end()	Iterators
rbegin()/rend()	Reverse iterators
lower_bound()	First element ≥ val
upper_bound()	First element > val
equal_range()	Pair of bounds
swap()	Swap two sets

🧠 Breakdown of Features
Feature	            Code	            Explanation
===========================================================================
Insert	            s.insert(val)	    Inserts element if not already present. O(log n).
Find	            s.find(val)	        Returns iterator to element or s.end() if not found(log n).
Erase by value	    s.erase(val)	    Removes the element with given value. O(log n).
Size	            s.size()	        Returns number of elements. O(1).
Empty	            s.empty()	        Returns true if set is empty. O(1).
Clear	            s.clear()	        Removes all elements. O(n).
Lower Bound	        s.lower_bound(val)	Iterator to first element ≥ val. O(log n).
Upper Bound	        s.upper_bound(val)	Iterator to first element > val. O(log n).
Iteration	        for (auto x : s)	Iterates in sorted order. O(n).

⚠️ Important Notes
=================================================================================
std::set does not allow duplicates. Use std::multiset if duplicates are required.

It uses operator< internally for ordering. For custom types, you must define comparator.

Erasing an element using an iterator is safer in loops to avoid invalidation.