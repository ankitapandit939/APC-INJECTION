# APC-INJECTION
APC-Injection

A process of attaching a malicious code to the APC queue or APC Injection is a process injection technique that abuses Windows’
Asynchronous Procedure Call mechanism to execute injected code(i.e malicious code) inside an existing thread without creating a new one.

But what is APC ?
Asynchronous procedure calls (APCs) are functions executed asynchronously within a specific thread of a PC.
It is used mostly for 
 - I/O operations and completions
 - Asynchronous operations

But what is inside a Computer that helps it to complete a task that is assigned .
There are Processes and Threads.

Now what is a process 
It is a running program in a PC (ex - virtualbox.exe , notepad++.exe)
A process consists of more than 1 thread

<img width="846" height="60" alt="image" src="https://github.com/user-attachments/assets/c06cd2a4-7eb1-428a-9e31-d0219bb9a17d" />



Which takes us to next block i.e thread
A thread is a unit that executes a code or command given user. So basically when we give any command to a computer it tells the thread to execute 
it and when this execution occurs it is called a process .


<img width="288" height="175" alt="image" src="https://github.com/user-attachments/assets/a2cde7ef-55a6-4a0c-8572-39179ab0bcd6" />


'THREADS ARE THE EXECUTION UNIT OF A PROCESS '

WHY APC IS AN IMPORTANT UNIT OR PART OF A COMPUTER ?
- Because it executes  all the task assigned ,whether it is an simple I/O operations or any complex operations . 

Now if Your APC gets injected with a malicious code it can be dangerous, but how is it done 

APC executes only when a thread enters an alertable state but what is an Alertable state -

ALERTABLE STATE - AN ALERTABLE STATE IS A CONDITION WHEN A THREAD IS IN REST OR WAITING TO EXECUTE THE QUEUED APC'S.

These were the Prerequisites that we should know before trying to learn about WHY AND HOW IS APC INJECTION DONE .

