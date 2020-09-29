#include"user.h"
#include"directory.h"
#include"directory.cpp"
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

//This file contains main. Main mostly contains if statements that check what buttons were pushed and calls the necessary functions or uses add_yaml.

int main() {
    init("store input");

    if (just_starting() || was_pressed(yaml, "Button_Logout")) {
        LoginPage();
    }
// Beginning of Home page
    else if (readUsername() && readPassword() && was_pressed(yaml, "Button_login") || was_pressed(yaml, "Button_home")) {
        HomePage();

        add_yaml("writereview_button.yaml");
        write_at(mem, 15, "write your own review"); // review writeup button
    }
// alternate Home page for visitors
    else if (was_pressed(yaml, "Button_visitor")) { HomePage(); }
// Invalid Usernames/Passwords
    else if (was_pressed(yaml, "Button_login")) { cerr << "Invalid Username or password, Retry!" << endl; }
// Settings
    else if (was_pressed(yaml, "Button_Settings") || was_pressed(yaml, "Button_settingsBack")) {
        SettingsPage();

        add_yaml("settings_page.yaml");
        write_at(mem, 500, "logout");
        write_at(mem, 550, "notifications"); 
        write_at(mem, 570, "on");
        write_at(mem, 580, "off");
        write_at(mem, 590, "privacy policy");
        write_at(mem, 610, "edit my review");
        write_at(mem, 630, "contact us"); 
    }
// settings: notifications - on vs off button
    if (was_pressed(yaml, "Button_On")) {
        SettingsPage();

        add_yaml("settings_page.yaml");
        write_at(mem, 500, "logout");
        write_at(mem, 550, "notifications"); 
        write_at(mem, 570, "on");
        write_at(mem, 580, "off");
        write_at(mem, 590, "privacy policy");
        write_at(mem, 610, "edit my review");
        write_at(mem, 630, "contact us"); 
    }
    if (was_pressed(yaml, "Button_Off")) {
        SettingsPage();

        add_yaml("settings2_page.yaml");
        write_at(mem, 500, "logout");
        write_at(mem, 550, "notifications"); 
        write_at(mem, 570, "on");
        write_at(mem, 580, "off");
        write_at(mem, 590, "privacy policy");
        write_at(mem, 610, "edit my review");
        write_at(mem, 630, "contact us"); 
    }
// settings: privacy policy
    if (was_pressed(yaml, "Button_privacyPolicy")) {
        PageBase();
        add_yaml("title.yaml", {{"color", "black"}, {"fsize", 50}, {"mleft", 230}, {"mtop", 5}, {"pos", 1}, {"len", 30}});
        write_at(mem, 1, "Privacy Policy");
        add_yaml("settings_back_button.yaml", {{"pos", 40}});
        write_at(mem, 40, "back");

        add_yaml("privacy_policy.yaml");
        write_at(mem, 100, "CafRate does not collect or store any personal information or passwords.");
        write_at(mem, 300, "We are not responsible for damage that may be done if personal security information is entered onto this website.");
        write_at(mem, 500, "It has absolutely NO security.");
    }
// settings: contact us
    if (was_pressed(yaml, "Button_ContactUs")) {
        PageBase();
        add_yaml("title.yaml", {{"color", "black"}, {"fsize", 50}, {"mleft", 230}, {"mtop", 5}, {"pos", 470}, {"len", 30}});
        write_at(mem, 470, "Contact Us");
        add_yaml("settings_back_button.yaml", {{"pos", 100}});
        write_at(mem, 100, "back");

        add_yaml("contact_us.yaml");
        write_at(mem, 200, "Erica Meyers: meyers2@stolaf.edu");
        write_at(mem, 250, "Sean Daly: daly1@stolaf.edu");
        write_at(mem, 300, "Dagmawe Haileslassie: hailes1@stolaf.edu");
    }
// Review Writeup
    else if (was_pressed(yaml, "Button_WriteReview")) {
        reviewpage(5,3);
    }
    starbuttons();
// Posting a Review
    if(was_pressed(yaml, "Button_PostReview")){
        viewreviews();

        writeinComment();

        readcomment();
    }
    if (was_pressed(yaml, "Button_ViewReviews")) {
        viewreviews();

        readcomment();
    }
// Home Line
    else if (was_pressed(yaml, "Button_HomeLine")) { Home(); }
// Grains Line
    else if (was_pressed(yaml, "Button_GrainsLine")) { Grains(); }
// Tortilla Line
    else if (was_pressed(yaml, "Button_TortillaLine")) { Tortilla(); }
// Bowls Line
    else if (was_pressed(yaml, "Button_BowlsLine")) { Bowls(); }
// Soup Line page
    else if (was_pressed(yaml, "Button_SoupLine")) { Soup(); }
// Grill Line page
    else if (was_pressed(yaml, "Button_GrillLine")) { Grill(); }
// Pasta Line page
    else if (was_pressed(yaml, "Button_PastaLine")) { Pasta(); }
// Pizza Line page
    else if (was_pressed(yaml, "Button_PizzaLine")) { Pizza(); }


    quit();
}
