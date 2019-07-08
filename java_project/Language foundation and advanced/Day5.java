package com.Darkhorse.demo;

/*
API :常用类、
Scanner:可以实现从键盘输入数据，到程序当中
只有java.lang包下的内容不需要导，其他都需要
 */

import java.util.Scanner;


public class Day5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        //从键盘上获取一个int :int num=sc.nextIn();
        //从键盘上输入一个字符串： String str=sc.next();


        int num = sc.nextInt();
        int sum=0;

        System.out.println("输入：" + num+"个数据");
        System.out.println("请输入数值====");
        int[] array1=new int[num];

        for (int i = 0; i < num; i++)
        {
            array1[i]=sc.nextInt();
            sum+=array1[i];

        }
        System.out.println("总和为"+sum);

//        String str=sc.next();
//        System.out.println("输入的数据："+str);




    }

}
