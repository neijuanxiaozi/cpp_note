Linux系统由Linux系统内核和系统级应用程序组成。

- 内核提供系统最核心的功能：CPU调度，调度内存，调度文件系统，调度网络通讯，调度IO等
- 系统级应用程序：文件管理器，任务管理器，图片查看，音乐播放。

Linux的目录结构：Linux没有盘符的概念，只有一个根目录/，所有文件都在它下面

命令格式：command [-options] [parameter]

Linux命令：

```shell
su  								#登录root用户
exit 								#退出登录
ctrl+alt+F3 						#转为命令行界面
ctrl+alt+F1							#图形界面
firewall-cmd --list-ports  			#查看防火墙开启端口
firewall-cmd --zone=public --add-port=7373/tcp --permanent  #开启指定端口
firewall-cmd --reload 				#重新加载防火墙
tty  								#查看当前是那个终端
ps -aux  							#查看当前所有进程
cd 									#进入目录
pwd									#打印当前工作目录
ls									#查看目录和文件 不加参数默认当前目录 -a表示所有  -l表示列表形式 -h显示文件大小的单位 选项可以混合使用 -al -lh

echo $$								#查看当前终端进程的id
									#命令最后加上&代表后台运行
vim命令行模式输入e可以刷新文件
getconf GNU_LIBPTHREAD_VERSION		#查看当前pthread库版本
man + 系统调用名                    	#查看命令或者系统调用详细内容
ifconfig							#查看网卡信息
netstat								#查看网络相关信息的命令
unzip								#解压zip文件 -d xxxxxx 表示解压到xxxx目录
sudo apt-get install libmysqlclient-de #安装mysql相关连接库 tinywebserver需要用到
mkdir [-p] 路径						#Make Directory 创建文件夹 -p表示自动创建不存在的父目录
touch 路径							#创建文件
cat 路径								#查看文件 cat显示文件的全部内容
more 路径								#查看文件内容 more支持翻页 空格翻页 q退出
cp [-r] 参数1 参数2					
#复制文件或文件夹 -r用于文件夹的复制 表示递归 参数1表示要复制的文件 2表示目的地

mv 参数1 参数2						
#移动文件或文件夹 参数1为被移动的文件或文件夹 参数2为目的地 不存在就改名

rm [-r -r] 参数1 参数2 ...参数N			
#删除文件或文件夹 -r用于递归删除文件夹 -f用于强制删除 参数代表删除的文件 可以有多个参数 删除的文件可以有通配符 例如test*表示所有以test开头的文件

su - root						#切换root用户 exit退出
which  命令						#查找所使用的一系列命令的程序文件存放在哪
find 起始路径 -name "被查找文件名"	#按名字查找文件
find 起始路径 -size +|-n[kMG]    	
#按大小查找文件  +和-表示大于和小于 n表示大小数字 kMG表示大小单位 k表示kb M表示MB G表示GB  
find / -size -10k #表示从根目录查找小于10kb的文件

grep [-n] 关键字 文件路径				
#从文件中通过关键字过滤文件行 -n在结果中显示匹配行的行号 关键字表示过滤的关键字，带有空格或其他特殊符号，建议使用""将关键字包裹起来 文件路径表示要过滤的文件路径，可作为内容输入端口

wc [-c -m -l -w] 文件路径			
#-c 统计bytes数量  -m 统计字符数量	-l统计行数 -w统计单词数量  参数是文件路径 可作为内容输入端口

| 		#管道符 将管道符左边命令的结果 作为管道符右边命令的输入 下面举例
cat test.txt | grep itheima					
cat test.txt | wc -l						
ls | grep test								
cat test.txt | grep itcast | grep itheima 	
echo 输出的内容  						#在命令行内输出指定内容，复杂内容可以用""包裹
``										#反引号 被``包裹的内容会作为命令去执行
>										#将重定向左侧命令的结果 覆盖写入到符号右侧指定的文件中
>>										#将重定向左侧命令的结果 追加写入到符号右侧的指定的文件中
tail [-f -num] Linux路径					#查看文件尾部的内容 -f表示持续跟踪 -num表示尾部多少行 默认10行
su [-] [用户名]							#-是可选的，表示是否在切换用户后加载环境变量 参数：用户名，表示要切换的用户，省略表示切换到root， 切换用户后exit回到上一个用户，或者ctrl+d
sudo 命令								#sudo可以为普通的命令授权，临时以root身份执行，但不是所有用户都有sudo权力


为普通用户配置sudo认证
1.切换到root用户，执行visudo命令 自动打开/etc/sudoers
在文件的最后添加
jianglong ALL=(ALL) NOPASSWD: ALL
其中NOPASSWD: ALL表示使用sudo命令 无需输入密码
最后通过wq保存退出


Linux中关于权限的管控级别有两个级别
1.针对用户的权限控制
2.针对用户组的权限控制

用户组管理
以下命令需要root用户执行
groupadd   #创建用户组
groupdel	#删除用户组

用户管理
1.useradd [-g -d] 用户名      #-g指定用户的组 不指定用户的组会创建同名的组并自动加入 -d指定用户的HOME路径，默认/home/用户名
2.userdel [-r] 用户名          #-r删除用户的HOME目录，不使用-r，删除用户时，HOME目录保留
3.id [用户名]                   #查看用户所属组
4.usermod -aG 用户组 用户名     #及那个指定用户加入指定用户组

getent passwd						#查看当前系统中有哪些用户
getent group						#查看当前系统中有哪些用户组

ls -l
权限控制信息	  所属用户   所属用户组
drwxrwxr-x 13 jianglong jianglong 4096 Jan 17 20:43 code
drwxrwxr-x  5 jianglong jianglong 4096 Jan 20 20:22 fastdfs
drwxrwxr-x  3 jianglong jianglong 4096 Dec  9 20:03 git_learn
drwxrwxr-x  3 jianglong jianglong 4096 Jan 20 19:36 heima_distributed_file_system
-rw-rw-r--  1 jianglong jianglong   23 Jan 26 21:03 hello2.txt
-rw-rw-r--  1 jianglong jianglong   21 Jan 26 21:02 hello.txt
drwxrwxr-x  2 jianglong jianglong 4096 Aug 21 15:29 java
drwxr-xr-x 13 jianglong jianglong 4096 Aug  8 15:47 neo4j-community-5.11.0
drwxrwxr-x  3 jianglong jianglong 4096 Jan 17 20:03 tools

权限控制信息
第1位：-表示文件 d表示文件夹 l表示软连接
第2-4位：表示所属用户权限 
第5-7位：表示所属用户组权限
第8-10位：表示其他用户权限
r表示读权限
w表示写权限
x表示执行权限


chmod [-R] 权限 文件或文件夹						#修改文件、文件夹的权限信息(只有文件(夹)的所属用户或root用户可以修改) -R对文件夹内的全部内容应用同样的操作

chmod举例:
chmod u=rwx,g=rx,o=x hello.txt 						#将hello.txt文件权限修改为:rwxr-x--x,其中u表示user所属用户权限,g表示group组权限,o表示other其他用户权限  也可以使用权限的数字序号:权限可以用3位数字来代表,第一位表示用户权限,第二位表示用户组权限,第三位表示其他用户权限,其中r为4,w为2,x为1

举例:
chmod 751 hello.txt    							#将hello.txt文件权限修改为:rwxr-x--x


chown [-R] [用户][:][用户组] 文件或文件夹 		#-R同chmod 对文件夹内全部内容应用相同规则 用户表示修改所属用户 用户组表示修改所属用户组 :用于分隔用户和用户组
chown root hello.txt 			#将hello.txt所属用户修改为root
chown :root hello.txt 			#将hello.txt所属用户组修改为root
chown root:itheima hello.txt 			#将hello.txt所属用户修改为root 用户组修改为itheima
chown -R root test		 			#将test所属用户修改为root 并对文件夹下所有文件修改




快捷按键:
ctrl + d #退出或登出(退出某些特定程序的专属页面 例如python)
history  #查看历史命令
ctrl + r #输入内容 去历史命令中内容 回车可以直接执行 左右键获得该命令
ctrl + a #光标跳到命令开头
ctrl + e #光标跳到命令结尾
ctrl + 左 #向左跳一个单词
ctrl + 右 #向右跳一个单词
ctrl + l 或者 clear #清空终端内容


yum:RPM包软件管理器，用于自动化安装配置Linux软件，并可以自动解决依赖问题
语法: yum [-y] [install | remove | search] 软件名称
	选项: -y自动确认 无需手动确认安装或卸载过程
	intall:安装
	remove:卸载
	search:搜索
apt:DEB包软件管理器，用于自动化安装配置Linux软件，并可以自动解决依赖问题
语法: apt [-y] [install | remove | search] 软件名称
	选项: -y自动确认 无需手动确认安装或卸载过程
	intall:安装
	remove:卸载
	search:搜索
	
	
systemctl命令
systemctl start | stop | status | enable | disable 服务名
start	#启动
stop	#关闭
status	#查看状态
enable	#开启开机自启
disable	#关闭开机自启
系统内置服务:
NetworkManager #主网络服务
network		#副网络服务
firewalld	#防火墙服务
sshd, ssh服务(FinalShell远程登录Linux)


软链接:包含了到原文件的路径信息  硬链接:对原文件起了一个别名
在系统创建软链接，可以将文件、文件夹链接到其它位置 类似快捷方式
ln -s 参数1 参数2
-s选项表示创建软链接
参数1:被链接的文件或文件夹
参数2:要链接去的目的地


date命令
在命令行中查看系统的时间
date [-d] [+格式化字符串]
-d按照给定的字符串显示日期 一般用于日期计算

修改linux时区为东八区
rm -f /etc/localtime
sudo ln -s /usr/share/zoneinfo/Asia/Shanghai /etc/localtime


ping命令
ping [-c num] ip或主机名
选项:-c检查的次数 不使用-c选项 将无限次持续检查
参数:ip或主机名 被检查的服务器的ip地址或主机地址

wget命令
wget是非交互式的文件下载器 可以在命令行内下载网络文件
wget [-b] url
选项:-b可选 后台下载 会将日志写入到当前工作目录的wget-log文件
参数:url 下载链接

curl命令
curl可以发送http网络请求 可用于:下载文件、获取信息等
语法: curl [-O] url
选项:-O 用于下载文件 当url是下载链接时 可以使用此选项保存文件
参数:url 要发起请求的网络地址


查看进程
语法: ps [-e -f]
选项: -e 显示出全部的进程
选项: -f 以完全格式化的形式展示信息


查看系统资源占用
top命令查看CPU、内存使用情况，类似windows的任务管理器 默认每五秒刷新一次
语法:直接输入top即可 按q或者ctrl+c退出
top命令选项:
选项 		功能
-p		只显示某个进程的信息
-d		设置刷新时间 默认5s
-c		显示产生进程的完整命令 默认是进程名
-n		指定刷新次数 比如top -n 3 刷新输出3次后退出
-b		以非交互非全屏模式运行 以批次的方式执行top 一般配合-n指定输出几次统计信息 将输出重定向到指定文件 比如top -b -n 3 > /tmp/top.tmp
-i		不显示闲置或无用的进程
-u		查找特定用户启动的进程

释放缓存:echo 1 > /proc/sys/vm/drop_caches



磁盘信息监控
使用df命令 查看硬盘的使用情况
df [-h]

使用iostat查看cpu 磁盘的相关信息
语法: iostat [-x][num1][num2]
选项: -x 显示更多信息
num1: 数字 刷新间隔 num2: 刷新几次

网络状态监控
sar命令查看网络的相关统计
语法:sar -n DEV num1 num2
选项:-n 查看网络 DEV表示查看网络接口
num1:刷新间隔 num2:查看次数


环境变量
在Linux系统中执行:env命令即可查看当前系统中记录的环境变量
环境变量是kv型结构
PATH=/home/jianglong/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/usr/local/jdk/bin:/usr/local/jdk/jre/bin
PATH记录了系统执行任何命令的搜索路径，当执行任何命令，都会按照顺序从上述路径中搜索要执行的程序的本体
echo #PATH
自行设置环境变量:
Linux环境变量可以用户自行设置，其中分为:
1.临时设置 语法:export 变量名=变量值
2.永久生效
	- 针对当前用户生效 配置在当前用户的: ~/.bashrc文件中
	- 针对所有用户生效 配置在系统的: /etc/profile文件中
	- 通过语法: source配置文件，进行立刻生效



压缩和解压
压缩格式:
1.zip:Linux Windows MacOS常用
2.7zip:Windows常用
3.rar:Windows常用
4.tar:Linux MacOS常用
5.gzip:Linux MacOS常用

tar命令
Linux和Mac系统常用常用有2中压缩格式 后缀名分别是 .tar .gz
.tar 称之为tarball 归档文件 即简单的将文件组装到一个.tar的文件内 并没有太多文件体积的减少 仅仅是简单的封装
.gz 也常见为.tar.gz gzip格式压缩文件 即使用gzip压缩算法将文件压缩到一个一个文件内 可极大减少压缩后的体积
针对这两种格式 使用tar命令均可以进行压缩和解压缩的操作
语法:tar [-c -v -x -f -z -C] 参数1 参数2 ... 参数N
	-c 创建压缩文件 用于压缩模式
	-v 显示压缩 解压过程 用于查看进度
	-x 解压模式
	-f 要创建的文件或要解压的文件 -f选项必须在所有选项中位置处于最后一个
	-z gzip模式  不使用就是不同的tarball模式
	-C 选择解压的目的地 用于解压模式


zip命令
使用zip命令 压缩文件为zip压缩包
语法: zip [-r] 参数1 参数2 ...参数N
-r 被压缩的包含文件夹的时候 需要使用-r选项
示例:
zip -r test.zip test itheima a.txt

unzip命令
使用unzip命令 解压zip压缩包
语法: unzip [-d] 参数
-d 指定解压去的位置
参数 被解压的zip压缩包文件

```

在服务器上搭建一些服务的时候，经常要用到screen命令。某些服务开启的时候需要占据一整个控制台，如果关闭了就会导致进程终止。这就成了类似单进程的效果。而screen命令就是为了能够在服务器上开启多个控制面板(screen)，用以容纳不同的任务。

```shell
1、创建一个screen
screen -S  ***
2、查看当前screen列表
screen -ls
#detached：相当于最小化窗口
#attached：相当于当前窗口
#dead：相当于死了的窗口
3、重新进入已经创建的screen
screen -r ***
4、退出screen窗口
输入一下快捷键：ctrl + a + d
5、kill screen窗口
在screen窗口内部时 ： 
   输入一下快捷键：ctrl+d
在screen窗口外部时：
   1.使用screen窗口的名字
screen -S session_name -X quit
2.回到screen窗口，再退出screen窗口

1.回到screen窗口
screen -r session_name
2.利用exit退出screen窗口，退出窗口后session窗口被自动kill
exit # 可能需要多次exit命令，因为screen中正在运行的程序可能也需要使用exit命令才退出（先使用exit命令退出screen中正在运行的程序，再使用exit命令退出screen）
```

