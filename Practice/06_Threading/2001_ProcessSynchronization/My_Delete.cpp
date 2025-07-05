/*
 *
 1. Using Mutex with pthread (POSIX)
If the processes share memory (e.g., using shared memory), you can use POSIX mutexes.
 *
 * */
#include <iostream>
#include <pthread.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

#define SHARED_MEM_NAME "/sync_mutex"

int main() {
    int fd = shm_open(SHARED_MEM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, sizeof(pthread_mutex_t));
    
    void* ptr = mmap(0, sizeof(pthread_mutex_t), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    pthread_mutex_t* mutex = static_cast<pthread_mutex_t*>(ptr);

    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(mutex, &attr);

    std::cout << "Waiting for lock...\n";
    pthread_mutex_lock(mutex);
    std::cout << "Critical section\n";
    sleep(3);
    pthread_mutex_unlock(mutex);

    pthread_mutex_destroy(mutex);
    shm_unlink(SHARED_MEM_NAME);
}
/*
One process locks the mutex, and the other waits.

The shm_open function is used to share the mutex across processes.
 *
 Explanation:
 	shm_open and shm_unlink require -lrt
	These functions are part of the POSIX real-time extensions and are provided by the librt library.

	pthread_mutexattr_init and pthread_mutexattr_setpshared require -pthread
	These functions are part of the POSIX thread (pthread) library.
 *
 *
 * */

