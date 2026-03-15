# **GCC 常用方法大全**

## **一、基础编译**

### **1. C 程序编译**
```bash
# 编译单个文件，输出 a.out
gcc hello.c

# 指定输出文件名
gcc hello.c -o hello

# 运行程序
./hello
```

### **2. C++ 程序编译**
```bash
# 使用 g++（推荐）
g++ hello.cpp -o hello

# 使用 gcc 编译 C++（需要链接 C++ 库）
gcc hello.cpp -lstdc++ -o hello
```

---

## **二、编译选项分类**

### **1. 优化选项**
```bash
# 无优化（调试用，默认）
gcc -O0 program.c -o program

# 基本优化
gcc -O1 program.c -o program

# 推荐优化（常用）
gcc -O2 program.c -o program

# 激进优化
gcc -O3 program.c -o program

# 优化代码大小
gcc -Os program.c -o program

# 优化调试体验
gcc -Og program.c -o program
```

### **2. 调试信息**
```bash
# 生成调试信息（gdb 用）
gcc -g program.c -o program

# 三级调试信息
gcc -g3 program.c -o program

# 独立调试信息文件
gcc -g -gsplit-dwarf program.c -o program
```

### **3. 警告控制**
```bash
# 开启所有常见警告
gcc -Wall program.c -o program

# 更多警告
gcc -Wall -Wextra program.c -o program

# 严格的 ISO C 警告
gcc -Wall -Wextra -pedantic program.c -o program

# 将警告视为错误
gcc -Wall -Werror program.c -o program

# 特定警告控制
gcc -Wno-unused-variable program.c  # 禁用未使用变量警告
gcc -Wshadow program.c              # 变量遮盖警告
```

### **4. 标准版本**
```bash
# C 标准
gcc -std=c89 program.c
gcc -std=c99 program.c
gcc -std=c11 program.c
gcc -std=c17 program.c
gcc -std=c2x program.c              # 最新草案

# GNU 扩展标准（默认）
gcc -std=gnu11 program.c

# C++ 标准（用 g++ 或 gcc -lstdc++）
g++ -std=c++11 program.cpp
g++ -std=c++14 program.cpp
g++ -std=c++17 program.cpp
g++ -std=c++20 program.cpp
g++ -std=c++23 program.cpp
```

---

## **三、多文件编译**

### **1. 分别编译链接**
```bash
# 编译为目标文件（.o）
gcc -c main.c -o main.o
gcc -c utils.c -o utils.o
gcc -c math.c -o math.o

# 链接成可执行文件
gcc main.o utils.o math.o -o program
```

### **2. 直接编译多个文件**
```bash
gcc main.c utils.c math.c -o program
```

### **3. 编译为静态库**
```bash
# 编译为目标文件
gcc -c lib1.c -o lib1.o
gcc -c lib2.c -o lib2.o

# 打包为静态库
ar rcs libmylib.a lib1.o lib2.o

# 使用静态库
gcc main.c -L. -lmylib -o program
```

### **4. 编译为动态库**
```bash
# 编译为位置无关代码
gcc -fPIC -c lib1.c -o lib1.o
gcc -fPIC -c lib2.c -o lib2.o

# 创建动态库
gcc -shared lib1.o lib2.o -o libmylib.so

# 使用动态库
gcc main.c -L. -lmylib -o program

# 运行时指定库路径
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
./program
```

---

## **四、目录和库管理**

### **1. 头文件目录**
```bash
# 添加头文件搜索路径
gcc -I./include program.c -o program
gcc -I../libs/include program.c
gcc -I/usr/local/include program.c

# 多个目录
gcc -I./inc1 -I./inc2 -I/opt/include program.c
```

### **2. 库文件目录**
```bash
# 添加库搜索路径
gcc -L./lib program.c -o program
gcc -L/usr/local/lib program.c

# 链接库文件
gcc program.c -lm          # 数学库
gcc program.c -lpthread    # 线程库
gcc program.c -ldl         # 动态加载库
gcc program.c -lm -lpthread -lrt  # 多个库

# 静态链接
gcc program.c -static -lm  # 静态链接所有库
```

### **3. 常用库示例**
```bash
# 图形界面 (GTK)
gcc gtk_app.c -o gtk_app `pkg-config --cflags --libs gtk+-3.0`

# OpenGL
gcc opengl_app.c -o opengl_app -lGL -lGLU -lglut

# SDL2
gcc sdl_app.c -o sdl_app -lSDL2 -lSDL2_image -lSDL2_ttf

# 网络编程
gcc server.c -o server -lpthread
```

---

## **五、预处理和诊断**

### **1. 预处理**
```bash
# 只进行预处理（生成 .i 文件）
gcc -E program.c -o program.i

# 查看宏定义
gcc -dM -E program.c

# 包含头文件信息
gcc -H program.c
```

### **2. 生成汇编代码**
```bash
# 生成汇编（.s 文件）
gcc -S program.c -o program.s

# 带优化和调试信息的汇编
gcc -S -O2 -g program.c
```

### **3. 依赖关系**
```bash
# 生成依赖关系（Makefile 用）
gcc -M program.c             # 包含系统头文件
gcc -MM program.c            # 不包含系统头文件
gcc -MD program.c            # 生成 .d 文件
gcc -MMD program.c           # 不包含系统头文件的 .d 文件
```

### **4. 性能分析**
```bash
# 生成性能分析数据（gprof）
gcc -pg program.c -o program
./program                    # 运行生成 gmon.out
gprof program gmon.out       # 查看分析结果

# 代码覆盖（gcov）
gcc -fprofile-arcs -ftest-coverage program.c
./program                    # 运行
gcov program.c              # 生成覆盖率报告
```

---

## **六、架构和平台相关**

### **1. 目标架构**
```bash
# 指定目标平台
gcc -m32 program.c          # 编译为 32 位
gcc -m64 program.c          # 编译为 64 位（默认）
gcc -march=native program.c # 为本机 CPU 优化
gcc -march=x86-64 -mtune=generic program.c

# ARM 平台
arm-linux-gnueabi-gcc program.c  # ARM 交叉编译
aarch64-linux-gnu-gcc program.c  # ARM64 交叉编译
```

### **2. 输出格式**
```bash
# 生成位置无关代码
gcc -fPIC -c lib.c -o lib.o

# 生成共享库
gcc -shared -o lib.so lib1.o lib2.o

# 生成可重定位目标文件
gcc -c program.c -o program.o
```

### **3. 安全加固**
```bash
# 栈保护
gcc -fstack-protector program.c
gcc -fstack-protector-strong program.c
gcc -fstack-protector-all program.c

# 内存位置随机化（ASLR）
gcc -fPIE -pie program.c -o program

# 格式字符串保护
gcc -Wformat -Wformat-security program.c

# 缓冲区溢出检测
gcc -D_FORTIFY_SOURCE=2 -O2 program.c
```

---

## **七、实用组合命令**

### **1. 常用开发组合**
```bash
# 开发编译（调试）
gcc -g -Wall -Wextra -O0 program.c -o program

# 发布编译
gcc -Wall -Wextra -O2 -DNDEBUG program.c -o program

# 安全敏感编译
gcc -Wall -Wextra -O2 -fstack-protector-strong -D_FORTIFY_SOURCE=2 program.c -o program
```

### **2. 编译检查**
```bash
# 只检查语法不生成文件
gcc -fsyntax-only program.c

# 检查所有警告
gcc -Wall -Wextra -pedantic -fsyntax-only program.c
```

### **3. 查看编译器信息**
```bash
# 查看 GCC 版本
gcc --version

# 查看预定义的宏
gcc -dM -E - < /dev/null

# 查看搜索路径
gcc -print-search-dirs
gcc -print-file-name=libc.a
echo | gcc -E -Wp,-v -  # 查看头文件搜索路径
```

---

## **八、实际示例**

### **示例1：完整项目编译**
```bash
# 假设项目结构：
# src/main.c src/utils.c include/utils.h

# 编译
gcc -I./include -c src/main.c -o obj/main.o
gcc -I./include -c src/utils.c -o obj/utils.o
gcc obj/main.o obj/utils.o -o bin/program

# 或一步到位
gcc -I./include src/main.c src/utils.c -o bin/program -Wall -O2
```

### **示例2：Makefile 常用规则**
```makefile
CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS = -lm

program: main.o utils.o
    $(CC) $^ -o $@ $(LDFLAGS)

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f *.o program
```

### **示例3：调试编译**
```bash
# 带调试信息的编译
gcc -g3 -O0 -Wall program.c -o program.debug

# 使用 gdb 调试
gdb ./program.debug
# (gdb) break main
# (gdb) run
# (gdb) next
# (gdb) print variable
```

---

## **九、快速参考表**

| 选项       | 作用           | 常用场景   |
| ---------- | -------------- | ---------- |
| `-o file`  | 指定输出文件名 | 所有编译   |
| `-c`       | 只编译不链接   | 多文件项目 |
| `-g`       | 生成调试信息   | 调试阶段   |
| `-O2`      | 优化级别2      | 发布版本   |
| `-Wall`    | 开启所有警告   | 开发阶段   |
| `-I dir`   | 添加头文件路径 | 使用外部库 |
| `-L dir`   | 添加库文件路径 | 链接外部库 |
| `-l lib`   | 链接库文件     | 使用系统库 |
| `-std=c11` | 指定C标准      | 跨平台兼容 |
| `-D MACRO` | 定义宏         | 条件编译   |
| `-E`       | 只预处理       | 调试宏     |
| `-S`       | 生成汇编       | 性能分析   |
| `-shared`  | 生成动态库     | 库开发     |
| `-fPIC`    | 位置无关代码   | 动态库编译 |
| `-m32`     | 32位编译       | 兼容旧系统 |

---

**一句话总结**：根据开发阶段选择不同组合：
- **调试**：`gcc -g -Wall -O0`
- **测试**：`gcc -Wall -O2 -DNDEBUG`
- **发布**：`gcc -O3 -DNDEBUG`
- **安全**：`gcc -O2 -fstack-protector-strong -D_FORTIFY_SOURCE=2`















# 调试方法

## **一、GDB 基础调试流程**

### **1. 准备可调试的程序**

```bash
# 编译时添加 -g 参数生成调试信息
gcc -g program.c -o program

# 如果想同时优化和调试（开发常用）
gcc -g -O0 program.c -o program  # -O0 禁用优化，调试更直观
```

### **2. GDB 基本命令**
```bash
# 启动GDB
gdb ./program

# 或直接带参数启动
gdb --args ./program arg1 arg2
```

#### **常用调试命令**

```gdb
# 运行控制
(gdb) run                    # 运行程序
(gdb) run arg1 arg2          # 带参数运行
(gdb) start                  # 开始运行并在main处暂停

# 断点管理
(gdb) break main             # 在main函数设断点
(gdb) break file.c:20        # 在file.c第20行设断点
(gdb) break function_name    # 在函数处设断点
(gdb) info breakpoints       # 查看所有断点
(gdb) delete 1               # 删除1号断点

# 执行控制
(gdb) next (n)               # 执行下一行（不进入函数）
(gdb) step (s)               # 执行下一行（进入函数）
(gdb) continue (c)           # 继续运行到下一个断点
(gdb) finish                 # 运行到当前函数返回

# 查看数据
(gdb) print variable         # 打印变量值
(gdb) print array[0]@10      # 打印数组前10个元素
(gdb) display variable       # 每次停止时自动显示变量
(gdb) info locals            # 查看所有局部变量
(gdb) info args              # 查看函数参数

# 查看源码和堆栈
(gdb) list                   # 显示当前源码
(gdb) backtrace (bt)         # 查看调用栈
(gdb) frame 1                # 切换到栈帧1
```

---

## **二、查看反汇编代码**

### **1. 在 GDB 中查看汇编**
```gdb
# 查看汇编代码
(gdb) disassemble            # 反汇编当前函数
(gdb) disassemble main       # 反汇编main函数
(gdb) disas /m main          # 混合显示源码和汇编

# 设置汇编格式
(gdb) set disassembly-flavor intel   # Intel格式（常用）
(gdb) set disassembly-flavor att     # AT&T格式（默认）

# 查看特定地址的汇编
(gdb) x/10i $pc              # 查看程序计数器处10条指令
```

### **2. 用 objdump 查看反汇编**
```bash
# 查看整个可执行文件的汇编
objdump -d ./program > program.asm

# 查看特定函数的汇编
objdump -d ./program | grep -A 20 "<main>:"

# 混合显示源码和汇编（需要-g编译）
objdump -S -d ./program > program_mixed.asm

# 查看只读数据段（字符串常量等）
objdump -s -j .rodata ./program

# 各种有用的选项组合
objdump -M intel -d ./program        # Intel格式
objdump -t ./program                 # 符号表
objdump -h ./program                 # 段头信息
```

### **3. objdump 常用参数详解**
```bash
# 格式：objdump [选项] 文件

# 主要功能分类：
1. 反汇编代码
   -d, --disassemble        # 反汇编代码段
   -D, --disassemble-all    # 反汇编所有段

2. 查看文件结构  
   -h, --section-headers    # 查看段头信息
   -t, --syms               # 查看符号表
   -T, --dynamic-syms       # 查看动态符号表

3. 查看数据内容
   -s, --full-contents      # 显示所有段内容
   -j section               # 仅显示特定段

4. 查看头信息
   -f, --file-headers       # 查看文件头
   -p, --private-headers    # 查看私有头信息

# 实用组合
objdump -f ./program                 # 查看文件基本信息
objdump -t ./program | grep FUNCTION # 查找函数
objdump -s -j .data ./program        # 查看全局变量
```

---

## **三、查看和分析内存**

### **1. GDB 内存查看命令**
```gdb
# 基本内存查看
(gdb) x/10xw &variable      # 以16进制查看10个字（4字节）
(gdb) x/20cb &variable      # 以字符查看20个字节
(gdb) x/s &string           # 以字符串格式查看

# x命令格式：x/[数量][格式][单位] 地址
格式：x(16进制)、d(10进制)、u(无符号10进制)、o(8进制)、
      t(2进制)、c(字符)、s(字符串)、i(指令)
单位：b(字节)、h(半字/2字节)、w(字/4字节)、g(双字/8字节)

# 示例
(gdb) x/4xw 0x7fffffffe340  # 查看该地址的4个4字节字
(gdb) x/16cb &array         # 查看数组前16个字节的字符
(gdb) x/10i main            # 查看main函数的前10条指令

# 内存修改
(gdb) set {int}0x7fffffffe340 = 42  # 修改内存值
(gdb) set variable = 100            # 修改变量值
```

### **2. 查看堆栈内存**
```gdb
# 查看当前堆栈帧
(gdb) info frame

# 查看堆栈内容
(gdb) x/40xw $sp           # 查看栈顶40个字
(gdb) x/20a $sp            # 查看栈顶20个地址

# 查看寄存器
(gdb) info registers       # 查看所有寄存器
(gdb) print $rax           # 查看rax寄存器
(gdb) print $rip           # 查看指令指针
```

---

## **四、完整调试示例**

### **示例程序**
```c
// debug_demo.c
#include <stdio.h>

int sum(int a, int b) {
    int result = a + b;
    return result;
}

int main() {
    int x = 10;
    int y = 20;
    int total = sum(x, y);
    printf("Sum: %d\n", total);
    return 0;
}
```

### **完整调试流程**
```bash
# 1. 编译带调试信息
gcc -g -O0 debug_demo.c -o debug_demo

# 2. 启动GDB
gdb ./debug_demo

# 3. GDB内部操作
(gdb) break main                    # 在main设断点
(gdb) run                           # 运行
(gdb) disassemble main              # 查看main的汇编
(gdb) next                          # 执行到 int x = 10;
(gdb) print x                       # 查看x的值
(gdb) break sum                     # 在sum函数设断点
(gdb) continue                      # 继续运行到sum
(gdb) info registers                # 查看寄存器
(gdb) x/4xw $sp                     # 查看栈内存
(gdb) step                          # 进入sum函数
(gdb) disassemble                   # 查看sum的汇编
(gdb) info args                     # 查看函数参数
(gdb) finish                        # 运行到函数返回
(gdb) print total                   # 查看返回值
```

---

## **五、进阶调试技巧**

### **1. 条件断点**
```gdb
# 只在条件满足时中断
(gdb) break file.c:30 if x > 100
(gdb) break function if argc == 2

# 条件断点示例
(gdb) break sum if a == 10 && b == 20
```

### **2. 观察点（Watchpoint）**
```gdb
# 监视变量变化
(gdb) watch variable           # 变量被写入时中断
(gdb) rwatch variable          # 变量被读取时中断
(gdb) awatch variable          # 变量被读或写时中断

# 监视内存地址
(gdb) watch *(int*)0x7fffffffe340
```

### **3. 自定义命令**
```gdb
# 创建命令别名
(gdb) define mydebug
>info registers
>x/10i $pc
>info frame
>end

(gdb) mydebug                  # 执行自定义命令
```

### **4. 调试崩溃程序**
```bash
# 如果程序崩溃（段错误）
gdb ./program core          # core是崩溃时生成的文件

# 或者运行后崩溃
gdb ./program
(gdb) run
# 程序崩溃后
(gdb) backtrace             # 查看崩溃时的调用栈
(gdb) frame 0               # 查看崩溃的栈帧
(gdb) info registers        # 查看崩溃时寄存器
```

---

## **六、辅助工具**

### **1. nm - 查看符号表**
```bash
# 查看程序中的符号（函数、变量）
nm ./program                # 显示所有符号
nm -C ./program             # 解码C++名称
nm -D ./program             # 动态符号
nm -g ./program | grep FUNCTION  # 只查看函数
```

### **2. readelf - 查看ELF文件信息**
```bash
# 比objdump更详细的ELF信息
readelf -h ./program        # 查看文件头
readelf -S ./program        # 查看段表
readelf -s ./program        # 查看符号表
readelf -r ./program        # 查看重定位表
```

### **3. strings - 提取字符串**
```bash
# 提取可执行文件中的所有字符串
strings ./program | less
strings -n 10 ./program     # 只显示长度>=10的字符串
```

### **4. ldd - 查看依赖库**
```bash
# 查看程序依赖的动态库
ldd ./program
```

---

## **七、调试GUI前端**

如果你觉得命令行GDB太原始，可以试试：

### **1. GDB TUI（文本界面）**
```bash
# 启动TUI模式
gdb -tui ./program

# 或在GDB中切换
(gdb) layout src           # 显示源码窗口
(gdb) layout asm           # 显示汇编窗口
(gdb) layout regs          # 显示寄存器窗口
(gdb) layout split         # 同时显示源码和汇编
(gdb) Ctrl+X A             # 切换TUI模式
```

### **2. CGDB（彩色增强版）**
```bash
# 安装
sudo apt install cgdb

# 使用（类似vim的操作）
cgdb ./program
```

### **3. IDE集成**
- **VSCode**：安装 C/C++ 扩展，支持图形化调试
- **CLion**：专业的C/C++ IDE，调试功能强大
- **Eclipse CDT**：免费的C/C++开发环境

---

## **八、快速参考卡片**

### **GDB常用命令速查**
```markdown
启动：         gdb program
运行：         run/r
断点：         break/b [位置]
删除断点：     delete/d [编号]
继续：         continue/c
单步（不进）： next/n  
单步（进入）： step/s
查看变量：     print/p [变量]
查看内存：     x/[格式] [地址]
反汇编：       disassemble/disas
查看栈：       backtrace/bt
查看寄存器：   info registers/i r
查看源码：     list/l
退出：         quit/q
```

### **实用组合命令**
```bash
# 一键生成调试报告
gdb -q -ex "set pagination off" -ex "break main" \
    -ex "run" -ex "info registers" -ex "disas main" \
    -ex "quit" ./program > debug_report.txt

# 自动反汇编函数
objdump -M intel -d ./program | grep -A 30 "<main>:"
```

---

## **实践建议**

1. **从简单程序开始**：先调试只有几行的程序
2. **混合使用**：先用GDB定位问题，再用objdump深入分析
3. **做笔记**：记录每个命令的作用和效果
4. **理解内存布局**：画图理解栈、堆、全局变量的位置

**记住**：调试不是魔法，而是系统性的观察和分析。掌握这些工具后，你就能像侦探一样追踪程序的每个细节！