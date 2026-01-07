# 🎯 C 语言编程入门 - Steve-1219 的学习仓库

![GitHub last commit](https://img.shields.io/github/last-commit/Steve-1219/c-learning)
![GitHub repo size](https://img.shields.io/github/repo-size/Steve-1219/c-learning)
![GitHub License](https://img.shields.io/github/license/Steve-1219/c-learning)
![GitHub stars](https://img.shields.io/github/stars/Steve-1219/c-learning?style=social)

> 一个完整的 C 语言学习项目，包含教程、示例、练习和实战项目。由 Steve-1219 创建和维护。

## ✨ 项目亮点

- ✅ **系统学习** - 从零开始的完整学习路径
- ✅ **丰富示例** - 100+ 个实用代码示例
- ✅ **互动练习** - 分级练习题和答案
- ✅ **实战项目** - 从简单到复杂的完整项目
- ✅ **详细文档** - 速查表、常见错误、学习资源

---

## 🚀 快速开始（5分钟内）

### 1. 获取代码
```bash
# 克隆项目
git clone https://github.com/Steve-1219/c-learning.git

# 进入项目目录
cd c-learning
```

### 2. 运行第一个程序
```bash
# 进入基础示例目录
cd src/basics

# 编译运行 Hello World
gcc hello-world.c -o hello
./hello
```

### 3. 查看输出
```
Hello, C World!
Welcome to Steve-1219's C Learning Project!
```

### 第二部分：项目结构
```markdown
## 📁 项目结构概览
```
c-learning/
├── 📘 README.md                  # 主项目介绍文档
├── 📖 tutorial.md                # 完整C语言教程
├── ⚙️ setup-guide.md             # 开发环境配置指南
├── 📚 examples.md                # 代码示例目录索引
├── 📝 practice-exercises.md      # 练习题和答案
├── 🚀 projects.md                # 实战项目指导
└── 📁 src/                       # C语言源代码
    ├── 🔰 basics/                # 基础语法
    │   ├── 👋 hello-world.c      # Hello World示例
    │   ├── 🔢 variables.c        # 变量和数据类型
    │   ├── ➕ operators.c        # 运算符使用
    │   ├── 🔄 control-flow.c     # 控制结构
    │   ├── 🎯 functions.c        # 函数基础
    │   └── 📊 arrays.c           # 数组操作
    ├── 🧭 pointers/              # 指针专题
    │   ├📍 basic-pointers.c   # 指针基础
    │   ├📍🔢 pointer-arrays.c   # 指针与数组
    │   ├📍💾 dynamic-memory.c   # 动态内存分配
    │   └📍⚡ function-pointers.c # 函数指针
    ├── 🎯 functions/             # 函数进阶
    │   ├── 🔁 recursion.c        # 递归函数
    │   ├── 🔀 variable-funcs.c   # 可变参数函数
    │   └── ⚡ inline-funcs.c     # 内联函数
    ├── 🚀 advanced/              # 高级主题
    │   ├── 🏗️ structures.c       # 结构体
    │   ├── 🤝 unions.c           # 联合体
    │   ├── 📁 file-io.c          # 文件操作
    │   ├── 🔧 preprocessor.c     # 预处理器
    │   └── 🔢 bit-operations.c   # 位运算
    └── 🛠️ projects/              # 实战项目
        └── 🧮 calculator/        # 计算器项目
            ├── 🎮 calculator.c   # 主程序
            └── ➗ operations.c
