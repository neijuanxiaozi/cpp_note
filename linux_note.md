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
mkdir [-p] 路径						Make Directory 创建文件夹 -p表示自动创建不存在的父目录
touch 路径							创建文件，
cat 路径								查看文件， cat显示文件的全部内容
more 路径								查看文件内容 more支持翻页 空格翻页 q退出
cp [-r] 参数1 参数2					复制文件或文件夹 -r用于文件夹的复制 表示递归 参数1表示要复制的文件 2表示目的地
mv 参数1 参数2						移动文件或文件夹 参数1为被移动的文件或文件夹 参数2为目的地 不存在就改名
rm [-r -r] 参数1 参数2 ...参数N			删除文件或文件夹 -r用于递归删除文件夹 -f用于强制删除 参数代表删除的文件 										可以有多个 参数 删除的文件可以有通配符 例如test*表示所有以test开头的文件
su - root						切换root用户 exit退出
which  命令						查找所使用的一系列命令的程序文件存放在哪
find 起始路径 -name "被查找文件名"	按名字查找文件
find 起始路径 -size +|-n[kMG]    	按大小查找文件  +和-表示大于和小于 n表示大小数字 kMG表示大小单位 k表示kb M表示MB G表示GB  find / -size -10k 表示从根目录查找小于10kb的文件

grep [-n] 关键字 文件路径				从文件中通过关键字过滤文件行 -n在结果中显示匹配行的行号 关键字表示过滤的关键									字，带有空格或其他特殊符号，建议使用""将关键字包裹起来 文件路径表示要过滤的文件										路径，可作为内容输入端口
wc [-c -m -l -w] 文件路径				-c 统计bytes数量  -m 统计字符数量	-l统计行数 -w统计单词数量  参数是文件路											径 可作为内容输入端口
| 										管道符 将管道符左边命令的结果 作为管道符右边命令的输入 例
cat test.txt | grep itheima					管道符命令举例
cat test.txt | wc -l						管道符命令举例
ls | grep test								管道符命令举例
cat test.txt | grep itcast | grep itheima 	管道符命令举例
```



