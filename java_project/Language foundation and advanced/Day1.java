package com.Darkhorse.demo;


/*
方法是若干语句的功能集合

参数
返回值
 */
public class Day1 {
    public static void main(String[] args) {
        //Pr();
        int result;
        result=countSum(13,17);
        System.out.println("结果是"+result);


    }

/*方法
修饰符 返回值类型 方法名称（参数类型，参数名称）
{
方法体

return 返回值

}
 */

    public static void Pr() {
        for (int i = 0; i < 5; i++) {
            for (int i1 = 0; i1 < 20; i1++) {
                System.out.print("*");

            }
            System.out.println();


        }

    }

    //定义两数相加
    public static  int countSum(int a,int b)
    {
        System.out.println("方法Sum调用");
        int sum=a+b;
        return sum;
    }

