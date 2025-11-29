# Byte_Algorithm
This module provides quick and basic byte algorithm for you to improve your developing efficiency.

## 简介
介绍这个项目的定位和用途，例如：
> 一个用 C 语言实现的基础字节与位操作算法库，支持对 8 位字节的单独或批量位操作，包含获取、设置、翻转等常用方法，适用于嵌入式开发、底层协议解析、数据处理等场景。

## 功能特性
- 获取/设置/翻转/复位 LSB（最低位）与 MSB（最高位）
- 操作任意 bit 位
- 操作连续若干位（getBits, writeBits）
- 提供错误检测机制
- 辅助函数：判断是否 2 的幂、判断奇偶性

## 环境要求
- C99 及以上标准的 C 语言编译器

## 使用方法

### 头文件引用
```c
#include "Byte_Algorithm.h"
```

### 示例代码
```c
uint8_t data = 0x53;
uint8_t lsb = getLSB(data);
uint8_t msb = getMSB(data);

uint8_t new_data = setBitN(data, 3); // 将第 3 位设为 1

uint8_t extracted = getBits(data, 1, 3); // 提取第1位起的3位
```

### 错误处理
```c
if (Byte_Algorithm_check_Error()) {
    // 处理错误
    Byte_Algorithm_clear_Error();
}
```

## 主要 API 说明
简要罗列每个函数功能：
- `getLSB(uint8_t byte)`: 获取最低位
- `setLSB(uint8_t byte)`: 设最低位为1
- `getMSB(uint8_t byte)`: 获取最高位
- `setMSB(uint8_t byte)`: 设最高位为1
- `getBitN(uint8_t byte, uint8_t n)`: 获取指定位

可继续补充其它重要函数说明。

## 致谢和许可
> 本项目由 Werner-15 开发与维护。如有建议或贡献欢迎 Issue 和 PR。
