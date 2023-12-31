#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
//
// Created by szj on 2021/4/22.
//
int main() {
    printf("C语言 图片加密....\n");
    //图片加密与解密

    //需要加密的地址
    char *flieUrl = "icons.png";
    //加密后的地址
    char *newFlieUrl = "enicons.png";

    //密钥 (根据密钥来加密)
    char *password = "891124";

    //TODO 二进制读取旧的文件 写入到新的文件生成一个新的加密的文件
    //参数一:文件路径
    //参数二: "r"读取文件 "w" 写入文件 "rb"作为二进制文件读取  "rw"作为二进制文件写
    FILE *file = fopen(flieUrl, "rb");
    FILE *newFlie = fopen(newFlieUrl, "wb");

    if (!file || !newFlie) {
        printf("打开失败,请检查路径%s", flieUrl);
        exit(0);    //结束程序
    }

    //接收读取的值
    int c;
    //用来设置密钥
    int index = 0;

    //TODO EOF = end of flie 表示结束
    while ((c = fgetc(file)) != EOF) {
        //CC为最终密钥
        int cc = password[index++ % strlen(password)];
        //写入文件的时候,
        fputc(c ^ cc, newFlie);
    }
    printf("文件加密成功!!\n");
    printf("文件加密原路径为:%s\n", flieUrl);
    printf("文件加密新路径为:%s", newFlieUrl);
    //文件关闭
    fclose(file);
    fclose(newFlie);

    return 0;
}