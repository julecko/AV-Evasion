# Good things take time
This method is very simple.
When your program gets ran in sandbox, it has to verify, if after execution it doesnt do anything malicious. Well, it cannot hold your program in there forever, can it? Adding simple sleep at beginning of your program should do the thing.
## Statistics
Program had no detection change in encrypted payload detection, but it lowered count of antiviruses flagging this program by 2, which i know, is not a very big deal, but sometimes it can help. If it doesnt, there is upgraded version of this method in next subdirectory.
## Results
### Encrypted payload result
![Encrypted](images/gttt_encr.png)
### Normal payload result
![Normal](images/gttt.png)