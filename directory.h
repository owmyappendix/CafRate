#ifndef _DIRECTORY_
#define _DIRECTORY_
#include "sd_fun.h"
#include<iostream>
#include<fstream>
using namespace std;

//Contains classes.

//allows creation of stars. allows specifying position, number, scale, various types, and a group name.
class stars{
    int left, top, num, scale, startype;
    char* id;
    public:
    stars(int left, int top, int num, int scale, int startype, char* id) {
    for (int i = 0; i < num; ++i)
    {
        append(yaml, "\nImage_star_", id);
        append(yaml, i, ":\n");
        append(yaml, "  name: star", startype, ".png\n");
        append(yaml, "  style:\n");
        append(yaml, "    width: ", scale * 10, "\n");
        append(yaml, "    height: ", scale * 10, "\n");
        append(yaml, "    position: absolute\n");
        append(yaml, "    left: ", scale * 11 * i + left, "\n");
        append(yaml, "    top: ", top);
    }
}
};
//creates yaml for food items
class item{
    int id; 
    int mp; //memory position
    public:
    item(int id, int mp) {
        append(yaml, "\nText_i", id, ":\n");
        append(yaml, "  style:\n");
        append(yaml, "      color: gold\n");
        append(yaml, "      fontSize: 25\n");
        append(yaml, "      marginLeft: 50\n");
        append(yaml, "      marginTop: 20\n");
        append(yaml, "  pos: ", mp, "\n");
        append(yaml, "  len: 50\n");
    }
};
//creates yaml for food item descriptions
class itemDescription{
    int id, mp;
    public:
    itemDescription(int id, int mp) {
        append(yaml, "\nText_id", id, ":\n");
        append(yaml, "  style:\n");
        append(yaml, "      color: gold\n");
        append(yaml, "      fontSize: 15\n");
        append(yaml, "      marginLeft: 100\n");
        append(yaml, "      marginTop: 20\n");
        append(yaml, "  pos: ", mp, "\n");
        append(yaml, "  len: 100\n");
    }
};


#endif // _DIRECTORY_
