#ifndef BYTEBUFFER00_H_
#define BYTEBUFFER00_H_

class copyable
{
protected:
    copyable() = default;
    ~copyable() = default;
};

//non-blocking = non-blocking + IO multiplexing 网络编程中，必须维护应用层buffer（in and out buffer）
//non-blocking IO核心思想：IO线程应避免阻塞在read或write或其他IO系统调用上，只能阻塞在IO multiplexing函数上
//对应用程序而言，应该只管生成数据，不应该关心数据是一次发送还是多次发送，这些应该由网络库来关心
#endif