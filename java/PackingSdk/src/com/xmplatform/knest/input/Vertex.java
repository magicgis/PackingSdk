package com.xmplatform.knest.input;

/**
 * 顶点
 */
public class Vertex {
    private double x;           //x坐标
    private double y;           //y坐标
    private double bulge = 0.0; //凸度值

    // 构造函数
    public Vertex() {
    }

    public Vertex(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public Vertex(double x, double y, double bulge) {
        this.x = x;
        this.y = y;
        this.bulge = bulge;
    }

    // Getter和Setter方法
    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }

    public double getBulge() {
        return bulge;
    }

    public void setBulge(double bulge) {
        this.bulge = bulge;
    }
}
