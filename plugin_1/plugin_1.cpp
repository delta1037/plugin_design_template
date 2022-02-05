/* 包含定义插件必须的头文件 */
#include "plugin_ctrl.h"

/* 插件私有变量定义 */
struct plugin_private_data {
    // some private data
    int write_call_times;
    int read_call_times;
};

/* 插件定义的初始化函数*/
static int plugin_1_init(void *some_args){
    return 0;
}

/* 插件定义的反初始化函数 */
static int plugin_1_uninit(void *some_args){
    return 0;
}

/* 插件实现的功能函数 */
static int plugin_1_func_1(void *some_args){
    return 0;
}

/* 插件实现的功能函数 */
static int plugin_1_func_2(void *some_args){
    return 0;
}

/* 注册所有本插件的相关函数到插件结构体中 */
struct PluginStruct plugin = {
        .plugin_name 		= "plugin_1",
        .plugin_version 	= 1,
        .init				= plugin_1_uninit,
        .uninit 			= plugin_1_uninit,
        .plugin_func_1 		= plugin_1_func_1,
        .plugin_func_2		= plugin_1_func_2,
};

/*
 * 以下两个自动调用的函数，自动调用是因为包含的plugin.h头文件中两个构造和析构宏定义
 *  #define plugin_init	__attribute__((constructor))
 *  #define plugin_exit	__attribute__((destructor))
 */
/* 插件动态库在加载时会自动调用该函数 */
static void plugin_init plugin_1_auto_register(){
    // plugin_register 是头文件中定义的插件注册接口
    plugin_register(&plugin);
}

/* 插件动态库在关闭时会自动调用该函数 */
static void plugin_exit plugin_1_auto_unregister(){
    // plugin_unregister 是头文件中定义的插件反注册接口
    plugin_unregister(&plugin);
}