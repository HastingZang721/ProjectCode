package demo;

import java.util.ArrayList;
import java.util.Arrays;

/*
arrays 与数组相关，提供大量静态方法
 */
public class Day7_Arrays {
    public static void main(String[] args) {
        int[] intarray={10,12,13,3,56,2};
        //将参数数组变成字符串（按照默认格式：【元素1，元素2，元素3】）
//        String instr= Arrays.toString(intarray);//省去for循环
//        System.out.println(instr);


       // sort 生序
//        Arrays.sort(intarray);
//        System.out.println(Arrays.toString(intarray));

        //使用Arrays  相关的API，将一个随机字符串的所有字符升序排列，并倒序打印

        String str="agsydbwudbsiamqidsndf";
        char[] chars=str.toCharArray();//先变成数组才能使用sort
        Arrays.sort(chars);
        for (int l = chars.length-1; l > 0; l--) {
            System.out.println(chars[l]);


        }

    }
}
