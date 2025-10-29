package com.xmplatform.knest.input;

/**
 * 优化的参数(旧版本结构-只支持单种大板类型的优化)
 */
public class OptParameter {
    private String material;                    //基材
    private float thickness;                    //板厚
    private float trimL;                       //左修边
    private float trimR;                       //右修边
    private float trimT;                       //上修边
    private float trimB;                       //下修边
    private float spacing;                     //板件/零件之间的间距
    private double binLength;                  //原材料大板长度
    private double binWidth;                   //原材料大板宽度
    private byte baseCorner = 1;               //优化的堆积角落，1表示左下角，2表示右下角，3表示右上角，4表示左上角
    private byte nestType;                     //优先级类型 1表示优先级大于0的尽量靠前，2表示优先级大于0的绝对靠前
    private boolean enablePriority = false;    //是否启用板件/零件的排版优先级（优先级的值默认是0）
    private byte priorityType;                 //优先级类型 1表示优先级大于0的尽量靠前，2表示优先级大于0的绝对靠前
    private boolean higherPriorityPlacedFront = false; //大板中的小板存在优先级定义时，该大板靠前还是靠后, true 则放在前面，false 则放在后面， 默认false
    private long binCount;                     //原材料大板对应的数量
    private int resultTimeOut = -1;            //得到优化结果后，等待多长时间内(毫秒)再无优化结果变化，则算法停止运行，当为-1表示不限制，即一直等待
    private short logLevel = 4;                //日志级别，默认值是2调试模式  Trace = 1, Debug = 2, Info = 3, Warn = 4, Error = 5, Fatal = 6, Off = 7
    private boolean jsonResultAsFile = false;  //是否将输出结果导出为文件，然后将文件路径放入jsonResult中。默认值为false，false表示jsonResult中放入的是json字符串(NestOutput)，true表示将json字符串保存为文件后，将文件路径值放入jsonResult
    private byte binValueType = 1;             //大板价值类型：按照面积还是按照价格，当为空或者为1表示按照面积，非空且为2表示按照价格
    private double binValue;                   //大板价格
    private boolean enableExecCbOnTimer = false; //是否启用了定期执行回调函数，默认为false不启用
    private int execCbOnTimerInterval = 3;     //定时执行回调函数的间隔时间，单位（秒），默认值为3秒
    private int calThreads = 2;                //算法计算线程数，默认值为2个

    // 构造函数
    public OptParameter() {
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

    public byte getBaseCorner() {
        return baseCorner;
    }

    public void setBaseCorner(byte baseCorner) {
        this.baseCorner = baseCorner;
    }

    public byte getNestType() {
        return nestType;
    }

    public void setNestType(byte nestType) {
        this.nestType = nestType;
    }

    public boolean isEnablePriority() {
        return enablePriority;
    }

    public void setEnablePriority(boolean enablePriority) {
        this.enablePriority = enablePriority;
    }

    public byte getPriorityType() {
        return priorityType;
    }

    public void setPriorityType(byte priorityType) {
        this.priorityType = priorityType;
    }

    public boolean isHigherPriorityPlacedFront() {
        return higherPriorityPlacedFront;
    }

    public void setHigherPriorityPlacedFront(boolean higherPriorityPlacedFront) {
        this.higherPriorityPlacedFront = higherPriorityPlacedFront;
    }

    public long getBinCount() {
        return binCount;
    }

    public void setBinCount(long binCount) {
        this.binCount = binCount;
    }

    public int getResultTimeOut() {
        return resultTimeOut;
    }

    public void setResultTimeOut(int resultTimeOut) {
        this.resultTimeOut = resultTimeOut;
    }

    public short getLogLevel() {
        return logLevel;
    }

    public void setLogLevel(short logLevel) {
        this.logLevel = logLevel;
    }

    public boolean isJsonResultAsFile() {
        return jsonResultAsFile;
    }

    public void setJsonResultAsFile(boolean jsonResultAsFile) {
        this.jsonResultAsFile = jsonResultAsFile;
    }

    public byte getBinValueType() {
        return binValueType;
    }

    public void setBinValueType(byte binValueType) {
        this.binValueType = binValueType;
    }

    public double getBinValue() {
        return binValue;
    }

    public void setBinValue(double binValue) {
        this.binValue = binValue;
    }

    public boolean isEnableExecCbOnTimer() {
        return enableExecCbOnTimer;
    }

    public void setEnableExecCbOnTimer(boolean enableExecCbOnTimer) {
        this.enableExecCbOnTimer = enableExecCbOnTimer;
    }

    public int getExecCbOnTimerInterval() {
        return execCbOnTimerInterval;
    }

    public void setExecCbOnTimerInterval(int execCbOnTimerInterval) {
        this.execCbOnTimerInterval = execCbOnTimerInterval;
    }

    public int getCalThreads() {
        return calThreads;
    }

    public void setCalThreads(int calThreads) {
        this.calThreads = calThreads;
    }
}
