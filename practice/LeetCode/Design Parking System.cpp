// https://leetcode.com/problems/design-parking-system/

enum VehicleType { BIG_CAR, MEDIUM_CAR, SMALL_CAR }
enum SpotType { SMALL, MEDIUM, LARGE }

class Vehicle {
    String id;
    VehicleType type;
    ParkingSpot parkingSpot;

    Vehicle(String id, VehicleType type) {
        this.id = id;
        this.type = type;
    }

    public String getId() {
        return id;
    }

    public VehicleType getType() {
        return type;
    }

    public ParkingSpot getParking() {
        return parkingSpot;
    }

    public void setParking(ParkingSpot parkingSpot) {
        this.parkingSpot = parkingSpot;
    }
}

class ParkingSpot {
    String id;
    SpotType type;
    Vehicle vehicle;

    ParkingSpot(String id, SpotType type) {
        this.id = id;
        this.type = type;
        this.vehicle = null;
    }

    public String getId() {
        return id;
    }

    public SpotType getType() {
        return this.type;
    }

    public Boolean getIsEmpty() {
        return vehicle == null;
    }

    public synchronized boolean canFit(VehicleType vehicleType) {
        switch (vehicleType) {
            case BIG_CAR:
                return type == SpotType.LARGE;
            case MEDIUM_CAR:
                return type == SpotType.MEDIUM;
            case SMALL_CAR:
                return type == SpotType.SMALL;
            default:
                return false;
        }
    }

    public synchronized void parkVehicle(Vehicle vehicle) {
        if (this.getIsEmpty()) {
            if (!this.canFit(vehicle.getType())) {
                throw new IllegalArgumentException("Only" + this.type + "can be parked in this spot.");
            }
            this.vehicle = vehicle;
            this.vehicle.setParking(this);
        } else {
            throw new IllegalStateException("Parking spot is already occupied.");
        }
    }


    public synchronized void unparkVehicle() {
        if (!this.getIsEmpty()) {
            this.vehicle = null;
        } else {
            throw new IllegalStateException("Parking spot is already empty.");
        }
    }
}

class ParkingFloor {
    String number;
    List<ParkingSpot> parkingSpots;

    ParkingFloor(String number, List<ParkingSpot> parkingSpots) {
        this.number = number;
        this.parkingSpots = parkingSpots;
    }

    public List<ParkingSpot> getAvailableSpots(VehicleType vehicleType) {
        List<ParkingSpot> availableSpots = new ArrayList<>();
        for (ParkingSpot spot : parkingSpots) {
            if (spot.getIsEmpty() && spot.canFit(vehicleType)) {
                availableSpots.add(spot);
            }
        }
        return availableSpots;
    }
}

class ParkingLot {
    String name;
    List<ParkingFloor> floors;

    ParkingLot(String name, List<ParkingFloor> floors) {
        this.name = name;
        this.floors = floors;
    }

    public String getName() {
        return name;
    }

    public List<ParkingFloor> getFloors() {
        return floors;
    }

    public List<ParkingSpot> getAvailableSpots(VehicleType vehicleType) {
        List<ParkingSpot> availableSpots = new ArrayList<>();
        for (ParkingFloor floor : floors) {
            availableSpots.addAll(floor.getAvailableSpots(vehicleType));
        }
        return availableSpots;
    }
}

class ParkingService {
    ParkingLot parkingLot;

    public ParkingService(ParkingLot parkingLot) {
        this.parkingLot = parkingLot;
    }

    public synchronized void parkVehicle(String vehicleId, VehicleType vehicleType) {
        Vehicle vehicle = new Vehicle(vehicleId, vehicleType);

        List<ParkingSpot> availableSpots = parkingLot.getAvailableSpots(vehicleType);
        if (availableSpots.isEmpty()) {
            throw new IllegalStateException("No available parking spots for " + vehicleType);
        }

        ParkingSpot spot = availableSpots.get(0); // Park in the first available spot
        spot.parkVehicle(vehicle);
    }
}

class ParkingSystem {
    private ParkingService parkingService;

    public ParkingSystem(int big, int medium, int small) {
        List<ParkingSpot> allSpots = new ArrayList<>();
        for (int i = 0; i < big; i++) {
            allSpots.add(new ParkingSpot("L" + i, SpotType.LARGE));
        }
        for (int i = 0; i < medium; i++) {
            allSpots.add(new ParkingSpot("M" + i, SpotType.MEDIUM));
        }
        for (int i = 0; i < small; i++) {
            allSpots.add(new ParkingSpot("S" + i, SpotType.SMALL));
        }
        ParkingFloor floor1 = new ParkingFloor("1", allSpots);
        List<ParkingFloor> floors = new ArrayList<>();
        floors.add(floor1);
        ParkingLot parkingLot = new ParkingLot("MainLot", floors);
        parkingService = new ParkingService(parkingLot);
    }

    public boolean addCar(int carType) {
        VehicleType vehicleType;
        switch (carType) {
            case 1:
                vehicleType = VehicleType.BIG_CAR;
                break;
            case 2:
                vehicleType = VehicleType.MEDIUM_CAR;
                break;
            case 3:
                vehicleType = VehicleType.SMALL_CAR;
                break;
            default:
                throw new IllegalArgumentException("Invalid car type");
        }
        try {
            parkingService.parkVehicle("DUMMY", vehicleType);
            return true;
        } catch (IllegalStateException e) {
            System.out.println(e.getMessage());
            return false;
        }
    }
}


/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem obj = new ParkingSystem(big, medium, small);
 * boolean param_1 = obj.addCar(carType);
 */