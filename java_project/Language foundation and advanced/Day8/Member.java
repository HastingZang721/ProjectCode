package demo2;

import java.util.ArrayList;
import java.util.Random;

public class Member extends Person {
    public Member(String name, int money) {
        super(name, money);
    }

    public Member() {
    }

    public void receive(ArrayList list) {
        int index = new Random().nextInt(list.size());
        //生成一个list范围的随机数

        int delta = Integer.parseInt(String.valueOf(list.remove(index)));//根据索引，从集合中删除，并且得到被删除的红包
        //给自己
        int money = super.getMoney();
        super.setMoney(money + delta);
    }
}
