//jiadai c++ code, shaun read and understood
class Trip {
public:
	int id; // trip's id, primary key
	int driver_id, rider_id; // foreign key
	double lat, lng; // pick up location
	Trip(int rider, double lat, double lng);
}
class Helper {
	public:
	static get_distance(double lat1, double lng1,
	double lat2, double lng2) {
		// return distance between (lat1, lng1) and (lat2, lng2)
	}
};
struct Location {
    double lat;
    double lng;
    Location() {}
    Location(double la, double ln): lat(la), lng(ln) {}
};

class MiniUber {
public:
    MiniUber() {
        // initialize your data structure here.
    }

    // @param driver_id an integer
    // @param lat, lng driver's location
    // return matched trip information if there have matched rider or NULL
    Trip* report(int driver_id, double lat, double lng) {
        if (busyDrivers.find(driver_id) != busyDrivers.end()) {
            return busyDrivers[driver_id];
        }
        
        freeDrivers[driver_id] = Location(lat, lng);
        return nullptr;
    }

    // @param rider_id an integer
    // @param lat, lng rider's location
    // return a trip
    Trip* request(int rider_id, double lat, double lng) {
        Trip* trip = new Trip(rider_id, lat, lng);
        int driver_id = -1;
        double minDistance = -1;
		//it.first -- free driver id, it.second -- location
        for (auto it = freeDrivers.begin(); it != freeDrivers.end(); ++it) {
            double distance = Helper::get_distance(lat, lng, it->second.lat, it->second.lng);
            if (minDistance < 0 ||  distance < minDistance) {
                minDistance = distance;
                driver_id = it->first;
            }
        }
        
        if (driver_id != -1) { //now driver_id is closest to rider location
            freeDrivers.erase(driver_id); //remove from freeDrivers
            busyDrivers[driver_id] = trip; //add to busyDrivers
        }
        
        trip->driver_id = driver_id; //populate driver id of the trip just created
        return trip;
    }
    
private:
    unordered_map<int, Location> freeDrivers; //from driver id to its location
    unordered_map<int, Trip*> busyDrivers; //from driver id to his active trip
};
