# Message to the unknown
I was suprised, that this really worked, because just the principle of this method is very funny. So, how does it work? When we create malware, we often create remote connection to a server. Either if its some kind of backdoor, trojan horse or even ransomware checking if payment was received. When such a program is in sandbox, antivirus doesnt want you to communicate with your program so it does 2 things. One is, that it holds all network requests, so you are unable to communicate with your program and other one is, that they fake data that is being send to you, because if you cant communicate, sandboxes try to simulate enviroment where it can communicate. The catch is, that when giving false response from server, antiviruses often dosnt check, if that url is even valid. We can take advantage of this, by making request to domain, which is not linked to any IP address. And thats it, our whole method is just sending request to domain, which is not registered, thus we should get no response but because of antivirus we get response. If we get response, program is in sandbox, if we dont, it isnt. Its that simple.
## Statistics
This method has one of the best results with drop of 14 antiviruses in encrypted payload. Again, unencrypted has no big win, but thats because of stupid static/heuristic analysis.
## Results
### Encrypted payload result
![Encrypted](/images/mttu_encr.png)
### Normal payload result
![Normal](/images/mttu.png)