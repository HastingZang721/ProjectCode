package demo;


import java.sql.SQLOutput;

/*
static 关键字 内容就变成属于类的\(专门存放在静态方法区，不是在堆栈中)
static 修饰成员方法 方法变成属于类的静态方法
静态方法中不使用非静态元素,静态内容总是先执行
 */
public class Day7 {
    public static void main(String[] args) {
//        student.room="101";
//        student one=new student("guo",19);
//        student two =new student("huang",20);
//        System.out.println(one.room);
//        System.out.println(two.room  );

        //静态代码块
       // 当第一次使用本类时，静态代码块的唯一执行;
        //一般用于一次性对静态成员赋值
        Person one=new Person();
        Person two=new Person();





    }
}
