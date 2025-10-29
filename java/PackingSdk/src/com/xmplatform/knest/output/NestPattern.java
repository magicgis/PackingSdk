package com.xmplatform.knest.output;

import java.util.ArrayList;
import java.util.List;

/**
 * 排版图案
 */
public class NestPattern {
    private long id;                            //原材料板件/大板id
    private String code;                        //原材料板件/大板唯一编码
    private String material;                    //材质
    private double length;                      //排版图案长
    private double width;                       //排版图案宽
    private double thickness;                   //排版图案厚
    private List<NestPlacement> wsPlacements;   //零件/小板件排版位置
    private double area;                        //面积
    private double fillRate;                    //填充率

    // 构造函数
    public NestPattern() {
        this.wsPlacements = new ArrayList<>();
    }

    // Getter和Setter方法
    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public String getCode() {
        return code;
    }

    public void setCode(String code) {
        this.code = code;
    }

    public String getMaterial() {
        return material;
    }

    public void setMaterial(String material) {
        this.material = material;
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

    public double getThickness() {
        return thickness;
    }

    public void setThickness(double thickness) {
        this.thickness = thickness;
    }

    public List<NestPlacement> getWsPlacements() {
        return wsPlacements;
    }

    public void setWsPlacements(List<NestPlacement> wsPlacements) {
        this.wsPlacements = wsPlacements;
    }

    public double getArea() {
        return area;
    }

    public void setArea(double area) {
        this.area = area;
    }

    public double getFillRate() {
        return fillRate;
    }

    public void setFillRate(double fillRate) {
        this.fillRate = fillRate;
    }
}
