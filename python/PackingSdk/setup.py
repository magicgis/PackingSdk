import sys
from setuptools import setup

# 根据操作系统位数选择文件
if sys.maxsize > 2**32:
    package_data = {"sdk": ["Lib/x64/*.dll", "Lib/x64/*.lib", "Lib/x64/*.exe", "Lib/x64/frontend/**"]}  # 64位文件
else:
    package_data = {"sdk": ["Lib/x86/*.dll", "Lib/x86/*.lib", "Lib/x86/*.exe", "Lib/x86/frontend/**"]}  # 32位文件

setup(
    package_data=package_data,
    # 其他配置...
)