#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h> // strtok
using namespace std;

class StrArray {
    public:
        StrArray(std::string *inpPtr, size_t size) : m_ptr(inpPtr), m_size(size) {
            // Do Nothing
        }

        ~StrArray() {
            delete[] m_ptr;
        }

        std::string& operator[](size_t idx) {
            return m_ptr[idx];
        }
        
        size_t size() const {
            return m_size;
        }

    private:
        std::string* m_ptr;
        size_t m_size;
};

StrArray split(const string& str, const string& delim) {
    string* string_list = new string[10];
    size_t idx = 0;
    size_t nextStart = 0;

    while (true) {
        size_t delimPos = str.find(delim, nextStart);
        if(delimPos == std::string::npos) {
            string_list[idx] = str.substr(nextStart);
            break;
        }
        string_list[idx] = str.substr(nextStart, delimPos-nextStart);
        ++idx;
        nextStart = delimPos+1;
    }
    return StrArray(string_list, idx+1);
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
        StrArray inpStr = split(buffer,":");
        item->name = inpStr[0];
        item->age = stoi(inpStr[1]);
        item->id = inpStr[2];
        StrArray subjects_ = split(inpStr[3],",");
        for(int i=0;i<subjects_.size();i++)
        {
            item->subjects.push_back(subjects_[i]);
        }
        insert_item(node, item);
        node = node->next;
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