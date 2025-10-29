package com.xmplatform.knest;
import com.sun.jna.Callback;
import com.sun.jna.Pointer;

//回调的接口
public interface PackingSdkCallbackVoid extends Callback {
    //回调函数
    void callback(Pointer sdk, Pointer data);
}

