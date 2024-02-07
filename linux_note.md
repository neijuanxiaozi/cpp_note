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
	
```



