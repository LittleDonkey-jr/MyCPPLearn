#include <iostream>
#include <thread>
#include <chrono>
using namespace std;


static bool is_Finished = false;

void DoWork() {
    using namespace std::literals::chrono_literals; //等待时间的操作可以先using一个命名空间，为 1s 提供作用域
    while (!is_Finished) {
        std::cout << "hello" << std::endl;
        std::this_thread::sleep_for(1s);    //等待一秒
    }
}

class Timer
{
    public:
    std::chrono::time_point<std::chrono::high_resolution_clock> start,end;
    std::chrono::duration<float> duration;

    Timer();
    ~Timer();

};

Timer::Timer()
{
    start = std::chrono::high_resolution_clock::now();
}

Timer::~Timer()
{
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    
    float ms = duration.count() * 1000;
    std::cout << "Timer took " << ms << " ms" << std::endl;
}


class student
{
private:
    int num;
    int sex;
    int score;
public:
    char school[20] = "ChangAnUniversity\n";
    void init();
    student();
    student(int x,int y,int z);
    void display();
    ~student();
};

void student::init()
{
    num = 0;
    sex = 0;
    score = 0;
}

student::student()
{
    num = 1;
    sex = 1;
    score = 1;  

}
student::student(int x,int y,int z)
{
    num = x;
    sex = y;
    score = z;
}

void student::display()
{
    printf("%d\n",num);
    printf("%d\n",sex);
    printf("%d\n",score);
}
student::~student()
{
    printf("destroy the object\n");
}

int main()
{
    Timer timer;


    std::thread worker(DoWork); //开启多线程操作

    std::cin.get(); //此时工作线程在疯狂循环打印，而主线程此时被cin.get()阻塞
    is_Finished = true;// 让worker线程终止的条件，如果按下回车，则会修改该值，间接影响到另一个线程的工作。

    worker.join();  //join:等待工作线程结束后，才会执行接下来的操作

    printf("HelloWorld!\n");
    class student stu1;
    class student stu2(1,0,90);
    stu1.init();
    student *p = &stu1;
    stu1.display();
    p->display();
    printf("%s\n",p->school);

    p = &stu2;
    stu2.display();
    p->display();
    printf("%s\n",p->school);

    double d = 3.1415926;
    int x = static_cast<int>(d);
    student stu[3] = 
    {
        student(3,4,5),
        student(4,5,6),
        student(5,6,7)
    };
    std::cout<<"stu[0] is " << stu[0].school <<std::endl;
    return 0;
}
