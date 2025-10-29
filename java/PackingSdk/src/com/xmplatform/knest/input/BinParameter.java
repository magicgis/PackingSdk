package com.xmplatform.knest.input;

/**
 * 大板的属性
 */
public class BinParameter {
    private String material;    //基材
    private float thickness;    //板厚
    private float trimL;        //左修边
    private float trimR;        //右修边
    private float trimT;        //上修边
    private float trimB;        //下修边
    private float spacing;      //小板件/零件之间的间距
    private double binLength;   //原材料大板长度
    private double binWidth;    //原材料大板宽度
    private long binCount;      //原材料大板对应的数量
    private double binValue;    //原材料大板对应的价格

    // 构造函数
    public BinParameter() {
    }

    // Getter和Setter方法
    public String getMaterial() {
        return material;
    }

    public void setMaterial(String material) {
        this.material = material;
    }

    public float getThickness() {
        return thickness;
    }

    public void setThickness(float thickness) {
        this.thickness = thickness;
    }

    public float getTrimL() {
        return trimL;
    }

    public void setTrimL(float trimL) {
        this.trimL = trimL;
    }

    public float getTrimR() {
        return trimR;
    }

    public void setTrimR(float trimR) {
        this.trimR = trimR;
    }

    public float getTrimT() {
        return trimT;
    }

    public void setTrimT(float trimT) {
        this.trimT = trimT;
    }

    public float getTrimB() {
        return trimB;
    }

    public void setTrimB(float trimB) {
        this.trimB = trimB;
    }

    public float getSpacing() {
        return spacing;
    }

    public void setSpacing(float spacing) {
        this.spacing = spacing;
    }

    public double getBinLength() {
        return binLength;
    }

    public void setBinLength(double binLength) {
        this.binLength = binLength;
    }

    public double getBinWidth() {
        return binWidth;
    }

    public void setBinWidth(double binWidth) {
        this.binWidth = binWidth;
    }

    public long getBinCount() {
        return binCount;
    }

    public void setBinCount(long binCount) {
        this.binCount = binCount;
    }

    public double getBinValue() {
        return binValue;
    }

    public void setBinValue(double binValue) {
        this.binValue = binValue;
    }
}
