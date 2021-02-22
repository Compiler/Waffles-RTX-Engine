#include <Waffles.h>
#include <Tools/Logging.h>
#include <Cores/RenderCore.h>
int main(){
    
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

    WARN("Program Unloading...");
    core.unload();

    return 0;

}