# Too many increments
Well, i have no idea why it works. I guess antivirus skips interations in order to not get into infinite loop which could crash program or sandbox (probably not, but there is a chacke). Program checks if loop was done to the end and if it was not, again, it just closes. What is very nice about this method, is that it wont affect user. Modern cpus can do 100 000 000 increments in miliseconds, its nothing time or resource consuming.
## Statistics
We can see best result with this method. I would never think, that this one would avoid most anviruses and have drop of 16 from original encrypted payload down to only 11 from 27.
## Results
### Encrypted payload result
![Encrypted](/images/tmi_encr.png)
### Normal payload result
![Normal](/images/tmi.png)