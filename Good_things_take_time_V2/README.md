# Good things take time V2
As we saw, results of previous version of this method were not very satisfying. You might wonder, why was in not working that well? It's because, antiviruses use their own methods to speed up analysis process. Sleep is basic windows API which is removed from program when put into sandbox. So, if you cannot delay your program execution, very simple thing you can do is check, if your program had a delay. You can do this by measuring time before and after sleep command. If that time is nowhere close to specified time, you know that something is wrong and you can just close the program. This method closes program program inside most quick sandboxes and let your program run inside user enviroment.
## Statistics
When seeing results of this method i was really supprised, in good way. With normal payload we saw decrese of 5 antiviruses, which is not gamechanging. But thats because of static analysis. Using encrypted payload we saw decrese of 15 antiviruses less from 27 to 12, which is amazing!
## Results
### Encrypted payload result
![Encrypted](images/gttt_v2_encr.png)
### Normal payload result
![Normal](images/gttt_v2.png)