package ParkingLotManager.Entities;

import ParkingLotManager.Interfaces.EntityInterface;

public class Car implements EntityInterface {

    protected String plate;

    public Car(String plate) {
        this.plate = plate;
    }

    public String identify() {
        return "Car with plate number " + this.plate;
    }

    public boolean canEnter() {
        return true;
    }
    public boolean havetopay() {
        return true;
    }
}
