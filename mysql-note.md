```sql
mysql -V/--version       			查看mysql版本
sudo service mysql start  			开启服务
sudo service mysql stop  			关闭服务
systemctl status mysql   			查看mysql状态
mysql -u root -p         			登录root 我的密码为123456
exit;								退出
use mysql;							选择数据库
select user,host from mysql.user;	查看mysql用户与主机权限
source 脚本文件名;         			 执行脚本，脚本名要包含路径
select database();        			查看当前库
show databases;           			展示所有库
create database 库名;      			创建数据库
show tables;						展示表
show columns from customers;        展示表列
describe customers;					是show columns的快捷方式
show status; 						显示服务器状态信息
show create database;				
show grants;						显示授予用户
show errors;						显示错误
show warnings;						显示警告

```
