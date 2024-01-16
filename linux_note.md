Linux系统由Linux系统内核和系统级应用程序组成。

- 内核提供系统最核心的功能：CPU调度，调度内存，调度文件系统，调度网络通讯，调度IO等
- 系统级应用程序：文件管理器，任务管理器，图片查看，音乐播放。

Linux的目录结构：Linux没有盘符的概念，只有一个根目录/，所有文件都在它下面

命令格式：command [-options] [parameter]

Linux命令：

```shell
su  								登录root用户
exit 								退出登录
ctrl+alt+F3 						转为命令行界面
ctrl+alt+F1							图形界面
firewall-cmd --list-ports  			查看防火墙开启端口
firewall-cmd --zone=public --add-port=7373/tcp --permanent  开启指定端口
firewall-cmd --reload 				重新加载防火墙
tty  								查看当前是那个终端
ps -aux  							查看当前所有进程
cd 									进入目录
pwd									打印当前工作目录
ls									查看目录和文件 不加参数默认当前目录 -a表示所有  -l表示列表形式 -h显示文件大小									的单位 选项可以混合使用 -al -lh
echo $$								查看当前终端进程的id
									命令最后加上&代表后台运行
									vim命令行模式输入e可以刷新文件
getconf GNU_LIBPTHREAD_VERSION		查看当前pthread库版本
man + 系统调用名                    	查看命令或者系统调用详细内容
ifconfig							查看网卡信息
netstat								查看网络相关信息的命令
unzip								解压zip文件 -d xxxxxx 表示解压到xxxx目录
sudo apt-get install libmysqlclient-de 安装mysql相关连接库 tinywebserver需要用到

```



