498. Parking Lot
Difficulty: Hard

http://lintcode.com/en/problem/parking-lot/

Design a parking lot.

see CC150 OO Design for details.

n levels, each level has m rows of spots and each row has k spots.So each level has m x k spots.
The parking lot can park motorcycles, cars and buses
The parking lot has motorcycle spots, compact spots, and large spots
Each row, motorcycle spots id is in range [0,k/4)(0 is included, k/4 is not included), compact spots id is in range [k/4,k/43) and large spots id is in range [k/43,k).
A motorcycle can park in any spot
A car park in single compact spot or large spot
A bus can park in five large spots that are consecutive and within same row. it can not park in small spots
Example

level=1, num_rows=1, spots_per_row=11
parkVehicle("Motorcycle_1") // return true
parkVehicle("Car_1") // return true
parkVehicle("Car_2") // return true
parkVehicle("Car_3") // return true
parkVehicle("Car_4") // return true
parkVehicle("Car_5") // return true
parkVehicle("Bus_1") // return false
unParkVehicle("Car_5")
parkVehicle("Bus_1") // return true
