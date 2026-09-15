# VEXcode

VEX V5 机器人代码，基于 [PROS](https://pros.cs.purdue.edu/) (kernel 4.2.2, C++)。

## 环境

- PROS CLI 3.5.6（`pipx install pros-cli`）
- Arm GNU Toolchain（`arm-none-eabi-gcc`）

## 常用命令

```bash
pros make          # 编译
pros upload        # 通过 USB 上传到主控
pros mu            # 编译 + 上传
pros terminal      # 查看主控串口输出
```

## 目录结构

- `src/` — 源代码（`main.cpp` 含 initialize / autonomous / opcontrol）
- `include/` — 头文件与 PROS API
- `firmware/` — PROS 内核库
