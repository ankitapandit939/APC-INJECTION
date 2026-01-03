# **APC INJECTION**



# **TABLE OF CONTENTS:**
 
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

# _**PROCESS:**_


So now WHAT IS A PROCESS IN A COMPUTER?
- A PROCESS is basically a type of conatiner that helps the commands to get executed inside it when they are assigned with the help of THREAD.

  for example : _spotify.exe, notepad.exe, androidstudio.exe_

  _Opening Notepad.exe creates a process._

  _Opening spotify creates another process._

  _Each process runs independently._

 Now with context to APC injection the attacker will choose a target process like notepad to run their malicious code inside it.

  
# _**THREAD:**_

that takes us to our next basic unit THREAD

A THREAD is a fundamental unit of a PROCESS , it is the Thread that performs the execution of a assigned task or command in the Computer.

For more clear understanding think that _YOU OPEN CHROME AND SEARCH FOR SPOTIFY_


What happens next SPOTIFY loads and you search/view a SONG on your feed 

how does this process happens ? for this process THREAD plays a major role 


One thread loads a webpage(i.e SPOTIFY webpage)


Another plays a plays the song.



For more simple breakdown we can refer to the figure below:


<img width="1120" height="561" alt="image" src="https://github.com/user-attachments/assets/e9ba385f-3037-4795-9238-57d7cd6c1cc4" />

When APC Injection is done it needs a  _**VIRTUAL MEMORY**_ but What is a Virtual Memory?

Virtual memory is a technique used by an operating system that lets programs think they have a large, continuous memory space, even though the actual RAM is limited and scattered in different places.

in other words Virtual memory makes each process think it owns all memory.

But what are the **Objectives** of a Virtual Memory
 * A program does not need to be fully loaded into memory to run; only the required parts are loaded.
 * Programs can be larger than the system’s physical RAM.
 * Virtual memory makes it seem like the system has more memory than it actually does.
 * It uses both RAM and disk space, loading program parts into RAM only when needed.
 * This helps the system run more programs at the same time and use memory efficiently.


<img width="1042" height="745" alt="image" src="https://github.com/user-attachments/assets/b7a34058-17e3-406c-9d3c-93f348785acf" />

But how does a Computer use Virtual Memory to manage / run A PROGRAM

well a Virtal Memory also need permission to **READ , WRITE AND EXECUTE** an assigned Process .

Now each Process has its own private virtual memory that is protected from other processes

that takes us to a brief note of **MEMORY PERMISSIONS (R/W/X)** :

* **Read (R):** Allows a program to read data from a memory location.
* **Write (W):** Allows a program to modify or store data in a memory location.
* **Execute (X):** Allows the CPU to run instructions from a memory location.
* These permissions prevent misuse of memory, such as executing data or modifying code.
* The operating system enforces these permissions to keep programs secure and stable.

  In contect to the APC INJECTION Shellcode (malicious code) is written into the virtual memory space of the target process _(ex-notepad.exe)_.


  Even if there are permissions for VirtualallocEx() attackers can misuse the memory by using **SHELL CODE** but what is it ?


  A Shell Code is basically a A malicious Payload (CODE) that can make our system Vulnerable , but to run this payload in Virtual Memory the attacker needs to
  write it in a memory location with EXECUTE(X) permissions . It runs directly from the memory (ex - RAM ) of the machine i.e insted of running a program like
  androidstudio.exe the instructions (shellcode) will run directly through memeory .   
  
There are some important points that must be noted:

  -If memory is not executable, shellcode cannot run.

  -So attackers ensure memory has Execute permission.

   __Shellcode is the “secret instruction” delivered via APC.__ 


  Figure Reference:

  <img width="1588" height="511" alt="image" src="https://github.com/user-attachments/assets/785ab603-6337-47c3-9ebc-5eb1fd8a7f90" />



  Now since we know the basics we can continue our Journey to APC 



But before we talk about APC there is one more important thing and that is **WINDOWS API**

  Now what is WINDOWS API ? 

  -In simple words these are the commands through which programs ask windows to run/do things .

for example
 
  * opening a file


  * allocating a memory

Since APC INJECTION is more about using THREADS ,

in programs to pinpoint a specific thread we need a unique id right? And here comes the role of _HANDLE_ which 

is the OS-approved reference that allows safe and controlled operations on that exact thread.


  - A Handle is a unique identifier that gives access to a specific thread or process that an attacker can use to ADD their APC to the TARGETS thread queue.

    simplying it the process or thread is a room and handle is a KEY to that room .

    like in the figure below we can see with the use of WINDOWS API , THREAD , HANDLE an attacker is inserting a secret Song i.e APC


    <img width="868" height="448" alt="image" src="https://github.com/user-attachments/assets/964b94e5-aa2f-4c75-8c9a-b33645a50f32" />



    HERE COMES THE MAIN TOPIC OF DISCUSSION **APC INJECTION**

    But before WHAT IS APC ?

    So APC stands for Asynchronous procedure calls these are the functions executed asynchronously within a specific thread of a Machine . Basically a request sent to a
    THREAD.
    
    

    Here is a Breakdown of Asynchronous procedure calls

   Asynchronous    :
  * The task does not run immediately.
    
  
  * It does not block other operations.
  
  
  * It runs later when the system is ready.

   Procedure Calls :

   
  * A request to run a specific set of instructions (like a function or routine) within a defined execution environment (context). 


   There are three types of APCs

   * SIMPLE APC
   * EARLY BIRD APC
   * SPECIAL USER APC


     - SIMPLE APC - A simple APC runs only when a thread is waiting or idle (in an alertable
     state)

       for example :

       You are listening to a Song on Spotify (not  a premium user) and the AD only plays when
       the song has ended not in between i.e The ad does not interrupt the song immediately it
       waits until the song finishes just like that SIMPLE APC waits until thread is ready .

       <img width="364" height="193" alt="image" src="https://github.com/user-attachments/assets/92ecc5be-a28d-41e7-8e5e-6e4707efb02f" />



     - EARLY BIRD APC - In this the APC is queued before that thread starts running so
       that it executes as soon as the thread begins

       for example :

       You open SPOTIFY (again not premium) and AD plays immediatley that is The AD is ready
       before the start of the song/music even before the APP fully loads.

       <img width="363" height="191" alt="image" src="https://github.com/user-attachments/assets/e12ecbb3-23ef-4645-8260-897c6340f64e" />


       
     - SPECIAL USER APC - It is a high priority APC and run when certain system events happen
       even if the thread is not waiting .

       for example :

       While streaming on spotify you come across a forced AD means the the AD is
       event-triggered , it does not wait for the song to end because it is HIGH PRIORITY


       <img width="368" height="192" alt="image" src="https://github.com/user-attachments/assets/4f5dc1df-ff78-4f3a-a5cb-081fe7bedd43" />




   




<img width="813" height="82" alt="image" src="https://github.com/user-attachments/assets/e64d9612-0048-4b6c-a364-3920e08f8f97" />


that takes us to WHAT IS **APC INJECTION** ?

A process of attaching a malicious code to the APC queue or APC Injection is a process injection technique that abuses Window's
Asynchronous Procedure Call mechanism to execute injected code(i.e malicious code) inside an existing thread without creating a new one.

**APC QUEUE**

- An APC queue is a list where Asynchronous Procedure Calls (APCs) are stored until 
            they are ready to run.

 SIMPLE BREAKDOWN :

 -When an APC is created , it is placed into the APC queue of a thread .
 there 

 -The APC waits in the queue until the thread is allowed to execute it 

 -The APC runs when the thread enters an _**ALERTABLE STATE**_ or when Conditions for that APC is met.

 <img width="897" height="689" alt="image" src="https://github.com/user-attachments/assets/1dc5f1e6-3a7a-465b-a5aa-59408f0fba8c" />



**ALERTABLE STATE**

- A special state where a THREAD temporarily pauses its main work to process its APC
  QUEUE .

  for example:

  Think of a scheduled Break during your study hours to do some doom scrolling .
  basically a coffee break.


  <img width="808" height="212" alt="image" src="https://github.com/user-attachments/assets/f2a37c0f-ef78-4963-ac0a-699a329791f8" />




 








