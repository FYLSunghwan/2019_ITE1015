#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h> // strtok
using namespace std;

string* split(const string& str, const string& delim) {
    string* string_list = new string[10];
    int idx = 0;
    char * token = strtok(const_cast<char*>(str.c_str()), delim.c_str());
    while (token != NULL) {
        string_list[idx] = token;
        token = strtok(NULL, delim.c_str());
        ++idx;
    }
    return string_list;
}

struct Item {
    string name;
    int age;
    string id;
    vector<string> subjects;
    Item* next = nullptr;
};

struct Item* create_item() {
// 하나의 struct Item 형 변수를 동적할당한 후 이에 대한 pointer 를 리턴한다.
    Item* newItem = new Item;
    return newItem;
}

void insert_item(struct Item *prev_item, struct Item *item) {
// head 에 포함되어 있는 prev_item 바로 뒤에 새로운 item 을 추가한다.
    prev_item->next = item;
}

int deb;

int main(void){ 
    ifstream fin;
    fin.open("input.txt");
    string buffer;
    Item* head = nullptr;
    Item* node = nullptr;
    int sw=0;
    while (fin.peek() != EOF) {
        Item* item = create_item();
        if(!sw) {
            node = head = item;
            sw=1;
        }
        getline(fin, buffer);
        string* inpStr = split(buffer,":");
        item->name = *inpStr;
        item->age = stoi(inpStr[1]);
        item->id = inpStr[2];
        string* subjects = split(inpStr[3],",");
        for(int i=0;!subjects[i].empty();i++)
        {
            item->subjects.push_back(subjects[i]);
        }
        insert_item(node, item);
        node = node->next;
        if(inpStr!=nullptr) delete[] inpStr;
    }
    
    while(head!=nullptr)
    {
        if(head->id.substr(0,4) == "2013") {
            cout<<head->name;
            cout<<"("<<head->id<<") : ";
            for(int i=0;i<head->subjects.size();i++)
            {
                string subject = head->subjects[i];
                if(i) cout <<" & ";
                cout<<subject;
            }
            cout << endl;
        }
        Item* tmp = head->next;
        if(head!= nullptr) delete head;
        head = tmp;
    }
    fin.close();
    return 0;
}