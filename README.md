# Before you begin

It is actually an assignment of OOP. If you're a student, especially studying in ZJU, I do hope this can help you.
I've done most of the work by myself. In another word, you can say it is "original". Anyway, you can use my code freely and it is unnecessary to let me know, but I'll take no responsibility either if something out of your control happens.


# Personal Diary Application

Personal Diary is a simple application designed to help users manage and maintain their personal diaries. It allows users to easily add, view, delete, and list their diary entries. The application provides a basic command-line interface for users to interact with the software.


## File Structure

```
PersonalDiary/
│
├── README.md               # This document                             
├── src/              
│   ├── main.cpp        # Main program interface code
│   ├── pdadd.cpp       # Adding or overwriting diary entries
│   ├── pdlist.cpp      # Listing diary entries
│   ├── pdshow.cpp      # Displaying a diary entry for a specific date
│   ├── pdremove.cpp    # Removing a diary entry for a specific date
|   └── diary.bat		# A script calling programs through parameter
├── download/         
│   └── mysetup.exe     # For installation
├── bin/
|   ├── main.exe
|   ├── pdadd.exe
|   ├── pdlist.exe
|   ├── pdshow.exe
|   └── pdremove.exe

```


## Features

This application provides the following functionalities:

1. **Add Diary Entry** (`pdadd.exe`):

   Allows the user to add a new diary entry or overwrite an existing one for a specific date.
2. **List Diary Entries** (`pdlist.exe`):

   Lists diary entries within a specified date range, or lists all diary entries.
3. **Show Diary Entry** (`pdshow.exe`):

   Displays a specific diary entry based on the provided date.
4. **Remove Diary Entry** (`pdremove.exe`):

   Removes a specific diary entry based on the provided date.
5. **Main Program** (`main.exe`):

   The main interface of the application, where users can choose different actions.
6. **Batch Script** (`diary.bat`):

   A batch script to execute the programs with parameters, enabling users to perform specific tasks directly from the command line.


## Installation

1. Download the `mysetup.exe` file and run the installer.
2. Follow the on-screen instructions to complete the installation.
3. Once installed, you can run the Personal Diary application from the Start Menu or the desktop shortcut.

## System Requirements

* Windows operating system (64-bit version)
* Microsoft Visual C++ runtime libraries
* gcc (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0
