✅ What is std::multimap?
Associative container that stores key–value pairs.

Keys are sorted automatically (by default in ascending order).

Allows duplicate keys, unlike std::map.

Backed by a Red-Black Tree → O(log n) insert/find/erase.


🧠 Functions Explained
=============================================================
Function	      Usage       	            Description
-------------------------------------------------------------
insert({k, v})	  mm.insert({1, "Apple"});	Inserts a pair. Allows duplicates.
count(k)	      mm.count(2)	            Returns number of entries with key k.
find(k)	          mm.find(2)	            Returns iterator to first occurrence of key.
equal_range(k)	  mm.equal_range(2)	        Returns pair<iterator, iterator> spanning all values with key.
erase(k)	      mm.erase(1)	            Erases all entries with key k.
erase(it)	      mm.erase(mm.find(2))	    Erases a single instance by iterator.
size()	          mm.size()	                Returns number of total entries.
empty()	          mm.empty()	            True if empty.
clear()	          mm.clear()	            Removes all entries.


✅ When to Use multimap
==============================================================
Scenario	                                        Reason
--------------------------------------------------------------
You want to store multiple values per key	        Unlike map, allows duplicates
You need sorted keys	                            Keeps keys ordered
You care about order and grouping	                Useful in grouped data (like SQL GROUP BY)
You need log-time insert/lookup	Based on Red-Black  Tree


❓ Common Interview Tip
======================================
Avoid using mm[key] = val in multimap. Unlike map, it doesn’t support operator[] because duplicate keys would make it ambiguous.