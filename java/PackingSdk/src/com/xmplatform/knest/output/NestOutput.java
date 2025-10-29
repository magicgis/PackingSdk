package com.xmplatform.knest.output;

/**
 * 优化输出结果结构体
 */
public class NestOutput {
    private short status;               //状态
    private NestOutputData data;        //输出数据

    // 构造函数
    public NestOutput() {}

    public NestOutput(short status, NestOutputData data) {
        this.status = status;
        this.data = data;
    }

    // Getter和Setter方法
    public short getStatus() { return status; }
    public void setStatus(short status) { this.status = status; }

    public NestOutputData getData() { return data; }
    public void setData(NestOutputData data) { this.data = data; }
}
