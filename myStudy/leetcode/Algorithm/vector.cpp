#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main(){

    vector<int> vec;    //定义与声明
    int n, t;   //定义数组长度和数组元素
    cin >> n;   //输入数组长度
    for(int i = 0; i < n; i++){
        cin >> t;   //赋值
        vec.push_back(t);   //将值传入进数组之中
    }

    sort(vec.begin(), vec.end());   //调用so rt()方法进行排序，从小到大排序

    vector<int>::iterator it;   //对vector创建一个指向它的迭代器
    //迭代器循环遍历数组
    for(it = vec.begin(); it!=vec.end();it++){
        cout << *it << ' ';
    }cout << endl;

    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << ' ';
    }cout << endl;

    //使用auto自动判断数组类型
    for(auto j:vec){
        cout << j << ' ';
    }cout << endl;
    //auto无法倒序遍历

    //使用auto判定迭代器指针类型，从后向前遍历数组
    for(auto it = vec.rbegin(); it != vec.rend(); it++){
        cout << *it << ' ';
    }cout << endl;

    reverse(vec.begin(),vec.end()); //反转数组

    vec.clear();    //清空数组

    //二维数组
    vector<vector<int> > num;   //创建一个二维数组，长度为0*0
    vector<vector<int> > num1(3,vector<int>(4,0));  //建立一个3*4的数组，且都被初始化为0
    vector<vector<int> > num2(3);   //创建一个3*0的数组

    //使用vector.erase()方法删除迭代器所指向的位置
    for(auto it = vec.begin(); it!=vec.end();){
        if(*it==4)  it = vec.erase(it); //erase()方法会直接删除目前的位置并且返回下一个位置的指针，需要用原it迭代器接收，不然原it迭代器所指向的位置被删除，无法继续遍历
    }

    if(vec.size()){
        //确保数组有值才能使用以下两种方法
        cout << vec.front() << endl;    //返回第一个元素
        cout << vec.back() << endl; //返回第二个元素
    }

    //查找
    auto m = lower_bound(vec.begin(), vec.end(), 3);    //找到一个大于等于3的数，返回它的指针。找不到返回end()指针
    cout << *m << endl;
    int p = lower_bound(vec.begin(), vec.end(), 3) - vec.begin();   //返回在vec容器内的下标，如果没有找到会返回数组长度
    cout << p << endl;

    vec.pop_back(); //删除末尾元素

    //去重
    //unique()函数会去除连续相同的元素，例77788777，只会删减成787，并将重复元素堆积至数组末尾。所以一般使用前先对容器进行排序，使用unique方法后再对后面进行删除
    sort(vec.begin(), vec.end());
//    unique(vec.begin(),vec.end());  //将重复项堆积至数组末尾，返回第一个重复的数字的指针
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    //返回下标用求出的指针减去开头的指针，即it - vec.begin()

    //插入元素
    //插入单个元素
    vec.insert(vec.begin()+1, 10);  //前面是位置，后面是元素
    //插入多个元素
    vec.insert(vec.begin(),2,5);    //第一个是位置，第二个是数量，第三个是元素
    //插入另外一个数组
    vector<int> vec2;
    vec.insert(vec.end(),vec2.begin(),vec2.end()); //第一个是插入位置，第二个是要插入的数组的第一个位置，第三个是插入数组的结尾

    return 0;
}
