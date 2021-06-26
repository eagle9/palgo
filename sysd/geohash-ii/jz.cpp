class GeoHash {
public:
    /**
     * @param geohash a base32 string
     * @return latitude and longitude a location coordinate pair
     */
    vector<double> decode(string& geohash) {
        // Write your code here
        string _base32 = "0123456789bcdefghjkmnpqrstuvwxyz";
        vector<int> mask = {16, 8, 4, 2, 1};
        vector<double> lon = {-180, 180};
        vector<double> lat = {-90, 90};
        bool is_even = true;

        for (int i = 0; i < geohash.size(); ++i) {
            int val = _base32.find(geohash[i]);
            for (int j = 0; j < 5; ++j) {
                if (is_even) {
                    refine_interval(lon, val, mask[j]);
                } else {
                    refine_interval(lat, val, mask[j]);
                }
                is_even = ! is_even;
            }
        }
        vector<double> location = {(lat[0] + lat[1]) / 2.0, (lon[0] + lon[1]) / 2.0};
        return location;
    }

    void refine_interval(vector<double> &interval, int val, int mask) {
        if ((val & mask) > 0) {
            interval[0] = (interval[0] + interval[1]) / 2.0;
        } else {
            interval[1] = (interval[0] + interval[1]) / 2.0;
        }
    }
};
