#ifndef FILE_IO_H
#define FILE_IO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <time.h>
#include <sys/stat.h>   // 文件状态
#include <unistd.h>     // 文件操作
#include <dirent.h>     // 目录操作

/*============================================================================
  第一部分：文件基础
============================================================================*/

void part1_file_fundamentals(void) {
    printf("\n");
    printf("================================================\n");
    printf("第一部分：文件基础概念\n");
    printf("================================================\n\n");
    
    /*
     * 1. 文件的基本概念
     */
    printf("1. 文件的基本概念\n\n");
    
    printf("   文件是什么？\n");
    printf("   - 存储在外部介质上的数据集合\n");
    printf("   - 程序与外部世界交互的桥梁\n");
    printf("   - 持久化存储数据的方式\n\n");
    
    printf("   文件的分类：\n");
    printf("   1. 文本文件（Text Files）\n");
    printf("      - 以ASCII码存储\n");
    printf("      - 人类可读\n");
    printf("      - 例如：.txt, .c, .h文件\n\n");
    
    printf("   2. 二进制文件（Binary Files）\n");
    printf("      - 以二进制形式存储\n");
    printf("      - 计算机直接使用\n");
    printf("      - 例如：.exe, .bin, 图片文件\n\n");
    
    /*
     * 2. 文件指针（FILE指针）
     */
    printf("2. 文件指针（FILE指针）\n\n");
    
    printf("   FILE结构体：\n");
    printf("   - 定义在<stdio.h>中\n");
    printf("   - 包含文件的所有控制信息\n");
    printf("   - 用户不需要知道内部细节\n\n");
    
    printf("   文件指针作用：\n");
    printf("   1. 标识打开的文件\n");
    printf("   2. 维护文件位置信息\n");
    printf("   3. 管理文件缓冲区\n");
    printf("   4. 跟踪错误状态\n\n");
    
    printf("   示例：\n");
    printf("   FILE *fp;  // 声明文件指针\n");
    printf("   fp = fopen(\"file.txt\", \"r\");\n");
    printf("   // 使用fp操作文件\n");
    printf("   fclose(fp);\n\n");
    
    /*
     * 3. 标准文件指针
     */
    printf("3. 标准文件指针（预定义）\n\n");
    
    printf("   stdin  - 标准输入（键盘）\n");
    printf("   stdout - 标准输出（屏幕）\n");
    printf("   stderr - 标准错误（屏幕）\n\n");
    
    printf("   它们是全局变量，自动打开\n");
    printf("   不需要fopen和fclose\n");
    printf("   可以重定向到文件\n\n");
    
    printf("   示例：\n");
    printf("   printf() 相当于 fprintf(stdout, ...)\n");
    printf("   scanf()  相当于 fscanf(stdin, ...)\n\n");
}

/*============================================================================
  1.2 文件流概念
============================================================================*/

void file_stream_concepts(void) {
    printf("4. 文件流（File Stream）概念\n\n");
    
    /*
     * 4.1 缓冲机制
     */
    printf("4.1 缓冲机制（Buffering）\n\n");
    
    printf("   为什么需要缓冲？\n");
    printf("   - 磁盘访问比内存访问慢得多\n");
    printf("   - 减少磁盘I/O操作次数\n");
    printf("   - 提高程序性能\n\n");
    
    printf("   缓冲类型：\n");
    printf("   1. 全缓冲（Fully Buffered）\n");
    printf("      - 缓冲区满才写入磁盘\n");
    printf("      - 普通文件默认\n\n");
    
    printf("   2. 行缓冲（Line Buffered）\n");
    printf("      - 遇到换行符或缓冲区满\n");
    printf("      - 标准输出默认\n\n");
    
    printf("   3. 无缓冲（Unbuffered）\n");
    printf("      - 立即写入磁盘\n");
    printf("      - 标准错误默认\n\n");
    
    /*
     * 4.2 缓冲相关函数
     */
    printf("4.2 缓冲控制函数\n\n");
    
    printf("   setvbuf() - 设置缓冲区类型和大小\n");
    printf("   setbuf()  - 简单的缓冲区设置\n");
    printf("   fflush()  - 刷新缓冲区\n\n");
    
    printf("   示例：设置文件缓冲\n");
    printf("   FILE *fp = fopen(\"test.txt\", \"w\");\n");
    printf("   char buffer[4096];\n");
    printf("   setvbuf(fp, buffer, _IOFBF, sizeof(buffer));\n");
    printf("   // _IOFBF: 全缓冲\n");
    printf("   // _IOLBF: 行缓冲\n");
    printf("   // _IONBF: 无缓冲\n\n");
    
    /*
     * 4.3 演示缓冲效果
     */
    printf("4.3 缓冲效果演示\n\n");
    
    printf("   创建测试文件...\n");
    
    // 演示缓冲效果
    FILE *fp1 = fopen("buffer_test1.txt", "w");
    FILE *fp2 = fopen("buffer_test2.txt", "w");
    
    if (fp1 && fp2) {
        // fp1: 使用默认缓冲
        // fp2: 使用无缓冲
        setbuf(fp2, NULL);
        
        printf("   写入10000个字符到两个文件...\n");
        
        clock_t start, end;
        
        // 测试默认缓冲
        start = clock();
        for (int i = 0; i < 10000; i++) {
            fputc('A', fp1);
        }
        end = clock();
        printf("   默认缓冲时间: %.4f秒\n", 
               (double)(end - start) / CLOCKS_PER_SEC);
        
        // 测试无缓冲
        start = clock();
        for (int i = 0; i < 10000; i++) {
            fputc('B', fp2);
        }
        end = clock();
        printf("   无缓冲时间: %.4f秒\n", 
               (double)(end - start) / CLOCKS_PER_SEC);
        
        fclose(fp1);
        fclose(fp2);
        
        printf("\n   结论：缓冲可以显著提高性能\n");
    }
    printf("\n");
}

/*============================================================================
  1.3 文件打开模式
============================================================================*/

void file_opening_modes(void) {
    printf("5. 文件打开模式\n\n");
    
    /*
     * 5.1 基本打开模式
     */
    printf("5.1 基本文本文件模式\n\n");
    
    printf("   模式字符串    描述\n");
    printf("   --------------------------------------------------\n");
    printf("   \"r\"          只读打开文本文件（文件必须存在）\n");
    printf("   \"w\"          只写创建文本文件（覆盖已存在文件）\n");
    printf("   \"a\"          追加打开文本文件（文件不存在则创建）\n");
    printf("   \"r+\"         读写打开文本文件（文件必须存在）\n");
    printf("   \"w+\"         读写创建文本文件（覆盖已存在文件）\n");
    printf("   \"a+\"         读写打开文本文件（文件不存在则创建）\n\n");
    
    /*
     * 5.2 二进制文件模式
     */
    printf("5.2 二进制文件模式\n\n");
    
    printf("   在模式字符串后加 'b'\n");
    printf("   --------------------------------------------------\n");
    printf("   \"rb\"         只读打开二进制文件\n");
    printf("   \"wb\"         只写创建二进制文件\n");
    printf("   \"ab\"         追加打开二进制文件\n");
    printf("   \"r+b\" 或 \"rb+\"  读写打开二进制文件\n");
    printf("   \"w+b\" 或 \"wb+\"  读写创建二进制文件\n");
    printf("   \"a+b\" 或 \"ab+\"  读写打开二进制文件\n\n");
    
    /*
     * 5.3 模式选择指南
     */
    printf("5.3 模式选择指南\n\n");
    
    printf("   根据需求选择模式：\n");
    printf("   --------------------------------------------------\n");
    printf("   需求                    推荐模式\n");
    printf("   --------------------------------------------------\n");
    printf("   读取现有文件             \"r\" 或 \"rb\"\n");
    printf("   创建新文件（覆盖）       \"w\" 或 \"wb\"\n");
    printf("   追加数据到文件           \"a\" 或 \"ab\"\n");
    printf("   读取并修改文件           \"r+\" 或 \"r+b\"\n");
    printf("   创建新文件可读写         \"w+\" 或 \"w+b\"\n");
    printf("   读取并追加数据           \"a+\" 或 \"a+b\"\n\n");
    
    /*
     * 5.4 模式演示
     */
    printf("5.4 不同模式演示\n\n");
    
    printf("   演示各种模式的行为：\n");
    
    // 测试各种模式
    const char* test_filename = "mode_test.txt";
    
    // 1. "w" 模式 - 创建新文件
    printf("   1. \"w\" 模式：\n");
    FILE *fp = fopen(test_filename, "w");
    if (fp) {
        fprintf(fp, "Line 1 written in write mode\n");
        fclose(fp);
        printf("   创建文件并写入数据\n");
    }
    
    // 2. "a" 模式 - 追加数据
    printf("   2. \"a\" 模式：\n");
    fp = fopen(test_filename, "a");
    if (fp) {
        fprintf(fp, "Line 2 appended in append mode\n");
        fclose(fp);
        printf("   追加数据到文件末尾\n");
    }
    
    // 3. "r" 模式 - 读取文件
    printf("   3. \"r\" 模式：\n");
    fp = fopen(test_filename, "r");
    if (fp) {
        char buffer[100];
        printf("   文件内容：\n");
        while (fgets(buffer, sizeof(buffer), fp)) {
            printf("   %s", buffer);
        }
        fclose(fp);
    }
    
    // 4. "w" 模式再次打开 - 会清空文件
    printf("   4. 再次使用 \"w\" 模式：\n");
    fp = fopen(test_filename, "w");
    if (fp) {
        fprintf(fp, "New content overwritten\n");
        fclose(fp);
        printf("   文件被清空并重新写入\n");
    }
    
    // 清理测试文件
    remove(test_filename);
    printf("\n");
}

/*============================================================================
  1.4 错误处理
============================================================================*/

void file_error_handling(void) {
    printf("6. 文件操作错误处理\n\n");
    
    /*
     * 6.1 常见文件错误
     */
    printf("6.1 常见文件错误\n\n");
    
    printf("   文件操作可能失败的原因：\n");
    printf("   --------------------------------------------------\n");
    printf("   错误原因                错误码\n");
    printf("   --------------------------------------------------\n");
    printf("   文件不存在              ENOENT\n");
    printf("   权限不足                EACCES\n");
    printf("   磁盘空间不足            ENOSPC\n");
    printf("   文件已存在              EEXIST\n");
    printf("   无效的文件描述符        EBADF\n");
    printf("   中断的系统调用          EINTR\n");
    printf("   无效的参数              EINVAL\n\n");
    
    /*
     * 6.2 错误处理函数
     */
    printf("6.2 错误处理函数\n\n");
    
    printf("   errno  - 全局错误变量\n");
    printf("   perror() - 打印错误信息\n");
    printf("   strerror() - 返回错误描述字符串\n");
    printf("   ferror() - 检查文件错误\n");
    printf("   clearerr() - 清除错误标志\n\n");
    
    /*
     * 6.3 正确的错误处理模式
     */
    printf("6.3 正确的错误处理模式\n\n");
    
    printf("   模式1：检查fopen返回值\n");
    printf("   FILE *fp = fopen(\"file.txt\", \"r\");\n");
    printf("   if (fp == NULL) {\n");
    printf("       perror(\"打开文件失败\");\n");
    printf("       // 处理错误\n");
    printf("   }\n\n");
    
    printf("   模式2：检查读写操作\n");
    printf("   size_t count = fwrite(data, size, n, fp);\n");
    printf("   if (count < n) {\n");
    printf("       if (ferror(fp)) {\n");
    printf("           perror(\"写入失败\");\n");
    printf("       } else if (feof(fp)) {\n");
    printf("           printf(\"到达文件末尾\\n\");\n");
    printf("       }\n");
    printf("   }\n\n");
    
    /*
     * 6.4 错误处理演示
     */
    printf("6.4 错误处理演示\n\n");
    
    printf("   演示各种错误情况：\n\n");
    
    // 1. 文件不存在的错误
    printf("   1. 尝试打开不存在的文件：\n");
    FILE *fp = fopen("non_existent_file.txt", "r");
    if (fp == NULL) {
        printf("   错误信息：%s\n", strerror(errno));
        perror("   fopen失败");
    } else {
        fclose(fp);
    }
    printf("\n");
    
    // 2. 权限错误（尝试在只读位置创建文件）
    printf("   2. 尝试在无权限位置创建文件：\n");
    fp = fopen("/root/test.txt", "w");
    if (fp == NULL) {
        if (errno == EACCES) {
            printf("   权限被拒绝（正常情况）\n");
        }
        perror("   创建文件失败");
    } else {
        fclose(fp);
        remove("/root/test.txt");
    }
    printf("\n");
    
    // 3. 磁盘空间不足（模拟）
    printf("   3. 处理写操作错误：\n");
    fp = fopen("test_large.txt", "w");
    if (fp) {
        // 尝试写入大量数据
        char *large_data = malloc(1024 * 1024 * 100); // 100MB
        if (large_data) {
            memset(large_data, 'X', 1024 * 1024 * 100);
            size_t written = fwrite(large_data, 1, 1024 * 1024 * 100, fp);
            if (written < 1024 * 1024 * 100) {
                if (ferror(fp)) {
                    printf("   写入过程中发生错误\n");
                    perror("   错误详情");
                }
            }
            free(large_data);
        }
        fclose(fp);
        remove("test_large.txt");
    }
    printf("\n");
    
    /*
     * 6.5 错误处理最佳实践
     */
    printf("6.5 错误处理最佳实践\n\n");
    
    printf("   1. 总是检查文件操作返回值\n");
    printf("   2. 使用perror或strerror提供有用信息\n");
    printf("   3. 区分不同错误类型进行不同处理\n");
    printf("   4. 确保资源正确释放（即使发生错误）\n");
    printf("   5. 记录错误日志便于调试\n");
    printf("   6. 提供用户友好的错误信息\n\n");
    
    printf("   示例：健壮的文件打开函数\n");
    printf("   FILE* safe_fopen(const char* filename, const char* mode) {\n");
    printf("       FILE* fp = fopen(filename, mode);\n");
    printf("       if (fp == NULL) {\n");
    printf("           fprintf(stderr, \"无法打开文件 %%s: %%s\\n\", \n");
    printf("                   filename, strerror(errno));\n");
    printf("           // 根据错误类型决定是否退出\n");
    printf("           if (errno == ENOENT) {\n");
    printf("               // 文件不存在，可能是正常情况\n");
    printf("           }\n");
    printf("       }\n");
    printf("       return fp;\n");
    printf("   }\n\n");
}

/*============================================================================
  第二部分：文本文件操作
============================================================================*/

void part2_text_file_operations(void) {
    printf("\n");
    printf("================================================\n");
    printf("第二部分：文本文件操作\n");
    printf("================================================\n\n");
    
    /*
     * 1. 文本文件读取
     */
    printf("1. 文本文件读取函数\n\n");
    
    printf("   逐字符读取：\n");
    printf("   --------------------------------------------------\n");
    printf("   函数          描述\n");
    printf("   --------------------------------------------------\n");
    printf("   fgetc()       读取一个字符\n");
    printf("   getc()        同fgetc()，可能是宏\n");
    printf("   getchar()     从stdin读取一个字符\n\n");
    
    printf("   逐行读取：\n");
    printf("   --------------------------------------------------\n");
    printf("   fgets()       读取一行字符串\n");
    printf("   gets()        从stdin读取一行（不安全，已废弃）\n\n");
    
    printf("   格式化读取：\n");
    printf("   --------------------------------------------------\n");
    printf("   fscanf()      格式化读取\n");
    printf("   scanf()       从stdin格式化读取\n\n");
    
    /*
     * 2. 文本文件写入
     */
    printf("2. 文本文件写入函数\n\n");
    
    printf("   逐字符写入：\n");
    printf("   --------------------------------------------------\n");
    printf("   fputc()       写入一个字符\n");
    printf("   putc()        同fputc()，可能是宏\n");
    printf("   putchar()     向stdout写入一个字符\n\n");
    
    printf("   字符串写入：\n");
    printf("   --------------------------------------------------\n");
    printf("   fputs()       写入字符串\n");
    printf("   puts()        向stdout写入字符串并添加换行\n\n");
    
    printf("   格式化写入：\n");
    printf("   --------------------------------------------------\n");
    printf("   fprintf()     格式化写入\n");
    printf("   printf()      向stdout格式化写入\n\n");
    
    /*
     * 3. 文件结束和错误检测
     */
    printf("3. 文件结束和错误检测\n\n");
    
    printf("   --------------------------------------------------\n");
    printf("   函数          描述\n");
    printf("   --------------------------------------------------\n");
    printf("   feof()        检查文件结束标志\n");
    printf("   ferror()      检查文件错误标志\n");
    printf("   clearerr()    清除错误和结束标志\n\n");
    
    printf("   重要：不要用feof()作为循环条件！\n");
    printf("   正确做法是检查读写函数的返回值\n\n");
}

/*============================================================================
  2.2 文本文件读取演示
============================================================================*/

void text_file_reading(void) {
    printf("4. 文本文件读取演示\n\n");
    
    // 首先创建测试文件
    create_test_files();
    
    /*
     * 4.1 逐字符读取
     */
    printf("4.1 逐字符读取（fgetc）\n\n");
    
    FILE *fp = fopen("test_data.txt", "r");
    if (fp) {
        printf("   文件内容（逐字符）：\n   ");
        
        int ch;
        int count = 0;
        while ((ch = fgetc(fp)) != EOF) {
            putchar(ch);
            count++;
        }
        
        printf("\n   总字符数：%d\n", count);
        fclose(fp);
    }
    printf("\n");
    
    /*
     * 4.2 逐行读取
     */
    printf("4.2 逐行读取（fgets）\n\n");
    
    fp = fopen("test_data.txt", "r");
    if (fp) {
        printf("   文件内容（逐行）：\n");
        
        char buffer[256];
        int line_num = 1;
        
        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            // 移除可能的换行符
            buffer[strcspn(buffer, "\n")] = '\0';
            printf("   行 %d: %s\n", line_num++, buffer);
        }
        
        fclose(fp);
    }
    printf("\n");
    
    /*
     * 4.3 格式化读取
     */
    printf("4.3 格式化读取（fscanf）\n\n");
    
    fp = fopen("test_data.txt", "r");
    if (fp) {
        printf("   提取文件中的数字：\n");
        
        char word[100];
        int num_int;
        float num_float;
        int items;
        
        // 读取整个文件，提取各种类型的数据
        rewind(fp);
        printf("   单词：");
        while ((items = fscanf(fp, "%s", word)) == 1) {
            // 尝试判断是否为数字
            if (sscanf(word, "%d", &num_int) == 1) {
                printf(" [整数:%d]", num_int);
            } else if (sscanf(word, "%f", &num_float) == 1) {
                printf(" [浮点数:%.2f]", num_float);
            } else {
                // 不是数字，显示前几个字符
                if (strlen(word) > 5) {
                    printf(" %.5s...", word);
                } else {
                    printf(" %s", word);
                }
            }
        }
        printf("\n");
        
        fclose(fp);
    }
    printf("\n");
    
    /*
     * 4.4 高效读取技巧
     */
    printf("4.4 高效读取技巧\n\n");
    
    printf("   方法1：一次读取整个文件\n");
    fp = fopen("test_data.txt", "r");
    if (fp) {
        // 获取文件大小
        fseek(fp, 0, SEEK_END);
        long file_size = ftell(fp);
        rewind(fp);
        
        // 分配内存
        char *content = (char*)malloc(file_size + 1);
        if (content) {
            // 一次读取整个文件
            size_t bytes_read = fread(content, 1, file_size, fp);
            content[bytes_read] = '\0';
            
            printf("   文件大小：%ld 字节\n", file_size);
            printf("   实际读取：%zu 字节\n", bytes_read);
            printf("   前100个字符：\n   %.100s...\n", content);
            
            free(content);
        }
        fclose(fp);
    }
    printf("\n");
    
    printf("   方法2：使用缓冲区循环读取\n");
    fp = fopen("test_data.txt", "r");
    if (fp) {
        char buffer[1024];
        size_t total_bytes = 0;
        
        printf("   分块读取：\n");
        while (!feof(fp)) {
            size_t bytes_read = fread(buffer, 1, sizeof(buffer) - 1, fp);
            if (bytes_read > 0) {
                buffer[bytes_read] = '\0';
                total_bytes += bytes_read;
                printf("   读取块：%zu 字节（累计：%zu）\n", 
                       bytes_read, total_bytes);
            }
        }
        fclose(fp);
    }
    printf("\n");
}

/*============================================================================
  2.3 文本文件写入演示
============================================================================*/

void text_file_writing(void) {
    printf("5. 文本文件写入演示\n\n");
    
    const char* filename = "output_demo.txt";
    
    /*
     * 5.1 逐字符写入
     */
    printf("5.1 逐字符写入（fputc）\n\n");
    
    FILE *fp = fopen(filename, "w");
    if (fp) {
        const char *text = "Hello, World!\nThis is a test.\n";
        
        printf("   写入字符串：%s", text);
        
        for (int i = 0; text[i] != '\0'; i++) {
            fputc(text[i], fp);
        }
        
        // 添加一些特殊字符
        for (int i = 33; i <= 126; i++) {
            if (i % 16 == 0) fputc('\n', fp);
            fputc(i, fp);
            fputc(' ', fp);
        }
        
        fclose(fp);
        printf("   写入完成，文件大小：%ld 字节\n", get_file_size(filename));
    }
    printf("\n");
    
    /*
     * 5.2 字符串写入
     */
    printf("5.2 字符串写入（fputs）\n\n");
    
    fp = fopen("append_demo.txt", "a");  // 追加模式
    if (fp) {
        const char *lines[] = {
            "这是第一行\n",
            "这是第二行\n",
            "这是第三行，包含数字：123\n",
            "这是第四行，包含浮点数：3.14159\n",
            NULL
        };
        
        printf("   追加多行文本：\n");
        for (int i = 0; lines[i] != NULL; i++) {
            fputs(lines[i], fp);
            printf("   %s", lines[i]);
        }
        
        fclose(fp);
        printf("   追加完成\n");
    }
    printf("\n");
    
    /*
     * 5.3 格式化写入
     */
    printf("5.3 格式化写入（fprintf）\n\n");
    
    fp = fopen("format_demo.txt", "w");
    if (fp) {
        printf("   写入格式化数据：\n");
        
        // 写入各种类型的数据
        fprintf(fp, "整数：%d, %ld, %u\n", 42, 1000000L, 255);
        fprintf(fp, "浮点数：%.2f, %e, %g\n", 3.14159, 1.23e-4, 9.8765);
        fprintf(fp, "字符串：%s\n", "Hello World");
        fprintf(fp, "字符：%c\n", 'A');
        fprintf(fp, "指针：%p\n", (void*)fp);
        fprintf(fp, "八进制：%o, 十六进制：%x, %X\n", 255, 255, 255);
        
        // 格式控制
        fprintf(fp, "宽度控制：|%10s|%-10s|%10d|%-10d|\n", 
                "right", "left", 123, 456);
        fprintf(fp, "填充：|%010d|%10.2f|\n", 123, 3.14159);
        
        fclose(fp);
        
        // 显示写入的内容
        fp = fopen("format_demo.txt", "r");
        if (fp) {
            char buffer[256];
            printf("   写入的内容：\n");
            while (fgets(buffer, sizeof(buffer), fp)) {
                printf("   %s", buffer);
            }
            fclose(fp);
        }
    }
    printf("\n");
    
    /*
     * 5.4 日志文件示例
     */
    printf("5.4 日志文件示例\n\n");
    
    fp = fopen("application.log", "a");
    if (fp) {
        time_t now = time(NULL);
        struct tm *tm_info = localtime(&now);
        
        // 写入带时间戳的日志
        fprintf(fp, "[%04d-%02d-%02d %02d:%02d:%02d] ",
                tm_info->tm_year + 1900, tm_info->tm_mon + 1, 
                tm_info->tm_mday, tm_info->tm_hour, 
                tm_info->tm_min, tm_info->tm_sec);
        fprintf(fp, "程序启动\n");
        
        fprintf(fp, "[%04d-%02d-%02d %02d:%02d:%02d] ",
                tm_info->tm_year + 1900, tm_info->tm_mon + 1, 
                tm_info->tm_mday, tm_info->tm_hour, 
                tm_info->tm_min, tm_info->tm_sec);
        fprintf(fp, "用户登录：user123\n");
        
        fprintf(fp, "[%04d-%02d-%02d %02d:%02d:%02d] ",
                tm_info->tm_year + 1900, tm_info->tm_mon + 1, 
                tm_info->tm_mday, tm_info->tm_hour, 
                tm_info->tm_min, tm_info->tm_sec);
        fprintf(fp, "操作完成，状态：%s\n", "SUCCESS");
        
        fprintf(fp, "[%04d-%02d-%02d %02d:%02d:%02d] ",
                tm_info->tm_year + 1900, tm_info->tm_mon + 1, 
                tm_info->tm_mday, tm_info->tm_hour, 
                tm_info->tm_min, tm_info->tm_sec);
        fprintf(fp, "程序退出，运行时间：%d秒\n", 60);
        
        fclose(fp);
        
        printf("   日志文件创建成功\n");
        
        // 显示日志内容
        fp = fopen("application.log", "r");
        if (fp) {
            printf("   日志内容：\n");
            char buffer[256];
            while (fgets(buffer, sizeof(buffer), fp)) {
                printf("   %s", buffer);
            }
            fclose(fp);
        }
    }
    printf("\n");
    
    // 清理测试文件
    remove(filename);
    remove("append_demo.txt");
    remove("format_demo.txt");
    remove("application.log");
}

/*============================================================================
  2.4 文本文件高级操作
============================================================================*/

void text_file_advanced(void) {
    printf("6. 文本文件高级操作\n\n");
    
    /*
     * 6.1 文件复制
     */
    printf("6.1 文件复制（逐字符）\n\n");
    
    // 创建源文件
    FILE *src = fopen("source.txt", "w");
    if (src) {
        fprintf(src, "这是源文件内容\n");
        fprintf(src, "包含多行文本\n");
        fprintf(src, "用于演示文件复制\n");
        fclose(src);
    }
    
    printf("   复制 source.txt 到 dest.txt\n");
    
    src = fopen("source.txt", "r");
    FILE *dest = fopen("dest.txt", "w");
    
    if (src && dest) {
        int ch;
        int count = 0;
        
        while ((ch = fgetc(src)) != EOF) {
            fputc(ch, dest);
            count++;
        }
        
        printf("   复制完成，复制了 %d 个字符\n", count);
        
        fclose(src);
        fclose(dest);
        
        // 验证复制结果
        dest = fopen("dest.txt", "r");
        if (dest) {
            printf("   目标文件内容：\n");
            char buffer[256];
            while (fgets(buffer, sizeof(buffer), dest)) {
                printf("   %s", buffer);
            }
            fclose(dest);
        }
    }
    printf("\n");
    
    /*
     * 6.2 文件合并
     */
    printf("6.2 文件合并\n\n");
    
    // 创建第二个源文件
    FILE *src2 = fopen("source2.txt", "w");
    if (src2) {
        fprintf(src2, "这是第二个源文件\n");
        fprintf(src2, "将被合并到第一个文件后面\n");
        fclose(src2);
    }
    
    printf("   合并 source.txt 和 source2.txt 到 merged.txt\n");
    
    src = fopen("source.txt", "r");
    src2 = fopen("source2.txt", "r");
    dest = fopen("merged.txt", "w");
    
    if (src && src2 && dest) {
        // 复制第一个文件
        int ch;
        while ((ch = fgetc(src)) != EOF) {
            fputc(ch, dest);
        }
        
        // 添加分隔符
        fprintf(dest, "\n--- 文件合并分隔符 ---\n\n");
        
        // 复制第二个文件
        while ((ch = fgetc(src2)) != EOF) {
            fputc(ch, dest);
        }
        
        fclose(src);
        fclose(src2);
        fclose(dest);
        
        printf("   合并完成\n");
    }
    printf("\n");
    
    /*
     * 6.3 文件内容搜索
     */
    printf("6.3 文件内容搜索\n\n");
    
    const char *search_word = "文件";
    
    src = fopen("merged.txt", "r");
    if (src) {
        char line[256];
        int line_num = 1;
        int match_count = 0;
        
        printf("   在 merged.txt 中搜索 \"%s\"：\n", search_word);
        
        while (fgets(line, sizeof(line), src)) {
            // 移除换行符
            line[strcspn(line, "\n")] = '\0';
            
            // 搜索单词
            if (strstr(line, search_word) != NULL) {
                printf("   第 %d 行找到匹配：%s\n", line_num, line);
                match_count++;
            }
            line_num++;
        }
        
        if (match_count == 0) {
            printf("   未找到匹配项\n");
        } else {
            printf("   总共找到 %d 处匹配\n", match_count);
        }
        
        fclose(src);
    }
    printf("\n");
    
    /*
     * 6.4 文件内容统计
     */
    printf("6.4 文件内容统计\n\n");
    
    src = fopen("merged.txt", "r");
    if (src) {
        int char_count = 0;
        int line_count = 0;
        int word_count = 0;
        int in_word = 0;
        int ch;
        
        while ((ch = fgetc(src)) != EOF) {
            char_count++;
            
            if (ch == '\n') {
                line_count++;
            }
            
            // 统计单词（简单方法）
            if (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r') {
                if (in_word) {
                    word_count++;
                    in_word = 0;
                }
            } else {
                in_word = 1;
            }
        }
        
        // 处理最后一个单词
        if (in_word) {
            word_count++;
        }
        
        printf("   文件统计信息：\n");
        printf("   字符数：%d\n", char_count);
        printf("   行数：%d\n", line_count);
        printf("   单词数：%d\n", word_count);
        
        fclose(src);
    }
    printf("\n");
    
    /*
     * 6.5 文件比较
     */
    printf("6.5 文件比较\n\n");
    
    printf("   比较 source.txt 和 dest.txt：\n");
    
    FILE *file1 = fopen("source.txt", "r");
    FILE *file2 = fopen("dest.txt", "r");
    
    if (file1 && file2) {
        int ch1, ch2;
        int pos = 0;
        int differences = 0;
        
        while (1) {
            ch1 = fgetc(file1);
            ch2 = fgetc(file2);
            pos++;
            
            if (ch1 == EOF && ch2 == EOF) {
                break;  // 两个文件都结束
            }
            
            if (ch1 != ch2) {
                differences++;
                printf("   位置 %d 不同：", pos);
                printf("文件1='%c'(%d), 文件2='%c'(%d)\n",
                       (ch1 == EOF) ? '?' : ch1, ch1,
                       (ch2 == EOF) ? '?' : ch2, ch2);
                
                if (differences > 10) {
                    printf("   ... 还有更多不同\n");
                    break;
                }
            }
        }
        
        if (differences == 0) {
            printf("   两个文件完全相同\n");
        } else {
            printf("   发现 %d 处不同\n", differences);
        }
        
        fclose(file1);
        fclose(file2);
    }
    printf("\n");
    
    // 清理测试文件
    remove("source.txt");
    remove("source2.txt");
    remove("dest.txt");
    remove("merged.txt");
}

/*============================================================================
  第三部分：二进制文件操作
============================================================================*/

void part3_binary_file_operations(void) {
    printf("\n");
    printf("================================================\n");
    printf("第三部分：二进制文件操作\n");
    printf("================================================\n\n");
    
    /*
     * 1. 二进制文件 vs 文本文件
     */
    printf("1. 二进制文件 vs 文本文件\n\n");
    
    printf("   主要区别：\n");
    printf("   --------------------------------------------------\n");
    printf("   特性          文本文件          二进制文件\n");
    printf("   --------------------------------------------------\n");
    printf("   存储方式      ASCII码          原始二进制\n");
    printf("   可读性       人类可读         机器可读\n");
    printf("   大小          较大             较小\n");
    printf("   处理速度      较慢             较快\n");
    printf("   跨平台        可能有问题       更可靠\n");
    printf("   示例         .txt, .c         .exe, .jpg\n\n");
    
    printf("   选择依据：\n");
    printf("   - 需要人类阅读/编辑：文本文件\n");
    printf("   - 需要高效存储/处理：二进制文件\n");
    printf("   - 存储结构化数据：二进制文件\n");
    printf("   - 存储配置/日志：文本文件\n\n");
    
    /*
     * 2. 二进制文件操作函数
     */
    printf("2. 二进制文件操作函数\n\n");
    
    printf("   块读写：\n");
    printf("   --------------------------------------------------\n");
    printf("   函数          描述\n");
    printf("   --------------------------------------------------\n");
    printf("   fread()       从文件读取数据块\n");
    printf("   fwrite()      向文件写入数据块\n\n");
    
    printf("   内存直接读写：\n");
    printf("   --------------------------------------------------\n");
    printf("   fread()       读取到内存\n");
    printf("   fwrite()      从内存写入\n\n");
    
    printf("   注意：二进制模式需要在模式字符串中加 'b'\n");
    printf("   例如：\"rb\", \"wb\", \"ab\", \"r+b\"\n\n");
}

/*============================================================================
  3.2 二进制文件基础操作
============================================================================*/

void binary_file_basics(void) {
    printf("3. 二进制文件基础操作\n\n");
    
    /*
     * 3.1 基本数据类型的读写
     */
    printf("3.1 基本数据类型的读写\n\n");
    
    const char* filename = "binary_basic.bin";
    
    // 写入基本数据类型
    printf("   写入基本数据类型到 %s：\n", filename);
    
    FILE *fp = fopen(filename, "wb");
    if (fp) {
        // 写入各种数据类型
        int int_val = 42;
        float float_val = 3.14159f;
        double double_val = 2.718281828459045;
        char char_val = 'A';
        char str[] = "Hello Binary";
        
        fwrite(&int_val, sizeof(int), 1, fp);
        fwrite(&float_val, sizeof(float), 1, fp);
        fwrite(&double_val, sizeof(double), 1, fp);
        fwrite(&char_val, sizeof(char), 1, fp);
        fwrite(str, sizeof(char), strlen(str), fp);
        
        // 写入结束标记
        char end_mark = '\0';
        fwrite(&end_mark, sizeof(char), 1, fp);
        
        fclose(fp);
        
        printf("   写入完成，文件大小：%ld 字节\n", get_file_size(filename));
    }
    printf("\n");
    
    /*
     * 3.2 读取基本数据类型
     */
    printf("3.2 读取基本数据类型\n\n");
    
    fp = fopen(filename, "rb");
    if (fp) {
        int int_val;
        float float_val;
        double double_val;
        char char_val;
        char str[100];
        
        // 按写入顺序读取
        fread(&int_val, sizeof(int), 1, fp);
        fread(&float_val, sizeof(float), 1, fp);
        fread(&double_val, sizeof(double), 1, fp);
        fread(&char_val, sizeof(char), 1, fp);
        
        // 读取字符串（直到遇到结束标记）
        int i = 0;
        char ch;
        while ((ch = fgetc(fp)) != '\0' && i < sizeof(str) - 1) {
            str[i++] = ch;
        }
        str[i] = '\0';
        
        printf("   读取的数据：\n");
        printf("   整数：%d\n", int_val);
        printf("   浮点数：%.5f\n", float_val);
        printf("   双精度：%.15lf\n", double_val);
        printf("   字符：'%c'\n", char_val);
        printf("   字符串：\"%s\"\n", str);
        
        fclose(fp);
    }
    printf("\n");
    
    /*
     * 3.3 数组的读写
     */
    printf("3.3 数组的读写\n\n");
    
    const char* array_filename = "binary_array.bin";
    
    // 写入数组
    printf("   写入数组到 %s：\n", array_filename);
    
    fp = fopen(array_filename, "wb");
    if (fp) {
        int int_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        double double_array[] = {1.1, 2.2, 3.3, 4.4, 5.5};
        
        // 写入数组长度和内容
        int int_count = sizeof(int_array) / sizeof(int_array[0]);
        fwrite(&int_count, sizeof(int), 1, fp);
        fwrite(int_array, sizeof(int), int_count, fp);
        
        int double_count = sizeof(double_array) / sizeof(double_array[0]);
        fwrite(&double_count, sizeof(int), 1, fp);
        fwrite(double_array, sizeof(double), double_count, fp);
        
        fclose(fp);
        
        printf("   写入完成\n");
    }
    
    // 读取数组
    printf("   从 %s 读取数组：\n", array_filename);
    
    fp = fopen(array_filename, "rb");
    if (fp) {
        int int_count;
        fread(&int_count, sizeof(int), 1, fp);
        
        int *int_array = malloc(int_count * sizeof(int));
        if (int_array) {
            fread(int_array, sizeof(int), int_count, fp);
            
            printf("   整数数组（%d个元素）：", int_count);
            for (int i = 0; i < int_count; i++) {
                printf("%d ", int_array[i]);
            }
            printf("\n");
            
            free(int_array);
        }
        
        int double_count;
        fread(&double_count, sizeof(int), 1, fp);
        
        double *double_array = malloc(double_count * sizeof(double));
        if (double_array) {
            fread(double_array, sizeof(double), double_count, fp);
            
            printf("   双精度数组（%d个元素）：", double_count);
            for (int i = 0; i < double_count; i++) {
                printf("%.1f ", double_array[i]);
            }
            printf("\n");
            
            free(double_array);
        }
        
        fclose(fp);
    }
    printf("\n");
    
    // 清理文件
    remove(filename);
    remove(array_filename);
}

/*============================================================================
  3.3 结构化数据I/O
============================================================================*/

void structured_data_io(void) {
    printf("4. 结构化数据I/O\n\n");
    
    /*
     * 4.1 结构体读写
     */
    printf("4.1 结构体读写\n\n");
    
    // 定义结构体
    typedef struct {
        int id;
        char name[50];
        float salary;
        int department;
    } Employee;
    
    const char* employee_file = "employees.bin";
    
    // 创建一些员工数据
    Employee employees[] = {
        {101, "张三", 8000.50f, 1},
        {102, "李四", 9500.75f, 2},
        {103, "王五", 12000.00f, 1},
        {104, "赵六", 7500.25f, 3},
        {105, "钱七", 11000.00f, 2}
    };
    
    int employee_count = sizeof(employees) / sizeof(employees[0]);
    
    // 写入结构体数组
    printf("   写入 %d 个员工记录到 %s：\n", employee_count, employee_file);
    
    FILE *fp = fopen(employee_file, "wb");
    if (fp) {
        // 写入记录数量
        fwrite(&employee_count, sizeof(int), 1, fp);
        
        // 写入所有员工记录
        fwrite(employees, sizeof(Employee), employee_count, fp);
        
        fclose(fp);
        printf("   写入完成，文件大小：%ld 字节\n", get_file_size(employee_file));
    }
    printf("\n");
    
    /*
     * 4.2 读取结构体数据
     */
    printf("4.2 读取结构体数据\n\n");
    
    fp = fopen(employee_file, "rb");
    if (fp) {
        int read_count;
        fread(&read_count, sizeof(int), 1, fp);
        
        printf("   读取 %d 个员工记录：\n", read_count);
        printf("   ID    姓名        工资      部门\n");
        printf("   --------------------------------------\n");
        
        Employee emp;
        for (int i = 0; i < read_count; i++) {
            fread(&emp, sizeof(Employee), 1, fp);
            printf("   %-6d%-12s%-10.2f%d\n", 
                   emp.id, emp.name, emp.salary, emp.department);
        }
        
        fclose(fp);
    }
    printf("\n");
    
    /*
     * 4.3 随机访问结构体记录
     */
    printf("4.3 随机访问结构体记录\n\n");
    
    fp = fopen(employee_file, "r+b");  // 读写模式
    if (fp) {
        // 读取记录数量
        int record_count;
        fread(&record_count, sizeof(int), 1, fp);
        
        printf("   文件中有 %d 条记录\n", record_count);
        
        // 修改第三条记录（索引2）
        printf("   修改第三条记录（ID 103）的工资：\n");
        
        // 计算第三条记录的位置
        // 第一条记录在：sizeof(int)（记录数量）之后
        long record_size = sizeof(Employee);
        long position = sizeof(int) + 2 * record_size;
        
        // 定位到第三条记录
        fseek(fp, position, SEEK_SET);
        
        // 读取当前记录
        Employee emp;
        fread(&emp, sizeof(Employee), 1, fp);
        printf("   原工资：%.2f\n", emp.salary);
        
        // 修改工资
        emp.salary = 15000.00f;
        
        // 写回修改后的记录
        fseek(fp, -record_size, SEEK_CUR);  // 回到记录开头
        fwrite(&emp, sizeof(Employee), 1, fp);
        
        printf("   新工资：%.2f\n", emp.salary);
        
        // 验证修改
        fseek(fp, position, SEEK_SET);
        fread(&emp, sizeof(Employee), 1, fp);
        printf("   验证工资：%.2f\n", emp.salary);
        
        fclose(fp);
    }
    printf("\n");
    
    /*
     * 4.4 追加新记录
     */
    printf("4.4 追加新记录\n\n");
    
    fp = fopen(employee_file, "r+b");
    if (fp) {
        // 读取当前记录数量
        int current_count;
        fread(&current_count, sizeof(int), 1, fp);
        
        printf("   当前有 %d 条记录\n", current_count);
        
        // 追加新记录
        Employee new_employee = {106, "孙八", 9000.00f, 3};
        
        // 移动到文件末尾
        fseek(fp, 0, SEEK_END);
        
        // 写入新记录
        fwrite(&new_employee, sizeof(Employee), 1, fp);
        
        // 更新记录数量
        current_count++;
        fseek(fp, 0, SEEK_SET);
        fwrite(&current_count, sizeof(int), 1, fp);
        
        printf("   添加新员工：%s（ID %d）\n", 
               new_employee.name, new_employee.id);
        printf("   现在总共有 %d 条记录\n", current_count);
        
        fclose(fp);
    }
    printf("\n");
    
    /*
     * 4.5 删除记录（标记删除）
     */
    printf("4.5 删除记录（标记删除）\n\n");
    
    fp = fopen(employee_file, "r+b");
    if (fp) {
        int record_count;
        fread(&record_count, sizeof(int), 1, fp);
        
        // 查找要删除的记录（ID 102）
        int delete_id = 102;
        long delete_pos = -1;
        
        Employee emp;
        for (int i = 0; i < record_count; i++) {
            long pos = ftell(fp);
            fread(&emp, sizeof(Employee), 1, fp);
            
            if (emp.id == delete_id) {
                delete_pos = pos;
                printf("   找到要删除的记录：%s（位置 %ld）\n", 
                       emp.name, delete_pos);
                break;
            }
        }
        
        if (delete_pos != -1) {
            // 标记删除（将ID设为-1）
            fseek(fp, delete_pos, SEEK_SET);
            emp.id = -1;
            fwrite(&emp, sizeof(Employee), 1, fp);
            
            printf("   已标记删除记录 ID %d\n", delete_id);
        } else {
            printf("   未找到 ID 为 %d 的记录\n", delete_id);
        }
        
        fclose(fp);
    }
    printf("\n");
    
    /*
     * 4.6 显示所有有效记录
     */
    printf("4.6 显示所有有效记录\n\n");
    
    fp = fopen(employee_file, "rb");
    if (fp) {
        int record_count;
        fread(&record_count, sizeof(int), 1, fp);
        
        printf("   所有有效员工记录（共 %d 条）：\n", record_count);
        printf("   ID    姓名        工资      部门\n");
        printf("   --------------------------------------\n");
        
        Employee emp;
        int valid_count = 0;
        
        for (int i = 0; i < record_count; i++) {
            fread(&emp, sizeof(Employee), 1, fp);
            
            // 跳过标记删除的记录
            if (emp.id != -1) {
                printf("   %-6d%-12s%-10.2f%d\n", 
                       emp.id, emp.name, emp.salary, emp.department);
                valid_count++;
            }
        }
        
        printf("   有效记录：%d 条\n", valid_count);
        printf("   已删除记录：%d 条\n", record_count - valid_count);
        
        fclose(fp);
    }
    
    // 清理文件
    remove(employee_file);
    printf("\n");
}

/*============================================================================
  第四部分：文件位置与随机访问
============================================================================*/

void part4_file_positioning(void) {
    printf("\n");
    printf("================================================\n");
    printf("第四部分：文件位置与随机访问\n");
    printf("================================================\n\n");
    
    /*
     * 1. 文件位置函数
     */
    printf("1. 文件位置函数\n\n");
    
    printf("   文件位置概念：\n");
    printf("   - 每个打开的文件都有一个当前位置\n");
    printf("   - 位置是相对于文件开头的字节偏移量\n");
    printf("   - 读写操作从当前位置开始\n");
    printf("   - 读写后位置自动移动\n\n");
    
    printf("   位置操作函数：\n");
    printf("   --------------------------------------------------\n");
    printf("   函数          描述\n");
    printf("   --------------------------------------------------\n");
    printf("   ftell()       获取当前位置\n");
    printf("   fseek()       设置位置\n");
    printf("   rewind()      重置到文件开头\n\n");
    
    printf("   fseek() 的 whence 参数：\n");
    printf("   SEEK_SET - 相对于文件开头\n");
    printf("   SEEK_CUR - 相对于当前位置\n");
    printf("   SEEK_END - 相对于文件结尾\n\n");
}

/*============================================================================
  4.2 文件位置函数演示
============================================================================*/

void file_position_functions(void) {
    printf("2. 文件位置函数演示\n\n");
    
    const char* filename = "position_demo.txt";
    
    // 创建测试文件
    FILE *fp = fopen(filename, "w");
    if (fp) {
        for (int i = 1; i <= 10; i++) {
            fprintf(fp, "这是第 %d 行文本内容\n", i);
        }
        fclose(fp);
    }
    
    /*
     * 2.1 ftell() 演示
     */
    printf("2.1 ftell() - 获取当前位置\n\n");
    
    fp = fopen(filename, "r");
    if (fp) {
        printf("   文件打开时的位置：%ld\n", ftell(fp));
        
        // 读取一行
        char buffer[100];
        fgets(buffer, sizeof(buffer), fp);
        printf("   读取一行后的位置：%ld\n", ftell(fp));
        
        // 再读取一行
        fgets(buffer, sizeof(buffer), fp);
        printf("   再读一行后的位置：%ld\n", ftell(fp));
        
        fclose(fp);
    }
    printf("\n");
    
    /*
     * 2.2 fseek() 演示
     */
    printf("2.2 fseek() - 设置文件位置\n\n");
    
    fp = fopen(filename, "r");
    if (fp) {
        // 跳到文件开头
        fseek(fp, 0, SEEK_SET);
        printf("   fseek(0, SEEK_SET) 后位置：%ld\n", ftell(fp));
        
        // 跳到第50个字节
        fseek(fp, 50, SEEK_SET);
        printf("   fseek(50, SEEK_SET) 后位置：%ld\n", ftell(fp));
        
        // 读取当前位置的内容
        char buffer[100];
        fgets(buffer, sizeof(buffer), fp);
        printf("   当前位置的内容：%s", buffer);
        
        // 相对当前位置移动
        printf("   当前相对位置：%ld\n", ftell(fp));
        fseek(fp, -20, SEEK_CUR);  // 向后移动20字节
        printf("   fseek(-20, SEEK_CUR) 后位置：%ld\n", ftell(fp));
        
        // 读取移动后的内容
        fgets(buffer, sizeof(buffer), fp);
        printf("   移动后的内容：%s", buffer);
        
        // 跳到文件末尾
        fseek(fp, 0, SEEK_END);
        printf("   fseek(0, SEEK_END) 后位置：%ld\n", ftell(fp));
        
        // 从末尾向前移动
        fseek(fp, -30, SEEK_END);
        printf("   fseek(-30, SEEK_END) 后位置：%ld\n", ftell(fp));
        
        fclose(fp);
    }
    printf("\n");
    
    /*
     * 2.3 rewind() 演示
     */
    printf("2.3 rewind() - 重置到文件开头\n\n");
    
    fp = fopen(filename, "r");
    if (fp) {
        // 读取到文件中间
        fseek(fp, 100, SEEK_SET);
        printf("   移动到位置：%ld\n", ftell(fp));
        
        // 读取一些内容
        char buffer[100];
        fgets(buffer, sizeof(buffer), fp);
        printf("   当前位置的内容：%s", buffer);
        
        // 使用rewind回到开头
        rewind(fp);
        printf("   rewind() 后位置：%ld\n", ftell(fp));
        
        // 验证在开头
        fgets(buffer, sizeof(buffer), fp);
        printf("   回到开头后的第一行：%s", buffer);
        
        fclose(fp);
    }
    printf("\n");
    
    /*
     * 2.4 位置操作的应用
     */
    printf("2.4 位置操作的应用\n\n");
    
    fp = fopen(filename, "r");
    if (fp) {
        // 获取文件总大小
        fseek(fp, 0, SEEK_END);
        long file_size = ftell(fp);
        printf("   文件总大小：%ld 字节\n", file_size);
        
        // 计算总行数
        rewind(fp);
        int line_count = 0;
        char ch;
        while ((ch = fgetc(fp)) != EOF) {
            if (ch == '\n') line_count++;
        }
        printf("   文件总行数：%d\n", line_count);
        
        // 计算平均每行长度
        double avg_line_length = (double)file_size / line_count;
        printf("   平均每行长度：%.2f 字节\n", avg_line_length);
        
        fclose(fp);
    }
    printf("\n");
    
    // 清理文件
    remove(filename);
}

/*============================================================================
  4.3 随机访问文件
============================================================================*/

void random_access_files(void) {
    printf("3. 随机访问文件\n\n");
    
    /*
     * 3.1 索引文件示例
     */
    printf("3.1 索引文件示例\n\n");
    
    // 创建学生记录文件
    typedef struct {
        int id;
        char name[30];
        float score;
    } Student;
    
    const char* student_file = "students.dat";
    
    // 创建一些学生数据
    Student students[] = {
        {1001, "Alice", 85.5},
        {1002, "Bob", 92.0},
        {1003, "Charlie", 78.5},
        {1004, "David", 88.0},
        {1005, "Eve", 95.5}
    };
    
    int student_count = sizeof(students) / sizeof(Student);
    
    // 写入学生数据
    FILE *fp = fopen(student_file, "wb");
    if (fp) {
        // 写入记录数量
        fwrite(&student_count, sizeof(int), 1, fp);
        
        // 写入所有学生记录
        fwrite(students, sizeof(Student), student_count, fp);
        
        fclose(fp);
        printf("   创建了 %d 个学生记录\n", student_count);
    }
    printf("\n");
    
    /*
     * 3.2 直接访问特定记录
     */
    printf("3.2 直接访问特定记录\n\n");
    
    fp = fopen(student_file, "rb");
    if (fp) {
        int record_count;
        fread(&record_count, sizeof(int), 1, fp);
        
        printf("   文件中有 %d 条记录\n", record_count);
        
        // 直接读取第三条记录（索引2）
        int record_index = 2;  // 第三条记录
        if (record_index >= 0 && record_index < record_count) {
            // 计算记录位置：记录数量的大小 + 索引 * 记录大小
            long record_size = sizeof(Student);
            long position = sizeof(int) + record_index * record_size;
            
            fseek(fp, position, SEEK_SET);
            
            Student student;
            fread(&student, sizeof(Student), 1, fp);
            
            printf("   第 %d 条记录（直接访问）：\n", record_index + 1);
            printf("   学号：%d\n", student.id);
            printf("   姓名：%s\n", student.name);
            printf("   成绩：%.1f\n", student.score);
        }
        
        fclose(fp);
    }
    printf("\n");
    
    /*
     * 3.3 按ID查找记录
     */
    printf("3.3 按ID查找记录\n\n");
    
    fp = fopen(student_file, "rb");
    if (fp) {
        int record_count;
        fread(&record_count, sizeof(int), 1, fp);
        
        // 要查找的ID
        int search_id = 1004;
        
        Student student;
        int found = 0;
        
        // 顺序查找（可以用索引优化）
        for (int i = 0; i < record_count; i++) {
            fread(&student, sizeof(Student), 1, fp);
            if (student.id == search_id) {
                found = 1;
                printf("   找到学生记录（第 %d 条）：\n", i + 1);
                printf("   学号：%d\n", student.id);
                printf("   姓名：%s\n", student.name);
                printf("   成绩：%.1f\n", student.score);
                break;
            }
        }
        
        if (!found) {
            printf("   未找到学号为 %d 的学生\n", search_id);
        }
        
        fclose(fp);
    }
    printf("\n");
    
    /*
     * 3.4 更新特定记录
     */
    printf("3.4 更新特定记录\n\n");
    
    fp = fopen(student_file, "r+b");  // 读写模式
    if (fp) {
        int record_count;
        fread(&record_count, sizeof(int), 1, fp);
        
        // 要更新的ID
        int update_id = 1003;
        
        Student student;
        int found_index = -1;
        
        // 查找记录位置
        for (int i = 0; i < record_count; i++) {
            long current_pos = ftell(fp);
            fread(&student, sizeof(Student), 1, fp);
            if (student.id == update_id) {
                found_index = i;
                printf("   找到要更新的记录：%s，原成绩：%.1f\n", 
                       student.name, student.score);
                
                // 修改成绩
                student.score = 85.0;
                
                // 回到记录开头
                fseek(fp, current_pos, SEEK_SET);
                
                // 写回修改后的记录
                fwrite(&student, sizeof(Student), 1, fp);
                
                printf("   更新后成绩：%.1f\n", student.score);
                break;
            }
        }
        
        if (found_index == -1) {
            printf("   未找到要更新的记录\n");
        }
        
        fclose(fp);
    }
    printf("\n");
    
    /*
     * 3.5 显示所有记录
     */
    printf("3.5 显示所有记录\n\n");
    
    fp = fopen(student_file, "rb");
    if (fp) {
        int record_count;
        fread(&record_count, sizeof(int), 1, fp);
        
        printf("   所有学生记录：\n");
        printf("   序号  学号   姓名       成绩\n");
        printf("   ------------------------------\n");
        
        Student student;
        for (int i = 0; i < record_count; i++) {
            fread(&student, sizeof(Student), 1, fp);
            printf("   %-6d%-7d%-11s%.1f\n", 
                   i + 1, student.id, student.name, student.score);
        }
        
        fclose(fp);
    }
    
    // 清理文件
    remove(student_file);
    printf("\n");
}

/*============================================================================
  第五部分：高级文件操作
============================================================================*/

void part5_advanced_file_operations(void) {
    printf("\n");
    printf("================================================\n");
    printf("第五部分：高级文件操作\n");
    printf("================================================\n\n");
    
    /*
     * 1. 文件管理函数
     */
    printf("1. 文件管理函数\n\n");
    
    printf("   标准库函数：\n");
    printf("   --------------------------------------------------\n");
    printf("   函数          描述                    头文件\n");
    printf("   --------------------------------------------------\n");
    printf("   remove()      删除文件                <stdio.h>\n");
    printf("   rename()      重命名或移动文件        <stdio.h>\n\n");
    
    printf("   POSIX函数：\n");
    printf("   --------------------------------------------------\n");
    printf("   access()      检查文件访问权限        <unistd.h>\n");
    printf("   unlink()      删除文件（链接）        <unistd.h>\n");
    printf("   stat()        获取文件状态信息        <sys/stat.h>\n");
    printf("   chmod()       修改文件权限            <sys/stat.h>\n");
    printf("   chown()       修改文件所有者          <unistd.h>\n\n");
}

/*============================================================================
  5.2 文件管理函数演示
============================================================================*/

void file_management_functions(void) {
    printf("2. 文件管理函数演示\n\n");
    
    /*
     * 2.1 文件删除
     */
    printf("2.1 文件删除（remove）\n\n");
    
    // 创建测试文件
    FILE *fp = fopen("delete_test.txt", "w");
    if (fp) {
        fprintf(fp, "This file will be deleted.\n");
        fclose(fp);
        printf("   创建测试文件：delete_test.txt\n");
    }
    
    // 检查文件是否存在
    if (access("delete_test.txt", F_OK) == 0) {
        printf("   文件存在，大小：%ld 字节\n", get_file_size("delete_test.txt"));
        
        // 删除文件
        if (remove("delete_test.txt") == 0) {
            printf("   文件删除成功\n");
        } else {
            perror("   删除失败");
        }
        
        // 再次检查
        if (access("delete_test.txt", F_OK) != 0) {
            printf("   确认文件已不存在\n");
        }
    }
    printf("\n");
    
    /*
     * 2.2 文件重命名
     */
    printf("2.2 文件重命名（rename）\n\n");
    
    // 创建源文件
    fp = fopen("source_rename.txt", "w");
    if (fp) {
        fprintf(fp, "This file will be renamed.\n");
        fclose(fp);
        printf("   创建源文件：source_rename.txt\n");
    }
    
    // 重命名文件
    if (rename("source_rename.txt", "dest_rename.txt") == 0) {
        printf("   文件重命名为：dest_rename.txt\n");
        
        // 验证新文件存在
        if (access("dest_rename.txt", F_OK) == 0) {
            printf("   新文件存在，内容：\n");
            fp = fopen("dest_rename.txt", "r");
            if (fp) {
                char buffer[100];
                fgets(buffer, sizeof(buffer), fp);
                printf("   %s", buffer);
                fclose(fp);
            }
        }
        
        // 验证旧文件不存在
        if (access("source_rename.txt", F_OK) != 0) {
            printf("   旧文件已不存在\n");
        }
    } else {
        perror("   重命名失败");
    }
    
    // 清理
    remove("dest_rename.txt");
    printf("\n");
    
    /*
     * 2.3 文件移动（跨目录）
     */
    printf("2.3 文件移动（跨目录重命名）\n\n");
    
    // 创建目录（如果不存在）
    #ifdef _WIN32
    system("mkdir test_dir 2>nul");
    #else
    system("mkdir -p test_dir 2>/dev/null");
    #endif
    
    // 创建要移动的文件
    fp = fopen("move_source.txt", "w");
    if (fp) {
        fprintf(fp, "This file will be moved to another directory.\n");
        fclose(fp);
        printf("   创建要移动的文件：move_source.txt\n");
    }
    
    // 移动文件到子目录
    if (rename("move_source.txt", "test_dir/moved_file.txt") == 0) {
        printf("   文件移动到：test_dir/moved_file.txt\n");
        
        // 验证移动成功
        if (access("test_dir/moved_file.txt", F_OK) == 0) {
            printf("   目标文件存在\n");
        }
        if (access("move_source.txt", F_OK) != 0) {
            printf("   源文件已不存在\n");
        }
    }
    printf("\n");
    
    /*
     * 2.4 文件状态信息
     */
    printf("2.4 文件状态信息（stat）\n\n");
    
    struct stat file_stat;
    
    // 获取文件状态
    if (stat("test_dir/moved_file.txt", &file_stat) == 0) {
        printf("   文件状态信息：\n");
        printf("   --------------------------------------------------\n");
        printf("   文件大小：%lld 字节\n", (long long)file_stat.st_size);
        printf("   文件权限：%o（八进制）\n", file_stat.st_mode & 0777);
        printf("   最后访问时间：%s", ctime(&file_stat.st_atime));
        printf("   最后修改时间：%s", ctime(&file_stat.st_mtime));
        printf("   最后状态改变时间：%s", ctime(&file_stat.st_ctime));
        
        // 文件类型
        printf("   文件类型：");
        if (S_ISREG(file_stat.st_mode)) printf("普通文件\n");
        if (S_ISDIR(file_stat.st_mode)) printf("目录\n");
        if (S_ISCHR(file_stat.st_mode)) printf("字符设备\n");
        if (S_ISBLK(file_stat.st_mode)) printf("块设备\n");
        if (S_ISFIFO(file_stat.st_mode)) printf("FIFO/管道\n");
        if (S_ISLNK(file_stat.st_mode)) printf("符号链接\n");
        if (S_ISSOCK(file_stat.st_mode)) printf("套接字\n");
        
        // 文件权限详细
        printf("   权限详细：\n");
        printf("   用户读：%s\n", (file_stat.st_mode & S_IRUSR) ? "是" : "否");
        printf("   用户写：%s\n", (file_stat.st_mode & S_IWUSR) ? "是" : "否");
        printf("   用户执行：%s\n", (file_stat.st_mode & S_IXUSR) ? "是" : "否");
        printf("   组读：%s\n", (file_stat.st_mode & S_IRGRP) ? "是" : "否");
        printf("   组写：%s\n", (file_stat.st_mode & S_IWGRP) ? "是" : "否");
        printf("   组执行：%s\n", (file_stat.st_mode & S_IXGRP) ? "是" : "否");
        printf("   其他读：%s\n", (file_stat.st_mode & S_IROTH) ? "是" : "否");
        printf("   其他写：%s\n", (file_stat.st_mode & S_IWOTH) ? "是" : "否");
        printf("   其他执行：%s\n", (file_stat.st_mode & S_IXOTH) ? "是" : "否");
    } else {
        perror("   获取文件状态失败");
    }
    printf("\n");
    
    /*
     * 2.5 修改文件权限
     */
    printf("2.5 修改文件权限（chmod）\n\n");
    
    const char* perm_file = "permission_test.txt";
    
    // 创建测试文件
    fp = fopen(perm_file, "w");
    if (fp) {
        fprintf(fp, "Permission test file.\n");
        fclose(fp);
        
        printf("   创建文件：%s\n", perm_file);
        
        // 获取当前权限
        stat(perm_file, &file_stat);
        printf("   当前权限：%o\n", file_stat.st_mode & 0777);
        
        // 修改权限为只读
        if (chmod(perm_file, 0444) == 0) {
            printf("   修改权限为只读（0444）\n");
            
            // 验证修改
            stat(perm_file, &file_stat);
            printf("   新权限：%o\n", file_stat.st_mode & 0777);
            
            // 尝试写入（应该失败）
            fp = fopen(perm_file, "w");
            if (fp == NULL) {
                printf("   写入被拒绝（符合预期）\n");
            }
            
            // 恢复可写权限
            chmod(perm_file, 0644);
            printf("   恢复可写权限（0644）\n");
        }
    }
    
    // 清理
    remove(perm_file);
    
    #ifdef _WIN32
    system("rmdir /s /q test_dir 2>nul");
    #else
    system("rm -rf test_dir 2>/dev/null");
    #endif
    printf("\n");
}

/*============================================================================
  5.3 临时文件
============================================================================*/

void temporary_files(void) {
    printf("3. 临时文件处理\n\n");
    
    /*
     * 3.1 临时文件函数
     */
    printf("3.1 临时文件函数\n\n");
    
    printf("   临时文件用途：\n");
    printf("   1. 存储中间计算结果\n");
    printf("   2. 缓存数据\n");
    printf("   3. 进程间通信\n");
    printf("   4. 下载文件的暂存\n\n");
    
    printf("   相关函数：\n");
    printf("   --------------------------------------------------\n");
    printf("   函数          描述\n");
    printf("   --------------------------------------------------\n");
    printf("   tmpfile()     创建临时文件（自动删除）\n");
    printf("   tmpnam()      生成临时文件名\n");
    printf("   tempnam()     生成临时文件名（可指定目录）\n");
    printf("   mkstemp()     创建临时文件（POSIX）\n\n");
    
    printf("   安全警告：\n");
    printf("   - tmpnam() 不安全，可能被攻击者利用\n");
    printf("   - 推荐使用 tmpfile() 或 mkstemp()\n\n");
    
    /*
     * 3.2 tmpfile() 演示
     */
    printf("3.2 tmpfile() - 自动删除的临时文件\n\n");
    
    FILE *temp_fp = tmpfile();
    if (temp_fp) {
        printf("   创建临时文件成功\n");
        
        // 写入数据
        fprintf(temp_fp, "这是临时文件内容\n");
        fprintf(temp_fp, "第二行内容\n");
        fprintf(temp_fp, "数字：%d %.2f\n", 42, 3.14);
        
        // 获取文件大小
        fseek(temp_fp, 0, SEEK_END);
        long size = ftell(temp_fp);
        printf("   临时文件大小：%ld 字节\n", size);
        
        // 读取数据
        rewind(temp_fp);
        char buffer[256];
        printf("   临时文件内容：\n");
        while (fgets(buffer, sizeof(buffer), temp_fp)) {
            printf("   %s", buffer);
        }
        
        // 文件会自动在 fclose 时删除
        fclose(temp_fp);
        printf("   临时文件已自动删除\n");
    } else {
        perror("   创建临时文件失败");
    }
    printf("\n");
    
    /*
     * 3.3 tmpnam() 演示（不安全，仅演示）
     */
    printf("3.3 tmpnam() - 生成临时文件名（不安全）\n\n");
    
    char temp_name[L_tmpnam];
    char *name_ptr = tmpnam(temp_name);
    
    if (name_ptr) {
        printf("   生成的临时文件名：%s\n", temp_name);
        
        // 使用这个文件名创建文件
        FILE *fp = fopen(temp_name, "w");
        if (fp) {
            fprintf(fp, "使用tmpnam创建的文件\n");
            fclose(fp);
            
            printf("   文件创建成功\n");
            
            // 手动删除
            remove(temp_name);
            printf("   文件已手动删除\n");
        }
    }
    printf("\n");
    
    /*
     * 3.4 mkstemp() 演示（POSIX，更安全）
     */
    printf("3.4 mkstemp() - 创建临时文件（POSIX）\n\n");
    
    #ifndef _WIN32  // mkstemp 在 Windows 上不可用
    char template[] = "/tmp/mytempXXXXXX";  // 最后6个X会被替换
    int fd = mkstemp(template);
    
    if (fd != -1) {
        printf("   创建临时文件：%s\n", template);
        
        // 将文件描述符转换为文件指针
        FILE *fp = fdopen(fd, "w+");
        if (fp) {
            fprintf(fp, "使用mkstemp创建的临时文件\n");
            fflush(fp);
            
            // 读取验证
            rewind(fp);
            char buffer[256];
            fgets(buffer, sizeof(buffer), fp);
            printf("   文件内容：%s", buffer);
            
            fclose(fp);  // 这也会关闭文件描述符
        }
        
        // 文件不会自动删除，需要手动删除
        unlink(template);
        printf("   临时文件已删除\n");
    } else {
        perror("   mkstemp失败");
    }
    #else
    printf("   mkstemp() 在Windows上不可用\n");
    #endif
    printf("\n");
    
    /*
     * 3.5 临时文件最佳实践
     */
    printf("3.5 临时文件最佳实践\n\n");
    
    printf("   1. 使用 tmpfile() 处理不需要命名的临时文件\n");
    printf("   2. 如果需要文件名，使用 mkstemp()（POSIX）\n");
    printf("   3. 避免使用 tmpnam()（不安全）\n");
    printf("   4. 及时删除临时文件\n");
    printf("   5. 设置合适的临时文件权限\n");
    printf("   6. 考虑使用内存代替临时文件\n");
    printf("   7. 处理临时文件创建失败的情况\n");
    printf("   8. 确保程序异常退出时能清理临时文件\n\n");
    
    printf("   示例：安全的临时文件包装函数\n");
    printf("   FILE* create_temp_file(char **filename) {\n");
    printf("   #ifndef _WIN32\n");
    printf("       char template[] = \"/tmp/myapp_XXXXXX\";\n");
    printf("       int fd = mkstemp(template);\n");
    printf("       if (fd == -1) return NULL;\n");
    printf("       \n");
    printf("       if (filename) *filename = strdup(template);\n");
    printf("       return fdopen(fd, \"w+\");\n");
    printf("   #else\n");
    printf("       // Windows实现\n");
    printf("       FILE* fp = tmpfile();\n");
    printf("       if (fp && filename) *filename = NULL;\n");
    printf("       return fp;\n");
    printf("   #endif\n");
    printf("   }\n\n");
}

/*============================================================================
  5.4 缓冲I/O控制
============================================================================*/

void buffered_io(void) {
    printf("4. 缓冲I/O控制\n\n");
    
    /*
     * 4.1 缓冲类型回顾
     */
    printf("4.1 缓冲类型回顾\n\n");
    
    printf("   三种缓冲类型：\n");
    printf("   1. 全缓冲（_IOFBF）\n");
    printf("      - 缓冲区满才进行I/O操作\n");
    printf("      - 普通文件默认\n\n");
    
    printf("   2. 行缓冲（_IOLBF）\n");
    printf("      - 遇到换行符或缓冲区满\n");
    printf("      - 标准输出（stdout）默认\n\n");
    
    printf("   3. 无缓冲（_IONBF）\n");
    printf("      - 立即进行I/O操作\n");
    printf("      - 标准错误（stderr）默认\n\n");
    
    /*
     * 4.2 缓冲控制函数
     */
    printf("4.2 缓冲控制函数\n\n");
    
    printf("   setvbuf() - 设置缓冲类型和大小\n");
    printf("   原型：int setvbuf(FILE *stream, char *buffer, \n");
    printf("                     int mode, size_t size);\n");
    printf("   参数：\n");
    printf("     stream - 文件指针\n");
    printf("     buffer - 用户提供的缓冲区（NULL则自动分配）\n");
    printf("     mode   - _IOFBF, _IOLBF, _IONBF\n");
    printf("     size   - 缓冲区大小\n\n");
    
    printf("   setbuf() - setvbuf的简化版本\n");
    printf("   fflush() - 刷新缓冲区\n");
    printf("   fpurge() - 清空缓冲区（某些系统）\n\n");
    
    /*
     * 4.3 缓冲控制演示
     */
    printf("4.3 缓冲控制演示\n\n");
    
    const char* buffer_test_file = "buffer_test.txt";
    
    printf("   测试不同缓冲类型对性能的影响：\n\n");
    
    // 测试1：默认缓冲（全缓冲）
    printf("   测试1：默认缓冲（全缓冲）\n");
    FILE *fp1 = fopen(buffer_test_file, "w");
    if (fp1) {
        clock_t start = clock();
        for (int i = 0; i < 10000; i++) {
            fprintf(fp1, "Line %d: This is a test line for buffering.\n", i);
        }
        clock_t end = clock();
        fclose(fp1);
        printf("   写入时间：%.4f秒\n", 
               (double)(end - start) / CLOCKS_PER_SEC);
    }
    
    // 测试2：无缓冲
    printf("   测试2：无缓冲\n");
    FILE *fp2 = fopen("buffer_test2.txt", "w");
    if (fp2) {
        setbuf(fp2, NULL);  // 无缓冲
        
        clock_t start = clock();
        for (int i = 0; i < 10000; i++) {
            fprintf(fp2, "Line %d: This is a test line for buffering.\n", i);
        }
        clock_t end = clock();
        fclose(fp2);
        printf("   写入时间：%.4f秒\n", 
               (double)(end - start) / CLOCKS_PER_SEC);
    }
    
    // 测试3：自定义缓冲区
    printf("   测试3：自定义大缓冲区（32KB）\n");
    FILE *fp3 = fopen("buffer_test3.txt", "w");
    if (fp3) {
        char custom_buffer[32768];  // 32KB
        setvbuf(fp3, custom_buffer, _IOFBF, sizeof(custom_buffer));
        
        clock_t start = clock();
        for (int i = 0; i < 10000; i++) {
            fprintf(fp3, "Line %d: This is a test line for buffering.\n", i);
        }
        clock_t end = clock();
        fclose(fp3);
        printf("   写入时间：%.4f秒\n", 
               (double)(end - start) / CLOCKS_PER_SEC);
    }
    
    // 测试4：行缓冲
    printf("   测试4：行缓冲\n");
    FILE *fp4 = fopen("buffer_test4.txt", "w");
    if (fp4) {
        setvbuf(fp4, NULL, _IOLBF, BUFSIZ);
        
        clock_t start = clock();
        for (int i = 0; i < 10000; i++) {
            fprintf(fp4, "Line %d: This is a test line for buffering.\n", i);
        }
        clock_t end = clock();
        fclose(fp4);
        printf("   写入时间：%.4f秒\n", 
               (double)(end - start) / CLOCKS_PER_SEC);
    }
    
    printf("\n   结论：全缓冲通常性能最好，适合批量写入\n");
    
    /*
     * 4.4 fflush() 演示
     */
    printf("4.4 fflush() - 刷新缓冲区\n\n");
    
    printf("   演示fflush的用途：\n");
    
    FILE *log_fp = fopen("flush_demo.log", "w");
    if (log_fp) {
        printf("   1. 写入数据但不刷新：\n");
        fprintf(log_fp, "数据1写入\n");
        printf("   数据已写入缓冲区，但可能未到磁盘\n");
        
        printf("   2. 调用fflush()：\n");
        fflush(log_fp);
        printf("   缓冲区已刷新到磁盘\n");
        
        printf("   3. 程序崩溃模拟（不调用fflush）：\n");
        fprintf(log_fp, "数据2写入（可能丢失）\n");
        printf("   如果现在程序崩溃，数据2可能丢失\n");
        
        printf("   4. 安全写入：\n");
        fprintf(log_fp, "数据3写入\n");
        fflush(log_fp);  // 立即刷新
        printf("   数据3已安全写入磁盘\n");
        
        fclose(log_fp);
    }
    
    /*
     * 4.5 缓冲策略选择
     */
    printf("4.5 缓冲策略选择指南\n\n");
    
    printf("   选择缓冲策略：\n");
    printf("   --------------------------------------------------\n");
    printf("   场景                  推荐策略\n");
    printf("   --------------------------------------------------\n");
    printf("   批量写入大文件        全缓冲，大缓冲区\n");
    printf("   交互式输出            行缓冲\n");
    printf("   错误日志              无缓冲\n");
    printf("   实时数据采集          无缓冲\n");
    printf("   数据库事务            每次操作后fflush\n");
    printf("   网络通信              根据协议选择\n\n");
    
    printf("   性能调优建议：\n");
    printf("   1. 测试不同缓冲区大小\n");
    printf("   2. 批量操作减少刷新次数\n");
    printf("   3. 重要数据及时fflush\n");
    printf("   4. 避免频繁的缓冲区切换\n");
    printf("   5. 考虑操作系统页面大小\n\n");
    
    // 清理测试文件
    remove(buffer_test_file);
    remove("buffer_test2.txt");
    remove("buffer_test3.txt");
    remove("buffer_test4.txt");
    remove("flush_demo.log");
    printf("\n");
}

/*============================================================================
  第六部分：目录操作
============================================================================*/

void part6_directory_operations(void) {
    printf("\n");
    printf("================================================\n");
    printf("第六部分：目录操作\n");
    printf("================================================\n\n");
    
    /*
     * 1. 目录操作概述
     */
    printf("1. 目录操作概述\n\n");
    
    printf("   C标准库没有目录操作函数\n");
    printf("   需要使用平台特定的API：\n");
    printf("   --------------------------------------------------\n");
    printf("   平台      头文件         主要函数\n");
    printf("   --------------------------------------------------\n");
    printf("   POSIX     <dirent.h>     opendir, readdir, closedir\n");
    printf("   Windows   <windows.h>    FindFirstFile, FindNextFile\n");
    printf("   C17       <dirent.h>     （新增标准）\n\n");
    
    printf("   本部分主要介绍POSIX目录操作\n");
    printf("   （Windows有类似功能）\n\n");
}

/*============================================================================
  6.2 目录基础操作
============================================================================*/

void directory_basics(void) {
    printf("2. 目录基础操作\n\n");
    
    /*
     * 2.1 创建测试目录结构
     */
    printf("2.1 创建测试目录结构\n\n");
    
    #ifdef _WIN32
    system("mkdir test_root 2>nul");
    system("mkdir test_root\\dir1 2>nul");
    system("mkdir test_root\\dir2 2>nul");
    system("echo content1 > test_root\\file1.txt 2>nul");
    system("echo content2 > test_root\\file2.txt 2>nul");
    system("echo content3 > test_root\\dir1\\file3.txt 2>nul");
    #else
    system("mkdir -p test_root/dir1 2>/dev/null");
    system("mkdir -p test_root/dir2 2>/dev/null");
    system("echo 'content1' > test_root/file1.txt 2>/dev/null");
    system("echo 'content2' > test_root/file2.txt 2>/dev/null");
    system("echo 'content3' > test_root/dir1/file3.txt 2>/dev/null");
    #endif
    
    printf("   创建测试目录结构：\n");
    printf("   test_root/\n");
    printf("   ├── file1.txt\n");
    printf("   ├── file2.txt\n");
    printf("   ├── dir1/\n");
    printf("   │   └── file3.txt\n");
    printf("   └── dir2/\n");
    printf("\n");
    
    /*
     * 2.2 检查目录存在
     */
    printf("2.2 检查目录存在\n\n");
    
    printf("   方法1：使用stat()\n");
    struct stat dir_stat;
    
    if (stat("test_root", &dir_stat) == 0) {
        if (S_ISDIR(dir_stat.st_mode)) {
            printf("   test_root 是目录\n");
        } else {
            printf("   test_root 不是目录\n");
        }
    } else {
        printf("   test_root 不存在\n");
    }
    
    printf("   方法2：使用access()\n");
    if (access("test_root", F_OK) == 0) {
        printf("   test_root 存在\n");
    } else {
        printf("   test_root 不存在\n");
    }
    printf("\n");
    
    /*
     * 2.3 创建目录
     */
    printf("2.3 创建目录\n\n");
    
    #ifdef _WIN32
    printf("   Windows: 使用 _mkdir() 或 system(\"mkdir\")\n");
    #else
    printf("   POSIX: 使用 mkdir() 函数\n");
    
    // 创建目录
    if (mkdir("new_directory", 0755) == 0) {
        printf("   创建目录成功：new_directory\n");
        
        // 设置权限
        chmod("new_directory", 0755);
        printf("   目录权限设置为 755\n");
        
        // 删除目录
        if (rmdir("new_directory") == 0) {
            printf("   目录删除成功\n");
        }
    } else {
        perror("   创建目录失败");
    }
    #endif
    printf("\n");
    
    /*
     * 2.4 删除目录
     */
    printf("2.4 删除目录\n\n");
    
    printf("   注意：只能删除空目录\n");
    printf("   要删除非空目录需要递归删除\n\n");
    
    // 创建然后删除测试目录
    #ifndef _WIN32
    mkdir("temp_dir", 0755);
    FILE *fp = fopen("temp_dir/temp.txt", "w");
    if (fp) {
        fprintf(fp, "test\n");
        fclose(fp);
    }
    
    printf("   尝试删除非空目录：\n");
    if (rmdir("temp_dir") == -1) {
        perror("   删除失败（目录非空）");
        
        // 先删除文件
        remove("temp_dir/temp.txt");
        if (rmdir("temp_dir") == 0) {
            printf("   删除空目录成功\n");
        }
    }
    #endif
    printf("\n");
}

/*============================================================================
  6.3 目录遍历
============================================================================*/

void directory_traversal(void) {
    printf("3. 目录遍历\n\n");
    
    #ifndef _WIN32  // POSIX目录遍历
    
    /*
     * 3.1 基本目录遍历
     */
    printf("3.1 基本目录遍历\n\n");
    
    DIR *dir = opendir("test_root");
    if (dir) {
        printf("   打开目录 test_root 成功\n");
        printf("   目录内容：\n");
        printf("   --------------------------------------------------\n");
        
        struct dirent *entry;
        int count = 0;
        
        while ((entry = readdir(dir)) != NULL) {
            // 跳过 . 和 ..
            if (strcmp(entry->d_name, ".") == 0 || 
                strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            
            // 获取完整路径
            char fullpath[256];
            snprintf(fullpath, sizeof(fullpath), 
                    "test_root/%s", entry->d_name);
            
            // 获取文件信息
            struct stat st;
            if (stat(fullpath, &st) == 0) {
                printf("   %-20s", entry->d_name);
                
                if (S_ISDIR(st.st_mode)) {
                    printf(" [目录]");
                } else if (S_ISREG(st.st_mode)) {
                    printf(" [文件] %lld 字节", (long long)st.st_size);
                } else if (S_ISLNK(st.st_mode)) {
                    printf(" [链接]");
                }
                
                printf("\n");
            }
            count++;
        }
        
        printf("   --------------------------------------------------\n");
        printf("   总条目数：%d\n", count);
        
        closedir(dir);
    } else {
        perror("   打开目录失败");
    }
    printf("\n");
    
    /*
     * 3.2 递归目录遍历
     */
    printf("3.2 递归目录遍历\n\n");
    
    // 递归遍历函数
    void list_directory_recursive(const char *path, int depth) {
        DIR *dir = opendir(path);
        if (!dir) return;
        
        struct dirent *entry;
        
        while ((entry = readdir(dir)) != NULL) {
            // 跳过 . 和 ..
            if (strcmp(entry->d_name, ".") == 0 || 
                strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            
            // 缩进显示层级
            for (int i = 0; i < depth; i++) {
                printf("  ");
            }
            
            // 构建完整路径
            char fullpath[1024];
            snprintf(fullpath, sizeof(fullpath), 
                    "%s/%s", path, entry->d_name);
            
            struct stat st;
            if (stat(fullpath, &st) == 0) {
                if (S_ISDIR(st.st_mode)) {
                    printf("📁 %s/\n", entry->d_name);
                    // 递归遍历子目录
                    list_directory_recursive(fullpath, depth + 1);
                } else {
                    printf("📄 %s", entry->d_name);
                    if (S_ISREG(st.st_mode)) {
                        printf(" (%lld 字节)", (long long)st.st_size);
                    }
                    printf("\n");
                }
            }
        }
        
        closedir(dir);
    }
    
    printf("   递归遍历 test_root：\n");
    printf("   --------------------------------------------------\n");
    list_directory_recursive("test_root", 0);
    printf("   --------------------------------------------------\n");
    printf("\n");
    
    /*
     * 3.3 文件搜索
     */
    printf("3.3 文件搜索\n\n");
    
    // 搜索函数：查找特定扩展名的文件
    void find_files_by_extension(const char *path, const char *ext) {
        DIR *dir = opendir(path);
        if (!dir) return;
        
        struct dirent *entry;
        
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") == 0 || 
                strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            
            char fullpath[1024];
            snprintf(fullpath, sizeof(fullpath), 
                    "%s/%s", path, entry->d_name);
            
            struct stat st;
            if (stat(fullpath, &st) == 0) {
                if (S_ISDIR(st.st_mode)) {
                    // 递归搜索子目录
                    find_files_by_extension(fullpath, ext);
                } else if (S_ISREG(st.st_mode)) {
                    // 检查文件扩展名
                    char *dot = strrchr(entry->d_name, '.');
                    if (dot && strcmp(dot + 1, ext) == 0) {
                        printf("   找到：%s (%lld 字节)\n", 
                               fullpath, (long long)st.st_size);
                    }
                }
            }
        }
        
        closedir(dir);
    }
    
    printf("   搜索 .txt 文件：\n");
    find_files_by_extension("test_root", "txt");
    printf("\n");
    
    /*
     * 3.4 目录统计
     */
    printf("3.4 目录统计\n\n");
    
    typedef struct {
        long long total_size;
        int file_count;
        int dir_count;
        int other_count;
    } DirStats;
    
    void calculate_directory_stats(const char *path, DirStats *stats) {
        DIR *dir = opendir(path);
        if (!dir) return;
        
        struct dirent *entry;
        
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") == 0 || 
                strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            
            char fullpath[1024];
            snprintf(fullpath, sizeof(fullpath), 
                    "%s/%s", path, entry->d_name);
            
            struct stat st;
            if (stat(fullpath, &st) == 0) {
                if (S_ISDIR(st.st_mode)) {
                    stats->dir_count++;
                    // 递归统计子目录
                    calculate_directory_stats(fullpath, stats);
                } else if (S_ISREG(st.st_mode)) {
                    stats->file_count++;
                    stats->total_size += st.st_size;
                } else {
                    stats->other_count++;
                }
            }
        }
        
        closedir(dir);
    }
    
    DirStats stats = {0, 0, 0, 0};
    calculate_directory_stats("test_root", &stats);
    
    printf("   目录统计结果：\n");
    printf("   --------------------------------------------------\n");
    printf("   文件数：%d\n", stats.file_count);
    printf("   目录数：%d\n", stats.dir_count);
    printf("   其他：%d\n", stats.other_count);
    printf("   总大小：%.2f KB\n", stats.total_size / 1024.0);
    printf("   --------------------------------------------------\n");
    
    #else
    printf("   目录遍历演示在Windows上不可用\n");
    printf("   请使用Linux或macOS环境运行此演示\n");
    #endif
    printf("\n");
    
    /*
     * 3.5 目录操作最佳实践
     */
    printf("3.5 目录操作最佳实践\n\n");
    
    printf("   1. 总是检查目录操作返回值\n");
    printf("   2. 处理特殊目录 . 和 ..\n");
    printf("   3. 注意路径长度限制\n");
    printf("   4. 考虑跨平台兼容性\n");
    printf("   5. 递归操作注意栈溢出\n");
    printf("   6. 处理符号链接\n");
    printf("   7. 注意权限问题\n");
    printf("   8. 及时释放资源（closedir）\n\n");
    
    printf("   跨平台目录遍历示例：\n");
    printf("   #ifdef _WIN32\n");
    printf("       // Windows实现\n");
    printf("       WIN32_FIND_DATA find_data;\n");
    printf("       HANDLE hFind = FindFirstFile(\"path\\\\*\", &find_data);\n");
    printf("   #else\n");
    printf("       // POSIX实现\n");
    printf("       DIR *dir = opendir(\"path\");\n");
    printf("       struct dirent *entry;\n");
    printf("   #endif\n\n");
    
    // 清理测试目录
    #ifdef _WIN32
    system("rmdir /s /q test_root 2>nul");
    #else
    system("rm -rf test_root 2>/dev/null");
    #endif
}

/*============================================================================
  第七部分：实际应用案例
============================================================================*/

void part7_real_world_applications(void) {
    printf("\n");
    printf("================================================\n");
    printf("第七部分：实际应用案例\n");
    printf("================================================\n\n");
    
    /*
     * 1. 案例概览
     */
    printf("1. 实际应用案例概览\n\n");
    
    printf("   我们将演示：\n");
    printf("   1. 文件加密/解密\n");
    printf("   2. 日志文件系统\n");
    printf("   3. 配置文件读写\n");
    printf("   4. 数据备份系统\n");
    printf("   5. CSV文件处理\n");
    printf("   6. 简单数据库\n\n");
}

/*============================================================================
  7.2 文件加密解密
============================================================================*/

void file_encryption_demo(void) {
    printf("2. 文件加密/解密系统\n\n");
    
    /*
     * 2.1 简单的XOR加密
     */
    printf("2.1 简单的XOR加密\n\n");
    
    void xor_encrypt_file(const char *input_file, 
                         const char *output_file, 
                         const char *key) {
        FILE *in_fp = fopen(input_file, "rb");
        FILE *out_fp = fopen(output_file, "wb");
        
        if (!in_fp || !out_fp) {
            if (in_fp) fclose(in_fp);
            if (out_fp) fclose(out_fp);
            return;
        }
        
        int key_len = strlen(key);
        int key_index = 0;
        int ch;
        
        while ((ch = fgetc(in_fp)) != EOF) {
            // 使用XOR加密
            ch = ch ^ key[key_index];
            fputc(ch, out_fp);
            
            key_index = (key_index + 1) % key_len;
        }
        
        fclose(in_fp);
        fclose(out_fp);
    }
    
    // 创建测试文件
    FILE *test_fp = fopen("secret.txt", "w");
    if (test_fp) {
        fprintf(test_fp, "这是机密信息！\n");
        fprintf(test_fp, "密码：123456\n");
        fprintf(test_fp, "银行账户：XXXX-XXXX-XXXX\n");
        fclose(test_fp);
        
        printf("   创建测试文件：secret.txt\n");
        printf("   文件内容：\n");
        
        test_fp = fopen("secret.txt", "r");
        if (test_fp) {
            char buffer[256];
            while (fgets(buffer, sizeof(buffer), test_fp)) {
                printf("   %s", buffer);
            }
            fclose(test_fp);
        }
    }
    printf("\n");
    
    // 加密文件
    printf("   使用密钥 'mysecretkey' 加密文件...\n");
    xor_encrypt_file("secret.txt", "secret.enc", "mysecretkey");
    
    printf("   加密完成：secret.enc\n");
    printf("   加密后文件（十六进制显示）：\n");
    
    FILE *enc_fp = fopen("secret.enc", "rb");
    if (enc_fp) {
        int ch;
        int count = 0;
        printf("   ");
        while ((ch = fgetc(enc_fp)) != EOF) {
            printf("%02X ", ch);
            count++;
            if (count % 16 == 0) printf("\n   ");
        }
        printf("\n");
        fclose(enc_fp);
    }
    printf("\n");
    
    // 解密文件
    printf("   解密文件...\n");
    xor_encrypt_file("secret.enc", "secret.dec", "mysecretkey");
    
    printf("   解密完成：secret.dec\n");
    printf("   解密后内容：\n");
    
    FILE *dec_fp = fopen("secret.dec", "r");
    if (dec_fp) {
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), dec_fp)) {
            printf("   %s", buffer);
        }
        fclose(dec_fp);
    }
    printf("\n");
    
    // 清理
    remove("secret.txt");
    remove("secret.enc");
    remove("secret.dec");
    
    /*
     * 2.2 简单的文件完整性校验
     */
    printf("2.2 文件完整性校验（MD5模拟）\n\n");
    
    // 简单的校验和计算
    unsigned long simple_checksum(const char *filename) {
        FILE *fp = fopen(filename, "rb");
        if (!fp) return 0;
        
        unsigned long checksum = 0;
        int ch;
        
        while ((ch = fgetc(fp)) != EOF) {
            checksum = (checksum * 31 + ch) % 1000000007;
        }
        
        fclose(fp);
        return checksum;
    }
    
    // 创建测试文件
    test_fp = fopen("checksum_test.txt", "w");
    if (test_fp) {
        fprintf(test_fp, "重要文件内容，需要校验完整性。\n");
        fclose(test_fp);
        
        // 计算校验和
        unsigned long original_sum = simple_checksum("checksum_test.txt");
        printf("   文件校验和：%lu\n", original_sum);
        
        // 模拟文件被修改
        test_fp = fopen("checksum_test.txt", "a");
        if (test_fp) {
            fprintf(test_fp, "（恶意修改）\n");
            fclose(test_fp);
            
            unsigned long modified_sum = simple_checksum("checksum_test.txt");
            printf("   修改后校验和：%lu\n", modified_sum);
            
            if (original_sum == modified_sum) {
                printf("   ✅ 文件完整性验证通过\n");
            } else {
                printf("   ❌ 文件已被修改！\n");
            }
        }
        
        remove("checksum_test.txt");
    }
    printf("\n");
}

/*============================================================================
  7.3 日志文件系统
============================================================================*/

void log_file_system(void) {
    printf("3. 日志文件系统\n\n");
    
    /*
     * 3.1 基本的日志系统
     */
    printf("3.1 基本的日志系统\n\n");
    
    typedef struct {
        FILE *log_fp;
        char log_file[256];
        int max_size;  // 最大文件大小（KB）
        int level;     // 日志级别
    } Logger;
    
    // 日志级别
    enum LogLevel {
        LOG_DEBUG,
        LOG_INFO,
        LOG_WARNING,
        LOG_ERROR,
        LOG_CRITICAL
    };
    
    // 初始化日志系统
    Logger* logger_init(const char *filename, int max_size_kb, int level) {
        Logger *logger = malloc(sizeof(Logger));
        if (!logger) return NULL;
        
        strncpy(logger->log_file, filename, sizeof(logger->log_file) - 1);
        logger->max_size = max_size_kb * 1024;
        logger->level = level;
        
        // 打开日志文件（追加模式）
        logger->log_fp = fopen(filename, "a");
        if (!logger->log_fp) {
            free(logger);
            return NULL;
        }
        
        return logger;
    }
    
    // 检查日志文件大小，如果太大则轮转
    void logger_check_rotate(Logger *logger) {
        if (!logger || !logger->log_fp) return;
        
        fseek(logger->log_fp, 0, SEEK_END);
        long file_size = ftell(logger->log_fp);
        
        if (file_size > logger->max_size) {
            fclose(logger->log_fp);
            
            // 创建备份文件
            char backup_file[256];
            time_t now = time(NULL);
            struct tm *tm_info = localtime(&now);
            
            snprintf(backup_file, sizeof(backup_file),
                    "%s.%04d%02d%02d_%02d%02d%02d",
                    logger->log_file,
                    tm_info->tm_year + 1900, tm_info->tm_mon + 1,
                    tm_info->tm_mday, tm_info->tm_hour,
                    tm_info->tm_min, tm_info->tm_sec);
            
            rename(logger->log_file, backup_file);
            
            // 重新打开日志文件
            logger->log_fp = fopen(logger->log_file, "w");
        }
    }
    
    // 写日志
    void logger_write(Logger *logger, int level, const char *format, ...) {
        if (!logger || !logger->log_fp || level < logger->level) {
            return;
        }
        
        // 检查文件大小
        logger_check_rotate(logger);
        
        // 获取当前时间
        time_t now = time(NULL);
        struct tm *tm_info = localtime(&now);
        
        // 日志级别字符串
        const char *level_str;
        switch (level) {
            case LOG_DEBUG: level_str = "DEBUG"; break;
            case LOG_INFO: level_str = "INFO"; break;
            case LOG_WARNING: level_str = "WARNING"; break;
            case LOG_ERROR: level_str = "ERROR"; break;
            case LOG_CRITICAL: level_str = "CRITICAL"; break;
            default: level_str = "UNKNOWN"; break;
        }
        
        // 写入时间戳和级别
        fprintf(logger->log_fp, "[%04d-%02d-%02d %02d:%02d:%02d] [%s] ",
                tm_info->tm_year + 1900, tm_info->tm_mon + 1,
                tm_info->tm_mday, tm_info->tm_hour,
                tm_info->tm_min, tm_info->tm_sec,
                level_str);
        
        // 写入日志内容
        va_list args;
        va_start(args, format);
        vfprintf(logger->log_fp, format, args);
        va_end(args);
        
        fprintf(logger->log_fp, "\n");
        fflush(logger->log_fp);  // 立即写入，防止丢失
    }
    
    // 关闭日志系统
    void logger_close(Logger *logger) {
        if (logger) {
            if (logger->log_fp) {
                fclose(logger->log_fp);
            }
            free(logger);
        }
    }
    
    printf("   演示日志系统：\n");
    
    // 创建日志系统（最大10KB，记录INFO及以上级别）
    Logger *logger = logger_init("app.log", 10, LOG_INFO);
    
    if (logger) {
        logger_write(logger, LOG_INFO, "应用程序启动");
        logger_write(logger, LOG_DEBUG, "调试信息（不会记录）");
        logger_write(logger, LOG_INFO, "用户登录：user123");
        logger_write(logger, LOG_WARNING, "内存使用率超过80%%");
        logger_write(logger, LOG_ERROR, "数据库连接失败");
        logger_write(logger, LOG_INFO, "处理100条数据记录");
        logger_write(logger, LOG_CRITICAL, "系统即将崩溃！");
        logger_write(logger, LOG_INFO, "应用程序退出");
        
        logger_close(logger);
        
        printf("   日志写入完成\n");
        
        // 显示日志内容
        FILE *log_fp = fopen("app.log", "r");
        if (log_fp) {
            printf("   日志文件内容：\n");
            printf("   --------------------------------------------------\n");
            char buffer[256];
            while (fgets(buffer, sizeof(buffer), log_fp)) {
                printf("   %s", buffer);
            }
            printf("   --------------------------------------------------\n");
            fclose(log_fp);
        }
        
        // 清理
        remove("app.log");
    }
    printf("\n");
    
    /*
     * 3.2 日志分析
     */
    printf("3.2 日志分析\n\n");
    
    // 创建测试日志
    FILE *test_log = fopen("analysis.log", "w");
    if (test_log) {
        fprintf(test_log, "[2024-01-01 10:00:00] [INFO] 系统启动\n");
        fprintf(test_log, "[2024-01-01 10:00:01] [INFO] 用户A登录\n");
        fprintf(test_log, "[2024-01-01 10:00:05] [ERROR] 数据库连接失败\n");
        fprintf(test_log, "[2024-01-01 10:00:10] [INFO] 用户B登录\n");
        fprintf(test_log, "[2024-01-01 10:00:15] [WARNING] 内存使用率高\n");
        fprintf(test_log, "[2024-01-01 10:00:20] [ERROR] 文件打开失败\n");
        fprintf(test_log, "[2024-01-01 10:00:25] [INFO] 用户A退出\n");
        fclose(test_log);
        
        printf("   日志分析结果：\n");
        
        // 分析日志
        FILE *log_fp = fopen("analysis.log", "r");
        if (log_fp) {
            char buffer[256];
            int info_count = 0;
            int warning_count = 0;
            int error_count = 0;
            
            while (fgets(buffer, sizeof(buffer), log_fp)) {
                // 简单的关键字分析
                if (strstr(buffer, "[INFO]")) {
                    info_count++;
                } else if (strstr(buffer, "[WARNING]")) {
                    warning_count++;
                } else if (strstr(buffer, "[ERROR]")) {
                    error_count++;
                }
            }
            
            printf("   INFO级别：%d 条\n", info_count);
            printf("   WARNING级别：%d 条\n", warning_count);
            printf("   ERROR级别：%d 条\n", error_count);
            
            fclose(log_fp);
        }
        
        remove("analysis.log");
    }
    printf("\n");
}

/*============================================================================
  7.4 配置文件处理
============================================================================*/

void configuration_files(void) {
    printf("4. 配置文件处理\n\n");
    
    /*
     * 4.1 INI格式配置文件
     */
    printf("4.1 INI格式配置文件\n\n");
    
    // 创建INI配置文件
    FILE *ini_fp = fopen("config.ini", "w");
    if (ini_fp) {
        fprintf(ini_fp, "# 应用程序配置文件\n");
        fprintf(ini_fp, "# 最后修改：2024-01-01\n\n");
        
        fprintf(ini_fp, "[database]\n");
        fprintf(ini_fp, "host = localhost\n");
        fprintf(ini_fp, "port = 3306\n");
        fprintf(ini_fp, "username = admin\n");
        fprintf(ini_fp, "password = secret123\n");
        fprintf(ini_fp, "database = mydb\n\n");
        
        fprintf(ini_fp, "[server]\n");
        fprintf(ini_fp, "port = 8080\n");
        fprintf(ini_fp, "max_connections = 100\n");
        fprintf(ini_fp, "timeout = 30\n\n");
        
        fprintf(ini_fp, "[logging]\n");
        fprintf(ini_fp, "level = INFO\n");
        fprintf(ini_fp, "file = app.log\n");
        fprintf(ini_fp, "max_size = 1024\n");
        
        fclose(ini_fp);
        
        printf("   创建配置文件：config.ini\n");
        printf("   文件内容：\n");
        printf("   --------------------------------------------------\n");
        
        ini_fp = fopen("config.ini", "r");
        if (ini_fp) {
            char buffer[256];
            while (fgets(buffer, sizeof(buffer), ini_fp)) {
                printf("   %s", buffer);
            }
            fclose(ini_fp);
        }
        printf("   --------------------------------------------------\n");
    }
    printf("\n");
    
    /*
     * 4.2 配置文件读取
     */
    printf("4.2 配置文件读取\n\n");
    
    // 简单的INI解析器
    void read_ini_config(const char *filename) {
        FILE *fp = fopen(filename, "r");
        if (!fp) return;
        
        char buffer[256];
        char current_section[64] = "";
        
        printf("   解析配置文件：\n");
        
        while (fgets(buffer, sizeof(buffer), fp)) {
            // 移除换行符
            buffer[strcspn(buffer, "\n")] = '\0';
            
            // 跳过空行和注释
            if (buffer[0] == '\0' || buffer[0] == '#' || buffer[0] == ';') {
                continue;
            }
            
            // 检查是否是节标记
            if (buffer[0] == '[') {
                char *end = strchr(buffer, ']');
                if (end) {
                    *end = '\0';
                    strcpy(current_section, buffer + 1);
                    printf("   节：%s\n", current_section);
                }
            } 
            // 检查是否是键值对
            else {
                char *equals = strchr(buffer, '=');
                if (equals) {
                    *equals = '\0';
                    char *key = buffer;
                    char *value = equals + 1;
                    
                    // 去除空白字符
                    while (*key == ' ') key++;
                    char *key_end = key + strlen(key) - 1;
                    while (key_end > key && *key_end == ' ') {
                        *key_end = '\0';
                        key_end--;
                    }
                    
                    while (*value == ' ') value++;
                    char *value_end = value + strlen(value) - 1;
                    while (value_end > value && *value_end == ' ') {
                        *value_end = '\0';
                        value_end--;
                    }
                    
                    printf("      %s.%s = %s\n", current_section, key, value);
                }
            }
        }
        
        fclose(fp);
    }
    
    read_ini_config("config.ini");
    printf("\n");
    
    /*
     * 4.3 配置文件修改
     */
    printf("4.3 配置文件修改\n\n");
    
    void update_config_value(const char *filename, 
                            const char *section, 
                            const char *key, 
                            const char *new_value) {
        // 读取整个文件到内存
        FILE *fp = fopen(filename, "r");
        if (!fp) return;
        
        fseek(fp, 0, SEEK_END);
        long file_size = ftell(fp);
        rewind(fp);
        
        char *content = malloc(file_size + 1);
        if (!content) {
            fclose(fp);
            return;
        }
        
        fread(content, 1, file_size, fp);
        content[file_size] = '\0';
        fclose(fp);
        
        // 在内存中修改
        char *current_pos = content;
        char *section_start = NULL;
        int in_target_section = 0;
        
        // 重新写入文件
        fp = fopen(filename, "w");
        if (!fp) {
            free(content);
            return;
        }
        
        while (*current_pos) {
            // 处理行
            char *line_end = strchr(current_pos, '\n');
            if (!line_end) line_end = current_pos + strlen(current_pos);
            
            int line_len = line_end - current_pos;
            char line[256];
            if (line_len > sizeof(line) - 1) line_len = sizeof(line) - 1;
            strncpy(line, current_pos, line_len);
            line[line_len] = '\0';
            
            // 去除行尾的\r
            if (line_len > 0 && line[line_len - 1] == '\r') {
                line[line_len - 1] = '\0';
            }
            
            // 检查是否是目标节
            if (line[0] == '[') {
                char *end = strchr(line, ']');
                if (end) {
                    *end = '\0';
                    if (strcmp(line + 1, section) == 0) {
                        in_target_section = 1;
                    } else {
                        in_target_section = 0;
                    }
                }
            }
            // 在目标节中查找键
            else if (in_target_section && line[0] != '#' && line[0] != ';') {
                char *equals = strchr(line, '=');
                if (equals) {
                    *equals = '\0';
                    
                    // 去除键的空白字符
                    char *key_start = line;
                    while (*key_start == ' ') key_start++;
                    char *key_end = key_start + strlen(key_start) - 1;
                    while (key_end > key_start && *key_end == ' ') {
                        *key_end = '\0';
                        key_end--;
                    }
                    
                    if (strcmp(key_start, key) == 0) {
                        // 找到键，修改值
                        fprintf(fp, "%s = %s\n", key_start, new_value);
                        current_pos = line_end + (*line_end ? 1 : 0);
                        continue;
                    }
                }
            }
            
            // 写入原始行
            fwrite(current_pos, 1, line_end - current_pos, fp);
            if (*line_end) fputc('\n', fp);
            
            current_pos = line_end + (*line_end ? 1 : 0);
        }
        
        fclose(fp);
        free(content);
    }
    
    printf("   修改配置：database.password = newpassword123\n");
    update_config_value("config.ini", "database", "password", "newpassword123");
    
    printf("   修改后的配置文件：\n");
    read_ini_config("config.ini");
    
    // 清理
    remove("config.ini");
    printf("\n");
}

/*============================================================================
  第八部分：性能优化与最佳实践
============================================================================*/

void part8_performance_best_practices(void) {
    printf("\n");
    printf("================================================\n");
    printf("第八部分：性能优化与最佳实践\n");
    printf("================================================\n\n");
    
    /*
     * 1. 性能优化概述
     */
    printf("1. 文件I/O性能优化概述\n\n");
    
    printf("   文件I/O的瓶颈：\n");
    printf("   1. 磁盘访问速度慢（相比内存）\n");
    printf("   2. 系统调用开销\n");
    printf("   3. 上下文切换\n");
    printf("   4. 磁盘寻道时间\n\n");
    
    printf("   优化目标：\n");
    printf("   1. 减少I/O操作次数\n");
    printf("   2. 减少数据拷贝\n");
    printf("   3. 利用缓存\n");
    printf("   4. 异步I/O\n\n");
}

/*============================================================================
  8.2 文件I/O性能优化
============================================================================*/

void file_io_optimization(void) {
    printf("2. 文件I/O性能优化技术\n\n");
    
    /*
     * 2.1 批量读写 vs 单个读写
     */
    printf("2.1 批量读写 vs 单个读写\n\n");
    
    const char* test_file = "io_perf_test.dat";
    const int data_size = 1000000;  // 1百万个整数
    
    printf("   测试批量读写性能：\n");
    
    // 创建测试数据
    int *test_data = malloc(data_size * sizeof(int));
    for (int i = 0; i < data_size; i++) {
        test_data[i] = i;
    }
    
    // 测试1：逐个写入（最差性能）
    printf("   测试1：逐个写入（fwrite单个元素）\n");
    FILE *fp = fopen(test_file, "wb");
    if (fp) {
        clock_t start = clock();
        for (int i = 0; i < data_size; i++) {
            fwrite(&test_data[i], sizeof(int), 1, fp);
        }
        clock_t end = clock();
        fclose(fp);
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("   时间：%.4f秒，速度：%.2f MB/s\n", 
               time_taken, (data_size * sizeof(int)) / time_taken / 1024 / 1024);
    }
    
    // 测试2：批量写入（最佳性能）
    printf("   测试2：批量写入（fwrite整个数组）\n");
    fp = fopen("batch_test.dat", "wb");
    if (fp) {
        clock_t start = clock();
        fwrite(test_data, sizeof(int), data_size, fp);
        clock_t end = clock();
        fclose(fp);
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("   时间：%.4f秒，速度：%.2f MB/s\n", 
               time_taken, (data_size * sizeof(int)) / time_taken / 1024 / 1024);
    }
    
    free(test_data);
    remove(test_file);
    remove("batch_test.dat");
    printf("\n");
    
    /*
     * 2.2 缓冲策略比较
     */
    printf("2.2 缓冲策略比较\n\n");
    
    printf("   测试不同缓冲区大小的影响：\n");
    
    const int test_buffer_sizes[] = {512, 1024, 4096, 16384, 65536};
    const char* buffer_test_file = "buffer_size_test.txt";
    
    for (int i = 0; i < 5; i++) {
        int buffer_size = test_buffer_sizes[i];
        
        fp = fopen(buffer_test_file, "w");
        if (fp) {
            // 设置自定义缓冲区
            char *custom_buffer = malloc(buffer_size);
            setvbuf(fp, custom_buffer, _IOFBF, buffer_size);
            
            clock_t start = clock();
            for (int j = 0; j < 10000; j++) {
                fprintf(fp, "Line %d: Testing buffer size %d\n", j, buffer_size);
            }
            clock_t end = clock();
            
            fclose(fp);
            free(custom_buffer);
            
            double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
            printf("   缓冲区大小：%5d 字节，时间：%.4f秒\n", 
                   buffer_size, time_taken);
        }
    }
    
    remove(buffer_test_file);
    printf("\n");
    
    /*
     * 2.3 顺序访问 vs 随机访问
     */
    printf("2.3 顺序访问 vs 随机访问\n\n");
    
    printf("   创建测试文件用于访问模式比较...\n");
    
    // 创建包含10000个记录的文件
    typedef struct {
        int id;
        double value;
        char description[50];
    } Record;
    
    const int num_records = 10000;
    Record *records = malloc(num_records * sizeof(Record));
    
    for (int i = 0; i < num_records; i++) {
        records[i].id = i;
        records[i].value = i * 1.5;
        snprintf(records[i].description, 50, "Record %d", i);
    }
    
    // 写入文件
    fp = fopen("records.dat", "wb");
    if (fp) {
        fwrite(records, sizeof(Record), num_records, fp);
        fclose(fp);
    }
    
    // 测试顺序访问
    printf("   测试顺序访问：\n");
    fp = fopen("records.dat", "rb");
    if (fp) {
        Record rec;
        clock_t start = clock();
        
        for (int i = 0; i < num_records; i++) {
            fread(&rec, sizeof(Record), 1, fp);
        }
        
        clock_t end = clock();
        fclose(fp);
        
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("   顺序读取 %d 条记录：%.4f秒\n", num_records, time_taken);
    }
    
    // 测试随机访问
    printf("   测试随机访问：\n");
    fp = fopen("records.dat", "rb");
    if (fp) {
        Record rec;
        clock_t start = clock();
        
        // 随机访问1000条记录
        srand(time(NULL));
        for (int i = 0; i < 1000; i++) {
            int random_index = rand() % num_records;
            long position = random_index * sizeof(Record);
            
            fseek(fp, position, SEEK_SET);
            fread(&rec, sizeof(Record), 1, fp);
        }
        
        clock_t end = clock();
        fclose(fp);
        
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("   随机读取 1000 条记录：%.4f秒\n", time_taken);
    }
    
    free(records);
    remove("records.dat");
    printf("\n");
    
    /*
     * 2.4 内存映射文件（概念）
     */
    printf("2.4 内存映射文件（高级优化）\n\n");
    
    printf("   内存映射文件（mmap）概念：\n");
    printf("   1. 将文件直接映射到进程地址空间\n");
    printf("   2. 文件访问像访问内存一样快\n");
    printf("   3. 操作系统负责缓存和同步\n");
    printf("   4. 适合大文件随机访问\n\n");
    
    printf("   优点：\n");
    printf("   - 避免用户空间和内核空间之间的数据拷贝\n");
    printf("   - 可以利用虚拟内存管理\n");
    printf("   - 支持共享内存\n\n");
    
    printf("   缺点：\n");
    printf("   - 实现复杂\n");
    printf("   - 错误处理困难\n");
    printf("   - 可移植性差\n\n");
    
    printf("   使用场景：\n");
    printf("   - 数据库文件\n");
    printf("   - 大型数据文件\n");
    printf("   - 共享内存通信\n\n");
}

/*============================================================================
  8.3 文件I/O最佳实践
============================================================================*/

void file_io_best_practices(void) {
    printf("3. 文件I/O最佳实践总结\n\n");
    
    /*
     * 3.1 错误处理最佳实践
     */
    printf("3.1 错误处理最佳实践\n\n");
    
    printf("   1. 总是检查文件操作返回值\n");
    printf("      FILE *fp = fopen(...);\n");
    printf("      if (fp == NULL) {\n");
    printf("          perror(\"打开文件失败\");\n");
    printf("          return ERROR;\n");
    printf("      }\n\n");
    
    printf("   2. 使用errno和strerror提供详细信息\n");
    printf("      if (ferror(fp)) {\n");
    printf("          fprintf(stderr, \"I/O错误: %s\\n\", strerror(errno));\n");
    printf("      }\n\n");
    
    printf("   3. 区分不同错误类型\n");
    printf("      switch (errno) {\n");
    printf("          case ENOENT: // 文件不存在\n");
    printf("          case EACCES: // 权限不足\n");
    printf("          case ENOSPC: // 磁盘空间不足\n");
    printf("      }\n\n");
    
    printf("   4. 资源清理（即使出错）\n");
    printf("      FILE *fp = NULL;\n");
    printf("      char *buffer = NULL;\n");
    printf("      \n");
    printf("      do {\n");
    printf("          fp = fopen(...);\n");
    printf("          if (!fp) break;\n");
    printf("          \n");
    printf("          buffer = malloc(...);\n");
    printf("          if (!buffer) break;\n");
    printf("          \n");
    printf("          // 业务逻辑\n");
    printf("      } while (0);\n");
    printf("      \n");
    printf("      if (fp) fclose(fp);\n");
    printf("      if (buffer) free(buffer);\n\n");
    
    /*
     * 3.2 性能最佳实践
     */
    printf("3.2 性能最佳实践\n\n");
    
    printf("   1. 批量读写代替单个读写\n");
    printf("      // 差：\n");
    printf("      for (i = 0; i < n; i++) fwrite(&data[i], sizeof(int), 1, fp);\n");
    printf("      // 好：\n");
    printf("      fwrite(data, sizeof(int), n, fp);\n\n");
    
    printf("   2. 使用合适的缓冲区大小\n");
    printf("      setvbuf(fp, buffer, _IOFBF, 65536); // 64KB缓冲区\n\n");
    
    printf("   3. 减少文件打开/关闭次数\n");
    printf("      // 差：多次打开关闭\n");
    printf("      // 好：一次打开，多次操作\n\n");
    
    printf("   4. 顺序访问优于随机访问\n");
    printf("      // 尽量避免频繁的fseek\n\n");
    
    printf("   5. 考虑使用内存映射文件（mmap）\n");
    printf("      // 对于大文件随机访问\n\n");
    
    /*
     * 3.3 代码可读性最佳实践
     */
    printf("3.3 代码可读性最佳实践\n\n");
    
    printf("   1. 使用有意义的文件名变量\n");
    printf("      // 差：\n");
    printf("      FILE *f;\n");
    printf("      // 好：\n");
    printf("      FILE *config_file;\n");
    printf("      FILE *log_file;\n\n");
    
    printf("   2. 统一错误处理模式\n");
    printf("      typedef enum { SUCCESS, FILE_ERROR, MEMORY_ERROR } Result;\n");
    printf("      Result process_file(const char *filename) {\n");
    printf("          FILE *fp = fopen(filename, \"r\");\n");
    printf("          if (!fp) return FILE_ERROR;\n");
    printf("          // ...\n");
    printf("      }\n\n");
    
    printf("   3. 添加适当的注释\n");
    printf("      // 打开配置文件，如果不存在则创建默认配置\n");
    printf("      FILE *fp = fopen(\"config.ini\", \"a+\");\n\n");
    
    printf("   4. 使用常量定义\n");
    printf("      #define MAX_PATH_LENGTH 256\n");
    printf("      #define DEFAULT_BUFFER_SIZE 4096\n\n");
    
    /*
     * 3.4 安全性最佳实践
     */
    printf("3.4 安全性最佳实践\n\n");
    
    printf("   1. 验证文件路径\n");
    printf("      // 防止目录遍历攻击\n");
    printf("      if (strstr(filename, \"..\")) {\n");
    printf("          return ERROR_INVALID_PATH;\n");
    printf("      }\n\n");
    
    printf("   2. 限制文件大小\n");
    printf("      fseek(fp, 0, SEEK_END);\n");
    printf("      long size = ftell(fp);\n");
    printf("      if (size > MAX_FILE_SIZE) {\n");
    printf("          return ERROR_FILE_TOO_LARGE;\n");
    printf("      }\n\n");
    
    printf("   3. 检查文件权限\n");
    printf("      struct stat st;\n");
    printf("      stat(filename, &st);\n");
    printf("      if (st.st_mode & S_IWOTH) { // 其他人可写\n");
    printf("          fprintf(stderr, \"警告：文件权限过宽\\n\");\n");
    printf("      }\n\n");
    
    printf("   4. 避免缓冲区溢出\n");
    printf("      char buffer[MAX_PATH];\n");
    printf("      fgets(buffer, sizeof(buffer), fp); // 安全的\n");
    printf("      // 不要使用 gets()！\n\n");
    
    printf("   5. 清理临时文件\n");
    printf("      FILE *temp = tmpfile(); // 自动清理\n");
    printf("      // 或手动清理\n");
    printf("      remove(\"tempfile.txt\");\n\n");
    
    /*
     * 3.5 可移植性最佳实践
     */
    printf("3.5 可移植性最佳实践\n\n");
    
    printf("   1. 使用标准C函数\n");
    printf("      // 而不是平台特定API\n\n");
    
    printf("   2. 处理路径分隔符\n");
    printf("      #ifdef _WIN32\n");
    printf("          #define PATH_SEPARATOR \"\\\\\"\n");
    printf("      #else\n");
    printf("          #define PATH_SEPARATOR \"/\"\n");
    printf("      #endif\n\n");
    
    printf("   3. 处理文本文件换行符\n");
    printf("      // Windows: \\r\\n, Unix: \\n, Mac: \\r\n");
    printf("      // 使用二进制模式避免问题\n\n");
    
    printf("   4. 使用大文件支持\n");
    printf("      #define _FILE_OFFSET_BITS 64\n");
    printf("      // 支持大于2GB的文件\n\n");
    
    printf("   5. 检查函数可用性\n");
    printf("      #ifdef HAVE_MKSTEMP\n");
    printf("          // 使用mkstemp\n");
    printf("      #else\n");
    printf("          // 回退方案\n");
    printf("      #endif\n\n");
    
    /*
     * 3.6 完整示例：健壮的文件复制函数
     */
    printf("3.6 完整示例：健壮的文件复制函数\n\n");
    
    printf("   #include <stdio.h>\n");
    printf("   #include <stdlib.h>\n");
    printf("   #include <string.h>\n");
    printf("   #include <errno.h>\n\n");
    
    printf("   // 定义错误码\n");
    printf("   typedef enum {\n");
    printf("       COPY_SUCCESS = 0,\n");
    printf("       COPY_ERROR_OPEN_SOURCE,\n");
    printf("       COPY_ERROR_OPEN_DEST,\n");
    printf("       COPY_ERROR_READ,\n");
    printf("       COPY_ERROR_WRITE,\n");
    printf("       COPY_ERROR_CLOSE,\n");
    printf("       COPY_ERROR_MEMORY\n");
    printf("   } CopyResult;\n\n");
    
    printf("   // 健壮的文件复制函数\n");
    printf("   CopyResult copy_file(const char *src_path, \n");
    printf("                        const char *dest_path,\n");
    printf("                        size_t buffer_size) {\n");
    printf("       FILE *src = NULL;\n");
    printf("       FILE *dest = NULL;\n");
    printf("       char *buffer = NULL;\n");
    printf("       CopyResult result = COPY_SUCCESS;\n\n");
    
    printf("       // 1. 验证参数\n");
    printf("       if (!src_path || !dest_path || buffer_size == 0) {\n");
    printf("           return COPY_ERROR_MEMORY;\n");
    printf("       }\n\n");
    
    printf("       // 2. 分配缓冲区\n");
    printf("       buffer = malloc(buffer_size);\n");
    printf("       if (!buffer) {\n");
    printf("           return COPY_ERROR_MEMORY;\n");
    printf("       }\n\n");
    
    printf("       // 3. 打开源文件\n");
    printf("       src = fopen(src_path, \"rb\");\n");
    printf("       if (!src) {\n");
    printf("           result = COPY_ERROR_OPEN_SOURCE;\n");
    printf("           goto cleanup;\n");
    printf("       }\n\n");
    
    printf("       // 4. 打开目标文件\n");
    printf("       dest = fopen(dest_path, \"wb\");\n");
    printf("       if (!dest) {\n");
    printf("           result = COPY_ERROR_OPEN_DEST;\n");
    printf("           goto cleanup;\n");
    printf("       }\n\n");
    
    printf("       // 5. 复制数据\n");
    printf("       size_t bytes_read;\n");
    printf("       while ((bytes_read = fread(buffer, 1, buffer_size, src)) > 0) {\n");
    printf("           size_t bytes_written = fwrite(buffer, 1, bytes_read, dest);\n");
    printf("           if (bytes_written != bytes_read) {\n");
    printf("               result = COPY_ERROR_WRITE;\n");
    printf("               goto cleanup;\n");
    printf("           }\n");
    printf("       }\n\n");
    
    printf("       // 6. 检查读取错误\n");
    printf("       if (ferror(src)) {\n");
    printf("           result = COPY_ERROR_READ;\n");
    printf("           goto cleanup;\n");
    printf("       }\n\n");
    
    printf("       // 7. 确保数据写入磁盘\n");
    printf("       if (fflush(dest) != 0) {\n");
    printf("           result = COPY_ERROR_WRITE;\n");
    printf("           goto cleanup;\n");
    printf("       }\n\n");
    
    printf("   cleanup:\n");
    printf("       // 8. 清理资源\n");
    printf("       if (src) {\n");
    printf("           if (fclose(src) != 0 && result == COPY_SUCCESS) {\n");
    printf("               result = COPY_ERROR_CLOSE;\n");
    printf("           }\n");
    printf("       }\n");
    printf("       if (dest) {\n");
    printf("           if (fclose(dest) != 0 && result == COPY_SUCCESS) {\n");
    printf("               result = COPY_ERROR_CLOSE;\n");
    printf("           }\n");
    printf("       }\n");
    printf("       free(buffer);\n\n");
    
    printf("       return result;\n");
    printf("   }\n\n");
    
    printf("   这个函数展示了：\n");
    printf("   - 详细的错误处理\n");
    printf("   - 资源清理保证\n");
    printf("   - 合理的缓冲区使用\n");
    printf("   - 明确的错误码\n");
    printf("   - 可配置的缓冲区大小\n");
    printf("\n");
}

/*============================================================================
  文件操作总结
============================================================================*/

void file_io_summary(void) {
    printf("================================================\n");
    printf("第九章：文件操作总结\n");
    printf("================================================\n\n");
    
    printf("   📚 核心知识点总结：\n\n");
    
    printf("   1. 文件基础\n");
    printf("      - 文本文件 vs 二进制文件\n");
    printf("      - 文件指针（FILE*）\n");
    printf("      - 标准文件流：stdin, stdout, stderr\n\n");
    
    printf("   2. 文件操作函数\n");
    printf("      - fopen(), fclose()\n");
    printf("      - fread(), fwrite()\n");
    printf("      - fgets(), fputs(), fprintf(), fscanf()\n");
    printf("      - fgetc(), fputc()\n\n");
    
    printf("   3. 文件位置控制\n");
    printf("      - ftell(), fseek(), rewind()\n");
    printf("      - 随机访问文件\n\n");
    
    printf("   4. 错误处理\n");
    printf("      - errno, perror(), strerror()\n");
    printf("      - feof(), ferror(), clearerr()\n\n");
    
    printf("   5. 高级文件操作\n");
    printf("      - 文件管理：remove(), rename()\n");
    printf("      - 临时文件：tmpfile(), tmpnam()\n");
    printf("      - 缓冲控制：setvbuf(), fflush()\n\n");
    
    printf("   6. 目录操作（POSIX）\n");
    printf("      - opendir(), readdir(), closedir()\n");
    printf("      - mkdir(), rmdir()\n");
    printf("      - 目录遍历\n\n");
    
    printf("   7. 实际应用\n");
    printf("      - 配置文件处理\n");
    printf("      - 日志系统\n");
    printf("      - 文件加密\n");
    printf("      - 数据备份\n\n");
    
    printf("   8. 性能优化\n");
    printf("      - 批量读写\n");
    printf("      - 合适的缓冲区大小\n");
    printf("      - 内存映射文件\n\n");
    
    printf("   💡 学习建议：\n");
    printf("   1. 从简单文本文件开始练习\n");
    printf("   2. 掌握错误处理模式\n");
    printf("   3. 理解缓冲机制\n");
    printf("   4. 实践结构化数据存储\n");
    printf("   5. 学习调试文件I/O问题\n\n");
    
    printf("   🛠️ 实践项目建议：\n");
    printf("   1. 实现一个简单的文本编辑器\n");
    printf("   2. 编写日志分析工具\n");
    printf("   3. 创建配置文件管理器\n");
    printf("   4. 实现文件加密工具\n");
    printf("   5. 编写目录同步工具\n\n");
    
    printf("   ⚠️ 常见错误：\n");
    printf("   1. 忘记检查文件操作返回值\n");
    printf("   2. 未正确关闭文件\n");
    printf("   3. 缓冲区溢出\n");
    printf("   4. 忽略错误处理\n");
    printf("   5. 未考虑大文件支持\n\n");
    
    printf("   🎯 高级主题延伸：\n");
    printf("   1. 异步I/O（aio.h）\n");
    printf("   2. 内存映射文件（mmap）\n");
    printf("   3. 文件锁（fcntl.h）\n");
    printf("   4. 文件系统监控（inotify）\n");
    printf("   5. 网络文件系统\n\n");
    
    printf("================================================\n");
    printf("恭喜完成第九章：文件操作的学习！\n");
    printf("文件I/O是C语言编程的重要技能，\n");
    printf("掌握它将让你能处理各种数据持久化需求。\n");
    printf("================================================\n");
}
