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
git config --global user.name "Your Name"
git config --global user.email "email@example.com"
# 配置完后，看看用户配置文件：
cat 'C:\Users\Kwongad\.gitconfig'
#linux查看git用户配置文件
cat ~/.gitconfig
[user]
        name = Kanding
        email = 123anding@163.com

# 克隆命令
git clone 'https://github.com/kwonganding/KWebNote.git'


# 添加指定文件到暂存区，包括被修改的文件
git add [file1] [file2] ...

# 添加当前目录的所有文件到暂存区
git add .

# 删除工作区文件，并且将这次删除放入暂存区
git rm [file1] [file2] ...

# 改名文件，并且将这个改名放入暂存区
git mv [file-original] [file-renamed]

# 提交暂存区到仓库区
$ git commit -m [message]
# 提交所有修改到仓库
$ git commit -a -m'修改README的版权信息'

# 提交暂存区的指定文件到仓库区
$ git commit [file1] [file2] ... -m [message]

# 使用一次新的commit，替代上一次提交
# 如果代码没有任何新变化，则用来改写上一次commit的提交信息
$ git commit --amend -m [message]

$ git log -n2
commit 412b56448568ff362ef312507e78797befcf2846 (HEAD -> main)
Author: Kanding <123anding@163.com>
Date:   Thu Dec 1 19:02:22 2022 +0800

commit c0ef58e3738f7d54545d8c13d603cddeee328fcb
Author: Kanding <123anding@163.com>
Date:   Thu Dec 1 16:52:56 2022 +0800

# 用参数“--oneline”可以让日志输出更简洁（一行）
$ git log -n2 --oneline
5444126 (HEAD -> main, origin/main, origin/HEAD) Update README.md
228362e Merge branch 'main' of github.com:kwonganding/KWebNote



```

