# Batm-n Sh----s Edition
A certain entertainment application presents timed dialogues and "actions".
Subtitles are available in several languages yet the user cannot make a choice but must go with the one preselected for them.

## Objectives
1-Increase the time limit of timed choices and actions.

2-Have subtitles in English.

## Work
1-We make the application load a custom library which creates a thread that with a certain frequency samples the screen to decide whether the time bar is present, if so it sets the application's time scale to a very low number so that time slows down giving the user ample time to make their choice; if the time bar is not present then it sets the variable back to the default value.

The loading operation is coded in the application's binary itself, which is patched with the following logic: if a certain global variable is false then the library is loaded and the variable is set to true.

This mod gives the user plenty of time to make a choice, and contrary to other solutions which require the user input it is fully automated.

2-We make the routine inside the application's binary that returns the system language return the value which corresponds to English.

This makes the application display susbtitles (and the UI) in English.

## What is Available
Only the code of the bot, ie the library, is available.

## License
This project is provided **AS-IS**.

This project is MIT licensed.
