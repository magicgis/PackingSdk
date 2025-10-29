package com.xmplatform.knest;

/**
 * @Description 算法当前状态
 */
public enum SolverState {
    READY("已准备好"),//0已准备好
    RUNNING("运行中"),//1运行中
    PAUSED("暂停中"),//2暂停中
    ENDED("结束");//3结束

    private String name;//中文名称
    //构造方法，将中文名称放入name变量
    private SolverState(String name) {
        this.name = name;
    }
    public String getName() {
        return name;
    }
};
