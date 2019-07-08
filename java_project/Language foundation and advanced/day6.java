package demo;

/*String 内容永不可变
字符串的常量池：程序中直接写上双引号的字符串，就在字符串常量池中
对基本类型比较：== 是进行数值的比较
对引用类型比较：==是地址值的比较

若是对字符串内容的比较：
public boolean equals(object obj)


public string concat(String str)//拼接字符串：+
public char charAt(inn index)//获取指定索引位置的字符
public int indexOf()
//字符串的截取
public String subString(int index)
public String subString


//public char[] tocharArray:将当前字符串拆分成字符数组作为返回值
 */


import java.util.Scanner;

public class Day6 {
    public static void main(String[] args) {
//        String str1=new String();
//
//        String str4="";
//        char[] charArray={'A','B'};
//        String str2=new String(charArray);
//
//
//        byte[] byteArray={97,98,99};
//        String str3=new String(byteArray);

//
//        String str1="hello";
//        String str2="hello";
//        char[] Arraystr={'h','e','l','l','o'};
//        String str3=new String(Arraystr);
//
//
//        //若是对字符串内容的比较：
//        //public boolean equals(object obj)
//        System.out.println(str1.equals(str2));
//        System.out.println(str1.equals(str3));

//         String str="shjqw,hdd,fnxs";
//        System.out.println(str);
////        //System.out.println("字符串的长度"+str.length());
////        String str1="ase";
////        System.out.println(str.concat(str1));
////        System.out.println(str1.charAt(1));
////
////        String str2=str.substring(5);
////        char[] str2=str.toCharArray();
////        /System.out.println(str2[1]);
//
//        String[] str2=str.split(",");
//       System.out.println(str2);


        //从键盘输入一个字符串，并且统计其他字符串出现的次数

        Scanner sc = new Scanner(System.in);
        System.out.println("请输入一个字符串");
        String inputString = sc.next();//获取键盘输入的字符串
        int coutUpper = 0;
        int countLower = 0;
        int countNumber = 0;//数字
        int countOther = 0;//其他字

        char[] chars = inputString.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            char ch = chars[i];//当前字符
            if ('A'<=ch&&ch<='Z')
                coutUpper++;
            else if('a'<=ch&& ch<='z' )
                countLower++;
            else if('0'<=ch&&ch<='9')
                countNumber++;
            else
                countOther++;




        }
        System.out.println("大写字母有"+coutUpper);
        System.out.println("小写字母有"+countLower);
        System.out.println("shuzi 有"+countNumber);
        System.out.println("其他有"+countOther);


    }
}
