```shell
#查看版本
git --version					

#查看git配置
git config --list
git config -l

#查看系统配置
git config --system --list

#查看当前用户（global）全局配置
git config --list --global

#查看当前仓库配置信息
git config --local  --list


#配置用户名 邮箱
$ git config --global user.name "Your Name"
$ git config --global user.email "email@example.com"
# 配置完后，看看用户配置文件：
$ cat 'C:\Users\Kwongad\.gitconfig'
#linux查看git用户配置文件
cat ~/.gitconfig
[user]
        name = Kanding
        email = 123anding@163.com

# 克隆命令
git clone 'https://github.com/kwonganding/KWebNote.git'





```

