# BugWorld
Bug World is an idle game where the player makes strategic decisions using a variety of bugs to clear endless levels of organically growing vegetation.

## Installation
### Windows
Download the installer from the [releases](https://github.com/emmgame221/BugWorld/releases/tag/v1.0.0) page and run it.
Alternatively, you can follow the build instructions for Windows below to build the project from scratch.

### Linux
Follow the build instructions for Linux below

### Mac
Mac is not officially supported, but it should be possible to build on Mac by following the instructions on the [SFML website](https://www.sfml-dev.org/tutorials/2.5/start-osx.php) to create a project with SFML and then add/copy the files from this repository into it.

## Build Instructions
### Windows
You will need Visual Studio 2019 or later and SFML 2.5.1.

You can get Visual Studio [here](https://visualstudio.microsoft.com/downloads/).

You can get SFML [here](https://www.sfml-dev.org/download/sfml/2.5.1/). If you want to use the dlls in the repository, you will need to install the 32 bit version of SFML.
Otherwise just replace the dlls with the ones from your download.

Use git to clone the repository, or download the code as a zip file from github.

Open "Bug World.sln" in Visual Studio. Check the project properties for the main Bug World project.
You will want to check all of the locations mentioned in the [SFML and Visual Studio tutorial](https://www.sfml-dev.org/tutorials/2.5/start-vc.php).
Ensure that the sfml/lib and sfml/include directories in the project properties match their locations on your system.

Bug World uses the SFML Graphics, Window, System and Audio libraries, so make sure all of those are included in Linker->Input->Additional Dependencies.

Once you have the project settings set up you should be able to build the program from Visual Studio.
If your build fails, check in the Configuration Manager that you're build platform matches the version of SFML you are using.
Also, ensure that the C++ Language Standard is set to ISO C++17 Standard in the project settings
If it still fails, try following the SFML and Visual Studio tutorial above to see if all of the necessary project properties are set.

Following a successful build, "Bug World.exe" can be found in either the Release or Debug folder depending on your build configuration.
To play the game either run from Visual Studio or make sure that the resources folder is contained in the same folder as "Bug World.exe" and then double click the executable.
You can also create a desktop shortcut by right clicking and selecting Send to->Desktop (Create Shortcut).

### Linux
You will need make and g++ with a recent enough version to support the C++ 2017 standard.

The [SFML and Linux tutorial](https://www.sfml-dev.org/tutorials/2.5/start-linux.php) can walk you through the process of installing SFML.

Use git to clone the repository, or download the code as a zip file from github.

Assuming you installed SFML to a standard path you should be able to build Bug World by simply navigating to the project folder in your terminal and entering ```make```

Now you can run the game by entering ```./bugworld```

If you installed SFML to a nonstandard path you will need to edit the Makefile to use the correct include directory or build manually following the instructions on the SFML website.

## Authors
Vincent Baldassari, Adrian Martinez, Eric McHugh, and John Szwakob III

## Notes
This project was created for CS 370 Software Engineering at SUNY Poly Utica with Professor Confer
