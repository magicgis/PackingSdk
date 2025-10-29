package com.xmplatform.knest;

/**
 * @Description 算法结束原因
 */
public enum SolverEndedReason {
    None("无"),//0无
    Normal("正常结束"),//1正常结束(算法已计算出最优结果)
    WrongParam("输入数据或者输入参数不合法而终止"),//2输入数据或者输入参数不合法而终止
    DogError("没有找到硬件狗，或者其他硬件狗错误"),//3没有找到硬件狗，或者其他硬件狗错误
    ReachCondition("达到最大迭代次数、最大收敛条件等而终止"),//4达到最大迭代次数、最大收敛条件等而终止
    TimeOut("达到用户设置的最大等待时间"),//5达到用户设置的最大等待时间(得到优化结果后，等待多长时间内再无优化结果，则算法停止运行)而终止
    UserCancel("用户中断"),//6用户中断
    CallBackToStop("回调函数返回true从而终止"),//7回调函数返回true从而终止
    ExceptionExit("异常结束");//8异常结束


    private String name;//中文名称
    //构造方法，将中文名称放入name变量
    private SolverEndedReason(String name) {
        this.name = name;
    }
    public String getName() {
        return name;
    }
}