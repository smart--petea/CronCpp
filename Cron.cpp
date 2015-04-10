#include <fstream>
#include <string>
#include <exception>
using namespace std;

class Cron
{
    public:
        Cron(string cronNameFile) : _cronNameFile(cronNameFile), _cronOutFile(cronNameFile)
        {
            if(! _cronOutFile.is_open()) throw "unable to open file";
        }

    private:
        string      _cronNameFile;
        ifstream    _cronInFile;
        ofstream    _cronOutFile;
};
