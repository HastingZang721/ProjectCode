package hasting.demo;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


//判断方法
//boolean eauqls(String str)//比较两个字符串内容是否相同
/*boolean equalsIgnoreCase(String str)//比较两个字符串是相等的（忽略大小写）
boolean  startsWith(String substr);//判断某字符串是否以指定的子串kaitou
boolean endsWith(String shubstr);//判断某个字符串是否以指定的子串结尾


*获取方法
        int length();//获取字符串中字符个数
        char charAt(int index)//获取字符串中某一个字符
        String substring(int startIndex)//从指定下标开始街区字符串，直到字符串的末尾
        String substring(int startIndex,int endIndex);//从指定的下标开始截取字符串，到指定的下标结束（左闭右开）
        int indexof(String substr)//获取子串第一次出现的下标

 第三组：转换方法
        String tolowerCase();//转成小写串
        String toUpperCase()//转成大写
        char[] toCharArray()//变成字符数组

        第四组：
        String trim//去掉字符串两端空格
        String split(String str)//切割字符串

*
*
*
*
*
 */
//


//三。读 写文件
//输出流：数据从java程序到文件中
//FileWriter
//write(int ch)//写一个字符（可以是ASCII）


public class HelloWorld {
    public static void main(String[] args) throws IOException
    {
//        FileWriter fw=new FileWriter("1.txt");
//        fw.write("java",1,2);
//
//        fw.close();

        //FileWriter
        FileReader fr=new FileReader("1.txt");
//        int ch=fr.read();
//        System.out.println(ch);//将ASCII转成字符A-65 0-48
        char[] chs=new char[4];
        int len=fr.read(chs);
        System.out.println(len);

        fr.close();
    }
}


//输入流
//FileReader(读字符，或者字符串)
//int read();//读取一个字符
//int read(char[] chs)//一个读取一个字符数组，返回值表示实际读取到的字符个数
