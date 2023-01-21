package ParkingLotManager;

import ParkingLotManager.Entities.Bicycle;
import ParkingLotManager.Entities.Car;
import ParkingLotManager.Entities.Pedestrian;
import ParkingLotManager.Entities.TeacherCar;
import ParkingLotManager.Interfaces.EntityInterface;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

final class QueueGenerator {

    private static final int ANONYMOUS_PEDESTRIANS_COUNT = 50;
    private static final int PEDESTRIANS_COUNT = 5;
    private static final int CARS_COUNT = 50;
    private static final int TEACHER_CARS_COUNT = 7;
    private static final int BICYCLES_COUNT = 3;
    private static final int PRIVILIGED_CARS_COUNT = 5;
    private static final int TANK_COUNT = 1;

    public static ArrayList<EntityInterface> generate() {
        ArrayList<EntityInterface> queue = new ArrayList<>();

        for (int i = 0; i <= ANONYMOUS_PEDESTRIANS_COUNT; i++) {
            queue.add(new Pedestrian());
        }

        for (int i = 0; i <= PEDESTRIANS_COUNT; i++) {
            queue.add(new Pedestrian(getRandomName()));
        }

        for (int i = 0; i <= CARS_COUNT; i++) {
            queue.add(new Car(getRandomPlateNumber()));
        }


        for (int i = 0; i <= TEACHER_CARS_COUNT; i++) {
            queue.add(new TeacherCar(getRandomPlateNumber()));
        }

        for (int i = 0; i <= BICYCLES_COUNT; i++) {
            queue.add(new Bicycle());

        for (int i = 0; i <= TANK_COUNT; i++) {
            queue[i] = new Tank();
        }

        for (int i = 0; i <= PRIVILIGED_CARS_COUNT; i++) {
            queue[i] = new PriviligedCar(getRandomPlateNumber());
        }

        Collections.shuffle(queue);
        return queue;
    }

    private static String getRandomPlateNumber() {
        return "DLX " + random_int(10000, 99999);
    }

    private static String getRandomName() {
        String[] names = {"John", "Jack", "James", "George", "Joe", "Jim"};
            return names[(int) (Math.random() * names.length)];
    }

}