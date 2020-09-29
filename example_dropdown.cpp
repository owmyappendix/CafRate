#include<iostream>
#include"sd_fun.h"

int main() {
  init();

  if (just_starting()) {  // initial setup
    yaml[0] = 0;
    append(yaml, R"(
Picker_1:
  style:
    width: 200
  pos: [10, 20, 30]
  indexPos: 40
)");
    write_at(mem, 10, "option A");
    write_at(mem, 20, "option B");
    write_at(mem, 30, "option C");
    write_at(mem, 40, "0");
    append(yaml, R"(
Text_1:
  pos: 50
  len: 10
)");
    write_at(mem, 50, "hello");
  } else { // check if the user picked something
    int i = was_picked(yaml, "Picker_1");
    write_at(mem, 50, i);
  }
  quit();
}
