package ParkingLotManager.Entities;

import ParkingLotManager.Interfaces.EntityInterface;

public class Pedestrian implements EntityInterface {

    protected String name = "";

    public Pedestrian() {}

    public Pedestrian(String name) {
        this.name = name;
    }

    public String identify() {
        return this.name != null ? this.name : "Unknown pedestrian";
    }

    public boolean canEnter() {
        return true;
    }
    public boolean havetopay() {
        return false;
    }
}
