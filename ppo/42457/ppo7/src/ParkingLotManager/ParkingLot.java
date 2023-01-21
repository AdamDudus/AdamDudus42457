package ParkingLotManager;

import ParkingLotManager.Entities.Bicycle;
import ParkingLotManager.Entities.Car;
import ParkingLotManager.Interfaces.EntityInterface;

import java.util.ArrayList;

public final class ParkingLot {

    protected List<EntityInterface> entitiesOnProperty = new ArrayList<>();
    protected int carsOnProperty = 0;
    protected int bicyclesOnProperty = 0;
    protected int maxcarsOnProperty = 100;
    protected int maxbicyclesOnProperty = 20;
    protected int collectedmoney = 0;

    public boolean checkIfCanEnter(EntityInterface entity) {

        if (entity instanceof Car) {

            if (this.carsOnProperty < this.maxcarsOnProperty) {
                return entity.canEnter();
            }
            else {
                return false;
            }
        }
        if (entity instanceof Bicycle) {
            if (this.bicyclesOnProperty < this.maxbicyclesOnProperty) {
                return entity.canEnter();
            }
            else {
                return false;
            }
        }
        return entity.canEnter();
    }

    public boolean doeshehavetopay(EntityInterface entity) {
        return entity.havetopay();
    }

    public void letIn(EntityInterface entity) {
        this.entitiesOnProperty.add(entity);
        Log.info(entity.identify() + " let in.");

        if (entity instanceof Car) {

            this.carsOnProperty++;
            if (entity.havetopay()) {
                this.collectedmoney += 3;
            }
        }

        if (entity instanceof Bicycle) {
            this.bicyclesOnProperty++;
        }
    }

    public void dontletIn(EntityInterface entity) {
        this.entitiesOnProperty.add(entity);
        Log.info(entity.identify() + " can't let in.");
    }

    public int countCars() {
        return this.carsOnProperty;
    }

    public int countmoney() {
        return this.collectedmoney;
    }

}