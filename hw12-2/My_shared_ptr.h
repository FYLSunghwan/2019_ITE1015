#include <iostream>
using std::cout;

template <class T>
class My_shared_ptr
{
	private:
		T* m_obj;
		int* count;		
	public:
		My_shared_ptr() : m_obj(nullptr), count(nullptr)
        {
        }

		My_shared_ptr(T* obj) : m_obj(obj), count(new int)
        {
            *count = 1;
        }

		My_shared_ptr(const My_shared_ptr<T>& rhs) : m_obj(rhs.m_obj), count(rhs.count)
        {
            this->increase();
        }

		~My_shared_ptr(){
			if(getCount() > 0)
            {
                this->decrease();

                if (getCount() == 0)
                {
                    delete m_obj;
                    delete count;

                    m_obj = nullptr;
                    count = nullptr;

                    cout << "everything destroyed";
                }
            }
		}

		My_shared_ptr<T>& operator=(const My_shared_ptr<T>& rhs)
		{
            m_obj = rhs.m_obj;
            count = rhs.count;

            this->increase();
            
			return *this;
		}
		const T* get_m_obj(){ return m_obj;}

		int getCount()
        {
            if (m_obj == nullptr)
            {
                return 0;
            }

            return *count;
        }

		void increase()
        {
            ++(*count);
        }

		void decrease()
        {
            --(*count);
        }
};
