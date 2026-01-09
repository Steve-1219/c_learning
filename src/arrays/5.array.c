#include <stdio.h>
#include <string.h>     // 字符串处理函数
#include <stdlib.h>     // 动态内存函数
#include <time.h>       // 随机数函数

/*================================================================
  第一部分：数组概述
  说明：数组是C语言中最基本的数据结构之一
================================================================*/

void part1_array_overview(void) {
    printf("\n");
    printf("================================================\n");
    printf("第一部分：数组概述\n");
    printf("================================================\n\n");
    
    printf("数组（Array）的定义：\n");
    printf("数组是相同类型数据的有限序列，存储在连续的内存单元中\n\n");
    
    printf("数组的特点：\n");
    printf("1. 相同类型：数组中的所有元素必须是同一数据类型\n");
    printf("2. 有限长度：数组有固定的大小，在声明时确定\n");
    printf("3. 连续存储：数组元素在内存中按顺序连续存放\n");
    printf("4. 随机访问：通过下标可以直接访问任意元素\n\n");
    
    printf("数组的组成：\n");
    printf("数组名：标识整个数组\n");
    printf("元素：数组中的每个数据项\n");
    printf("下标：元素的位置索引，从0开始\n");
    printf("长度：数组能容纳的元素个数\n\n");
    
    printf("数组的用途：\n");
    printf("- 存储一组相关数据（如学生成绩、温度记录）\n");
    printf("- 实现向量、矩阵等数学概念\n");
    printf("- 作为字符串的存储方式\n");
    printf("- 作为其他数据结构（如栈、队列）的基础\n\n");
    
    printf("数组的分类：\n");
    printf("1. 一维数组：线性的数据序列\n");
    printf("2. 多维数组：多个维度的数据，如二维数组（矩阵）\n");
    printf("3. 字符数组：用于存储字符串\n\n");
}

/*================================================================
  第二部分：一维数组详解
  说明：一维数组是最基本的数组形式
================================================================*/

void part2_one_dimensional_arrays(void) {
    printf("\n");
    printf("================================================\n");
    printf("第二部分：一维数组详解\n");
    printf("================================================\n\n");
    
    /*
     * 1. 一维数组的声明和初始化
     */
    printf("1. 一维数组的声明和初始化\n\n");
    
    printf("   语法：数据类型 数组名[数组长度];\n\n");
    
    printf("   示例1：声明一个整型数组\n");
    int numbers[5];  // 声明一个包含5个整数的数组
    printf("   int numbers[5];  // 声明了5个整数的数组\n\n");
    
    printf("   数组初始化的几种方式：\n");
    
    printf("   方式1：声明时全部初始化\n");
    int arr1[5] = {1, 2, 3, 4, 5};  // 完全初始化
    printf("   int arr1[5] = {1, 2, 3, 4, 5};\n");
    printf("   结果：arr1[0]=%d, arr1[4]=%d\n\n", arr1[0], arr1[4]);
    
    printf("   方式2：声明时部分初始化\n");
    int arr2[5] = {1, 2, 3};  // 部分初始化，剩余元素自动为0
    printf("   int arr2[5] = {1, 2, 3};  // 后两个元素自动为0\n");
    printf("   结果：arr2[3]=%d, arr2[4]=%d\n\n", arr2[3], arr2[4]);
    
    printf("   方式3：自动确定数组大小\n");
    int arr3[] = {1, 2, 3, 4, 5};  // 编译器自动计算长度为5
    printf("   int arr3[] = {1, 2, 3, 4, 5};  // 自动确定长度为5\n");
    printf("   数组大小：%zu个元素\n\n", sizeof(arr3) / sizeof(arr3[0]));
    
    printf("   方式4：清零初始化\n");
    int arr4[5] = {0};  // 所有元素初始化为0
    printf("   int arr4[5] = {0};  // 所有元素为0\n");
    printf("   验证：arr4[2] = %d\n\n", arr4[2]);
    
    /*
     * 2. 数组元素的访问
     */
    printf("2. 数组元素的访问\n\n");
    
    printf("   语法：数组名[下标]\n");
    printf("   注意：下标从0开始，到数组长度-1结束\n\n");
    
    int scores[5] = {85, 92, 78, 90, 88};
    
    printf("   示例：访问数组元素\n");
    printf("   int scores[5] = {85, 92, 78, 90, 88};\n\n");
    
    printf("   访问单个元素：\n");
    printf("   scores[0] = %d  // 第一个元素\n", scores[0]);
    printf("   scores[2] = %d  // 第三个元素\n", scores[2]);
    printf("   scores[4] = %d  // 最后一个元素\n\n", scores[4]);
    
    printf("   修改数组元素：\n");
    scores[1] = 95;  // 修改第二个元素
    printf("   scores[1] = 95;  // 修改后：scores[1] = %d\n\n", scores[1]);
    
    printf("   注意：数组下标越界是常见错误！\n");
    printf("   scores[5] = 100;  // 错误！下标越界\n");
    printf("   有效下标：0到4，共5个元素\n\n");
    
    /*
     * 3. 数组的遍历
     */
    printf("3. 数组的遍历（循环访问所有元素）\n\n");
    
    int data[6] = {10, 20, 30, 40, 50, 60};
    int size = sizeof(data) / sizeof(data[0]);  // 计算数组大小
    
    printf("   示例：遍历数组的所有元素\n");
    printf("   int data[6] = {10, 20, 30, 40, 50, 60};\n");
    printf("   数组大小：%d\n\n", size);
    
    printf("   方法1：for循环遍历\n");
    printf("   for (int i = 0; i < size; i++) {\n");
    printf("       printf(\"data[%%d] = %%d\\\\n\", i, data[i]);\n");
    printf("   }\n");
    printf("   输出：\n");
    
    for (int i = 0; i < size; i++) {
        printf("   data[%d] = %d\n", i, data[i]);
    }
    printf("\n");
    
    printf("   方法2：while循环遍历\n");
    printf("   int i = 0;\n");
    printf("   while (i < size) {\n");
    printf("       printf(\"%%d \", data[i]);\n");
    printf("       i++;\n");
    printf("   }\n");
    printf("   输出：");
    
    int i = 0;
    while (i < size) {
        printf("%d ", data[i]);
        i++;
    }
    printf("\n\n");
    
    printf("   方法3：计算数组元素个数\n");
    printf("   sizeof运算符使用技巧：\n");
    printf("   数组总大小：sizeof(data) = %zu 字节\n", sizeof(data));
    printf("   单个元素大小：sizeof(data[0]) = %zu 字节\n", sizeof(data[0]));
    printf("   元素个数 = 总大小 / 单个元素大小 = %zu\n\n", 
           sizeof(data) / sizeof(data[0]));
    
    /*
     * 4. 一维数组的应用示例
     */
    printf("4. 一维数组的应用示例\n\n");
    
    printf("   示例1：计算数组平均值\n");
    float values[5] = {12.5, 18.3, 15.7, 20.1, 16.8};
    float sum = 0;
    
    for (int j = 0; j < 5; j++) {
        sum += values[j];
    }
    
    float average = sum / 5;
    printf("   数据：");
    for (int j = 0; j < 5; j++) {
        printf("%.1f ", values[j]);
    }
    printf("\n   平均值：%.2f\n\n", average);
    
    printf("   示例2：查找数组中的最大值和最小值\n");
    int nums[8] = {23, 45, 12, 67, 34, 89, 56, 21};
    int max = nums[0];
    int min = nums[0];
    
    for (int j = 1; j < 8; j++) {
        if (nums[j] > max) {
            max = nums[j];
        }
        if (nums[j] < min) {
            min = nums[j];
        }
    }
    
    printf("   数组：");
    for (int j = 0; j < 8; j++) {
        printf("%d ", nums[j]);
    }
    printf("\n   最大值：%d\n", max);
    printf("   最小值：%d\n\n", min);
    
    printf("   示例3：数组元素反转\n");
    int original[6] = {1, 2, 3, 4, 5, 6};
    int reversed[6];
    
    printf("   原数组：");
    for (int j = 0; j < 6; j++) {
        printf("%d ", original[j]);
    }
    
    // 反转操作
    for (int j = 0; j < 6; j++) {
        reversed[j] = original[5 - j];
    }
    
    printf("\n   反转后：");
    for (int j = 0; j < 6; j++) {
        printf("%d ", reversed[j]);
    }
    printf("\n\n");
    
    printf("   示例4：数组排序（冒泡排序）\n");
    int unsorted[7] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    
    printf("   排序前：");
    for (int j = 0; j < n; j++) {
        printf("%d ", unsorted[j]);
    }
    
    // 冒泡排序
    for (int j = 0; j < n - 1; j++) {
        for (int k = 0; k < n - j - 1; k++) {
            if (unsorted[k] > unsorted[k + 1]) {
                // 交换
                int temp = unsorted[k];
                unsorted[k] = unsorted[k + 1];
                unsorted[k + 1] = temp;
            }
        }
    }
    
    printf("\n   排序后：");
    for (int j = 0; j < n; j++) {
        printf("%d ", unsorted[j]);
    }
    printf("\n\n");
    
    /*
     * 5. 数组的内存布局
     */
    printf("5. 数组在内存中的布局\n\n");
    
    printf("   内存地址示例：\n");
    int memory_arr[3] = {100, 200, 300};
    
    printf("   int memory_arr[3] = {100, 200, 300};\n");
    printf("   元素   值    内存地址（示例）\n");
    printf("   -----------------------------\n");
    
    // 实际打印内存地址
    for (int j = 0; j < 3; j++) {
        printf("   arr[%d]   %d      %p\n", 
               j, memory_arr[j], (void*)&memory_arr[j]);
    }
    
    printf("\n   重要观察：\n");
    printf("   1. 相邻元素地址相差4字节（int类型大小）\n");
    printf("   2. 数组元素连续存储\n");
    printf("   3. 数组名是首元素地址：arr = %p\n", (void*)memory_arr);
    printf("   4. &arr[0] = %p（与arr相同）\n\n", (void*)&memory_arr[0]);
    
    /*
     * 6. 一维数组的注意事项
     */
    printf("6. 一维数组的注意事项\n\n");
    
    printf("   注意1：数组下标从0开始\n");
    printf("   有效下标范围：0 到 数组长度-1\n");
    printf("   访问arr[长度]是越界访问，结果不可预测\n\n");
    
    printf("   注意2：数组长度必须是常量\n");
    printf("   int n = 10;\n");
    printf("   int arr[n];  // C99之前不允许，C99允许（变长数组）\n");
    printf("   传统C要求数组长度是编译时常量\n\n");
    
    printf("   注意3：数组不能整体赋值\n");
    printf("   int a[3] = {1, 2, 3};\n");
    printf("   int b[3];\n");
    printf("   b = a;  // 错误！不能数组整体赋值\n");
    printf("   必须逐个元素复制\n\n");
    
    printf("   注意4：数组作为函数参数传递\n");
    printf("   数组作为参数时，传递的是首地址，不是整个数组\n");
    printf("   函数内无法直接获取数组长度\n\n");
}

/*================================================================
  第三部分：二维数组详解
  说明：二维数组用于表示表格、矩阵等结构
================================================================*/

void part3_two_dimensional_arrays(void) {
    printf("\n");
    printf("================================================\n");
    printf("第三部分：二维数组详解\n");
    printf("================================================\n\n");
    
    /*
     * 1. 二维数组的基本概念
     */
    printf("1. 二维数组的基本概念\n\n");
    
    printf("   二维数组可以看作是一个表格或矩阵：\n");
    printf("   - 行（rows）：水平方向\n");
    printf("   - 列（columns）：垂直方向\n");
    printf("   - 元素：matrix[行][列]\n\n");
    
    printf("   声明语法：数据类型 数组名[行数][列数];\n");
    printf("   示例：int matrix[3][4];  // 3行4列的整型矩阵\n\n");
    
    /*
     * 2. 二维数组的初始化和访问
     */
    printf("2. 二维数组的初始化和访问\n\n");
    
    printf("   初始化方法1：按行分组初始化\n");
    int matrix1[3][4] = {
        {1, 2, 3, 4},     // 第0行
        {5, 6, 7, 8},     // 第1行
        {9, 10, 11, 12}   // 第2行
    };
    
    printf("   int matrix1[3][4] = {\n");
    printf("       {1, 2, 3, 4},\n");
    printf("       {5, 6, 7, 8},\n");
    printf("       {9, 10, 11, 12}\n");
    printf("   };\n\n");
    
    printf("   初始化方法2：连续初始化\n");
    int matrix2[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    printf("   效果与按行分组相同\n\n");
    
    printf("   初始化方法3：部分初始化\n");
    int matrix3[3][4] = {
        {1, 2},          // 第0行：前两列有值，后两列为0
        {5, 6, 7},       // 第1行：前三列有值，最后一列为0
        {9}              // 第2行：只有第一列有值
    };
    printf("   未指定的元素自动初始化为0\n\n");
    
    printf("   访问二维数组元素：\n");
    printf("   语法：数组名[行下标][列下标]\n");
    printf("   示例：matrix1[1][2] = %d（第1行第2列）\n\n", matrix1[1][2]);
    
    /*
     * 3. 二维数组的遍历
     */
    printf("3. 二维数组的遍历\n\n");
    
    printf("   示例：遍历3×4矩阵\n");
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    printf("   矩阵内容：\n");
    for (int row = 0; row < 3; row++) {
        printf("   行%d: ", row);
        for (int col = 0; col < 4; col++) {
            printf("%3d ", matrix[row][col]);
        }
        printf("\n");
    }
    printf("\n");
    
    /*
     * 4. 二维数组的应用示例
     */
    printf("4. 二维数组的应用示例\n\n");
    
    printf("   示例1：计算矩阵转置\n");
    int original[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    int transpose[3][2];
    
    printf("   原矩阵（2×3）：\n");
    for (int i = 0; i < 2; i++) {
        printf("   ");
        for (int j = 0; j < 3; j++) {
            printf("%d ", original[i][j]);
        }
        printf("\n");
    }
    
    // 计算转置
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            transpose[j][i] = original[i][j];
        }
    }
    
    printf("   转置矩阵（3×2）：\n");
    for (int i = 0; i < 3; i++) {
        printf("   ");
        for (int j = 0; j < 2; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    printf("   示例2：矩阵加法\n");
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int C[2][2];
    
    printf("   矩阵A：\n");
    printf("   %d %d\n", A[0][0], A[0][1]);
    printf("   %d %d\n\n", A[1][0], A[1][1]);
    
    printf("   矩阵B：\n");
    printf("   %d %d\n", B[0][0], B[0][1]);
    printf("   %d %d\n\n", B[1][0], B[1][1]);
    
    // 矩阵相加
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    
    printf("   矩阵C = A + B：\n");
    printf("   %d %d\n", C[0][0], C[0][1]);
    printf("   %d %d\n\n", C[1][0], C[1][1]);
    
    printf("   示例3：学生成绩管理系统\n");
    // 3个学生，4门课程
    int scores[3][4] = {
        {85, 92, 78, 90},  // 学生1的成绩
        {76, 88, 95, 82},  // 学生2的成绩
        {90, 85, 88, 92}   // 学生3的成绩
    };
    
    char *subjects[4] = {"数学", "语文", "英语", "物理"};
    
    printf("   学生成绩表：\n");
    printf("   学生\\课程");
    for (int i = 0; i < 4; i++) {
        printf("   %s", subjects[i]);
    }
    printf("   平均分\n");
    
    for (int stu = 0; stu < 3; stu++) {
        int total = 0;
        printf("   学生%d", stu + 1);
        
        for (int sub = 0; sub < 4; sub++) {
            printf("      %3d", scores[stu][sub]);
            total += scores[stu][sub];
        }
        
        float avg = total / 4.0;
        printf("     %.1f\n", avg);
    }
    printf("\n");
    
    /*
     * 5. 二维数组的内存布局
     */
    printf("5. 二维数组在内存中的布局\n\n");
    
    printf("   重要事实：内存是一维的！\n");
    printf("   二维数组在内存中按行优先顺序存储\n\n");
    
    int demo[2][3] = {{1, 2, 3}, {4, 5, 6}};
    
    printf("   int demo[2][3] = {{1,2,3}, {4,5,6}};\n");
    printf("   内存中的存储顺序：\n");
    
    printf("   地址顺序      值      对应位置\n");
    printf("   ----------------------------------\n");
    
    // 按内存顺序访问
    int *ptr = (int *)demo;  // 指向数组首地址
    for (int k = 0; k < 6; k++) {
        int row = k / 3;      // 计算行
        int col = k % 3;      // 计算列
        printf("   demo[%d][%d]   %d     内存位置%d\n", 
               row, col, *(ptr + k), k);
    }
    
    printf("\n   按行优先存储：\n");
    printf("   第0行：demo[0][0], demo[0][1], demo[0][2]\n");
    printf("   第1行：demo[1][0], demo[1][1], demo[1][2]\n\n");
    
    printf("   验证：demo[0][3] = %d（实际是demo[1][0]）\n", demo[0][3]);
    printf("   注意：这属于越界访问，虽然可能不报错，但是错误的！\n\n");
}

/*================================================================
  第四部分：字符数组和字符串
  说明：C语言中字符串用字符数组表示
================================================================*/

void part4_character_arrays_and_strings(void) {
    printf("\n");
    printf("================================================\n");
    printf("第四部分：字符数组和字符串\n");
    printf("================================================\n\n");
    
    /*
     * 1. 字符数组基础
     */
    printf("1. 字符数组基础\n\n");
    
    printf("   字符数组：用于存储字符序列的数组\n\n");
    
    printf("   示例1：字符数组声明和初始化\n");
    char str1[10] = {'H', 'e', 'l', 'l', 'o', '!', '\0'};
    char str2[10] = "Hello!";  // 字符串字面量会自动添加'\0'
    char str3[] = "Hello!";    // 自动确定大小（包括'\0'）
    
    printf("   方式1：逐个字符初始化\n");
    printf("   char str1[10] = {'H','e','l','l','o','!','\\0'};\n");
    printf("   内容：%s\n\n", str1);
    
    printf("   方式2：字符串字面量初始化\n");
    printf("   char str2[10] = \"Hello!\";\n");
    printf("   内容：%s\n\n", str2);
    
    printf("   方式3：自动大小\n");
    printf("   char str3[] = \"Hello!\";\n");
    printf("   大小：%zu字节（包含'\\0'）\n\n", sizeof(str3));
    
    printf("   重要概念：空字符'\\0'\n");
    printf("   - ASCII码值为0\n");
    printf("   - 表示字符串结束\n");
    printf("   - 字符串处理函数依赖它\n\n");
    
    /*
     * 2. 字符串的输入输出
     */
    printf("2. 字符串的输入输出\n\n");
    
    printf("   示例1：使用printf输出字符串\n");
    char greeting[] = "Welcome to C Programming!";
    printf("   char greeting[] = \"%s\";\n", greeting);
    printf("   printf输出: %s\n\n", greeting);
    
    printf("   示例2：使用puts输出字符串\n");
    char message[] = "Hello, World!";
    printf("   puts(\"%s\"); 输出：\n", message);
    puts(message);  // 自动换行
    printf("\n");
    
    printf("   示例3：使用scanf输入字符串（不安全）\n");
    char name[20];
    // 模拟输入：实际编程中不要这样用，容易缓冲区溢出
    printf("   scanf不安全示例：\n");
    printf("   scanf(\"%%s\", name);  // 可能溢出！\n");
    printf("   应该使用：scanf(\"%%19s\", name);  // 限制长度\n\n");
    
    printf("   示例4：使用fgets安全输入\n");
    printf("   fgets(name, sizeof(name), stdin);  // 安全\n");
    printf("   会读取换行符，可以处理空格\n\n");
    
    /*
     * 3. 标准字符串处理函数
     */
    printf("3. 标准字符串处理函数（需要#include <string.h>）\n\n");
    
    char strA[20] = "Hello";
    char strB[20] = "World";
    char strC[50];
    
    printf("   函数1：strlen - 字符串长度（不包括'\\0'）\n");
    printf("   strlen(\"%s\") = %zu\n", strA, strlen(strA));
    printf("   strlen(\"%s\") = %zu\n\n", strB, strlen(strB));
    
    printf("   函数2：strcpy - 字符串复制\n");
    strcpy(strC, strA);
    printf("   strcpy(strC, strA);\n");
    printf("   strC = \"%s\"\n\n", strC);
    
    printf("   函数3：strcat - 字符串连接\n");
    strcat(strC, " ");
    strcat(strC, strB);
    printf("   strcat(strC, \" \"); strcat(strC, strB);\n");
    printf("   strC = \"%s\"\n\n", strC);
    
    printf("   函数4：strcmp - 字符串比较\n");
    printf("   strcmp(\"%s\", \"%s\") = %d\n", strA, "Hello", strcmp(strA, "Hello"));
    printf("   strcmp(\"%s\", \"%s\") = %d\n", strA, strB, strcmp(strA, strB));
    printf("   strcmp(\"%s\", \"%s\") = %d\n", strB, strA, strcmp(strB, strA));
    printf("   返回0表示相等，负数表示str1<str2，正数表示str1>str2\n\n");
    
    printf("   函数5：strchr - 查找字符\n");
    char *pos = strchr(strC, 'W');
    if (pos != NULL) {
        printf("   strchr(\"%s\", 'W') 找到，位置：%td\n", strC, pos - strC);
    }
    printf("\n");
    
    printf("   函数6：strstr - 查找子串\n");
    char *sub = strstr(strC, "World");
    if (sub != NULL) {
        printf("   strstr(\"%s\", \"World\") 找到，位置：%td\n", strC, sub - strC);
    }
    printf("\n");
    
    /*
     * 4. 字符串应用示例
     */
    printf("4. 字符串应用示例\n\n");
    
    printf("   示例1：统计字符串中字符出现次数\n");
    char text[] = "programming is interesting";
    char target = 'i';
    int count = 0;
    
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == target) {
            count++;
        }
    }
    
    printf("   字符串：\"%s\"\n", text);
    printf("   字符'%c'出现了%d次\n\n", target, count);
    
    printf("   示例2：字符串反转\n");
    char original[] = "ABCDE";
    char reversed[100];
    int len = strlen(original);
    
    for (int i = 0; i < len; i++) {
        reversed[i] = original[len - 1 - i];
    }
    reversed[len] = '\0';
    
    printf("   原字符串：%s\n", original);
    printf("   反转后：%s\n\n", reversed);
    
    printf("   示例3：判断回文字符串\n");
    char palindrome[] = "racecar";
    int is_palindrome = 1;  // 假设是回文
    int length = strlen(palindrome);
    
    for (int i = 0; i < length / 2; i++) {
        if (palindrome[i] != palindrome[length - 1 - i]) {
            is_palindrome = 0;
            break;
        }
    }
    
    printf("   字符串：\"%s\"\n", palindrome);
    printf("   判断结果：%s\n\n", 
           is_palindrome ? "是回文字符串" : "不是回文字符串");
    
    printf("   示例4：字符串分割\n");
    char sentence[] = "C,Java,Python,JavaScript";
    char *token;
    
    printf("   原字符串：%s\n", sentence);
    printf("   分割结果：\n");
    
    token = strtok(sentence, ",");
    int token_count = 1;
    
    while (token != NULL) {
        printf("   第%d部分：%s\n", token_count, token);
        token = strtok(NULL, ",");
        token_count++;
    }
    printf("\n");
    
    /*
     * 5. 字符串操作的安全问题
     */
    printf("5. 字符串操作的安全问题\n\n");
    
    printf("   问题1：缓冲区溢出（Buffer Overflow）\n");
    printf("   不安全的代码：\n");
    printf("   char buffer[10];\n");
    printf("   scanf(\"%%s\", buffer);  // 输入超过9个字符就会溢出\n\n");
    
    printf("   安全解决方案：\n");
    printf("   1. 使用长度限制：scanf(\"%%9s\", buffer);\n");
    printf("   2. 使用fgets：fgets(buffer, sizeof(buffer), stdin);\n");
    printf("   3. 使用strncpy代替strcpy\n\n");
    
    printf("   问题2：字符串未以'\\0'结尾\n");
    printf("   char str[5] = {'H','e','l','l','o'};  // 缺少'\\0'！\n");
    printf("   printf(\"%%s\", str);  // 可能打印垃圾数据\n\n");
    
    printf("   解决方案：\n");
    printf("   1. 确保字符串以'\\0'结尾\n");
    printf("   2. 使用安全的字符串函数\n");
    printf("   3. 初始化时预留空间给'\\0'\n\n");
}

/*================================================================
  第五部分：数组作为函数参数
  说明：如何将数组传递给函数
================================================================*/

void part5_arrays_as_function_parameters(void) {
    printf("\n");
    printf("================================================\n");
    printf("第五部分：数组作为函数参数\n");
    printf("================================================\n\n");
    
    /*
     * 1. 一维数组作为函数参数
     */
    printf("1. 一维数组作为函数参数\n\n");
    
    printf("   重要事实：数组作为参数时传递的是地址，不是整个数组\n");
    printf("   函数内对数组的修改会影响原数组\n\n");
    
    printf("   示例：函数参数传递方式\n\n");
    
    // 函数声明
    void print_array(int arr[], int size);
    void modify_array(int arr[], int size);
    int find_max(int arr[], int size);
    
    int numbers[5] = {10, 20, 30, 40, 50};
    
    printf("   原数组：");
    print_array(numbers, 5);
    
    printf("   修改数组后：");
    modify_array(numbers, 5);
    print_array(numbers, 5);
    
    int max_value = find_max(numbers, 5);
    printf("   数组最大值：%d\n\n", max_value);
    
    printf("   函数参数的不同写法：\n");
    printf("   1. 数组写法：void func(int arr[], int size)\n");
    printf("   2. 指针写法：void func(int *arr, int size)  // 等价\n");
    printf("   两种写法在函数内部是等价的\n\n");
    
    /*
     * 2. 二维数组作为函数参数
     */
    printf("2. 二维数组作为函数参数\n\n");
    
    printf("   二维数组作为参数必须指定列数：\n");
    printf("   void func(int arr[][4], int rows)  // 正确\n");
    printf("   void func(int arr[3][4])           // 正确\n");
    printf("   void func(int arr[][], int rows)   // 错误！\n\n");
    
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    printf("   二维数组示例：\n");
    
    // 函数声明
    void print_matrix(int mat[][4], int rows);
    int sum_matrix(int mat[][4], int rows);
    
    printf("   矩阵内容：\n");
    print_matrix(matrix, 3);
    
    int total = sum_matrix(matrix, 3);
    printf("   矩阵所有元素和：%d\n\n", total);
    
    /*
     * 3. 数组参数的注意事项
     */
    printf("3. 数组参数的注意事项\n\n");
    
    printf("   注意1：函数内无法直接获取数组大小\n");
    printf("   必须额外传递大小参数\n\n");
    
    printf("   注意2：数组参数退化为指针\n");
    printf("   void func(int arr[]) 中的arr是指针，不是数组\n");
    printf("   sizeof(arr) 返回指针大小，不是数组大小\n\n");
    
    printf("   注意3：函数可以修改原数组\n");
    printf("   因为传递的是地址，不是副本\n");
    printf("   如果不希望修改，可以传递const数组\n");
    printf("   void func(const int arr[], int size)\n\n");
    
    printf("   注意4：动态多维数组传递\n");
    printf("   对于动态创建的多维数组，需要更复杂的参数传递\n");
    printf("   通常使用指针的指针（int **）\n\n");
}

// 第五部分中使用的函数定义
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void modify_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;  // 所有元素乘以2
    }
}

int find_max(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void print_matrix(int mat[][4], int rows) {
    for (int i = 0; i < rows; i++) {
        printf("   ");
        for (int j = 0; j < 4; j++) {
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }
}

int sum_matrix(int mat[][4], int rows) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 4; j++) {
            sum += mat[i][j];
        }
    }
    return sum;
}

/*================================================================
  第六部分：数组编程技巧
  说明：数组使用的技巧和最佳实践
================================================================*/

void part6_array_programming_tips(void) {
    printf("\n");
    printf("================================================\n");
    printf("第六部分：数组编程技巧\n");
    printf("================================================\n\n");
    
    printf("1. 数组初始化技巧\n");
    printf("   - 使用{0}清零数组\n");
    printf("   - 使用指定初始化器（C99）：int arr[10] = {[3]=10, [7]=20}\n");
    printf("   - 对于大数组，考虑动态初始化\n\n");
    
    printf("2. 数组遍历技巧\n");
    printf("   - 使用sizeof计算数组大小\n");
    printf("   - 使用范围for循环（C99以后）\n");
    printf("   - 倒序遍历：for(i=n-1; i>=0; i--)\n\n");
    
    printf("3. 数组边界检查\n");
    printf("   - 始终检查数组下标是否越界\n");
    printf("   - 使用assert断言检查\n");
    printf("   - 在循环中使用正确的边界条件\n\n");
    
    printf("4. 数组作为函数参数\n");
    printf("   - 同时传递数组和大小\n");
    printf("   - 使用const防止意外修改\n");
    printf("   - 考虑返回数组的函数设计\n\n");
    
    printf("5. 多维数组处理\n");
    printf("   - 理解行优先存储\n");
    printf("   - 使用嵌套循环时注意效率\n");
    printf("   - 考虑使用一维数组模拟多维数组\n\n");
    
    printf("6. 字符串处理安全\n");
    printf("   - 使用安全的字符串函数（strncpy, snprintf）\n");
    printf("   - 确保字符串以'\\0'结尾\n");
    printf("   - 检查缓冲区大小\n\n");
    
    printf("7. 性能优化\n");
    printf("   - 减少数组访问次数\n");
    printf("   - 考虑局部性原理\n");
    printf("   - 避免不必要的数组复制\n\n");
    
    printf("8. 调试技巧\n");
    printf("   - 打印数组内容调试\n");
    printf("   - 使用调试器查看数组内存\n");
    printf("   - 检查数组初始化\n\n");
}
