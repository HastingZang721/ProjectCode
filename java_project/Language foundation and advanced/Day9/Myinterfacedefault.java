package demo3;

public interface Myinterfacedefault {

    public abstract void methodAbs();

   // public abstract void methodAbs11();

    //新添加的改成默认方法
    public default void methodDefault(){
        System.out.println("default method");

    }



}
