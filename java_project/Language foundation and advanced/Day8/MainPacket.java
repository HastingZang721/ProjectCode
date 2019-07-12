package demo2;

import java.util.ArrayList;

public class MainPacket {
    public static void main(String[] args) {
        Manager manager=new Manager("群主",100);
        Member menberone=new Member("1",0);
        Member menbertwo=new Member("2",0);
        Member menberthree=new Member("3",0);

        manager.showMoney();
        menberone.showMoney();
        menbertwo.showMoney();
        menberthree.showMoney();
        System.out.println("==========");

       ArrayList<Integer> list1= manager.send(35,3);
       menberone.receive(list1);
       menbertwo.receive(list1);
       menberthree.receive(list1);

        manager.showMoney();
        menberone.showMoney();
        menbertwo.showMoney();
        menberthree.showMoney();


    }
}
