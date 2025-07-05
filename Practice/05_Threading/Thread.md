Common Issues & Solutions
=============================================================================
Deadlock -:
	Two or more threads/processes waiting for each other to release a lock.
Solution -:    Avoid circular waits, use timeouts, lock ordering, or try_lock.

Priority Inversion -:
     -	A low-priority thread holds a lock needed by a high-priority thread.
Solution -: Use priority inheritance mutexes.

Starvation -:A lower-priority thread never gets the lock because high-priority threads keep acquiring it.
Solution   -: Use fair locking policies.


Which One to Use in Embedded?
=============================================================================
RTOS (QNX, FreeRTOS, Linux RT) → Priority Inheritance Mutex
Critical Data (Counters, Flags) → Atomic Variables
Shared Resources (File, Sensor Access) → Mutex with Timeout
High-Performance Applications → Lock-Free Programming
Safety-Critical Systems → Watchdog Timer for Deadlocks
=============================================================================