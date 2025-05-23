# paint-plus
An improved version of Paint for XP. Screenshots and features below.

## DEVELOPERS WANTED!!
If you or a friend knows C++ please contribute by working on the broken things section down below. If you can't compile it yourself but know how to code, just add a pull request and I will compile it myself inside the VM or scroll down to find the "How to compile" section

## Features:

Working things:

- New icon for paintbrush because why not
- Zoom past 1000x by going to View > Zoom > 1000x zoom...
- Small spray paint icon is amogus, it doesn't actually spray an among us character but it WILL in the future!

Broken things (devs wanted):

- Cursed icon underneath the circle tool - it is supposed to be a triangle tool but it's a WIP. If you know C++, please contribute!
- Image > Attributes shows the "Use transparent background color" option. It only is active when you are editing a GIF and it doesn't work...
- I can't save any image as a GIF on Windows 10 but we only have to start caring about that when we get transparent bg color working.

Todo:

- Add a DLL icon stamp tool thing. I know that you can make one, but the same thing with the triangle tool, I have only figured out how to replace a tool instead of making a new one.

The end goal for this project is to turn this into a more feature-rich version of Paint.

## Screenshots

![image](https://github.com/user-attachments/assets/2d482e0e-7716-4a8c-bdc2-3813d27615ab)

![image](https://github.com/user-attachments/assets/087e03ad-2180-4e30-84db-4260dd6705c3)

Okay, here's the source code. It does require a "few" extra thingies to compile though.

Edit: https://github.com/svgmaker/paint-plus

# How to compile 

Requirements

- XP Virtual machine, the software will rot your registry on later versions
- [Visual C++ 6.0](https://winworldpc.com/product/visual-c/6x)
- Knowledge on how to add directories to Visual C++
- [Windows platform SDK](archive.org/details/en_platformsdk_win2003) - installs to a folder in the c drive. if you get "file.h not found", search this.)
- [Sygwin](https://www.cygwin.com/install.html) to convert the unix file types to Windows. Install the "dos2unix" component.
- [W32 api](https://github.com/MaxKellermann/w32api) - if you have any errors that tell you "file.h not found" or something like that, search this for the dll.
- [whatever the fuck this is](https://winworldpc.com/product/windows-sdk-ddk/xp-nt-51) for the same reason above.
- [twain.h](https://github.com/twain/twain-toolkit/blob/master/twcommon/TWAIN.H) unless you know how to remove scanner support from the code.

Get the source code [here](https://github.com/tongzx/nt5src). Download the zip, extract it and search for the folder "mspaint". then before you copy it, use unix2dos that you downloaded with Cygwin by opening up Cynwig64 Terminal, cd-ing to your dir and running "unix2dos *" in the folder, and then in the subdirs. Copy it to your VM and then stitch everything together. Remember that #include <file.h> is including a file in one of the directories you specified, and #include "file.h" is including a file inside the mspaint folder. I managed to get all the .h files by searching around the web and copying them to the mspaint folder and changing #include <file.h> to #include "file.h"
