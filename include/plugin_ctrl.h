#ifndef PLUGIN_H
#define PLUGIN_H
/* 插件在加载和关闭时，自动调用的构造函数和析构函数 标识？ */
#define plugin_init	__attribute__((constructor))
#define plugin_exit	__attribute__((destructor))

struct PluginStruct {
    /* 插件的名字 */
    char *plugin_name;
    /* 插件的版本 */
    int plugin_version;

    /* 插件的初始化函数（可选），其中参数可以是任意类型，不需要必须是void *，下同 */
    int (*init)(void *some_args);
    /* 插件的反初始化函数（可选） */
    int (*uninit)(void *some_args);

    /* 一些插件需要实现的功能函数 */
    int (*plugin_func_1)(void *some_args);
    int (*plugin_func_2)(void *some_args);
};

/* 插件向主程序注册和反注册接口 */
extern void plugin_register(struct PluginStruct *);
extern void plugin_unregister(struct PluginStruct *);

/* 外部想要调用插件的功能函数时，先获取插件名字 */
struct PluginStruct *get_plugin(char *plugin_name);
#endif //PLUGIN_H
