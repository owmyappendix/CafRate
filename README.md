# CafRate
CafRate is a program for viewing the St. Olaf dialy menu, reading reviews, and leaving reviews for others.

# Note:
* This program was written as a collaborative project between myself, Dagmawe Haileslassie, and Erica Meyers. It has been posted here with their permission.
* CafRate was written for use with a proprietary web server at St. Olaf college. The code will not run off campus without heavy tweaking.
* Cafrate is written mostly in C++ with the UI in YAML and communication with a webserver in python.
* This is an unfinished project. Most features work locally but it has not been configured to share data between users
* Currently the login page is for show only

# Using CafRate

* CafRate is only usable on St. Olaf college networks and currently only on the link machines in RNS202 and 203. On these machines, download the code and run the following. g++ -Wall -g -std=c++11 driver.cpp str_util.o sd_fun.o then run ./serve.py

# CafRate code
 
 * driver.cpp: This file contains main. Main mostly contains if statements that check what buttons were pushed and calls the necessary functions or uses add_yaml.
 
 * directory.cpp: This file contains our functions that build each page and the items on the page. 
 
 * directory.h: Contains classes.
 
 * user.h: This file contains a few functions that assist in the login process and in reading in and writing out reviews
 
 * Comments.txt: This is the file that is written to and read from for the reviews. Hopefully, with Gcloud tweaks it could be read and written to by multiple
   users as a dataport alternative.
 
 * usernames.txt: Contains usernames
 
 * Passwords.txt: passwords
 
 * many .yaml files, this is where much of our code is contained, including the entire GUI.
 
