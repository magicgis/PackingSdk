package com.xmplatform.knest;

import com.google.gson.ExclusionStrategy;
import com.google.gson.FieldAttributes;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.annotations.JsonAdapter;

/**
 * @Description Solver输出格式类
 */
public class SolverOutput {
    private int solverState = SolverState.READY.ordinal();//算法当前状态
    private int solverEndedReason = SolverEndedReason.None.ordinal();//算法结束原因
    private String solver_ended_msg;//算法结束原因的相关文字信息
    private long currentPriority = 0;//当前优先级
    private long numOfIteration = 0;//迭代总次数
    private long elapsedTime = 0;//算法消耗的总时间(单位毫秒)
    private double calUsage = 0.0;//本轮计算的总利用率，例如0.97表示95%的利用率
    private double calProgress = 0.0;//本轮计算的进度，例如0.95表示95%的进度
    private int calTargetSheetCount = 0;//本轮计算的的目标大板数，例如当前最优结果的大板数是8，则通常本轮计算的目标大板数是8-1=7
    private long optimumIndex = 0;//每次优化结果列表都与上次不同，该值用于标记第几次优化结果列表
    private long bestFitness = 0;//目前最好的适应度值
    private int resultTimeOut = 0;//超时时间（毫秒数） -用于定义距离上次优化结果的时间间隔，当为-1时表示不超时，当优化结果没变化并且超过该时间间隔时，优化自动停止
    private long startTimeForTimeOut = 0;//超时开始时间（毫秒数）
    private int bestResultSheetCount = 0;//当前已计算完成的排版方案中结果最优的大板数
    private double bestResultUsage = 0.0;//当前已计算完成的排版方案中结果最优的利用率
    @JsonAdapter(ObjectToStringAdapter.class)//将该字段反序列化为字符串
    private String jsonResult;//优化结果json文件路径或者字符串，只有计算最终结束的时候该字段才会有值

    public int getSolverState() {
        return solverState;
    }

    public void setSolverState(int solverState) {
        this.solverState = solverState;
    }

    public int getSolverEndedReason() {
        return solverEndedReason;
    }

    public void setSolverEndedReason(int solverEndedReason) {
        this.solverEndedReason = solverEndedReason;
    }

    public String getSolver_ended_msg() {
        return solver_ended_msg;
    }

    public void setSolver_ended_msg(String solver_ended_msg) {
        this.solver_ended_msg = solver_ended_msg;
    }

    public long getCurrentPriority() {
        return currentPriority;
    }

    public void setCurrentPriority(long currentPriority) {
        this.currentPriority = currentPriority;
    }

    public long getNumOfIteration() {
        return numOfIteration;
    }

    public void setNumOfIteration(long numOfIteration) {
        this.numOfIteration = numOfIteration;
    }

    public long getElapsedTime() {
        return elapsedTime;
    }

    public void setElapsedTime(long elapsedTime) {
        this.elapsedTime = elapsedTime;
    }

    public double getCalUsage() {
        return calUsage;
    }

    public void setCalUsage(double calUsage) {
        this.calUsage = calUsage;
    }

    public double getCalProgress() {
        return calProgress;
    }

    public void setCalProgress(double calProgress) {
        this.calProgress = calProgress;
    }

    public int getCalTargetSheetCount() {
        return calTargetSheetCount;
    }

    public void setCalTargetSheetCount(int calTargetSheetCount) {
        this.calTargetSheetCount = calTargetSheetCount;
    }

    public long getOptimumIndex() {
        return optimumIndex;
    }

    public void setOptimumIndex(long optimumIndex) {
        this.optimumIndex = optimumIndex;
    }

    public long getBestFitness() {
        return bestFitness;
    }

    public void setBestFitness(long bestFitness) {
        this.bestFitness = bestFitness;
    }

    public int getResultTimeOut() {
        return resultTimeOut;
    }

    public void setResultTimeOut(int resultTimeOut) {
        this.resultTimeOut = resultTimeOut;
    }

    public long getStartTimeForTimeOut() {
        return startTimeForTimeOut;
    }

    public void setStartTimeForTimeOut(long startTimeForTimeOut) {
        this.startTimeForTimeOut = startTimeForTimeOut;
    }

    public int getBestResultSheetCount() {
        return bestResultSheetCount;
    }

    public void setBestResultSheetCount(int bestResultSheetCount) {
        this.bestResultSheetCount = bestResultSheetCount;
    }

    public double getBestResultUsage() {
        return bestResultUsage;
    }

    public void setBestResultUsage(double bestResultUsage) {
        this.bestResultUsage = bestResultUsage;
    }

    public String getJsonResult() {
        return jsonResult;
    }

    public void setJsonResult(String jsonResult) {
        this.jsonResult = jsonResult;
    }




    //转换为json字符串
    public String toJson(){
        //字段不输出到json，仅内部使用
        String[] options = new String[] { "" };
        ExclusionStrategy excludeStrategy = new SetterExclusionStrategy(options);
        Gson gson = new GsonBuilder().setExclusionStrategies(excludeStrategy).create();
        return gson.toJson(this);
    }


    /**
     * 转json字段过滤类
     */
    private static class SetterExclusionStrategy implements ExclusionStrategy {
        private String[] fields;

        public SetterExclusionStrategy(String[] fields) {
            this.fields = fields;

        }

        @Override
        public boolean shouldSkipClass(Class<?> arg0) {
            return false;
        }

        /**
         * 过滤字段的方法
         */
        @Override
        public boolean shouldSkipField(FieldAttributes f) {
            if (fields != null) {
                for (String name : fields) {
                    if (f.getName().equals(name)) {
                        /** true 代表此字段要过滤 */
                        return true;
                    }
                }
            }
            return false;
        }
    }

}
