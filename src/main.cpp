#include <Waffles.h>
#include <Tools/Logging.h>
#include <Cores/RenderCore.h>
int main(){
    uint32_t layerCount;
    vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
    WARN("Program begin");
    Waffles::RenderCore core;
    if(__DEBUG_MODE){
        WARN("DEBUG MODE ON");
    }else{
        WARN("RELEASE MODE ON");
    }
    core.load();
    int count = 0;
    while(core.isRunning()){
        core.update();
        core.render();
    }

    UNLOAD_LOG("Program Unloading...");
    core.unload();

    return 0;

}