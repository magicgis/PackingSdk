package com.xmplatform.knest.input;

import com.xmplatform.knest.GsonUtils;

/**
 * 优化算法输入(总体结构)
 */
public class NestInput {
    private int version = 1;          //版本
    private NestInputData data;         //优化所需的所有数据

    // 构造函数
    public NestInput() {}

    public NestInput(NestInputData data) {
        this.data = data;
    }

    // Getter和Setter方法
    public int getVersion() { return version; }
    public void setVersion(int version) { this.version = version; }

    public NestInputData getData() { return data; }
    public void setData(NestInputData data) { this.data = data; }

    public String toJson(){
        return GsonUtils.toJson(this);
    }
}