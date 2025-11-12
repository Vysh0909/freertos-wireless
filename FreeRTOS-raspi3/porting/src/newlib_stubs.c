#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h> // Required for printf
#include <stdint.h>
#include <stddef.h>

// Standard File Descriptors
#define STDIN_FILENO  0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

void panic(void)
{
        printf("An error occured! Aborting...\n");
        abort();
}
// Heap Management (used by malloc/free)
caddr_t _sbrk(int incr)
{
    panic();
}

// File I/O (used by printf/scanf)
int _write(int file, char *ptr, int len)
{
    panic();
}

int _read(int file, char *ptr, int len)
{
    panic();
}

int _close(int file)
{
    panic();
}

int _lseek(int file, int ptr, int dir)
{
    panic();
}

int _fstat(int file, struct stat *st)
{
    panic();
}

int _isatty(int file)
{
    panic();
}


// --- Process Control Stubs ---
void _exit(int status)
{
    panic();
}

int _kill(int pid, int sig)
{
    panic();
}

int _getpid(void)
{
    panic();
}
