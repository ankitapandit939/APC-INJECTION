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

  for example : _virtualbox.exe, notepad.exe, androidstudio.exe_

  _Opening Notepad.exe creates a process._

  _Opening Android Studio creates another process._

  _Each process runs independently._

 Now with context to APC injection the attacker will choose a target process like ANDROID STUDIO to run their malicious code inside it.

  
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


  Even if there are permissions for Virtualalloc() attackers can misuse the memory by using **SHELL CODE** but what is it ?


  A Shell Code is basically a A malicious Payload (CODE) that can make our system Vulnerable , but to run this payload in Virtual Memory the attacker needs to
  write it in a memory location with EXECUTE(X) permissions . It runs directly from the memory (ex - RAM ) of the machine i.e insted of ruuning a program like
  androidstudio.exe the instructions (shellcode) will run diretly through memeory    
  
There are some important points that must be noted:

  -If memory is not executable, shellcode cannot run.

  -So attackers ensure memory has Execute permission.

   __Shellcode is the “secret instruction” delivered via APC.__ 


  Figure Reference:

  <img width="1457" height="635" alt="image" src="https://github.com/user-attachments/assets/e21774f6-4f6b-4363-9f13-d7905771a565" />


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

    like in the figure below we can see with the use of WINDOWS API , THREAD , HANDLE an attacker is inserting a secret Song i.e APC


    <img width="868" height="448" alt="image" src="https://github.com/user-attachments/assets/964b94e5-aa2f-4c75-8c9a-b33645a50f32" />




   







