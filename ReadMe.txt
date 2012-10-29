========================================================================
    TimeStampCreator by Aleksander Lorenc
========================================================================

Program can batch set timestamps into files.
This program was written and compiled using Microsoft Visual C++ 2010 Express.
Idea to write this program came when I was writting TimeStampCopy.
Thanks to MSDN Library I was able to code what I needed.

/////////////////////////////////////////////////////////////////////////////
Program usage:

tsm [target] [creation] [access] [write] [year] [month] [day] [hour] [min] [sec]

target - file to save timestamp[s] to
creation, access, write - timestamp options:
      c - replace file timestamp
      x - leave unchanged
day, month, year - timestamp date(YYYY M D)
hour, min, sec - timestamp time(24h clock)

Any time you write bad command information about usage is shown.
Examples:
If you want to set creation date of a.txt file to the Battle of Grunwald at noon you write the following
tsm a.txt c x x 1410 7 15 12 0 0
If want to set last access timestamp and last save timestamp to b.txt to signing of United States Declaration of Independence at noon you write the following
tsm b.txt x c c 1776 7 4 12 0 0

/////////////////////////////////////////////////////////////////////////////
Requirments:

Windows 2000 Professional or above

/////////////////////////////////////////////////////////////////////////////
Other information:

The filenames I was using were non-latin(hangul) and the program failed. This is what I've done to make it work. There might be an easier/better way.
I made a utf-8 without bom batch(.bat) file in Notepad++. First line was "chcp 65001". Then "tsm..."
Then I run it through PowerShell ISE v2. There is command line in lower half. I wrote "./file.bat".

/////////////////////////////////////////////////////////////////////////////
