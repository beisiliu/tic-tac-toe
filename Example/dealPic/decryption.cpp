#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void decryption(char* fileUrl, char* newFileUrl);

int main()
{
    decryption("enicons.png", "icons123.png");
}

// char* fileUrl 需要解密的文件
// char* newFileUrl 解密后的文件
void decryption(char* fileUrl, char* newFileUrl) 
{
    printf("file decryption....\n");
    //TODO 二进制读取旧的文件 写入到新的文件生成一个新的加密的文件
    //参数一:文件路径
    //参数二: "r"读取文件 "w" 写入文件 "rb"作为二进制文件读取  "rw"作为二进制文件写
    FILE *file = fopen(fileUrl, "rb");
    FILE *newFile = fopen(newFileUrl, "wb");

    if (!file || !newFile) {
        printf("open file error, check file %s", fileUrl);
        exit(0);    //结束程序
    }
    //密钥 (根据密钥来加密)
    char *password = "891124";

    //接收读取的值
    int c;
    //用来设置密钥
    int index = 0;

    //TODO EOF = end of file 表示结束 
    while ((c = fgetc(file) )!= EOF) {
        //CC为最终密钥
        int cc = password[index++ % strlen(password)];
        //写入文件的时候,
        fputc(c ^ cc, newFile);
    }
    printf("file decryption success !!\n");
    //文件关闭
    fclose(file);
    fclose(newFile);
}