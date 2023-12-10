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


# 显示当前指针
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

# 分支相关命令
git branch  # 列出所有分支 *为当前分支  只显示本地分支
git branch -r #列出所有远程分支
git branch -a #列出所有远程和本地分支
git branch dev # 创建dev分支 但是停留在当前分支
git branch -d dev # 删除dev分支，-D（大写）强制删除
git checkout -b dev # 从当前分支创建并切换到dev分支
git checkout -b feature1 dev # 从本地dev分支代码创建一个 feature1分支，并切换到新分支
git branch [branch][commit] #新建一个分支，指向指定commit id
git branch --tack [branch][remote-branch] #新建一个分支与指定的远程分支建立关联
git checkout -b hotfix remote hotfix #远端remote的hotfix分支创建本地hotfix分支
git branch --set-upstream [branch] [remote-branch] #在现有分支与指定的远程分支之间建立跟踪关联
git checkout [branch-name] #切换到指定分支，并更新工作区
git checkout . #撤销工作区的（未暂存）修改，把暂存区恢复到工作区
git checkout HEAD . #撤销工作区、暂存区的修改，用HEAD指向的当前分支最新版本替换
git merge [branch] #合并指定分支到当前分支
git merge --no-ff dev # 合并dev分支到当前分支，参数--no-ff禁用快速合并模式
git push origin --delete [branch-name] # 删除远程分支
git rebase master # 将当前分支变基合并到master分支
git switch dev # 切换到dev分支，HEAD指向了dev
git switch -c dev #创建并切换到新的dev分支
git reset #专门用来实现本地修改的撤销 

#把两个分支的修改内容合并到一起的办法有两种：merge 和 rebase，作用都是一样的，区别是rebase的提交历史更简洁，干掉了分叉，merge的提交历史更完整。
git rebase master #将当前分支合的提交打补丁到master中


#标签（Tags）
git tag #查看标签列表
git tag -l 'a*' # 查看名称是“a”开头的标签列表，带查询参数
git show [tagname] #查看标签信息
git tag [taganem] #创建一个标签，默认标签是打在最新提交的commit上的
git tag [tagname] [commit id] #新建一个tag在指定commit上
git tag -a v5.1 -m'v5.1版本' #创建标签v5.1.1039，-a指定标签名，-m指定说明文字
git tag -d [tagname] #删除本地标签
git checkout v5.1.1039 #切换标签，同时切换分支
git push [remote] v5.1 #推送标签，标签不会默认随代码推送推送到服务端
git push [remote] --tags #提交所有tag

# 撤销
git checkout . 	#撤销工作区的（未暂存）修改，把暂存区恢复到工作区。不影响暂存区，如果没暂存，则撤销所有工作区修改
git checkout [file] #撤销指定文件
git checkout HEAD . # 撤销工作区、暂存区的修改，用HEAD指向的当前分支最新版本替换工作区、暂存区
git checkout HEAD [file] #指定文件
git reset # 撤销暂存区状态 同git resetHEAD 不影响工作区
git reset HERD # 指定文件
git reset [commit] #回退到指定版本，清空暂存区，不影响工作区。工作区需要手动git checkout签出
git reset --soft [commit] # 移动分支master、HEAD到指定的版本，不影响暂存区、工作区，需手动git checkout签出更新
git reset --hard HEAD # 撤销工作区、暂存区的修改，用当前最新版
git reset --hard HEAD~ # 回退到上一个版本，并重置工作区、暂存区内容。
git reset --hard [commit] # 回退到指定版本，并重置工作区、暂存区内容。
git revert[commit]  # 撤销一个提交，会用一个新的提交（原提交的逆向操作）来完成撤销操作，如果已push则重新push即可

#reset有三种模式，对应三种参数：mixed（默认模式）、soft、hard。三种参数的主要区别就是对工作区、暂存区的操作不同

git reset [--soft | --mixed | --hard] [HEAD]

# 撤销暂存区
$ git reset
Unstaged changes after reset:
M       R.md

# 撤销工作区、暂存区修改
$ git reset --hard HEAD

# 回退版本库到上一个版本，并重置工作区、暂存
$ git reset --hard HEAD~

# 回到原来的版本（恢复上一步的撤销操作），并重置工作区、暂存
$ git reset --hard 5f8b961

# 查看所有历史提交记录
$ git reflog
ccb9937 (HEAD -> main, origin/main, origin/HEAD) HEAD@{0}: commit: 报表新增导入功能
8f61a60 HEAD@{1}: commit: bug：修复报表导出bug
4869ff7 HEAD@{2}: commit: 用户报表模块开发
4b1028c HEAD@{3}: commit: 财务报表模块开发完成


# revert撤销指定的提交，“-m”附加说明
$ git revert 41ea42 -m'撤销对***的修改'
[main 967560f] Revert "123"
                            1 file changed, 1 deletion(-)

```

