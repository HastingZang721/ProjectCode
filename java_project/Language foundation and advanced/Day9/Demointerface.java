package demo3;

/*
public interface name{}

接口可以包含
常量
抽象方法

java8 还可以包含默认方法+静态方法
接口使用步骤
1。不能直接使用，需要实现类来实现
public class 实现类 implements 接口名称{}
2 接口的实现类必须覆盖重写接口中所有抽象方法

3。一个类可以有多个接口
 */

public class DemoInterface {
    public static void main(String[] args) {
//        MyinterfaceAbstractImpl impl=new MyinterfaceAbstractImpl();
//        impl.method1();
//        impl.methodABs();

//        MyinterfaceDefaultA impl=new MyinterfaceDefaultA();
//        impl.methodAbs();
//        impl.methodDefault();
        MyinterfaceStatic.methodStatic();

    }



}
