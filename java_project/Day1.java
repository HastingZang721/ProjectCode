package hasting.demo;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

//面向对象
/*

面向对象 ：遇到问题找具有解决这个问题的对象，调用这个对象的方法
先有类 才能实例化对象

基本数据类型
整数型 浮点 字符 布尔；

引用数据类型
类 数组 接口；



 */
//1-1-5-01数据类型转换
//自动类型转换，：数据范围需要符合从小到大

//强制类型转化:一般不推荐使用，可能会发生精度损失；或者数据溢出
//byte char short 都可以发生数学运算

//public class HelloWorld{
//    public static void main(String[] args){
//        //int num1=100L;//Error:(27, 18) java: 不兼容的类型: 从long转换到int可能会有损失
//
////        int num1=(int)100L;
////        System.out.println(num1);
//
////        int num2=(int )3.5;
//
////        System.out.println(num2);
//
//        char zifu='A';
//        System.out.println(zifu+1);
//
//
//    }
//}
//////////////////////////////////////////运算符/////////////////////
/*
运算符 加
"+"的常见用法
数字 ：加法
char 先会被提升int ,然后再计算
字符串：String（首字母大写），并不是关键字，表示连接操作
任何数字与字符串连接 都会变成字符串
 */
/*
1-7方法入门
方法：将功能抽象出来
定义：public static void 方法名称（）{};命名方法：
调用：

1-8 java9的新特性
j-shell脚本：没有类和方法 可以写出结果
编译器的两点优化：没有超过左侧范围，编译器会自动补上强转
编译器常量优化： 表达式右侧全部是常量

1-9选择结构switch if 语句
continue :跳过当前次循环


 */
public class HelloWorld{
    public static void main(String[] args){
        int i=10;
        while(i>0){
            System.out.println("hello"+i);
            --i;
            

        }

    }

}
