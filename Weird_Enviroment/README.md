# Weird Enviroment
As the name says, this method will check, if our program is in weird enviroment. Our "weird" enviroment is the one in which antivirus runs our program. To allow computer to run normally and not concume all its resources, antivirus enviroment has limited resources. By this method we check for standards, which every computer should have but most antivirus enviroments dont. To be more exact, this method checks if our runtime has at least 2 CPU cores and more than 2GB of RAM. Thoose numbers are customizable of course, but as of writing this post, they are enough to bypass some antivirus protection.
## Statistics
Checking for resources has gotten very good results, similiar to method Good things take time V2. We can see small drop with unecrypted payload and significant drop with encrypted payload.
## Results
### Encrypted payload result
![Encrypted](/images/we_encr.png)
### Normal payload result
![Normal](/images/we.png)