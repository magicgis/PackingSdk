package com.xmplatform.knest.output;

/**
 * 零件/小板件的摆放信息
 */
public class NestPlacement {
    private String code;        //唯一编码
    private boolean texture;    //是否有纹理要求
    private double angle;       //旋转角度
    private double baseX;       //坐标x
    private double baseY;       //坐标y

    // 构造函数
    public NestPlacement() {
    }

    public NestPlacement(String code, boolean texture, double angle, double baseX, double baseY) {
        this.code = code;
        this.texture = texture;
        this.angle = angle;
        this.baseX = baseX;
        this.baseY = baseY;
    }

    // Getter和Setter方法
    public String getCode() {
        return code;
    }

    public void setCode(String code) {
        this.code = code;
    }

    public boolean isTexture() {
        return texture;
    }

    public void setTexture(boolean texture) {
        this.texture = texture;
    }

    public double getAngle() {
        return angle;
    }

    public void setAngle(double angle) {
        this.angle = angle;
    }

    public double getBaseX() {
        return baseX;
    }

    public void setBaseX(double baseX) {
        this.baseX = baseX;
    }

    public double getBaseY() {
        return baseY;
    }

    public void setBaseY(double baseY) {
        this.baseY = baseY;
    }
}
