#include <iostream>

using namespace std;

// chain of responsibility

enum errorstates{lvl1 = 0,lvl2 = 1, lvl3 =2};

class errorReport
{
    errorstates state;
    public:
    errorReport(errorstates e):state(e){}
    void setstate(errorstates e)
    {
        state = e;
    }
    errorstates getstate()
    {
        return this->state;

    }

};

class error
{
protected:
    error *parent;
    errorstates state;

    public:

    error(errorstates es):state(es){}
    void setParent(error *p)
    {
        this->parent = p;
    }
    virtual void process(errorReport *er)=0;

};
class l1error:public error
{
public:
    l1error():error(lvl1){}
    void process(errorReport *er)
    {
        if(er->getstate() == state)
        {
            cout<<"processed at l1"<<endl;
        }else
        {
            cout<<"sending to parent"<<endl;

            parent->process(er);
        }
    }



};
class l2error:public error
{
public:
    l2error():error(lvl2){}
    void process(errorReport *er)
    {
        if(er->getstate() == state)
        {
            cout<<"processed at l2"<<endl;
        }else
        {
            cout<<"sending to parent"<<endl;

            parent->process(er);
        }
    }

};
class l3error:public error
{
public:
    l3error():error(lvl3){}
    void process(errorReport *er)
    {
        if(er->getstate() == state)
        {
            cout<<"processed at l3"<<endl;
        }else
        {
            cout<<"sending to parent"<<endl;

            parent->process(er);
        }
    }

};
int main()
{
    l1error *l1= new l1error();
    l2error *l2= new l2error();
    l3error *l3= new l3error();

    //creat chain
    l1->setParent(l2);
    l2->setParent(l3);

    //test for lvel1 error
    errorReport *e1 = new errorReport(lvl1);
    l1->process(e1);

    //test for level2 error
    e1->setstate(lvl3);
    l1->process(e1);

    return 0;
}