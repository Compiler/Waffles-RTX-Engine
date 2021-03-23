#include <Waffles/Waffles.h>
#include <Waffles/Tools/Logging.h>
#include <Waffles/Cores/EngineCore.h>
int main(){
    uint32_t layerCount;
    vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
    WARN("Program begin");
    Waffles::EngineCore core;
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