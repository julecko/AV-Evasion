# Too much to handle
This method allocates big chunk of memmory at the beggining of execution and imidiatelly frees it. At first i didnt understad why this method worked but later i have learned, that ist because allocating big chunks of memmory is normal behavor for bigger applications, so it allows program to blend in more and it also delays execution a little bit by something non malicious. Its like distraction from malicious content of malware.
## Statistics
Again, in normal payload we can see not really big change of 2, but in encrypted one, count of antiviruses flagging this malicious dropped down to 19, so 8 less. Its not outstanding result, but its still a drop and in the end, we can mix many methods to try to decrease this count close to zero. Of course, after using some methods, this method wont drop AV count by 8, but it will help for sure in some way
## Results
### Encrypted payload result
![Encrypted](images/tmth_encr.png)
### Normal payload result
![Normal](images/tmth.png)