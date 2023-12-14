| launch的属性           | 属性的含义                                                                  |
| ---------------------- | --------------------------------------------------------------------------- |
| type                   | 用于此启动配置的调试器类型                                                  |
| request                | 此启动配置的请求类型,，launch(以调试模式开始)和attach(在运行过程中附加调试) |
| name                   | 显示在调试启动配置下拉列表中的易于阅读的名称。                              |
| presentation           | 如何显示调试的信息，使用order，group和hidden 属性                           |
| preLaunchTask          | 要在调试会话开始之前启动任务，请将此属性设置为task.json中指定的任务标签     |
| postDebugTask          | 要在调试会话的最后启动任务，请将此属性设置为task.json中指定的任务标签       |
| internalConsoleOptions | 此属性控制调试会话期间调试控制台面板的可见性                                |
| program                | 启动调试器时要运行的可执行文件或文件                                        |
| args                   | 传递给程序以进行调试的参数                                                  |
| environment            | 环境变量（该值null可用于“取消定义”变量）                                    |
| envFile                | 带有环境变量的 dotenv 文件的路径                                            |
| cwd                    | 用于查找依赖项和其他文件的当前工作目录                                      |
| stopAtEntry            | 是否在进入短点前停止                                                        |
| externalConsole        | 是否允许外部中端，不允许的话就是用liunx和window自己的中端                   |
| MIMode                 | 所连接的调试器名字                                                          |
| setupCommands          | 执行一个或多个 GDB/LLDB 命令以设置底层调试器。                              |
| miDebuggerPath         | 调试器的位置                                                                |
