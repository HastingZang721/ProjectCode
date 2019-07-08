package com.Darkhorse.demo;

import java.util.ArrayList;
import java.util.Random;

public class Day5Array {
    public static void main(String[] args) {
        //创建长度为3的数组
//        Person[] array=new Person[3];
//        System.out.println(array[0]);

        /*
        Arraylist 长度可变

         */
        //创建ArrayList集合，集合的名称是list,里面装的全是String字符串类型的数据
//        ArrayList<String> list=new ArrayList<>();
//        list.add("112");
//        list.add("2321");
//        list.add("zang");
//        System.out.println(list);
//        String name=list.get(2);
//        System.out.println("second is "+name);
//        list.remove(2);
//        System.out.println(list);
//        int len=list.size();
//        System.out.println("集合的长度"+len);
//        ArrayList<String> list=new ArrayList<>();
//        //范型只能是引用类型
//        //若想要基本类型，需要加入包装类java lang
//        ArrayList<Integer>list1=new ArrayList<>();
//        list1.add(100);
//        list1.add(120);
//        System.out.println(list1);

//        ArrayList<Integer>list=new ArrayList<>();
//        for (int i = 0; i < 6; i++) {
//            Random r=new Random();
//            int num=r.nextInt(33);//0-32
//            int result=num+1;
//            list.add(result);
//
//        }
//        for (int i=0;i<list.size();i++)
//        {
//            int num2=list.get(i);
//            System.out.println(num2);
//        }
//

//        ArrayList<student> list=new ArrayList<>();
//        student one=new student("hong",2);
//        student two =new student("zza",23);
//        student three=new student("dq1",34);
//        list.add(one);
//        list.add(two);
//        list.add(three);
//        ArrayList<String>list=new ArrayList<>();
//        list.add("zang");
//        list.add("heo");
//        list.add("der");
//        System.out.println(list);
//        PrintMethod(list);
//
//

        ArrayList<Integer>listB=new ArrayList<>();
        Random r=new Random();
        for (int i = 0; i < 20; i++) {
           listB.add(r.nextInt(100));

        }
        System.out.println(listB);
        System.out.println("=====");
        ArrayList<Integer> Smlist=new ArrayList<>();
        Smlist=SmallEvenlist(listB);
        System.out.println(Smlist);





    }
//    public  static  void PrintMethod(ArrayList<String> list){
//        System.out.print("{");
//        for (int i = 0; i < list.size(); i++) {
//
//            String ns=list.get(i);
//            if(i==list.size()-1)
//                System.out.print(ns+"}");
//            else
//                System.out.print(ns+"@");
//
//}
    public static  ArrayList<Integer> SmallEvenlist(ArrayList<Integer> list){
        //进大集合后 筛选出小集合都是偶数
        ArrayList<Integer> listsmall=new ArrayList<>();
        for (int i = 0; i < list.size(); i++) {
            int num=list.get(i);
            if(num%2==0)
            {
                listsmall.add(num);
            }


        }
        return listsmall;

    }

            



}
