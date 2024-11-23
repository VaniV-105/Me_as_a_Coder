#include <iostream>
using namespace std;
class ball{
    private:
        float area;
    public:
        void setarea(int radius){
            area = 3.14 * radius * radius;
        }
        float getarea(){
            return area;
        }
};
int main(){
    ball obj;
    obj.setarea(6);
    cout <<"Area of ball is "<<endl;
    cout << obj.getarea();
    return 0;
}