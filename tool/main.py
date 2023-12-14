# coding=utf-8
import pyautogui
import os
import time
import pyperclip

# 配置
# 要打开的应用地址
app_dir = "C:\Windows\system32\cmd.exe"
# 执行命令列表
cmds = [
    "cd ../",
    "tree",
    "java",
    "javac",
    "cd ../",
    "cd ../",
    "你想说什么"
]

# 打开windows应用
time.sleep(2)
os.startfile(app_dir)

# 自动跑输入命令
pyautogui.typewrite(["enter"], '0.25')

# 暂停5秒，定位应用界面
time.sleep(5)

# 获取应用坐标，通过鼠标位置获取
# 获取鼠标位置
x, y = pyautogui.position()
# 输入命令
for i in cmds:
    """
     解决CMD中中文不可用情况，使用右键复制
    """
    # 放置到剪贴板
    pyperclip.copy(i)
    # 右键粘贴命令
    pyautogui.click(x = x, y = y, button = 'right')
    time.sleep(0.5)
    # pyautogui.typewrite([x for x in i], '0.25')
    pyautogui.typewrite(["enter"], '0.25')
    
