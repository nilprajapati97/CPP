->  std::unique_lock (More Flexible Locking)
=============================================================
    std::unique_lock<std::mutex> is a more advanced and flexible locking mechanism compared to std::lock_guard.
    It allows manual unlocking, try-locking, and timed-locking.

Pros of std::unique_lock
--------------------------------------------------------------------------------------------------------------------
-> 1. Manual Locking and Unlocking
    You can lock and unlock the mutex multiple times within the same scope.

-> 2.Try-Lock Support
    Allows non-blocking attempts to lock the mutex (try_lock()).

-> 3.Timed Locking
    Can wait for a specific duration before giving up on locking (try_lock_for() or try_lock_until()).

-> 4.Deferred Locking
    Allows you to create a std::unique_lock object without immediately locking the mutex (std::defer_lock).

-> 5.Exception Safety
    Like std::lock_guard, std::unique_lock ensures the mutex is released when the lock object goes out of scope.

Cons of std::unique_lock
---------------------------------------------------------------------------------------------------------------------
-> 1. Slightly More Overhead
    Because of its flexibility, std::unique_lock has slightly more overhead than std::lock_guard.

-> 2. Potential Misuse
    If used incorrectly, manual unlocking can lead to deadlocks or undefined behavior.

->3. Not as Lightweight as std::lock_guard
    If you just need a simple lock, std::lock_guard is a better choice.



When and Where to Use std::unique_lock
============================================================================================================================

✅ Best Use Cases
->1. When you need to unlock and relock a mutex manually
    Example: A function that needs to temporarily release the lock while doing some expensive operation.

->2. When you need try-locking
    Example: If you want to check if a resource is available without blocking.

->3. When you need timed-locking
    Example: If you want to wait for a mutex to be unlocked but give up after a certain time.

->4. When dealing with multiple mutexes
    Example: std::unique_lock can be used with std::lock to avoid deadlocks when locking multiple mutexes.









Comparison: std::lock_guard vs. std::unique_lock
-------------------------------------------------------------------
Feature	                std::lock_guard	            std::unique_lock
-------------------------------------------------------------------
Automatic Unlocking	    ✅ Yes                  	    ✅ Yes
Manual Unlocking	    ❌ No	                    ✅ Yes
Try-Lock Support	    ❌ No	                    ✅ Yes (try_lock())
Timed-Lock Support	    ❌ No	                    ✅ Yes (try_lock_for())
Deferred Locking	    ❌ No	                    ✅ Yes (std::defer_lock)
Performance	            ✅ Faster	                ⚠️ Slight Overhead

Conclusion
✅ Use std::lock_guard when you need a simple, lightweight lock without manual unlocking.
✅ Use std::unique_lock when you need more flexibility, such as manual unlocking, try-locking, or timed-locking.