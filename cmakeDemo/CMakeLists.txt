cmake_minimum_required (VERSION 2.8)

project (test1)

#遍历当前目录的所有文件并使用DIR_SRCS保存，也可通过set(SRC_LIST main.cpp testfunc.cpp testfunc1.cpp)进行指定
#aux_source_directory(. DIR_SRCS)
#set(SRC_LIST src/testfunc.cpp 
 #            src/testfunc1.cpp
  #           src/main.cpp)

#添加生成可执行文件的保存目录，不会保存中间产物，如果不指定该目录则和中间产物保存在一起
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

#添加头文件
include_directories(${PROJECT_SOURCE_DIR}/include)

# 这里将子目录条件到工程，并指定编译的输出产物，默认输出产物保存到build/src文件夹下，
# 如果不指定可行文件保存路径同样也会保存到该路径下
add_subdirectory(src)

# 上面定义了将src子目录加入工程，并指定编译输出(包含编译中间结果)路径为
# bin目录。如果不进行 bin目录的指定，那么编译结果(包括中间结果)都将存放在
# build/src 目录(这个目录跟原有的src目录对应)，指定 bin 目录后，相当于在编译时
# 将src重命名为bin，所有的中间结果和目标二进制都将存放在bin目录。

# 指定生成目标
add_executable(test1 main.cpp)

# 添加链接库
# 把子目录集src的编译成的库文件链接到这里
target_link_libraries(test1 add)

message(STATUS  ${PROJECT_SOURCE_DIR} "------完成编译和链接生成可执行文件-----")
