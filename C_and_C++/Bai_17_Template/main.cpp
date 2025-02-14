#include <iostream>

using namespace std;


/* template <class var> có thể khai báo như này cũm giống như bên dưới*/

/* template function */
template <typename var, typename var1>
var tong(var a, var1 b){
    return var(a+b);
}

/* template class */
template <typename type>
class SensorData{
    private:
        type data;
        int a;
    public:
        SensorData(type initData) : data(initData), a(10){} // giống với data = initData
        void updateData(type newData){
            data = newData;
        };
        type getData() const{
            return data;
        }

};

int main(){

    SensorData<double> temperatureSensor(10.5);
    temperatureSensor.updateData(30.5);
    cout<<"Nhiet do: "<<temperatureSensor.getData()<<endl;

    SensorData<double> speedSensor(5);
    speedSensor.updateData(6.6);
    cout<<"Toc do: "<<speedSensor.getData()<<endl;

    printf("%f", tong(5,10.6)); // nếu viết như này nó sẽ bị xung đột
    return 0;
}