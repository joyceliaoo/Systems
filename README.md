# System Level Programming
Main repo for MKS65 Fall 2018 course assignments
## Projects
### 00 - MUSIC LIBRARY
* Add a song
* Retrieve all songs by an artist
* Search for a(n) song/artist
* Print all artists whose name start with a specific letter along with their songs
* Print entire library
* Delete a song from the library
* Clear entire library
### 01 - SHELL
* Parse input that contains multi-argument commands separated by `;`
  * Account for irregular spacing in the form of spaces, tabs, or new lines
  * Execute basic bash commands such as `ls` and `tr`
* Change current working directory of program
* Single / Double redirects with `<`,`<<`,`>`
* Single pipe
* Exit program
## Homework
### 01 - PROJECT EULER
* Solutions to problems 1, 2 and 6 written in C
### 02 - PRINT INT
* Use a char pointer to print/modify each byte of an unsigned int
### 03 - POINTER and RANDOM NUM
* Generate a random number using `srand()` in combination with `time()`
* Manipulate pointers to copy data from one array to another
### 05 - STRING FUNCTIONS
* Rewrite some of the basic C string functions
### 06 - STRUCT
* Modify/print data stored in a struct
### 07 - LINKED LIST
* Create a linked list using structs
  * Insert at the front of a linked list
  * Free all elements in a linked list
### 08 - SIEVE OF ERATOSTHENES
* Find the nth prime using the sieve of Eratosthenes algorithm
### 09 - FILE FUNCTIONS
* Open, write, read, close a file in C
### 10 - FILE and RANDOM NUM
* Generate an array of random numbers by reading from dev/ran
* Writes content of an array to a file
* Read content of a file into an array
### 11 - STAT
* Use `stat()` to get the metadata of a file
* Print out the size of a file in G, KB, MB, and GB as appropriate
* Print out the permission of a file in `ls -l` form
### 12 - SCANNING DIRECTORIES
* List all files in a directory by taking user input
* Separately list directories and files in a given directory
* Recursively list the files in subdirectories
* Handle invalid input using `errno`
### 13 - SIGNAL HANDLING
* Print `pid`
* `Sleep()`
* Handle `SIGINT` (`ctrl`+`c`) and `SIGUSR1` (`kill -10`)
### 14 - PARSING STRING
* Parse a string into an array by a given delimiter
* Use `execvp` to execute the given array of args
### 15 - FORK
* Fork two child processes
* Have parent process wait for child to finish and get its return value
### 16 - SHARED MEMORY SEGMENTS
* Generate a unique key using `ftok()`
* Create new shared memory segment
  * Get id to memory segment of specified size
  * Get pointer to memory segment given id
* Write to shared memory segment
* Discard memory segment
  * Detach process from segment when done
  * Delete shared segment from heap
### 17 - SEMAPHORES
* Control file
 * Create/remove semaphores, shared memory segments
 * Open a file in truncate mode
 * View contents of a file line by line
* Write file
 * Use semaphore to let user write to a file
 * Use a shared memory segment to store last line written to file
### 18 - NETWORK HANDSHAKE
* 3 way handshake between server and client
### 19 - NETWORK PART II
* Client sends message to server and receives a response
* Server receives client message and sends back metadata
* Process continues until client exits
    * Server then closes both pipes
    * Server Resets
* Server removes wkp upon receiving SIGINT
### 20 - FORKING SUBSERVERS
* Main server forks off a subserver for each connection
