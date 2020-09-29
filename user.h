#ifndef _USER_
#include "sd_fun.h"
#define _USER_
#include <iostream>
#include<vector>
#include <fstream>
#include<ctime>
#include <cstdlib>
using namespace std;

//This file contains a few functions that assist in the login process and in reading in and writing out reviews

//checks username entered against list of options
bool readUsername() { 
    vector<string> tmp;
    string usertxt;
    char * username;
    ifstream userfile("usernames.txt");
    if (userfile.is_open()) {
        while (userfile.good()) {
            getline (userfile,usertxt);
            tmp.push_back(usertxt);
        }
        userfile.close();
    }
    else cout <<"unable to open file"<<endl;
    int len;
    for (len=0; mem[320 + len] != '\0'; len++);
    username = new char[len+1];
    for(int i = 0; i < len +1; i ++) {
        username[i] = mem[320+i];
    }
    for(string x : tmp) {
        if(x == username) {
            return true;
        }
    }return false;
}
//checks password
bool readPassword() {
    vector <string> tmp;
    string usertxt2;
    char * password;
    ifstream userfile2("passwords.txt");
    if (userfile2.is_open()) {
        while (userfile2.good()) {
            getline (userfile2, usertxt2);
            tmp.push_back(usertxt2);
        }
        userfile2.close();
    }
    else cout << "unable to open file" << endl;
    int len;
    for (len = 0; mem[420 + len] != '\0'; len++);
    password = new char[len+1];
    for(int i = 0; i < len +1; i++) {
        password[i] = mem[420+i];
    }
    for(string x : tmp) {
        if(x == password) {
            return true;
        }
    }return false;
}
//Writes a comment to a text file with a timestamp and rating
void writeinComment() {
    vector <string> tmp;
    ofstream myfile;
    char * Comment;
    int num = mem[500];
    myfile.open ("Comments.txt", ofstream::out | ofstream::app);
    // Current date/time based on current system
    time_t now = time(0);
    // Convert now to tm struct for local timezone
    tm* localtm = localtime(&now);
    int len2;
    char * username;
    for (len2=0; mem[320 + len2] != '\0'; len2++);
    username = new char[len2+1];
    for(int i = 0; i < len2 +1; i ++) {
            username[i] = mem[320+i];
    }//at this point the program is trying to access the memory adress beginning from username mem
    Comment = (char *) &mem[340];
    //writing the current date and time to the txt file
    myfile<<asctime(localtm);
    for (int i=0; i<len2; i++){
       myfile<<username[i];
    }
    //this write in whatever was copied form mem earlier
    myfile<<": ";
    myfile<<Comment<<endl;
    myfile<<"Rating: ";
    myfile<<num<<"/5";
    myfile<<endl;
    myfile<<endl;
    myfile.close();
}
//reads comments.txt and displays them
void readcomment() {
    vector <string> tmp;
    string line;
    ifstream myfile ("Comments.txt");
    if (myfile.is_open()) {
        while (myfile.good()) {
            getline (myfile,line);
            tmp.push_back(line);
        }
        int count = 30;
        cerr << ' ' << endl;
        int i = 0;
        for (string x:tmp) {
            add_yaml("review.yaml", {{"num", i}, {"num2", i+1}, {"pos", count}, {"len", 200}});
            write_at(mem, count, x.c_str());
            count += 200;
            i++;
        }
        myfile.close();
    }
    else cout << "unable to open file"; 
}

#endif //_USER_
