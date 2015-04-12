#include <string>
#include <thread>
#include <iostream>

using namespace std;

class CronTab
{
    public:
        CronTab(string user = "") : _user(user), _root(this_thread::get_id() == main_thread_id)
        {}

        void isRoot() { cout << "isRoot: " << (int)_root << endl; }
    private:
        string  _user;
        bool    _root;

        static thread::id main_thread_id;
};

thread::id CronTab::main_thread_id = this_thread::get_id();

int main()
{
    thread th([]{ 
        CronTab cTab;

        cTab.isRoot();
    });
    CronTab cTab1;

    cTab1.isRoot();

    th.join();
}
