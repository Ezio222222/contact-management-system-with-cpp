#include <iostream>
using namespace std;
class time
{ private:
    int hours,minutes,seconds;

  public:
  time(): hours(0),minutes(0),seconds(0)
  {}  

  time(int a,int b,int c): hours(a),minutes(b),seconds(c)
  {}

};
int main()
{  time t1;
    time t2(11,59,59);

    return 0;
}
