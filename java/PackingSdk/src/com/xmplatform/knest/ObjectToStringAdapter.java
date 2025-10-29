package com.xmplatform.knest;

import com.google.gson.*;

import java.lang.reflect.Type;

//创建一个专门处理Object到String转换的适配器
class ObjectToStringAdapter implements JsonDeserializer<Object> {
    @Override
    public Object deserialize(JsonElement json, Type typeOfT, JsonDeserializationContext context)
            throws JsonParseException {
        if (json.isJsonNull()) {
            return null;
        }

        // 如果是对象或数组，转换为JSON字符串
        if (json.isJsonObject() || json.isJsonArray()) {
            return json.toString();
        }

        // 如果是基本类型，直接获取字符串值
        if (json.isJsonPrimitive()) {
            JsonPrimitive primitive = json.getAsJsonPrimitive();
            if (primitive.isString()) {
                return primitive.getAsString();
            } else if (primitive.isNumber()) {
                return primitive.getAsString();  // 将数字转换为字符串
            } else if (primitive.isBoolean()) {
                return Boolean.toString(primitive.getAsBoolean());
            }
        }

        return json.toString();
    }
}

