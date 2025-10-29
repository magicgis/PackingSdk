package com.xmplatform.knest.tests;

import com.sun.jna.Memory;
import com.sun.jna.Pointer;
import com.sun.jna.ptr.IntByReference;
import com.sun.jna.ptr.LongByReference;
import com.xmplatform.knest.EnvUtils;
import com.xmplatform.knest.PackingSdk;
import com.xmplatform.knest.PointerUtils;
import org.junit.FixMethodOrder;
import org.junit.Test;
import org.junit.runners.MethodSorters;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.net.URISyntaxException;
import static org.junit.Assert.assertTrue;

/**
 * 离线加密狗相关测试样例
 */
@FixMethodOrder(MethodSorters.NAME_ASCENDING)//测试函数按照函数名升序执行
public class TestCaseOffline{
    //强制取消/删除本机离线授权
    @Test
    public void testA_cancelOfflineLicenseForce() throws URISyntaxException, IOException {
        //如果jdk是64位的，则使用copyX64Dll()，如果jdk是32位的，则使用copyX86Dll()
        EnvUtils.copyX64Dll();
        int result = PackingSdk.NATIVE.cancelOfflineLicenseForce(true);//返回0表示成功
        if(result == 0){
            System.out.println("CancelOfflineLicenseForce succeed");
        }else {
            System.err.println("Failed to cancelOfflineLicenseForce：" + result);
        }
        assertTrue(result == 0);
    }
    //注册离线授权
    @Test
    public void testB_registerOfflineLicense() throws URISyntaxException, IOException {
        //如果jdk是64位的，则使用copyX64Dll()，如果jdk是32位的，则使用copyX86Dll()
        EnvUtils.copyX64Dll();
        //注册离线授权
        String registerCode = "BAS-BA2I-OPKQ-76PO-13TH";//注册码
        String registerParams = "{\"a\":1, \"b\":2}";//注册的时候需要放入授权的参数
        //将数据放入指针内
        Pointer registerCodePointer = new Memory(registerCode.length()*2);
        registerCodePointer.setMemory(0, registerCode.length()*2, (byte)0);
        PointerUtils.setString(registerCodePointer, registerCode, "UTF-8");

        Pointer registerParamsPointer = new Memory(registerParams.length()*2);
        registerParamsPointer.setMemory(0, registerParams.length()*2, (byte)0);
        PointerUtils.setString(registerParamsPointer, registerParams, "UTF-8");
        //执行注册
        int result = PackingSdk.NATIVE.registerOfflineLicense(registerCodePointer, registerParamsPointer);
        if(result == 0){
            System.out.println("RegisterOfflineLicense succeed");
        }else {
            System.err.println("Failed to registerOfflineLicense：" + result);
        }
        assertTrue(result == 0);
    }
    //取消/删除本机离线授权
    @Test
    public void testC_cancelOfflineLicense() throws URISyntaxException, IOException {
        //如果jdk是64位的，则使用copyX64Dll()，如果jdk是32位的，则使用copyX86Dll()
        EnvUtils.copyX64Dll();
        int result = PackingSdk.NATIVE.cancelOfflineLicense();//返回0表示成功
        if(result == 0){
            System.out.println("cancelOfflineLicense succeed");
        }else {
            System.err.println("Failed to cancelOfflineLicense：" + result);
        }
        assertTrue(result == 0);
    }
    //重新注册离线授权
    @Test
    public void testD_registerOfflineLicenseWithLastMachineCode() throws URISyntaxException, IOException {
        //如果jdk是64位的，则使用copyX64Dll()，如果jdk是32位的，则使用copyX86Dll()
        EnvUtils.copyX64Dll();
        //重新注册离线授权
        String registerCode = "TRI-ZB3W-6UNO-B4I5-41YO";//注册码
        String dogCode = "";//本机重新注册时dogCode为空，当非本机重新注册时，dogCode放入原已注册电脑的dogCode(通过getDogCode获取)
        String registerParams = "{\"a\":\"test\", \"b\":2}";//注册的时候需要放入授权的参数
        //将注册码数据放入指针内
        Pointer registerCodePointer = new Memory(registerCode.length()*2);
        registerCodePointer.setMemory(0, registerCode.length()*2, (byte)0);
        PointerUtils.setString(registerCodePointer, registerCode, "UTF-8");
        //将机器码数据放入指针内
        Pointer dogCodePointer = new Memory(dogCode.length()==0?1:dogCode.length()* 2L);
        dogCodePointer.setMemory(0, dogCode.length()==0?1:dogCode.length()*2, (byte)0);
        PointerUtils.setString(dogCodePointer, dogCode, "UTF-8");
        //将注册参数数据放入指针内
        Pointer registerParamsPointer = new Memory(registerParams.length()*2);
        registerParamsPointer.setMemory(0, registerParams.length()*2, (byte)0);
        PointerUtils.setString(registerParamsPointer, registerParams, "UTF-8");

        int errorCode = PackingSdk.NATIVE.registerOfflineLicenseWithLastMachineCode(registerCodePointer, dogCodePointer, registerParamsPointer);//返回0表示成功
        if(errorCode == 0){
            System.out.println("RegisterOfflineLicenseWithLastMachineCode succeed");
        }else {
            System.err.println("Failed to registerOfflineLicenseWithLastMachineCode：" + errorCode);
        }
        assertTrue(errorCode == 0);
    }
    //获取当前离线授权剩余天数
    @Test
    public void testE_getOfflineDogRestDays() throws URISyntaxException, IOException {
        //如果jdk是64位的，则使用copyX64Dll()，如果jdk是32位的，则使用copyX86Dll()
        EnvUtils.copyX64Dll();
        //获取当前离线授权剩余天数
        IntByReference daysPtr = new IntByReference(0);
        Pointer rawPointer = daysPtr.getPointer();
        int result = PackingSdk.NATIVE.getOfflineDogRestDays(rawPointer);//返回0表示成功
        if(result == 0){
            System.out.println("GetOfflineDogRestDays succeed");
            System.out.println("GetOfflineDogRestDays value：" + rawPointer.getInt(0));//0表示已经过期，-1表示没有时间限制，其他正数表示剩余的天数
        }else {
            System.err.println("Failed to getOfflineDogRestDays：" + result);
        }
        assertTrue(result == 0);
    }


    //根据key读取离线加密狗的参数的值
    @Test
    public void testF_readOfflineDog() throws URISyntaxException, IOException {
        //如果jdk是64位的，则使用copyX64Dll()，如果jdk是32位的，则使用copyX86Dll()
        EnvUtils.copyX64Dll();

        // 设置缓冲区大小
        int bufferSize = 1024;
        // 创建缓冲区并初始化为0
        Pointer buffer = new Memory(bufferSize);
        buffer.clear(bufferSize); // 将内存区域清零
        String key = "a";//键
        //将key数据放入指针内
        Pointer keyPointer = new Memory(key.length()*2);
        keyPointer.setMemory(0, key.length()*2, (byte)0);
        PointerUtils.setString(keyPointer, key, "UTF-8");
        // 调用 readOfflineDog 函数
        int errorCode = PackingSdk.NATIVE.readOfflineDog(keyPointer, buffer);//返回0表示成功
        // 打印错误码
        System.out.println("==readOfflineDog errorCode:" + errorCode);
        // 处理返回的数据
        if (errorCode == 0) {
            try {
                // 从指针读取字节数据
                byte[] byteArray = buffer.getByteArray(0, bufferSize);
                // 找到第一个null终止符的位置
                int length = 0;
                while (length < byteArray.length && byteArray[length] != 0) {
                    length++;
                }
                // 提取有效数据
                byte[] validData = new byte[length];
                System.arraycopy(byteArray, 0, validData, 0, length);
                // 假设数据是UTF-8编码，转换为字符串
                String result = new String(validData, "UTF-8");
                // 打印结果
                System.out.println("==readOfflineDog result:" + result);
            } catch (UnsupportedEncodingException e) {
                System.err.println("UTF-8 encoding not supported: " + e.getMessage());
            }
        } else {
            System.err.println("Failed to read offline dog, error code: " + errorCode);
        }
        assertTrue(errorCode == 0);
    }


    //根据key读取离线加密狗的参数的值
    @Test
    public void testF_writeOfflineDog() throws URISyntaxException, IOException {
        //如果jdk是64位的，则使用copyX64Dll()，如果jdk是32位的，则使用copyX86Dll()
        EnvUtils.copyX64Dll();

        String key = "key1";//键
        String value = "value1";//值
        //将key数据放入指针内
        Pointer keyPointer = new Memory(key.length()*2);
        keyPointer.setMemory(0, key.length()*2, (byte)0);
        PointerUtils.setString(keyPointer, key, "UTF-8");
        //将value数据放入指针内
        Pointer valuePointer = new Memory(value.length()*2);
        valuePointer.setMemory(0, value.length()*2, (byte)0);
        PointerUtils.setString(valuePointer, value, "UTF-8");
        // 调用 writeOfflineDog 函数
        int errorCode = PackingSdk.NATIVE.writeOfflineDog(keyPointer, valuePointer);//返回0表示成功
        // 打印错误码
        System.out.println("writeOfflineDog errorCode:" + errorCode);
        // 处理返回的数据
        if (errorCode == 0) {
            System.out.println("writeOfflineDog result:" + errorCode);
        } else {
            System.err.println("Failed to write offline dog, error code: " + errorCode);
        }
        assertTrue(errorCode == 0);
    }


    //将参数提前写入到注册码对应的参数中
    @Test
    public void testG_writeParameterByRegisterCode() throws URISyntaxException, IOException {
        //如果jdk是64位的，则使用copyX64Dll()，如果jdk是32位的，则使用copyX86Dll()
        EnvUtils.copyX64Dll();

        String registerCode = "TRI-ZB3W-6UNO-B4I5-41YO";//注册码
        String key = "key1";//键
        String value = "value2";//值
        //将数据放入指针内
        Pointer registerCodePointer = new Memory(registerCode.length()*2);
        registerCodePointer.setMemory(0, registerCode.length()*2, (byte)0);
        PointerUtils.setString(registerCodePointer, registerCode, "UTF-8");

        Pointer keyPointer = new Memory(key.length()==0?1:key.length()* 2L);
        keyPointer.setMemory(0, key.length()==0?1:key.length()*2, (byte)0);
        PointerUtils.setString(keyPointer, key, "UTF-8");

        Pointer valuePointer = new Memory(value.length()*2);
        valuePointer.setMemory(0, value.length()*2, (byte)0);
        PointerUtils.setString(valuePointer, value, "UTF-8");

        int result = PackingSdk.NATIVE.writeParameterByRegisterCode(registerCodePointer, keyPointer, valuePointer, false);//返回0表示成功
        if(result == 0){
            System.out.println("WriteParameterByRegisterCode succeed");
        }else {
            System.err.println("Failed to writeParameterByRegisterCode：" + result);
        }
        assertTrue(result == 0);
    }

    //从服务器读取离线加密狗的提前参数
    @Test
    public void testH_readParameterByRegisterCode() throws URISyntaxException, IOException {
        //如果jdk是64位的，则使用copyX64Dll()，如果jdk是32位的，则使用copyX86Dll()
        EnvUtils.copyX64Dll();

        String registerCode = "TRI-ZB3W-6UNO-B4I5-41YO";//注册码
        String key = "key1";//键
        //将数据放入指针内
        Pointer registerCodePointer = new Memory(registerCode.length()*2);
        registerCodePointer.setMemory(0, registerCode.length()*2, (byte)0);
        PointerUtils.setString(registerCodePointer, registerCode, "UTF-8");

        Pointer keyPointer = new Memory(key.length()==0?1:key.length()* 2L);
        keyPointer.setMemory(0, key.length()==0?1:key.length()*2, (byte)0);
        PointerUtils.setString(keyPointer, key, "UTF-8");

        //读取int值
        int bufferSize = 4; // int通常占4字节
        Pointer buffer = new Memory(bufferSize);
        buffer.clear(bufferSize);
        int errorCode = PackingSdk.NATIVE.readParameterByRegisterCode(registerCodePointer, keyPointer, buffer);
        if (errorCode == 0) {
            // 直接从buffer中读取int值
            int result = buffer.getInt(0);
            System.out.println("==readParameterByRegisterCode int result:" + result);
        } else {
            System.err.println("Failed to readParameterByRegisterCode, error code: " + errorCode);
        }

        //读取float值
        bufferSize = 4; // float通常占4字节
        buffer = new Memory(bufferSize);
        buffer.clear(bufferSize);
        errorCode = PackingSdk.NATIVE.readParameterByRegisterCode(registerCodePointer, keyPointer, buffer);
        if (errorCode == 0) {
            // 直接从buffer中读取float值
            float result = buffer.getFloat(0);
            System.out.println("==readParameterByRegisterCode float result:" + result);
        } else {
            System.err.println("Failed to readParameterByRegisterCode, error code: " + errorCode);
        }


        //读取字符串
        bufferSize = 1024;//设置缓冲区大小
        // 创建缓冲区并初始化为0
        buffer = new Memory(bufferSize);
        buffer.clear(bufferSize); // 将内存区域清零
        errorCode = PackingSdk.NATIVE.readParameterByRegisterCode(registerCodePointer, keyPointer, buffer);//返回0表示成功
        // 处理返回的数据
        if (errorCode == 0) {
            try {
                // 从指针读取字节数据
                byte[] byteArray = buffer.getByteArray(0, bufferSize);
                // 找到第一个null终止符的位置
                int length = 0;
                while (length < byteArray.length && byteArray[length] != 0) {
                    length++;
                }
                // 提取有效数据
                byte[] validData = new byte[length];
                System.arraycopy(byteArray, 0, validData, 0, length);
                // 假设数据是UTF-8编码，转换为字符串
                String result = new String(validData, "UTF-8");
                // 打印结果
                System.out.println("==readParameterByRegisterCode string result:" + result);
            } catch (UnsupportedEncodingException e) {
                System.err.println("UTF-8 encoding not supported: " + e.getMessage());
            }
        } else {
            System.err.println("Failed to readParameterByRegisterCode, error code: " + errorCode);
        }


        assertTrue(errorCode == 0);
    }

    //向服务器读取指定注册码的状态
    @Test
    public void testI_readRegisterCodeStatus() throws URISyntaxException, IOException {
        //如果jdk是64位的，则使用copyX64Dll()，如果jdk是32位的，则使用copyX86Dll()
        EnvUtils.copyX64Dll();

        String registerCode = "TRI-ZB3W-6UNO-B4I5-41YO";//注册码
        //将数据放入指针内
        Pointer registerCodePointer = new Memory(registerCode.length()*2);
        registerCodePointer.setMemory(0, registerCode.length()*2, (byte)0);
        PointerUtils.setString(registerCodePointer, registerCode, "UTF-8");
        //状态指针
        IntByReference intPtr = new IntByReference(0);
        Pointer rawPointer = intPtr.getPointer();
        //readRegisterCodeStatus
        int errorCode = PackingSdk.NATIVE.readRegisterCodeStatus(registerCodePointer, rawPointer);
        if (errorCode == 0) {
            System.out.println("==readRegisterCodeStatus status result:" + rawPointer.getInt(0));
        } else {
            System.err.println("Failed to readParameterByRegisterCode, error code: " + errorCode);
        }
        assertTrue(errorCode == 0);
    }


}
