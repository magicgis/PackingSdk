package com.xmplatform.knest.input;

import java.util.ArrayList;
import java.util.List;

/**
 * 零件/小板件数据
 */
public class NestPart {
    private long num;                                    //唯一数字，初始化时指定，后面都不会变（可以理解为顺序号）
    private String code;                                 //唯一编码（字符类型的唯一编码）
    private double length;                               //板长
    private double width;                                //板宽
    private long quantity;                               //数量
    private boolean texture;                             //是否要求纹理(false无纹理要求-即表示可以任意旋转  true有纹理要求-即表示不可旋转或者只能旋转180度)
    private List<Vertex> outer;                          //外轮廓
    private List<List<Vertex>> inners;                   //内轮廓
    private List<Vertex> outerPreserved;                 //包含预留空间的轮廓，当没有预留空间时，该值为空
    private long priority = 0;                           //优先级，默认为0

    // 构造函数
    public NestPart() {
        this.outer = new ArrayList<>();
        this.inners = new ArrayList<>();
        this.outerPreserved = new ArrayList<>();
    }

    // Getter和Setter方法
    public long getNum() {
        return num;
    }

    public void setNum(long num) {
        this.num = num;
    }

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

    public long getQuantity() {
        return quantity;
    }

    public void setQuantity(long quantity) {
        this.quantity = quantity;
    }

    public boolean isTexture() {
        return texture;
    }

    public void setTexture(boolean texture) {
        this.texture = texture;
    }

    public List<Vertex> getOuter() {
        return outer;
    }

    public void setOuter(List<Vertex> outer) {
        this.outer = outer;
    }

    public List<List<Vertex>> getInners() {
        return inners;
    }

    public void setInners(List<List<Vertex>> inners) {
        this.inners = inners;
    }

    public List<Vertex> getOuterPreserved() {
        return outerPreserved;
    }

    public void setOuterPreserved(List<Vertex> outerPreserved) {
        this.outerPreserved = outerPreserved;
    }

    public long getPriority() {
        return priority;
    }

    public void setPriority(long priority) {
        this.priority = priority;
    }
}
