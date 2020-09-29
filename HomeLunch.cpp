#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

void readHomelunch(){
    string line;
        ifstream Txtfile("menu.txt");
        if (Txtfile.is_open())
        {
            while (Txtfile.good())
            {
                getline (Txtfile,line);
                    cout << line << endl;
            }
            Txtfile.close();
        }
        else cout <<"unable to open file"<<endl;
}    
void readUsername(){
    vector<string> tmp;
    string usertxt;
    char * username;
        ifstream userfile("menu.txt");
        if (userfile.is_open())
        {
            while (userfile.good())
            {
                getline (userfile,usertxt);
                    tmp.push_back(usertxt);
            }
            userfile.close();
        }
        else cout <<"unable to open file"<<endl;
        //cout<<"enter username"<<endl;
        int len;
        for (len=0; mem[320 + len] != '\0'; len++);
        username = new char[len+1];
        for(int i = 0; i < len +1; i ++) {
            username[i] = mem[320+i];
        }
        for(string x:tmp){
            if(x==username){
                cout<<"welcome\n";
                break;
            }
        }
}
void readinComment(){
    vector<string> tmp;
    ofstream myfile;
    char * Comment;
    int len;
    myfile.open ("Comments.txt");
    Comment = (char *) &mem[340];
    myfile<<Comment;
    myfile.close();
}
int main(){
    //readHomelunch();
    readUsername();
    readinComment();
}


