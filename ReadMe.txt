Abysmal Depths v1.0
by Kenshin Himura, Copyright 2012-13

This is a game engine which uses certain story files to drive a text-based adventure game with numeric inputs from users, always taking only a maximum of three choices (which can be extended in future versions). There is no limit on the length of the story included. The only constraint is that you should propely index and link to all of the storyfiles in an arc.

Here is the structure to follow:
Game01.adg -> Contains all Story Arc File Names one after the other
StoryFile.ads -> Contains story, including display of three choices
StoryFile.adc -> Contains choice results, including next StoryFileName
chooseHero.ads -> Contains the story before prompting the user to enter his name
chooseClass.ads -> Contains the story before prompting the user to enter his Class

*Story Files like Introductions, if they contain ASCII art with constant width 80 can be displayed.
*The Story file should have the character 'A' appended to its filename to specify that its an ASCII Art file.
*These will have no choice by default.
*Story Files, if they don't need a choice file, can have > or >nextStoryFileName at the END. This improves the story reading experience of the user ashe can read bits of the stories at a time. This can also simulate scenarios of resting and dreaming about the past (which was the original idea).
*Each choice in the choiceFile should also have a >nextStoryFileName at the END

Also, to instantiate a monster, a tag
[monster monsterName monsterLevel
should be added anywhere in the story file
[c tag is used at the end of the choice in the choice file to indicate start of combat
[e tag is used to indicate start of escape by userHero

Visions of this project (for now):
->To create a parser instead of a choice-based input.
->To change fixed hero types and hard coded attributes and update functions to dynamic hero types with dynamic attributes and update functions read from separate files.
->Instead of using plaintext files with varying extensinos, to create encrypted plaintext files only decoded by the engine (simple substitution cipher will suffice)