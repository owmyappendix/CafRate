#include "directory.h"
#include<iostream>
#include<fstream>
using namespace std;

//This file contains our functions that build each page and the items on the page. 

//basis for every page
void PageBase() {
    yaml[0] = 0;
    add_yaml("page_base.yaml");
}
//basis for the buttons that bring you to each line
void LineButton(char *line, int top, int left) {
    append(yaml, "\nButton_", line, "Line:\n");
    append(yaml, "    style:\n");
    append(yaml, "        position: absolute\n");
    append(yaml, "        top: ", 120 + 200 * top, "\n");
    append(yaml, "        left: ", 100 + 300 * left, "\n");
    append(yaml, "        width: 200\n");
    append(yaml, "        height: 150\n");
    append(yaml, "        backgroundColor: gold\n");
    append(yaml, "        borderRadius: 25\n");
    append(yaml, "    children: [Text_", line, "Line]\n");
    append(yaml, "    on_touch:\n");
    append(yaml, "        backgroundColor: rgb(255, 200, 0)\n");
}
//creates login page
void LoginPage() {
    yaml[0] = 0;

    add_yaml("login_base.yaml");

    write_at(mem, 1, "CafRate");//title for the Caf rate
    write_at(mem, 50, "what's good?");//slogan for the Caf rate
    
    add_yaml("login_button.yaml", {{"type", "login"}, {"top", 550}, {"mleft", 45}, {"pos", 100}, {"len", 10}});
    write_at(mem, 100, "Login");
    add_yaml("login_button.yaml", {{"type", "visitor"}, {"top", 600}, {"mleft", 17}, {"pos", 110}, {"len", 20}});
    write_at(mem, 110, "I am a visitor");

    add_yaml("login_textinput.yaml", {{"type", "username"}, {"top", 400}, {"secure", false}, {"pos", 320}});
    mem[320] = 0;

    add_yaml("login_textinput.yaml", {{"type", "password"}, {"top", 450}, {"secure", true}, {"pos", 420}});
    mem[420] = 0;
}
//creates home page
void HomePage() {
    PageBase();

    add_yaml("title.yaml", {{"fsize", 50}, {"mleft", 225}, {"mtop", 5}, {"pos", 1}, {"len", 5}});
    write_at(mem, 1, "Home"); // title

    add_yaml("settings_button.yaml");
    write_at(mem, 6, "settings"); // settings button

    LineButton("Home", 0, 0); // home line
    add_yaml("line_button.yaml", {{"line", "HomeLine"}, {"mleft", 17}, {"pos", 40}, {"len", 10}});
    write_at(mem, 40, "Home Line");
    stars(118, 205, 3, 3.5, 2, "home"); // stars

    LineButton("Grains", 0, 1); //grains line
    add_yaml("line_button.yaml", {{"line", "GrainsLine"}, {"mleft", 12}, {"pos", 50}, {"len", 15}});
    write_at(mem, 50, "Grains Line");
    stars(418, 205, 5, 3.5, 2, "grains"); // stars

    LineButton("Tortilla", 1, 0); // tortilla line
    add_yaml("line_button.yaml", {{"line", "TortillaLine"}, {"mleft", 8}, {"pos", 65}, {"len", 15}});
    write_at(mem, 65, "Tortilla Line");
    stars(118, 405, 5, 3.5, 2, "tortilla"); // stars

    LineButton("Bowls", 1, 1); // bowls line
    add_yaml("line_button.yaml", {{"line", "BowlsLine"}, {"mleft", 17}, {"pos", 80}, {"len", 15}});
    write_at(mem, 80, "Bowls Line");
    stars(418, 405, 4, 3.5, 2, "bowls"); // stars

    LineButton("Soup", 2, 0); // soup line
    add_yaml("line_button.yaml", {{"line", "SoupLine"}, {"mleft", 22}, {"pos", 95}, {"len", 10}});
    write_at(mem, 95, "Soup Line");
    stars(118, 605, 4, 3.5, 2, "soup"); // stars

    LineButton("Grill", 2, 1); // grill line
    add_yaml("line_button.yaml", {{"line", "GrillLine"}, {"mleft", 27}, {"pos", 105}, {"len", 15}});
    write_at(mem, 105, "Grill Line");
    stars(418, 605, 3, 3.5, 2, "grill"); // stars

    LineButton("Pasta", 3, 0); // pasta line
    add_yaml("line_button.yaml", {{"line", "PastaLine"}, {"mleft", 22}, {"pos", 120}, {"len", 15}});
    write_at(mem, 120, "Pasta Line");
    stars(118, 805, 4, 3.5, 2, "pasta"); // stars

    LineButton("Pizza", 3, 1); // pizza line
    add_yaml("line_button.yaml", {{"line", "PizzaLine"}, {"mleft", 22}, {"pos", 135}, {"len", 15}});
    write_at(mem, 135, "Pizza Line");
    stars(418, 805, 2, 3.5, 2, "pizza"); // stars
}
//creates settings page
void SettingsPage() {
    PageBase();

    add_yaml("title.yaml", {{"color", "black"}, {"fsize", 50}, {"mleft", 230}, {"mtop", 5}, {"pos", 470}, {"len", 30}});
    write_at(mem, 470, "CafRate");//title for the settings 

    add_yaml("home_button.yaml", {{"pos", 100}});
    write_at(mem, 100, "home");

}
//basis for the line pages
void LinePageBase(int i1, int id1, int i2, int id2, int i3, int id3, int i4, int id4, int i5, int id5, int i6, int id6, int i7, int id7, int i8, int id8, int i9, int id9, int i10, int id10, int i11, int id11, int i12, int id12) {
    PageBase();
    add_yaml("home_button.yaml", {{"pos", 20}});
    add_yaml("header.yaml", {{"pos", 1}, {"len", 9}});
    write_at(mem, 1, "CafRate");
    write_at(mem, 20, "home");

    add_yaml("divider.yaml");

    if (i1 == 1) { item(1,100);} //these lines call the item and itemdescription classes to create the necessary yaml based on how many items are in each line that day
    if (id1 == 1) {itemDescription(1,150);}
    if (i2 == 1) { item(2,250);}
    if (id2 == 1) {itemDescription(2,300);}
    if (i3 == 1) { item(3,400);}
    if (id3 == 1) {itemDescription(3,450);}
    if (i4 == 1) { item(4,550);}
    if (id4 == 1) {itemDescription(4,600);}
    if (i5 == 1) { item(5,700);}
    if (id5 == 1) {itemDescription(5,750);}
    if (i6 == 1) { item(6,850);}
    if (id6 == 1) {itemDescription(6,900);}

    add_yaml("divider2.yaml");

    if (i7 == 1) { item(7,1100);} 
    if (id7 == 1) {itemDescription(7,1150);}
    if (i8 == 1) { item(8,1250);}
    if (id8 == 1) {itemDescription(8,1300);}
    if (i9 == 1) { item(9,1400);}
    if (id9 == 1) {itemDescription(9,1450);}
    if (i10 == 1) { item(10,1550);}
    if (id10 == 1) {itemDescription(10,1600);}
    if (i11 == 1) { item(11,1700);}
    if (id11 == 1) {itemDescription(11,1750);}
    if (i12 == 1) { item(12,1850);}
    if (id12 == 1) {itemDescription(12,1900);}

    add_yaml("reviews_button.yaml");
    write_at(mem, 2000, "view reviews");

    // i1 = 100, id1 = 150, i2 = 250, id2 = 300, i3 = 400, id3 = 450, i4 = 550, id4 = 600, i5 = 700, id5 = 750, i6 = 850, id6 = 900
    // i7 = 1100, id7 = 1150, i8 = 1250, id8 = 1300, i9 = 1400, id9 = 1450, i10 = 1550, id10 = 1600, i11 = 1700, id11 = 1750, i12 = 1850, id12 = 1900
}
//each individual line function specifies which items are needed, stars, and writes the menu items
void Home() {
    LinePageBase(1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0);

    stars(135, 200, 3, 8, 1, "HL");

    add_yaml("title.yaml", {{"color", "gold"}, {"fsize", 70}, {"mleft", 240}, {"mtop", 50}, {"pos", 50}, {"len", 20}});
    write_at(mem, 50, "Home");

    //lunch
    write_at(mem, 100, "Shrimp and Calamari Po'boy");
    write_at(mem, 150, "chipotle tartar sauce, new french rolls");
    write_at(mem, 250, "Lemon Pepper Coleslaw");
    //dinner
    write_at(mem, 1100, "Roasted Salmon Steaks");
    write_at(mem, 1250, "Wild Rice Pilaf with Cranberries");
    write_at(mem, 1400, "Baby Green Beans with Brown Garlic Butter");
}
void Grains() {
    yaml[0] = 0;
    LinePageBase(1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0);

    stars(135, 200, 5, 8, 1, "GL");

    add_yaml("title.yaml", {{"color", "gold"}, {"fsize", 70}, {"mleft", 225}, {"mtop", 50}, {"pos", 10}, {"len", 50}});
    write_at(mem, 10, "Grains");

    //lunch
    write_at(mem, 100, "Morroccan Chickpea and Potato Tagine");
    write_at(mem, 250, "Steamed Brown Rice");
    write_at(mem, 400, "Spring Berry and Grain Salad");
    write_at(mem, 450, "wheat berries, mixed greens, red onion, red and black berries, parsley, green onion, vinaigrette");
    //dinner
    write_at(mem, 1100, "Morroccan Chickpea and Potato Tagine");
    write_at(mem, 1250, "Steamed Brown Rice");
    write_at(mem, 1400, "Spring Berry and Grain Salad");
    write_at(mem, 1450, "wheat berries, mixed greens, red onion, red and black berries, parsley, green onion, vinaigrette");

}
void Tortilla() {
    yaml[0] = 0;
    LinePageBase(1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0);

    stars(135, 200, 5, 8, 1, "TL");

    add_yaml("title.yaml", {{"color", "gold"}, {"fsize", 70}, {"mleft", 215}, {"mtop", 50}, {"pos", 10}, {"len", 50}});
    write_at(mem, 10, "Tortilla");

    //lunch
    write_at(mem, 100, "Taco and Burrito Bar");
    write_at(mem, 150, "latin rice, cazuela style beans, selection of toppings and salsas");
    write_at(mem, 250, "Chicken Tinga");
    write_at(mem, 400, "Taco Beef");
    //dinner
    write_at(mem, 1100, "Taco and Burrito Bar");
    write_at(mem, 1150, "latin rice, cazuela style beans, selection of toppings and salsas");
    write_at(mem, 1250, "Chicken Tinga");
    write_at(mem, 1400, "Taco Beef");
}
void Bowls() {
    yaml[0] = 0;
    LinePageBase(1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0);

    stars(135, 200, 4, 8, 1, "BL");

    add_yaml("title.yaml", {{"color", "gold"}, {"fsize", 70}, {"mleft", 240}, {"mtop", 50}, {"pos", 10}, {"len", 50}});
    write_at(mem, 10, "Bowls");

    //lunch
    write_at(mem, 100, "Steamed Rice");
    write_at(mem, 250, "Kung Pao Beef");
    write_at(mem, 300, "spicy beef");
    write_at(mem, 400, "Kung Pao Tofu");
    write_at(mem, 450, "tofu with broccoli and scallion sticks");
    write_at(mem, 550, "Egg Drop Soup");
    //dinner
    write_at(mem, 1100, "Steamed Rice");
    write_at(mem, 1250, "Kung Pao Beef");
    write_at(mem, 1300, "spicy beef");
    write_at(mem, 1400, "Kung Pao Tofu");
    write_at(mem, 1450, "tofu with broccoli and scallion sticks");
    write_at(mem, 1550, "Egg Drop Soup");
}
void Soup() {
    yaml[0] = 0;
    LinePageBase(1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);

    stars(135, 200, 4, 8, 1, "SL");

    add_yaml("title.yaml", {{"color", "gold"}, {"fsize", 70}, {"mleft", 240}, {"mtop", 50}, {"pos", 10}, {"len", 50}});
    write_at(mem, 10, "Soup");

    //lunch
    write_at(mem, 100, "New England Clam Chowder");
    write_at(mem, 250, "Vegetable Lentil Soup");
    //dinner
    write_at(mem, 1100, "New England Clam Chowder");
    write_at(mem, 1250, "Vegetable Lentil Soup");
}
void Grill() {
    yaml[0] = 0;
    LinePageBase(1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0);

    stars(135, 200, 3, 8, 1, "GLL");

    add_yaml("title.yaml", {{"color", "gold"}, {"fsize", 70}, {"mleft", 260}, {"mtop", 50}, {"pos", 10}, {"len", 50}});
    write_at(mem, 10, "Grill");

    //lunch
    write_at(mem, 100, "All Natural Beef Burger");
    write_at(mem, 250, "Marinated Chicken Breast");
    write_at(mem, 400, "Chipotle Black Bean Burger");
    write_at(mem, 550, "Fries");
    write_at(mem, 700, "Sweet Potato Fries");
    write_at(mem, 850, "American Classic Hot Dog");
    //dinner
    write_at(mem, 1100, "All Natural Beef Burger");
    write_at(mem, 1250, "Marinated Chicken Breast");
    write_at(mem, 1400, "Chipotle Black Bean Burger");
    write_at(mem, 1550, "Fries");
    write_at(mem, 1700, "Sweet Potato Fries");
    write_at(mem, 1850, "American Classic Hot Dog");
}
void Pasta() {
    yaml[0] = 0;
    LinePageBase(1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0);

    stars(135, 200, 4, 8, 1, "PL");

    add_yaml("title.yaml", {{"color", "gold"}, {"fsize", 70}, {"mleft", 240}, {"mtop", 50}, {"pos", 10}, {"len", 50}});
    write_at(mem, 10, "Pasta");

    //lunch
    write_at(mem, 100, "Classic Marinara Sauce");
    write_at(mem, 250, "Alfredo Sauce");
    write_at(mem, 300, "plainview milk products cooperative");
    write_at(mem, 400, "Fresh Roasted Vegetables");
    write_at(mem, 550, "Puttanesca Sauce");
    //dinner
    write_at(mem, 1100, "Classic Marinara Sauce");
    write_at(mem, 1250, "Alfredo Sauce");
    write_at(mem, 1300, "plainview milk products cooperative");
    write_at(mem, 1400, "Fresh Roasted Vegetables");
    write_at(mem, 1550, "Puttanesca Sauce");
}
void Pizza() {
    yaml[0] = 0;
    LinePageBase(1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0);

    stars(135, 200, 2, 8, 1, "PZL");

    add_yaml("title.yaml", {{"color", "gold"}, {"fsize", 70}, {"mleft", 240}, {"mtop", 50}, {"pos", 10}, {"len", 50}});
    write_at(mem, 10, "Pizza");

    //lunch
    write_at(mem, 100, "Pepperoni Pizza");
    write_at(mem, 150, "house pizza sauce topped with a five cheese blend and spicy pepperoni");
    write_at(mem, 250, "Cheese Pizza");
    write_at(mem, 300, "house pizza sauce topped with a five cheese blend");
    write_at(mem, 400, "Minnesota Margherita");
    write_at(mem, 450, "basic tomato sauce, cheese curds, basil");
    //dinner
    write_at(mem, 1100, "Pepperoni Pizza");
    write_at(mem, 1150, "house pizza sauce topped with a five cheese blend and spicy pepperoni");
    write_at(mem, 1250, "Cheese Pizza");
    write_at(mem, 1300, "house pizza sauce topped with a five cheese blend");
    write_at(mem, 1400, "Minnesota Margherita");
    write_at(mem, 1450, "basic tomato sauce, cheese curds, basil");
}
//takes arguments of number and types of stars chosen for creating a review and reloads page to display this.
void reviewpage(int num, int type)
{
        PageBase();

        add_yaml("title.yaml", {{"color", "black"}, {"fsize", 50}, {"mleft", 210}, {"mtop", 5}, {"pos", 1}, {"len", 9}});
        write_at(mem, 1, "Review"); // title for page

        add_yaml("home_button.yaml", {{"pos", 10}});
        write_at(mem, 10, "back"); // back button

        add_yaml("review_writeup.yaml");
        write_at(mem, 20, "Line: "); // line drop down label
        write_at(mem, 40, "Comments: "); // comment text box label
        write_at(mem, 60, "post your review"); // review writeup button

        add_yaml("drop_down.yaml");   // drop down menu for lines
        write_at(mem, 85, "choose line");
        write_at(mem, 100, "Home Line");
        write_at(mem, 115, "Grains Line");
        write_at(mem, 130, "Tortilla Line");
        write_at(mem, 145, "Bowls Line");
        write_at(mem, 160, "Soup Line");
        write_at(mem, 175, "Grill Line");
        write_at(mem, 190, "Pasta Line");
        write_at(mem, 205, "Pizza Line");
        write_at(mem, 220, "0");
        stars(200, 150, num, 7, type, "review");
        mem[340] = 0; 
        mem[500] = num; //stores number of stars selected

        add_yaml("star_button.yaml", {{"left", 200}, {"num", 1}});
        add_yaml("star_button.yaml", {{"left", 277}, {"num", 2}});
        add_yaml("star_button.yaml", {{"left", 354}, {"num", 3}});
        add_yaml("star_button.yaml", {{"left", 431}, {"num", 4}});
        add_yaml("star_button.yaml", {{"left", 508}, {"num", 5}});
}
//allows selection of stars
void starbuttons() //reloads reviewpage with number of stars selected and sets snum to this value
    {
    if (was_pressed(yaml, "Button_star_1")) { reviewpage(1,1); } 
    if (was_pressed(yaml, "Button_star_2")) { reviewpage(2,1); }
    if (was_pressed(yaml, "Button_star_3")) { reviewpage(3,1); }
    if (was_pressed(yaml, "Button_star_4")) { reviewpage(4,1); }
    if (was_pressed(yaml, "Button_star_5")) { reviewpage(5,1); }
}

void viewreviews() {
    PageBase();

        add_yaml("title.yaml", {{"color", "black"}, {"fsize", 50}, {"mleft", 210}, {"mtop", 5}, {"pos", 1}, {"len", 9}});
        write_at(mem, 1, "Reviews");

        add_yaml("divider3.yaml");

        add_yaml("home_button.yaml", {{"pos", 10}});
        write_at(mem, 10, "home"); // back button

}
