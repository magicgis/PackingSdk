package com.xmplatform.knest;

import java.io.IOException;
import java.io.InputStream;
import java.net.URI;
import java.net.URISyntaxException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardCopyOption;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Objects;

/**
 * 用于构建相关运行环境的工具类
 */
public class EnvUtils {
    /**
     * 拷贝64位的dll到编译目标目录（jna会搜索编译目标目录，找到并加载对应的dll）
     */
    public static void copyX64Dll() throws URISyntaxException, IOException {
        //将相关dll拷贝至编译目标目录
        URI uri = EnvUtils.class.getClass().getResource("/").toURI();
        Path outPath = Paths.get(uri);
        String outputPath = outPath.toString();
        String projectPath = Paths.get(System.getProperty("user.dir")).toString();
        //System.out.println("outputPath: " + outputPath);
        Path fromPath = Paths.get(projectPath + "\\Lib\\x64\\packing.dll");
        Path toPath = Paths.get(outputPath + "\\packing.dll");
        if(isFileTheSame(toPath, fromPath) == false){
            Files.copy(fromPath, toPath, StandardCopyOption.REPLACE_EXISTING);
            //拷贝rsa
            fromPath = Paths.get(projectPath + "\\Lib\\x64\\rsa.dll");
            toPath = Paths.get(outputPath + "\\rsa.dll");
            Files.copy(fromPath, toPath, StandardCopyOption.REPLACE_EXISTING);
        }
    }
    /**
     * 拷贝32位的dll到编译目标目录（jna会搜索编译目标目录，找到并加载对应的dll）
     */
    public static void copyX86Dll() throws URISyntaxException, IOException {
        //将相关dll拷贝至编译目标目录
        URI uri = EnvUtils.class.getClass().getResource("/").toURI();
        Path outPath = Paths.get(uri);
        String outputPath = outPath.toString();
        String projectPath = Paths.get(System.getProperty("user.dir")).toString();
        //System.out.println("outputPath: " + outputPath);
        Path fromPath = Paths.get(projectPath + "\\Lib\\x86\\packing.dll");
        Path toPath = Paths.get(outputPath + "\\packing.dll");
        if(isFileTheSame(toPath, fromPath) == false){
            Files.copy(fromPath, toPath, StandardCopyOption.REPLACE_EXISTING);
            //拷贝rsa
            fromPath = Paths.get(projectPath + "\\Lib\\x86\\rsa.dll");
            toPath = Paths.get(outputPath + "\\rsa.dll");
            Files.copy(fromPath, toPath, StandardCopyOption.REPLACE_EXISTING);
        }
    }
    /**
     * 检查两个文件是否相同
     * @param targetFile 要检查的目标文件路径
     * @param sourceFile 要检查的原始文件路径
     * @return 如果存在内容相同的文件返回true，否则返回false
     * @throws IllegalArgumentException 如果参数无效
     * @throws IOException 如果发生I/O错误
     */
    public static boolean isFileTheSame(Path targetFile, Path sourceFile) throws IOException {
        // 参数校验
        Objects.requireNonNull(targetFile, "Target file path cannot be null");
        Objects.requireNonNull(sourceFile, "Source file path cannot be null");
        if (!Files.exists(targetFile)) {
            return false;
        }

        if (!Files.isRegularFile(targetFile)) {
            throw new IllegalArgumentException("Target path must be a regular file: " + targetFile);
        }

        // 目标存在但内容不同
        if (isContentDifferent(targetFile, sourceFile)) {
            return false;
        }
        return true;
    }
    /**
     * 通过文件哈希比较内容差异（更可靠但稍慢）
     */
    private static boolean isContentDifferent(Path p1, Path p2) throws IOException {
        // 快速检查：文件大小不同 → 内容必然不同
        if (Files.size(p1) != Files.size(p2)) {
            return true;
        }

        // 完整内容校验（SHA-256哈希）
        byte[] hash1 = computeFileHash(p1);
        byte[] hash2 = computeFileHash(p2);
        return !MessageDigest.isEqual(hash1, hash2);
    }

    /**
     * 计算文件哈希（SHA-256）
     */
    private static byte[] computeFileHash(Path file) throws IOException {
        try {
            MessageDigest digest = MessageDigest.getInstance("SHA-256");
            try (InputStream is = Files.newInputStream(file)) {
                byte[] buffer = new byte[8192];
                int read;
                while ((read = is.read(buffer)) != -1) {
                    digest.update(buffer, 0, read);
                }
            }
            return digest.digest();
        } catch (NoSuchAlgorithmException e) {
            // SHA-256是Java标准算法，理论上不会触发这个异常
            throw new RuntimeException("SHA-256 algorithm not available", e);
        }
    }
    public static void main(String[] args) throws URISyntaxException, IOException {
        EnvUtils.copyX64Dll();
    }
}
