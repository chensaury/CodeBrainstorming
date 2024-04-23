如果 .c 文件和 .h 文件不在同一个目录中，需要更新任务配置以确保编译器能够找到头文件。可以通过两种方式来实现：

更新任务配置中的包含路径：将包含路径添加到任务配置中，以便编译器可以找到新的头文件。**在任务配置的 "args" 部分添加 -I 选项并指定头文件所在的目录。**

tasks.josn修改
```C
```C
{
	"version": "2.0.0",
	"tasks": [
		{
			"type": "cppbuild",
			//任务名
			"label": "MyCFD",
			"command": "D:/APP/mingw64/bin/g++.exe",
			"args": [
				
				"-fdiagnostics-color=always",
				
				"-g",//生成和调试有挂信息
				"-Wall",
				//"${file}",
				//"${fileDirname}\\*.cpp",//代表编译当前目录下的所有.cpp文件，大型项目，不同的cpp在不同目录下，run code 模式运行就会出现：undefined referecde to 'xxx函数'
				"${workspaceFolder}\\code_test\\MyCFD_1101\\*.cpp ",
				"${workspaceFolder}\\code_test\\MyCFD_1101\\readcase\\*.cpp",
				"${workspaceFolder}\\code_test\\MyCFD_1101\\setequation\\*.cpp",
				"${workspaceFolder}\\code_test\\MyCFD_1101\\solver\\run_steady_calculation\\*.cpp",
				
				"-o",
				"${fileDirname}\\${fileBasenameNoExtension}.exe",//exe文件存放地址
				//"${workspaceFolder}\\code_test\\MyCFD_1101\\${fileBasenameNoExtension}.exe",
				//"-fexec-charset=GBK"//该设置与vscode自带编码冲突，导致中文乱码
			],
			"options": {
				"cwd": "D:/APP/mingw64/bin"
			},
			"problemMatcher": [
				"$gcc"
			],
			"group": {
				"kind": "build",
				"isDefault": true
			},
			"presentation": {
				"echo": false,//是否显示任务命令在终端，但似乎不作用
				"reveal": "silent",
				"focus": true,
				"panel": "shared",//每次代开一个新的C/C++:g++.exe build active file 窗口
				"showReuseMessage": false,//不输出：终端将被任务重用，安任意键关闭
				"clear": true
				
			},
			"detail": "compiler: D:/APP/mingw64/bin/g++.exe"
		}
	]
}
```

请将

```c
 /path/to/header_directory
```

 替换为头文件所在的实际目录路径。

在源文件中使用相对路径包含头文件：在您的 .c 文件中，使用相对路径包含头文件，这样就无需修改任务配置中的包含路径。
例如，如果 .h 文件位于 include 目录下，可以这样包含它：

这样，编译器会相对于 .c 文件的位置去寻找头文件。

```C
#include "../include/example.h"
```

这样，编译器会相对于 .c 文件的位置去寻找头文件。



以下是修改后的两个文件

c_cpp_properties.json修改
```c
{
    "configurations": [
        {
            "name": "windows-gcc-x64",
            "includePath": [
                "${workspaceFolder}/**",
                "${workspaceFolder}/src/DesignLinkedList"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            "compilerPath": "D:/Software Install/mingw64/bin/gcc.exe",
            "cStandard": "c99",
            "cppStandard": "gnu++14",
            "intelliSenseMode": "windows-gcc-x64"
        }
    ],
    "version": 4
}
```
```c

{
	"version": "2.0.0",
	"tasks": [
		{
			"type": "cppbuild",
			"label": "C/C++: gcc.exe 生成活动文件",
			"command": "D:/Software Install/mingw64/bin/gcc.exe",
			"args": [
				"-fdiagnostics-color=always",
				"-g",
				// "${file}",
				"${workspaceFolder}\\src\\*.c ",
				"${workspaceFolder}\\src\\DesignLinkedList\\*.c ",
				"-I","${workspaceFolder}\\src\\DesignLinkedList",
				"-o",
				"${fileDirname}\\${fileBasenameNoExtension}.exe",
				""
			],
			"options": {
				"cwd": "D:/Software Install/mingw64/bin"
			},
			"problemMatcher": [
				"$gcc"
			],
			"group": "build",
			"detail": "编译器: D:/Software Install/mingw64/bin/gcc.exe"
		}
	]
}
```