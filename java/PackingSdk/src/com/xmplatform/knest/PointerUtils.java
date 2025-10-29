package com.xmplatform.knest;
import com.sun.jna.Pointer;
import java.io.UnsupportedEncodingException;

/**
 * 指针Pointer工具类
 */
public class PointerUtils {
    public static String getString(Pointer pointer, String encoding) {
        long len = pointer.indexOf(0, (byte)0);
        if (len != -1L) {
            if (len > 2147483647L) {
                throw new OutOfMemoryError("String exceeds maximum length: " + len);
            }

            byte[] data = pointer.getByteArray(0, (int)len);

            try {
                return new String(data, encoding);
            } catch (UnsupportedEncodingException var8) {
            }
        }

        return pointer.getString(0);
    }

    public static void setString(Pointer pointer, String value, String encoding) {
        byte[] data = new byte[0];
        try {
            data = value.getBytes(encoding);
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        pointer.write(0, (byte[])data, 0, data.length);
        pointer.setByte(0 + (long)data.length, (byte)0);
    }
}
