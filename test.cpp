#include <iostream>
#include <stdio.h>
#include <thread>
#include <mutex>
#include <pthread.h>
using namespace std;

int cnt = 20;
mutex m;

void t1()  //普通的函数，用来执行线程
 {
    while (cnt > 0){    
        lock_guard<mutex> lockGuard(m);
        
        if (cnt > 0){
            --cnt;
            cout << cnt << endl;
        }
    }
 }

 void t2()
 {
    while (cnt > 0){    
        lock_guard<mutex> lockGuard(m);
        
        if (cnt > 0){
            --cnt;
            cout << cnt << endl;
        }
    }
 }
 
int main()
{
    thread th1(t1);  //实例化一个线程对象th1，使用函数t1构造，然后该线程就开始执行了（t1()）
    thread th2(t2);

    th1.join(); //等待th1执行完
    th2.join(); //等待th2执行完
 
    cout << "here is main\n\n";
    return 0; 
} 