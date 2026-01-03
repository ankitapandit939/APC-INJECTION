APC INJECTION 

  A process of attaching a malicious code to the APC queue or APC Injection is a process injection technique that abuses Windows’ Asynchronous Procedure Call 
mechanism to execute injected code(i.e malicious code) inside an existing thread without creating a new one.

But before we talk about What is APC or how APC Injection is done there are some concepts we need to know 


TABLE OF CONTENTS:
  -PROCESS
  
  -THREAD                                         
  
  -VIRTUAL MEMORY
  
  -MEMORY PERMISSION
  
  -SHELL CODE
  
  -WINDOWS API
  
  -HANDLE
  
  -WHAT IS APC
  
  -APC QUEUE
  
  -ALERTABLE STATE

So now WHAT IS A PROCESS IN A COMPUTER?
- A PROCESS is basically a type of conatiner that helps the commands to get executed inside it when they are assigned with the help of THREAD.

that takes us to our next basic unit THREAD

A THREAD is a fundamental unit of a PROCESS , it is the Thread that performs the execution of a assigned task or command in the Computer 

For more simple breakdown we can refer to the figure below:


<img width="1120" height="561" alt="image" src="https://github.com/user-attachments/assets/e9ba385f-3037-4795-9238-57d7cd6c1cc4" />

When APC Injection is done it needs a VIRTUAL MEMORY but What is a Virtual Memory?

Virtual memory is a technique used by an operating system that lets programs think they have a large, continuous memory space, even though the actual RAM is limited and scattered in different places.

But what are the Objectives of a Virtual Memory
 * A program does not need to be fully loaded into memory to run; only the required parts are loaded.
 * Programs can be larger than the system’s physical RAM.
 * Virtual memory makes it seem like the system has more memory than it actually does.
 * It uses both RAM and disk space, loading program parts into RAM only when needed.
 * This helps the system run more programs at the same time and use memory efficiently.


<img width="1042" height="745" alt="image" src="https://github.com/user-attachments/assets/b7a34058-17e3-406c-9d3c-93f348785acf" />

But how does a Computer use Virtual Memory to manage / run A PROGRAM

well a Virtal Memory also need permission to READ , WRITE AND EXECUTE an assigned Process .

that takes us to a brief note of MEMORY PERMISSIONS (R/W/X) :






