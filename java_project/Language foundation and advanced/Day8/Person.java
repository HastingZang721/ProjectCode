package demo2;

public class Person {
    private String name;
    private int money;//当前钱】

    public Person() {

    }

    public Person(String name, int money) {
        this.name = name;
        this.money = money;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getMoney() {
        return money;
    }

    public void setMoney(int money) {
        this.money = money;
    }
    public void showMoney(){
        System.out.println("name"+name+"余额"+money);
    }
}
