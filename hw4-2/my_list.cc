#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

StrArray split(const std::string& str, const std::string& delim) {
    std::string* string_list = new std::string[10];
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

class Item {
    public:
        Item() : m_age(0), m_subsize(0), m_next(nullptr) {
            // Do Nothing
        }

        ~Item() {
            if(m_next != nullptr) {
                delete m_next;
            }
        }

        Item(const std::string &str) : m_next(nullptr) {
            StrArray inpStr = split(str,":");
            m_name = inpStr[0];
            m_age = stoi(inpStr[1]);
            m_id = inpStr[2];
            StrArray subjects_ = split(inpStr[3],",");
            for(int i=0;i<subjects_.size();i++)
            {
                m_subjects.push_back(subjects_[i]);
            }
        }

        Item* create_item() {
            // 하나의 struct Item 형 변수를 동적할당한 후 이에 대한 pointer 를 리턴한다.
            Item* newItem = new Item;
            return newItem;
        }

        void insert_item(Item *item) {
            // head 에 포함되어 있는 prev_item 바로 뒤에 새로운 item 을 추가한다.
            m_next = item;
        }

        void PrintSubjects() const {
            for(int i=0;i<m_subjects.size();i++)
            {
                std::string subject = m_subjects[i];
                if(i) std::cout <<" & ";
                std::cout<<subject;
            }
            std::cout << std::endl;
        }
        
        const std::string& GetName() const {
            return m_name;
        }

        const std::string& GetID() const {
            return m_id;
        }

        Item* GetNextNode() const {
            return m_next;
        }

    private:
        std::string m_name;
        int m_age;
        std::string m_id;
        std::vector<std::string> m_subjects;
        size_t m_subsize;
        Item* m_next;
};

int main(void){ 
    std::ifstream fin;
    fin.open("input.txt");
    std::string buffer;
    Item tmphead;
    Item* node = &tmphead;
    int sw=0;
    while (fin.peek() != EOF) {
        getline(fin, buffer);
        Item* item = new Item(buffer);
        
        node->insert_item(item);
        node = item;
    }
    fin.close();
    
    Item* head = tmphead.GetNextNode();

    while(head!=nullptr)
    {
        if(head->GetID().substr(0,4) == "2013") {
            std::cout<<head->GetName();
            std::cout<<"("<<head->GetID()<<") : ";
            head->PrintSubjects();
        }
        head = head->GetNextNode();
    }
    return 0;
}