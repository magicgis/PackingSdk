package com.xmplatform.knest.tests;
import com.sun.jna.Memory;
import com.sun.jna.Pointer;
import com.sun.jna.ptr.LongByReference;
import com.sun.jna.ptr.PointerByReference;
import com.xmplatform.knest.EnvUtils;
import com.xmplatform.knest.PackingSdk;
import org.junit.FixMethodOrder;
import org.junit.Test;
import org.junit.runners.MethodSorters;
import java.io.IOException;
import java.net.URISyntaxException;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
/**
 * 无论何种加密狗类型(usb加密狗、离线加密狗)都适用的测试用例
 */
@FixMethodOrder(MethodSorters.NAME_ASCENDING)
public class TestCaseCommon {
    //设置日志级别
    @Test
    public void setLogLevel() throws URISyntaxException, IOException {
        //如果jdk是64位的，则使用copyX64Dll()，如果jdk是32位的，则使用copyX86Dll()
        EnvUtils.copyX64Dll();
        PackingSdk.NATIVE.setLogLevel(1);//Trace = 1,Debug = 2,Info = 3,Warn = 4,Error = 5,Fatal = 6,Off = 7
        PackingSdk.NATIVE.helloWorld();//在日志级别为1的情况下会输出Hello world
    }
    //获取加密狗code
    @Test
    public void getDogCode() throws URISyntaxException, IOException {
        //如果jdk是64位的，则使用copyX64Dll()，如果jdk是32位的，则使用copyX86Dll()
        EnvUtils.copyX64Dll();
        //获取加密狗的code
        Pointer dogCodePointer = PackingSdk.NATIVE.getDogCode();
        String dogCode = dogCodePointer.getString(0);
        if (dogCodePointer != null) {
            PointerByReference ptrRef = new PointerByReference(dogCodePointer);
            PackingSdk.NATIVE.charFree(ptrRef);
        }
        System.out.println("Dog code: " + dogCode);
        assertTrue(dogCode != null && !"".equals(dogCode));
    }
    //获取加密狗code2
    @Test
    public void getDogCode2() throws URISyntaxException, IOException {
        //如果jdk是64位的，则使用copyX64Dll()，如果jdk是32位的，则使用copyX86Dll()
        EnvUtils.copyX64Dll();
        //获取加密狗的code
        PointerByReference dogCodePref = new PointerByReference(); // 相当于 char**
        int result = PackingSdk.NATIVE.getDogCode2(dogCodePref);
        if (result == 0) {
            // 从 PointerByReference 中读取字符串
            Pointer p = dogCodePref.getValue();
            String dogCode = p.getString(0); // 读取 C 字符串
            System.out.println("Dog Code: " + dogCode);
            assertTrue(dogCode != null && !"".equals(dogCode));
        } else {
            System.err.println("Failed to get dog code!");
        }
    }
    //根据加密狗类型获取加密狗code
    @Test
    public void getDogCodeByDogType() throws URISyntaxException, IOException {
        //如果jdk是64位的，则使用copyX64Dll()，如果jdk是32位的，则使用copyX86Dll()
        EnvUtils.copyX64Dll();
        //获取加密狗的类型
        Pointer dogCodePointer = PackingSdk.NATIVE.getDogCodeByDogType(1);
        String dogCode = dogCodePointer.getString(0);
        System.out.println("Dog code: " + dogCode);
        assertTrue(dogCode != null && !"".equals(dogCode));
        if (dogCodePointer != null) {
            PointerByReference ptrRef = new PointerByReference(dogCodePointer);
            PackingSdk.NATIVE.charFree(ptrRef);
        }
    }
    //根据加密狗类型获取加密狗code2
    @Test
    public void getDogCodeByDogType2() throws URISyntaxException, IOException {
        //如果jdk是64位的，则使用copyX64Dll()，如果jdk是32位的，则使用copyX86Dll()
        EnvUtils.copyX64Dll();
        //获取加密狗的code
        PointerByReference dogCodePref = new PointerByReference(); // 相当于 char**
        int result = PackingSdk.NATIVE.getDogCodeByDogType2(1, dogCodePref);
        if (result == 0) {
            // 从 PointerByReference 中读取字符串
            Pointer p = dogCodePref.getValue();
            String dogCode = p.getString(0); // 读取 C 字符串
            System.out.println("Dog Code: " + dogCode);
            assertTrue(dogCode != null && !"".equals(dogCode));
        } else {
            System.err.println("Failed to get dog code!");
        }
    }
    //加密狗是否可用
    @Test
    public void isDogValid() throws URISyntaxException, IOException {
        //如果jdk是64位的，则使用copyX64Dll()，如果jdk是32位的，则使用copyX86Dll()
        EnvUtils.copyX64Dll();
        boolean isDogValid = PackingSdk.NATIVE.isDogValid();
        System.out.println("IsDogValid: " + isDogValid);
        assertTrue(isDogValid);
    }
    //往加密狗中写入数据-数字5
    @Test
    public void writeDog() throws URISyntaxException, IOException {
        //如果jdk是64位的，则使用copyX64Dll()，如果jdk是32位的，则使用copyX86Dll()
        EnvUtils.copyX64Dll();
        //写入数据到加密狗
        int offset = 1;//要写入的地址
        int dataLength = 1;//要写入的数据的长度
        byte[] dataToWrite = "5".getBytes();// 假设你要写入的数据为5
        Pointer dataPointer = new Memory(dataToWrite.length);// 为数据分配内存并初始化
        dataPointer.write(0, dataToWrite, 0, dataToWrite.length);
        int result = PackingSdk.NATIVE.writeDog(offset, dataLength, dataPointer);//调用往加密狗写入数据的函数
        if(result == 0){
            System.out.println("WriteDog succeed");
        }else {
            System.err.println("Failed to writeDog：" + result);
        }
        assertTrue(result == 0);
    }
    //读取加密狗数据-数字5
    @Test
    public void readDog() throws URISyntaxException, IOException {
        //如果jdk是64位的，则使用copyX64Dll()，如果jdk是32位的，则使用copyX86Dll()
        EnvUtils.copyX64Dll();
        int offset = 1;//要读取的地址
        int dataLength = 1;//要读取的数据的长度
        //读取加密狗的数据
        Memory readDataPointer = new Memory(dataLength);
        int result = PackingSdk.NATIVE.readDog(offset, dataLength, readDataPointer);//读取加密狗数据
        if(result == 0){
            System.out.println("ReadDog succeed");
            // 从内存中读取数据并转换为byte，并打印
            byte value = readDataPointer.getByte(0);
            String str = String.valueOf((char) value);
            System.out.println("ReadDog value: " + str);
            assertTrue("5".equals(str));
        }else {
            System.err.println("Failed to readDog：" + result);
        }
        assertTrue(result == 0);
    }
    //往加密狗中写入数据-char数组
    @Test
    public void writeDogArray() throws URISyntaxException, IOException {
        //如果jdk是64位的，则使用copyX64Dll()，如果jdk是32位的，则使用copyX86Dll()
        EnvUtils.copyX64Dll();
        //写入数据到加密狗
        int offset = 300;//要写入的地址
        int dataLength = 16;//要写入的数据的长度
        byte[] dataToWrite = new byte[17]; // 相当于 unsigned char[17]
        {
            dataToWrite[0] = (byte) 0xb0;
            dataToWrite[1] = (byte) 0x02;
            dataToWrite[2] = (byte) 0x00;
            dataToWrite[3] = (byte) 0x69;
            dataToWrite[4] = (byte) 0x59;
            dataToWrite[5] = (byte) 0x23;
            dataToWrite[6] = (byte) 0x05;
            dataToWrite[7] = (byte) 0xc4;
            dataToWrite[8] = (byte) 0x66;
            dataToWrite[9] = (byte) 0x77;
            dataToWrite[10] = (byte) 0x43;
            dataToWrite[11] = (byte) 0x65;
            dataToWrite[12] = (byte) 0x77;
            dataToWrite[13] = (byte) 0x75;
            dataToWrite[14] = (byte) 0x54;
            dataToWrite[15] = (byte) 0x43;
            dataToWrite[16] = (byte) 0x00;
        }
        System.out.print("write:");
        for (int i = 0; i < dataLength; i++) {
            System.out.printf("%02X ", dataToWrite[i] & 0xFF);  // 使用 & 0xFF 处理符号位
        }
        System.out.println();

        // 打印字符形式
        System.out.print("write:");
        for (int i = 0; i < dataLength; i++) {
            char c = (char) (dataToWrite[i] & 0xFF);
            System.out.printf("%04X ", (int) c);  // 使用 %04X 打印字符的Unicode码
        }
        Pointer dataPointer = new Memory(dataToWrite.length);// 为数据分配内存并初始化
        dataPointer.write(0, dataToWrite, 0, dataToWrite.length);
        int result = PackingSdk.NATIVE.writeDog(offset, dataLength, dataPointer);//调用往加密狗写入数据的函数
        if(result == 0){
            System.out.println("WriteDog succeed");
        }else {
            System.err.println("Failed to writeDog：" + result);
        }
        assertTrue(result == 0);
    }
    //读取加密狗数据-char数组
    @Test
    public void readDogArray() throws URISyntaxException, IOException {
        //如果jdk是64位的，则使用copyX64Dll()，如果jdk是32位的，则使用copyX86Dll()
        EnvUtils.copyX64Dll();
        int offset = 300;//要读取的地址
        int dataLength = 16;//要读取的数据的长度
        //读取加密狗的数据
        Pointer readDataPointer = new Memory(dataLength);
        int result = PackingSdk.NATIVE.readDog(offset, dataLength, readDataPointer);//读取加密狗数据
        if(result == 0){
            System.out.println("readDog succeed");
            // 从内存中读取数据并转换为byte，并打印
            // 逐个字节打印（处理符号位）
            System.out.print("char :");
            for (int i = 0; i < dataLength; i++) {
                byte b = readDataPointer.getByte(i);
                System.out.printf("%02X ", b & 0xFF);
            }
            assertTrue(readDataPointer.getByte(15) == 0x43);
            System.out.println();
            // 打印字符形式
            System.out.print("read:");
            for (int i = 0; i < dataLength; i++) {
                char c = (char) (readDataPointer.getByte(i) & 0xFF);
                System.out.printf("%04X ", (int) c);  // 使用 %04X 打印字符的Unicode码
            }
        }else {
            System.err.println("Failed to readDog：" + result);
        }
        assertTrue(result == 0);
    }
    //是否支持获取时间
    @Test
    public void supportGetDogTime() throws URISyntaxException, IOException {
        //如果jdk是64位的，则使用copyX64Dll()，如果jdk是32位的，则使用copyX86Dll()
        EnvUtils.copyX64Dll();
        int isSupport = PackingSdk.NATIVE.supportGetDogTime();
        if(isSupport == 0){
            System.err.println("Current dog don't supports get time.");
        }else{
            System.out.println("Current dog supports get time.");
        }
        assertEquals(isSupport, 0);//0表示不支持获取时间
    }
    //获取时间（从 1970 年 1 月 1 日开始经过的秒数）
    @Test
    public void getDogTime() throws URISyntaxException, IOException {
        //如果jdk是64位的，则使用copyX64Dll()，如果jdk是32位的，则使用copyX86Dll()
        EnvUtils.copyX64Dll();
        //获取时间
        LongByReference longPtr = new LongByReference(0L);
        Pointer rawPointer = longPtr.getPointer();
        int result = PackingSdk.NATIVE.getDogTime(rawPointer);
        if(result == 0){
            System.out.println("GetDogTime succeed");
        }else {
            System.err.println("Failed to getDogTime：" + result);
        }
        System.out.println("GetDogTime value：" + rawPointer.getLong(0));
        //assertEquals(result, 3);//错误码3表示当前加密狗无此函数的实现
        assertEquals(rawPointer.getLong(0), 0);
    }
    //获取加密狗类型
    @Test
    public void getDogType() throws URISyntaxException, IOException {
        //如果jdk是64位的，则使用copyX64Dll()，如果jdk是32位的，则使用copyX86Dll()
        EnvUtils.copyX64Dll();
        //获取加密狗类型 0表示未定义 1表示USB加密狗 2表示离线的加密狗
        int dogType = PackingSdk.NATIVE.getDogType();
        if(dogType == 0){
            System.out.println("Current dog is not defined.");
        }else if(dogType == 1){
            System.out.println("Current dog is usb dog.");
        }else if(dogType == 2){
            System.out.println("Current dog is offline dog.");
        }
        assertTrue(dogType > 0);
    }
    //获取加密狗的套餐类型
    @Test
    public void getDogSuite() throws URISyntaxException, IOException {
        //如果jdk是64位的，则使用copyX64Dll()，如果jdk是32位的，则使用copyX86Dll()
        EnvUtils.copyX64Dll();
        //获取加密狗类型 0表示未定义 1表示USB加密狗 2表示离线的加密狗
        int dogSuite = PackingSdk.NATIVE.getDogSuite();
        if(dogSuite == 0){
            System.out.println("Current dog suite is not defined.");
        }else if(dogSuite == 1){
            System.out.println("Current dog suite is Base.");
        }else if(dogSuite == 2){
            System.out.println("Current dog suite is Advance.");
        }
        assertTrue(dogSuite > 0);
    }
}
