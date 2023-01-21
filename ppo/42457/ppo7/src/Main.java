import java.util.ArrayList;
import ParkingLotManager.Interfaces.EntityInterface;
import ParkingLotManager.Log;
import ParkingLotManager.ParkingLot;
import ParkingLotManager.QueueGenerator;


public class QueueGenerator {
    public static List&lt;Entity&gt; generate() {
        List&lt;Entity&gt;
        queue = new ArrayList&lt;&gt;();
        Random random = new Random();

        for (int i = 0; i &lt;= random.nextInt(10); i++) {
            queue.add(new Entity());
        }

        return queue;
    }
}

public class Entity {
    private String name;
    private int money;
    private int time;
    private int hour;

    public Entity() {
        Random random = new Random();
        this.name = "Entity " + random.nextInt(100);
        this.money = random.nextInt(100);
        this.time = random.nextInt(100);
        this.hour = random.nextInt(100);
    }

    public String getName() {
        return name;
    }

    public int getMoney() {
        return money;
    }

    public int getTime() {
        return time;
    }

    public int getHour() {
        return hour;
    }
}

public class ParkingLot {
    private List&lt;Entity&gt; parkingLot;
    private int money;

    public ParkingLot() {
        this.parkingLot = new ArrayList&lt;&gt;();
        this.money = 0;
    }

    public void letIn(Entity entity) {
        this.parkingLot.add(entity);
        this.money += entity.getMoney();
        Log.info(entity.getName() + " entered the parking lot.");
    }

    public void dontletIn(Entity entity) {
        Log.info(entity.getName() + " didn't enter the parking lot.");
    }

    public boolean checkIfCanEnter(Entity entity) {
        return entity.getMoney() &gt;= 10;
    }

    public int countCars() {
        return this.parkingLot.size();
    }

    public int countmoney() {
        return this.money;
    }
}

public class Log {
    public static void info(String message) {
        System.out.println(message);
    }

    public static void info() {
        System.out.println();
    }
}

public class Main {
    public static void main(String[] args) {
        List&lt;Entity&gt; queue = QueueGenerator.generate();
        ParkingLot parking = new ParkingLot();

        Log.info("There's " +  parking.countCars() + " cars in the parking lot.");
        Log.info();

        for (int x = 0; x &lt;= 24; x++) {
            if (x == 8) {
                for (Entity entity : queue) {
                    if (parking.checkIfCanEnter(entity)) {
                        parking.letIn(entity);
                    } else {
                        parking.dontletIn(entity);
                    }
                }
            }
            if (x == 12) {
                for (Entity entity : queue) {
                    if (parking.checkIfCanEnter(entity)) {
                        parking.letIn(entity);

                    } else {
                        parking.dontletIn(entity);
                    }
                }
            }
            if (x == 16) {
                for (Entity entity : queue) {
                    if (parking.checkIfCanEnter(entity)) {
                        parking.letIn(entity);
                    } else {
                        parking.dontletIn(entity);
                    }
                }
            }
        }

        Log.info();
        Log.info("There's " +  parking.countCars() + " cars in the parking lot.");
        Log.info();
        Log.info("There's " + parking.countmoney() + " in parking money");
    }
}