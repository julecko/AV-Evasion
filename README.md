# Introduction
Have you ever created some software, potencionally malware, maybe something fun to prank your friends and it was always getting detected by antivirus?
Well, this project focuses on fixing this problem, problem of antivirus detection. First you must learn how antivirus work in order to make program that can bypass antivirus.

## Antivirus
So, what is antivirus? It is software, that sets rules and manages your computer. It protects you from harm and malicious activity and filters applications which you can use and which are dangerous. That's something most of us already know, but how does it detect stuff? How does it knows all of this? Answer is simple, from analysis. It monitors all activity and decides if that activity should be allowed, should not be allowed or asks you when it cannot decide by rules it has defined. For example one rule can be, that any file on desktop cannot be edited by unknown application (this is called ransomware protection), and if any application tries to do so, it asks you, if you want to allow this kind of behavior. This is just one of many possible scenarios.

## Analysis
There are many types of analysis antivirus uses, but they can all be sorted into 2 groups

### Static Analysis
As the name says, its static, which means, analysis is done in static state of program, where it checks program for patters, common string, function calls, properities or even certificate of program.
Certain malware is not found by normal detection, where basic antivirus would normally allow it to go through, but if it gets a little more popular, cybersecurity specialist look into it they can find a part of program which is unique and add it to database of malware. It can be also done with simple hash, where that hash of program is forbidden. Using this method, malware will be captured just because its already in database of known malware.
Another example is, where antivirus forbids certain function calls. If my program wants to try to infect another process, in which case function <b>OpenProcess</b> is usually used, program will be flagged as malicious just because this functions is in my program. To evade this type of analysis, you need to avoid using certain strings, words, function and pattersn in your program.

### Dynamic Analysis
You probably saw this comming, another group of analysis is dynamic one. In this type, programs are ran by your antivirus in sandboxes. Sandboxes are virtual enviroments, which are separated from main computer. This means, that if your program is runned in sandbox, no harm can be done to user under which this sandbox is running. They are usually implemented by antivirus. Lets say, your program bypassed all of static analysis, but when it is runned in sandbox, it still executes forbidden function like <b>OpenProcess</b>. Well, your program will still get flagged as malicious, because antivirus saw, that you program tried to do this. In order to bypass this kind of detection, you need to do one simple thing, not do stuff that is detected. Which is not simple at all, but trust me, its not that hard. So basicly, you need to tell your program, to either not run in sandbox, or do something which sandbox arent capable of doing, monitoring or comprehending. Its hard to find the right words for it, but hopefully you'll understand after this tutorial like repository. So, to not run in sandbox, program need to be able to tell difference between computer and sandbox. Enviroments in sandbox differ in lot of stuff from user enviroment. They have less space, less ram, might not have acces to all possible API functions and have limited time. Maybe you have already seen little antivirus windows, which said that your programm is being controller for viruses. This is when your program is tested in sandbox. Before i was studying AV-evasion and making my homemade malware, i had problem with antivirus. It was flagged as malicious always after i started it, which means, dynamic analysis cought it. And after thinking about it for like a day, I got an idea. If my program is caught at start of my program, why dont i just make it wait for few seconds and then start. Well, surprisingly, it worked. Such a simple solution to complicated problem. Of course, its really amateur solution and when antivirus has more strict rules or its just more advanced this solution doesn't work, but in that moment, it was my solution.

## Running
After you bypass theese two types of analysis and your program is succesfully running, you are mostly free to do anything. There is still behavioral analysis, which is part of dynamic analysis and it can flag and capture your program at runtime, but in most cases this analysis is not your problem and if so, evading it is a lot harder and requires harder methods of evasion which i won't be covering in this repository. You can find some of them <a href="https://www.scriptchildie.com/">here</a>

## Suggested order of techniques
1. [Good things take time](/Good_things_take_time/)
2. [Good things take time V2](/Good_things_take_time_V2/)
3. [Too many increments](/Too_many_increments/)
4. [Too much to handle](/Too_much_to_handle/)
5. [Who am I](/Who_am_i/)
6. [Debuggable or Not](/Debuggable_or_Not/)
7. [Weird enviroment](/Weird_Enviroment/)
8. [Am i my own father](/Am_I_my_own_father/)
9. [Message to the unknown](/Message_to_the_unknown/)

And all of them finish with [Finale](/Finale/)

You can also check [static evasion](/Static_Evasion/) which is a little more complicated

## Testing
I have created simple payload, which executes shellcode in its memory which starts calc.exe. In images subfolder are screenshots of VirusTotal result of my programs. Default payload was detected by 32 out of 73 antiviruses. I tought, that many results might be afected because of static analysis, so for many methods i have implemented a little bit of static analysis evasion for better results. New, encrypted payload was detected by 27 out of 73 antiviruses which is still pretty high and by AV-evasion methods we will try to get this number lower.

## Final Words
I hope you will find this repository helpful, you will learn something and mostly, you will use it with ethical intentions.

## Resources
- [BypassAVDynamics.pdf](https://wikileaks.org/ciav7p1/cms/files/BypassAVDynamics.pdf)
- [SimpleMalwareAV-Evasion part1](https://cocomelonc.github.io/tutorial/2021/09/04/simple-malware-av-evasion.html)
- [SimpleMalwareAv-Evasion part2](https://cocomelonc.github.io/tutorial/2021/09/06/simple-malware-av-evasion-2.html)
- [SimpleMalwareAv-Evasion part3](https://cocomelonc.github.io/tutorial/2021/12/25/simple-malware-av-evasion-3.html)
- [AV-Methodology](https://book.hacktricks.xyz/windows-hardening/av-bypass)
- [ScriptChildie](https://www.scriptchildie.com/)
## Payload Analysis Results
### Encrypted payload
![Encrypted](/images/payload_encr.png)
### Normal payload
![Normal](/images/payload.png)
