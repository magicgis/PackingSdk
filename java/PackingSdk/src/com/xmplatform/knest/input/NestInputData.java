package com.xmplatform.knest.input;

import java.util.ArrayList;
import java.util.List;

/**
 * 优化算法输入数据
 */
public class NestInputData {
    private OptParameter param;                          //优化参数
    //std::vector<GroupInfo> groupInfos;                //组信息列表
    //std::vector<WsPart> partOfGroups;                  //组信息列表，该节点下的part，其属性groupCode必须非空
    //上面的属性是原有属性，下面的属性是建议新增属性
    //原有结构保留，以兼容以前的数据。新的输入数据根据版本version的值来区分，例如当版本号为1时，优化相关参数从algorithmParam中获取，大板的相关参数则从bins中获取（从而支持多原片-单次优化时输入数据中有多个不同的大板）
    private short version = 1;                           //版本
    private List<NestPart> parts;                        //零件/小板件列表
    private AlgorithmParameter algorithmParam;           //优化参数
    private List<BinParameter> bins;                     //原材料板件/大板列表

    // 构造函数
    public NestInputData() {
        this.parts = new ArrayList<>();
        this.bins = new ArrayList<>();
    }

    // Getter和Setter方法
    public OptParameter getParam() {
        return param;
    }

    public void setParam(OptParameter param) {
        this.param = param;
    }

    public short getVersion() {
        return version;
    }

    public void setVersion(short version) {
        this.version = version;
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
}
