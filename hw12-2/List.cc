#include "List.h"

template <class T>
List<T>::List()
{
    head = nullptr;
    m_num = 0;
}

template <class T>
List<T>::List(T* arr, int n_nodes)
{
    m_num = 0;
    for(int i=0; i < n_nodes; i++)
    {
        this->push_back(arr[i]);
    }
}

template <class T>
bool List<T>::isEmpty() const
{
    return m_num ? true : false;
}

template <class T>
void List<T>::insert_at(int idx, T data)
{
    ++this->m_num;
    if(!idx)
    {
        Node<T>* tmp = this->head;
        this->head = new Node<T>(data);
        this->head->next = tmp;
        return;
    }
    Node<T>* cur, *tmp;
    cur = this->head;
    for(int i=0;i<idx-1;i++)
    {
        cur = cur->next;
    }
    tmp = cur->next;
    cur->next = new Node<T>(data);
    cur->next->next = tmp;
}

template <class T>
void List<T>::remove_at(int idx)
{
    --m_num;
    if(!idx)
    {
        Node<T>* tmp = this->head->next;
        delete this->head;
        this->head = tmp;
        return;
    }
    Node<T>* cur, *tmp;
    cur = this->head;
    for(int i=0;i<idx-1;i++)
    {
        cur = cur->next;
    }
    tmp = cur->next;
    cur->next = cur->next->next;
    delete tmp;
}

template <class T>
void List<T>::pop_back()
{
    this->remove_at(this->m_num-1);
}

template <class T>
void List<T>::push_back(T val)
{
    this->insert_at(this->m_num, val);
}

template <class T>
void List<T>::pop_front()
{
    this->remove_at(0);
}

template <class T>
void List<T>::push_front(T val)
{
    this->insert_at(0, val);
}

template <class T>
std::ostream& operator<<(std::ostream& out, const List<T>& rhs)
{
    Node<T>* tmp = rhs.head;
    while(tmp!=nullptr)
    {
        out << tmp->data;
        tmp = tmp->next;
        if(tmp!=nullptr) out << ",";
    }
    return out;
}