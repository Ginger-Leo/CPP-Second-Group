#include <iostream>
#include <cstdlib>
#include <ctime>

class Base 
{
    private:
        Base();
        virtual ~Base();
    protected:

    public:
        Base *generate(void);
        void identify(Base& p);
        void identify(Base* p);

};