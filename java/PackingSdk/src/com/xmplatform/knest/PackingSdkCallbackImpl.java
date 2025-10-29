package com.xmplatform.knest;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.sun.jna.Pointer;

// 回调接口的实现
public class PackingSdkCallbackImpl implements PackingSdkCallback {
    @Override
    public boolean callback(Pointer sdk, Pointer data) {
        //System.out.println("sdk:" + sdk);
        //从指针中获取字符串
        String dataString = data.getString(0);
        //如果字符串非空，则转换为SolverOutput对象
        if(dataString != null && !dataString.isEmpty()){
            //使用Gson将json字符串转换为SolverOutput对象
            Gson gson = new GsonBuilder().create();
            SolverOutput solverOutput = gson.fromJson(dataString, SolverOutput.class);
            //将jsonResult的值打印出来
            System.out.println("solverOutput.jsonResult:" + solverOutput.getJsonResult());
        }else{
            System.out.println("no result");
        }
        //默认返回false，表示不要停止优化
        return false;
    }
}