#include <dlfcn.h>
#include "plugin_ctrl.h"

/* 这里是Linux下查找插件并加载动态库 */
static PluginStruct* load_plugin(char *plugin_dll_path){
    struct PluginStruct *plugin;
    void *dll_handle = dlopen(plugin_dll_path, RTLD_LAZY);
    if (!dll_handle) {
        return nullptr;
    }

    plugin = dlsym(dll_handle, plugin_dll_path); // 这是啥？
    if (!plugin){
        plugin = dlsym(dll_handle, "plugin");
    }
    return plugin;
}

void plugin_register(struct PluginStruct *){
    // TODO 插件的注册管理
    /* 这里可以将注册的插件保存到一个map结构里*/
}

void plugin_unregister(struct PluginStruct *){
    // TODO 插件的反注册管理
}

struct PluginStruct *get_plugin(char *plugin_name){
    // TODO 按照名字从map结构里查询对应注册的插件
}