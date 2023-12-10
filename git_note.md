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


# 添加指定文件到暂存区，包括被修改的文件
git add [file1] [file2] ...

# 添加当前目录的所有文件到暂存区
git add .

# 删除工作区文件，并且将这次删除放入暂存区
git rm [file1] [file2] ...

# 改名文件，并且将这个改名放入暂存区
git mv [file-original] [file-renamed]

# 提交暂存区到仓库区
git commit -m [message]
# 提交所有修改到仓库
git commit -a -m'修改README的版权信息'

# 提交暂存区的指定文件到仓库区
git commit [file1] [file2] ... -m [message]

# 使用一次新的commit，替代上一次提交
# 如果代码没有任何新变化，则用来改写上一次commit的提交信息
git commit --amend -m [message]

git log -n2
commit 412b56448568ff362ef312507e78797befcf2846 (HEAD -> main)
Author: Kanding <123anding@163.com>
Date:   Thu Dec 1 19:02:22 2022 +0800

commit c0ef58e3738f7d54545d8c13d603cddeee328fcb
Author: Kanding <123anding@163.com>
Date:   Thu Dec 1 16:52:56 2022 +0800

# 用参数“--oneline”可以让日志输出更简洁（一行）
git log -n2 --oneline
5444126 (HEAD -> main, origin/main, origin/HEAD) Update README.md
228362e Merge branch 'main' of github.com:kwonganding/KWebNote

# tag
git tag -a 'v1' -m'v1版本'
cat .git/refs/tags/v1
a2e2c9caea35e176cf61e96ad9d5a929cfb82461

# main分支指向最新的提交
cat .git/refs/heads/main
8f4244550c2b6c23a543b741c362b13768442090

# HEAD指向当前活动分支
cat .git/HEAD
ref: refs/heads/main

# 切换到dev分支，HEAD指向了dev
git switch dev
Switched to branch 'dev'
cat .git/HEAD
ref: refs/heads/dev

# HEAD 表示当前分支的最新版本，是比较常用的参数。
# HEAD^上一个版本，HEAD^^ 上上一个版本。
# HEAD~ 或HEAD~1 表示上一个版本，以此类推，HEAD^10 为最近第10个版本。
# HEAD@{2}在git reflog日志中标记的提交记录索引。

# 通过git log、git reflog可以查看历史日志，可以看每次提交的唯一编号（hash）。区别是git reflog可以查看所有操作的记录（实际是HEAD变更记录），包括被撤销回退的提交记录。

#查看在那存取和工作区的差异
git diff

# 查看文件的修改 指定文件
git diff README.md

#查看已暂存的改动，就是暂存区与新版本HEAD进行比较
git diff --cached
git diff --staged
git diff --cached [file]

#查看已暂存的+未暂存的所有改动，就是与最新版本HEAD进行比较
git diff HEAD
git diff HEAD~

# 查看两次提交的差异
git diff [id] [id]
git diff 8f4244 1da22

#查看工作区和分支直接的差异
git diff [branch]
# 显示今天你写了多少行代码：工作区+暂存区
git diff --shortstat "@{0 day ago}"

#查看当前远程仓库使用的那种协议连接：
git remote -v

# 更改为https地址，即可切换连接模式。还需要禁用掉SSL, 才能正常使用https管理git
git config --global http.sslVerify false

#SSH方式通过非对称加密  需要公私钥对 公钥放服务器上 私钥自己留着进行认证
ssh-keygen -t rsa

# 从远程仓库克隆到本地（当前目录）
git clone 'https://github.com/kwonganding/KWebNote.git'


#查看所有远程仓库，不带参数-v只显示名称
git remote -v

# 显示某个远程仓库的信息
git remote show [remote]

# 增加一个新的远程仓库，并命名
git remote add [name] [url]

# 修改远程仓库名称
git remote rename [old] [new]

# 取回远程仓库的变化，并与本地版本合并
git pull [remote] [branch]
git pull # 只针对当前分支

# 获取远程仓库的所有变动到本地仓库，不会自动合并！需要手动合并
git fetch [remote]

# 推送当前分支到远程仓库
git push
git push [remote] [branch] # 指定分支
git push [remote] --force/-f # 强行推送当前分支 即使有冲突
git push [remote] -all #推送所有分支
git push -u # 表示与远程分支建立关联，第一次执行的时候用，后面就不需要了
git remote rm [remote-name] # 删除远程仓库
git pull  -rebase #使用rebase的模式进行合并

# fetch不会自动合并 不会影响当前工作区的内容
git pull = git fetch + git merge

# 合并
git merge

# 查看当前分支
git branch --show-current

# 列出所有分支
git branch

# 创建dev分支
git branch dev
```

