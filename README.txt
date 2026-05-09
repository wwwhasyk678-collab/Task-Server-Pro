Task Server Pro is an advanced task distribution platform built on a Client-Server
Architecture using the C programming language. The system acts as a high-performance
centralized server designed to handle concurrent requests from multiple geographically
distributed clients.
------------------------------------------------------------------------------------------
Technical Stack:
   Programming Language: Standard C for direct system resource access.  

   Network Protocol: TCP to ensure reliable, ordered, and error-free data transfer.  

   Concurrency: Multi-threading via the pthread.h library, allowing the server to serve multiple clients
                simultaneously without blocking.  

   Data Integrity: Implementation of Mutex Locks to prevent race conditions and ensure
                   thread safety during shared memory access.  

   Persistence: Instant archiving of tasks into text files (tasks.txt) to prevent data loss.  

   Operating System: Optimized for Linux (Ubuntu) for stable socket management.
-------------------------------------------------------------------------------------------
Application Protocol (Op-Codes)

The system utilizes a custom numerical coding system to reduce data size and improve response latency:  

Code	Action Type	Technical Description
101	Create Task	Request to add a new task to the central database.

202	List/Read Tasks	Synchronize and retrieve all current tasks from the server.

303	Update Task	Modify status or details of an existing task via its ID.

404	Delete Task	Permanently remove a task from the system records.

100	Response: OK	Server confirmation of a successful operation.

500	Response: Error	Indicates a failure (e.g., ID not found or concurrency error).
-------------------------------------------------------------------------------------------
How to Run

    1.Compile and Run the Server:
         gcc server.c -o server -lpthread
         ./server
    2.Compile and Run the Client:
         gcc client.c -o client
         ./client
-------------------------------------------------------------------------------------------
The Team

    Bushra Yacoub Dayoub   

    Hassan Akram Youssef   

    Maali Mohammad Mahrez

    Anaghaim Sultan Mohammed

Supervised by: Eng. Rama Al-Khair University: Latakia University - Faculty of Informatics Engineering