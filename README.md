```

__/\\\________/\\\_____/\\\\\\\\\___________/\\\\\\\\\____________/\\\\\\\\\\\\\________________________________________________________________________        
 _\/\\\_______\/\\\___/\\\\\\\\\\\\\______/\\\////////____________\/\\\/////////\\\______________________________________________________________________       
  _\//\\\______/\\\___/\\\/////////\\\___/\\\/_____________________\/\\\_______\/\\\____/\\\__/\\\___/\\\\\\\\\___________________________________________      
   __\//\\\____/\\\___\/\\\_______\/\\\__/\\\_______________________\/\\\\\\\\\\\\\\____\//\\\/\\\___/\\\/////\\\__/\\\\\\\\\_____/\\\\\\\\\\__/\\\\\\\\\\_     
    ___\//\\\__/\\\____\/\\\\\\\\\\\\\\\_\/\\\_______________________\/\\\/////////\\\____\//\\\\\___\/\\\\\\\\\\__\////////\\\___\/\\\//////__\/\\\//////__    
     ____\//\\\/\\\_____\/\\\/////////\\\_\//\\\______________________\/\\\_______\/\\\_____\//\\\____\/\\\//////_____/\\\\\\\\\\__\/\\\\\\\\\\_\/\\\\\\\\\\_   
      _____\//\\\\\______\/\\\_______\/\\\__\///\\\____________________\/\\\_______\/\\\__/\\_/\\\_____\/\\\__________/\\\/////\\\__\////////\\\_\////////\\\_  
       ______\//\\\_______\/\\\_______\/\\\____\////\\\\\\\\\___________\/\\\\\\\\\\\\\/__\//\\\\/______\/\\\_________\//\\\\\\\\/\\__/\\\\\\\\\\__/\\\\\\\\\\_ 
        _______\///________\///________\///________\/////////____________\/////////////_____\////________\///___________\////////\//__\//////////__\//////////__

```

This is a very very simple GUI written using C++20 and the windows API. This GUI allows you to inject a DLL and bypass Valve Anti Cheat with CSGO (VAC). When you run the program the windows file explorer will pop up and execute, you must select a .dll file or the program will not work. 

# Set up 

### Open MSVSC ( Microsoft Visual Studio Code ) and select release and X86 ) ###

![](git/Set1.png)


### Right click on `loader` and select properties ###

* General - C++ standard = ISO C++20 Standard 

![](git/Properties.png)

* Advanced - Characterset = Use Multi Byte Character Set

![](git/Prop2.png)

* Linker - System - Subsystem = Not Set

![](git/Prop3.png)

### Build and execute ### 

![](git/Example.png)

* hardware info 

![](git/Hardware.png)







