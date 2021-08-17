class Solution {
    double radius, x_center, y_center;

    public Solution(double radius, double x_center, double y_center) {
        this.radius = radius;
        this.x_center = x_center;
        this.y_center = y_center;
    }

    public double[] randPoint() {
        double len = Math.sqrt(Math.random()) * radius;
        int degree = (int)(Math.random() * 360);
        double x = x_center + len * Math.cos(degree);
        double y = y_center + len * Math.sin(degree);
        return new double[] {x, y};
    }
}

