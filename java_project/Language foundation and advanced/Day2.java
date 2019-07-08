package com.Darkhorse.demo;
/*
方法因定义在类中，不能在方法中再定义方法
方法重载overload:参数个数不同，参数类型不同，参数多类型顺序不同
在调用语句时，println其实就是重载
 */
public class Day2 {
    public static void main(String[] args) {
        //System.out.println(isSame(3,4));
        myPrint(100);
        myPrint(100.2);







    }
    public static  void myPrint(byte m)
    {
        System.out.println(m);
    }
    public static  void myPrint(int m)
    {
        System.out.println(m);
    }
    public static  void myPrint(float m)
    {
        System.out.println(m);
    }
    public static  void myPrint(double m)
    {
        System.out.println(m);
    }







}
