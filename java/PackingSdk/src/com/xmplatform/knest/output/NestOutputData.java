package com.xmplatform.knest.output;

import com.xmplatform.knest.input.AlgorithmParameter;
import com.xmplatform.knest.input.BinParameter;
import com.xmplatform.knest.input.NestPart;

import java.util.ArrayList;
import java.util.List;

/**
 * 优化输出数据结构体
 */
public class NestOutputData {
    private short status;                               //状态
    private List<NestPart> parts;                       //零件/小板件列表
    private AlgorithmParameter algorithmParam;          //优化参数
    private List<BinParameter> bins;                    //原材料板件/大板列表
    private List<NestPattern> patterns;                 //排版图案
    private List<NestPartUsedInfo> partUsedInfos;       //被使用的零件/小板件信息
    private List<BinUsedInfo> binUsedInfos;             //被使用的原材料板件/大板信息
    private double totalFillRate;                       //填充率
    private long totalPartCount;                        //零件/小板件总数

    // 构造函数
    public NestOutputData() {
        this.parts = new ArrayList<>();
        this.bins = new ArrayList<>();
        this.patterns = new ArrayList<>();
        this.partUsedInfos = new ArrayList<>();
        this.binUsedInfos = new ArrayList<>();
    }

    // Getter和Setter方法
    public short getStatus() {
        return status;
    }

    public void setStatus(short status) {
        this.status = status;
    }

    public List<NestPart> getParts() {
        return parts;
    }

    public void setParts(List<NestPart> parts) {
        this.parts = parts;
    }

    public AlgorithmParameter getAlgorithmParam() {
        return algorithmParam;
    }

    public void setAlgorithmParam(AlgorithmParameter algorithmParam) {
        this.algorithmParam = algorithmParam;
    }

    public List<BinParameter> getBins() {
        return bins;
    }

    public void setBins(List<BinParameter> bins) {
        this.bins = bins;
    }

    public List<NestPattern> getPatterns() {
        return patterns;
    }

    public void setPatterns(List<NestPattern> patterns) {
        this.patterns = patterns;
    }

    public List<NestPartUsedInfo> getPartUsedInfos() {
        return partUsedInfos;
    }

    public void setPartUsedInfos(List<NestPartUsedInfo> partUsedInfos) {
        this.partUsedInfos = partUsedInfos;
    }

    public List<BinUsedInfo> getBinUsedInfos() {
        return binUsedInfos;
    }

    public void setBinUsedInfos(List<BinUsedInfo> binUsedInfos) {
        this.binUsedInfos = binUsedInfos;
    }

    public double getTotalFillRate() {
        return totalFillRate;
    }

    public void setTotalFillRate(double totalFillRate) {
        this.totalFillRate = totalFillRate;
    }

    public long getTotalPartCount() {
        return totalPartCount;
    }

    public void setTotalPartCount(long totalPartCount) {
        this.totalPartCount = totalPartCount;
    }
}
