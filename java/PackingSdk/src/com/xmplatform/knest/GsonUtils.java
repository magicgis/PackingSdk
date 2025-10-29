package com.xmplatform.knest;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.JsonSyntaxException;

import java.lang.reflect.Type;

/**
 * Gson序列化反序列化工具类
 * 用于处理knest包中所有数据结构的JSON转换
 */
public class GsonUtils {
    // 单例Gson实例，配置格式化输出和处理null值
    private static final Gson gson = new GsonBuilder()
            .setPrettyPrinting()           // 格式化输出
            .serializeNulls()              // 序列化null值
            .create();

    // 简单Gson实例，不格式化输出（用于紧凑JSON）
    private static final Gson compactGson = new GsonBuilder()
            .serializeNulls()
            .create();

    /**
     * 将对象序列化为JSON字符串（格式化输出）
     * @param object 要序列化的对象
     * @return JSON字符串
     */
    public static String toJson(Object object) {
        if (object == null) {
            return null;
        }
        return gson.toJson(object);
    }

    /**
     * 将对象序列化为JSON字符串（紧凑输出）
     * @param object 要序列化的对象
     * @return 紧凑的JSON字符串
     */
    public static String toCompactJson(Object object) {
        if (object == null) {
            return null;
        }
        return compactGson.toJson(object);
    }

    /**
     * 从JSON字符串反序列化为指定类型的对象
     * @param json JSON字符串
     * @param clazz 目标类的Class对象
     * @param <T> 目标类型
     * @return 反序列化后的对象
     * @throws JsonSyntaxException JSON语法错误时抛出异常
     */
    public static <T> T fromJson(String json, Class<T> clazz) throws JsonSyntaxException {
        if (json == null || json.trim().isEmpty()) {
            return null;
        }
        return gson.fromJson(json, clazz);
    }

    /**
     * 从JSON字符串反序列化为指定类型的对象（使用Type）
     * @param json JSON字符串
     * @param type 目标类型的Type对象
     * @param <T> 目标类型
     * @return 反序列化后的对象
     * @throws JsonSyntaxException JSON语法错误时抛出异常
     */
    public static <T> T fromJson(String json, Type type) throws JsonSyntaxException {
        if (json == null || json.trim().isEmpty()) {
            return null;
        }
        return gson.fromJson(json, type);
    }
}
