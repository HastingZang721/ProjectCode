package com.Darkhorse.demo;

//数组
/*
引用数据类型
容器；数组中多数据存储，但是数据类型必须统一
程序运行期间不能改变长度
 */
public class Day3 {
    public static void main(String[] args) {
//        //动态创建
//
//        int[] arrayA=new int[300];
//        double[] ayrray1= new double[10];
//        String[] array2=new String[100];
//
//
//        //静态创建
//        int[] arrayB= new int[]{1,2,3};
//
//        //省略格式;不可拆分
//        int[] arr3={1,2,4};

        //获取数组中数据
//        int[] array1={10,20,30};
//        System.out.println(array1[1]);//[I@61bbe9ba 内存地址哈希值
        //访问数组值并且赋值
//
//        int[] array=new int[3];
//        System.out.println(array);
//        System.out.println(array[0]);//动态初始化数组的时候，整数元素默认为0,bool 默认false
//        System.out.println(array[1]);
//        System.out.println(array[2]);
//
//        array[1]=12;
//        System.out.println(array[1]);

        //java的内存划分
        /*
        棧：方法中的局部变量（真正的方法运行在此）
        堆：new出来的都在堆中，都有自己的地址值
        方法区：.class 文件（main 自定义）
        本地方法棧
        寄存器区
         */
//
//        int[] array1=new int[3];
//        int[] array3=array1;//两个引用（左边的名字）指向同一个数组
//        System.out.println(array1);
//        System.out.println(array3);

        //数组索引越界异常
        //int[] array={1,12,13};
        //System.out.println(array[3]);//java.lang.ArrayIndexOutOfBoundsException:

        //空指针异常;
//        int[] array1=null;
//        //array1=new int[]{1,2,3}
//        System.out.println(array1[0]);//NullPointerException

        //获取数组的长度;数组一旦创建，程序运行期间 长度不可改变

        int[] arrayA = new int[3];
        int[] arrayB = new int[]{10, 9, 7, 3, 21, 34, 2, 1, 4, 2};
//        System.out.println(arrayB.length);
//        System.out.println(arrayA.length);
        //遍历数组 求最值
//        int Max = arrayB[0];
//        int Min = arrayB[0];
//
//        for (int i = 0; i < arrayB.length; i++) {
//            // System.out.println(arrayB[i]);
//            if (arrayB[i] > Max) {
//                //int temp;
//                Max=arrayB[i];
//
//            }
//            Min = Min < arrayB[i] ? Min : arrayB[i];
//        }
//        System.out.println("Max:   " + Max);
//        System.out.println("Min:   " + Min);


        //数组元素的反转；（交换两个对称位置的数据）
        System.out.println("原先的数组顺序为：");
        PrintMethod(arrayB);


        for(int min=0,max=arrayB.length-1;min<max;min++,max--)
        {
            int temp=arrayB[min];
            arrayB[min]=arrayB[max];
            arrayB[max]=temp;

        }




        System.out.println("现在的数组顺序为：");

        PrintMethod(arrayB);







    }
    public static  void PrintMethod(int[]  array)//数组作为方法的参数
    {


        for(int j=0;j<array.length;j++)
        {
            System.out.println(array[j]);
        }
    }





}
