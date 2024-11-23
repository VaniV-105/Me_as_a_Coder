#include <iostream>
using namespace std;
#include <string>
class GradeBook{
    private:
        string coursename;
    public:
        void setcoursename(string coursename){
            this->coursename=coursename;
        }
        void display(){
            cout<<"The coursename is "<<coursename<<endl;
        }
};
int main(){
    GradeBook gb;
    gb.setcoursename("C++");
    gb.display();
    return 0;
}