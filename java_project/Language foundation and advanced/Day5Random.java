package com.Darkhorse.demo;

import java.util.Random;

/*
Random 用来生成随机数字
导包
创建
使用
 */
public class Day5Random {
    public static void main(String[] args) {
        //
        Random r=new Random();
        int num=r.nextInt();
        System.out.println("数值为："+num);
        int num2=r.nextInt(3);
        System.out.println("数值为"+num2);
    }
}
