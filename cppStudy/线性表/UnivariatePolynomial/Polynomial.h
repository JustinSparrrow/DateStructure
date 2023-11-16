//
// Created by moqi on 2023/10/26.
//

#ifndef DATASTRUCTUREANDALGORITHMS_POLYNOMIAL_H
#define DATASTRUCTUREANDALGORITHMS_POLYNOMIAL_H
#include <iostream>
using namespace std;

class Polynomial{
private:
    struct polynomial{
        double coef;    //系数
        int expn;   //指数
    };
    polynomial *head;
public:
    int cmp(double a, double b);    //依a的指数值<、=或>b的指数值，分别返回-1、0、1

    void CreatePolyn(polynomial &P, int m); //输入m项的系数和指数，建立表示一元多项式的有序链表P

    void DestroyPolyn(polynomial &P);   //销毁一元多项式P

    void PrintPolyn(polynomial P);  //打印输出一元多项式P

    int PolynLength(polynomial P);  //返回一元多项式P中的项数

    void AddPolyn(polynomial &Pa, polynomial &Pb);  //完成多项式相加运算，即：Pa=Pa+Pb，并销毁一元多项式Pb

    void SubstractPolyn(polynomial &Pa, polynomial &Pb);    //完成多项式相减运算，即：Pa=Pa-Pb，并销毁一元多项式Pb

    void MultiplyPolyn(polynomial &Pa, polynomial &Pb); //完成多项式相乘运算，即Pa=Pa*Pb，并销毁一元多项式Pb
};

#endif //DATASTRUCTUREANDALGORITHMS_POLYNOMIAL_H
