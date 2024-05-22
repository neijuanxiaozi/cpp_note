# GroupCache

groupcache 最初是由 memcache 的作者 Brad Fitzpatrick 编写的。groupcache 最初是为 Google 的静态文件服务器提供二进制文件 blob (Binary Large Object 二进制类型的大对象)服务而创建的。目前，groupcache 是一个用 Go 编写的。

groupcache不支持更新或删除缓存内容。主要应用在缓存热点数据(不可变的)，

# gocache

## grpc

**`protobuf`版本26.1**

**安装grpc版本为v1.64.0**

```shell
go get -u -v google.golang.org/grpc
```

使用`protobuf`生成`grpc`服务所需要的文件:

```shell
protoc --go_out=. --go-grpc_out=. *.proto
```

用`protobuf`生成`grpc`文件需要用到`protoc-gen-go-grpc.exe`,安装:

```c++
go install google.golang.org/grpc/cmd/protoc-gen-go-grpc@latest
```

**grpc举例：**

proto文件:

```c++
syntax = "proto3";
option go_package = "./";
package pb;
message Teacher {
    int32 age = 1;
    string name = 2;

}
// 添加 rpc服务
service SayName {
    rpc SayHello (Teacher) returns (Teacher);
}
```

服务端:

1. 初始化一个`grpc`对象
2. 注册服务
3. 设置监听 监听ip，port
4. 启动服务  serve()

```go
package main
import (
	"context"
	"fmt"
	"net"

	"day02/pb"

	"google.golang.org/grpc"
)

type Children struct {
    //重写服务中方法的类需要加一个这个 参考https://www.cnblogs.com/zhangmingcheng/p/16329237.html
	*pb.UnimplementedSayNameServer 
}
// rpc方法
func (this *Children) SayHello(ctx context.Context, t *pb.Teacher) (*pb.Teacher, error) {
	t.Name += " is Sleeping! helloworld"
	return t, nil
}

func main() {
    // 1.初始化一个`grpc`对象
	grpcServer := grpc.NewServer()
    // 2.注册rpc服务 绑定对象 这个对象需要实现服务方法SayHello
	pb.RegisterSayNameServer(grpcServer, new(Children))
	// 3.设置监听
	listener, err := net.Listen("tcp", "127.0.0.1:8800")
	if err != nil {
		fmt.Println("net.Listen err:", err)
	}
	defer listener.Close()
    // 4. 启动服务
	grpcServer.Serve(listener)
}
```

客户端:

1. 连接`grpc`服务
2. 初始化`grpc`客户端
3. 调用远程服务

```go
package main

import (
	"context"
	"day02/pb"
	"fmt"

	"google.golang.org/grpc"
)

func main() {
	// 1.连接grpc服务
	grpcConn, err := grpc.Dial("127.0.0.1:8800", grpc.WithInsecure())
	if err != nil {
		fmt.Println("rpcDial  err:", err)
		return
	}
	defer grpcConn.Close()

	// 2.初始化grpc客户端
	grpcClient := pb.NewSayNameClient(grpcConn)
	
    // 创建rpc方法参数
	teacher := &pb.Teacher{
		Name: "itcast",
		Age:  18,
	}
    // 3.调用远程服务
	t, err := grpcClient.SayHello(context.TODO(), teacher)
	fmt.Println(t, err)
}
```

## Group模块

## 相关面试题

### 去设计一个分布式缓存系统要从哪些方面考虑？

