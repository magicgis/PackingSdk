package com.xmplatform.knest.output;

/**
 * 大板使用信息
 */
public class BinUsedInfo {
    private String code;            //大板唯一编码
    private double length;          //长
    private double width;           //宽
    private long startQuantity;     //初始数量(原材料板件/大板的数量)
    private long usedQuantity;      //已使用数量
    private long restQuantity;      //剩余数量

    // 构造函数
    public BinUsedInfo() {
    }

    public BinUsedInfo(String code, double length, double width, long startQuantity, long usedQuantity, long restQuantity) {
        this.code = code;
        this.length = length;
        this.width = width;
        this.startQuantity = startQuantity;
        this.usedQuantity = usedQuantity;
        this.restQuantity = restQuantity;
    }

    // Getter和Setter方法
    public String getCode() {
        return code;
    }

    public void setCode(String code) {
        this.code = code;
    }

    public double getLength() {
        return length;
    }

    public void setLength(double length) {
        this.length = length;
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    public long getStartQuantity() {
        return startQuantity;
    }

    public void setStartQuantity(long startQuantity) {
        this.startQuantity = startQuantity;
    }

    public long getUsedQuantity() {
        return usedQuantity;
    }

    public void setUsedQuantity(long usedQuantity) {
        this.usedQuantity = usedQuantity;
    }

    public long getRestQuantity() {
        return restQuantity;
    }

    public void setRestQuantity(long restQuantity) {
        this.restQuantity = restQuantity;
    }
}
