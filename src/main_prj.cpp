#include "plugin_ctrl.h"

int main(){
    // 查找动态库
    struct PluginStruct *plugin_1 = get_plugin("plugin_1");

    // 调用插件的一些功能函数
    void *args = nullptr;
    plugin_1->init(args);
}
