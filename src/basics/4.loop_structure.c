#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>     // system函数
#include <time.h>       // 时间函数

/*================================================================
  第一部分：循环结构概述
  说明：循环结构用于重复执行代码块
================================================================*/

void part1_overview(void) {
    printf("\n");
    printf("================================================\n");
    printf("第一部分：循环结构概述\n");
    printf("================================================\n\n");
    
    printf("循环结构（Loop Structure）\n");
    printf("作用：根据条件重复执行特定的代码块\n\n");
    
    printf("C语言中的循环结构语句：\n");
    printf("1. while循环      - 先判断条件，再执行循环体\n");
    printf("2. do-while循环  - 先执行循环体，再判断条件\n");
    printf("3. for循环       - 最常用的循环，结构清晰\n");
    printf("4. 嵌套循环      - 循环内部包含另一个循环\n\n");
    
    printf("循环控制语句：\n");
    printf("1. break语句     - 立即退出整个循环\n");
    printf("2. continue语句  - 跳过本次循环的剩余部分\n");
    printf("3. goto语句      - 跳转到指定标签（一般不推荐使用）\n\n");
    
    printf("循环的应用场景：\n");
    printf("- 遍历数组或集合\n");
    printf("- 重复计算\n");
    printf("- 等待用户输入\n");
    printf("- 游戏循环\n");
    printf("- 文件处理\n");
    printf("- 数据处理\n\n");
    
    printf("循环的三要素：\n");
    printf("1. 循环变量初始化\n");
    printf("2. 循环条件（何时继续循环）\n");
    printf("3. 循环变量更新（确保循环能结束）\n\n");
}

/*================================================================
  第二部分：while循环详解
  说明：while循环是最基本的循环结构
================================================================*/

void part2_while_loop(void) {
    printf("\n");
    printf("================================================\n");
    printf("第二部分：while循环详解\n");
    printf("================================================\n\n");
    
    /*
     * 1. while循环基本语法
     */
    printf("1. while循环基本语法\n");
    printf("   语法：while (条件) { 循环体; }\n");
    printf("   执行流程：\n");
    printf("   1. 检查条件是否为真（非零）\n");
    printf("   2. 如果为真，执行循环体\n");
    printf("   3. 再次检查条件，重复步骤1-2\n");
    printf("   4. 条件为假时，退出循环\n\n");
    
    /*
     * 2. while循环基本示例
     */
    printf("2. while循环基本示例\n\n");
    
    printf("   示例1：打印1到5的数字\n");
    int i = 1;                  // 1. 循环变量初始化
    while (i <= 5) {           // 2. 循环条件
        printf("   %d ", i);
        i++;                    // 3. 循环变量更新
    }
    printf("\n\n");
    
    printf("   示例2：计算1到100的和\n");
    int sum = 0;
    int num = 1;
    
    while (num <= 100) {
        sum += num;            // 累加
        num++;                 // 更新循环变量
    }
    printf("   1到100的和 = %d\n\n", sum);
    
    printf("   示例3：用户输入验证\n");
    printf("   模拟：要求用户输入1-10之间的数字\n");
    
    int input = 15;            // 模拟用户输入错误值
    int attempt_count = 0;
    
    while (input < 1 || input > 10) {
        if (attempt_count > 0) {
            printf("   输入错误！请重新输入1-10之间的数字。\n");
        }
        // 模拟用户重新输入
        input = 3;             // 第二次输入正确值
        attempt_count++;
    }
    printf("   输入正确！您输入了：%d\n\n", input);
    
    /*
     * 3. while循环的变体：无限循环
     */
    printf("3. while循环的变体：无限循环\n");
    printf("   语法：while (1) 或 while (true)\n");
    printf("   用途：需要一直运行直到显式退出的情况\n");
    printf("   注意：必须有break语句退出，否则会永远循环\n\n");
    
    printf("   示例：简单的菜单系统\n");
    int choice = 0;
    int loop_count = 0;
    
    while (1) {                // 无限循环
        loop_count++;
        
        if (loop_count > 3) {  // 模拟用户选择退出
            printf("   用户选择退出程序\n");
            break;             // 退出循环
        }
        
        // 模拟菜单显示
        printf("   第%d次循环：模拟菜单选项\n", loop_count);
        
        // 这里应该有用户输入，我们模拟一个选择
        if (loop_count == 1) {
            printf("   选择：继续执行\n");
        }
    }
    printf("\n");
    
    /*
     * 4. while循环的注意事项
     */
    printf("4. while循环的注意事项\n\n");
    
    printf("   注意1：避免死循环\n");
    printf("   死循环是循环条件永远为真的情况\n");
    printf("   原因：忘记更新循环变量或条件永远满足\n\n");
    
    printf("   错误的例子（死循环）：\n");
    printf("   int i = 0;\n");
    printf("   while (i < 5) {\n");
    printf("       printf(\"%%d \", i);\n");
    printf("       // 忘记 i++，i永远小于5\n");
    printf("   }\n\n");
    
    printf("   注意2：循环条件的边界\n");
    printf("   确保循环条件的正确性\n");
    printf("   例如：while (i <= 5) 和 while (i < 5) 的区别\n\n");
    
    printf("   注意3：循环变量的初始化\n");
    printf("   循环变量必须在循环前正确初始化\n");
    printf("   否则可能导致不可预测的结果\n\n");
    
    printf("   注意4：循环体内的变量作用域\n");
    printf("   在循环体内定义的变量只在当前迭代有效\n");
    printf("   每次循环都会重新创建和销毁\n\n");
}

/*================================================================
  第三部分：do-while循环详解
  说明：do-while循环先执行后判断
================================================================*/

void part3_do_while_loop(void) {
    printf("\n");
    printf("================================================\n");
    printf("第三部分：do-while循环详解\n");
    printf("================================================\n\n");
    
    /*
     * 1. do-while循环基本语法
     */
    printf("1. do-while循环基本语法\n");
    printf("   语法：do { 循环体; } while (条件);\n");
    printf("   执行流程：\n");
    printf("   1. 先执行循环体一次\n");
    printf("   2. 检查条件是否为真\n");
    printf("   3. 如果为真，重复执行循环体\n");
    printf("   4. 条件为假时，退出循环\n\n");
    
    printf("   while与do-while的区别：\n");
    printf("   - while：先判断条件，可能一次都不执行\n");
    printf("   - do-while：先执行一次，再判断条件\n");
    printf("   - do-while至少执行一次循环体\n\n");
    
    /*
     * 2. do-while循环基本示例
     */
    printf("2. do-while循环基本示例\n\n");
    
    printf("   示例1：打印1到5的数字\n");
    int i = 1;
    do {
        printf("   %d ", i);
        i++;
    } while (i <= 5);
    printf("\n\n");
    
    printf("   示例2：密码验证（至少尝试一次）\n");
    printf("   模拟场景：用户必须至少输入一次密码\n\n");
    
    int correct_password = 123456;
    int user_input = 0;
    int attempts = 0;
    
    do {
        attempts++;
        // 模拟用户输入
        if (attempts == 1) {
            user_input = 111111;  // 第一次错误
            printf("   第%d次尝试：密码错误\n", attempts);
        } else if (attempts == 2) {
            user_input = 123456;  // 第二次正确
            printf("   第%d次尝试：密码正确\n", attempts);
        }
    } while (user_input != correct_password && attempts < 3);
    
    if (user_input == correct_password) {
        printf("   登录成功！\n");
    } else {
        printf("   尝试次数过多，账户已锁定。\n");
    }
    printf("\n");
    
    printf("   示例3：游戏菜单（至少显示一次）\n");
    int game_choice;
    int game_loop = 0;
    
    do {
        game_loop++;
        printf("   第%d次显示游戏菜单\n", game_loop);
        
        // 模拟用户选择
        if (game_loop == 1) {
            game_choice = 1;  // 选择开始游戏
            printf("   选择：开始游戏\n");
        } else if (game_loop == 2) {
            game_choice = 0;  // 选择退出
            printf("   选择：退出游戏\n");
        }
        
    } while (game_choice != 0 && game_loop < 5);
    
    if (game_choice == 0) {
        printf("   游戏结束，欢迎下次再来！\n");
    }
    printf("\n");
    
    /*
     * 3. do-while循环的适用场景
     */
    printf("3. do-while循环的适用场景\n\n");
    
    printf("   场景1：菜单系统\n");
    printf("   需要至少显示一次菜单供用户选择\n");
    printf("   do {\n");
    printf("       显示菜单();\n");
    printf("       获取用户选择();\n");
    printf("       处理选择();\n");
    printf("   } while (用户没有选择退出);\n\n");
    
    printf("   场景2：输入验证\n");
    printf("   需要用户至少输入一次\n");
    printf("   do {\n");
    printf("       获取输入();\n");
    printf("       验证输入();\n");
    printf("   } while (输入无效);\n\n");
    
    printf("   场景3：游戏循环\n");
    printf("   至少执行一次游戏逻辑\n");
    printf("   do {\n");
    printf("       更新游戏状态();\n");
    printf("       渲染画面();\n");
    printf("       处理输入();\n");
    printf("   } while (游戏没有结束);\n\n");
    
    /*
     * 4. do-while循环的注意事项
     */
    printf("4. do-while循环的注意事项\n\n");
    
    printf("   注意1：不要忘记分号\n");
    printf("   do-while语句的while后面必须有分号\n");
    printf("   do { ... } while (条件);  // 正确\n");
    printf("   do { ... } while (条件)   // 错误：缺少分号\n\n");
    
    printf("   注意2：循环变量的更新\n");
    printf("   确保在循环体内更新循环变量\n");
    printf("   否则可能造成死循环\n\n");
    
    printf("   注意3：边界条件的处理\n");
    printf("   特别是第一次执行的特殊情况\n");
    printf("   考虑是否需要特殊处理\n\n");
    
    printf("   注意4：与while循环的选择\n");
    printf("   如果需要至少执行一次：使用do-while\n");
    printf("   如果可能一次都不执行：使用while\n");
    printf("   根据实际需求选择合适的循环\n\n");
}

/*================================================================
  第四部分：for循环详解
  说明：for循环是最常用、结构最清晰的循环
================================================================*/

void part4_for_loop(void) {
    printf("\n");
    printf("================================================\n");
    printf("第四部分：for循环详解\n");
    printf("================================================\n\n");
    
    /*
     * 1. for循环基本语法
     */
    printf("1. for循环基本语法\n");
    printf("   语法：for (初始化; 条件; 更新) { 循环体; }\n");
    printf("   执行流程：\n");
    printf("   1. 执行初始化语句（只执行一次）\n");
    printf("   2. 检查条件是否为真\n");
    printf("   3. 如果为真，执行循环体\n");
    printf("   4. 执行更新语句\n");
    printf("   5. 重复步骤2-4，直到条件为假\n\n");
    
    printf("   for循环的三要素集中在一行：\n");
    printf("   初始化：循环变量的初始值\n");
    printf("   条件：循环继续的条件\n");
    printf("   更新：循环变量的更新方式\n\n");
    
    /*
     * 2. for循环基本示例
     */
    printf("2. for循环基本示例\n\n");
    
    printf("   示例1：打印1到10的数字\n");
    printf("   for (int i = 1; i <= 10; i++) {\n");
    printf("       printf(\"%%d \", i);\n");
    printf("   }\n");
    printf("   输出：");
    
    for (int i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    printf("\n\n");
    
    printf("   示例2：计算1到n的阶乘\n");
    int n = 5;
    long long factorial = 1;
    
    printf("   计算 %d! = ", n);
    for (int i = 1; i <= n; i++) {
        factorial *= i;
        if (i < n) {
            printf("%d × ", i);
        } else {
            printf("%d", i);
        }
    }
    printf(" = %lld\n\n", factorial);
    
    printf("   示例3：遍历数组\n");
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("   数组元素：");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n   数组大小：%d\n\n", size);
    
    /*
     * 3. for循环的变体和特殊用法
     */
    printf("3. for循环的变体和特殊用法\n\n");
    
    printf("   变体1：倒序循环\n");
    printf("   for (int i = 10; i >= 1; i--) {\n");
    printf("       printf(\"%%d \", i);\n");
    printf("   }\n");
    printf("   输出：");
    
    for (int i = 10; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\n\n");
    
    printf("   变体2：步长不为1的循环\n");
    printf("   for (int i = 0; i <= 20; i += 2) {\n");
    printf("       printf(\"%%d \", i);\n");
    printf("   }\n");
    printf("   输出：");
    
    for (int i = 0; i <= 20; i += 2) {
        printf("%d ", i);
    }
    printf("（0到20的偶数）\n\n");
    
    printf("   变体3：多个循环变量\n");
    printf("   for (int i = 0, j = 10; i < j; i++, j--) {\n");
    printf("       printf(\"(%%d,%%d) \", i, j);\n");
    printf("   }\n");
    printf("   输出：");
    
    for (int i = 0, j = 10; i < j; i++, j--) {
        printf("(%d,%d) ", i, j);
    }
    printf("\n\n");
    
    printf("   变体4：省略部分表达式\n");
    printf("   int k = 0;\n");
    printf("   for (; k < 5; ) {  // 省略初始化和更新\n");
    printf("       printf(\"%%d \", k);\n");
    printf("       k++;\n");
    printf("   }\n");
    printf("   注意：分号不能省略，即使表达式为空\n\n");
    
    printf("   变体5：无限for循环\n");
    printf("   for (;;) {  // 所有表达式都省略\n");
    printf("       // 无限循环，需要break退出\n");
    printf("   }\n\n");
    
    /*
     * 4. for循环的注意事项
     */
    printf("4. for循环的注意事项\n\n");
    
    printf("   注意1：循环变量的作用域\n");
    printf("   在C99之前，循环变量必须在for外部声明\n");
    printf("   C99及以后，可以在for内部声明（推荐）\n\n");
    
    printf("   传统的写法（C89）：\n");
    printf("   int i;\n");
    printf("   for (i = 0; i < 10; i++) { ... }\n\n");
    
    printf("   现代的写法（C99）：\n");
    printf("   for (int i = 0; i < 10; i++) { ... }\n");
    printf("   优点：循环变量只在循环内有效\n\n");
    
    printf("   注意2：浮点数作为循环变量\n");
    printf("   避免使用浮点数作为循环变量\n");
    printf("   浮点数的精度问题可能导致意外结果\n\n");
    
    printf("   错误的例子：\n");
    printf("   for (double x = 0.0; x != 1.0; x += 0.1) { ... }\n");
    printf("   由于浮点数精度，x可能永远不会等于1.0\n\n");
    
    printf("   正确的做法：\n");
    printf("   for (int i = 0; i <= 10; i++) {\n");
    printf("       double x = i * 0.1;\n");
    printf("       // 使用x进行计算\n");
    printf("   }\n\n");
    
    printf("   注意3：不要在循环体内修改循环变量\n");
    printf("   这可能导致循环行为不可预测\n");
    printf("   如果需要修改，确保理解其影响\n\n");
    
    printf("   注意4：循环效率\n");
    printf("   将不变的计算移到循环外\n");
    printf("   减少循环内的函数调用\n");
    printf("   使用局部变量提高效率\n\n");
}

/*================================================================
  第五部分：循环控制语句详解
  说明：break、continue、goto语句的使用
================================================================*/

void part5_loop_control(void) {
    printf("\n");
    printf("================================================\n");
    printf("第五部分：循环控制语句详解\n");
    printf("================================================\n\n");
    
    /*
     * 1. break语句
     */
    printf("1. break语句\n");
    printf("   作用：立即退出当前循环（或switch语句）\n");
    printf("   注意：只退出包含它的最内层循环\n\n");
    
    printf("   示例1：在循环中使用break\n");
    printf("   查找数组中第一个负数\n");
    
    int arr[] = {5, 3, 0, -2, 7, -1, 4};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int first_negative = 0;
    bool found = false;
    
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] < 0) {
            first_negative = arr[i];
            found = true;
            printf("   找到第一个负数：%d，位于位置%d\n", first_negative, i);
            break;  // 找到后立即退出循环
        }
    }
    
    if (!found) {
        printf("   没有找到负数\n");
    }
    printf("\n");
    
    printf("   示例2：break在while循环中的使用\n");
    printf("   模拟：读取用户输入直到输入q\n");
    
    char ch = 'a';  // 模拟用户输入
    int input_count = 0;
    
    while (1) {  // 无限循环
        input_count++;
        
        // 模拟用户输入
        if (input_count == 1) ch = 'h';
        else if (input_count == 2) ch = 'e';
        else if (input_count == 3) ch = 'l';
        else if (input_count == 4) ch = 'l';
        else if (input_count == 5) ch = 'o';
        else if (input_count == 6) {
            ch = 'q';  // 输入q退出
            printf("   用户输入了'q'，退出循环\n");
        }
        
        if (ch == 'q') {
            break;  // 退出无限循环
        }
        
        printf("   第%d次输入：%c\n", input_count, ch);
        
        if (input_count > 10) {  // 安全限制
            printf("   输入次数过多，强制退出\n");
            break;
        }
    }
    printf("\n");
    
    /*
     * 2. continue语句
     */
    printf("2. continue语句\n");
    printf("   作用：跳过本次循环的剩余部分，直接进入下一次循环\n");
    printf("   注意：只跳过当前迭代，不退出整个循环\n\n");
    
    printf("   示例1：只处理正数，跳过负数\n");
    
    int numbers[] = {5, -3, 2, -8, 7, 0, -1, 4};
    int num_size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("   原始数组：");
    for (int i = 0; i < num_size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    printf("   只输出正数：");
    for (int i = 0; i < num_size; i++) {
        if (numbers[i] <= 0) {
            continue;  // 跳过非正数
        }
        printf("%d ", numbers[i]);
    }
    printf("\n\n");
    
    printf("   示例2：跳过特定值的处理\n");
    printf("   计算1到10中非3的倍数的和\n");
    
    int sum = 0;
    for (int i = 1; i <= 10; i++) {
        if (i % 3 == 0) {
            printf("   跳过 %d（3的倍数）\n", i);
            continue;  // 跳过3的倍数
        }
        sum += i;
        printf("   累加 %d，当前和：%d\n", i, sum);
    }
    printf("   最终结果：%d\n\n", sum);
    
    /*
     * 3. break与continue的区别
     */
    printf("3. break与continue的区别\n\n");
    
    printf("   break：\n");
    printf("   - 立即退出整个循环\n");
    printf("   - 循环完全结束\n");
    printf("   - 用于满足某个条件时提前结束循环\n\n");
    
    printf("   continue：\n");
    printf("   - 只跳过当前迭代\n");
    printf("   - 循环继续下一次迭代\n");
    printf("   - 用于跳过某些不需要处理的情况\n\n");
    
    printf("   对比示例：\n");
    printf("   for (int i = 1; i <= 5; i++) {\n");
    printf("       if (i == 3) break;\n");
    printf("       printf(\"%%d \", i);\n");
    printf("   }\n");
    printf("   输出：1 2（遇到3时退出循环）\n\n");
    
    printf("   for (int i = 1; i <= 5; i++) {\n");
    printf("       if (i == 3) continue;\n");
    printf("       printf(\"%%d \", i);\n");
    printf("   }\n");
    printf("   输出：1 2 4 5（跳过3，但继续循环）\n\n");
    
    /*
     * 4. goto语句（一般不推荐使用）
     */
    printf("4. goto语句（了解即可，一般不推荐使用）\n");
    printf("   作用：无条件跳转到指定的标签处\n");
    printf("   语法：goto 标签;\n");
    printf("         标签: 语句;\n\n");
    
    printf("   示例：使用goto跳出多层循环\n");
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("   (%d,%d) ", i, j);
            if (i == 1 && j == 1) {
                printf("\\n   满足条件，使用goto跳出所有循环\\n");
                goto end_loops;  // 跳转到标签
            }
        }
        printf("\n");
    }
    
    end_loops:  // 标签
    printf("   跳转到这里，循环结束\n\n");
    
    printf("   goto语句的注意事项：\n");
    printf("   - 破坏程序结构，降低可读性\n");
    printf("   - 可能导致难以发现的bug\n");
    printf("   - 现代编程中很少使用\n");
    printf("   - 仅在某些特殊情况下使用（如错误处理）\n\n");
    
    printf("   替代goto的方案：\n");
    printf("   1. 使用函数返回\n");
    printf("   2. 使用标志变量\n");
    printf("   3. 重构代码结构\n");
    printf("   4. 使用break和continue\n\n");
}

/*================================================================
  第六部分：嵌套循环详解
  说明：循环内部包含另一个循环
================================================================*/

void part6_nested_loops(void) {
    printf("\n");
    printf("================================================\n");
    printf("第六部分：嵌套循环详解\n");
    printf("================================================\n\n");
    
    /*
     * 1. 嵌套循环基本概念
     */
    printf("1. 嵌套循环基本概念\n");
    printf("   定义：一个循环内部包含另一个完整的循环\n");
    printf("   外层循环：包含其他循环的循环\n");
    printf("   内层循环：被包含的循环\n");
    printf("   执行顺序：外层循环一次，内层循环完整执行一遍\n\n");
    
    printf("   执行流程示意图：\n");
    printf("   外层循环开始\n");
    printf("   ├─ 内层循环开始（执行完整一遍）\n");
    printf("   ├─ 内层循环结束\n");
    printf("   ├─ 外层循环更新\n");
    printf("   └─ 重复直到外层循环结束\n\n");
    
    /*
     * 2. 嵌套循环示例
     */
    printf("2. 嵌套循环示例\n\n");
    
    printf("   示例1：打印九九乘法表\n");
    printf("   外层循环：被乘数（1-9）\n");
    printf("   内层循环：乘数（1-当前被乘数）\n\n");
    
    for (int i = 1; i <= 9; i++) {          // 外层循环
        for (int j = 1; j <= i; j++) {      // 内层循环
            printf("   %d×%d=%-2d ", j, i, i * j);
        }
        printf("\n");
    }
    printf("\n");
    
    printf("   示例2：打印图形（直角三角形）\n");
    int rows = 5;
    
    printf("   行数：%d\n", rows);
    for (int i = 1; i <= rows; i++) {       // 控制行数
        for (int j = 1; j <= i; j++) {      // 控制每行的星号数
            printf("* ");
        }
        printf("\n");
    }
    printf("\n");
    
    printf("   示例3：二维数组遍历\n");
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    printf("   3×4矩阵：\n");
    for (int i = 0; i < 3; i++) {           // 行循环
        printf("   ");
        for (int j = 0; j < 4; j++) {       // 列循环
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    printf("   示例4：冒泡排序（简单演示）\n");
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("   排序前：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // 简化版冒泡排序演示
    for (int i = 0; i < n - 1; i++) {       // 外层：遍历次数
        for (int j = 0; j < n - i - 1; j++) { // 内层：比较相邻元素
            if (arr[j] > arr[j + 1]) {
                // 交换
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    printf("   排序后：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    /*
     * 3. 多层嵌套循环
     */
    printf("3. 多层嵌套循环\n");
    printf("   可以有任意层嵌套，但一般不超过3层\n\n");
    
    printf("   示例：三维数组遍历\n");
    int cube[2][3][2] = {
        {{1, 2}, {3, 4}, {5, 6}},
        {{7, 8}, {9, 10}, {11, 12}}
    };
    
    printf("   2×3×2三维数组：\n");
    for (int i = 0; i < 2; i++) {           // 第一维
        printf("   第%d层：\n", i);
        for (int j = 0; j < 3; j++) {       // 第二维
            printf("      ");
            for (int k = 0; k < 2; k++) {   // 第三维
                printf("%3d ", cube[i][j][k]);
            }
            printf("\n");
        }
    }
    printf("\n");
    
    /*
     * 4. 嵌套循环的注意事项
     */
    printf("4. 嵌套循环的注意事项\n\n");
    
    printf("   注意1：循环变量名不要重复\n");
    printf("   不同层的循环应使用不同的变量名\n");
    printf("   for (int i = 0; i < 5; i++) {\n");
    printf("       for (int j = 0; j < 5; j++) {  // 正确：使用j\n");
    printf("           // ...\n");
    printf("       }\n");
    printf("   }\n\n");
    
    printf("   注意2：避免过度嵌套\n");
    printf("   嵌套层次过深会降低可读性\n");
    printf("   一般建议不超过3层嵌套\n");
    printf("   如果嵌套太深，考虑重构代码\n\n");
    
    printf("   注意3：注意循环效率\n");
    printf("   嵌套循环的时间复杂度是乘积关系\n");
    printf("   两层嵌套：O(n²)\n");
    printf("   三层嵌套：O(n³)\n");
    printf("   对于大数据量要考虑性能\n\n");
    
    printf("   注意4：break和continue的影响范围\n");
    printf("   break/continue只影响包含它的最内层循环\n");
    printf("   如果需要跳出多层循环，需要使用其他方法\n\n");
}

/*================================================================
  第七部分：循环结构应用实例
  说明：循环在实际编程中的应用
================================================================*/

void part7_practical_examples(void) {
    printf("\n");
    printf("================================================\n");
    printf("第七部分：循环结构应用实例\n");
    printf("================================================\n\n");
    
    /*
     * 1. 数字处理类应用
     */
    printf("1. 数字处理类应用\n\n");
    
    printf("   示例1：判断质数\n");
    int num = 17;
    bool is_prime = true;
    
    if (num <= 1) {
        is_prime = false;
    } else {
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                is_prime = false;
                break;
            }
        }
    }
    
    printf("   数字%d是%s\n", num, is_prime ? "质数" : "合数");
    printf("\n");
    
    printf("   示例2：斐波那契数列\n");
    int fib_count = 10;
    long long fib1 = 0, fib2 = 1, fib_next;
    
    printf("   前%d个斐波那契数：\n", fib_count);
    printf("   %lld %lld ", fib1, fib2);
    
    for (int i = 3; i <= fib_count; i++) {
        fib_next = fib1 + fib2;
        printf("%lld ", fib_next);
        fib1 = fib2;
        fib2 = fib_next;
    }
    printf("\n\n");
    
    printf("   示例3：最大公约数（GCD）\n");
    int a = 56, b = 98;
    int original_a = a, original_b = b;
    
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    printf("   %d和%d的最大公约数是：%d\n", original_a, original_b, a);
    printf("\n");
    
    /*
     * 2. 字符串处理类应用
     */
    printf("2. 字符串处理类应用\n\n");
    
    printf("   示例1：统计字符串长度\n");
    char str[] = "Hello, C Programming!";
    int length = 0;
    
    while (str[length] != '\0') {
        length++;
    }
    
    printf("   字符串：\"%s\"\n", str);
    printf("   长度：%d\n", length);
    printf("\n");
    
    printf("   示例2：统计字符出现次数\n");
    char text[] = "programming is fun and programming is challenging";
    char target = 'm';
    int count = 0;
    
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == target) {
            count++;
        }
    }
    
    printf("   文本：\"%s\"\n", text);
    printf("   字符'%c'出现了%d次\n", target, count);
    printf("\n");
    
    printf("   示例3：字符串反转\n");
    char original[] = "ABCDEFG";
    char reversed[100];
    int len = 0;
    
    // 计算长度
    while (original[len] != '\0') {
        len++;
    }
    
    // 反转
    for (int i = 0; i < len; i++) {
        reversed[i] = original[len - 1 - i];
    }
    reversed[len] = '\0';
    
    printf("   原字符串：%s\n", original);
    printf("   反转后：%s\n", reversed);
    printf("\n");
    
    /*
     * 3. 游戏和模拟类应用
     */
    printf("3. 游戏和模拟类应用\n\n");
    
    printf("   示例1：猜数字游戏\n");
    int secret_number = 42;
    int guess = 0;
    int attempts = 0;
    int max_attempts = 5;
    
    printf("   猜数字游戏开始！数字在1-100之间\n");
    printf("   你有%d次机会\n\n", max_attempts);
    
    for (attempts = 1; attempts <= max_attempts; attempts++) {
        // 模拟用户猜测
        if (attempts == 1) guess = 50;
        else if (attempts == 2) guess = 30;
        else if (attempts == 3) guess = 45;
        else if (attempts == 4) guess = 42;  // 猜对了
        
        printf("   第%d次猜测：%d\n", attempts, guess);
        
        if (guess == secret_number) {
            printf("   恭喜！猜对了！\n");
            break;
        } else if (guess < secret_number) {
            printf("   太小了\n");
        } else {
            printf("   太大了\n");
        }
        
        if (attempts == max_attempts) {
            printf("   很遗憾，机会用完了。正确答案是：%d\n", secret_number);
        }
    }
    printf("\n");
    
    printf("   示例2：简单的进度条模拟\n");
    int total_steps = 20;
    
    printf("   任务执行中：\n");
    printf("   [");
    
    for (int i = 0; i <= total_steps; i++) {
        // 模拟进度更新
        for (int j = 0; j < i; j++) {
            printf("=");
        }
        for (int j = i; j < total_steps; j++) {
            printf(" ");
        }
        
        printf("] %d%%\r", (i * 100) / total_steps);
        // 模拟延时
        for (int k = 0; k < 10000000; k++) {}
    }
    
    printf("\n   任务完成！\n\n");
    
    /*
     * 4. 数据处理类应用
     */
    printf("4. 数据处理类应用\n\n");
    
    printf("   示例1：计算平均值和统计\n");
    int scores[] = {85, 92, 78, 90, 88, 76, 95, 89, 81, 93};
    int score_count = sizeof(scores) / sizeof(scores[0]);
    int sum_scores = 0;
    int max_score = scores[0];
    int min_score = scores[0];
    
    for (int i = 0; i < score_count; i++) {
        sum_scores += scores[i];
        
        if (scores[i] > max_score) {
            max_score = scores[i];
        }
        
        if (scores[i] < min_score) {
            min_score = scores[i];
        }
    }
    
    double average = (double)sum_scores / score_count;
    
    printf("   成绩统计：\n");
    printf("   成绩列表：");
    for (int i = 0; i < score_count; i++) {
        printf("%d ", scores[i]);
    }
    printf("\n");
    
    printf("   平均分：%.2f\n", average);
    printf("   最高分：%d\n", max_score);
    printf("   最低分：%d\n", min_score);
    printf("   总人数：%d\n", score_count);
    printf("\n");
    
    printf("   示例2：查找和过滤数据\n");
    int data[] = {23, 45, 67, 12, 89, 34, 56, 78, 90, 21};
    int data_size = sizeof(data) / sizeof(data[0]);
    int threshold = 50;
    
    printf("   原始数据：");
    for (int i = 0; i < data_size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    printf("   大于%d的数据：", threshold);
    for (int i = 0; i < data_size; i++) {
        if (data[i] > threshold) {
            printf("%d ", data[i]);
        }
    }
    printf("\n");
}

/*================================================================
  第八部分：循环编程技巧
  说明：编写高效、可读性好的循环代码
================================================================*/

void part8_programming_tips(void) {
    printf("\n");
    printf("================================================\n");
    printf("第八部分：循环编程技巧\n");
    printf("================================================\n\n");
    
    printf("1. 选择合适的循环类型\n");
    printf("   - 知道循环次数：使用for循环\n");
    printf("   - 不知道循环次数，但知道条件：使用while循环\n");
    printf("   - 至少执行一次：使用do-while循环\n");
    printf("   - 遍历数组或集合：使用for循环\n\n");
    
    printf("2. 优化循环性能\n");
    printf("   - 将不变的计算移到循环外\n");
    printf("   - 减少循环内的函数调用\n");
    printf("   - 使用局部变量\n");
    printf("   - 避免在循环内分配内存\n\n");
    
    printf("   性能差的例子：\n");
    printf("   for (int i = 0; i < strlen(str); i++) { ... }\n");
    printf("   // strlen在每次循环都调用，效率低\n\n");
    
    printf("   性能好的例子：\n");
    printf("   int len = strlen(str);\n");
    printf("   for (int i = 0; i < len; i++) { ... }\n");
    printf("   // strlen只调用一次\n\n");
    
    printf("3. 编写清晰的循环条件\n");
    printf("   - 使用有意义的变量名\n");
    printf("   - 避免复杂的条件表达式\n");
    printf("   - 使用布尔变量提高可读性\n\n");
    
    printf("   不清晰的例子：\n");
    printf("   while (i < n && !found && (count < max || flag)) { ... }\n\n");
    
    printf("   清晰的例子：\n");
    printf("   bool continue_search = (i < n) && !found;\n");
    printf("   bool within_limits = (count < max) || flag;\n");
    printf("   while (continue_search && within_limits) { ... }\n\n");
    
    printf("4. 避免常见的循环错误\n");
    printf("   - 死循环：确保循环条件能变为假\n");
    printf("   - 差一错误：注意边界条件\n");
    printf("   - 无限递归：循环内不要调用自身\n");
    printf("   - 修改循环变量：除非必要，不要在循环内修改循环变量\n\n");
    
    printf("5. 使用循环时考虑可维护性\n");
    printf("   - 添加适当的注释\n");
    printf("   - 限制嵌套层次（一般不超过3层）\n");
    printf("   - 将复杂的循环逻辑提取为函数\n");
    printf("   - 使用常量代替魔法数字\n\n");
    
    printf("6. 调试循环的技巧\n");
    printf("   - 添加调试输出，显示循环变量的值\n");
    printf("   - 使用断点观察循环执行过程\n");
    printf("   - 检查边界条件\n");
    printf("   - 测试空集合或极端情况\n\n");
    
    printf("7. 循环的最佳实践总结\n");
    printf("   - 保持循环简短（最好不超过20行）\n");
    printf("   - 一个循环只做一件事\n");
    printf("   - 使用有意义的循环变量名\n");
    printf("   - 优先使用for循环遍历数组\n");
    printf("   - 考虑循环的提前退出（使用break）\n");
    printf("   - 处理所有可能的循环退出条件\n\n");
}
