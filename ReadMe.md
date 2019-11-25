# HFL (Hacker's Function Library)

Version 0.7-incomplete
Author: BlackBox (formerly op2hacker)

This library is for use by Outpost 2 mission DLLs (or shell extensions). It extends the usual set of functionality provided by Outpost2.exe, beyond what is normally exported, by giving direct access to internal methods and data. It does this through various memory hacking techniques.

Normally memory hacks of the nature used in this project can be a bit unsafe as they are dependent on particular binary layouts of classes and structures. Such layouts are subject to change during a recompile. However, as the source code for Outpost 2 is unavailable, it is extremely unlikely it will ever be recompiled, hence memory hacks should be reasonably safe to use.

## Usage

This library is distributed as part of the [MissionSDK](https://github.com/OutpostUniverse/OP2MissionSDK). An Outpost 2 mission project can reference the MissionSDK project, which will bring in access to HFL. For a template mission project, see the [LevelTemplate](https://github.com/OutpostUniverse/LevelTemplate) project. The LevelTemplate project is already configured to use the MissionSDK, and hence also provides access to HFL.

## Documentation

An incomplete manual in HTML format can be found in the "Doc\" folder. A small example mission can be found in the "Example\" folder.

## Client Project Configuration

If you are using the LevelTemplate project, you can largely ignore this section as it is already setup for you.

To use HFL, you must configure the compiler's Include and Library paths. See the "basics" page of the manual in the Doc folder for details. The project will need an include folder set so it can find the header file with the `#include <HFL.h>` line. It will also need a library folder set so it can find HFL.lib during the link step.

Calling code should be sure to call `HFLInit` before calling any other HFL methods. For an Outpost 2 mission, this should be done from `DllMain`. In particular, this should not be done from `InitProc`, as that will leave the mission vulnerable to problems after loading a saved game. The `InitProc` method is only run once at level start, and will not run when a saved game is loaded. This can leave the HFL library uninitialized after loading a saved game.

## Bugs / Help

I'm sure this has lots of bugs. If you find something that might be a bug, post about it on the forum. Likewise, if you need help using anything in HFL, make a post regarding that.

And yes, I know one of the major 'bugs' is the lack of a complete manual. The manual also probably has the wrong version number listed, has pages missing, has stuff documented that doesn't even exist in the library, etc. As far as documentation on the GUI objects like command panes and such, the manual isn't too helpful. You'd be best off looking at the example mission in the Example folder, and/or playing around until you get things to work.

Good luck, and I hope this helps you in your Outpost 2 mission endeavors :-)
