#include <iostream>
#include <thread>
#include <sstream>

#define MAXNUM 1000
//const int MAXNUM = 10;
int num = 0;

std::string thrid_tostring(std::thread::id thrid ){
    std::stringstream ss;
    ss << thrid;
    return ss.str();
}


void fincr(){
    //std::cout << "#id = " << std::this_thread::get_id() << std::endl; //THIS VERSION MIGHT BE BROKEN BY ANOTHER THREAD
    std::cout << "#id = " + thrid_tostring(std::this_thread::get_id()) + "\n";
    while(1){
    //while(num < MAXNUM){
        //std::this_thread::sleep_for(1000ms);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        if(num < MAXNUM){
            std::cout << "Number of clients increased from " << num << " to " << num+2 << "\n";
            num += 2;
        }
    }
}
void fdecr(){
    //std::cout << "#id = " << std::this_thread::get_id() << std::endl; //THIS VERSION MIGHT BE BROKEN BY ANOTHER THREAD
    std::cout << "#id = " + thrid_tostring(std::this_thread::get_id()) + "\n";
    while(1){
    //while(num > 0){
        //std::this_thread::sleep_for(2000ms);
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        if(num > 0){
            std::cout << "Number of clients decreased from " << num << " to " << num-1 << "\n";
            num--;
        }
        //std::cout << "Number of clients decreased from " << num << " to " << num-1 << "\n";
        //num--;
    }
}

int main(){

    std::thread t1(fincr);
    std::thread t2(fdecr);
    t2.join();
    t1.join();
}
