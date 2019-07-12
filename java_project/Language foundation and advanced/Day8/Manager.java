package demo2;

import java.util.ArrayList;

public class Manager extends Person {

    public Manager(){}

    public Manager(String name, int money) {
        super(name, money);
    }
    public ArrayList<Integer> send(int totalMoney,int count){

        ArrayList<Integer>redlist=new ArrayList<>();

        //群主看下剩下余
        int leftMoney=super.getMoney();
        if(totalMoney>leftMoney) {
            System.out.println("insufficient");
            return redlist;//返回空集合
        }

        super.setMoney(leftMoney-totalMoney);//重新设置余额
        int avg=totalMoney/count;
        int mod=totalMoney%count;//零头

        //
        for (int i = 0; i < count-1; i++) {
            redlist.add(avg);

        }

        redlist.add(avg+mod);

        return redlist;


        }

 }
